#ifndef JANELACADASTRARCLIENTE_H
#define JANELACADASTRARCLIENTE_H

#include <QWidget>

namespace Ui {
class JanelaCadastrarCliente;
}

class JanelaCadastrarCliente : public QWidget
{
    Q_OBJECT

signals:
    // Define a capacidade de notificar o pai
    void voltarParaPrincipal();

public:
    explicit JanelaCadastrarCliente(QWidget *parent = nullptr);
    ~JanelaCadastrarCliente();

private slots:
    void on_pushButtonCadastrar_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::JanelaCadastrarCliente *ui;
};

#endif // JANELACADASTRARCLIENTE_H
