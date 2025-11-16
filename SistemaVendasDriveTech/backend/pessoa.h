#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
private:
    std::string nome;
    std::string documento;

public:
    Pessoa(std::string nome, std::string documento);

    virtual ~Pessoa();

    // Getters
    std::string getNome() const;
    std::string getDocumento() const;

    // Setters
    void setNome(std::string nome);
    void setDocumento(std::string doc);
};

class Cliente : public Pessoa {
public:
    Cliente(std::string nome, std::string documento);
};

class Vendedor : public Pessoa {
private:
    std::string login;
    std::string senha;

public:
    Vendedor(std::string nome, std::string login, std::string senha);

    ~Vendedor();

    // Getters
    std::string getLogin() const;
    std::string getSenha() const;

    // Setters
    void setLogin(std::string l);
    void setSenha(std::string s);
};

#endif // PESSOA_H
