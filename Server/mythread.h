#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QTcpSocket>
#include <QThread>

/**
 * @brief The mythread class
 * This is class has the base class of QThread
 * Everytime new connection comes new thread has to be created
 * This is why implement seperate class for threads.
 */
class mythread : public QThread
{
    Q_OBJECT
public:
   explicit mythread(QObject *parent=0);
    QTcpSocket *socket;
      void run();

signals:
   void messageInvoked(QByteArray);

private:
int socketDescriptor;

private slots:



};

#endif // MYTHREAD_H
