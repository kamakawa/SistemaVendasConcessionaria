/********************************************************************************
** Form generated from reading UI file 'janelalistarvendas.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELALISTARVENDAS_H
#define UI_JANELALISTARVENDAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaListarVendas
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonVoltar;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidgetVendas;

    void setupUi(QWidget *JanelaListarVendas)
    {
        if (JanelaListarVendas->objectName().isEmpty())
            JanelaListarVendas->setObjectName("JanelaListarVendas");
        JanelaListarVendas->resize(1247, 746);
        verticalLayout = new QVBoxLayout(JanelaListarVendas);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(JanelaListarVendas);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonVoltar = new QPushButton(widget);
        pushButtonVoltar->setObjectName("pushButtonVoltar");
        pushButtonVoltar->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(pushButtonVoltar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        tableWidgetVendas = new QTableWidget(JanelaListarVendas);
        tableWidgetVendas->setObjectName("tableWidgetVendas");
        tableWidgetVendas->setStyleSheet(QString::fromUtf8("color: white;"));

        verticalLayout->addWidget(tableWidgetVendas);


        retranslateUi(JanelaListarVendas);

        QMetaObject::connectSlotsByName(JanelaListarVendas);
    } // setupUi

    void retranslateUi(QWidget *JanelaListarVendas)
    {
        JanelaListarVendas->setWindowTitle(QCoreApplication::translate("JanelaListarVendas", "Form", nullptr));
        pushButtonVoltar->setText(QCoreApplication::translate("JanelaListarVendas", "Voltar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JanelaListarVendas: public Ui_JanelaListarVendas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELALISTARVENDAS_H
