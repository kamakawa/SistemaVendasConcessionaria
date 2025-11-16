#ifndef VEICULO_H
#define VEICULO_H

#include <string>

class Veiculo {
private:
    std::string modelo;
    std::string cor;
    std::string tipo;
    double valor;
    int ano;

public:
    virtual ~Veiculo();

    // Getters
    std::string getModelo() const;
    std::string getCor() const;
    std::string getTipo() const;
    double getValor() const;
    int getAno() const;

    // Setters
    void setModelo(std::string m);
    void setCor(std::string c);
    void setTipo(std::string t);
    void setValor(double v);
    void setAno(int a);

    virtual std::string Tipo() const = 0;
};

class Carro : public Veiculo {
private:
    std::string nomeCarro;

public:
    Carro(std::string nome, std::string modelo, std::string cor, double valor, int ano);

    std::string Tipo() const override;

    std::string getNomeCarro() const;
    void setNomeCarro(std::string nome);
};

class Moto : public Veiculo {
private:
    std::string nomeMoto;

public:
    Moto(std::string nome, std::string modelo, std::string cor, double valor, int ano);

    std::string Tipo() const override;

    std::string getNomeMoto() const;
    void setNomeMoto(std::string nome);
};

#endif // VEICULO_H
