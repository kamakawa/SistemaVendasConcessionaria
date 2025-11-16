/********************************************************************************
** Form generated from reading UI file 'janelaconsultarestoque.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELACONSULTARESTOQUE_H
#define UI_JANELACONSULTARESTOQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaConsultarEstoque
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetCabecalho;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonVoltar;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *labelFilial;
    QComboBox *comboBoxFilial;
    QLabel *labelTipoDeVeiculo;
    QComboBox *comboBoxTipoDeVeiculo;
    QLabel *labelModelo;
    QComboBox *comboBoxModelo;
    QPushButton *pushButtonConsulta;
    QLabel *labelStatus;

    void setupUi(QWidget *JanelaConsultarEstoque)
    {
        if (JanelaConsultarEstoque->objectName().isEmpty())
            JanelaConsultarEstoque->setObjectName("JanelaConsultarEstoque");
        JanelaConsultarEstoque->resize(945, 259);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JanelaConsultarEstoque->sizePolicy().hasHeightForWidth());
        JanelaConsultarEstoque->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(JanelaConsultarEstoque);
        verticalLayout->setObjectName("verticalLayout");
        widgetCabecalho = new QWidget(JanelaConsultarEstoque);
        widgetCabecalho->setObjectName("widgetCabecalho");
        horizontalLayout = new QHBoxLayout(widgetCabecalho);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonVoltar = new QPushButton(widgetCabecalho);
        pushButtonVoltar->setObjectName("pushButtonVoltar");
        pushButtonVoltar->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(pushButtonVoltar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widgetCabecalho);

        groupBox = new QGroupBox(JanelaConsultarEstoque);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setStyleSheet(QString::fromUtf8("color: white;"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        labelFilial = new QLabel(groupBox);
        labelFilial->setObjectName("labelFilial");
        labelFilial->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelFilial);

        comboBoxFilial = new QComboBox(groupBox);
        comboBoxFilial->addItem(QString());
        comboBoxFilial->addItem(QString());
        comboBoxFilial->addItem(QString());
        comboBoxFilial->addItem(QString());
        comboBoxFilial->setObjectName("comboBoxFilial");
        comboBoxFilial->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboBoxFilial);

        labelTipoDeVeiculo = new QLabel(groupBox);
        labelTipoDeVeiculo->setObjectName("labelTipoDeVeiculo");
        labelTipoDeVeiculo->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelTipoDeVeiculo);

        comboBoxTipoDeVeiculo = new QComboBox(groupBox);
        comboBoxTipoDeVeiculo->addItem(QString());
        comboBoxTipoDeVeiculo->addItem(QString());
        comboBoxTipoDeVeiculo->addItem(QString());
        comboBoxTipoDeVeiculo->setObjectName("comboBoxTipoDeVeiculo");
        comboBoxTipoDeVeiculo->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboBoxTipoDeVeiculo);

        labelModelo = new QLabel(groupBox);
        labelModelo->setObjectName("labelModelo");
        labelModelo->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelModelo);

        comboBoxModelo = new QComboBox(groupBox);
        comboBoxModelo->addItem(QString());
        comboBoxModelo->setObjectName("comboBoxModelo");
        comboBoxModelo->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboBoxModelo);

        pushButtonConsulta = new QPushButton(groupBox);
        pushButtonConsulta->setObjectName("pushButtonConsulta");
        pushButtonConsulta->setStyleSheet(QString::fromUtf8("color: white;"));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, pushButtonConsulta);


        verticalLayout->addWidget(groupBox);

        labelStatus = new QLabel(JanelaConsultarEstoque);
        labelStatus->setObjectName("labelStatus");
        sizePolicy.setHeightForWidth(labelStatus->sizePolicy().hasHeightForWidth());
        labelStatus->setSizePolicy(sizePolicy);
        labelStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelStatus);


        retranslateUi(JanelaConsultarEstoque);

        QMetaObject::connectSlotsByName(JanelaConsultarEstoque);
    } // setupUi

    void retranslateUi(QWidget *JanelaConsultarEstoque)
    {
        JanelaConsultarEstoque->setWindowTitle(QCoreApplication::translate("JanelaConsultarEstoque", "Form", nullptr));
        pushButtonVoltar->setText(QCoreApplication::translate("JanelaConsultarEstoque", "Voltar", nullptr));
        groupBox->setTitle(QCoreApplication::translate("JanelaConsultarEstoque", "Filtros de Consulta", nullptr));
        labelFilial->setText(QCoreApplication::translate("JanelaConsultarEstoque", "Filial:", nullptr));
        comboBoxFilial->setItemText(0, QCoreApplication::translate("JanelaConsultarEstoque", "Selecione a filial", nullptr));
        comboBoxFilial->setItemText(1, QCoreApplication::translate("JanelaConsultarEstoque", "Curitiba", nullptr));
        comboBoxFilial->setItemText(2, QCoreApplication::translate("JanelaConsultarEstoque", "Londrina", nullptr));
        comboBoxFilial->setItemText(3, QCoreApplication::translate("JanelaConsultarEstoque", "Maringa", nullptr));

        labelTipoDeVeiculo->setText(QCoreApplication::translate("JanelaConsultarEstoque", "Tipo de ve\303\255culo:", nullptr));
        comboBoxTipoDeVeiculo->setItemText(0, QCoreApplication::translate("JanelaConsultarEstoque", "Selecione o tipo", nullptr));
        comboBoxTipoDeVeiculo->setItemText(1, QCoreApplication::translate("JanelaConsultarEstoque", "Carro", nullptr));
        comboBoxTipoDeVeiculo->setItemText(2, QCoreApplication::translate("JanelaConsultarEstoque", "Moto", nullptr));

        labelModelo->setText(QCoreApplication::translate("JanelaConsultarEstoque", "Modelo:", nullptr));
        comboBoxModelo->setItemText(0, QCoreApplication::translate("JanelaConsultarEstoque", "Selecione o modelo", nullptr));

        pushButtonConsulta->setText(QCoreApplication::translate("JanelaConsultarEstoque", "Consultar", nullptr));
        labelStatus->setText(QCoreApplication::translate("JanelaConsultarEstoque", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JanelaConsultarEstoque: public Ui_JanelaConsultarEstoque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELACONSULTARESTOQUE_H
