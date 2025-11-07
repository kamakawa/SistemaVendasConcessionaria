#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>   // para data/hora
#include <ctime>    // para ctime
#include <exception> // para exceções
#include <iomanip> // para setprecision

class Pessoa {
private:
    std::string nome;
    std::string documento;

public:
    Pessoa(std::string nome, std::string documento) {
        setNome(nome);
        setDocumento(documento);
    }

    virtual ~Pessoa() {}

    std::string getNome() const { return nome; }
    std::string getDocumento() const { return documento; }

    void setNome(std::string nome) { this->nome = nome; }
    void setDocumento(std::string doc) { this->documento = doc; }
};

class Cliente : public Pessoa {
public:
    Cliente(std::string nome, std::string documento) : Pessoa(nome, documento) {}
};

class Vendedor : public Pessoa {
private:
    std::string login;
    std::string senha;

public:
    Vendedor(std::string nome, std::string documento, std::string login, std::string senha)
        : Pessoa(nome, documento) {
        setLogin(login);
        setSenha(senha);
    }

    ~Vendedor() {}

    std::string getLogin() const { return login; }
    std::string getSenha() const { return senha; }

    void setLogin(std::string l) { login = l; }
    void setSenha(std::string s) { senha = s; }
};

class Veiculo {
private:
    std::string modelo;
    std::string cor;
    std::string tipo;
    double valor;
    int ano;

public:
    virtual ~Veiculo() {}

    std::string getModelo() const { return modelo; }
    std::string getCor() const { return cor; }
    std::string getTipo() const { return tipo; }
    double getValor() const { return valor; }
    int getAno() const { return ano; }

    void setModelo(std::string m) { modelo = m; }
    void setCor(std::string c) { cor = c; }
    void setTipo(std::string t) { tipo = t; }
    void setValor(double v) { valor = v; }
    void setAno(int a) { ano = a; }

    virtual std::string Tipo() const = 0;
};

class Carro : public Veiculo {
private:
    std::string nomeCarro;

public:
    Carro(std::string nome, std::string modelo, std::string cor, double valor, int ano) {
        setNomeCarro(nome);
        setModelo(modelo);
        setCor(cor);
        setValor(valor);
        setAno(ano);
        setTipo("Carro");
    }

    std::string Tipo() const override {
        return getTipo();
    }

    std::string getNomeCarro() const { return nomeCarro; }
    void setNomeCarro(std::string nome) { nomeCarro = nome; }
};

class Moto : public Veiculo {
private:
    std::string nomeMoto;

public:
    Moto(std::string nome, std::string modelo, std::string cor, double valor, int ano) {
        setNomeMoto(nome);
        setModelo(modelo);
        setCor(cor);
        setValor(valor);
        setAno(ano);
        setTipo("Moto");
    }

    std::string Tipo() const override {
        return getTipo();
    }

    std::string getNomeMoto() const { return nomeMoto; }
    void setNomeMoto(std::string nome) { nomeMoto = nome; }
};

//classe para salvar o histórico de vendas
class Venda {
private:
    std::string nomeCliente;
    std::string documentoCliente;
    std::string filial;
    std::string tipoVeiculo;
    std::string modeloVeiculo;
    int anoVeiculo;
    double valorOriginal;
    std::string tipoDesconto;
    double valorFinal;
    std::string formaPagamento;
    std::string status;
    std::string dataHora;
    std::string nomeVendedor;

public:
    Venda(std::string nome, std::string doc, std::string fil, std::string tipoV,
          std::string modV, int anoV, double valOrig, std::string desc,
          double valFinal, std::string pag, std::string stat, std::string dataHoraVenda,
          std::string vendedorNome)
        : nomeCliente(nome), documentoCliente(doc), filial(fil), tipoVeiculo(tipoV),
          modeloVeiculo(modV), anoVeiculo(anoV), valorOriginal(valOrig),
          tipoDesconto(desc), valorFinal(valFinal), formaPagamento(pag),
          status(stat), dataHora(dataHoraVenda), nomeVendedor(vendedorNome) {}

    // Getters
    std::string getDocumentoClienteRaw() const { return documentoCliente; } 
    std::string getDataHora() const { return dataHora; }
    std::string getNomeVendedor() const { return nomeVendedor; }
    std::string getNomeCliente() const { return nomeCliente; }
    double getValorOriginal() const { return valorOriginal; }
    double getValorFinal() const { return valorFinal; }
    std::string getTipoDesconto() const { return tipoDesconto; }

    std::string getResumo() const {
        std::ostringstream oss;
        oss << "Cliente: " << nomeCliente
            << " | Vendedor: " << nomeVendedor
            << " | Veículo: " << tipoVeiculo << " " << modeloVeiculo << " (" << anoVeiculo << ")"
            << " | Valor Final: R$" << std::fixed << std::setprecision(2) << valorFinal
            << " | Filial: " << filial
            << " | Data/Hora: " << dataHora;
        return oss.str();
    }
};

//Strategy
class DescontoStrategy {
public:
    virtual double aplicarDesconto(double valor) const = 0;
    virtual std::string getNome() const = 0;
    virtual ~DescontoStrategy() {}
};

class SemDesconto : public DescontoStrategy {
public:
    double aplicarDesconto(double valor) const override {
        return valor;
    }
    std::string getNome() const override {
        return "Tarifa padrão";
    }
};

class DescontoClienteFiel : public DescontoStrategy {
    public:
    double aplicarDesconto(double valor) const override {
        return valor * 0.95; // 5%
    }
    std::string getNome() const override {
        return "Cliente Fidelidade (5%)";
    }
};

class DescontoPromocional : public DescontoStrategy {
    public:
    double aplicarDesconto(double valor) const override {
        return valor * 0.90; // 10%
    }
    std::string getNome() const override {
        return "Promoção Especial (10%)";
    }
};

class VendaCorporativa : public DescontoStrategy {
public:
    double aplicarDesconto(double valor) const override {
        return valor * 0.85; // 15% de desconto
    }
    std::string getNome() const override {
        return "Vendas Corporativas (15%)";
    }
};

// Singleton
class GerenciadorDriveTech {
private:
    static GerenciadorDriveTech* instancia;

    std::vector<Vendedor> vendedores;
    std::vector<Veiculo*> estoqueLondrina;
    std::vector<Veiculo*> estoqueMaringa;
    std::vector<Veiculo*> estoqueCuritiba;
    std::vector<Cliente> clientes;
    std::vector<Venda> historicoVendas;

    std::string vendedorAtivoNome;
    std::string vendedorAtivoLogin;

    std::vector<Veiculo*>& getEstoqueFilial(const std::string& filial) {
        if (filial == "Londrina") return estoqueLondrina;
        if (filial == "Maringá") return estoqueMaringa;
        if (filial == "Curitiba") return estoqueCuritiba;
        throw std::invalid_argument("Filial inválida: " + filial);
    }

    GerenciadorDriveTech() : vendedorAtivoNome(""), vendedorAtivoLogin("") {}

public:
    GerenciadorDriveTech(const GerenciadorDriveTech&) = delete;
    GerenciadorDriveTech& operator=(const GerenciadorDriveTech&) = delete;

    static GerenciadorDriveTech* obterInstancia() {
        if (instancia == nullptr) {
            instancia = new GerenciadorDriveTech();
        }
        return instancia;
    }

    bool autenticar(const std::string& login, const std::string& senha) {
        int opc;
        for (const Vendedor& vendedor : vendedores) {
            if (vendedor.getLogin() == login) {
                if (vendedor.getSenha() == senha) {
                    vendedorAtivoNome = vendedor.getNome();
                    vendedorAtivoLogin = vendedor.getLogin();

                    do{
                        std::cout << "Olá, " << vendedor.getNome() << std::endl;
                        std::cout << "\n======MENU VENDEDOR========" << std::endl;
                        std::cout << "1. Listar Veículos no estoque\n";
                        std::cout << "2. Consulta de estoque\n";
                        std::cout << "3. Vender\n";
                        std::cout << "4. Histórico de vendas\n";
                        std::cout << "5. Histórico de um cliente\n";
                        std::cout << "6. Sair\n";
                        std::cout << "Escolha uma opção: ";
                        std::cin >> opc;

                        switch (opc) {
                            case 1: {
                                listarVeiculos();
                                break;
                            }
                            case 2: {
                                buscarVeiculos();
                                break;
                            }
                            case 3: {
                                venda();
                                break;
                            }
                            case 4: {
                                listarHistoricoVendas();
                                break;
                            }
                            case 5: {
                                std::cin.ignore();
                                std::string doc;
                                std::cout << "Digite o documento do cliente (CPF/CNPJ) para filtrar: ";
                                std::getline(std::cin, doc);
                                listarHistoricoCliente(doc);
                                break;
                            }
                            case 6:
                                std::cout << "Saindo... Até breve " << vendedor.getNome() << std::endl;
                                vendedorAtivoNome = "";
                                vendedorAtivoLogin = "";
                                break;
                            default:
                                std::cout << "Opção inválida!\n";
                        }

                    }while(opc != 6);
                    return true;
                }
                std::cout << "Senha incorreta!\n";
                return false;
            }
        }
        std::cout << "Login não encontrado!\n";
        return false;
    }

    void cadastrarVendedor(const Vendedor& novoVendedor) {
        for (const Vendedor& vendedor : vendedores) {
            if (vendedor.getLogin() == novoVendedor.getLogin()) {
                std::cout << "Vendedor já cadastrado!\n";
                return;
            }
        }
        vendedores.push_back(novoVendedor);
        std::cout << " Vendedor cadastrado com sucesso!\n" << "Bem-Vindo ao time!" << std::endl;
    }

    void cadastrarCliente(const Cliente& novoCliente) {
        for (const Cliente& cliente : clientes) {
            if (cliente.getDocumento() == novoCliente.getDocumento()) {
                std::cout << "Cliente já cadastrado!\n";
                return;
            }
        }
        clientes.push_back(novoCliente);
        std::cout << "Cliente cadastrado com sucesso!\n";
    }

    void carregarEstoqueCSV(const std::string& nomeArquivo) {
        try {
            std::ifstream arquivo(nomeArquivo);
            std::string linha;

            if (!arquivo.is_open()) {
                throw std::runtime_error("Erro ao abrir o arquivo: " + nomeArquivo);
            }

            std::getline(arquivo, linha); 

            for (Veiculo* v : estoqueLondrina) delete v;
            for (Veiculo* v : estoqueMaringa) delete v;
            for (Veiculo* v : estoqueCuritiba) delete v;
            estoqueLondrina.clear();
            estoqueMaringa.clear();
            estoqueCuritiba.clear();

            int contador = 0;
            while (std::getline(arquivo, linha)) {
                if (linha.empty()) continue; // pula linhas vazias
                std::stringstream ss(linha);
                std::string tipo, modelo, anoStr, valorStr, cor;

                std::getline(ss, tipo, ',');
                std::getline(ss, modelo, ',');
                std::getline(ss, anoStr, ',');
                std::getline(ss, valorStr, ',');
                std::getline(ss, cor, ',');

                try {
                    int ano = std::stoi(anoStr);
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
                        contador++;
                    }
                } catch (const std::exception& e) {
                    std::cerr << "Linha de estoque com formato inválido: " << linha << " | erro: " << e.what() << "\n";
                }
            }

            arquivo.close();
            std::cout << "Estoque carregado com sucesso!\n";
            std::cout << "Londrina: " << estoqueLondrina.size() << " veículos\n";
            std::cout << "Maringá: " << estoqueMaringa.size() << " veículos\n";
            std::cout << "Curitiba: " << estoqueCuritiba.size() << " veículos\n";
        } catch (const std::exception& e) {
            std::cerr << "Erro em carregarEstoqueCSV: " << e.what() << "\n";
        }
    }

    void venda() {
        try {
            std::string nomeCliente, documentoCliente;
            bool clienteEncontrado = false;
            Cliente clienteSelecionado("", "");
            int opc;
            int opcHistorico;

            std::cout << "\n=== REGISTRO DE VENDA ===\n";
            std::cin.ignore();
            std::cout << "Digite o nome do cliente: ";
            std::getline(std::cin, nomeCliente);
            std::cout << "Digite o número de algum documento válido (CPF/CNPJ): ";
            std::getline(std::cin, documentoCliente);

            for (const Cliente& c : clientes) {
                if (c.getNome() == nomeCliente && c.getDocumento() == documentoCliente) {
                    clienteEncontrado = true;
                    clienteSelecionado = c;
                    break;
                }
            }

            if (!clienteEncontrado) {
                std::cout << "Cliente não encontrado.\nDeseja cadastrar? (1-Sim / 2-Não): ";
                std::cin >> opc;

                if (opc == 1) {
                    cadastrarCliente(Cliente(nomeCliente, documentoCliente));
                    clienteSelecionado = Cliente(nomeCliente, documentoCliente);
                } else {
                    std::cout << "Operação cancelada.\n";
                    return;
                }
            }

            std::cout << "Deseja ver o Histórico de compras de " << nomeCliente << std::endl;
            std::cout << "1. Sim\n" << "2. Não" << std::endl;
            std::cin >> opcHistorico;

            if(opcHistorico == 1){
                listarHistoricoCliente(documentoCliente);
            }
            
            std::string filial;
            do {
                std::cout << "\nSelecione a filial:\n";
                std::cout << "1. Curitiba\n2. Maringá\n3. Londrina\nOpção: ";
                std::cin >> opc;
            } while (opc < 1 || opc > 3);

            switch (opc) {
                case 1: filial = "Curitiba"; break;
                case 2: filial = "Maringá"; break;
                case 3: filial = "Londrina"; break;
            }

            std::string formaPagamento;
            int opcPagamento;
            std::cout << "\nSelecione a forma de pagamento:\n";
            std::cout << "1. À vista\n2. Parcelado\nOpção: ";
            std::cin >> opcPagamento;
            
            if (opcPagamento == 1) {
                formaPagamento = "À vista";
            } else {
                formaPagamento = "Parcelado";
            }

            struct ItemCompraTemp {
                std::string tipo;
                std::string modelo;
                std::string cor;
                int ano;
                double valorOriginal;
            };
            std::vector<ItemCompraTemp> carrinho;
            double totalSemDesconto = 0.0;

            auto agora = std::chrono::system_clock::now();
            std::time_t tempoAtual = std::chrono::system_clock::to_time_t(agora);
            std::string dataHoraVenda = std::ctime(&tempoAtual);
            if (!dataHoraVenda.empty() && dataHoraVenda.back() == '\n') dataHoraVenda.pop_back();

            bool continuar = true;
            while (continuar) {
                std::string tipo, modelo, cor;
                int ano;
                std::cout << "\nDigite o tipo de veículo (Carro/Moto): ";
                std::cin >> tipo;
                std::cin.ignore(); 
                std::cout << "Modelo: ";
                std::getline(std::cin, modelo); 
                std::cout << "Cor: ";
                std::getline(std::cin, cor);    
                std::cout << "Ano: ";
                std::cin >> ano;

                Veiculo* veiculoSelecionado = nullptr;
                int indiceRemover = -1;

                std::vector<Veiculo*>& estoqueFilial = getEstoqueFilial(filial);

                for (size_t i = 0; i < estoqueFilial.size(); ++i) {
                    Veiculo* v = estoqueFilial[i];
                    if (v->Tipo() == tipo && v->getModelo() == modelo &&
                        v->getCor() == cor && v->getAno() == ano) {
                        veiculoSelecionado = v;
                        indiceRemover = static_cast<int>(i);
                        break;
                    }
                }

                if (!veiculoSelecionado) {
                    std::cout << "\nVeículo não encontrado ou indisponível.\n";
                    int tentar;
                    std::cout << "Deseja tentar pesquisar outro veículo? (1-Sim / 2-Não): ";
                    std::cin >> tentar;
                    if (tentar == 1) continue;
                    else break;
                }

                std::cout << "\nVeículo disponível!\n";
                std::cout << tipo << " " << modelo << " (" << cor << ", " << ano
                        << ") - R$" << veiculoSelecionado->getValor() << "\n";

                std::cout << "Adicionar este veículo à compra? (1-Sim / 2-Não): ";
                int opcAdicionar;
                std::cin >> opcAdicionar;
                if (opcAdicionar != 1) {
                    int querContinuar;
                    std::cout << "Deseja pesquisar/selecionar outro veículo? (1-Sim / 2-Não): ";
                    std::cin >> querContinuar;
                    if (querContinuar == 1) continue;
                    else break;
                }

                ItemCompraTemp item;
                item.tipo = tipo;
                item.modelo = modelo;
                item.cor = cor;
                item.ano = ano;
                item.valorOriginal = veiculoSelecionado->getValor();
                carrinho.push_back(item);
                totalSemDesconto += item.valorOriginal;

                try {
                    if (indiceRemover >= 0 && indiceRemover < static_cast<int>(estoqueFilial.size())) {
                        delete estoqueFilial[indiceRemover];
                        estoqueFilial.erase(estoqueFilial.begin() + indiceRemover);
                    } else {
                        throw std::out_of_range("Índice do veículo para remoção é inválido.");
                    }
                } catch (const std::exception& e) {
                    std::cerr << "Erro ao remover veículo do estoque: " << e.what() << "\n";
                }

                int mais;
                std::cout << "\nDeseja adicionar outro veículo a essa compra? (1-Sim / 2-Não): ";
                std::cin >> mais;
                if (mais == 1) {
                    continuar = true;
                } else {
                    continuar = false;
                }
            } 

            if (carrinho.empty()) {
                std::cout << "Nenhum veículo adicionado. Operação encerrada.\n";
                return;
            }

            DescontoStrategy* estrategiaEscolhida = nullptr;
            int escolhaDesconto;
            std::cout << "\nSelecione o tipo de desconto para essa compra:\n";
            std::cout << "1. Sem desconto\n";
            std::cout << "2. Cliente Fidelidade (5%)\n";
            std::cout << "3. Promoção Especial (10%)\n";
            std::cout << "4. Vendas Corporativas (15% - 2+ veículos)\n";
            std::cout << "Opção: ";
            std::cin >> escolhaDesconto;

            bool aplicouVendaCorporativa = false;
            switch (escolhaDesconto) {
                case 2: {
                    bool jaComprou = false;
                    for (const Venda& v : historicoVendas) {
                        if (v.getDocumentoClienteRaw() == documentoCliente) {
                            jaComprou = true;
                            break;
                        }
                    }
                    if (jaComprou) {
                        estrategiaEscolhida = new DescontoClienteFiel();
                        std::cout << "Cliente fiel detectado — desconto de 5% será considerado.\n";
                    } else {
                        estrategiaEscolhida = new SemDesconto();
                        std::cout << "Esse cliente ainda não possui histórico de compras. Desconto de fidelidade não será aplicado.\n";
                    }
                    break;
                }
                case 3:
                    estrategiaEscolhida = new DescontoPromocional();
                    break;
                case 4: {
                    if (carrinho.size() >= 2) {
                        estrategiaEscolhida = new VendaCorporativa();
                        aplicouVendaCorporativa = true;
                        std::cout << "Venda corporativa selecionada e válida (compra com " << carrinho.size() << " veículos).\n";
                    } else {
                        estrategiaEscolhida = new SemDesconto();
                        std::cout << "Venda corporativa inválida: é necessário comprar 2 ou mais veículos para aplicar.\n";
                    }
                    break;
                }
                default:
                    estrategiaEscolhida = new SemDesconto();
                    break;
            }

            double totalFinal = 0.0;
            std::vector<double> valoresFinaisPorItem(carrinho.size(), 0.0);

            if (aplicouVendaCorporativa) {
                double totalComDesconto = estrategiaEscolhida->aplicarDesconto(totalSemDesconto); // total * 0.85
                for (size_t i = 0; i < carrinho.size(); ++i) {
                    double proporcao = carrinho[i].valorOriginal / totalSemDesconto;
                    valoresFinaisPorItem[i] = totalComDesconto * proporcao;
                }
                totalFinal = totalComDesconto;
            } else {
                for (size_t i = 0; i < carrinho.size(); ++i) {
                    valoresFinaisPorItem[i] = estrategiaEscolhida->aplicarDesconto(carrinho[i].valorOriginal);
                    totalFinal += valoresFinaisPorItem[i];
                }
            }

            std::cout << "\n=== RESUMO FINAL DA COMPRA ===\n";
            std::cout << "Cliente: " << clienteSelecionado.getNome() << " | Documento: " << documentoCliente << "\n";
            std::cout << "Filial: " << filial << " | Vendedor: " << vendedorAtivoNome << " | Data/Hora: " << dataHoraVenda << "\n";
            std::cout << "Itens:\n";
            for (size_t i = 0; i < carrinho.size(); ++i) {
                std::cout << "- " << carrinho[i].tipo << " " << carrinho[i].modelo << " (" << carrinho[i].ano << ")"
                          << " --> R$" << std::fixed << std::setprecision(2) << carrinho[i].valorOriginal
                          << "  | Valor Final: R$" << valoresFinaisPorItem[i] << "\n";
            }
            std::cout << "Subtotal: R$" << totalSemDesconto << "\n";
            if (aplicouVendaCorporativa) {
                std::cout << "Desconto aplicado: " << "Vendas Corporativas (15%)" << " (no total) \n";
            } else {
                std::cout << "Desconto aplicado: " << estrategiaEscolhida->getNome() << "\n";
            }
            std::cout << "Total a pagar: R$" << totalFinal << "\n";
            std::cout << "Forma de pagamento: " << formaPagamento << "\n";

            std::cout << "Confirmar pagamento de R$" << totalFinal << "? (1-Sim / 2-Não): ";
            int confirma;
            std::cin >> confirma;
            if (confirma != 1) {
                std::cout << "Pagamento cancelado. Operação encerrada.\n";
                delete estrategiaEscolhida;
                return;
            }

            try {
                std::ofstream arquivo("vendas.csv", std::ios::app);
                if (!arquivo.is_open()) {
                    throw std::runtime_error("Não foi possível abrir vendas.csv para escrita.");
                }
                for (size_t i = 0; i < carrinho.size(); ++i) {
                    // grava: NomeCliente,Documento,Filial,Tipo,Modelo,Ano,ValorOriginal,TipoDesconto,ValorFinal,FormaPagamento,Status,DataHora,NomeVendedor
                    arquivo << clienteSelecionado.getNome() << ","
                            << documentoCliente << ","
                            << filial << ","
                            << carrinho[i].tipo << ","
                            << carrinho[i].modelo << ","
                            << carrinho[i].ano << ","
                            << carrinho[i].valorOriginal << ","
                            << (aplicouVendaCorporativa ? "Vendas Corporativas (15%)" : estrategiaEscolhida->getNome()) << ","
                            << valoresFinaisPorItem[i] << ","
                            << formaPagamento << ","
                            << "Confirmada,"
                            << dataHoraVenda << ","
                            << vendedorAtivoNome << "\n";

                    // salva também no histórico em memória
                    historicoVendas.push_back(
                        Venda(
                            clienteSelecionado.getNome(),
                            documentoCliente,
                            filial,
                            carrinho[i].tipo,
                            carrinho[i].modelo,
                            carrinho[i].ano,
                            carrinho[i].valorOriginal,
                            (aplicouVendaCorporativa ? "Vendas Corporativas (15%)" : estrategiaEscolhida->getNome()),
                            valoresFinaisPorItem[i],
                            formaPagamento,
                            "Confirmada",
                            dataHoraVenda,
                            vendedorAtivoNome
                        )
                    );
                }
                arquivo.close();
            } catch (const std::exception& e) {
                std::cerr << "Erro ao gravar vendas.csv: " << e.what() << "\n";
            }

            // atualiza CSV de estoque com os itens removidos
            atualizarEstoqueCSV("estoque.csv");

            std::cout << "\nCompra(s) registrada(s) com sucesso! Total pago: R$" << totalFinal << "\n";

            delete estrategiaEscolhida;

        } catch (const std::exception& e) {
            std::cerr << "Erro durante o processo de venda: " << e.what() << "\n";
        }
    }

    void listarHistoricoVendas() {
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

    void listarHistoricoCliente(std::string docBusca) {
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

    void atualizarEstoqueCSV(const std::string& nomeArquivo) {
        try {
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
        } catch (const std::exception& e) {
            std::cerr << "Erro em atualizarEstoqueCSV: " << e.what() << "\n";
        }
    }

    void listarVeiculos() {
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

    bool buscarVeiculos() {
        try {
            std::string tipo, modelo, cor;
            int ano;
            bool encontrado = false;

            int opcFilial;
            std::cout << "Selecione a filial para consulta:\n";
            std::cout << "1. Londrina\n2. Maringá\n3. Curitiba\nOpção: ";
            std::cin >> opcFilial;
            
            std::string filial;
            switch (opcFilial) {
                case 1: filial = "Londrina"; break;
                case 2: filial = "Maringá"; break;
                case 3: filial = "Curitiba"; break;
                default: 
                    std::cout << "Opção inválida!\n";
                    return false;
            }

            std::cout << "Digite o tipo de veículo (Carro/Moto): ";
            std::cin >> tipo;
            std::cin.ignore();
            std::cout << "Modelo: ";
            std::getline(std::cin, modelo);
            std::cout << "Cor: ";
            std::getline(std::cin, cor);
            std::cout << "Ano: ";
            std::cin >> ano;

            std::vector<Veiculo*>& estoqueFilial = getEstoqueFilial(filial);
            
            for (Veiculo* v : estoqueFilial) {
                if (v->Tipo() == tipo &&
                    v->getModelo() == modelo &&
                    v->getCor() == cor &&
                    v->getAno() == ano) {
                    std::cout << "\nStatus: Disponível em " << filial << ":\n";
                    std::cout << "- " << v->Tipo() << ": " << v->getModelo()
                              << " (" << v->getCor() << ", " << v->getAno()
                              << ") - R$" << v->getValor() << "\n";
                    encontrado = true;
                    return encontrado;
                }
            }

            if (!encontrado) {
                std::cout << "Veículo indisponível em " << filial << "\n";
                return false;
            }

            return encontrado;
        } catch (const std::exception& e) {
            std::cerr << "Erro em buscarVeiculos: " << e.what() << "\n";
            return false;
        }
    }

};

GerenciadorDriveTech* GerenciadorDriveTech::instancia = nullptr;

int main() {
    GerenciadorDriveTech* sistema = GerenciadorDriveTech::obterInstancia();
    sistema->carregarEstoqueCSV("estoque.csv"); // CARREGA UMA VEZ NO INÍCIO
    sistema->cadastrarVendedor(Vendedor("Vendedor 1", "doc1", "vendedor1", "senha1"));
    sistema->cadastrarVendedor(Vendedor("Vendedor 2", "doc2", "vendedor2", "senha2"));
    sistema->cadastrarVendedor(Vendedor("Vendedor 3", "doc3", "vendedor3", "senha3"));
    sistema->cadastrarVendedor(Vendedor("Vendedor 4", "doc4", "vendedor4", "senha4"));
    
    int opcao;

    do {
        std::cout << "\n=== MENU DRIVE TECH ===\n";
        std::cout << "1. Cadastrar Cliente\n";
        std::cout << "2. Login de Vendedor\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpa buffer

        switch (opcao) {
            case 1: {
                std::string nome, doc;
                std::cout << "Nome do cliente: ";
                std::getline(std::cin, nome);
                std::cout << "Documento: ";
                std::getline(std::cin, doc);
                sistema->cadastrarCliente(Cliente(nome, doc));
                break;
            }
            case 2: {
                std::string login, senha;
                std::cout << "Login: ";
                std::getline(std::cin, login);
                std::cout << "Senha: ";
                std::getline(std::cin, senha);
                sistema->autenticar(login, senha);
                break;
            }

            case 3:
                std::cout << "Encerrando o sistema...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }

    } while (opcao != 3);

    return 0;
}