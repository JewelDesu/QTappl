#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLineSeries* series = new QLineSeries();
    series->append(0, 6);
    series->append(1, 4);
    series->append(2, 9);
    series->append(3, 7);
    series->append(4, 3);
    series->append(5, 8);
    series->append(6, 5);
    series->append(7, 6);
    series->append(8, 1);
    series->append(9, 8);

    
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Chungus");
    
    QChartView* view = new QChartView(chart);
    
    view->setRenderHint(QPainter::Antialiasing);
    view->setParent(ui->horizontalFrame);
}

MainWindow::~MainWindow()
{
    delete ui;


}
