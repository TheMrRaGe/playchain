/********************************************************************************
** Form generated from reading UI file 'modaloverlay.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODALOVERLAY_H
#define UI_MODALOVERLAY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModalOverlay
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *bgWidget;
    QVBoxLayout *verticalLayoutMain;
    QWidget *contentWidget;
    QVBoxLayout *verticalLayoutSub;
    QHBoxLayout *horizontalLayoutIconText;
    QVBoxLayout *verticalLayoutIcon;
    QPushButton *warningIcon;
    QSpacerItem *verticalSpacerWarningIcon;
    QVBoxLayout *verticalLayoutInfoText;
    QLabel *infoText;
    QLabel *infoTextStrong;
    QSpacerItem *verticalSpacerInTextSpace;
    QSpacerItem *verticalSpacerAfterText;
    QFormLayout *formLayout;
    QLabel *labelNumberOfBlocksLeft;
    QLabel *numberOfBlocksLeft;
    QLabel *labelLastBlockTime;
    QLabel *newestBlockDate;
    QLabel *labelSyncDone;
    QHBoxLayout *horizontalLayoutSync;
    QLabel *percentageProgress;
    QLabel *labelProgressIncrease;
    QLabel *progressIncreasePerH;
    QLabel *labelEstimatedTimeLeft;
    QLabel *expectedTimeLeft;
    QHBoxLayout *horizontalLayoutButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QWidget *ModalOverlay)
    {
        if (ModalOverlay->objectName().isEmpty())
            ModalOverlay->setObjectName(QString::fromUtf8("ModalOverlay"));
        ModalOverlay->resize(640, 385);
        verticalLayout = new QVBoxLayout(ModalOverlay);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bgWidget = new QWidget(ModalOverlay);
        bgWidget->setObjectName(QString::fromUtf8("bgWidget"));
        bgWidget->setStyleSheet(QString::fromUtf8("#bgWidget { background: rgba(0,0,0,220); }"));
        verticalLayoutMain = new QVBoxLayout(bgWidget);
        verticalLayoutMain->setObjectName(QString::fromUtf8("verticalLayoutMain"));
        verticalLayoutMain->setContentsMargins(60, 60, 60, 60);
        contentWidget = new QWidget(bgWidget);
        contentWidget->setObjectName(QString::fromUtf8("contentWidget"));
        contentWidget->setStyleSheet(QString::fromUtf8("#contentWidget { background: rgba(255,255,255,240); border-radius: 6px; }\n"
"\n"
"QLabel { color: rgb(40,40,40);  }"));
        verticalLayoutSub = new QVBoxLayout(contentWidget);
        verticalLayoutSub->setSpacing(0);
        verticalLayoutSub->setObjectName(QString::fromUtf8("verticalLayoutSub"));
        verticalLayoutSub->setContentsMargins(10, 10, 10, 10);
        horizontalLayoutIconText = new QHBoxLayout();
        horizontalLayoutIconText->setObjectName(QString::fromUtf8("horizontalLayoutIconText"));
        horizontalLayoutIconText->setContentsMargins(-1, 20, -1, -1);
        verticalLayoutIcon = new QVBoxLayout();
        verticalLayoutIcon->setObjectName(QString::fromUtf8("verticalLayoutIcon"));
        verticalLayoutIcon->setContentsMargins(0, -1, -1, -1);
        warningIcon = new QPushButton(contentWidget);
        warningIcon->setObjectName(QString::fromUtf8("warningIcon"));
        warningIcon->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/warning"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icons/warning"), QSize(), QIcon::Disabled, QIcon::Off);
        warningIcon->setIcon(icon);
        warningIcon->setIconSize(QSize(48, 48));
        warningIcon->setFlat(true);

        verticalLayoutIcon->addWidget(warningIcon);

        verticalSpacerWarningIcon = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutIcon->addItem(verticalSpacerWarningIcon);


        horizontalLayoutIconText->addLayout(verticalLayoutIcon);

        verticalLayoutInfoText = new QVBoxLayout();
        verticalLayoutInfoText->setObjectName(QString::fromUtf8("verticalLayoutInfoText"));
        verticalLayoutInfoText->setContentsMargins(0, 0, -1, -1);
        infoText = new QLabel(contentWidget);
        infoText->setObjectName(QString::fromUtf8("infoText"));
        infoText->setTextFormat(Qt::RichText);
        infoText->setWordWrap(true);

        verticalLayoutInfoText->addWidget(infoText);

        infoTextStrong = new QLabel(contentWidget);
        infoTextStrong->setObjectName(QString::fromUtf8("infoTextStrong"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        infoTextStrong->setFont(font);
        infoTextStrong->setTextFormat(Qt::RichText);
        infoTextStrong->setWordWrap(true);

        verticalLayoutInfoText->addWidget(infoTextStrong);

        verticalSpacerInTextSpace = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutInfoText->addItem(verticalSpacerInTextSpace);


        horizontalLayoutIconText->addLayout(verticalLayoutInfoText);

        horizontalLayoutIconText->setStretch(1, 1);

        verticalLayoutSub->addLayout(horizontalLayoutIconText);

        verticalSpacerAfterText = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutSub->addItem(verticalSpacerAfterText);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(6);
        formLayout->setContentsMargins(-1, 10, -1, -1);
        labelNumberOfBlocksLeft = new QLabel(contentWidget);
        labelNumberOfBlocksLeft->setObjectName(QString::fromUtf8("labelNumberOfBlocksLeft"));
        labelNumberOfBlocksLeft->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNumberOfBlocksLeft);

        numberOfBlocksLeft = new QLabel(contentWidget);
        numberOfBlocksLeft->setObjectName(QString::fromUtf8("numberOfBlocksLeft"));

        formLayout->setWidget(0, QFormLayout::FieldRole, numberOfBlocksLeft);

        labelLastBlockTime = new QLabel(contentWidget);
        labelLastBlockTime->setObjectName(QString::fromUtf8("labelLastBlockTime"));
        labelLastBlockTime->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelLastBlockTime);

        newestBlockDate = new QLabel(contentWidget);
        newestBlockDate->setObjectName(QString::fromUtf8("newestBlockDate"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newestBlockDate->sizePolicy().hasHeightForWidth());
        newestBlockDate->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, newestBlockDate);

        labelSyncDone = new QLabel(contentWidget);
        labelSyncDone->setObjectName(QString::fromUtf8("labelSyncDone"));
        labelSyncDone->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelSyncDone);

        horizontalLayoutSync = new QHBoxLayout();
        horizontalLayoutSync->setObjectName(QString::fromUtf8("horizontalLayoutSync"));
        percentageProgress = new QLabel(contentWidget);
        percentageProgress->setObjectName(QString::fromUtf8("percentageProgress"));
        percentageProgress->setText(QString::fromUtf8("~"));

        horizontalLayoutSync->addWidget(percentageProgress);

        horizontalLayoutSync->setStretch(1, 1);

        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayoutSync);

        labelProgressIncrease = new QLabel(contentWidget);
        labelProgressIncrease->setObjectName(QString::fromUtf8("labelProgressIncrease"));
        labelProgressIncrease->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelProgressIncrease);

        progressIncreasePerH = new QLabel(contentWidget);
        progressIncreasePerH->setObjectName(QString::fromUtf8("progressIncreasePerH"));

        formLayout->setWidget(4, QFormLayout::FieldRole, progressIncreasePerH);

        labelEstimatedTimeLeft = new QLabel(contentWidget);
        labelEstimatedTimeLeft->setObjectName(QString::fromUtf8("labelEstimatedTimeLeft"));
        labelEstimatedTimeLeft->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, labelEstimatedTimeLeft);

        expectedTimeLeft = new QLabel(contentWidget);
        expectedTimeLeft->setObjectName(QString::fromUtf8("expectedTimeLeft"));

        formLayout->setWidget(5, QFormLayout::FieldRole, expectedTimeLeft);


        verticalLayoutSub->addLayout(formLayout);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName(QString::fromUtf8("horizontalLayoutButtons"));
        horizontalLayoutButtons->setContentsMargins(10, 10, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutButtons->addItem(horizontalSpacer);

        closeButton = new QPushButton(contentWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setFocusPolicy(Qt::StrongFocus);

        horizontalLayoutButtons->addWidget(closeButton);


        verticalLayoutSub->addLayout(horizontalLayoutButtons);

        verticalLayoutSub->setStretch(0, 1);

        verticalLayoutMain->addWidget(contentWidget);

        verticalLayoutMain->setStretch(0, 1);

        verticalLayout->addWidget(bgWidget);


        retranslateUi(ModalOverlay);

        closeButton->setDefault(true);


        QMetaObject::connectSlotsByName(ModalOverlay);
    } // setupUi

    void retranslateUi(QWidget *ModalOverlay)
    {
        ModalOverlay->setWindowTitle(QCoreApplication::translate("ModalOverlay", "Form", nullptr));
        warningIcon->setText(QString());
        infoText->setText(QCoreApplication::translate("ModalOverlay", "Recent transactions may not yet be visible; therefore your wallet's balance and name inventory might be incorrect, and name lookups are disabled. This information will be correct, and name lookups will be enabled, once your wallet has finished synchronizing with the PLAYCHAIN network, as detailed below.", nullptr));
        infoTextStrong->setText(QCoreApplication::translate("ModalOverlay", "Attempting to spend BITS or update names that are affected by not-yet-displayed transactions will not be accepted by the network.", nullptr));
        labelNumberOfBlocksLeft->setText(QCoreApplication::translate("ModalOverlay", "Number of blocks left", nullptr));
        numberOfBlocksLeft->setText(QCoreApplication::translate("ModalOverlay", "Unknown\342\200\246", nullptr));
        labelLastBlockTime->setText(QCoreApplication::translate("ModalOverlay", "Last block time", nullptr));
        newestBlockDate->setText(QCoreApplication::translate("ModalOverlay", "Unknown\342\200\246", nullptr));
        labelSyncDone->setText(QCoreApplication::translate("ModalOverlay", "Progress", nullptr));
        labelProgressIncrease->setText(QCoreApplication::translate("ModalOverlay", "Progress increase per hour", nullptr));
        progressIncreasePerH->setText(QCoreApplication::translate("ModalOverlay", "calculating\342\200\246", nullptr));
        labelEstimatedTimeLeft->setText(QCoreApplication::translate("ModalOverlay", "Estimated time left until synced", nullptr));
        expectedTimeLeft->setText(QCoreApplication::translate("ModalOverlay", "calculating\342\200\246", nullptr));
        closeButton->setText(QCoreApplication::translate("ModalOverlay", "Hide", nullptr));
#if QT_CONFIG(shortcut)
        closeButton->setShortcut(QCoreApplication::translate("ModalOverlay", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class ModalOverlay: public Ui_ModalOverlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODALOVERLAY_H
