/********************************************************************************
** Form generated from reading UI file 'janeladelogin.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELADELOGIN_H
#define UI_JANELADELOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaDeLogin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelSenha;
    QLabel *labelUsuario;
    QLineEdit *lineEditSenha;
    QLineEdit *lineEditUsuario;
    QPushButton *pushButtonEntrar;
    QLabel *logoEmpresa;

    void setupUi(QDialog *JanelaDeLogin)
    {
        if (JanelaDeLogin->objectName().isEmpty())
            JanelaDeLogin->setObjectName("JanelaDeLogin");
        JanelaDeLogin->resize(734, 513);
        layoutWidget = new QWidget(JanelaDeLogin);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(250, 330, 207, 94));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelSenha = new QLabel(layoutWidget);
        labelSenha->setObjectName("labelSenha");
        labelSenha->setStyleSheet(QString::fromUtf8("color: #00BFFF;\n"
""));

        gridLayout->addWidget(labelSenha, 1, 0, 1, 1);

        labelUsuario = new QLabel(layoutWidget);
        labelUsuario->setObjectName("labelUsuario");
        labelUsuario->setStyleSheet(QString::fromUtf8("color: #00BFFF;\n"
""));

        gridLayout->addWidget(labelUsuario, 0, 0, 1, 1);

        lineEditSenha = new QLineEdit(layoutWidget);
        lineEditSenha->setObjectName("lineEditSenha");
        lineEditSenha->setStyleSheet(QString::fromUtf8(""));
        lineEditSenha->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(lineEditSenha, 1, 1, 1, 1);

        lineEditUsuario = new QLineEdit(layoutWidget);
        lineEditUsuario->setObjectName("lineEditUsuario");
        lineEditUsuario->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lineEditUsuario, 0, 1, 1, 1);

        pushButtonEntrar = new QPushButton(layoutWidget);
        pushButtonEntrar->setObjectName("pushButtonEntrar");
        pushButtonEntrar->setStyleSheet(QString::fromUtf8("color: #00BFFF;\n"
"background-color: #D3D3D3;"));

        gridLayout->addWidget(pushButtonEntrar, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        logoEmpresa = new QLabel(JanelaDeLogin);
        logoEmpresa->setObjectName("logoEmpresa");
        logoEmpresa->setGeometry(QRect(180, 20, 391, 351));
        logoEmpresa->setPixmap(QPixmap(QString::fromUtf8("slogan.png")));
        logoEmpresa->setScaledContents(true);
        logoEmpresa->raise();
        layoutWidget->raise();

        retranslateUi(JanelaDeLogin);

        QMetaObject::connectSlotsByName(JanelaDeLogin);
    } // setupUi

    void retranslateUi(QDialog *JanelaDeLogin)
    {
        JanelaDeLogin->setWindowTitle(QCoreApplication::translate("JanelaDeLogin", "Dialog", nullptr));
        labelSenha->setText(QCoreApplication::translate("JanelaDeLogin", "Senha:", nullptr));
        labelUsuario->setText(QCoreApplication::translate("JanelaDeLogin", "Usuario:", nullptr));
        pushButtonEntrar->setText(QCoreApplication::translate("JanelaDeLogin", "Entrar", nullptr));
        logoEmpresa->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JanelaDeLogin: public Ui_JanelaDeLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELADELOGIN_H
