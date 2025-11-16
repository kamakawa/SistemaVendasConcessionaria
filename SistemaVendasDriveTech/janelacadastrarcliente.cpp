#include "janelacadastrarcliente.h"
#include "ui_janelacadastrarcliente.h"
#include "backend/gerenciadordrivetech.h"
#include "backend/pessoa.h"
#include <QString>
#include <QMessageBox>

JanelaCadastrarCliente::JanelaCadastrarCliente(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JanelaCadastrarCliente)
{
    ui->setupUi(this);
    ui->lineEditDocumento->setInputMask("000.000.000-00;_");
    ui->lineEditDocumento->setMaxLength(11);
}

JanelaCadastrarCliente::~JanelaCadastrarCliente()
{
    delete ui;
}


void JanelaCadastrarCliente::on_pushButtonCadastrar_clicked()
{
    std::string nome = ui->lineEditNome->text().toStdString();
    std::string documento = ui->lineEditDocumento->text().toStdString();

    if (nome.empty() || documento.empty()) {
        QMessageBox::warning(this, "Campos obrigatórios", "Preencha todos os campos antes de cadastrar!");
        return;
    }

    Cliente cliente(nome, documento);
    QString resultado = GerenciadorDriveTech::obterInstancia()->cadastrarCliente(cliente);

    if (resultado == "Cliente já cadastrado!") {
        QMessageBox::warning(this, "Erro", "Cliente já cadastrado!");
    } else {
        QMessageBox::information(this, "Sucesso", "Cliente cadastrado com sucesso!");
    }
}


void JanelaCadastrarCliente::on_pushButtonVoltar_clicked()
{
    emit voltarParaPrincipal();
    ui->lineEditNome->clear();
    ui->lineEditDocumento->clear();
}

