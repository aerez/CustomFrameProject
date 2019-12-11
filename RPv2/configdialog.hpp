#ifndef CONFIGDIALOG_HPP
#define CONFIGDIALOG_HPP

#include <QDialog>

namespace Ui {
class Configdialog;
}

class Configdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Configdialog(QWidget *parent = nullptr);
    ~Configdialog();

private:
    Ui::Configdialog *ui;
};

#endif // CONFIGDIALOG_HPP
