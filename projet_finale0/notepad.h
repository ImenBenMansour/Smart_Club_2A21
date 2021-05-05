#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

namespace Ui {
class notepad;
}

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit notepad(QWidget *parent = nullptr);
    ~notepad();

private:
    Ui::notepad *ui;
};

#endif // NOTEPAD_H
