#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Generate random number between 1 and 100
    secretNumber = QRandomGenerator::global()->bounded(1, 101);

    ui->labelResult->setText("Make a guess!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGuess_clicked()
{
    int userGuess = ui->lineEditGuess->text().toInt();

    if (userGuess < secretNumber)
    {
        ui->labelResult->setText("Too Low ❌");
    }
    else if (userGuess > secretNumber)
    {
        ui->labelResult->setText("Too High ❌");
    }
    else
    {
        ui->labelResult->setText("Correct 🎉 You Win!");
    }
}

void MainWindow::on_btnReset_clicked()
{
    secretNumber = QRandomGenerator::global()->bounded(1, 101);
    ui->lineEditGuess->clear();
    ui->labelResult->setText("Game reset. Try again!");
}
void MainWindow::on_labelResult_clicked()
{

}

