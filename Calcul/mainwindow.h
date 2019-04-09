#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void on_pushButton_tocka_clicked();
    void operations();
    void on_pushButton_AC_clicked();
    void on_pushButton_ravno_clicked();
    void math_operation();
};

#endif // MAINWINDOW_H
