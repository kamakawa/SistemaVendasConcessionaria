/********************************************************************************
** Form generated from reading UI file 'janelacadastrarcliente.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELACADASTRARCLIENTE_H
#define UI_JANELACADASTRARCLIENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaCadastrarCliente
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QPushButton *pushButtonVoltar;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEditDocumento;
    QLabel *labelNome;
    QLineEdit *lineEditNome;
    QLabel *labelDocumento;
    QPushButton *pushButtonCadastrar;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *JanelaCadastrarCliente)
    {
        if (JanelaCadastrarCliente->objectName().isEmpty())
            JanelaCadastrarCliente->setObjectName("JanelaCadastrarCliente");
        JanelaCadastrarCliente->resize(894, 474);
        JanelaCadastrarCliente->setStyleSheet(QString::fromUtf8("background-color: black;"));
        gridLayout_2 = new QGridLayout(JanelaCadastrarCliente);
        gridLayout_2->setObjectName("gridLayout_2");
        widget = new QWidget(JanelaCadastrarCliente);
        widget->setObjectName("widget");
        pushButtonVoltar = new QPushButton(widget);
        pushButtonVoltar->setObjectName("pushButtonVoltar");
        pushButtonVoltar->setGeometry(QRect(0, 0, 88, 26));
        pushButtonVoltar->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lineEditDocumento = new QLineEdit(JanelaCadastrarCliente);
        lineEditDocumento->setObjectName("lineEditDocumento");
        lineEditDocumento->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        gridLayout->addWidget(lineEditDocumento, 1, 1, 1, 1);

        labelNome = new QLabel(JanelaCadastrarCliente);
        labelNome->setObjectName("labelNome");
        labelNome->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        gridLayout->addWidget(labelNome, 0, 0, 1, 1);

        lineEditNome = new QLineEdit(JanelaCadastrarCliente);
        lineEditNome->setObjectName("lineEditNome");
        lineEditNome->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        gridLayout->addWidget(lineEditNome, 0, 1, 1, 1);

        labelDocumento = new QLabel(JanelaCadastrarCliente);
        labelDocumento->setObjectName("labelDocumento");
        labelDocumento->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        gridLayout->addWidget(labelDocumento, 1, 0, 1, 1);

        pushButtonCadastrar = new QPushButton(JanelaCadastrarCliente);
        pushButtonCadastrar->setObjectName("pushButtonCadastrar");
        pushButtonCadastrar->setStyleSheet(QString::fromUtf8("color: #00BFFF;"));

        gridLayout->addWidget(pushButtonCadastrar, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        gridLayout_2->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);


        retranslateUi(JanelaCadastrarCliente);

        QMetaObject::connectSlotsByName(JanelaCadastrarCliente);
    } // setupUi

    void retranslateUi(QWidget *JanelaCadastrarCliente)
    {
        JanelaCadastrarCliente->setWindowTitle(QCoreApplication::translate("JanelaCadastrarCliente", "Form", nullptr));
        pushButtonVoltar->setText(QCoreApplication::translate("JanelaCadastrarCliente", "Voltar", nullptr));
        lineEditDocumento->setInputMask(QString());
        labelNome->setText(QCoreApplication::translate("JanelaCadastrarCliente", "Nome:", nullptr));
        labelDocumento->setText(QCoreApplication::translate("JanelaCadastrarCliente", "Documento:", nullptr));
        pushButtonCadastrar->setText(QCoreApplication::translate("JanelaCadastrarCliente", "Cadastrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JanelaCadastrarCliente: public Ui_JanelaCadastrarCliente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELACADASTRARCLIENTE_H
