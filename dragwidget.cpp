#include <QtWidgets>
#include <QTableView>
#include <iostream>
#include <QPushButton>
#include <QObject>

#include "dragwidget.h"

using namespace std;

//! [0]
DragWidget::DragWidget(QWidget *parent)
    : QFrame(parent)
{
    setMinimumWidth(1000);
    setMinimumHeight(600);
    setMaximumWidth(1000);
    setMaximumHeight(600);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    QTableWidget *cuadricula = new QTableWidget(this);
    cuadricula->setColumnCount(15);
    cuadricula->setRowCount(15);
    for(int i=0;i<15;i++){
        cuadricula->setRowHeight(i,25);
    }
    for(int i=0;i<15;i++){
        cuadricula->setColumnWidth(i,55);
    }
    cuadricula->horizontalHeader()->setVisible(false);
    cuadricula->verticalHeader()->setVisible(false);
    cuadricula->setMinimumWidth(857);
    cuadricula->setMinimumHeight(378);
    cuadricula->setMaximumWidth(857);
    cuadricula->setMaximumHeight(378);
    cuadricula->move(20,30);
    this->matriz = cuadricula;

    /*QLabel *boatIcon = new QLabel(this);
    boatIcon->setPixmap(QPixmap("/home/cucho16/ImScrabble/CH.png"));
    boatIcon->move(10, 10);
    boatIcon->show();
    boatIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *carIcon = new QLabel(this);
    carIcon->setPixmap(QPixmap("/home/cucho16/ImScrabble/RR.png"));
    carIcon->move(100, 10);
    carIcon->show();
    carIcon->setAttribute(Qt::WA_DeleteOnClose);*/
    QPushButton *ret = new QPushButton(this);
    ret->move(75,500);
    ret->setText("Return");
    QObject::connect(ret, SIGNAL (clicked()),this, SLOT( on_ret_clicked()));


    QLabel *houseIcon = new QLabel(this);
    houseIcon->setPixmap(QPixmap("/home/cucho16/ImScrabble/Ñ.png"));
    houseIcon->move(75, 450);
    houseIcon->show();
    houseIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon2 = new QLabel(this);
    houseIcon2->setPixmap(QPixmap("/home/cucho16/ImScrabble/Ñ.png"));
    houseIcon2->move(135, 450);
    houseIcon2->show();
    houseIcon2->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon3 = new QLabel(this);
    houseIcon3->setPixmap(QPixmap("/home/cucho16/ImScrabble/Ñ.png"));
    houseIcon3->move(195, 450);
    houseIcon3->show();
    houseIcon3->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon4 = new QLabel(this);
    houseIcon4->setPixmap(QPixmap("/home/cucho16/ImScrabble/Ñ.png"));
    houseIcon4->move(255, 450);
    houseIcon4->show();
    houseIcon4->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon5 = new QLabel(this);
    houseIcon5->setPixmap(QPixmap("/home/cucho16/ImScrabble/Ñ.png"));
    houseIcon5->move(315, 450);
    houseIcon5->show();
    houseIcon5->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon6 = new QLabel(this);
    houseIcon6->setPixmap(QPixmap("/home/cucho16/ImScrabble/Ñ.png"));
    houseIcon6->move(375, 450);
    houseIcon6->show();
    houseIcon6->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseIcon7 = new QLabel(this);
    houseIcon7->setPixmap(QPixmap("/home/cucho16/ImScrabble/Ñ.png"));
    houseIcon7->move(435, 450);
    houseIcon7->show();
    houseIcon7->setAttribute(Qt::WA_DeleteOnClose);
}
//! [0]

void DragWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos() - offset);
        int cC= 0;
        int cR= 0;
        int Dx = 75;
        int dx = 20;
        int Dy = 55;
        int dy = 30;
        while(cC<15){
            if(dx< newIcon->x() + 28 and newIcon->x() + 28 < Dx){
                while(cR<15){
                    if(dy< newIcon->y() + 13 and newIcon->y() + 13 < Dy){
                        this->ficha = newIcon;
                        this->matriz->setCellWidget(cR,cC,newIcon);
                        newIcon->show();
                        newIcon->setAttribute(Qt::WA_DeleteOnClose);
                        cR=16;
                        cC=16;
                    }
                    else {
                        cR++;
                        dy += 25;
                        Dy += 25;
                    }
                }
                cC=17;

            }
            else{
                cC++;
                dx += 55;
                Dx += 55;
            }
        }
        if(cC==15 or cR== 15){
            newIcon->move(75,450);
            newIcon->show();
            newIcon->setAttribute(Qt::WA_DeleteOnClose);
        }

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

//! [1]
void DragWidget::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
//! [3]

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}

void DragWidget::on_ret_clicked(){
    QLabel *current = this->ficha;
    this->matriz->removeCellWidget(this->ficha->x(),this->ficha->y());
    current->move(0, 0);
    current->show();
    current->setAttribute(Qt::WA_DeleteOnClose);
    cout << "xd" << endl;
}
