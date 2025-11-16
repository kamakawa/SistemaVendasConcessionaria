#ifndef GERENCIADORDRIVETECH_H
#define GERENCIADORDRIVETECH_H

#include <vector>
#include "venda.h"
#include "pessoa.h"
#include "veiculo.h"
#include <QString>
#include <set>
#include <map>
#include "veiculo.h"

class GerenciadorDriveTech {
private:
    static GerenciadorDriveTech* instancia;

    std::vector<Vendedor> vendedores;
    std::vector<Veiculo*> estoqueLondrina;
    std::vector<Veiculo*> estoqueMaringa;
    std::vector<Veiculo*> estoqueCuritiba;
    std::vector<Cliente> clientes;
    std::vector<Venda> historicoVendas;
    std::string vendedorAtivoNome;
    std::string vendedorAtivoLogin;
    std::map<std::string, std::set<std::string>> modelosPorTipo;

    GerenciadorDriveTech();

public:
    GerenciadorDriveTech(const GerenciadorDriveTech&) = delete;
    GerenciadorDriveTech& operator=(const GerenciadorDriveTech&) = delete;

    static GerenciadorDriveTech* obterInstancia();

    void inicializarSistema();
    QString autenticar(const std::string& login, const std::string& senha);
    void cadastrarVendedor(const Vendedor& novoVendedor);
    QString cadastrarCliente(const Cliente& novoCliente);
    void carregarEstoqueCSV(const std::string& nomeArquivo);
    QString venda(
        const Cliente& cliente,
        const std::string& filial,
        Veiculo* veiculoSelecionado,
        const std::string& tipoDesconto,
        const std::string& formaPagamento,
        const std::string& nomeVendedor,
        double entrada,
        int parcelas
        );
    void listarHistoricoVendas();
    void listarHistoricoCliente(std::string docBusca);
    void atualizarEstoqueCSV(const std::string& nomeArquivo);
    void listarVeiculos();
    Veiculo* buscarVeiculos(const std::string& filial, const std::string& tipo, const std::string& modelo);
    std::vector<Veiculo*>& getEstoqueFilial(const std::string& filial);
    void registrarVendaCSV(const Venda& venda);
    const std::vector<Venda>& getHistoricoVendas() const;
    void carregarVendedoresCSV(const std::string& nomeArquivo);
    Veiculo* buscarVeiculoExato(const std::string& filial, const std::string& tipo,
                                const std::string& modelo, int ano, const std::string& cor);
    void carregarVendasCSV(const std::string& nomeArquivo);
    void carregarClientesCSV(const std::string& arquivo);
    std::string limparDocumento(const std::string& documento);

    Vendedor* getVendedorAtivo();
    std::set<std::string> getModelosPorTipo(const std::string& tipo) const;
    const std::vector<Cliente>& getClientes() const;
    std::set<int> getAnoPorModelo(const std::string& modelo) const;
    std::set<std::string> getCorPorAno(const std::string& modelo, int ano) const;
    std::string getVendedorAtivoNome() const;

    Cliente* buscarClientePorDocumento(const std::string& documento);

};

#endif // GERENCIADORDRIVETECH_H
