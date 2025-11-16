#include "janelaregistrarvenda.h"
#include "ui_janelaregistrarvenda.h"
#include "backend/gerenciadordrivetech.h"
#include "backend/pessoa.h"
#include <QStringList>
#include <QDebug>
#include <QStringListModel>
#include "backend/pessoa.h"
#include <QMessageBox>

JanelaRegistrarVenda::JanelaRegistrarVenda(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JanelaRegistrarVenda)
{
    ui->setupUi(this);
    configurarAutocompleteNomeCliente();
    GerenciadorDriveTech::obterInstancia()->carregarEstoqueCSV("data/estoque.csv");
    ui->comboBoxModelo->setEnabled(false);
    ui->comboBoxAno->setEnabled(false);
    ui->comboBoxCor->setEnabled(false);
}


JanelaRegistrarVenda::~JanelaRegistrarVenda()
{
    delete ui;
}


void JanelaRegistrarVenda::configurarAutocompleteNomeCliente() {
    QStringList listaNomes;
    for (const Cliente& c : GerenciadorDriveTech::obterInstancia()->getClientes()) {
        listaNomes << QString::fromStdString(c.getNome());
    }

    QCompleter* completer = new QCompleter(listaNomes, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);

    ui->lineEditNome->setCompleter(completer);

    // Conecta a seleção do QCompleter a um slot que preenche o CPF
    connect(completer, SIGNAL(activated(QString)), this, SLOT(preencherDocumentoDoCliente(QString)));
}


void JanelaRegistrarVenda::atualizarAutocompleteNomeCliente() {
    QStringList listaNomes;

    // Pega a lista mais recente de clientes do Gerenciador
    for (const Cliente& c : GerenciadorDriveTech::obterInstancia()->getClientes()) {
        listaNomes << QString::fromStdString(c.getNome());
    }

    QCompleter* completer = ui->lineEditNome->completer();
    if (completer) {
        // Se o completer já existe, apenas atualiza o modelo de dados
        QStringListModel *model = new QStringListModel(listaNomes, completer);
        completer->setModel(model);
    } else {
        // Se ainda não existe (no caso da primeira chamada)
        QCompleter* novoCompleter = new QCompleter(listaNomes, this);
        ui->lineEditNome->setCompleter(novoCompleter);
    }
}


void JanelaRegistrarVenda::preencherDocumentoDoCliente(const QString &nomeSelecionado) {
    const auto &clientes = GerenciadorDriveTech::obterInstancia()->getClientes();
    for (const Cliente& c : clientes) {
        if (QString::fromStdString(c.getNome()) == nomeSelecionado) {
            ui->lineEditDocumento->setText(QString::fromStdString(c.getDocumento()));
            break;
        }
    }
}


void JanelaRegistrarVenda::on_comboBoxTipo_currentTextChanged(const QString &tipoQt)
{
    ui->comboBoxModelo->clear();
    ui->comboBoxModelo->addItem("Selecione o modelo"); // placeholder

    if (tipoQt == "Selecione o tipo") return;

    std::string tipo = tipoQt.toStdString();
    auto modelos = GerenciadorDriveTech::obterInstancia()->getModelosPorTipo(tipo);

    for (const std::string& m : modelos) {
        ui->comboBoxModelo->addItem(QString::fromStdString(m));
    }

    ui->comboBoxModelo->setEnabled(true);
    ui->comboBoxAno->setEnabled(false);
    ui->comboBoxCor->setEnabled(false);
}


void JanelaRegistrarVenda::on_comboBoxModelo_currentTextChanged(const QString &modeloQt)
{
    // Limpa o combobox de ano e coloca um placeholder
    ui->comboBoxAno->clear();
    ui->comboBoxAno->addItem("Selecione o ano");

    if (modeloQt == "Selecione o modelo") return;

    // Converte para std::string
    std::string modelo = modeloQt.toStdString();

    // Obtém os anos disponíveis para o modelo
    auto anos = GerenciadorDriveTech::obterInstancia()->getAnoPorModelo(modelo);

    // Adiciona os anos no combobox
    for (int ano : anos) {
        ui->comboBoxAno->addItem(QString::number(ano));
    }

    // Limpa o combobox de cor
    ui->comboBoxCor->clear();
    ui->comboBoxCor->addItem("Selecione a cor");

    ui->comboBoxAno->setEnabled(true);
    ui->comboBoxCor->setEnabled(false);
}


void JanelaRegistrarVenda::on_comboBoxAno_currentTextChanged(const QString &anoQt)
{
    // Limpa o combobox de cor e coloca um placeholder
    ui->comboBoxCor->clear();
    ui->comboBoxCor->addItem("Selecione a cor");

    // Verifica se o ano é válido
    if (anoQt == "Selecione o ano") return;

    // Obtém o modelo selecionado
    QString modeloQt = ui->comboBoxModelo->currentText();
    if (modeloQt == "Selecione o modelo") return;

    // Converte ano para int e modelo para std::string
    int ano = anoQt.toInt();
    std::string modelo = modeloQt.toStdString();

    // Obtém as cores disponíveis para o modelo e ano
    auto cores = GerenciadorDriveTech::obterInstancia()->getCorPorAno(modelo, ano);

    // Adiciona as cores no combobox
    for (const std::string& cor : cores) {
        ui->comboBoxCor->addItem(QString::fromStdString(cor));
    }

    ui->comboBoxCor->setEnabled(true);
}


void JanelaRegistrarVenda::on_pushButtonRegistrarVenda_clicked()
{
    std::string nome = ui->lineEditNome->text().toStdString();
    std::string documento = ui->lineEditDocumento->text().toStdString();

    if (nome.empty() || documento.empty()) {
        QMessageBox::warning(this, "Campos obrigatórios",
                             "Preencha todos os campos obrigatórios (Nome e Documento) antes de registrar a venda!");
        return;
    }

    bool clienteCadastrado = false;
    const auto& clientes = GerenciadorDriveTech::obterInstancia()->getClientes();

    for (const Cliente& c : clientes) {
        if (c.getNome() == nome && c.getDocumento() == documento) {
            clienteCadastrado = true;
            break;
        }
    }

    if (!clienteCadastrado) {
        QMessageBox::warning(this, "Cliente não cadastrado",
                             "O cliente informado não está cadastrado no sistema!\n"
                             "Por favor, cadastre o cliente antes de realizar a venda.");
        return;
    }
    std::string filial = ui->comboBoxFilial->currentText().toStdString();
    Cliente clienteSelecionado(nome, documento);

    std::string tipo = ui->comboBoxTipo->currentText().toStdString();
    std::string modelo = ui->comboBoxModelo->currentText().toStdString();
    int ano = ui->comboBoxAno->currentText().toInt();
    std::string cor = ui->comboBoxCor->currentText().toStdString();

    std::string desconto = ui->comboBoxDesconto->currentText().toStdString();
    std::string formaPagamento = ui->comboBoxPagamento->currentText().toStdString();
    std::string vendedor = GerenciadorDriveTech::obterInstancia()->getVendedorAtivoNome();

    Veiculo* veiculoSelecionado = nullptr;

    double entrada = 0.0;
    int parcelas = 1;

    if (formaPagamento == "Parcelado") {
        entrada = ui->lineEditEntrada->text().toDouble();
        parcelas = ui->spinBoxParcelas->value();
    }

    try {
        veiculoSelecionado = GerenciadorDriveTech::obterInstancia()->buscarVeiculoExato(filial, tipo, modelo, ano, cor);

        if (!veiculoSelecionado) {
            QMessageBox::warning(this, "Erro de Estoque", "Veículo específico (Ano/Cor) não disponível nesta filial.");
            return;
        }

        QString resumo = GerenciadorDriveTech::obterInstancia()->venda(
            clienteSelecionado,
            filial,
            veiculoSelecionado,
            desconto,
            formaPagamento,
            vendedor,
            entrada,  
            parcelas  
            );


        ui->textBrowserResumo->setText(resumo);
        QMessageBox::information(this, "Sucesso", "Venda registrada com sucesso!");

    }
    catch (const std::exception& e) {
        // Captura erros do backend (ex: filial inválida, erro de CSV)
        QMessageBox::critical(this, "Erro na Venda", QString::fromStdString(e.what()));
    }
    catch (...) {
        QMessageBox::critical(this, "Erro Desconhecido", "Ocorreu um erro inesperado durante o registro da venda.");
    }
}



void JanelaRegistrarVenda::on_pushButtonCancelar_clicked()
{
    // Limpa os campos de texto
    ui->lineEditNome->clear();
    ui->lineEditDocumento->clear();
    ui->textBrowserResumo->clear();

    // Reseta comboBoxFilial
    ui->comboBoxFilial->setCurrentIndex(0);

    // Reseta comboBoxTipo
    ui->comboBoxTipo->setCurrentIndex(0);

    // Limpa e reseta modelo
    ui->comboBoxModelo->clear();
    ui->comboBoxModelo->addItem("Selecione o modelo");
    ui->comboBoxModelo->setEnabled(false);

    // Limpa e reseta ano
    ui->comboBoxAno->clear();
    ui->comboBoxAno->addItem("Selecione o ano");
    ui->comboBoxAno->setEnabled(false);

    // Limpa e reseta cor
    ui->comboBoxCor->clear();
    ui->comboBoxCor->addItem("Selecione a cor");
    ui->comboBoxCor->setEnabled(false);

    // Reseta desconto e pagamento
    ui->comboBoxDesconto->setCurrentIndex(0);
    ui->comboBoxPagamento->setCurrentIndex(0);
    emit voltarParaPrincipal();
}


void JanelaRegistrarVenda::on_comboBoxPagamento_currentTextChanged(const QString &formaPagamento)
{
    // Se o pagamento for parcelado, habilita campo de entrada
    if (formaPagamento == "Parcelado" || formaPagamento == "Financiamento") {
        ui->lineEditEntrada->setEnabled(true);
        ui->labelEntrada->setEnabled(true);
        ui->spinBoxParcelas->setEnabled(true);
        ui->labelParcelas->setEnabled(true);
    } else {
        // Se for à vista, desativa e limpa os campos
        ui->lineEditEntrada->setEnabled(false);
        ui->labelEntrada->setEnabled(false);
        ui->lineEditEntrada->clear();
        ui->spinBoxParcelas->setEnabled(false);
        ui->labelParcelas->setEnabled(false);
        ui->spinBoxParcelas->setValue(1);
    }
}

