#ifndef DIALOGHIGHESTDEGREEFILTER_H
#define DIALOGHIGHESTDEGREEFILTER_H

#include <QDialog>

namespace Ui {
class DialogHighestDegreeFilter;
}

class DialogHighestDegreeFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHighestDegreeFilter(QWidget *parent = nullptr);
    ~DialogHighestDegreeFilter();

    QString highestDegreeFilter;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogHighestDegreeFilter *ui;
};

#endif // DIALOGHIGHESTDEGREEFILTER_H
