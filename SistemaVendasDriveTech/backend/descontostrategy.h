#ifndef DESCONTOSTRATEGY_H
#define DESCONTOSTRATEGY_H

#include <string>

//Strategy
class DescontoStrategy {
public:
    virtual double aplicarDesconto(double valor) const = 0;
    virtual std::string getNome() const = 0;
    virtual ~DescontoStrategy();
};

class SemDesconto : public DescontoStrategy {
public:
    double aplicarDesconto(double valor) const override;
    std::string getNome() const override;
};

class DescontoClienteFiel : public DescontoStrategy {
public:
    double aplicarDesconto(double valor) const override;
    std::string getNome() const override;
};

class DescontoPromocional : public DescontoStrategy {
public:
    double aplicarDesconto(double valor) const override;
    std::string getNome() const override;
};

class VendaCorporativa : public DescontoStrategy {
public:
    double aplicarDesconto(double valor) const override;
    std::string getNome() const override;
};

#endif // DESCONTOSTRATEGY_H
