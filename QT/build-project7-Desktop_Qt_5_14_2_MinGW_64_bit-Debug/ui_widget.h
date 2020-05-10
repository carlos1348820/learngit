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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButtonNO;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(831, 617);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 120, 93, 28));
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(110, 260, 91, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/OnePiece.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(90, 170, 75, 84));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButtonNO = new QRadioButton(groupBox);
        radioButtonNO->setObjectName(QString::fromUtf8("radioButtonNO"));

        verticalLayout->addWidget(radioButtonNO);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(180, 180, 59, 84));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        verticalLayout_2->addWidget(radioButton_4);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(120, 330, 115, 110));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout_3->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_3->addWidget(checkBox_2);

        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setTristate(true);

        verticalLayout_3->addWidget(checkBox);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(470, 150, 256, 192));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        toolButton->setText(QCoreApplication::translate("Widget", "sytel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "yes", nullptr));
        radioButtonNO->setText(QCoreApplication::translate("Widget", "no", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "y", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Widget", "n", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Widget", "CheckBox", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "CheckBox", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
