#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>
#include <QTableWidget>
#include <QPushButton>
#include <QObject>
#include <QLabel>
#include <iostream>

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
private:
    QTableWidget *matriz;
    QPushButton* ret;
    QLabel* ficha;
    int Col, Row;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_ret_clicked();
};
//! [0]

#endif // DRAGWIDGET_H
