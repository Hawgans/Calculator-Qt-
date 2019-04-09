#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus,SIGNAL(clicked()), this,SLOT(operations()));
    connect(ui->pushButton_procent,SIGNAL(clicked()), this,SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()), this,SLOT(math_operation()));
    connect(ui->pushButton_minus,SIGNAL(clicked()), this,SLOT(math_operation()));
    connect(ui->pushButton_umnowenie,SIGNAL(clicked()), this,SLOT(math_operation()));
    connect(ui->pushButton_delenie,SIGNAL(clicked()), this,SLOT(math_operation()));

    ui->pushButton_delenie->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_umnowenie->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
}



 //^^^^^НАЗНАЧЕНИЕ КНОПОК^^^^^


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *) sender();

    double all_numbers;
    QString new_lable;

    if (ui->resultat->text().contains(".") && button->text() == "0") {
        new_lable = ui->resultat->text() + button->text();
    } else {

    all_numbers = (ui->resultat->text() + button->text()).toDouble();
    new_lable = QString::number(all_numbers,'g', 15);
    }
    ui->resultat->setText(new_lable);
}




void MainWindow::on_pushButton_tocka_clicked() //ТОЧКА
{
    if(!(ui->resultat->text().contains('.')))
     ui->resultat->setText(ui->resultat->text() + ".");
}





void MainWindow::operations() //ОПЕРАЦИИ
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;
    QString new_lable;

    if(button->text() == "+/-"){
    all_numbers = (ui->resultat->text()).toDouble();
    all_numbers = all_numbers * -1;
    new_lable = QString::number(all_numbers,'g', 15);

    ui->resultat->setText(new_lable);
    } else if(button->text() == "%"){
        all_numbers = (ui->resultat->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_lable = QString::number(all_numbers,'g', 15);

        ui->resultat->setText(new_lable);
    }
}




void MainWindow::math_operation() //МАТ.ОПЕРАЦИИ
{
    QPushButton *button = (QPushButton *) sender();

    num_first = ui->resultat->text().toDouble();
    ui->resultat->setText("");
    button->setChecked(true);
}






void MainWindow::on_pushButton_AC_clicked() //СБРОС
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_delenie->setChecked(false);
    ui->pushButton_umnowenie->setChecked(false);

    ui->resultat->setText("0");

}





void MainWindow::on_pushButton_ravno_clicked() //РАВНО+ВЫЧИСЛЕНИЯ
{
    double lableNamber, num_second;
    QString new_lable;

    num_second = ui->resultat->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        lableNamber = num_first + num_second;
        new_lable = QString::number(lableNamber,'g', 15);

        ui->resultat->setText(new_lable);
        ui->pushButton_plus->setChecked(false);

    } else if(ui->pushButton_minus->isChecked()){
        lableNamber = num_first - num_second;
        new_lable = QString::number(lableNamber,'g', 15);

        ui->resultat->setText(new_lable);
        ui->pushButton_minus->setChecked(false);

    } else if(ui->pushButton_delenie->isChecked()){
        if (num_second == 0){
            ui->resultat->setText("0");
        } else{
        lableNamber = num_first / num_second;
        new_lable = QString::number(lableNamber,'g', 15);

        ui->resultat->setText(new_lable);
        ui->pushButton_delenie->setChecked(false);
    }
    } else if(ui->pushButton_umnowenie->isChecked()){
        lableNamber = num_first * num_second;
        new_lable = QString::number(lableNamber,'g', 15);

        ui->resultat->setText(new_lable);
        ui->pushButton_umnowenie->setChecked(false);

    }
}
