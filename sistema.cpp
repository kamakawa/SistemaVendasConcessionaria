#include <iostream>
#include <cmath>
#include <vector>

class Cliente{
    private:
        std::string nomeCompleto;
        std::string documento;

    public:
        //construtor
        Cliente(std::string nome, std::string documento){
            setNomeCompleto(nome);
            setDocumento(documento);
        }

        //destrutor
        ~Cliente(){};

        //getters e setters
        std::string getNomeCompleto(){return this->nomeCompleto;}
        std::string getDocumento(){return this->documento;}

        void setNomeCompleto(std::string nome){this->nomeCompleto = nome;}
        void setDocumento(std::string documento){this->documento = documento;}

};

class SistemaClientes {
    private:
        std::vector<Cliente> clientes;
    public:
        void cadastrarCliente(Cliente& novoCliente) {
            for (Cliente& cliente : clientes) {
                if (cliente.getDocumento() == novoCliente.getDocumento()) {
                    std::cout << "ERRO: Cliente já cadastrado" << std::endl;
                    return;
                }
            }

            clientes.push_back(novoCliente);
            std::cout << "Cadastro bem-sucedido!" << std::endl;

        }

};

class Vendedor{
    private:
        std::string nome;
        std::string login;
        std::string senha;

    public:
        //construtor
        Vendedor(std::string nome, std::string login, std::string senha){
            setNomeVendedor(nome);
            setLogin(login);
            setSenha(senha);
        }

        //destrutor
        ~Vendedor(){};

        //getters e setters
        std::string getNomeVendedor(){return this->nome;}
        std::string getLogin(){return this->login;}
        std::string getSenha(){return this->senha;}

        void setNomeVendedor(std::string nomeVendedor){this->nome = nomeVendedor;}
        void setLogin(std::string login){this->login = login;}
        void setSenha(std::string senha){this->senha = senha;}
};

class SistemaVendedor {
    private:
        std::vector<Vendedor> vendedores;
    public:
        void cadastrarVendedor(Vendedor& novoVendedor) {
            for (Vendedor& vendedores : vendedores) {
                if (vendedores.getNomeVendedor() == novoVendedor.getNomeVendedor()) {
                    std::cout << "ERRO: Cliente já cadastrado" << std::endl;
                    return;
                }
            }

            vendedores.push_back(novoVendedor);
            std::cout << "Cadastro bem-sucedido!\n" << "Seja Bem-Vindo(a) ao time!"<< std::endl;

        }

};

class Login{
    public:
            void verificar(std::string login, std::string senha, std::vector<Vendedor>& vendedores){
                for (Vendedor& vendedor : vendedores) {
                    if (vendedor.getLogin() == login ) {
                        if(vendedor.getSenha() == senha){
                            std::cout << "Bem-Vindo" << std::endl;
                        }else{
                            std::cout << "ERRO: senha incorreta!" << std::endl;
                        }
                    }else{
                        std::cout << "ERRO: Login incorreto!" << std::endl;
                    }
                }
            }
    };

int main() {
    // Criando sistemas
    SistemaClientes sistemaClientes;
    SistemaVendedor sistemaVendedores;
    Login sistemaLogin;

    // Cadastrando clientes
    Cliente cliente1("Maria Alves", "123456789");
    Cliente cliente2("João Silva", "987654321");
    Cliente cliente3("Maria Alves", "123456789"); // duplicado

    std::cout << "\n--- Cadastro de Clientes ---\n";
    sistemaClientes.cadastrarCliente(cliente1); // deve cadastrar
    sistemaClientes.cadastrarCliente(cliente2); // deve cadastrar
    sistemaClientes.cadastrarCliente(cliente3); // deve dar erro

    // Cadastrando vendedores
    Vendedor vendedor1("Carlos Mendes", "carlos123", "senha456");
    Vendedor vendedor2("Ana Paula", "ana2023", "minhasenha");
    Vendedor vendedor3("Carlos Mendes", "carlos123", "senha456"); // duplicado

    std::cout << "\n--- Cadastro de Vendedores ---\n";
    sistemaVendedores.cadastrarVendedor(vendedor1); // deve cadastrar
    sistemaVendedores.cadastrarVendedor(vendedor2); // deve cadastrar
    sistemaVendedores.cadastrarVendedor(vendedor3); // deve dar erro

    // Testando login
    std::cout << "\n--- Teste de Login ---\n";
    std::vector<Vendedor> listaVendedores = {
        vendedor1,
        vendedor2
    };

    sistemaLogin.verificar("carlos123", "senha456", listaVendedores); // sucesso
    sistemaLogin.verificar("carlos123", "errada", listaVendedores);   // senha incorreta
    sistemaLogin.verificar("naoexiste", "1234", listaVendedores);     // login incorreto

    return 0;
}


