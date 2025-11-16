#ifndef JANELADELOGIN_H
#define JANELADELOGIN_H

#include <QDialog>

namespace Ui {
class JanelaDeLogin;
}

class JanelaDeLogin : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaDeLogin(QWidget *parent = nullptr);
    ~JanelaDeLogin();

private slots:
    void on_pushButtonEntrar_clicked();

private:
    Ui::JanelaDeLogin *ui;
};

#endif // JANELADELOGIN_H
