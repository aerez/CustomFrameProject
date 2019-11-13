#include "testapp.hpp"
#include "ui_testapp.h"

TestApp::TestApp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TestApp)
{
    ui->setupUi(this);
}

TestApp::~TestApp()
{
    delete ui;
}

