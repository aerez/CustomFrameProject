#include "configdialog.hpp"
#include "ui_configdialog.h"

Configdialog::Configdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configdialog)
{
    ui->setupUi(this);
}

Configdialog::~Configdialog()
{
    delete ui;
}
