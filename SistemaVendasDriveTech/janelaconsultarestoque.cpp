#include "janelaconsultarestoque.h"
#include "ui_janelaconsultarestoque.h"
#include "backend/gerenciadordrivetech.h"
#include <QMessageBox>

JanelaConsultarEstoque::JanelaConsultarEstoque(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JanelaConsultarEstoque)
{
    ui->setupUi(this);

    ui->comboBoxModelo->addItem("Selecione o modelo");
    ui->labelStatus->clear();

    // Desabilita botão inicialmente
    ui->pushButtonConsulta->setEnabled(false);

    GerenciadorDriveTech::obterInstancia()->carregarEstoqueCSV("data/estoque.csv");

    // Conecta sinais para monitorar mudanças nos combos
    connect(ui->comboBoxFilial, &QComboBox::currentTextChanged,
            this, &JanelaConsultarEstoque::verificarCamposValidos);
    connect(ui->comboBoxTipoDeVeiculo, &QComboBox::currentTextChanged,
            this, &JanelaConsultarEstoque::on_comboBoxTipoDeVeiculo_currentTextChanged);
    connect(ui->comboBoxModelo, &QComboBox::currentTextChanged,
            this, &JanelaConsultarEstoque::verificarCamposValidos);
}

JanelaConsultarEstoque::~JanelaConsultarEstoque()
{
    delete ui;
}

// Atualiza combo de modelos quando o tipo muda
void JanelaConsultarEstoque::on_comboBoxTipoDeVeiculo_currentTextChanged(const QString &tipoQt)
{
    ui->comboBoxModelo->clear();
    ui->comboBoxModelo->addItem("Selecione o modelo"); // placeholder

    std::string tipo = tipoQt.toStdString();
    auto modelos = GerenciadorDriveTech::obterInstancia()->getModelosPorTipo(tipo);

    for (const std::string& m : modelos) {
        ui->comboBoxModelo->addItem(QString::fromStdString(m));
    }

    verificarCamposValidos();  // Atualiza estado do botão
}

// Verifica se todos os combos estão preenchidos corretamente
void JanelaConsultarEstoque::verificarCamposValidos()
{
    bool filialValida = ui->comboBoxFilial->currentText() != "Selecione a filial";
    bool tipoValido = ui->comboBoxTipoDeVeiculo->currentText() != "Selecione o tipo";
    bool modeloValido = ui->comboBoxModelo->currentText() != "Selecione o modelo";

    ui->pushButtonConsulta->setEnabled(filialValida && tipoValido && modeloValido);
}

// Slot do botão de consulta
void JanelaConsultarEstoque::on_pushButtonConsulta_clicked()
{
    std::string filial = ui->comboBoxFilial->currentText().toStdString();
    std::string tipo = ui->comboBoxTipoDeVeiculo->currentText().toStdString();
    std::string modelo = ui->comboBoxModelo->currentText().toStdString();

    Veiculo* status = GerenciadorDriveTech::obterInstancia()->buscarVeiculos(filial, tipo, modelo);

    if (status != nullptr) {
        ui->labelStatus->setText("Veículo disponível!");
        ui->labelStatus->setStyleSheet("color: green; font-weight: bold; font-size: 16px;");
    } else {
        ui->labelStatus->setText("Veículo indisponível");
        ui->labelStatus->setStyleSheet("color: red; font-weight: bold; font-size: 16px;");
    }
}

void JanelaConsultarEstoque::on_pushButtonVoltar_clicked()
{
    ui->comboBoxFilial->setCurrentIndex(0);
    ui->comboBoxTipoDeVeiculo->setCurrentIndex(0);
    ui->labelStatus->clear();
    emit voltarParaPrincipal();
}

