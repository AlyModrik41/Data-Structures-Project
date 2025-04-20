#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QObject>       // Optional, since most widgets inherit from QObject
#include <QLineEdit>     // Required for QLineEdit
#include <QLabel>        // If you're using QLabel
#include <QDebug>        // If you're printing with qDebug
#include <QPushButton>
#include "properties.h"
#include <QMessageBox>
#include<set>
#include"properties.h"
#include "admin.h"

int main1324(int argc, char *argv[]) {
    QApplication app(argc, argv);
    multiset<properties,CompareByPrice> property_set;

    QWidget * mainWindow=new QWidget();
    mainWindow->setWindowTitle("Main Window");
    mainWindow->resize(300, 200);

    //adding button (goes to admin adding function)
    QPushButton *addBtn = new QPushButton("Add property");
    addBtn->setFixedSize(100,40);

    //property list layout
    QVBoxLayout* propertyListLayout = new QVBoxLayout();


    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(addBtn);
    mainLayout->addLayout(propertyListLayout);

    mainWindow->setLayout(mainLayout);



    QObject::connect(addBtn, &QPushButton::clicked, [&]() {
     mainWindow->hide();
    admin::add_prop(&property_set,mainWindow);
});

    for (const auto& p : property_set) {
        QString text = QString("🏢 %1 | 💵 %2 | 📍 %3")
                           .arg(QString::fromStdString(p.get_owner()))
                           .arg(p.get_price())
                           .arg(QString::fromStdString(p.get_location()));

        QLabel* propertyLabel = new QLabel(text);
        propertyListLayout->addWidget(propertyLabel);
    }
    mainWindow->show();
    return QApplication::exec();
}

