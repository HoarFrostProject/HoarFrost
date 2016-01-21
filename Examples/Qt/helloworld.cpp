#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <stdio.h>

void print_hello() {
  qDebug("Hello World");
}
 
int main(int argc, char **argv)
{
 QApplication app (argc, argv);
 
 QWidget *window = new QWidget();
 window->setWindowTitle(QString::fromUtf8("MainWindow"));
 window->resize(200, 200);

 QHBoxLayout *layout = new QHBoxLayout();
 QPushButton *button = new QPushButton("Hello World");
 layout->addWidget(button);
 window->setLayout(layout);
 window->show();

 QObject::connect(button, &QPushButton::clicked, print_hello);
 
 return app.exec();
}
