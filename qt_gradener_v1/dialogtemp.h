#ifndef DIALOGTEMP_H
#define DIALOGTEMP_H

#include <QDialog>

namespace Ui {
class DialogTemp;
}

class DialogTemp : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTemp(QWidget *parent = nullptr);
    ~DialogTemp();

private:
    Ui::DialogTemp *ui;
};

#endif // DIALOGTEMP_H
