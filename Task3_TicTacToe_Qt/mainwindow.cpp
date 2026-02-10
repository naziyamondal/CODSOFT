#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentPlayer = "X";
    gameOver = false;
    ui->labelStatus->setText("Player X Turn");

    // Connect all buttons using loop (clean way)
    QList<QPushButton*> buttons = {
        ui->btn1, ui->btn2, ui->btn3,
        ui->btn4, ui->btn5, ui->btn6,
        ui->btn7, ui->btn8, ui->btn9
    };

    for (QPushButton* btn : buttons)
        connect(btn, &QPushButton::clicked, this, &MainWindow::handleButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{
    if (gameOver) return;  // Stop game after win

    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (button->text() != "")
        return;

    button->setText(currentPlayer);

    checkWinner();

    if (!gameOver) {
        currentPlayer = (currentPlayer == "X") ? "O" : "X";
        ui->labelStatus->setText("Player " + currentPlayer + " Turn");
    }
}

void MainWindow::checkWinner()
{
    QPushButton* b[9] = {
        ui->btn1, ui->btn2, ui->btn3,
        ui->btn4, ui->btn5, ui->btn6,
        ui->btn7, ui->btn8, ui->btn9
    };

    int winCombos[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (int i = 0; i < 8; i++)
    {
        if (b[winCombos[i][0]]->text() == currentPlayer &&
            b[winCombos[i][1]]->text() == currentPlayer &&
            b[winCombos[i][2]]->text() == currentPlayer)
        {
            ui->labelStatus->setText("🎉 Player " + currentPlayer + " Wins!");
            gameOver = true;
            return;
        }
    }

    // ✅ Check Draw
    bool draw = true;
    for (int i = 0; i < 9; i++) {
        if (b[i]->text() == "") {
            draw = false;
            break;
        }
    }

    if (draw) {
        ui->labelStatus->setText("🤝 Match Draw!");
        gameOver = true;
    }
}

void MainWindow::on_btnReset_clicked()
{
    QPushButton* b[9] = {
        ui->btn1, ui->btn2, ui->btn3,
        ui->btn4, ui->btn5, ui->btn6,
        ui->btn7, ui->btn8, ui->btn9
    };

    for (int i = 0; i < 9; i++)
        b[i]->setText("");

    currentPlayer = "X";
    gameOver = false;
    ui->labelStatus->setText("Player X Turn");
}
