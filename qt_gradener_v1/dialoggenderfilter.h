#ifndef DIALOGGENDERFILTER_H
#define DIALOGGENDERFILTER_H

#include <QDialog>

namespace Ui {
class DialogGenderFilter;
}

class DialogGenderFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGenderFilter(QWidget *parent = nullptr);
    ~DialogGenderFilter();

    QString genderFilter;

private slots:
    void on_buttonBoxGenderFilter_accepted();

private:
    Ui::DialogGenderFilter *ui;
};

#endif // DIALOGGENDERFILTER_H
