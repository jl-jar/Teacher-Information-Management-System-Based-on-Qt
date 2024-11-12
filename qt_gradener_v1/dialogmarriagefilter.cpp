#include "dialogmarriagefilter.h"
#include "ui_dialogmarriagefilter.h"

DialogMarriageFilter::DialogMarriageFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMarriageFilter)
{
    ui->setupUi(this);
}

DialogMarriageFilter::~DialogMarriageFilter()
{
    delete ui;
}

void DialogMarriageFilter::on_buttonBoxMarriageFilter_accepted()
{
    marriageFilter = ui->comboBoxMarriageFilter->currentText();
}
