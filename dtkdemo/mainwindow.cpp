#include "mainwindow.h"

#include <QDebug>
#include <QRegExpValidator>

DWIDGET_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_dLineEdit(new DLineEdit(this))
    , m_dLineEdit2(new DLineEdit(this))
{
    m_dLineEdit->lineEdit()->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z][a-zA-Z0-9-_]{1,32}$"), this));
    m_dLineEdit->lineEdit()->setAttribute(Qt::WA_InputMethodEnabled, false);
    connect(m_dLineEdit->lineEdit(), &QLineEdit::editingFinished, this, [this](){
        qInfo() << "0000000000";
        m_dLineEdit2->setFocus();
    });
    connect(m_dLineEdit->lineEdit(), &QLineEdit::textChanged, this, [this](){
        m_dLineEdit->setAlert(true);
    });


    QWidget *widget = new QWidget(this);
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_dLineEdit);
    hLayout->addWidget(m_dLineEdit2);

    this->setCentralWidget(widget);
    centralWidget()->setLayout(hLayout);
}

MainWindow::~MainWindow()
{

}
