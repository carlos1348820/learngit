/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <smallwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_15;
    QPushButton *pushButton_10;
    QPushButton *pushButton_14;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_11;
    QPushButton *pushButton_16;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QWidget *page_5;
    QToolBox *toolBox;
    QWidget *page;
    QPushButton *pushButton_17;
    QWidget *page_2;
    QToolButton *toolButton;
    QWidget *page_3;
    QRadioButton *radioButton;
    QWidget *page_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QPushButton *scrollArea_push;
    QPushButton *toolBoxPush;
    QPushButton *tabWidgetPush;
    QComboBox *comboBox;
    QPushButton *pushButtonBox;
    QLabel *label;
    smallWidget *widget;
    QPushButton *get;
    QPushButton *half;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 20, 371, 371));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        scrollArea = new QScrollArea(page_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(120, 50, 117, 332));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 115, 575));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_15 = new QPushButton(scrollAreaWidgetContents);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        verticalLayout->addWidget(pushButton_15);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);

        pushButton_14 = new QPushButton(scrollAreaWidgetContents);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        verticalLayout->addWidget(pushButton_14);

        pushButton_12 = new QPushButton(scrollAreaWidgetContents);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        verticalLayout->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(scrollAreaWidgetContents);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        verticalLayout->addWidget(pushButton_13);

        pushButton_11 = new QPushButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        verticalLayout->addWidget(pushButton_11);

        pushButton_16 = new QPushButton(scrollAreaWidgetContents);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        verticalLayout->addWidget(pushButton_16);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        toolBox = new QToolBox(page_5);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(90, 50, 101, 301));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 101, 211));
        pushButton_17 = new QPushButton(page);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(0, 60, 93, 28));
        toolBox->addItem(page, QString::fromUtf8("home"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 101, 211));
        toolButton = new QToolButton(page_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(20, 40, 47, 21));
        toolBox->addItem(page_2, QString::fromUtf8("friend"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 101, 211));
        radioButton = new QRadioButton(page_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(-10, 60, 115, 19));
        toolBox->addItem(page_3, QString::fromUtf8("black"));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        tabWidget = new QTabWidget(page_6);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 70, 311, 271));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        stackedWidget->addWidget(page_6);
        scrollArea_push = new QPushButton(Widget);
        scrollArea_push->setObjectName(QString::fromUtf8("scrollArea_push"));
        scrollArea_push->setGeometry(QRect(460, 120, 93, 28));
        toolBoxPush = new QPushButton(Widget);
        toolBoxPush->setObjectName(QString::fromUtf8("toolBoxPush"));
        toolBoxPush->setGeometry(QRect(460, 190, 93, 28));
        tabWidgetPush = new QPushButton(Widget);
        tabWidgetPush->setObjectName(QString::fromUtf8("tabWidgetPush"));
        tabWidgetPush->setGeometry(QRect(460, 260, 93, 28));
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(470, 390, 87, 22));
        pushButtonBox = new QPushButton(Widget);
        pushButtonBox->setObjectName(QString::fromUtf8("pushButtonBox"));
        pushButtonBox->setGeometry(QRect(470, 440, 93, 28));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 390, 231, 161));
        widget = new smallWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(400, 480, 221, 41));
        get = new QPushButton(Widget);
        get->setObjectName(QString::fromUtf8("get"));
        get->setGeometry(QRect(420, 550, 93, 28));
        half = new QPushButton(Widget);
        half->setObjectName(QString::fromUtf8("half"));
        half->setGeometry(QRect(570, 550, 93, 28));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_15->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_16->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_17->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Widget", "home", nullptr));
        toolButton->setText(QCoreApplication::translate("Widget", "...", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("Widget", "friend", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "RadioButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("Widget", "black", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "google", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "baidu", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Widget", "another", nullptr));
        scrollArea_push->setText(QCoreApplication::translate("Widget", "scrollArea", nullptr));
        toolBoxPush->setText(QCoreApplication::translate("Widget", "toolBox", nullptr));
        tabWidgetPush->setText(QCoreApplication::translate("Widget", "tabWidget", nullptr));
        pushButtonBox->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        get->setText(QCoreApplication::translate("Widget", " get", nullptr));
        half->setText(QCoreApplication::translate("Widget", "half", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
