#include "dialoglogin.h"
#include "mainwindow.h"
#include "ui_dialoglogin.h"

DialogLogIn::DialogLogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogIn)
{
    ui->setupUi(this);
    //setWindowOpacity(0.5);//设置窗口透明度，所有控件也会变透明
}

DialogLogIn::~DialogLogIn()
{
    delete ui;
}

void DialogLogIn::on_buttonBoxLogIn_accepted()
{
    user = "seu"; //账户名
    password = "123456";//登陆密码
    user_name = ui->lineEdit_user->text();
    key = ui->lineEditLogIn->text();
}

