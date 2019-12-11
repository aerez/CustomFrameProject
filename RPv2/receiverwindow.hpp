#ifndef RECEIVERWINDOW_HPP
#define RECEIVERWINDOW_HPP

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

#include "Packets/datapacket.hpp"
#include "Packets/infopacket.hpp"
#include "filewriter.hpp"
#include "filemanager.hpp"

namespace Ui {
class ReceiverWindow;
}

class ReceiverWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReceiverWindow(QWidget *parent = nullptr);

    void setConfig();

    int setUpSocket();

    void receiveRun();

    std::vector<FileWriter>::iterator getFileByFileID(int fileID);



    ~ReceiverWindow();

public slots:

    void onConsoleChanged(QString);

    void on_progressBar_valueChanged(int value,int max);


private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::ReceiverWindow *ui;
    QFileSystemModel *dirmodel;
    std::string ip,port,dirpath;
    int sockfd;
    bool run=false;
    std::vector<FileWriter> files;
    struct addrinfo *p;
    FileManager *fm;
};

#endif // RECEIVERWINDOW_HPP
