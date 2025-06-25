#include "mainwindow.h"
#include "ui_mainwindow.h"

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




int firstnum, secondnum, result;  // Deklarera tre heltalsvariabler: två för indata och en för resultatet

// När plus-knappen klickas
void MainWindow::on_pushButton_clicked()
{
    firstnum = ui->txtFirstNum->text().toInt();       // Läs in texten från txtFirstNum och konvertera till int
    secondnum = ui->txtSecoundNum->text().toInt();    // Läs in texten från txtSecoundNum och konvertera till int
    result = firstnum + secondnum;                      // Lägg ihop de två talen
    ui->txtResult->setText(QString::number(result));   // Konvertera resultatet till QString och visa i txtResult
}

// När minus-knappen klickas
void MainWindow::on_pushButton_2_clicked()
{
    firstnum = ui->txtFirstNum->text().toInt();       // Läs in första talet från txtFirstNum
    secondnum = ui->txtSecoundNum->text().toInt();    // Läs in andra talet från txtSecoundNum
    result = firstnum - secondnum;                      // Subtrahera andra talet från första talet
    ui->txtResult->setText(QString::number(result));   // Visa resultatet som text i txtResult
}

// När multiplikations-knappen klickas
void MainWindow::on_pushButton_4_clicked()
{
    firstnum = ui->txtFirstNum->text().toInt();       // Läs in första talet från txtFirstNum
    secondnum = ui->txtSecoundNum->text().toInt();    // Läs in andra talet från txtSecoundNum
    result = firstnum * secondnum;                      // Multiplicera talen
    ui->txtResult->setText(QString::number(result));   // Visa resultatet som text i txtResult
}

// När divisions-knappen klickas
void MainWindow::on_pushButton_3_clicked()
{
    firstnum = ui->txtFirstNum->text().toInt();       // Läs in första talet från txtFirstNum
    secondnum = ui->txtSecoundNum->text().toInt();    // Läs in andra talet från txtSecoundNum

    if (secondnum != 0) {                              // Kontrollera att andra talet inte är noll (delning med noll är ej tillåten)
        result = firstnum / secondnum;                  // Dividera första talet med andra talet
        ui->txtResult->setText(QString::number(result)); // Visa resultatet i txtResult
    } else {
        ui->txtResult->setText("Kan inte dela med noll!"); // Visa felmeddelande vid division med noll
    }
}
