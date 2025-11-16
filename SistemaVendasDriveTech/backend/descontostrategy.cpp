#include "descontostrategy.h"

DescontoStrategy::~DescontoStrategy() {}

double SemDesconto::aplicarDesconto(double valor) const {
    return valor;
}
std::string SemDesconto::getNome() const {
    return "Tarifa padrão";
}

double DescontoClienteFiel::aplicarDesconto(double valor) const {
    return valor * 0.95; // 5%
}
std::string DescontoClienteFiel::getNome() const {
    return "Cliente Fidelidade (5%)";
}

double DescontoPromocional::aplicarDesconto(double valor) const {
    return valor * 0.90; // 10%
}
std::string DescontoPromocional::getNome() const {
    return "Promoção Especial (10%)";
}

double VendaCorporativa::aplicarDesconto(double valor) const {
    return valor * 0.85; // 15% de desconto
}
std::string VendaCorporativa::getNome() const {
    return "Vendas Corporativas (15%)";
}
