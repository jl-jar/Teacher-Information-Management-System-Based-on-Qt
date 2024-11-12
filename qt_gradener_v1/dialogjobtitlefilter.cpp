#include "dialogjobtitlefilter.h"
#include "ui_dialogjobtitlefilter.h"

DialogJobTitleFilter::DialogJobTitleFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogJobTitleFilter)
{
    ui->setupUi(this);

}

DialogJobTitleFilter::~DialogJobTitleFilter()
{
    delete ui;
}

void DialogJobTitleFilter::on_buttonBoxJobTitleFilter_accepted()
{
    jobTitleFilter = ui->comboBoxJobTitleFilter->currentText();
}
