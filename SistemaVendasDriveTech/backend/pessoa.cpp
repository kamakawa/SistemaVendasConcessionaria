#include "pessoa.h"

Pessoa::Pessoa(std::string nome, std::string documento) {
    setNome(nome);
    setDocumento(documento);
}

Pessoa::~Pessoa() {}

Cliente::Cliente(std::string nome, std::string documento) : Pessoa(nome, documento) {}

Vendedor::Vendedor(std::string nome, std::string login, std::string senha)
: Pessoa(nome, "")
{
    setLogin(login);
    setSenha(senha);
}

Vendedor::~Vendedor() {}

// Getters
std::string Vendedor::getLogin() const { return login; }
std::string Vendedor::getSenha() const { return senha; }
std::string Pessoa::getNome() const { return nome; }
std::string Pessoa::getDocumento() const { return documento; }

// Setters
void Vendedor::setLogin(std::string l) { login = l; }
void Vendedor::setSenha(std::string s) { senha = s; }
void Pessoa::setNome(std::string nome) { this->nome = nome; }
void Pessoa::setDocumento(std::string doc) { this->documento = doc; }
