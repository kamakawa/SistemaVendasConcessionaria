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
    std::string formaPagamento; // Falta adicionar isso no seu CSV e na função venda()
    std::string status;
    std::string dataHora;
    std::string nomeVendedor; // nome do vendedor que realizou a venda

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
        return "Sem desconto";
    }
};

class DescontoAVista : public DescontoStrategy {
public:
    double aplicarDesconto(double valor) const override {
        return valor * 0.95; // 5% de desconto
    }
    std::string getNome() const override {
        return "À vista (5%)";
    }
};

class DescontoClienteFiel : public DescontoStrategy {
public:
    double aplicarDesconto(double valor) const override {
        return valor * 0.90; // 10%
    }
    std::string getNome() const override {
        return "Cliente fiel (10%)";
    }
};

class DescontoPromocional : public DescontoStrategy {
public:
    double aplicarDesconto(double valor) const override {
        return valor * 0.85; // 15%
    }
    std::string getNome() const override {
        return "Promoção (15%)";
    }
};

// Singleton
class GerenciadorDriveTech {
private:
    static GerenciadorDriveTech* instancia;

    std::vector<Vendedor> vendedores;
    std::vector<Veiculo*> estoque;
    std::vector<Cliente> clientes;
    std::vector<Venda> historicoVendas;

    // [NOVO] armazena o vendedor que está logado atualmente (nome e login)
    std::string vendedorAtivoNome;
    std::string vendedorAtivoLogin;

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
                    // [NOVO] guarda o vendedor logado
                    vendedorAtivoNome = vendedor.getNome();
                    vendedorAtivoLogin = vendedor.getLogin();

                    do{
                        //Iago, aqui criei um mini menu no terminal só para teste para ver se a lógica está correta
                        //Funcionalidades apenas para o vendedor logado
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
                                // [NOVO] pedir documento do cliente para filtrar
                                std::cin.ignore();
                                std::string doc;
                                std::cout << "Digite o documento do cliente (CPF/CNPJ) para filtrar: ";
                                std::getline(std::cin, doc);
                                listarHistoricoCliente(doc);
                                break;
                            }
                            case 6:
                                std::cout << "Saindo... Até breve " << vendedor.getNome() << std::endl;
                                // [NOVO] limpa o vendedor ativo ao sair
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

            std::getline(arquivo, linha); // Ignora o cabeçalho

            // Limpa o estoque anterior
            for (Veiculo* v : estoque) {
                delete v;
            }
            estoque.clear();

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

                    if (tipo == "Carro") {
                        estoque.push_back(new Carro(modelo, modelo, cor, valor, ano));
                    } else if (tipo == "Moto") {
                        estoque.push_back(new Moto(modelo, modelo, cor, valor, ano));
                    }
                } catch (const std::exception& e) {
                    std::cerr << "Linha de estoque com formato inválido: " << linha << " | erro: " << e.what() << "\n";
                    // continuar lendo próximas linhas
                }
            }

            arquivo.close();
            std::cout << "Estoque carregado com sucesso a partir de " << nomeArquivo << "\n";
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

            // Verifica se o cliente já está cadastrado
            for (const Cliente& c : clientes) {
                if (c.getNome() == nomeCliente && c.getDocumento() == documentoCliente) {
                    clienteEncontrado = true;
                    clienteSelecionado = c;
                    break;
                }
            }

            // Se o cliente não existir, oferece cadastro
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
                listarHistoricoCliente(documentoCliente); // [NOVO] passa documento (CPF/CNPJ)
            }
            // Escolha da filial
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

            // --- NOVA LÓGICA: sessão de compra com 1 ou mais veículos ---
            std::vector<Veiculo*> comprados_ptrs; // para guardar ponteiros removidos do estoque (já deletados)
            struct ItemCompraTemp {
                std::string tipo;
                std::string modelo;
                std::string cor;
                int ano;
                double valorOriginal;
            };
            std::vector<ItemCompraTemp> carrinho;
            double totalSemDesconto = 0.0;

            // obtem timestamp único para toda a sessão de compra
            auto agora = std::chrono::system_clock::now();
            std::time_t tempoAtual = std::chrono::system_clock::to_time_t(agora);
            std::string dataHoraVenda = std::ctime(&tempoAtual);
            if (!dataHoraVenda.empty() && dataHoraVenda.back() == '\n') dataHoraVenda.pop_back();

            bool continuar = true;
            while (continuar) {
                // Escolha do veículo
                std::string tipo, modelo, cor;
                int ano;
                std::cout << "\nDigite o tipo de veículo (Carro/Moto): ";
                std::cin >> tipo;
                std::cin.ignore(); // limpa buffer
                std::cout << "Modelo: ";
                std::getline(std::cin, modelo); // lê incluindo espaços
                std::cout << "Cor: ";
                std::getline(std::cin, cor);    // lê incluindo espaços
                std::cout << "Ano: ";
                std::cin >> ano;

                // Verifica disponibilidade
                Veiculo* veiculoSelecionado = nullptr;
                int indiceRemover = -1;

                for (size_t i = 0; i < estoque.size(); ++i) {
                    Veiculo* v = estoque[i];
                    if (v->Tipo() == tipo && v->getModelo() == modelo &&
                        v->getCor() == cor && v->getAno() == ano) {
                        veiculoSelecionado = v;
                        indiceRemover = static_cast<int>(i);
                        break;
                    }
                }

                if (!veiculoSelecionado) {
                    std::cout << "\nVeículo não encontrado ou indisponível.\n";
                    // pergunta se quer tentar outro veículo
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
                    // pergunta se deseja continuar comprando outros
                    int querContinuar;
                    std::cout << "Deseja pesquisar/selecionar outro veículo? (1-Sim / 2-Não): ";
                    std::cin >> querContinuar;
                    if (querContinuar == 1) continue;
                    else break;
                }

                // registra item no "carrinho" temporário
                ItemCompraTemp item;
                item.tipo = tipo;
                item.modelo = modelo;
                item.cor = cor;
                item.ano = ano;
                item.valorOriginal = veiculoSelecionado->getValor();
                carrinho.push_back(item);
                totalSemDesconto += item.valorOriginal;

                // Remove do estoque (em memória) imediatamente para evitar duplicata em mesma sessão
                try {
                    if (indiceRemover >= 0 && indiceRemover < static_cast<int>(estoque.size())) {
                        // guarda ponteiro para deletar depois (já vamos deletar agora)
                        delete estoque[indiceRemover];
                        estoque.erase(estoque.begin() + indiceRemover);
                    } else {
                        throw std::out_of_range("Índice do veículo para remoção é inválido.");
                    }
                } catch (const std::exception& e) {
                    std::cerr << "Erro ao remover veículo do estoque: " << e.what() << "\n";
                }

                // pergunta se quer comprar mais um veículo antes de finalizar a compra
                int mais;
                std::cout << "\nDeseja adicionar outro veículo a essa compra? (1-Sim / 2-Não): ";
                std::cin >> mais;
                if (mais == 1) {
                    continuar = true;
                    // continuar o loop de compra (estoque já atualizado)
                } else {
                    continuar = false;
                }
            } // fim do loop de adicionar veículos

            if (carrinho.empty()) {
                std::cout << "Nenhum veículo adicionado. Operação encerrada.\n";
                // caso nada tenha sido adicionado, nada a salvar
                return;
            }

            // Agora: escolher tipo de desconto (o DescontoPromocional só será aplicado se carrinho.size() >= 2)
            DescontoStrategy* estrategiaEscolhida = nullptr;
            int escolhaDesconto;
            std::cout << "\nSelecione o tipo de desconto para essa compra (vai ser verificado e aplicado no total):\n";
            std::cout << "1. Sem desconto\n";
            std::cout << "2. À vista (5%)\n";
            std::cout << "3. Cliente fiel (10%)\n";
            std::cout << "4. Promoção (15%)\n";
            std::cout << "Opção: ";
            std::cin >> escolhaDesconto;

            // Lógica: se escolher 3 (fiel) verificamos histórico; se escolher 4 (promo) verificamos carrinho size >=2
            bool aplicouPromocionalNoTotal = false;
            switch (escolhaDesconto) {
                case 2:
                    estrategiaEscolhida = new DescontoAVista();
                    break;
                case 3: {
                    bool jaComprou = false;
                    for (const Venda& v : historicoVendas) {
                        if (v.getDocumentoClienteRaw() == documentoCliente) {
                            jaComprou = true;
                            break;
                        }
                    }
                    if (jaComprou) {
                        estrategiaEscolhida = new DescontoClienteFiel();
                        std::cout << "Cliente fiel detectado — desconto de 10% será considerado.\n";
                    } else {
                        estrategiaEscolhida = new SemDesconto();
                        std::cout << "Esse cliente ainda não possui histórico de compras. Desconto de fidelidade não será aplicado.\n";
                    }
                    break;
                }
                case 4: {
                    // Promoção escolhida — só aplicamos se houver 2 ou mais veículos na compra
                    if (carrinho.size() >= 2) {
                        estrategiaEscolhida = new DescontoPromocional();
                        aplicouPromocionalNoTotal = true;
                        std::cout << "Desconto promocional selecionado e válido (compra com " << carrinho.size() << " veículos).\n";
                    } else {
                        estrategiaEscolhida = new SemDesconto();
                        std::cout << "Desconto promocional inválido: é necessário comprar 2 ou mais veículos para aplicar.\n";
                    }
                    break;
                }
                default:
                    estrategiaEscolhida = new SemDesconto();
                    break;
            }

            // Se promocional válido: vamos aplicar 15% no total; se não, caso escolha outro desconto, aplicamos por item (cada um proporcionalmente)
            double totalFinal = 0.0;
            std::vector<double> valoresFinaisPorItem(carrinho.size(), 0.0);

            if (aplicouPromocionalNoTotal) {
                double totalComDesconto = estrategiaEscolhida->aplicarDesconto(totalSemDesconto); // total * 0.85
                // distribuir proporcionalmente entre itens para registrar cada linha com valor final
                for (size_t i = 0; i < carrinho.size(); ++i) {
                    double proporcao = carrinho[i].valorOriginal / totalSemDesconto;
                    valoresFinaisPorItem[i] = totalComDesconto * proporcao;
                }
                totalFinal = totalComDesconto;
            } else {
                // aplica a estratégia individualmente em cada item (caso SemDesconto, AVista ou ClienteFiel)
                for (size_t i = 0; i < carrinho.size(); ++i) {
                    valoresFinaisPorItem[i] = estrategiaEscolhida->aplicarDesconto(carrinho[i].valorOriginal);
                    totalFinal += valoresFinaisPorItem[i];
                }
            }

            // Mostrar resumo final e confirmar pagamento
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
            if (aplicouPromocionalNoTotal) {
                std::cout << "Desconto aplicado: " << "Promoção (15%)" << " (no total) \n";
            } else {
                std::cout << "Desconto aplicado: " << estrategiaEscolhida->getNome() << "\n";
            }
            std::cout << "Total a pagar: R$" << totalFinal << "\n";

            std::cout << "Confirmar pagamento de R$" << totalFinal << "? (1-Sim / 2-Não): ";
            int confirma;
            std::cin >> confirma;
            if (confirma != 1) {
                std::cout << "Pagamento cancelado. Operação encerrada.\n";
                delete estrategiaEscolhida;
                return;
            }

            // Gravar cada venda individual no CSV e no historico em memória (cada linha por veículo)
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
                            << (aplicouPromocionalNoTotal ? "Promoção (15%)" : estrategiaEscolhida->getNome()) << ","
                            << valoresFinaisPorItem[i] << ","
                            << "À vista,"   // formaPagamento fixo por enquanto
                            << "Confirmada," // status
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
                            (aplicouPromocionalNoTotal ? "Promoção (15%)" : estrategiaEscolhida->getNome()),
                            valoresFinaisPorItem[i],
                            "À vista",
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
        // [NOVO] try/catch para leitura do histórico em memória
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
        // [NOVO] try/catch para filtrar histórico por cliente
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
        // [NOVO] try/catch para escrita do CSV do estoque
        try {
            std::ofstream arquivo(nomeArquivo);
            if (!arquivo.is_open()) {
                throw std::runtime_error("Erro ao atualizar o arquivo de estoque.");
            }

            // Cabeçalho (opcional, caso seu arquivo original tenha)
            arquivo << "Tipo,Modelo,Ano,Valor,Cor\n";

            for (Veiculo* v : estoque) {
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
        // [NOVO] tentativa de carregar estoque com catch já interna
        carregarEstoqueCSV("estoque.csv");

        std::cout << "\n Veículos no estoque:\n";
        for (Veiculo* v : estoque) {
            std::cout << "- " << v->Tipo() << ": " << v->getModelo()
                    << " (" << v->getCor() << ", " << v->getAno()
                    << ") - R$" << v->getValor() << "\n";
        }
    }

    bool buscarVeiculos() {
        // [NOVO] try/catch geral
        try {
            carregarEstoqueCSV("estoque.csv");

            std::string tipo, modelo, cor;
            int ano;
            bool encontrado = false;

            std::cout << "Digite o tipo de veículo (Carro/Moto): ";
            std::cin >> tipo;
            std::cin.ignore();
            std::cout << "Modelo: ";
            std::getline(std::cin, modelo);
            std::cout << "Cor: ";
            std::getline(std::cin, cor);
            std::cout << "Ano: ";
            std::cin >> ano;

            for (Veiculo* v : estoque) {
                if (v->Tipo() == tipo &&
                    v->getModelo() == modelo &&
                    v->getCor() == cor &&
                    v->getAno() == ano) {
                    std::cout << "\nStatus: Disponível:\n";
                    std::cout << "- " << v->Tipo() << ": " << v->getModelo()
                              << " (" << v->getCor() << ", " << v->getAno()
                              << ") - R$" << v->getValor() << "\n";
                    encontrado = true;
                    return encontrado;
                }
            }

            if (!encontrado) {
                std::cout << "Veículo indisponível\n";
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
    sistema->carregarEstoqueCSV("estoque.csv");
    //Iago, aqui criei um mini menu no terminal só para teste para ver se a lógica está correta
    int opcao;

    do {
        std::cout << "\n=== MENU DRIVE TECH ===\n";
        std::cout << "1. Cadastrar Cliente\n";
        std::cout << "2. Cadastrar Vendedor\n";
        std::cout << "3. Login de Vendedor\n";
        std::cout << "4. Sair\n";
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
                std::string nome, doc, login, senha;
                std::cout << "Nome do vendedor: ";
                std::getline(std::cin, nome);
                std::cout << "Documento: ";
                std::getline(std::cin, doc);
                std::cout << "Login: ";
                std::getline(std::cin, login);
                std::cout << "Senha: ";
                std::getline(std::cin, senha);
                sistema->cadastrarVendedor(Vendedor(nome, doc, login, senha));
                break;
            }
            case 3: {
                std::string login, senha;
                std::cout << "Login: ";
                std::getline(std::cin, login);
                std::cout << "Senha: ";
                std::getline(std::cin, senha);
                sistema->autenticar(login, senha);
                break;
            }

            case 4:
                std::cout << "Encerrando o sistema...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }

    } while (opcao != 4);

    return 0;
}
