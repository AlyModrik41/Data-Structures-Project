//
// Created by BoOdy on 19/04/2025.
//

#include "admin.h"
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QObject>       // Optional, since most widgets inherit from QObject
#include <QLineEdit>     // Required for QLineEdit
#include <QLabel>        // If you're using QLabel
#include <QDebug>        // If you're printing with qDebug
#include <QPushButton>
#include "properties.h"
#include <QMessageBox>

admin::admin() {

}

admin::~admin() {
}

void admin::add_prop(multiset<properties, CompareByPrice> *property_set,QWidget* main) {
    QWidget *window = new QWidget();
    window->setWindowTitle("Adding page");
    window->resize(400, 300);

    //inputs fields and form
    QLineEdit *owner_input = new QLineEdit();
    owner_input->setPlaceholderText("Enter the company name");
    owner_input->setFixedSize(200, 30);

    QLineEdit *price_input = new QLineEdit();
    price_input->setPlaceholderText("Enter the property price");
    price_input->setFixedSize(200, 30);

    QLineEdit *location_input = new QLineEdit();
    location_input->setPlaceholderText("Enter the location");
    location_input->setFixedSize(200, 30);

    QPushButton *submitBtn = new QPushButton("Submit");
    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("Company name:", owner_input);
    formLayout->addRow("Property price:", price_input);
    formLayout->addRow("Property location:", location_input);
    formLayout->addWidget(submitBtn);  // Add the button to the layout
    window->setLayout(formLayout);


    //adding property

    QObject::connect(submitBtn,&QPushButton::clicked,[=]() {
      if (price_input->text().isEmpty()||owner_input->text().isEmpty()||location_input->text().isEmpty()) {
          QMessageBox::warning(nullptr, "Invalid Input", "Please enter all fields");
      }else {
          bool ok;
          int price=price_input->text().toInt(&ok);
          if (ok) {
              properties p;
              p.set_price(price);
              p.set_status(true);
              p.set_owner(owner_input->text().toStdString());
              p.set_location(location_input->text().toStdString());
              property_set->insert(p);
              QVBoxLayout* mainLayout = qobject_cast<QVBoxLayout*>(main->layout());
         if (mainLayout) {
             // Assume first widget is the button, so skip it
             for (int i = mainLayout->count() - 1; i >= 1; --i) {
                 QLayoutItem* item = mainLayout->takeAt(i);
                 if (item->widget()) item->widget()->deleteLater();
                 delete item;
             }

             for (const auto& prop : *property_set) {
                 QString info = QString("🏢Owner: %1 | 💵Price: %2$ | 📍Location: %3")
                     .arg(QString::fromStdString(prop.get_owner()))
                     .arg(prop.get_price())
                     .arg(QString::fromStdString(prop.get_location()));
                 QLabel* label = new QLabel(info);
                 mainLayout->addWidget(label);
             }
         }
              window->close();
              main->show();
          }else {
              QMessageBox::warning(nullptr, "Invalid Input", "Please enter valid number in price field");
          }
      }
    });
    window->show();

}

