/********************************************************************************
** Form generated from reading UI file 'configurenamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURENAMEDIALOG_H
#define UI_CONFIGURENAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "qt/qvalidatedlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_ConfigureNameDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *labelName;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QLabel *labelTransferTo;
    QHBoxLayout *transferToLayout;
    QValidatedLineEdit *transferTo;
    QToolButton *addressBookButton;
    QToolButton *pasteButton;
    QLabel *labelTransferToHint;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *dataEdit;
    QLabel *labelSubmitHint;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigureNameDialog)
    {
        if (ConfigureNameDialog->objectName().isEmpty())
            ConfigureNameDialog->setObjectName(QString::fromUtf8("ConfigureNameDialog"));
        ConfigureNameDialog->resize(545, 304);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConfigureNameDialog->sizePolicy().hasHeightForWidth());
        ConfigureNameDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ConfigureNameDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(ConfigureNameDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        labelName = new QLabel(ConfigureNameDialog);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setText(QString::fromUtf8("TextLabel"));
        labelName->setTextFormat(Qt::PlainText);

        formLayout->setWidget(1, QFormLayout::FieldRole, labelName);

        verticalSpacer_2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer_2);

        label = new QLabel(ConfigureNameDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        label_4 = new QLabel(ConfigureNameDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setOpenExternalLinks(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, label_4);

        verticalSpacer = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(6, QFormLayout::FieldRole, verticalSpacer);

        labelTransferTo = new QLabel(ConfigureNameDialog);
        labelTransferTo->setObjectName(QString::fromUtf8("labelTransferTo"));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelTransferTo);

        transferToLayout = new QHBoxLayout();
        transferToLayout->setSpacing(0);
        transferToLayout->setObjectName(QString::fromUtf8("transferToLayout"));
        transferToLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        transferTo = new QValidatedLineEdit(ConfigureNameDialog);
        transferTo->setObjectName(QString::fromUtf8("transferTo"));

        transferToLayout->addWidget(transferTo);

        addressBookButton = new QToolButton(ConfigureNameDialog);
        addressBookButton->setObjectName(QString::fromUtf8("addressBookButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/address-book"), QSize(), QIcon::Normal, QIcon::Off);
        addressBookButton->setIcon(icon);

        transferToLayout->addWidget(addressBookButton);

        pasteButton = new QToolButton(ConfigureNameDialog);
        pasteButton->setObjectName(QString::fromUtf8("pasteButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/editpaste"), QSize(), QIcon::Normal, QIcon::Off);
        pasteButton->setIcon(icon1);

        transferToLayout->addWidget(pasteButton);


        formLayout->setLayout(7, QFormLayout::FieldRole, transferToLayout);

        labelTransferToHint = new QLabel(ConfigureNameDialog);
        labelTransferToHint->setObjectName(QString::fromUtf8("labelTransferToHint"));

        formLayout->setWidget(8, QFormLayout::FieldRole, labelTransferToHint);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dataEdit = new QLineEdit(ConfigureNameDialog);
        dataEdit->setObjectName(QString::fromUtf8("dataEdit"));
        dataEdit->setMaxLength(2048);

        horizontalLayout_3->addWidget(dataEdit);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_3);


        verticalLayout->addLayout(formLayout);

        labelSubmitHint = new QLabel(ConfigureNameDialog);
        labelSubmitHint->setObjectName(QString::fromUtf8("labelSubmitHint"));
        labelSubmitHint->setText(QString::fromUtf8("TextLabel"));
        labelSubmitHint->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSubmitHint->setMargin(10);
        labelSubmitHint->setIndent(10);

        verticalLayout->addWidget(labelSubmitHint);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(ConfigureNameDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);

#if QT_CONFIG(shortcut)
        label_2->setBuddy(dataEdit);
        label->setBuddy(dataEdit);
        labelTransferTo->setBuddy(transferTo);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ConfigureNameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigureNameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigureNameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigureNameDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigureNameDialog)
    {
        ConfigureNameDialog->setWindowTitle(QCoreApplication::translate("ConfigureNameDialog", "Configure Name", nullptr));
        label_2->setText(QCoreApplication::translate("ConfigureNameDialog", "Name:", nullptr));
        label->setText(QCoreApplication::translate("ConfigureNameDialog", "&Data:", nullptr));
        label_4->setText(QCoreApplication::translate("ConfigureNameDialog", "JSON string, e.g. {&quot;ip&quot;: [&quot;1.2.3.4&quot;, &quot;1.2.3.5&quot;]}<br>See <a href=\"https://github.com/namecoin/proposals\">JSON value specifications</a>.", nullptr));
        labelTransferTo->setText(QCoreApplication::translate("ConfigureNameDialog", "&Transfer to:", nullptr));
#if QT_CONFIG(tooltip)
        transferTo->setToolTip(QCoreApplication::translate("ConfigureNameDialog", "The address to transfer the name to.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        addressBookButton->setToolTip(QCoreApplication::translate("ConfigureNameDialog", "Choose address from address book", nullptr));
#endif // QT_CONFIG(tooltip)
        addressBookButton->setText(QString());
#if QT_CONFIG(shortcut)
        addressBookButton->setShortcut(QCoreApplication::translate("ConfigureNameDialog", "Alt+A", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pasteButton->setToolTip(QCoreApplication::translate("ConfigureNameDialog", "Paste address from clipboard", nullptr));
#endif // QT_CONFIG(tooltip)
        pasteButton->setText(QString());
#if QT_CONFIG(shortcut)
        pasteButton->setShortcut(QCoreApplication::translate("ConfigureNameDialog", "Alt+P", nullptr));
#endif // QT_CONFIG(shortcut)
        labelTransferToHint->setText(QCoreApplication::translate("ConfigureNameDialog", "(Leave empty if not transferring.)", nullptr));
#if QT_CONFIG(tooltip)
        dataEdit->setToolTip(QCoreApplication::translate("ConfigureNameDialog", "Enter JSON string that will be associated with the name", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class ConfigureNameDialog: public Ui_ConfigureNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURENAMEDIALOG_H
