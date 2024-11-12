#include "dialoghighestdegreefilter.h"
#include "ui_dialoghighestdegreefilter.h"

DialogHighestDegreeFilter::DialogHighestDegreeFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHighestDegreeFilter)
{
    ui->setupUi(this);
}

DialogHighestDegreeFilter::~DialogHighestDegreeFilter()
{
    delete ui;
}

void DialogHighestDegreeFilter::on_buttonBox_accepted()
{
    highestDegreeFilter = ui->comboBoxHighestDegreeFilter->currentText();
}
