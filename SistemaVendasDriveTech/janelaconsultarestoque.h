#ifndef JANELACONSULTARESTOQUE_H
#define JANELACONSULTARESTOQUE_H

#include <QWidget>

namespace Ui {
class JanelaConsultarEstoque;
}

class JanelaConsultarEstoque : public QWidget
{
    Q_OBJECT

signals:
    void voltarParaPrincipal();

public:
    explicit JanelaConsultarEstoque(QWidget *parent = nullptr);
    ~JanelaConsultarEstoque();
    void verificarCamposValidos();

private slots:

    void on_comboBoxTipoDeVeiculo_currentTextChanged(const QString &arg1);

    void on_pushButtonConsulta_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::JanelaConsultarEstoque *ui;
};

#endif // JANELACONSULTARESTOQUE_H
