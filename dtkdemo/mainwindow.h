#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <DLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    DTK_WIDGET_NAMESPACE::DLineEdit *m_dLineEdit;
    DTK_WIDGET_NAMESPACE::DLineEdit *m_dLineEdit2;

};

#endif // MAINWINDOW_H
