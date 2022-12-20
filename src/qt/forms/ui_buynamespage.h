/********************************************************************************
** Form generated from reading UI file 'buynamespage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYNAMESPAGE_H
#define UI_BUYNAMESPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qt/qvalidatedlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_BuyNamesPage
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QValidatedLineEdit *registerName;
    QLabel *label;
    QLabel *statusLabel;
    QPushButton *registerNameButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *BuyNamesPage)
    {
        if (BuyNamesPage->objectName().isEmpty())
            BuyNamesPage->setObjectName(QString::fromUtf8("BuyNamesPage"));
        BuyNamesPage->resize(776, 364);
        horizontalLayout = new QHBoxLayout(BuyNamesPage);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame2 = new QFrame(BuyNamesPage);
        frame2->setObjectName(QString::fromUtf8("frame2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame2->sizePolicy().hasHeightForWidth());
        frame2->setSizePolicy(sizePolicy);
        frame2->setFrameShape(QFrame::StyledPanel);
        frame2->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(frame2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(frame2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_4);

        registerName = new QValidatedLineEdit(frame2);
        registerName->setObjectName(QString::fromUtf8("registerName"));

        verticalLayout->addWidget(registerName);

        label = new QLabel(frame2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(true);
        label->setOpenExternalLinks(true);

        verticalLayout->addWidget(label);

        statusLabel = new QLabel(frame2);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        sizePolicy2.setHeightForWidth(statusLabel->sizePolicy().hasHeightForWidth());
        statusLabel->setSizePolicy(sizePolicy2);
        statusLabel->setTextFormat(Qt::PlainText);
        statusLabel->setWordWrap(true);

        verticalLayout->addWidget(statusLabel);

        registerNameButton = new QPushButton(frame2);
        registerNameButton->setObjectName(QString::fromUtf8("registerNameButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(registerNameButton->sizePolicy().hasHeightForWidth());
        registerNameButton->setSizePolicy(sizePolicy3);
        registerNameButton->setMinimumSize(QSize(150, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/send"), QSize(), QIcon::Normal, QIcon::Off);
        registerNameButton->setIcon(icon);

        verticalLayout->addWidget(registerNameButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(frame2);

#if QT_CONFIG(shortcut)
        label_4->setBuddy(registerName);
#endif // QT_CONFIG(shortcut)

        retranslateUi(BuyNamesPage);

        registerNameButton->setDefault(true);


        QMetaObject::connectSlotsByName(BuyNamesPage);
    } // setupUi

    void retranslateUi(QWidget *BuyNamesPage)
    {
        label_4->setText(QCoreApplication::translate("BuyNamesPage", "&New name:", nullptr));
#if QT_CONFIG(tooltip)
        registerName->setToolTip(QCoreApplication::translate("BuyNamesPage", "Enter a name to register it.", nullptr));
#endif // QT_CONFIG(tooltip)
        registerName->setText(QCoreApplication::translate("BuyNamesPage", "p/", nullptr));
        label->setText(QCoreApplication::translate("BuyNamesPage", "Use <strong>p/</strong> prefix for user accounts, e.g. <strong>p/myname</strong>. Other prefixes can be used for miscellaneous purposes.</p>", nullptr));
        statusLabel->setText(QString());
#if QT_CONFIG(tooltip)
        registerNameButton->setToolTip(QCoreApplication::translate("BuyNamesPage", "Register the name.", nullptr));
#endif // QT_CONFIG(tooltip)
        registerNameButton->setText(QCoreApplication::translate("BuyNamesPage", "&Register Name\342\200\246", nullptr));
        (void)BuyNamesPage;
    } // retranslateUi

};

namespace Ui {
    class BuyNamesPage: public Ui_BuyNamesPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYNAMESPAGE_H
