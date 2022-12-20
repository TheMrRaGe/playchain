/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qt/qvalidatedlineedit.h"
#include "qt/qvaluecombobox.h"

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabMain;
    QVBoxLayout *verticalLayout_Main;
    QCheckBox *bitcoinAtStartup;
    QSpacerItem *horizontalSpacer_0_Main;
    QHBoxLayout *horizontalLayout_Main_Prune;
    QCheckBox *prune;
    QSpinBox *pruneSize;
    QLabel *pruneSizeUnitLabel;
    QSpacerItem *horizontalSpacer_Main_Prune;
    QLabel *pruneWarning;
    QHBoxLayout *horizontalLayout_2_Main;
    QLabel *databaseCacheLabel;
    QSpinBox *databaseCache;
    QLabel *databaseCacheUnitLabel;
    QSpacerItem *horizontalSpacer_2_Main;
    QHBoxLayout *horizontalLayout_Main_VerifyLabel;
    QLabel *threadsScriptVerifLabel;
    QSpinBox *threadsScriptVerif;
    QSpacerItem *horizontalSpacer_Main_Threads;
    QCheckBox *enableServer;
    QSpacerItem *verticalSpacer_Main;
    QWidget *tabWallet;
    QVBoxLayout *verticalLayout_Wallet;
    QCheckBox *subFeeFromAmount;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *coinControlFeatures;
    QCheckBox *spendZeroConfChange;
    QCheckBox *m_enable_psbt_controls;
    QGroupBox *groupBoxHww;
    QVBoxLayout *verticalLayoutHww;
    QHBoxLayout *horizontalLayoutHww;
    QLabel *externalSignerPathLabel;
    QLineEdit *externalSignerPath;
    QSpacerItem *verticalSpacer_Wallet;
    QWidget *tabNetwork;
    QVBoxLayout *verticalLayout_Network;
    QCheckBox *mapPortUpnp;
    QCheckBox *mapPortNatpmp;
    QCheckBox *allowIncoming;
    QCheckBox *connectSocks;
    QHBoxLayout *horizontalLayout_1_Network;
    QLabel *proxyIpLabel;
    QValidatedLineEdit *proxyIp;
    QLabel *proxyPortLabel;
    QLineEdit *proxyPort;
    QSpacerItem *horizontalSpacer_1_Network;
    QHBoxLayout *horizontalLayout_2_Network;
    QLabel *proxyActiveNets;
    QCheckBox *proxyReachIPv4;
    QLabel *proxyReachIPv4Label;
    QCheckBox *proxyReachIPv6;
    QLabel *proxyReachIPv6Label;
    QCheckBox *proxyReachTor;
    QLabel *proxyReachTorLabel;
    QSpacerItem *horizontalSpacer_2_Network;
    QCheckBox *connectSocksTor;
    QHBoxLayout *horizontalLayout_3_Network;
    QLabel *proxyIpTorLabel;
    QValidatedLineEdit *proxyIpTor;
    QLabel *proxyPortTorLabel;
    QLineEdit *proxyPortTor;
    QSpacerItem *horizontalSpacer_4_Network;
    QSpacerItem *verticalSpacer_Network;
    QWidget *tabWindow;
    QVBoxLayout *verticalLayout_Window;
    QCheckBox *showTrayIcon;
    QCheckBox *minimizeToTray;
    QCheckBox *minimizeOnClose;
    QSpacerItem *verticalSpacer_Window;
    QWidget *tabDisplay;
    QVBoxLayout *verticalLayout_Display;
    QHBoxLayout *horizontalLayout_1_Display;
    QLabel *langLabel;
    QValueComboBox *lang;
    QHBoxLayout *horizontalLayout_2_Display;
    QLabel *unitLabel;
    QValueComboBox *unit;
    QHBoxLayout *horizontalLayout_3_Display;
    QLabel *thirdPartyTxUrlsLabel;
    QLineEdit *thirdPartyTxUrls;
    QGroupBox *font_groupBox;
    QVBoxLayout *font_verticalLayout;
    QHBoxLayout *embeddedFont_horizontalLayout;
    QRadioButton *embeddedFont_radioButton;
    QSpacerItem *embeddedFont_horizontalSpacer;
    QVBoxLayout *embeddedFont_verticalLayout;
    QLabel *embeddedFont_label_1;
    QLabel *embeddedFont_label_9;
    QFrame *font_line;
    QHBoxLayout *systemFont_horizontalLayout;
    QRadioButton *systemFont_radioButton;
    QSpacerItem *systemFont_horizontalSpacer;
    QVBoxLayout *systemFont_verticalLayout;
    QLabel *systemFont_label_1;
    QLabel *systemFont_label_9;
    QSpacerItem *verticalSpacer_Display;
    QFrame *frame;
    QVBoxLayout *verticalLayout_Bottom;
    QHBoxLayout *horizontalLayout_Bottom;
    QLabel *overriddenByCommandLineInfoLabel;
    QSpacerItem *horizontalSpacer_Bottom;
    QLabel *overriddenByCommandLineLabel;
    QHBoxLayout *horizontalLayout_Buttons;
    QVBoxLayout *verticalLayout_Buttons;
    QPushButton *openBitcoinConfButton;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer_1;
    QLabel *statusLabel;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(560, 440);
        OptionsDialog->setModal(true);
        verticalLayout = new QVBoxLayout(OptionsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(OptionsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabMain = new QWidget();
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        verticalLayout_Main = new QVBoxLayout(tabMain);
        verticalLayout_Main->setObjectName(QString::fromUtf8("verticalLayout_Main"));
        bitcoinAtStartup = new QCheckBox(tabMain);
        bitcoinAtStartup->setObjectName(QString::fromUtf8("bitcoinAtStartup"));

        verticalLayout_Main->addWidget(bitcoinAtStartup);

        horizontalSpacer_0_Main = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_Main->addItem(horizontalSpacer_0_Main);

        horizontalLayout_Main_Prune = new QHBoxLayout();
        horizontalLayout_Main_Prune->setObjectName(QString::fromUtf8("horizontalLayout_Main_Prune"));
        prune = new QCheckBox(tabMain);
        prune->setObjectName(QString::fromUtf8("prune"));

        horizontalLayout_Main_Prune->addWidget(prune);

        pruneSize = new QSpinBox(tabMain);
        pruneSize->setObjectName(QString::fromUtf8("pruneSize"));

        horizontalLayout_Main_Prune->addWidget(pruneSize);

        pruneSizeUnitLabel = new QLabel(tabMain);
        pruneSizeUnitLabel->setObjectName(QString::fromUtf8("pruneSizeUnitLabel"));
        pruneSizeUnitLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_Main_Prune->addWidget(pruneSizeUnitLabel);

        horizontalSpacer_Main_Prune = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Main_Prune->addItem(horizontalSpacer_Main_Prune);


        verticalLayout_Main->addLayout(horizontalLayout_Main_Prune);

        pruneWarning = new QLabel(tabMain);
        pruneWarning->setObjectName(QString::fromUtf8("pruneWarning"));
        pruneWarning->setTextFormat(Qt::PlainText);

        verticalLayout_Main->addWidget(pruneWarning);

        horizontalLayout_2_Main = new QHBoxLayout();
        horizontalLayout_2_Main->setObjectName(QString::fromUtf8("horizontalLayout_2_Main"));
        databaseCacheLabel = new QLabel(tabMain);
        databaseCacheLabel->setObjectName(QString::fromUtf8("databaseCacheLabel"));
        databaseCacheLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Main->addWidget(databaseCacheLabel);

        databaseCache = new QSpinBox(tabMain);
        databaseCache->setObjectName(QString::fromUtf8("databaseCache"));

        horizontalLayout_2_Main->addWidget(databaseCache);

        databaseCacheUnitLabel = new QLabel(tabMain);
        databaseCacheUnitLabel->setObjectName(QString::fromUtf8("databaseCacheUnitLabel"));
        databaseCacheUnitLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Main->addWidget(databaseCacheUnitLabel);

        horizontalSpacer_2_Main = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2_Main->addItem(horizontalSpacer_2_Main);


        verticalLayout_Main->addLayout(horizontalLayout_2_Main);

        horizontalLayout_Main_VerifyLabel = new QHBoxLayout();
        horizontalLayout_Main_VerifyLabel->setObjectName(QString::fromUtf8("horizontalLayout_Main_VerifyLabel"));
        threadsScriptVerifLabel = new QLabel(tabMain);
        threadsScriptVerifLabel->setObjectName(QString::fromUtf8("threadsScriptVerifLabel"));
        threadsScriptVerifLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_Main_VerifyLabel->addWidget(threadsScriptVerifLabel);

        threadsScriptVerif = new QSpinBox(tabMain);
        threadsScriptVerif->setObjectName(QString::fromUtf8("threadsScriptVerif"));

        horizontalLayout_Main_VerifyLabel->addWidget(threadsScriptVerif);

        horizontalSpacer_Main_Threads = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Main_VerifyLabel->addItem(horizontalSpacer_Main_Threads);


        verticalLayout_Main->addLayout(horizontalLayout_Main_VerifyLabel);

        enableServer = new QCheckBox(tabMain);
        enableServer->setObjectName(QString::fromUtf8("enableServer"));

        verticalLayout_Main->addWidget(enableServer);

        verticalSpacer_Main = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Main->addItem(verticalSpacer_Main);

        tabWidget->addTab(tabMain, QString());
        tabWallet = new QWidget();
        tabWallet->setObjectName(QString::fromUtf8("tabWallet"));
        verticalLayout_Wallet = new QVBoxLayout(tabWallet);
        verticalLayout_Wallet->setObjectName(QString::fromUtf8("verticalLayout_Wallet"));
        subFeeFromAmount = new QCheckBox(tabWallet);
        subFeeFromAmount->setObjectName(QString::fromUtf8("subFeeFromAmount"));

        verticalLayout_Wallet->addWidget(subFeeFromAmount);

        groupBox = new QGroupBox(tabWallet);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        coinControlFeatures = new QCheckBox(groupBox);
        coinControlFeatures->setObjectName(QString::fromUtf8("coinControlFeatures"));

        verticalLayout_2->addWidget(coinControlFeatures);

        spendZeroConfChange = new QCheckBox(groupBox);
        spendZeroConfChange->setObjectName(QString::fromUtf8("spendZeroConfChange"));

        verticalLayout_2->addWidget(spendZeroConfChange);

        m_enable_psbt_controls = new QCheckBox(groupBox);
        m_enable_psbt_controls->setObjectName(QString::fromUtf8("m_enable_psbt_controls"));

        verticalLayout_2->addWidget(m_enable_psbt_controls);


        verticalLayout_Wallet->addWidget(groupBox);

        groupBoxHww = new QGroupBox(tabWallet);
        groupBoxHww->setObjectName(QString::fromUtf8("groupBoxHww"));
        verticalLayoutHww = new QVBoxLayout(groupBoxHww);
        verticalLayoutHww->setObjectName(QString::fromUtf8("verticalLayoutHww"));
        horizontalLayoutHww = new QHBoxLayout();
        horizontalLayoutHww->setObjectName(QString::fromUtf8("horizontalLayoutHww"));
        externalSignerPathLabel = new QLabel(groupBoxHww);
        externalSignerPathLabel->setObjectName(QString::fromUtf8("externalSignerPathLabel"));

        horizontalLayoutHww->addWidget(externalSignerPathLabel);

        externalSignerPath = new QLineEdit(groupBoxHww);
        externalSignerPath->setObjectName(QString::fromUtf8("externalSignerPath"));

        horizontalLayoutHww->addWidget(externalSignerPath);


        verticalLayoutHww->addLayout(horizontalLayoutHww);


        verticalLayout_Wallet->addWidget(groupBoxHww);

        verticalSpacer_Wallet = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Wallet->addItem(verticalSpacer_Wallet);

        tabWidget->addTab(tabWallet, QString());
        tabNetwork = new QWidget();
        tabNetwork->setObjectName(QString::fromUtf8("tabNetwork"));
        verticalLayout_Network = new QVBoxLayout(tabNetwork);
        verticalLayout_Network->setObjectName(QString::fromUtf8("verticalLayout_Network"));
        mapPortUpnp = new QCheckBox(tabNetwork);
        mapPortUpnp->setObjectName(QString::fromUtf8("mapPortUpnp"));

        verticalLayout_Network->addWidget(mapPortUpnp);

        mapPortNatpmp = new QCheckBox(tabNetwork);
        mapPortNatpmp->setObjectName(QString::fromUtf8("mapPortNatpmp"));

        verticalLayout_Network->addWidget(mapPortNatpmp);

        allowIncoming = new QCheckBox(tabNetwork);
        allowIncoming->setObjectName(QString::fromUtf8("allowIncoming"));

        verticalLayout_Network->addWidget(allowIncoming);

        connectSocks = new QCheckBox(tabNetwork);
        connectSocks->setObjectName(QString::fromUtf8("connectSocks"));

        verticalLayout_Network->addWidget(connectSocks);

        horizontalLayout_1_Network = new QHBoxLayout();
        horizontalLayout_1_Network->setObjectName(QString::fromUtf8("horizontalLayout_1_Network"));
        proxyIpLabel = new QLabel(tabNetwork);
        proxyIpLabel->setObjectName(QString::fromUtf8("proxyIpLabel"));
        proxyIpLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_1_Network->addWidget(proxyIpLabel);

        proxyIp = new QValidatedLineEdit(tabNetwork);
        proxyIp->setObjectName(QString::fromUtf8("proxyIp"));
        proxyIp->setMinimumSize(QSize(140, 0));
        proxyIp->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_1_Network->addWidget(proxyIp);

        proxyPortLabel = new QLabel(tabNetwork);
        proxyPortLabel->setObjectName(QString::fromUtf8("proxyPortLabel"));
        proxyPortLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_1_Network->addWidget(proxyPortLabel);

        proxyPort = new QLineEdit(tabNetwork);
        proxyPort->setObjectName(QString::fromUtf8("proxyPort"));
        proxyPort->setMinimumSize(QSize(55, 0));
        proxyPort->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_1_Network->addWidget(proxyPort);

        horizontalSpacer_1_Network = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_1_Network->addItem(horizontalSpacer_1_Network);


        verticalLayout_Network->addLayout(horizontalLayout_1_Network);

        horizontalLayout_2_Network = new QHBoxLayout();
        horizontalLayout_2_Network->setObjectName(QString::fromUtf8("horizontalLayout_2_Network"));
        proxyActiveNets = new QLabel(tabNetwork);
        proxyActiveNets->setObjectName(QString::fromUtf8("proxyActiveNets"));
        proxyActiveNets->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Network->addWidget(proxyActiveNets);

        proxyReachIPv4 = new QCheckBox(tabNetwork);
        proxyReachIPv4->setObjectName(QString::fromUtf8("proxyReachIPv4"));
        proxyReachIPv4->setEnabled(false);

        horizontalLayout_2_Network->addWidget(proxyReachIPv4);

        proxyReachIPv4Label = new QLabel(tabNetwork);
        proxyReachIPv4Label->setObjectName(QString::fromUtf8("proxyReachIPv4Label"));
        proxyReachIPv4Label->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Network->addWidget(proxyReachIPv4Label);

        proxyReachIPv6 = new QCheckBox(tabNetwork);
        proxyReachIPv6->setObjectName(QString::fromUtf8("proxyReachIPv6"));
        proxyReachIPv6->setEnabled(false);

        horizontalLayout_2_Network->addWidget(proxyReachIPv6);

        proxyReachIPv6Label = new QLabel(tabNetwork);
        proxyReachIPv6Label->setObjectName(QString::fromUtf8("proxyReachIPv6Label"));
        proxyReachIPv6Label->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Network->addWidget(proxyReachIPv6Label);

        proxyReachTor = new QCheckBox(tabNetwork);
        proxyReachTor->setObjectName(QString::fromUtf8("proxyReachTor"));
        proxyReachTor->setEnabled(false);

        horizontalLayout_2_Network->addWidget(proxyReachTor);

        proxyReachTorLabel = new QLabel(tabNetwork);
        proxyReachTorLabel->setObjectName(QString::fromUtf8("proxyReachTorLabel"));
        proxyReachTorLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Network->addWidget(proxyReachTorLabel);

        horizontalSpacer_2_Network = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2_Network->addItem(horizontalSpacer_2_Network);


        verticalLayout_Network->addLayout(horizontalLayout_2_Network);

        connectSocksTor = new QCheckBox(tabNetwork);
        connectSocksTor->setObjectName(QString::fromUtf8("connectSocksTor"));

        verticalLayout_Network->addWidget(connectSocksTor);

        horizontalLayout_3_Network = new QHBoxLayout();
        horizontalLayout_3_Network->setObjectName(QString::fromUtf8("horizontalLayout_3_Network"));
        proxyIpTorLabel = new QLabel(tabNetwork);
        proxyIpTorLabel->setObjectName(QString::fromUtf8("proxyIpTorLabel"));
        proxyIpTorLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_3_Network->addWidget(proxyIpTorLabel);

        proxyIpTor = new QValidatedLineEdit(tabNetwork);
        proxyIpTor->setObjectName(QString::fromUtf8("proxyIpTor"));
        proxyIpTor->setMinimumSize(QSize(140, 0));
        proxyIpTor->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_3_Network->addWidget(proxyIpTor);

        proxyPortTorLabel = new QLabel(tabNetwork);
        proxyPortTorLabel->setObjectName(QString::fromUtf8("proxyPortTorLabel"));
        proxyPortTorLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_3_Network->addWidget(proxyPortTorLabel);

        proxyPortTor = new QLineEdit(tabNetwork);
        proxyPortTor->setObjectName(QString::fromUtf8("proxyPortTor"));
        proxyPortTor->setMinimumSize(QSize(55, 0));
        proxyPortTor->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_3_Network->addWidget(proxyPortTor);

        horizontalSpacer_4_Network = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3_Network->addItem(horizontalSpacer_4_Network);


        verticalLayout_Network->addLayout(horizontalLayout_3_Network);

        verticalSpacer_Network = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Network->addItem(verticalSpacer_Network);

        tabWidget->addTab(tabNetwork, QString());
        tabWindow = new QWidget();
        tabWindow->setObjectName(QString::fromUtf8("tabWindow"));
        verticalLayout_Window = new QVBoxLayout(tabWindow);
        verticalLayout_Window->setObjectName(QString::fromUtf8("verticalLayout_Window"));
        showTrayIcon = new QCheckBox(tabWindow);
        showTrayIcon->setObjectName(QString::fromUtf8("showTrayIcon"));
        showTrayIcon->setChecked(true);

        verticalLayout_Window->addWidget(showTrayIcon);

        minimizeToTray = new QCheckBox(tabWindow);
        minimizeToTray->setObjectName(QString::fromUtf8("minimizeToTray"));

        verticalLayout_Window->addWidget(minimizeToTray);

        minimizeOnClose = new QCheckBox(tabWindow);
        minimizeOnClose->setObjectName(QString::fromUtf8("minimizeOnClose"));

        verticalLayout_Window->addWidget(minimizeOnClose);

        verticalSpacer_Window = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Window->addItem(verticalSpacer_Window);

        tabWidget->addTab(tabWindow, QString());
        tabDisplay = new QWidget();
        tabDisplay->setObjectName(QString::fromUtf8("tabDisplay"));
        verticalLayout_Display = new QVBoxLayout(tabDisplay);
        verticalLayout_Display->setObjectName(QString::fromUtf8("verticalLayout_Display"));
        horizontalLayout_1_Display = new QHBoxLayout();
        horizontalLayout_1_Display->setObjectName(QString::fromUtf8("horizontalLayout_1_Display"));
        langLabel = new QLabel(tabDisplay);
        langLabel->setObjectName(QString::fromUtf8("langLabel"));
        langLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_1_Display->addWidget(langLabel);

        lang = new QValueComboBox(tabDisplay);
        lang->setObjectName(QString::fromUtf8("lang"));

        horizontalLayout_1_Display->addWidget(lang);


        verticalLayout_Display->addLayout(horizontalLayout_1_Display);

        horizontalLayout_2_Display = new QHBoxLayout();
        horizontalLayout_2_Display->setObjectName(QString::fromUtf8("horizontalLayout_2_Display"));
        unitLabel = new QLabel(tabDisplay);
        unitLabel->setObjectName(QString::fromUtf8("unitLabel"));
        unitLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_2_Display->addWidget(unitLabel);

        unit = new QValueComboBox(tabDisplay);
        unit->setObjectName(QString::fromUtf8("unit"));

        horizontalLayout_2_Display->addWidget(unit);


        verticalLayout_Display->addLayout(horizontalLayout_2_Display);

        horizontalLayout_3_Display = new QHBoxLayout();
        horizontalLayout_3_Display->setObjectName(QString::fromUtf8("horizontalLayout_3_Display"));
        thirdPartyTxUrlsLabel = new QLabel(tabDisplay);
        thirdPartyTxUrlsLabel->setObjectName(QString::fromUtf8("thirdPartyTxUrlsLabel"));

        horizontalLayout_3_Display->addWidget(thirdPartyTxUrlsLabel);

        thirdPartyTxUrls = new QLineEdit(tabDisplay);
        thirdPartyTxUrls->setObjectName(QString::fromUtf8("thirdPartyTxUrls"));
        thirdPartyTxUrls->setPlaceholderText(QString::fromUtf8("https://example.com/tx/%s"));

        horizontalLayout_3_Display->addWidget(thirdPartyTxUrls);


        verticalLayout_Display->addLayout(horizontalLayout_3_Display);

        font_groupBox = new QGroupBox(tabDisplay);
        font_groupBox->setObjectName(QString::fromUtf8("font_groupBox"));
        font_verticalLayout = new QVBoxLayout(font_groupBox);
        font_verticalLayout->setObjectName(QString::fromUtf8("font_verticalLayout"));
        embeddedFont_horizontalLayout = new QHBoxLayout();
        embeddedFont_horizontalLayout->setObjectName(QString::fromUtf8("embeddedFont_horizontalLayout"));
        embeddedFont_radioButton = new QRadioButton(font_groupBox);
        embeddedFont_radioButton->setObjectName(QString::fromUtf8("embeddedFont_radioButton"));

        embeddedFont_horizontalLayout->addWidget(embeddedFont_radioButton);

        embeddedFont_horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        embeddedFont_horizontalLayout->addItem(embeddedFont_horizontalSpacer);

        embeddedFont_verticalLayout = new QVBoxLayout();
        embeddedFont_verticalLayout->setObjectName(QString::fromUtf8("embeddedFont_verticalLayout"));
        embeddedFont_label_1 = new QLabel(font_groupBox);
        embeddedFont_label_1->setObjectName(QString::fromUtf8("embeddedFont_label_1"));
        embeddedFont_label_1->setText(QString::fromUtf8("111.11111111 BTC"));

        embeddedFont_verticalLayout->addWidget(embeddedFont_label_1);

        embeddedFont_label_9 = new QLabel(font_groupBox);
        embeddedFont_label_9->setObjectName(QString::fromUtf8("embeddedFont_label_9"));
        embeddedFont_label_9->setText(QString::fromUtf8("909.09090909 BTC"));

        embeddedFont_verticalLayout->addWidget(embeddedFont_label_9);


        embeddedFont_horizontalLayout->addLayout(embeddedFont_verticalLayout);


        font_verticalLayout->addLayout(embeddedFont_horizontalLayout);

        font_line = new QFrame(font_groupBox);
        font_line->setObjectName(QString::fromUtf8("font_line"));
        font_line->setFrameShape(QFrame::HLine);
        font_line->setFrameShadow(QFrame::Sunken);

        font_verticalLayout->addWidget(font_line);

        systemFont_horizontalLayout = new QHBoxLayout();
        systemFont_horizontalLayout->setObjectName(QString::fromUtf8("systemFont_horizontalLayout"));
        systemFont_radioButton = new QRadioButton(font_groupBox);
        systemFont_radioButton->setObjectName(QString::fromUtf8("systemFont_radioButton"));

        systemFont_horizontalLayout->addWidget(systemFont_radioButton);

        systemFont_horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        systemFont_horizontalLayout->addItem(systemFont_horizontalSpacer);

        systemFont_verticalLayout = new QVBoxLayout();
        systemFont_verticalLayout->setObjectName(QString::fromUtf8("systemFont_verticalLayout"));
        systemFont_label_1 = new QLabel(font_groupBox);
        systemFont_label_1->setObjectName(QString::fromUtf8("systemFont_label_1"));
        systemFont_label_1->setText(QString::fromUtf8("111.11111111 BTC"));

        systemFont_verticalLayout->addWidget(systemFont_label_1);

        systemFont_label_9 = new QLabel(font_groupBox);
        systemFont_label_9->setObjectName(QString::fromUtf8("systemFont_label_9"));
        systemFont_label_9->setText(QString::fromUtf8("909.09090909 BTC"));

        systemFont_verticalLayout->addWidget(systemFont_label_9);


        systemFont_horizontalLayout->addLayout(systemFont_verticalLayout);


        font_verticalLayout->addLayout(systemFont_horizontalLayout);


        verticalLayout_Display->addWidget(font_groupBox);

        verticalSpacer_Display = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_Display->addItem(verticalSpacer_Display);

        tabWidget->addTab(tabDisplay, QString());

        verticalLayout->addWidget(tabWidget);

        frame = new QFrame(OptionsDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        verticalLayout_Bottom = new QVBoxLayout(frame);
        verticalLayout_Bottom->setObjectName(QString::fromUtf8("verticalLayout_Bottom"));
        horizontalLayout_Bottom = new QHBoxLayout();
        horizontalLayout_Bottom->setObjectName(QString::fromUtf8("horizontalLayout_Bottom"));
        overriddenByCommandLineInfoLabel = new QLabel(frame);
        overriddenByCommandLineInfoLabel->setObjectName(QString::fromUtf8("overriddenByCommandLineInfoLabel"));
        overriddenByCommandLineInfoLabel->setTextFormat(Qt::PlainText);

        horizontalLayout_Bottom->addWidget(overriddenByCommandLineInfoLabel);

        horizontalSpacer_Bottom = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Bottom->addItem(horizontalSpacer_Bottom);


        verticalLayout_Bottom->addLayout(horizontalLayout_Bottom);

        overriddenByCommandLineLabel = new QLabel(frame);
        overriddenByCommandLineLabel->setObjectName(QString::fromUtf8("overriddenByCommandLineLabel"));
        overriddenByCommandLineLabel->setTextFormat(Qt::PlainText);
        overriddenByCommandLineLabel->setWordWrap(true);

        verticalLayout_Bottom->addWidget(overriddenByCommandLineLabel);


        verticalLayout->addWidget(frame);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setObjectName(QString::fromUtf8("horizontalLayout_Buttons"));
        verticalLayout_Buttons = new QVBoxLayout();
        verticalLayout_Buttons->setObjectName(QString::fromUtf8("verticalLayout_Buttons"));
        openBitcoinConfButton = new QPushButton(OptionsDialog);
        openBitcoinConfButton->setObjectName(QString::fromUtf8("openBitcoinConfButton"));
        openBitcoinConfButton->setAutoDefault(false);

        verticalLayout_Buttons->addWidget(openBitcoinConfButton);

        resetButton = new QPushButton(OptionsDialog);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setAutoDefault(false);

        verticalLayout_Buttons->addWidget(resetButton);


        horizontalLayout_Buttons->addLayout(verticalLayout_Buttons);

        horizontalSpacer_1 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_1);

        statusLabel = new QLabel(OptionsDialog);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setMinimumSize(QSize(200, 0));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        statusLabel->setFont(font);
        statusLabel->setTextFormat(Qt::PlainText);
        statusLabel->setWordWrap(true);

        horizontalLayout_Buttons->addWidget(statusLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okButton = new QPushButton(OptionsDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setAutoDefault(false);

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(OptionsDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_Buttons->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_Buttons);

#if QT_CONFIG(shortcut)
        databaseCacheLabel->setBuddy(databaseCache);
        threadsScriptVerifLabel->setBuddy(threadsScriptVerif);
        externalSignerPathLabel->setBuddy(externalSignerPath);
        proxyIpLabel->setBuddy(proxyIp);
        proxyPortLabel->setBuddy(proxyPort);
        proxyIpTorLabel->setBuddy(proxyIpTor);
        proxyPortTorLabel->setBuddy(proxyPortTor);
        langLabel->setBuddy(lang);
        unitLabel->setBuddy(unit);
        thirdPartyTxUrlsLabel->setBuddy(thirdPartyTxUrls);
#endif // QT_CONFIG(shortcut)

        retranslateUi(OptionsDialog);

        tabWidget->setCurrentIndex(0);
        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QCoreApplication::translate("OptionsDialog", "Options", nullptr));
#if QT_CONFIG(tooltip)
        bitcoinAtStartup->setToolTip(QCoreApplication::translate("OptionsDialog", "Automatically start %1 after logging in to the system.", nullptr));
#endif // QT_CONFIG(tooltip)
        bitcoinAtStartup->setText(QCoreApplication::translate("OptionsDialog", "&Start %1 on system login", nullptr));
#if QT_CONFIG(tooltip)
        prune->setToolTip(QCoreApplication::translate("OptionsDialog", "Enabling pruning significantly reduces the disk space required to store transactions. All blocks are still fully validated. Reverting this setting requires re-downloading the entire blockchain.", nullptr));
#endif // QT_CONFIG(tooltip)
        prune->setText(QCoreApplication::translate("OptionsDialog", "Prune &block storage to", nullptr));
        pruneSizeUnitLabel->setText(QCoreApplication::translate("OptionsDialog", "GB", nullptr));
        pruneWarning->setText(QCoreApplication::translate("OptionsDialog", "Reverting this setting requires re-downloading the entire blockchain.", nullptr));
#if QT_CONFIG(tooltip)
        databaseCacheLabel->setToolTip(QCoreApplication::translate("OptionsDialog", "Maximum database cache size. A larger cache can contribute to faster sync, after which the benefit is less pronounced for most use cases. Lowering the cache size will reduce memory usage. Unused mempool memory is shared for this cache.", nullptr));
#endif // QT_CONFIG(tooltip)
        databaseCacheLabel->setText(QCoreApplication::translate("OptionsDialog", "Size of &database cache", nullptr));
        databaseCacheUnitLabel->setText(QCoreApplication::translate("OptionsDialog", "MiB", nullptr));
#if QT_CONFIG(tooltip)
        threadsScriptVerifLabel->setToolTip(QCoreApplication::translate("OptionsDialog", "Set the number of script verification threads. Negative values correspond to the number of cores you want to leave free to the system.", nullptr));
#endif // QT_CONFIG(tooltip)
        threadsScriptVerifLabel->setText(QCoreApplication::translate("OptionsDialog", "Number of script &verification threads", nullptr));
#if QT_CONFIG(tooltip)
        threadsScriptVerif->setToolTip(QCoreApplication::translate("OptionsDialog", "(0 = auto, <0 = leave that many cores free)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        enableServer->setToolTip(QCoreApplication::translate("OptionsDialog", "This allows you or a third party tool to communicate with the node through command-line and JSON-RPC commands.", nullptr));
#endif // QT_CONFIG(tooltip)
        enableServer->setText(QCoreApplication::translate("OptionsDialog", "Enable R&PC server", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMain), QCoreApplication::translate("OptionsDialog", "&Main", nullptr));
#if QT_CONFIG(tooltip)
        subFeeFromAmount->setToolTip(QCoreApplication::translate("OptionsDialog", "Whether to set subtract fee from amount as default or not.", nullptr));
#endif // QT_CONFIG(tooltip)
        subFeeFromAmount->setText(QCoreApplication::translate("OptionsDialog", "Subtract &fee from amount by default", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OptionsDialog", "Expert", nullptr));
#if QT_CONFIG(tooltip)
        coinControlFeatures->setToolTip(QCoreApplication::translate("OptionsDialog", "Whether to show coin control features or not.", nullptr));
#endif // QT_CONFIG(tooltip)
        coinControlFeatures->setText(QCoreApplication::translate("OptionsDialog", "Enable coin &control features", nullptr));
#if QT_CONFIG(tooltip)
        spendZeroConfChange->setToolTip(QCoreApplication::translate("OptionsDialog", "If you disable the spending of unconfirmed change, the change from a transaction cannot be used until that transaction has at least one confirmation. This also affects how your balance is computed.", nullptr));
#endif // QT_CONFIG(tooltip)
        spendZeroConfChange->setText(QCoreApplication::translate("OptionsDialog", "&Spend unconfirmed change", nullptr));
        m_enable_psbt_controls->setText(QCoreApplication::translate("OptionsDialog", "Enable &PSBT controls", nullptr));
#if QT_CONFIG(tooltip)
        m_enable_psbt_controls->setToolTip(QCoreApplication::translate("OptionsDialog", "Whether to show PSBT controls.", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBoxHww->setTitle(QCoreApplication::translate("OptionsDialog", "External Signer (e.g. hardware wallet)", nullptr));
        externalSignerPathLabel->setText(QCoreApplication::translate("OptionsDialog", "&External signer script path", nullptr));
#if QT_CONFIG(tooltip)
        externalSignerPath->setToolTip(QCoreApplication::translate("OptionsDialog", "Full path to a %1 compatible script (e.g. C:\\Downloads\\hwi.exe or /Users/you/Downloads/hwi.py). Beware: malware can steal your coins!", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tabWallet), QCoreApplication::translate("OptionsDialog", "W&allet", nullptr));
#if QT_CONFIG(tooltip)
        mapPortUpnp->setToolTip(QCoreApplication::translate("OptionsDialog", "Automatically open the Playchain client port on the router. This only works when your router supports UPnP and it is enabled.", nullptr));
#endif // QT_CONFIG(tooltip)
        mapPortUpnp->setText(QCoreApplication::translate("OptionsDialog", "Map port using &UPnP", nullptr));
#if QT_CONFIG(tooltip)
        mapPortNatpmp->setToolTip(QCoreApplication::translate("OptionsDialog", "Automatically open the Bitcoin client port on the router. This only works when your router supports NAT-PMP and it is enabled. The external port could be random.", nullptr));
#endif // QT_CONFIG(tooltip)
        mapPortNatpmp->setText(QCoreApplication::translate("OptionsDialog", "Map port using NA&T-PMP", nullptr));
#if QT_CONFIG(tooltip)
        allowIncoming->setToolTip(QCoreApplication::translate("OptionsDialog", "Accept connections from outside.", nullptr));
#endif // QT_CONFIG(tooltip)
        allowIncoming->setText(QCoreApplication::translate("OptionsDialog", "Allow incomin&g connections", nullptr));
#if QT_CONFIG(tooltip)
        connectSocks->setToolTip(QCoreApplication::translate("OptionsDialog", "Connect to the Playchain network through a SOCKS5 proxy.", nullptr));
#endif // QT_CONFIG(tooltip)
        connectSocks->setText(QCoreApplication::translate("OptionsDialog", "&Connect through SOCKS5 proxy (default proxy):", nullptr));
        proxyIpLabel->setText(QCoreApplication::translate("OptionsDialog", "Proxy &IP:", nullptr));
#if QT_CONFIG(tooltip)
        proxyIp->setToolTip(QCoreApplication::translate("OptionsDialog", "IP address of the proxy (e.g. IPv4: 127.0.0.1 / IPv6: ::1)", nullptr));
#endif // QT_CONFIG(tooltip)
        proxyPortLabel->setText(QCoreApplication::translate("OptionsDialog", "&Port:", nullptr));
#if QT_CONFIG(tooltip)
        proxyPort->setToolTip(QCoreApplication::translate("OptionsDialog", "Port of the proxy (e.g. 9050)", nullptr));
#endif // QT_CONFIG(tooltip)
        proxyActiveNets->setText(QCoreApplication::translate("OptionsDialog", "Used for reaching peers via:", nullptr));
#if QT_CONFIG(tooltip)
        proxyReachIPv4->setToolTip(QCoreApplication::translate("OptionsDialog", "Shows if the supplied default SOCKS5 proxy is used to reach peers via this network type.", nullptr));
#endif // QT_CONFIG(tooltip)
        proxyReachIPv4->setText(QString());
        proxyReachIPv4Label->setText(QCoreApplication::translate("OptionsDialog", "IPv4", nullptr));
#if QT_CONFIG(tooltip)
        proxyReachIPv6->setToolTip(QCoreApplication::translate("OptionsDialog", "Shows if the supplied default SOCKS5 proxy is used to reach peers via this network type.", nullptr));
#endif // QT_CONFIG(tooltip)
        proxyReachIPv6->setText(QString());
        proxyReachIPv6Label->setText(QCoreApplication::translate("OptionsDialog", "IPv6", nullptr));
#if QT_CONFIG(tooltip)
        proxyReachTor->setToolTip(QCoreApplication::translate("OptionsDialog", "Shows if the supplied default SOCKS5 proxy is used to reach peers via this network type.", nullptr));
#endif // QT_CONFIG(tooltip)
        proxyReachTor->setText(QString());
        proxyReachTorLabel->setText(QCoreApplication::translate("OptionsDialog", "Tor", nullptr));
#if QT_CONFIG(tooltip)
        connectSocksTor->setToolTip(QCoreApplication::translate("OptionsDialog", "Connect to the Bitcoin network through a separate SOCKS5 proxy for Tor onion services.", nullptr));
#endif // QT_CONFIG(tooltip)
        connectSocksTor->setText(QCoreApplication::translate("OptionsDialog", "Use separate SOCKS&5 proxy to reach peers via Tor onion services:", nullptr));
        proxyIpTorLabel->setText(QCoreApplication::translate("OptionsDialog", "Proxy &IP:", nullptr));
#if QT_CONFIG(tooltip)
        proxyIpTor->setToolTip(QCoreApplication::translate("OptionsDialog", "IP address of the proxy (e.g. IPv4: 127.0.0.1 / IPv6: ::1)", nullptr));
#endif // QT_CONFIG(tooltip)
        proxyPortTorLabel->setText(QCoreApplication::translate("OptionsDialog", "&Port:", nullptr));
#if QT_CONFIG(tooltip)
        proxyPortTor->setToolTip(QCoreApplication::translate("OptionsDialog", "Port of the proxy (e.g. 9050)", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tabNetwork), QCoreApplication::translate("OptionsDialog", "&Network", nullptr));
#if QT_CONFIG(tooltip)
        showTrayIcon->setToolTip(QCoreApplication::translate("OptionsDialog", "Show the icon in the system tray.", nullptr));
#endif // QT_CONFIG(tooltip)
        showTrayIcon->setText(QCoreApplication::translate("OptionsDialog", "&Show tray icon", nullptr));
#if QT_CONFIG(tooltip)
        minimizeToTray->setToolTip(QCoreApplication::translate("OptionsDialog", "Show only a tray icon after minimizing the window.", nullptr));
#endif // QT_CONFIG(tooltip)
        minimizeToTray->setText(QCoreApplication::translate("OptionsDialog", "&Minimize to the tray instead of the taskbar", nullptr));
#if QT_CONFIG(tooltip)
        minimizeOnClose->setToolTip(QCoreApplication::translate("OptionsDialog", "Minimize instead of exit the application when the window is closed. When this option is enabled, the application will be closed only after selecting Exit in the menu.", nullptr));
#endif // QT_CONFIG(tooltip)
        minimizeOnClose->setText(QCoreApplication::translate("OptionsDialog", "M&inimize on close", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWindow), QCoreApplication::translate("OptionsDialog", "&Window", nullptr));
        langLabel->setText(QCoreApplication::translate("OptionsDialog", "User Interface &language:", nullptr));
#if QT_CONFIG(tooltip)
        lang->setToolTip(QCoreApplication::translate("OptionsDialog", "The user interface language can be set here. This setting will take effect after restarting %1.", nullptr));
#endif // QT_CONFIG(tooltip)
        unitLabel->setText(QCoreApplication::translate("OptionsDialog", "&Unit to show amounts in:", nullptr));
#if QT_CONFIG(tooltip)
        unit->setToolTip(QCoreApplication::translate("OptionsDialog", "Choose the default subdivision unit to show in the interface and when sending coins.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        thirdPartyTxUrlsLabel->setToolTip(QCoreApplication::translate("OptionsDialog", "Third-party URLs (e.g. a block explorer) that appear in the transactions tab as context menu items. %s in the URL is replaced by transaction hash. Multiple URLs are separated by vertical bar |.", nullptr));
#endif // QT_CONFIG(tooltip)
        thirdPartyTxUrlsLabel->setText(QCoreApplication::translate("OptionsDialog", "&Third-party transaction URLs", nullptr));
#if QT_CONFIG(tooltip)
        thirdPartyTxUrls->setToolTip(QCoreApplication::translate("OptionsDialog", "Third-party URLs (e.g. a block explorer) that appear in the transactions tab as context menu items. %s in the URL is replaced by transaction hash. Multiple URLs are separated by vertical bar |.", nullptr));
#endif // QT_CONFIG(tooltip)
        font_groupBox->setTitle(QCoreApplication::translate("OptionsDialog", "Monospaced font in the Overview tab:", nullptr));
        embeddedFont_radioButton->setText(QCoreApplication::translate("OptionsDialog", "embedded \"%1\"", nullptr));
        systemFont_radioButton->setText(QCoreApplication::translate("OptionsDialog", "closest matching \"%1\"", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDisplay), QCoreApplication::translate("OptionsDialog", "&Display", nullptr));
        overriddenByCommandLineInfoLabel->setText(QCoreApplication::translate("OptionsDialog", "Options set in this dialog are overridden by the command line:", nullptr));
        overriddenByCommandLineLabel->setText(QString());
#if QT_CONFIG(tooltip)
        openBitcoinConfButton->setToolTip(QCoreApplication::translate("OptionsDialog", "Open the %1 configuration file from the working directory.", nullptr));
#endif // QT_CONFIG(tooltip)
        openBitcoinConfButton->setText(QCoreApplication::translate("OptionsDialog", "Open Configuration File", nullptr));
#if QT_CONFIG(tooltip)
        resetButton->setToolTip(QCoreApplication::translate("OptionsDialog", "Reset all client options to default.", nullptr));
#endif // QT_CONFIG(tooltip)
        resetButton->setText(QCoreApplication::translate("OptionsDialog", "&Reset Options", nullptr));
        statusLabel->setText(QString());
        okButton->setText(QCoreApplication::translate("OptionsDialog", "&OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("OptionsDialog", "&Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
