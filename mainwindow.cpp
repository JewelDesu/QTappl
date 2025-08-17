#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cstdlib"
#include "vector"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //std::vector<int> value(10);
    for (int i = 0; i < 10; i++) {
        values.push_back(std::rand() % 31);
        series->append(i, values[i]);
    }


    
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Chungus");
    chart->axes(Qt::Vertical).first()->setRange(0,100);

    
    QChartView* view = new QChartView(chart);
    
    view->setRenderHint(QPainter::Antialiasing);
    view->setParent(ui->horizontalFrame);
    //view->resize(640,480);


    // Timer to update every 60 seconds (for testing, set 1000ms)
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateChart);
    timer->start(1000); // 60000 ms = 1 minute
}
void MainWindow::updateChart()
{

    // shift values
    values.erase(values.begin());
    values.push_back(std::rand() % 31);

    series->clear();
    for (int i = 0; i < (int)values.size(); i++) {
        series->append(i, values[i]);
    }
}
MainWindow::~MainWindow()
{
    delete ui;


}
