#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>

namespace Ui {
class DialogLogIn;
}

class DialogLogIn : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogIn(QWidget *parent = nullptr);
    ~DialogLogIn();

    QString password;//预设密码
    QString key;//用户输入密码

    QString user;//预设账户名
    QString user_name;//用户输入账户


private slots:
    void on_buttonBoxLogIn_accepted();

private:
    Ui::DialogLogIn *ui;
};

#endif // DIALOGLOGIN_H
