#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>

qint16 a=1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile file("I://database.csv");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append))
       { QMessageBox::warning(this,"Error","Whoops sorry bro file not open");
        }
    QTextStream out (&file);
    QString text = " , " + ui->plainTextEdit->toPlainText() + " ," + ui->plainTextEdit_2->toPlainText() + " ," + ui->plainTextEdit_3->toPlainText() + "\n" ;
    out << a <<text;
    a++;
    QMessageBox::information(this,"Niceee","Append Successful !!!!");
    file.flush();
    file.close();
}


void MainWindow::on_read_clicked()
{
    QFile file("I://database.csv");
    if(!file.open(QFile::ReadOnly | QFile::Text))
       { QMessageBox::warning(this,"Error","Whoops sorry bro file not open !!! ");
        }
    QTextStream in (&file);
    QString text = in.readAll();
    ui->plainTextEdit_4->setPlainText(text);
    QMessageBox::information(this,"Successful","Data read successsfully !!! ");
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file("I://database.csv");
    if(!file.open(QFile::WriteOnly | QFile::Text))
       { QMessageBox::warning(this,"Error","Whoops sorry bro file not open !!! ");
        }
    QTextStream out (&file);
    QString text = ui->plainTextEdit_4->toPlainText();
    out << text;
    QMessageBox::information(this,"Successful","Data rewritten successfully !!!");
    file.flush();
    file.close();
}
