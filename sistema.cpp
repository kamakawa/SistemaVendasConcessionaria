#include <iostream>
#include <vector>
#include <string>

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

class SistemaClientes {
private:
    std::vector<Cliente> clientes;

public:
    void cadastrarCliente(const Cliente& novoCliente) {
        for (const Cliente& cliente : clientes) {
            if (cliente.getDocumento() == novoCliente.getDocumento()) {
                std::cout << "ERRO: Cliente já cadastrado\n";
                return;
            }
        }
        clientes.push_back(novoCliente);
        std::cout << "Cadastro bem-sucedido!\n";
    }
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

class SistemaVendedor {
private:
    std::vector<Vendedor> vendedores;

public:
    void cadastrarVendedor(const Vendedor& novoVendedor) {
        for (const Vendedor& vendedor : vendedores) {
            if (vendedor.getLogin() == novoVendedor.getLogin()) {
                std::cout << "ERRO: Vendedor já cadastrado\n";
                return;
            }
        }
        vendedores.push_back(novoVendedor);
        std::cout << "Cadastro bem-sucedido!\nSeja Bem-Vindo(a) ao time!\n";
    }

    std::vector<Vendedor>& getVendedores() {
        return vendedores;
    }
};

class Login {
public:
    void verificar(std::string login, std::string senha, std::vector<Vendedor>& vendedores) {
        for (Vendedor& vendedor : vendedores) {
            if (vendedor.getLogin() == login) {
                if (vendedor.getSenha() == senha) {
                    std::cout << "Bem-Vindo, " << vendedor.getNome() << "!\n";
                } else {
                    std::cout << "ERRO: senha incorreta!\n";
                }
                return;
            }
        }
        std::cout << "ERRO: Login incorreto!\n";
    }
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

int main() {
    SistemaClientes sistemaClientes;
    SistemaVendedor sistemaVendedores;
    Login sistemaLogin;

    // Cadastro de clientes
    Cliente cliente1("Maria Alves", "123456789");
    Cliente cliente2("João Silva", "987654321");
    Cliente cliente3("Maria Alves", "123456789"); // duplicado

    std::cout << "\n--- Cadastro de Clientes ---\n";
    sistemaClientes.cadastrarCliente(cliente1);
    sistemaClientes.cadastrarCliente(cliente2);
    sistemaClientes.cadastrarCliente(cliente3);

    // Cadastro de vendedores
    Vendedor vendedor1("Carlos Mendes", "001", "carlos123", "senha456");
    Vendedor vendedor2("Ana Paula", "002", "ana2023", "minhasenha");
    Vendedor vendedor3("Carlos Mendes", "001", "carlos123", "senha456"); // duplicado

    std::cout << "\n--- Cadastro de Vendedores ---\n";
    sistemaVendedores.cadastrarVendedor(vendedor1);
    sistemaVendedores.cadastrarVendedor(vendedor2);
    sistemaVendedores.cadastrarVendedor(vendedor3);

    // Teste de login
    std::cout << "\n--- Teste de Login ---\n";
    sistemaLogin.verificar("carlos123", "senha456", sistemaVendedores.getVendedores()); // sucesso
    sistemaLogin.verificar("carlos123", "errada", sistemaVendedores.getVendedores());   // senha incorreta
    sistemaLogin.verificar("naoexiste", "1234", sistemaVendedores.getVendedores());     // login incorreto

    // Cadastro de veículo
    std::cout << "\n--- Cadastro de Veículo ---\n";
    Carro carro1("Fiat Pulse", "Pulse Drive", "Vermelho", 95000.0, 2023);
    std::cout << "Nome: " << carro1.getNomeCarro() << "\n";
    std::cout << "Modelo: " << carro1.getModelo() << "\n";
    std::cout << "Cor: " << carro1.getCor() << "\n";
    std::cout << "Ano: " << carro1.getAno() << "\n";
    std::cout << "Valor: R$" << carro1.getValor() << "\n";
    std::cout << "Tipo: " << carro1.Tipo() << "\n";

    return 0;
}
