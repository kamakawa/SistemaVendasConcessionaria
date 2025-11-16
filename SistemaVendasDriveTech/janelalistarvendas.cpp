#include "janelalistarvendas.h"
#include "ui_janelalistarvendas.h"
#include "backend/gerenciadordrivetech.h"

JanelaListarVendas::JanelaListarVendas(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JanelaListarVendas)
{
    ui->setupUi(this);
}

JanelaListarVendas::~JanelaListarVendas()
{
    delete ui;
}

void JanelaListarVendas::carregarVendas() {
    auto& vendas = GerenciadorDriveTech::obterInstancia()->getHistoricoVendas();

    ui->tableWidgetVendas->clear();
    ui->tableWidgetVendas->setRowCount(vendas.size());
    ui->tableWidgetVendas->setColumnCount(16);

    QStringList cabecalho = {
        "Vendedor", "Cliente", "Documento", "Filial", "Tipo", "Modelo", "Ano",
        "Cor", "Valor Original", "Desconto", "Valor Final", "Forma Pagamento", "Status",
        "Valor Entrada", "Nº Parcelas", "Valor Parcela"
    };
    ui->tableWidgetVendas->setHorizontalHeaderLabels(cabecalho);

    int row = 0;
    for (const Venda& v : vendas) {
        ui->tableWidgetVendas->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(v.getNomeVendedor())));
        ui->tableWidgetVendas->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(v.getNomeCliente())));
        ui->tableWidgetVendas->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(v.getDocumentoClienteRaw())));
        ui->tableWidgetVendas->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(v.getFilial())));
        ui->tableWidgetVendas->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(v.getTipo())));
        ui->tableWidgetVendas->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(v.getModelo())));
        ui->tableWidgetVendas->setItem(row, 6, new QTableWidgetItem(QString::number(v.getAno())));
        ui->tableWidgetVendas->setItem(row, 7, new QTableWidgetItem(QString::fromStdString(v.getCor())));
        ui->tableWidgetVendas->setItem(row, 8, new QTableWidgetItem(QString::number(v.getValorOriginal(), 'f', 2)));
        ui->tableWidgetVendas->setItem(row, 9, new QTableWidgetItem(QString::fromStdString(v.getTipoDesconto())));
        ui->tableWidgetVendas->setItem(row, 10, new QTableWidgetItem(QString::number(v.getValorFinal(), 'f', 2)));
        ui->tableWidgetVendas->setItem(row, 11, new QTableWidgetItem(QString::fromStdString(v.getFormaPagamento())));

        QTableWidgetItem* statusItem = new QTableWidgetItem(QString::fromStdString(v.getStatus()));
        // Adiciona cor para status
        if (v.getStatus() == "Confirmada") {
            statusItem->setBackground(QBrush(Qt::green));
        } else if (v.getStatus() == "Pendente") {
            statusItem->setBackground(QBrush(Qt::yellow));
        }
        ui->tableWidgetVendas->setItem(row, 12, statusItem);

        ui->tableWidgetVendas->setItem(row, 13, new QTableWidgetItem(QString::number(v.getValorEntrada(), 'f', 2)));
        ui->tableWidgetVendas->setItem(row, 14, new QTableWidgetItem(QString::number(v.getNumeroParcelas())));

        // Pequena lógica para não mostrar "R$0.00" em compras à vista
        double vParcela = v.getValorParcela();
        QString vParcelaStr = (vParcela > 0.0) ? QString::number(vParcela, 'f', 2) : "N/A";
        ui->tableWidgetVendas->setItem(row, 15, new QTableWidgetItem(vParcelaStr));
        row++;
    }

    ui->tableWidgetVendas->resizeColumnsToContents();
    ui->tableWidgetVendas->setEditTriggers(QAbstractItemView::NoEditTriggers); // só leitura
}

void JanelaListarVendas::on_pushButtonVoltar_clicked()
{
    emit voltarParaPrincipal();
    ui->tableWidgetVendas->clear();
}

