#include "gerenciadordrivetech.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "descontostrategy.h"
#include <map>
#include <memory>
#include <stdexcept>
#include <algorithm>

GerenciadorDriveTech* GerenciadorDriveTech::instancia = nullptr;

GerenciadorDriveTech* GerenciadorDriveTech::obterInstancia() {
    if (instancia == nullptr) {
        instancia = new GerenciadorDriveTech();
    }
    return instancia;
}

GerenciadorDriveTech::GerenciadorDriveTech()
    : vendedorAtivoNome(""), vendedorAtivoLogin("")
{

}

std::string GerenciadorDriveTech::limparDocumento(const std::string& documento) {
    std::string limpo = documento;
    limpo.erase(std::remove(limpo.begin(), limpo.end(), '.'), limpo.end());
    limpo.erase(std::remove(limpo.begin(), limpo.end(), '-'), limpo.end());
    limpo.erase(std::remove(limpo.begin(), limpo.end(), ' '), limpo.end());
    return limpo;
}

void GerenciadorDriveTech::inicializarSistema() {
    carregarVendedoresCSV("data/vendedores.csv");
    carregarEstoqueCSV("data/estoque.csv");
    carregarVendasCSV("data/historicoDeVendas.csv");
    carregarClientesCSV("data/clientes.csv");
}

QString GerenciadorDriveTech::autenticar(const std::string& login, const std::string& senha) {
    int opc;
    for (const Vendedor& vendedor : vendedores) {
        if (vendedor.getLogin() == login) {
            if (vendedor.getSenha() == senha) {
                vendedorAtivoNome = vendedor.getNome();
                vendedorAtivoLogin = vendedor.getLogin();
                return "true";
            }
            return "Senha incorreta!";
        }
    }
    return "Login não encontrado!\n";
}

QString GerenciadorDriveTech::cadastrarCliente(const Cliente& novoCliente) {
    std::string documentoLimpo = limparDocumento(novoCliente.getDocumento());

    if (documentoLimpo.length() != 11) {
        return "Erro: O documento deve ter 11 (CPF) dígitos.";
    }

    for (const Cliente& cliente : clientes) {
        if (cliente.getDocumento() == documentoLimpo) {
            return "Cliente já cadastrado!";
        }
    }

    clientes.push_back(novoCliente);

    std::ofstream arquivo_out("data/clientes.csv", std::ios::app);

    if (!arquivo_out.is_open()) {
        clientes.pop_back();
        return "Erro: Nao foi possivel salvar o cliente no arquivo.";
    }

    arquivo_out << novoCliente.getNome() << "," << novoCliente.getDocumento() << "\n";
    arquivo_out.close();

    return "Cliente cadastrado com sucesso!";
}

void GerenciadorDriveTech::carregarClientesCSV(const std::string& arquivo) {
    std::ifstream arquivo_in(arquivo);
    if (!arquivo_in.is_open()) {
        throw std::runtime_error("Erro ao abrir arquivo de clientes: " + arquivo);
    }

    std::string linha;
    std::getline(arquivo_in, linha);

    while (std::getline(arquivo_in, linha)) {
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        std::string nome, documento;

        std::getline(ss, nome, ',');
        std::getline(ss, documento, ',');

        documento.erase(documento.find_last_not_of(" \n\r\t")+1);

        clientes.push_back(Cliente(nome, documento));
    }

    arquivo_in.close();
}

void GerenciadorDriveTech::carregarEstoqueCSV(const std::string& nomeArquivo) {

    if (!estoqueLondrina.empty() || !estoqueMaringa.empty() || !estoqueCuritiba.empty()) {
        for (Veiculo* v : estoqueLondrina) delete v;
        for (Veiculo* v : estoqueMaringa) delete v;
        for (Veiculo* v : estoqueCuritiba) delete v;
        estoqueLondrina.clear();
        estoqueMaringa.clear();
        estoqueCuritiba.clear();
    }

    std::ifstream arquivo(nomeArquivo);
    std::string linha;

    if (!arquivo.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo: " + nomeArquivo);
    }

    std::getline(arquivo, linha);

    std::string errosDeLinha = "";
    int contadorLinha = 1;

    int contador = 0;
    while (std::getline(arquivo, linha)) {
        contadorLinha++;
        if (linha.empty()) continue;
        std::stringstream ss(linha);
        std::string tipo, modelo, anoStr, valorStr, cor;

        std::getline(ss, tipo, ',');
        std::getline(ss, modelo, ',');
        std::getline(ss, anoStr, ',');
        std::getline(ss, valorStr, ',');
        std::getline(ss, cor, ',');

        try {
            int ano = std::stoi(anoStr);
            valorStr.erase(std::remove(valorStr.begin(), valorStr.end(), '.'), valorStr.end());
            double valor = std::stod(valorStr);

            Veiculo* novoVeiculo = nullptr;
            if (tipo == "Carro") {
                novoVeiculo = new Carro(modelo, modelo, cor, valor, ano);
            } else if (tipo == "Moto") {
                novoVeiculo = new Moto(modelo, modelo, cor, valor, ano);
            }

            if (novoVeiculo) {
                if (contador < 100) {
                    estoqueLondrina.push_back(novoVeiculo);
                } else if (contador < 200) {
                    estoqueMaringa.push_back(novoVeiculo);
                } else {
                    estoqueCuritiba.push_back(novoVeiculo);
                }
                modelosPorTipo[tipo].insert(modelo);
                contador++;
            }
        } catch (const std::exception& e) {
            errosDeLinha += "Linha " + std::to_string(contadorLinha) + " inválida: " + linha + "\n";
        }
    }

    arquivo.close();
    std::cout << "Estoque carregado com sucesso!\n";
    std::cout << "Londrina: " << estoqueLondrina.size() << " veículos\n";
    std::cout << "Maringá: " << estoqueMaringa.size() << " veículos\n";
    std::cout << "Curitiba: " << estoqueCuritiba.size() << " veículos\n";

    if (!errosDeLinha.empty()) {
        throw std::runtime_error("Erros ao carregar estoque:\n" + errosDeLinha);
    }
}

QString GerenciadorDriveTech::venda(
    const Cliente& cliente,
    const std::string& filial,
    Veiculo* veiculoSelecionado,
    const std::string& tipoDesconto,
    const std::string& formaPagamento,
    const std::string& nomeVendedor,
    double entrada,
    int parcelas
    )
{

    std::unique_ptr<DescontoStrategy> estrategiaEscolhida;
    if (tipoDesconto == "Cliente fidelidade") {
        bool jaComprou = false;
        for (const Venda& v : historicoVendas) {
            if (v.getDocumentoClienteRaw() == cliente.getDocumento()) {
                jaComprou = true;
                break;
            }
        }
        if (jaComprou) estrategiaEscolhida = std::make_unique<DescontoClienteFiel>();
        else estrategiaEscolhida = std::make_unique<SemDesconto>();
    }
    else if (tipoDesconto == "Promoção especial") estrategiaEscolhida = std::make_unique<DescontoPromocional>();
    else if (tipoDesconto == "Vendas corporativas") estrategiaEscolhida = std::make_unique<VendaCorporativa>();
    else estrategiaEscolhida = std::make_unique<SemDesconto>();

    double valorOriginal = veiculoSelecionado->getValor();
    double valorFinal = estrategiaEscolhida->aplicarDesconto(valorOriginal);
    double saldoRestante = 0.0;
    double valorParcela = 0.0;

    if (formaPagamento == "Parcelado") {
        if (entrada <= 0 || entrada >= valorFinal) {
            throw std::invalid_argument("O valor da entrada deve ser maior que 0 e menor que o total.");
        }
        if (parcelas <= 1) {
            throw std::invalid_argument("Para pagamento parcelado, o número de parcelas deve ser maior que 1.");
        }

        saldoRestante = valorFinal - entrada;
        valorParcela = saldoRestante / parcelas;
    } else {
        entrada = valorFinal;
        parcelas = 1;
        saldoRestante = 0.0;
        valorParcela = 0.0;
    }

    auto agora = std::chrono::system_clock::now();
    std::time_t tempoAtual = std::chrono::system_clock::to_time_t(agora);
    std::string dataHoraVenda = std::ctime(&tempoAtual);
    if (!dataHoraVenda.empty() && dataHoraVenda.back() == '\n') dataHoraVenda.pop_back();

    std::string statusDaVenda = "Confirmada";
    if (formaPagamento == "Parcelado" || formaPagamento == "Financiamento") {
        statusDaVenda = "Pendente";
    }

    Venda novaVenda(
        cliente.getNome(),
        cliente.getDocumento(),
        filial,
        veiculoSelecionado->Tipo(),
        veiculoSelecionado->getModelo(),
        veiculoSelecionado->getAno(),
        veiculoSelecionado->getCor(),
        valorOriginal,
        estrategiaEscolhida->getNome(),
        valorFinal,
        formaPagamento,
        statusDaVenda,
        dataHoraVenda,
        nomeVendedor,
        entrada,
        parcelas,
        valorParcela,
        saldoRestante
        );

    historicoVendas.push_back(novaVenda);
    std::vector<Veiculo*>& estoque = getEstoqueFilial(filial);
    estoque.erase(std::remove(estoque.begin(), estoque.end(), veiculoSelecionado), estoque.end());
    delete veiculoSelecionado;
    veiculoSelecionado = nullptr;

    atualizarEstoqueCSV("data/estoque.csv");
    registrarVendaCSV(novaVenda);

    return QString::fromStdString(novaVenda.getResumo());
}

void GerenciadorDriveTech::listarHistoricoVendas() {
    try {
        if (historicoVendas.empty()) {
            std::cout << "\nNenhuma venda registrada ainda.\n";
            return;
        }

        std::cout << "\n=== HISTÓRICO DE VENDAS ===\n";
        for (const Venda& v : historicoVendas) {
            std::cout << v.getResumo() << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao listar histórico de vendas: " << e.what() << "\n";
    }
}

void GerenciadorDriveTech::listarHistoricoCliente(std::string docBusca) {
    try {
        if (historicoVendas.empty()) {
            std::cout << "\nNenhuma venda registrada ainda.\n";
            return;
        }

        bool encontrado = false;
        std::cout << "\n=== HISTÓRICO DO CLIENTE " << docBusca << " ===\n";
        for (const Venda& v : historicoVendas) {
            if (v.getDocumentoClienteRaw() == docBusca) {
                std::cout << v.getResumo() << "\n";
                encontrado = true;
            }
        }

        if (!encontrado) {
            std::cout << "Nenhuma venda encontrada para esse cliente.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao listar histórico do cliente: " << e.what() << "\n";
    }
}

void GerenciadorDriveTech::atualizarEstoqueCSV(const std::string& nomeArquivo) {

    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Erro ao atualizar o arquivo de estoque.");
    }

    arquivo << "Tipo,Modelo,Ano,Valor,Cor\n";

    for (Veiculo* v : estoqueLondrina) {
        arquivo << v->Tipo() << ","
                << v->getModelo() << ","
                << v->getAno() << ","
                << v->getValor() << ","
                << v->getCor() << "\n";
    }
    for (Veiculo* v : estoqueMaringa) {
        arquivo << v->Tipo() << ","
                << v->getModelo() << ","
                << v->getAno() << ","
                << v->getValor() << ","
                << v->getCor() << "\n";
    }
    for (Veiculo* v : estoqueCuritiba) {
        arquivo << v->Tipo() << ","
                << v->getModelo() << ","
                << v->getAno() << ","
                << v->getValor() << ","
                << v->getCor() << "\n";
    }

    arquivo.close();
    std::cout << "Estoque atualizado com sucesso em " << nomeArquivo << "\n";

}

void GerenciadorDriveTech::listarVeiculos() {
    std::cout << "\n=== VEÍCULOS POR FILIAL ===\n";

    std::cout << "\nLONDRINA (" << estoqueLondrina.size() << " veículos):\n";
    for (Veiculo* v : estoqueLondrina) {
        std::cout << "- " << v->Tipo() << ": " << v->getModelo()
        << " (" << v->getCor() << ", " << v->getAno()
        << ") - R$" << v->getValor() << "\n";
    }

    std::cout << "\nMARINGÁ (" << estoqueMaringa.size() << " veículos):\n";
    for (Veiculo* v : estoqueMaringa) {
        std::cout << "- " << v->Tipo() << ": " << v->getModelo()
        << " (" << v->getCor() << ", " << v->getAno()
        << ") - R$" << v->getValor() << "\n";
    }

    std::cout << "\nCURITIBA (" << estoqueCuritiba.size() << " veículos):\n";
    for (Veiculo* v : estoqueCuritiba) {
        std::cout << "- " << v->Tipo() << ": " << v->getModelo()
        << " (" << v->getCor() << ", " << v->getAno()
        << ") - R$" << v->getValor() << "\n";
    }
}

Veiculo* GerenciadorDriveTech::buscarVeiculos(const std::string& filial, const std::string& tipo, const std::string& modelo) {
    std::vector<Veiculo*>& estoqueFilial = getEstoqueFilial(filial);

    for (Veiculo* v : estoqueFilial) {
        if (v->Tipo() == tipo && v->getModelo() == modelo) {
            return v;
        }
    }
    return nullptr;
}

void GerenciadorDriveTech::registrarVendaCSV(const Venda& venda) {
    bool precisaCabecalho = false;
    std::ifstream check("data/historicoDeVendas.csv");
    if (!check.good() || check.peek() == std::ifstream::traits_type::eof()) {
        precisaCabecalho = true;
    }
    check.close();

    std::ofstream arquivo("data/historicoDeVendas.csv", std::ios::app);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Falha ao abrir/salvar o histórico de vendas. Verifique as permissões do arquivo.");
    }

    if (precisaCabecalho) {
        arquivo << "Vendedor,Cliente,Documento,Filial,Tipo,Modelo,Ano,Cor,ValorOriginal,Desconto,ValorFinal,FormaPagamento,Status,DataHora"
                << ",Entrada,Parcelas,ValorParcela,SaldoRestante\n";
    }

    arquivo << venda.getNomeVendedor() << ","
            << venda.getNomeCliente() << ","
            << venda.getDocumentoClienteRaw() << ","
            << venda.getFilial() << ","
            << venda.getTipo() << ","
            << venda.getModelo() << ","
            << venda.getAno() << ","
            << venda.getCor() << ","
            << venda.getValorOriginal() << ","
            << venda.getTipoDesconto() << ","
            << venda.getValorFinal() << ","
            << venda.getFormaPagamento() << ","
            << venda.getStatus() << ","
            << venda.getDataHora()
            << "," << venda.getValorEntrada()
            << "," << venda.getNumeroParcelas()
            << "," << venda.getValorParcela()
            << "," << venda.getSaldoRestante()
            << "\n";

}

void GerenciadorDriveTech::carregarVendedoresCSV(const std::string& nomeArquivo) {
    vendedores.clear();
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo de vendedores: " + nomeArquivo);
    }

    std::string linha;
    std::getline(arquivo, linha);

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string nome, login, senha;
        std::getline(ss, nome, ',');
        std::getline(ss, login, ',');
        std::getline(ss, senha, ',');
        if (!nome.empty() && !login.empty() && !senha.empty()) {
            vendedores.emplace_back(nome, login, senha);
        }
    }
}

Veiculo* GerenciadorDriveTech::buscarVeiculoExato(const std::string& filial, const std::string& tipo,
                                                  const std::string& modelo, int ano, const std::string& cor)
{
    std::vector<Veiculo*>& estoqueFilial = getEstoqueFilial(filial);

    for (Veiculo* v : estoqueFilial) {
        if (v->Tipo() == tipo && v->getModelo() == modelo &&
            v->getAno() == ano && v->getCor() == cor) {
            return v;
        }
    }
    return nullptr;

}

void GerenciadorDriveTech::carregarVendasCSV(const std::string& nomeArquivo) {
    historicoVendas.clear();
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o histórico de vendas: " + nomeArquivo);
    }

    std::string linha;
    std::getline(arquivo, linha);

    std::string errosDeLinha = "";
    int contadorLinha = 1;

    while (std::getline(arquivo, linha)) {
        contadorLinha++;
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        std::string item, vendedor, cliente, documento, filial, tipo, modelo, cor, desconto, pagamento, status, dataHora;
        int ano;
        double valorOriginal, valorFinal;

        double entrada = 0.0;
        int parcelas = 1;
        double valorParcela = 0.0;
        double saldoRestante = 0.0;

        try {
            std::getline(ss, vendedor, ',');
            std::getline(ss, cliente, ',');
            std::getline(ss, documento, ',');
            std::getline(ss, filial, ',');
            std::getline(ss, tipo, ',');
            std::getline(ss, modelo, ',');
            std::getline(ss, item, ','); ano = std::stoi(item);
            std::getline(ss, cor, ',');
            std::getline(ss, item, ','); valorOriginal = std::stod(item);
            std::getline(ss, desconto, ',');
            std::getline(ss, item, ','); valorFinal = std::stod(item);
            std::getline(ss, pagamento, ',');
            std::getline(ss, status, ',');
            std::getline(ss, dataHora, ',');
            if (std::getline(ss, item, ',')) entrada = std::stod(item);
            if (std::getline(ss, item, ',')) parcelas = std::stoi(item);
            if (std::getline(ss, item, ',')) valorParcela = std::stod(item);
            if (std::getline(ss, item, ',')) saldoRestante = std::stod(item);

            Venda venda(cliente, documento, filial, tipo, modelo, ano, cor,
                        valorOriginal, desconto, valorFinal, pagamento, status, dataHora, vendedor,
                        entrada, parcelas, valorParcela, saldoRestante);

            historicoVendas.push_back(venda);

        } catch (const std::exception& e) {
            errosDeLinha += "Linha " + std::to_string(contadorLinha) + " inválida: " + linha + "\n";
        }
    }
    arquivo.close();

    if (!errosDeLinha.empty()) {
        throw std::runtime_error("Erros ao carregar histórico de vendas:\n" + errosDeLinha);
    }
}

Cliente* GerenciadorDriveTech::buscarClientePorDocumento(const std::string& documento) {
    std::string documentoLimpo = limparDocumento(documento);
    for (Cliente& cliente : clientes) {
        if (cliente.getDocumento() == documentoLimpo) {
            return &cliente;
        }
    }
    return nullptr;
}


std::string GerenciadorDriveTech::getVendedorAtivoNome() const {
    return vendedorAtivoNome;
}

std::vector<Veiculo*>& GerenciadorDriveTech::getEstoqueFilial(const std::string& filial) {
    if (filial == "Londrina") return estoqueLondrina;
    if (filial == "Maringa")  return estoqueMaringa;
    if (filial == "Curitiba") return estoqueCuritiba;
    throw std::runtime_error("Filial inválida: " + filial);
}

const std::vector<Venda>& GerenciadorDriveTech::getHistoricoVendas() const {
    return historicoVendas;
}

Vendedor* GerenciadorDriveTech::getVendedorAtivo() {
    for (Vendedor& v : vendedores) {
        if (v.getLogin() == vendedorAtivoLogin) {
            return &v;
        }
    }
    return nullptr;
}

std::set<std::string> GerenciadorDriveTech::getModelosPorTipo(const std::string& tipo) const {
    auto it = modelosPorTipo.find(tipo);
    if (it != modelosPorTipo.end()) return it->second;
    return {};
}

const std::vector<Cliente>& GerenciadorDriveTech::getClientes() const {
    return clientes;
}

std::set<int> GerenciadorDriveTech::getAnoPorModelo(const std::string& modelo) const {
    std::set<int> anos;
    auto verificar = [&](const std::vector<Veiculo*>& estoque){
        for (Veiculo* v : estoque) {
            if (v->getModelo() == modelo) {
                anos.insert(v->getAno());
            }
        }
    };
    verificar(estoqueLondrina);
    verificar(estoqueMaringa);
    verificar(estoqueCuritiba);
    return anos;
}

std::set<std::string> GerenciadorDriveTech::getCorPorAno(const std::string& modelo, int ano) const {
    std::set<std::string> cores;
    auto verificar = [&](const std::vector<Veiculo*>& estoque){
        for (Veiculo* v : estoque) {
            if (v->getModelo() == modelo && v->getAno() == ano) {
                cores.insert(v->getCor());
            }
        }
    };
    verificar(estoqueLondrina);
    verificar(estoqueMaringa);
    verificar(estoqueCuritiba);
    return cores;
}
