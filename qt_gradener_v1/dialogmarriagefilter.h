#ifndef DIALOGMARRIAGEFILTER_H
#define DIALOGMARRIAGEFILTER_H

#include <QDialog>

namespace Ui {
class DialogMarriageFilter;
}

class DialogMarriageFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMarriageFilter(QWidget *parent = nullptr);
    ~DialogMarriageFilter();

    QString marriageFilter;

private slots:
    void on_buttonBoxMarriageFilter_accepted();

private:
    Ui::DialogMarriageFilter *ui;
};

#endif // DIALOGMARRIAGEFILTER_H
