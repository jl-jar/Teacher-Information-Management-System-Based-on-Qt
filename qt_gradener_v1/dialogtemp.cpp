#include "dialogtemp.h"
#include "ui_dialogtemp.h"

DialogTemp::DialogTemp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogTemp)
{
    ui->setupUi(this);
}

DialogTemp::~DialogTemp()
{
    delete ui;
}
