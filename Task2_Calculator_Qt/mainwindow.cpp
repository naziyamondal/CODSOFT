#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect number buttons
    connect(ui->btn0, &QPushButton::clicked, this, &MainWindow::numberPressed);
    connect(ui->btn1, &QPushButton::clicked, this, &MainWindow::numberPressed);
    connect(ui->btn2, &QPushButton::clicked, this, &MainWindow::numberPressed);
    connect(ui->btn3, &QPushButton::clicked, this, &MainWindow::numberPressed);
    connect(ui->btn4, &QPushButton::clicked, this, &MainWindow::numberPressed);
    connect(ui->btn5, &QPushButton::clicked, this, &MainWindow::numberPressed);
    connect(ui->btn6, &QPushButton::clicked, this, &MainWindow::numberPressed);
    connect(ui->btn7, &QPushButton::clicked, this, &MainWindow::numberPressed);
    connect(ui->btn8, &QPushButton::clicked, this, &MainWindow::numberPressed);
    connect(ui->btn9, &QPushButton::clicked, this, &MainWindow::numberPressed);

    // Connect operator buttons
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->btnSub, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->btnMul, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->btnDiv, &QPushButton::clicked, this, &MainWindow::operatorPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    ui->lineEditDisplay->setText(ui->lineEditDisplay->text() + button->text());
}

void MainWindow::operatorPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    firstNumber = ui->lineEditDisplay->text().toDouble();
    currentOperator = button->text();
    ui->lineEditDisplay->clear();
}

void MainWindow::on_btnEqual_clicked()
{
    double secondNumber = ui->lineEditDisplay->text().toDouble();
    double result = 0;

    if (currentOperator == "+")
        result = firstNumber + secondNumber;
    else if (currentOperator == "-")
        result = firstNumber - secondNumber;
    else if (currentOperator == "*")
        result = firstNumber * secondNumber;
    else if (currentOperator == "/")
        result = secondNumber != 0 ? firstNumber / secondNumber : 0;

    ui->lineEditDisplay->setText(QString::number(result));
}

void MainWindow::on_btnClear_clicked()
{
    ui->lineEditDisplay->clear();
}
