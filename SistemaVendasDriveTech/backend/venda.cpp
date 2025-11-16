#include "venda.h"
#include <sstream> // para o ostringstream
#include <iomanip> // para fixed e setprecision

// Construtor
Venda::Venda(std::string nome, std::string doc, std::string fil, std::string tipoV,
             std::string modV, int anoV, std::string corV, double valOrig, std::string desc,
             double valFinal, std::string pag, std::string stat, std::string dataHoraVenda,
             std::string vendedorNome,
             double entrada, int parcelas, double vParcela, double sRestante)
    : nomeCliente(nome), documentoCliente(doc), filial(fil), tipoVeiculo(tipoV),
    modeloVeiculo(modV), anoVeiculo(anoV), cor(corV), valorOriginal(valOrig),
    tipoDesconto(desc), valorFinal(valFinal), formaPagamento(pag),
    status(stat), dataHora(dataHoraVenda), nomeVendedor(vendedorNome),
    valorEntrada(entrada), numeroParcelas(parcelas),
    valorParcela(vParcela), saldoRestante(sRestante) {}

// Getters
std::string Venda::getDocumentoClienteRaw() const { return documentoCliente; }
std::string Venda::getDataHora() const { return dataHora; }
std::string Venda::getNomeVendedor() const { return nomeVendedor; }
std::string Venda::getNomeCliente() const { return nomeCliente; }
double Venda::getValorOriginal() const { return valorOriginal; }
double Venda::getValorFinal() const { return valorFinal; }
std::string Venda::getTipoDesconto() const { return tipoDesconto; }
std::string Venda::getFilial() const { return filial; }
std::string Venda::getTipo() const { return tipoVeiculo; }
std::string Venda::getModelo() const { return modeloVeiculo; }
int Venda::getAno() const { return anoVeiculo; }
std::string Venda::getCor() const { return cor; } 
std::string Venda::getFormaPagamento() const { return formaPagamento; }
std::string Venda::getStatus() const { return status; }
double Venda::getValorEntrada() const { return valorEntrada; }
int Venda::getNumeroParcelas() const { return numeroParcelas; }
double Venda::getValorParcela() const { return valorParcela; }
double Venda::getSaldoRestante() const { return saldoRestante; }
std::string Venda::getResumo() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "=== RESUMO DA VENDA ===\n";
    oss << "Cliente: " << nomeCliente
        << " | Documento: " << documentoCliente << "\n";
    oss << "Vendedor: " << nomeVendedor
        << " | Filial: " << filial << "\n";
    oss << "Veículo: " << tipoVeiculo << " " << modeloVeiculo
        << " (" << anoVeiculo << ", " << cor << ")\n";
    oss << "Valor Original: R$" << valorOriginal
        << " | Desconto: " << tipoDesconto << "\n";
    oss << "Valor Final: R$" << valorFinal
        << " | Forma de Pagamento: " << formaPagamento << "\n";

    oss << "\n--- Detalhes do Pagamento ---\n";
    oss << "Valor de Entrada: R$" << valorEntrada << "\n";
    if (formaPagamento == "Parcelado") {
        oss << "Saldo Restante: R$" << saldoRestante << "\n";
        oss << "Parcelas: " << numeroParcelas << "x de R$" << valorParcela << "\n";
    }

    oss << "\nStatus: " << status
        << " | Data/Hora: " << dataHora << "\n";
    return oss.str();
}
