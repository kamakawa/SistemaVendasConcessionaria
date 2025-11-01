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

class Login{
    public:
            //construtor
            Login(std::string login, std::string senha){

            }
    };

int main() {
    SistemaClientes sistema;

    Cliente c1("Maria Alves", "123456789");
    Cliente c2("João Silva", "987654321");

    sistema.cadastrarCliente(c1); // Deve cadastrar
    sistema.cadastrarCliente(c2); // Deve cadastrar
    sistema.cadastrarCliente(c1); // Deve dar erro

    return 0;

}

