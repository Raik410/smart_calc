#include "calc_functions.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./ui_credit_calc.h"
#include "credit_calc.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_xMin->setAlignment(Qt::AlignCenter);
    ui->label_xMax->setAlignment(Qt::AlignCenter);
    ui->label_yMin->setAlignment(Qt::AlignCenter);
    ui->label_yMax->setAlignment(Qt::AlignCenter);

    QColor back_color("#1A1F33");
    QColor label_color("white");
    ui->widget_2->setBackground(QBrush(back_color));
    ui->widget_2->xAxis->setTickLabelColor(label_color);
    ui->widget_2->yAxis->setTickLabelColor(label_color);

    ui->widget_2->xAxis->setBasePen(QPen(QColor(255, 255, 255)));
    ui->widget_2->yAxis->setBasePen(QPen(QColor(255, 255, 255)));

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
    connect(ui->pushButton_31, &QPushButton::clicked, this, &MainWindow::on_pushButton_graf_clicked);
    connect(ui->pushButton_35, &QPushButton::clicked, this, &MainWindow::on_openCreditCalcButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitButton_clicked() {
    if (ui->lineEdit->text() == '0') {
        ui->lineEdit->setText("");
    }
    if (expressionComplete) {
        ui->lineEdit->clear();       // Очистка поля, если выражение было вычислено
        expressionComplete = false;  // Сброс флага
    }
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        ui->lineEdit->insert(button->text());
    }
}

void MainWindow::on_pushButton_graf_clicked() {
    QString result_expression = ui->lineEdit->text();
    QByteArray array_of_bytes = result_expression.toLocal8Bit();
    char* str_parser = array_of_bytes.data();
    ui->widget_2->clearGraphs();
    x.clear();
    y.clear();
    yx_1 = 0;
    yx_2 = 0;
    xy_1 = 0;
    xy_2 = 0;
    xBegin = 0;
    xEnd = 0;
    h = 0.1;

    double Y = ui->lineEdit_2->text().toDouble();
    if (Y == 0) Y = 1;

    xy_1 = ui->xMax->text().toDouble();
    xy_2 = ui->xMin->text().toDouble();
    yx_1 = ui->yMax->text().toDouble();
    yx_2 = ui->yMin->text().toDouble();

    xBegin = yx_2;
    xEnd = yx_1 + h;

    ui->widget_2->xAxis->setRange(xy_2, xy_1);
    ui->widget_2->yAxis->setRange(yx_2, yx_1);
    N = (xEnd - xBegin)/h + 2;

    for (X = xBegin; X <= xEnd; X += h) {
        x.push_back(X);
        y.push_back(parser(str_parser, Y*X));
    }

    ui->widget_2->addGraph();
    ui->widget_2->graph(0)->addData(x, y);
    ui->widget_2->replot();
}

void MainWindow::clearButton_clicked() {
    ui->lineEdit->clear();
}

void MainWindow::calculateButton_clicked() {
    QString input = ui->lineEdit->text();
    QByteArray byteArray = input.toLocal8Bit();
    char* cInput = byteArray.data();

    bool ok;
    double x_value = ui->lineEdit_2->text().toDouble();

    QString result_to_str = QString::number(parser(cInput, x_value), 'g', 15);

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

void MainWindow::on_openCreditCalcButton_clicked() {
    credit_calc credit_ui(this); // Создаем диалоговое окно как дочернее к MainWindow
    credit_ui.exec(); // Показываем диалоговое окно
}



