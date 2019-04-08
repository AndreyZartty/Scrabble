#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>
#include <QTableWidget>
#include <QPushButton>
#include <QObject>
#include <QLabel>

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
private:
    QTableWidget *matriz;
    QPushButton* ret;
    QLabel* ficha;

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
