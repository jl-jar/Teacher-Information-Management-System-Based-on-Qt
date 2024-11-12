#ifndef DIALOGJOBTITLEFILTER_H
#define DIALOGJOBTITLEFILTER_H

#include <QDialog>

namespace Ui {
class DialogJobTitleFilter;
}

class DialogJobTitleFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogJobTitleFilter(QWidget *parent = nullptr);
    ~DialogJobTitleFilter();

    QString jobTitleFilter;

private slots:
    void on_buttonBoxJobTitleFilter_accepted();

private:
    Ui::DialogJobTitleFilter *ui;
};

#endif // DIALOGJOBTITLEFILTER_H
