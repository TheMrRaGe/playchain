/********************************************************************************
** Form generated from reading UI file 'managenamespage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGENAMESPAGE_H
#define UI_MANAGENAMESPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageNamesPage
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QLabel *countLabel;
    QSpacerItem *countConfigureSpacer;
    QPushButton *configureNameButton;
    QSpacerItem *configureRenewSpacer;
    QPushButton *renewNameButton;
    QSpacerItem *renewExportSpacer;
    QPushButton *exportButton;

    void setupUi(QWidget *ManageNamesPage)
    {
        if (ManageNamesPage->objectName().isEmpty())
            ManageNamesPage->setObjectName(QString::fromUtf8("ManageNamesPage"));
        ManageNamesPage->resize(776, 364);
        horizontalLayout = new QHBoxLayout(ManageNamesPage);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame2 = new QFrame(ManageNamesPage);
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
        label_5 = new QLabel(frame2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_5);

        tableView = new QTableView(frame2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setContextMenuPolicy(Qt::CustomContextMenu);
        tableView->setTabKeyNavigation(false);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        countLabel = new QLabel(frame2);
        countLabel->setObjectName(QString::fromUtf8("countLabel"));
        sizePolicy1.setHeightForWidth(countLabel->sizePolicy().hasHeightForWidth());
        countLabel->setSizePolicy(sizePolicy1);
        countLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(countLabel);

        countConfigureSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(countConfigureSpacer);

        configureNameButton = new QPushButton(frame2);
        configureNameButton->setObjectName(QString::fromUtf8("configureNameButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(configureNameButton->sizePolicy().hasHeightForWidth());
        configureNameButton->setSizePolicy(sizePolicy2);
        configureNameButton->setMinimumSize(QSize(150, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/edit"), QSize(), QIcon::Normal, QIcon::Off);
        configureNameButton->setIcon(icon);

        horizontalLayout_3->addWidget(configureNameButton);

        configureRenewSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(configureRenewSpacer);

        renewNameButton = new QPushButton(frame2);
        renewNameButton->setObjectName(QString::fromUtf8("renewNameButton"));
        sizePolicy2.setHeightForWidth(renewNameButton->sizePolicy().hasHeightForWidth());
        renewNameButton->setSizePolicy(sizePolicy2);
        renewNameButton->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(renewNameButton);

        renewExportSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(renewExportSpacer);

        exportButton = new QPushButton(frame2);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/export"), QSize(), QIcon::Normal, QIcon::Off);
        exportButton->setIcon(icon1);
        exportButton->setAutoDefault(false);

        horizontalLayout_3->addWidget(exportButton);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addWidget(frame2);


        retranslateUi(ManageNamesPage);

        configureNameButton->setDefault(false);
        renewNameButton->setDefault(false);


        QMetaObject::connectSlotsByName(ManageNamesPage);
    } // setupUi

    void retranslateUi(QWidget *ManageNamesPage)
    {
        label_5->setText(QCoreApplication::translate("ManageNamesPage", "Your registered names:", nullptr));
#if QT_CONFIG(tooltip)
        tableView->setToolTip(QCoreApplication::translate("ManageNamesPage", "Double-click name to configure", nullptr));
#endif // QT_CONFIG(tooltip)
        countLabel->setText(QString());
#if QT_CONFIG(tooltip)
        configureNameButton->setToolTip(QCoreApplication::translate("ManageNamesPage", "Configure name and submit update operation", nullptr));
#endif // QT_CONFIG(tooltip)
        configureNameButton->setText(QCoreApplication::translate("ManageNamesPage", "&Configure Name\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        renewNameButton->setToolTip(QCoreApplication::translate("ManageNamesPage", "Renew the names with their current values", nullptr));
#endif // QT_CONFIG(tooltip)
        renewNameButton->setText(QCoreApplication::translate("ManageNamesPage", "&Renew Names", nullptr));
#if QT_CONFIG(tooltip)
        exportButton->setToolTip(QCoreApplication::translate("ManageNamesPage", "Export the data in the current tab to a file", nullptr));
#endif // QT_CONFIG(tooltip)
        exportButton->setText(QCoreApplication::translate("ManageNamesPage", "&Export", nullptr));
        (void)ManageNamesPage;
    } // retranslateUi

};

namespace Ui {
    class ManageNamesPage: public Ui_ManageNamesPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGENAMESPAGE_H
