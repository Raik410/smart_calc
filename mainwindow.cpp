#include "calc_functions.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, buttons) {
        button->setCursor(Qt::PointingHandCursor);
    }

    QList<QPushButton*> digitButtons = {
        ui->pushButton, ui->pushButton_2,
        ui->pushButton_3, ui->pushButton_4, ui->pushButton_5,
        ui->pushButton_6, ui->pushButton_7, ui->pushButton_8,
        ui->pushButton_9, ui->pushButton_10, ui->pushButton_11, ui->pushButton_13,
        ui->pushButton_14, ui->pushButton_15, ui->pushButton_16, ui->pushButton_17, ui->pushButton_18,
        ui->pushButton_19, ui->pushButton_20, ui->pushButton_21, ui->pushButton_22, ui->pushButton_23,
        ui->pushButton_24, ui->pushButton_26, ui->pushButton_27, ui->pushButton_28, ui->pushButton_29,
        ui->pushButton_30, ui->pushButton_33
    };

    foreach (QPushButton* button, digitButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::digitButton_clicked);
    }

    connect(ui->pushButton_25, &QPushButton::clicked, this, &MainWindow::clearButton_clicked);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::calculateButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitButton_clicked() {
    if (expressionComplete) {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();        // Очистка поля, если выражение было вычислено
        expressionComplete = false;  // Сброс флага
    }
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        ui->lineEdit->insert(button->text());
    }
}

void MainWindow::clearButton_clicked() {
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::calculateButton_clicked() {
    // Получаем введенную строку из QLineEdit
    QString input = ui->lineEdit->text();
    QByteArray byteArray = input.toLocal8Bit();
    char* cInput = byteArray.data();

    bool ok;
    double x_value = ui->lineEdit_2->text().toDouble(&ok);
    if (!ok || !x_value) {
        // Обработка ошибки, если строка не может быть преобразована в число
        qDebug() << "Invalid x value";
        x_value = 0;
    }

    // Вызываем функцию parser с введенным пользователем выражением
    QString result_to_str = QString::number(parser(cInput, x_value), 'g', 15);

    // Отображаем результат расчета на основе ввода пользователя в QLineEdit
    ui->lineEdit->setText(result_to_str);
    expressionComplete = true;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Backspace) {
        // Используйте backspace() вместо clear(), чтобы удалить последний символ
        ui->lineEdit->backspace();
    } else if ((event->key() == Qt::Key_Equal) || (event->key() == Qt::Key_Return)) {
        // Вызов функции calculateButton_clicked при нажатии Enter
        calculateButton_clicked();
        return;
    } else if (event->key() == Qt::Key_Space) {
        return;
    } else if (!event->text().isEmpty()) {
        // Добавление текста события в lineEdit
        ui->lineEdit->insert(event->text());
    } else {
        // Для всех других клавиш вызываем базовую реализацию
        QMainWindow::keyPressEvent(event);
    }
}



