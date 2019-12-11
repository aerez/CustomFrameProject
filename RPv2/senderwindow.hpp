#ifndef SENDERWINDOW_HPP
#define SENDERWINDOW_HPP

#include <QMainWindow>
#include <QTextBrowser>
#include <QObject>
#include <QtDebug>
#include <QTextBrowser>
#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fstream>
#include <sstream>
#include <pthread.h>
#include <QFileSystemModel>

#include "kathread.hpp"
#include "filethread.hpp"
#include "Packets/datapacket.hpp"
#include "Packets/infopacket.hpp"




QT_BEGIN_NAMESPACE
namespace Ui { class SenderWindow; }
QT_END_NAMESPACE

class SenderWindow : public QMainWindow
{
    Q_OBJECT

public:
    SenderWindow(QWidget *parent = nullptr);

    void setConfig();

    int establishConnection();






    ~SenderWindow();

public slots:
    void on_btnStart_clicked();

    void onConsoleChanged(QString);




private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_btnSend_clicked();

    void on_progressBar_valueChanged(int value,int max);

private:
    Ui::SenderWindow *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    std::string ip,port,dirpath;
    int sockfd;
    struct addrinfo *p;
    KAThread *kathread;
    Filethread *filethread;

};
#endif // SENDERWINDOW_HPP
