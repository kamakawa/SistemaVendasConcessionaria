/********************************************************************************
** Form generated from reading UI file 'janelaregistrarvenda.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAREGISTRARVENDA_H
#define UI_JANELAREGISTRARVENDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaRegistrarVenda
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelFilial;
    QComboBox *comboBoxFilial;
    QLabel *labelNome;
    QLineEdit *lineEditNome;
    QLabel *labelDocumento;
    QLineEdit *lineEditDocumento;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelTipo;
    QComboBox *comboBoxTipo;
    QLabel *labelModelo;
    QComboBox *comboBoxModelo;
    QLabel *labelAno;
    QComboBox *comboBoxAno;
    QLabel *labelCor;
    QComboBox *comboBoxCor;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *labelDesconto;
    QComboBox *comboBoxDesconto;
    QLabel *labelPagamento;
    QComboBox *comboBoxPagamento;
    QLabel *labelEntrada;
    QLineEdit *lineEditEntrada;
    QLabel *labelParcelas;
    QSpinBox *spinBoxParcelas;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonRegistrarVenda;
    QPushButton *pushButtonCancelar;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowserResumo;

    void setupUi(QWidget *JanelaRegistrarVenda)
    {
        if (JanelaRegistrarVenda->objectName().isEmpty())
            JanelaRegistrarVenda->setObjectName("JanelaRegistrarVenda");
        JanelaRegistrarVenda->resize(881, 748);
        verticalLayout = new QVBoxLayout(JanelaRegistrarVenda);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_3 = new QGroupBox(JanelaRegistrarVenda);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setStyleSheet(QString::fromUtf8("color: white;"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        labelFilial = new QLabel(groupBox_3);
        labelFilial->setObjectName("labelFilial");

        horizontalLayout_4->addWidget(labelFilial);

        comboBoxFilial = new QComboBox(groupBox_3);
        comboBoxFilial->addItem(QString());
        comboBoxFilial->addItem(QString());
        comboBoxFilial->addItem(QString());
        comboBoxFilial->addItem(QString());
        comboBoxFilial->setObjectName("comboBoxFilial");
        comboBoxFilial->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_4->addWidget(comboBoxFilial);

        labelNome = new QLabel(groupBox_3);
        labelNome->setObjectName("labelNome");

        horizontalLayout_4->addWidget(labelNome);

        lineEditNome = new QLineEdit(groupBox_3);
        lineEditNome->setObjectName("lineEditNome");
        lineEditNome->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_4->addWidget(lineEditNome);

        labelDocumento = new QLabel(groupBox_3);
        labelDocumento->setObjectName("labelDocumento");

        horizontalLayout_4->addWidget(labelDocumento);

        lineEditDocumento = new QLineEdit(groupBox_3);
        lineEditDocumento->setObjectName("lineEditDocumento");
        lineEditDocumento->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_4->addWidget(lineEditDocumento);


        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(JanelaRegistrarVenda);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setStyleSheet(QString::fromUtf8("color: white;"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelTipo = new QLabel(groupBox_2);
        labelTipo->setObjectName("labelTipo");

        horizontalLayout_3->addWidget(labelTipo);

        comboBoxTipo = new QComboBox(groupBox_2);
        comboBoxTipo->addItem(QString());
        comboBoxTipo->addItem(QString());
        comboBoxTipo->addItem(QString());
        comboBoxTipo->setObjectName("comboBoxTipo");
        comboBoxTipo->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_3->addWidget(comboBoxTipo);

        labelModelo = new QLabel(groupBox_2);
        labelModelo->setObjectName("labelModelo");

        horizontalLayout_3->addWidget(labelModelo);

        comboBoxModelo = new QComboBox(groupBox_2);
        comboBoxModelo->addItem(QString());
        comboBoxModelo->setObjectName("comboBoxModelo");
        comboBoxModelo->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_3->addWidget(comboBoxModelo);

        labelAno = new QLabel(groupBox_2);
        labelAno->setObjectName("labelAno");

        horizontalLayout_3->addWidget(labelAno);

        comboBoxAno = new QComboBox(groupBox_2);
        comboBoxAno->addItem(QString());
        comboBoxAno->setObjectName("comboBoxAno");
        comboBoxAno->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_3->addWidget(comboBoxAno);

        labelCor = new QLabel(groupBox_2);
        labelCor->setObjectName("labelCor");

        horizontalLayout_3->addWidget(labelCor);

        comboBoxCor = new QComboBox(groupBox_2);
        comboBoxCor->addItem(QString());
        comboBoxCor->setObjectName("comboBoxCor");
        comboBoxCor->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_3->addWidget(comboBoxCor);


        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(JanelaRegistrarVenda);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName("gridLayout");
        labelDesconto = new QLabel(groupBox_4);
        labelDesconto->setObjectName("labelDesconto");
        labelDesconto->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout->addWidget(labelDesconto, 0, 0, 1, 1);

        comboBoxDesconto = new QComboBox(groupBox_4);
        comboBoxDesconto->addItem(QString());
        comboBoxDesconto->addItem(QString());
        comboBoxDesconto->addItem(QString());
        comboBoxDesconto->addItem(QString());
        comboBoxDesconto->addItem(QString());
        comboBoxDesconto->setObjectName("comboBoxDesconto");
        comboBoxDesconto->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout->addWidget(comboBoxDesconto, 0, 1, 1, 1);

        labelPagamento = new QLabel(groupBox_4);
        labelPagamento->setObjectName("labelPagamento");
        labelPagamento->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout->addWidget(labelPagamento, 1, 0, 1, 1);

        comboBoxPagamento = new QComboBox(groupBox_4);
        comboBoxPagamento->addItem(QString());
        comboBoxPagamento->addItem(QString());
        comboBoxPagamento->addItem(QString());
        comboBoxPagamento->setObjectName("comboBoxPagamento");
        comboBoxPagamento->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout->addWidget(comboBoxPagamento, 1, 1, 1, 1);

        labelEntrada = new QLabel(groupBox_4);
        labelEntrada->setObjectName("labelEntrada");
        labelEntrada->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout->addWidget(labelEntrada, 2, 0, 1, 1);

        lineEditEntrada = new QLineEdit(groupBox_4);
        lineEditEntrada->setObjectName("lineEditEntrada");

        gridLayout->addWidget(lineEditEntrada, 2, 1, 1, 1);

        labelParcelas = new QLabel(groupBox_4);
        labelParcelas->setObjectName("labelParcelas");
        labelParcelas->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout->addWidget(labelParcelas, 3, 0, 1, 1);

        spinBoxParcelas = new QSpinBox(groupBox_4);
        spinBoxParcelas->setObjectName("spinBoxParcelas");
        spinBoxParcelas->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout->addWidget(spinBoxParcelas, 3, 1, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonRegistrarVenda = new QPushButton(JanelaRegistrarVenda);
        pushButtonRegistrarVenda->setObjectName("pushButtonRegistrarVenda");
        pushButtonRegistrarVenda->setStyleSheet(QString::fromUtf8("color: green;"));

        horizontalLayout->addWidget(pushButtonRegistrarVenda);

        pushButtonCancelar = new QPushButton(JanelaRegistrarVenda);
        pushButtonCancelar->setObjectName("pushButtonCancelar");
        pushButtonCancelar->setStyleSheet(QString::fromUtf8("color: red;"));

        horizontalLayout->addWidget(pushButtonCancelar);


        verticalLayout->addLayout(horizontalLayout);

        groupBox_5 = new QGroupBox(JanelaRegistrarVenda);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setStyleSheet(QString::fromUtf8("color: white;"));
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        textBrowserResumo = new QTextBrowser(groupBox_5);
        textBrowserResumo->setObjectName("textBrowserResumo");

        verticalLayout_2->addWidget(textBrowserResumo);


        verticalLayout->addWidget(groupBox_5);


        retranslateUi(JanelaRegistrarVenda);

        QMetaObject::connectSlotsByName(JanelaRegistrarVenda);
    } // setupUi

    void retranslateUi(QWidget *JanelaRegistrarVenda)
    {
        JanelaRegistrarVenda->setWindowTitle(QCoreApplication::translate("JanelaRegistrarVenda", "Form", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("JanelaRegistrarVenda", "Filial e Cliente", nullptr));
        labelFilial->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Filial:", nullptr));
        comboBoxFilial->setItemText(0, QCoreApplication::translate("JanelaRegistrarVenda", "Selecione a filial", nullptr));
        comboBoxFilial->setItemText(1, QCoreApplication::translate("JanelaRegistrarVenda", "Curitiba", nullptr));
        comboBoxFilial->setItemText(2, QCoreApplication::translate("JanelaRegistrarVenda", "Londrina", nullptr));
        comboBoxFilial->setItemText(3, QCoreApplication::translate("JanelaRegistrarVenda", "Maringa", nullptr));

        labelNome->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Nome:", nullptr));
        labelDocumento->setText(QCoreApplication::translate("JanelaRegistrarVenda", "CPF/CNPJ:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("JanelaRegistrarVenda", "Ve\303\255culo", nullptr));
        labelTipo->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Tipo:", nullptr));
        comboBoxTipo->setItemText(0, QCoreApplication::translate("JanelaRegistrarVenda", "Selecione o tipo", nullptr));
        comboBoxTipo->setItemText(1, QCoreApplication::translate("JanelaRegistrarVenda", "Carro", nullptr));
        comboBoxTipo->setItemText(2, QCoreApplication::translate("JanelaRegistrarVenda", "Moto", nullptr));

        labelModelo->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Modelo:", nullptr));
        comboBoxModelo->setItemText(0, QCoreApplication::translate("JanelaRegistrarVenda", "Selecione o modelo", nullptr));

        labelAno->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Ano:", nullptr));
        comboBoxAno->setItemText(0, QCoreApplication::translate("JanelaRegistrarVenda", "Selecione o ano", nullptr));

        labelCor->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Cor:", nullptr));
        comboBoxCor->setItemText(0, QCoreApplication::translate("JanelaRegistrarVenda", "Selecione a cor", nullptr));

        groupBox_4->setTitle(QCoreApplication::translate("JanelaRegistrarVenda", "Descontos e Pagamento", nullptr));
        labelDesconto->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Pol\303\255tica de desconto:", nullptr));
        comboBoxDesconto->setItemText(0, QCoreApplication::translate("JanelaRegistrarVenda", "Selecione a pol\303\255tica de desconto", nullptr));
        comboBoxDesconto->setItemText(1, QCoreApplication::translate("JanelaRegistrarVenda", "Sem desconto", nullptr));
        comboBoxDesconto->setItemText(2, QCoreApplication::translate("JanelaRegistrarVenda", "Cliente fidelidade", nullptr));
        comboBoxDesconto->setItemText(3, QCoreApplication::translate("JanelaRegistrarVenda", "Promo\303\247\303\243o especial", nullptr));
        comboBoxDesconto->setItemText(4, QCoreApplication::translate("JanelaRegistrarVenda", "Vendas corporativas", nullptr));

        labelPagamento->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Forma de pagamento", nullptr));
        comboBoxPagamento->setItemText(0, QCoreApplication::translate("JanelaRegistrarVenda", "Selecione a forma de pagamento", nullptr));
        comboBoxPagamento->setItemText(1, QCoreApplication::translate("JanelaRegistrarVenda", "\303\200 vista", nullptr));
        comboBoxPagamento->setItemText(2, QCoreApplication::translate("JanelaRegistrarVenda", "Parcelado", nullptr));

        labelEntrada->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Valor de entrada (R$):", nullptr));
        labelParcelas->setText(QCoreApplication::translate("JanelaRegistrarVenda", "N\302\272 de parcelas:", nullptr));
        pushButtonRegistrarVenda->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Registrar venda", nullptr));
        pushButtonCancelar->setText(QCoreApplication::translate("JanelaRegistrarVenda", "Cancelar", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("JanelaRegistrarVenda", " Resumo da Venda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JanelaRegistrarVenda: public Ui_JanelaRegistrarVenda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAREGISTRARVENDA_H
