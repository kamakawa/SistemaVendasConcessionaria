#ifndef VENDA_H
#define VENDA_H

#include <string>

// Classe para salvar o histórico de vendas
class Venda {
private:
    std::string nomeCliente;
    std::string documentoCliente;
    std::string filial;
    std::string tipoVeiculo;
    std::string modeloVeiculo;
    int anoVeiculo;
    std::string cor;           
    double valorOriginal;
    std::string tipoDesconto;
    double valorFinal;
    std::string formaPagamento;
    std::string status;
    std::string dataHora;
    std::string nomeVendedor;
    double valorEntrada;
    int numeroParcelas;
    double valorParcela;
    double saldoRestante;

public:
    // Construtor
    Venda(std::string nome, std::string doc, std::string fil, std::string tipoV,
                 std::string modV, int anoV, std::string corV, double valOrig, std::string desc,
                 double valFinal, std::string pag, std::string stat, std::string dataHoraVenda,
                 std::string vendedorNome,
                 // Novos parâmetros
                 double entrada, int parcelas, double vParcela, double sRestante);

    // Getters
    std::string getDocumentoClienteRaw() const;
    std::string getDataHora() const;
    std::string getNomeVendedor() const;
    std::string getNomeCliente() const;
    double getValorOriginal() const;
    double getValorFinal() const;
    std::string getTipoDesconto() const;
    std::string getFilial() const;
    std::string getTipo() const;
    std::string getModelo() const;
    int getAno() const;
    std::string getCor() const;
    std::string getFormaPagamento() const;
    std::string getStatus() const;
    double getValorEntrada() const;
    int getNumeroParcelas() const;
    double getValorParcela() const;
    double getSaldoRestante() const;
    std::string getResumo() const;
};

#endif // VENDA_H
