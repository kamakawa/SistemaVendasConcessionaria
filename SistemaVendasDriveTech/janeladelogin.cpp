#include "janeladelogin.h"
#include "ui_janeladelogin.h"
#include <QMessageBox>
#include "backend/gerenciadordrivetech.h"
#include "janelaprincipal.h"

JanelaDeLogin::JanelaDeLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::JanelaDeLogin)
{
    ui->setupUi(this);
    QPixmap logo("/home/erickamakawa/Documentos/SistemaVendasDriveTech/slogan.png");
    ui->logoEmpresa->setPixmap(logo);

}

JanelaDeLogin::~JanelaDeLogin()
{
    delete ui;
}

void JanelaDeLogin::on_pushButtonEntrar_clicked()
{
    std::string login = ui->lineEditUsuario->text().toStdString();
    std::string senha = ui->lineEditSenha->text().toStdString();

    GerenciadorDriveTech* gerenciador = GerenciadorDriveTech::obterInstancia();
    QString resultado = gerenciador->autenticar(login, senha);

    if (resultado == "true") {
        // Obtem o vendedor logado
        Vendedor* vendedorLogado = gerenciador->getVendedorAtivo();

        if (!vendedorLogado) {
            QMessageBox::critical(this, "Erro", "Vendedor logado não encontrado.");
            return;
        }

        // Abre a janela principal
        JanelaPrincipal* principal = new JanelaPrincipal(vendedorLogado);
        principal->show();

        // Fecha a tela de login
        accept();
    } else {
        // Mostra mensagem de erro com Ok e Cancel
        QMessageBox::StandardButton botao;
        botao = QMessageBox::warning(this, "Erro de autenticação", resultado, QMessageBox::Ok | QMessageBox::Cancel);

        if (botao == QMessageBox::Ok) {
            ui->lineEditUsuario->clear();
            ui->lineEditSenha->clear();
            ui->lineEditUsuario->setFocus();
        } else if (botao == QMessageBox::Cancel) {
            reject();
        }
    }
}





