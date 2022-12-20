/********************************************************************************
** Form generated from reading UI file 'receivecoinsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVECOINSDIALOG_H
#define UI_RECEIVECOINSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include "qt/bitcoinamountfield.h"

QT_BEGIN_NAMESPACE

class Ui_ReceiveCoinsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *reqLabel;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *reqMessage;
    QHBoxLayout *horizontalLayout;
    QPushButton *receiveButton;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_6;
    BitcoinAmountField *reqAmount;
    QComboBox *addressType;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QTableView *recentRequestsView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *showRequestButton;
    QPushButton *removeRequestButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ReceiveCoinsDialog)
    {
        if (ReceiveCoinsDialog->objectName().isEmpty())
            ReceiveCoinsDialog->setObjectName(QString::fromUtf8("ReceiveCoinsDialog"));
        ReceiveCoinsDialog->resize(776, 396);
        verticalLayout = new QVBoxLayout(ReceiveCoinsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame2 = new QFrame(ReceiveCoinsDialog);
        frame2->setObjectName(QString::fromUtf8("frame2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame2->sizePolicy().hasHeightForWidth());
        frame2->setSizePolicy(sizePolicy);
        frame2->setFrameShape(QFrame::StyledPanel);
        frame2->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(frame2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 5, 0, 1, 1);

        label_3 = new QLabel(frame2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        reqLabel = new QLineEdit(frame2);
        reqLabel->setObjectName(QString::fromUtf8("reqLabel"));

        gridLayout->addWidget(reqLabel, 4, 2, 1, 1);

        label_5 = new QLabel(frame2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        label_2 = new QLabel(frame2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        reqMessage = new QLineEdit(frame2);
        reqMessage->setObjectName(QString::fromUtf8("reqMessage"));

        gridLayout->addWidget(reqMessage, 6, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        receiveButton = new QPushButton(frame2);
        receiveButton->setObjectName(QString::fromUtf8("receiveButton"));
        receiveButton->setMinimumSize(QSize(150, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/receiving_addresses"), QSize(), QIcon::Normal, QIcon::Off);
        receiveButton->setIcon(icon);
        receiveButton->setAutoDefault(false);

        horizontalLayout->addWidget(receiveButton);

        clearButton = new QPushButton(frame2);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/remove"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon1);
        clearButton->setAutoDefault(false);

        horizontalLayout->addWidget(clearButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 7, 2, 1, 1);

        label_7 = new QLabel(frame2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        reqAmount = new BitcoinAmountField(frame2);
        reqAmount->setObjectName(QString::fromUtf8("reqAmount"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(reqAmount->sizePolicy().hasHeightForWidth());
        reqAmount->setSizePolicy(sizePolicy2);
        reqAmount->setMinimumSize(QSize(80, 0));
        reqAmount->setMaximumSize(QSize(1000, 100));

        horizontalLayout_6->addWidget(reqAmount);

        addressType = new QComboBox(frame2);
        addressType->setObjectName(QString::fromUtf8("addressType"));
        sizePolicy2.setHeightForWidth(addressType->sizePolicy().hasHeightForWidth());
        addressType->setSizePolicy(sizePolicy2);
        addressType->setMaximumSize(QSize(1000, 16777215));
        addressType->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_6->addWidget(addressType);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_6, 5, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout->addWidget(frame2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        frame = new QFrame(ReceiveCoinsDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);

        recentRequestsView = new QTableView(frame);
        recentRequestsView->setObjectName(QString::fromUtf8("recentRequestsView"));
        recentRequestsView->setContextMenuPolicy(Qt::CustomContextMenu);
        recentRequestsView->setTabKeyNavigation(false);
        recentRequestsView->setSortingEnabled(true);

        verticalLayout_2->addWidget(recentRequestsView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        showRequestButton = new QPushButton(frame);
        showRequestButton->setObjectName(QString::fromUtf8("showRequestButton"));
        showRequestButton->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/eye"), QSize(), QIcon::Normal, QIcon::Off);
        showRequestButton->setIcon(icon2);
        showRequestButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(showRequestButton);

        removeRequestButton = new QPushButton(frame);
        removeRequestButton->setObjectName(QString::fromUtf8("removeRequestButton"));
        removeRequestButton->setEnabled(false);
        removeRequestButton->setIcon(icon1);
        removeRequestButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(removeRequestButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(frame);

        verticalLayout->setStretch(2, 1);
#if QT_CONFIG(shortcut)
        label->setBuddy(reqAmount);
        label_3->setBuddy(reqMessage);
        label_2->setBuddy(reqLabel);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(reqLabel, reqAmount);
        QWidget::setTabOrder(reqAmount, addressType);
        QWidget::setTabOrder(addressType, reqMessage);
        QWidget::setTabOrder(reqMessage, receiveButton);
        QWidget::setTabOrder(receiveButton, clearButton);
        QWidget::setTabOrder(clearButton, recentRequestsView);
        QWidget::setTabOrder(recentRequestsView, showRequestButton);
        QWidget::setTabOrder(showRequestButton, removeRequestButton);

        retranslateUi(ReceiveCoinsDialog);

        receiveButton->setDefault(true);


        QMetaObject::connectSlotsByName(ReceiveCoinsDialog);
    } // setupUi

    void retranslateUi(QDialog *ReceiveCoinsDialog)
    {
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("ReceiveCoinsDialog", "An optional amount to request. Leave this empty or zero to not request a specific amount.", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("ReceiveCoinsDialog", "&Amount:", nullptr));
#if QT_CONFIG(tooltip)
        label_3->setToolTip(QCoreApplication::translate("ReceiveCoinsDialog", "An optional message to attach to the payment request, which will be displayed when the request is opened. Note: The message will not be sent with the payment over the Bitcoin network.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("ReceiveCoinsDialog", "&Message:", nullptr));
#if QT_CONFIG(tooltip)
        reqLabel->setToolTip(QCoreApplication::translate("ReceiveCoinsDialog", "An optional label to associate with the new receiving address (used by you to identify an invoice).  It is also attached to the payment request.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("ReceiveCoinsDialog", "Use this form to request payments. All fields are <b>optional</b>.", nullptr));
#if QT_CONFIG(tooltip)
        label_2->setToolTip(QCoreApplication::translate("ReceiveCoinsDialog", "An optional label to associate with the new receiving address.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("ReceiveCoinsDialog", "&Label:", nullptr));
#if QT_CONFIG(tooltip)
        reqMessage->setToolTip(QCoreApplication::translate("ReceiveCoinsDialog", "An optional message that is attached to the payment request and may be displayed to the sender.", nullptr));
#endif // QT_CONFIG(tooltip)
        receiveButton->setText(QCoreApplication::translate("ReceiveCoinsDialog", "&Create new receiving address", nullptr));
#if QT_CONFIG(tooltip)
        clearButton->setToolTip(QCoreApplication::translate("ReceiveCoinsDialog", "Clear all fields of the form.", nullptr));
#endif // QT_CONFIG(tooltip)
        clearButton->setText(QCoreApplication::translate("ReceiveCoinsDialog", "Clear", nullptr));
        label_7->setText(QString());
#if QT_CONFIG(tooltip)
        reqAmount->setToolTip(QCoreApplication::translate("ReceiveCoinsDialog", "An optional amount to request. Leave this empty or zero to not request a specific amount.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("ReceiveCoinsDialog", "Requested payments history", nullptr));
#if QT_CONFIG(tooltip)
        showRequestButton->setToolTip(QCoreApplication::translate("ReceiveCoinsDialog", "Show the selected request (does the same as double clicking an entry)", nullptr));
#endif // QT_CONFIG(tooltip)
        showRequestButton->setText(QCoreApplication::translate("ReceiveCoinsDialog", "Show", nullptr));
#if QT_CONFIG(tooltip)
        removeRequestButton->setToolTip(QCoreApplication::translate("ReceiveCoinsDialog", "Remove the selected entries from the list", nullptr));
#endif // QT_CONFIG(tooltip)
        removeRequestButton->setText(QCoreApplication::translate("ReceiveCoinsDialog", "Remove", nullptr));
        (void)ReceiveCoinsDialog;
    } // retranslateUi

};

namespace Ui {
    class ReceiveCoinsDialog: public Ui_ReceiveCoinsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVECOINSDIALOG_H
