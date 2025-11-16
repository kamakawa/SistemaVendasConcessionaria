#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include "janelaconsultarestoque.h"
#include "janelacadastrarcliente.h"
#include "janelaregistrarvenda.h"
#include "janelalistarvendas.h"
#include "backend/pessoa.h"
#include <QMainWindow>

namespace Ui {
class JanelaPrincipal;
}

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit JanelaPrincipal(Vendedor* vendedorLogado, QWidget *parent = nullptr);
    ~JanelaPrincipal();

private slots:
    void on_pushButtonConsultarEstoque_clicked();

    void on_pushButtonCadastrarCliente_clicked();

    void on_pushButtonRegistrarVenda_clicked();

    void on_pushButtonListarVendas_clicked();

    void on_pushButtonSair_clicked();

    void navegarParaHome();

private:
    Ui::JanelaPrincipal *ui;

    // Cria as telas
    JanelaConsultarEstoque *pageConsultarEstoque;
    JanelaCadastrarCliente *pageCadastrarCliente;
    JanelaRegistrarVenda *pageRegistrarVenda;
    JanelaListarVendas *pageListarVendas;
};

#endif // JANELAPRINCIPAL_H
