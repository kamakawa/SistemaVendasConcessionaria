#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

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


// Singleton
class GerenciadorDriveTech {
private:
    static GerenciadorDriveTech* instancia;

    std::vector<Vendedor> vendedores;
    std::vector<Veiculo*> estoque;
    std::vector<Cliente> clientes;

    GerenciadorDriveTech() {}

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
                    do{
                        //Iago, aqui criei um mini menu no terminal só para teste para ver se a lógica está correta
                        //Funcionalidades apenas para o vendedor logado
                        std::cout << "Olá, " << vendedor.getNome() << std::endl;
                        std::cout << "\n======MENU VENDEDOR========" << std::endl;
                        std::cout << "1. Listar Veículos no estoque\n";
                        std::cout << "2. Consulta de estoque\n";
                        std::cout << "3. Vender\n";
                        std::cout << "4. Sair\n";
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
                        
                            case 4:
                                std::cout << "Saindo... Até breve " << vendedor.getNome() << std::endl;
                                break;
                            default:
                                std::cout << "Opção inválida!\n";
                        }

                    }while(opc != 4);
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
    std::ifstream arquivo(nomeArquivo);
    std::string linha;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << "\n";
        return;
    }

    std::getline(arquivo, linha); // Ignora o cabeçalho

    // Limpa o estoque anterior
    for (Veiculo* v : estoque) {
            delete v;
        }
        estoque.clear();

        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string tipo, modelo, anoStr, valorStr, cor;

            std::getline(ss, tipo, ',');
            std::getline(ss, modelo, ',');
            std::getline(ss, anoStr, ',');
            std::getline(ss, valorStr, ',');
            std::getline(ss, cor, ',');

            int ano = std::stoi(anoStr);
            double valor = std::stod(valorStr);

            if (tipo == "Carro") {
                estoque.push_back(new Carro(modelo, modelo, cor, valor, ano));
            } else if (tipo == "Moto") {
                estoque.push_back(new Moto(modelo, modelo, cor, valor, ano));
            }
        }

        std::cout << "Estoque carregado com sucesso a partir de " << nomeArquivo << "\n";
    }

        void venda() {
        std::string nomeCliente, documentoCliente;
        bool clienteEncontrado = false;
        Cliente clienteSelecionado("", "");
        int opc;

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

        // Escolha do veículo
        std::string tipo, modelo, cor;
        int ano;
        std::cout << "\nDigite o tipo de veículo (Carro/Moto): ";
        std::cin >> tipo;
        std::cout << "Modelo: ";
        std::cin >> modelo;
        std::cout << "Cor: ";
        std::cin >> cor;
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
            return;
        }

        std::cout << "\nVeículo disponível!\n";
        std::cout << tipo << " " << modelo << " (" << cor << ", " << ano
                << ") - R$" << veiculoSelecionado->getValor() << "\n";

        std::cout << "Confirmar venda? (1-Sim / 2-Não): ";
        std::cin >> opc;
        if (opc != 1) {
            std::cout << "Venda cancelada.\n";
            return;
        }

        // Registra a venda no arquivo CSV
        std::ofstream arquivo("vendas.csv", std::ios::app);
        if (arquivo.is_open()) {
            arquivo << clienteSelecionado.getNome() << ","
                    << clienteSelecionado.getDocumento() << ","
                    << filial << ","
                    << tipo << ","
                    << modelo << ","
                    << ano << ","
                    << veiculoSelecionado->getValor() << ","
                    << "Sem desconto,"
                    << veiculoSelecionado->getValor() << ","
                    << "À vista,"
                    << "Confirmada\n";
            arquivo.close();
        }

        // Remove o veículo do estoque (em memória)
        delete estoque[indiceRemover];
        estoque.erase(estoque.begin() + indiceRemover);

        //atualizando o estoque
        atualizarEstoqueCSV("estoque.csv");

        std::cout << "\nVenda registrada com sucesso!\n";
        std::cout << "Resumo:\n";
        std::cout << "Cliente: " << clienteSelecionado.getNome() << "\n";
        std::cout << "Filial: " << filial << "\n";
        std::cout << "Veículo: " << tipo << " " << modelo << " (" << cor << ", " << ano << ")\n";
        std::cout << "Valor: R$" << veiculoSelecionado->getValor() << "\n";
        std::cout << "Status: Confirmada\n";
    }

    void atualizarEstoqueCSV(const std::string& nomeArquivo) {
        std::ofstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            std::cerr << "Erro ao atualizar o arquivo de estoque.\n";
            return;
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
    }


    void listarVeiculos() {
        carregarEstoqueCSV("estoque.csv");

        std::cout << "\n Veículos no estoque:\n";
        for (Veiculo* v : estoque) {
            std::cout << "- " << v->Tipo() << ": " << v->getModelo()
                    << " (" << v->getCor() << ", " << v->getAno()
                    << ") - R$" << v->getValor() << "\n";
        }
    }

    bool buscarVeiculos() {
    carregarEstoqueCSV("estoque.csv");

    std::string tipo, modelo, cor;
    int ano;
    bool encontrado = false;

    std::cout << "Digite o tipo de veículo (Carro/Moto): ";
    std::cin >> tipo;
    std::cout << "Modelo: ";
    std::cin >> modelo;
    std::cout << "Cor: ";
    std::cin >> cor;
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
