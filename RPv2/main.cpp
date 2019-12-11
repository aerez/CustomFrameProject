#include "senderwindow.hpp"
#include "receiverwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(argc>1){
        SenderWindow *w= new SenderWindow();
        w->show();
    }else{
       ReceiverWindow *r= new ReceiverWindow();
       r->show();
    }


    return a.exec();
}
