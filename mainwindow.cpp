#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    m_whiteboard = new WhiteBoard;
    QVBoxLayout *vlay = new QVBoxLayout(m_whiteboard);

    QPushButton *btn1 = new QPushButton("     ");
    QPalette pal = btn1->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    btn1->setAutoFillBackground(true);
    btn1->setPalette(pal);
    btn1->update();
    vlay->addWidget(btn1,0,Qt::AlignRight);

    QPushButton *btn2 = new QPushButton("     ");
    pal = btn2->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    btn2->setAutoFillBackground(true);
    btn2->setPalette(pal);
    btn2->update();
    vlay->addWidget(btn2,0,Qt::AlignRight);

    QPushButton *btn3 = new QPushButton("     ");
    pal = btn3->palette();
    pal.setColor(QPalette::Button, QColor(Qt::green));
    btn3->setAutoFillBackground(true);
    btn3->setPalette(pal);
    btn3->update();
    vlay->addWidget(btn3,0,Qt::AlignRight);

    QPushButton *btn4 = new QPushButton("Clear");
    pal = btn4->palette();
    pal.setColor(QPalette::Button, QColor(Qt::white));
    btn4->setAutoFillBackground(true);
    btn4->setPalette(pal);
    btn4->update();
    vlay->addWidget(btn4,0,Qt::AlignRight);

    m_whiteboard->setLayout(vlay);
    setCentralWidget(m_whiteboard);

    QPixmap image(":/images/logo.png");
    QLabel* logo = new QLabel(this);
    logo->setGeometry(10, 10, image.width() * (800 / width()), image.height() * (480 / height()));
    logo->setPixmap(image.scaled(logo->width(), logo->height(), Qt::KeepAspectRatio));

    connect(btn1, SIGNAL (pressed()), this, SLOT(setPenBlue()));
    connect(btn2, SIGNAL (pressed()), this, SLOT(setPenRed()));
    connect(btn3, SIGNAL (pressed()), this, SLOT(setPenGreen()));
    connect(btn4, SIGNAL (pressed()), this, SLOT(clearScreen()));
}

void MainWindow::setPenBlue()
{
    m_whiteboard->setPenColor(Qt::blue);
}

void MainWindow::setPenRed()
{
    m_whiteboard->setPenColor(Qt::red);
}

void MainWindow::setPenGreen()
{
    m_whiteboard->setPenColor(Qt::green);
}

void MainWindow::clearScreen()
{
    m_whiteboard->clearImage();
}

MainWindow::~MainWindow()
{

}
