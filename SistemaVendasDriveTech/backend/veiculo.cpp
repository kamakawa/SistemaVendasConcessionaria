#include "veiculo.h"

Veiculo::~Veiculo() {}

// Getters
std::string Veiculo::getModelo() const { return modelo; }
std::string Veiculo::getCor() const { return cor; }
std::string Veiculo::getTipo() const { return tipo; }
double Veiculo::getValor() const { return valor; }
int Veiculo::getAno() const { return ano; }
std::string Carro::getNomeCarro() const { return nomeCarro; }
std::string Moto::getNomeMoto() const { return nomeMoto; }

// Setters
void Veiculo::setModelo(std::string m) { modelo = m; }
void Veiculo::setCor(std::string c) { cor = c; }
void Veiculo::setTipo(std::string t) { tipo = t; }
void Veiculo::setValor(double v) { valor = v; }
void Veiculo::setAno(int a) { ano = a; }
void Carro::setNomeCarro(std::string nome) { nomeCarro = nome; }
void Moto::setNomeMoto(std::string nome) { nomeMoto = nome; }


Carro::Carro(std::string nome, std::string modelo, std::string cor, double valor, int ano) {
    setNomeCarro(nome);
    setModelo(modelo);
    setCor(cor);
    setValor(valor);
    setAno(ano);
    setTipo("Carro");
}

std::string Carro::Tipo() const {
    return getTipo();
}


Moto::Moto(std::string nome, std::string modelo, std::string cor, double valor, int ano) {
    setNomeMoto(nome);
    setModelo(modelo);
    setCor(cor);
    setValor(valor);
    setAno(ano);
    setTipo("Moto");
}

std::string Moto::Tipo() const {
    return getTipo();
}

