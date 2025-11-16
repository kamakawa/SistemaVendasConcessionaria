#ifndef JANELAREGISTRARVENDA_H
#define JANELAREGISTRARVENDA_H

#include <QWidget>
#include <QCompleter>

namespace Ui {
class JanelaRegistrarVenda;
}

class JanelaRegistrarVenda : public QWidget
{
    Q_OBJECT

signals:
    // Define a capacidade de notificar o pai
    void voltarParaPrincipal();

public:
    explicit JanelaRegistrarVenda(QWidget *parent = nullptr);
    ~JanelaRegistrarVenda();

    void atualizarAutocompleteNomeCliente();

private slots:
    void configurarAutocompleteNomeCliente();

    void preencherDocumentoDoCliente(const QString &nomeSelecionado);  // novo slot

    void on_comboBoxTipo_currentTextChanged(const QString &arg1);

    void on_comboBoxModelo_currentTextChanged(const QString &arg1);

    void on_comboBoxAno_currentTextChanged(const QString &arg1);

    void on_comboBoxPagamento_currentTextChanged(const QString &arg1);

    void on_pushButtonRegistrarVenda_clicked();

    void on_pushButtonCancelar_clicked();

private:
    Ui::JanelaRegistrarVenda *ui;
};

#endif // JANELAREGISTRARVENDA_H
