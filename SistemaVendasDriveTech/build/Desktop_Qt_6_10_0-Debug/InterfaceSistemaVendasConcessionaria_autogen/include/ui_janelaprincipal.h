/********************************************************************************
** Form generated from reading UI file 'janelaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAPRINCIPAL_H
#define UI_JANELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaPrincipal
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageJanelaPrincipal;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelVendedor;
    QPushButton *pushButtonConsultarEstoque;
    QPushButton *pushButtonCadastrarCliente;
    QPushButton *pushButtonRegistrarVenda;
    QPushButton *pushButtonListarVendas;
    QPushButton *pushButtonSair;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QWidget *pageCadastrarCliente;
    QWidget *pageListarVendas;
    QWidget *pageRegistrarVenda;
    QWidget *pageConsultarEstoque;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JanelaPrincipal)
    {
        if (JanelaPrincipal->objectName().isEmpty())
            JanelaPrincipal->setObjectName("JanelaPrincipal");
        JanelaPrincipal->resize(990, 541);
        centralwidget = new QWidget(JanelaPrincipal);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: black;"));
        pageJanelaPrincipal = new QWidget();
        pageJanelaPrincipal->setObjectName("pageJanelaPrincipal");
        gridLayout_2 = new QGridLayout(pageJanelaPrincipal);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        labelVendedor = new QLabel(pageJanelaPrincipal);
        labelVendedor->setObjectName("labelVendedor");
        labelVendedor->setStyleSheet(QString::fromUtf8("color: #00BFFF;\n"
""));

        verticalLayout->addWidget(labelVendedor);

        pushButtonConsultarEstoque = new QPushButton(pageJanelaPrincipal);
        pushButtonConsultarEstoque->setObjectName("pushButtonConsultarEstoque");
        pushButtonConsultarEstoque->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        verticalLayout->addWidget(pushButtonConsultarEstoque);

        pushButtonCadastrarCliente = new QPushButton(pageJanelaPrincipal);
        pushButtonCadastrarCliente->setObjectName("pushButtonCadastrarCliente");
        pushButtonCadastrarCliente->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        verticalLayout->addWidget(pushButtonCadastrarCliente);

        pushButtonRegistrarVenda = new QPushButton(pageJanelaPrincipal);
        pushButtonRegistrarVenda->setObjectName("pushButtonRegistrarVenda");
        pushButtonRegistrarVenda->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        verticalLayout->addWidget(pushButtonRegistrarVenda);

        pushButtonListarVendas = new QPushButton(pageJanelaPrincipal);
        pushButtonListarVendas->setObjectName("pushButtonListarVendas");
        pushButtonListarVendas->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        verticalLayout->addWidget(pushButtonListarVendas);

        pushButtonSair = new QPushButton(pageJanelaPrincipal);
        pushButtonSair->setObjectName("pushButtonSair");
        pushButtonSair->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        verticalLayout->addWidget(pushButtonSair);


        gridLayout_2->addLayout(verticalLayout, 4, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 4, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 4, 0, 1, 1);

        label = new QLabel(pageJanelaPrincipal);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 2, 2, 1, 1);

        stackedWidget->addWidget(pageJanelaPrincipal);
        pageCadastrarCliente = new QWidget();
        pageCadastrarCliente->setObjectName("pageCadastrarCliente");
        stackedWidget->addWidget(pageCadastrarCliente);
        pageListarVendas = new QWidget();
        pageListarVendas->setObjectName("pageListarVendas");
        stackedWidget->addWidget(pageListarVendas);
        pageRegistrarVenda = new QWidget();
        pageRegistrarVenda->setObjectName("pageRegistrarVenda");
        stackedWidget->addWidget(pageRegistrarVenda);
        pageConsultarEstoque = new QWidget();
        pageConsultarEstoque->setObjectName("pageConsultarEstoque");
        stackedWidget->addWidget(pageConsultarEstoque);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        JanelaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JanelaPrincipal);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 990, 23));
        JanelaPrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(JanelaPrincipal);
        statusbar->setObjectName("statusbar");
        JanelaPrincipal->setStatusBar(statusbar);

        retranslateUi(JanelaPrincipal);

        QMetaObject::connectSlotsByName(JanelaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaPrincipal)
    {
        JanelaPrincipal->setWindowTitle(QCoreApplication::translate("JanelaPrincipal", "MainWindow", nullptr));
        labelVendedor->setText(QCoreApplication::translate("JanelaPrincipal", "TextLabel", nullptr));
        pushButtonConsultarEstoque->setText(QCoreApplication::translate("JanelaPrincipal", "Consultar estoque", nullptr));
        pushButtonCadastrarCliente->setText(QCoreApplication::translate("JanelaPrincipal", "Cadastrar cliente", nullptr));
        pushButtonRegistrarVenda->setText(QCoreApplication::translate("JanelaPrincipal", "Registrar venda", nullptr));
        pushButtonListarVendas->setText(QCoreApplication::translate("JanelaPrincipal", "Listar vendas", nullptr));
        pushButtonSair->setText(QCoreApplication::translate("JanelaPrincipal", "Sair", nullptr));
        label->setText(QCoreApplication::translate("JanelaPrincipal", "<html><head/><body><h1 align=\"center\" style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; font-weight:700; color:#00bfff;\">MENU</span></h1></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipal: public Ui_JanelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H
