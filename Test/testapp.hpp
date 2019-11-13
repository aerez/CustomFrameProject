#ifndef TESTAPP_HPP
#define TESTAPP_HPP

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class TestApp; }
QT_END_NAMESPACE

class TestApp : public QDialog
{
    Q_OBJECT

public:
    TestApp(QWidget *parent = nullptr);
    ~TestApp();

private:
    Ui::TestApp *ui;
};
#endif // TESTAPP_HPP
