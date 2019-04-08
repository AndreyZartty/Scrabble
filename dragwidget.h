#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>
#include <QTableWidget>
#include <QPushButton>
#include <QObject>
#include <QLabel>
#include <iostream>
#include "serverHelper.h"

using namespace std;

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

//! [0]
class DragWidget : public QFrame
{
    Q_OBJECT
public:
    explicit DragWidget(QWidget *parent = nullptr);
    void setLabels(string _j1, string _j2, string _j3, string _j4);
    int sendJsonPasar(), checkTurno();
    void setServHelp(serverHelper _sH);
    serverHelper getServHelp();
    int sendJsonScrabble();
private:
    QTableWidget *matriz;
    QPushButton* ret, *pushButton, *pushButton_2;
    QLabel* ficha;
    int Col, Row;
    QLabel *label, *lbl_J1, *lbl_J2, *lbl_J3, *lbl_J4, *lbl_p1, *lbl_p2, *lbl_p3, *lbl_p4;
    serverHelper sH;

protected:
    void on_pushButton_clicked();
    void on_label_linkHovered(const QString &link);
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_ret_clicked();
    void on_pushButton_2_clicked();
};
//! [0]

#endif // DRAGWIDGET_H
