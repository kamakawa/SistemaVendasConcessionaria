#include <QApplication>
#include "janeladelogin.h"
#include <QByteArray>
#include "backend/gerenciadordrivetech.h" 
#include <QMessageBox>                    

int main(int argc, char *argv[])
{
    qputenv("QT_QPA_PLATFORM", "xcb"); // força X11, corrige bug do combo do Wayland
    QApplication a(argc, argv);

    a.setStyleSheet("QMessageBox {"
                    "   background-color: #333333; /* Fundo cinza escuro */"
                    "   color: #EEEEEE; /* Texto claro */"
                    "   font-family: Arial; /* Fonte */"
                    "   font-size: 14px;"
                    "}"
                    "QMessageBox QLabel {"
                    "   color: #EEEEEE; /* Garante que o texto dentro da label do QMessageBox seja claro */"
                    "}"
                    "QMessageBox QPushButton {"
                    "   background-color: #007ACC; /* Botão azul */"
                    "   color: white; /* Texto do botão branco */"
                    "   border: 1px solid #007ACC;"
                    "   padding: 5px 15px;"
                    "   border-radius: 3px;"
                    "}"
                    "QMessageBox QPushButton:hover {"
                    "   background-color: #005f99;"
                    "}");

    try {
        // Tenta carregar os dados do sistema antes de abrir a janela
        GerenciadorDriveTech::obterInstancia()->inicializarSistema();

    } catch (const std::exception& e) {
        // Se falhar, mostra o pop-up
        QMessageBox::critical(nullptr, "Erro Crítico de Inicialização",
            QString("Não foi possível carregar os arquivos de dados.\n") +
            QString("Erro: %1\n").arg(e.what()) +
            QString("O aplicativo será fechado.")
        );
        return 1; // Fecha o app se os arquivos não puderem ser lidos
    }

    JanelaDeLogin login;

    if (login.exec() == QDialog::Accepted) {
        return a.exec();
    }

    return 0;
}
