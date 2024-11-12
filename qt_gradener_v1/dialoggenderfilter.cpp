#include "dialoggenderfilter.h"
#include "ui_dialoggenderfilter.h"

DialogGenderFilter::DialogGenderFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGenderFilter)
{
    ui->setupUi(this);
}

DialogGenderFilter::~DialogGenderFilter()
{
    delete ui;
}

void DialogGenderFilter::on_buttonBoxGenderFilter_accepted()
{
    genderFilter = ui->comboBoxGenderFilter->currentText();
}
