#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QApplication>
#include "backend/pessoa.h"

JanelaPrincipal::JanelaPrincipal(Vendedor* vendedorLogado, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);

    if (vendedorLogado) {
        ui->labelVendedor->setText("Olá, " + QString::fromStdString(vendedorLogado->getNome()));
    }

    // Mude o 'parent' de 'this' para a página de destino (ex: ui->pageConsultarEstoque)
    pageConsultarEstoque = new JanelaConsultarEstoque(ui->pageConsultarEstoque);
    pageCadastrarCliente = new JanelaCadastrarCliente(ui->pageCadastrarCliente);
    pageRegistrarVenda = new JanelaRegistrarVenda(ui->pageRegistrarVenda);
    pageListarVendas = new JanelaListarVendas(ui->pageListarVendas);

    // Adiciona as subjanelas ao stacked window
    QVBoxLayout *layoutEstoque = new QVBoxLayout(ui->pageConsultarEstoque);
    layoutEstoque->addWidget(pageConsultarEstoque);
    ui->pageConsultarEstoque->setLayout(layoutEstoque);

    QVBoxLayout *layoutCliente = new QVBoxLayout(ui->pageCadastrarCliente);
    layoutCliente->addWidget(pageCadastrarCliente);
    ui->pageCadastrarCliente->setLayout(layoutCliente);

    QVBoxLayout *layoutVenda = new QVBoxLayout(ui->pageRegistrarVenda);
    layoutVenda->addWidget(pageRegistrarVenda);
    ui->pageRegistrarVenda->setLayout(layoutVenda);

    QVBoxLayout *layoutListar = new QVBoxLayout(ui->pageListarVendas);
    layoutListar->addWidget(pageListarVendas);
    ui->pageListarVendas->setLayout(layoutListar);

    //Conexão para a Janela de Consulta de Estoque
    connect(pageConsultarEstoque, &JanelaConsultarEstoque::voltarParaPrincipal,
            this, &JanelaPrincipal::navegarParaHome);

    // Conexão para a Janela de Cadastro de Cliente
    connect(pageCadastrarCliente, &JanelaCadastrarCliente::voltarParaPrincipal,
            this, &JanelaPrincipal::navegarParaHome);

    // Conexão para a Janela de Listar Vendas
    connect(pageListarVendas, &JanelaListarVendas::voltarParaPrincipal,
            this, &JanelaPrincipal::navegarParaHome);

    // Conexão para a Janela de Registrar Venda
    connect(pageRegistrarVenda, &JanelaRegistrarVenda::voltarParaPrincipal,
            this, &JanelaPrincipal::navegarParaHome);
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

// Mostra as telas
void JanelaPrincipal::on_pushButtonConsultarEstoque_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageConsultarEstoque);
}


void JanelaPrincipal::on_pushButtonCadastrarCliente_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCadastrarCliente);
}


void JanelaPrincipal::on_pushButtonRegistrarVenda_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageRegistrarVenda);
    pageRegistrarVenda->atualizarAutocompleteNomeCliente();
}


void JanelaPrincipal::on_pushButtonListarVendas_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageListarVendas);
    pageListarVendas->carregarVendas();
}

// Sair
void JanelaPrincipal::on_pushButtonSair_clicked()
{
    QApplication::quit();
}

void JanelaPrincipal::navegarParaHome()
{
    ui->stackedWidget->setCurrentWidget(ui->pageJanelaPrincipal);
}
