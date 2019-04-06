#ifndef PANTALLAUNIRSE_H
#define PANTALLAUNIRSE_H

#include <QWidget>

namespace Ui {
class pantallaunirse;
}

class pantallaunirse : public QWidget
{
    Q_OBJECT

public:
    explicit pantallaunirse(QWidget *parent = nullptr);
    ~pantallaunirse();

private slots:
    void on_UnirseButton_clicked();

private:
    Ui::pantallaunirse *ui;
    int SendJson();
};

#endif // PANTALLAUNIRSE_H
