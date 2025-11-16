#ifndef JANELALISTARVENDAS_H
#define JANELALISTARVENDAS_H

#include <QWidget>

namespace Ui {
class JanelaListarVendas;
}

class JanelaListarVendas : public QWidget
{
    Q_OBJECT

signals:
    // Define a capacidade de notificar o pai
    void voltarParaPrincipal();

public:
    explicit JanelaListarVendas(QWidget *parent = nullptr);
    ~JanelaListarVendas();
    void carregarVendas();

private slots:
    void on_pushButtonVoltar_clicked();

private:
    Ui::JanelaListarVendas *ui;
};

#endif // JANELALISTARVENDAS_H
