#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "calc_functions.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool expressionComplete = false;
    double xBegin, xEnd, h, X, yx_1, yx_2, xy_1, xy_2;
    int N;
    bool ok;
    QVector<double> x,y;

private slots:
    void digitButton_clicked();
    void clearButton_clicked();
    void calculateButton_clicked();
    void on_pushButton_graf_clicked();
};

#endif // MAINWINDOW_H

