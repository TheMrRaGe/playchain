#include <qt/buynamespage.h>
#include <qt/forms/ui_buynamespage.h>

#include <interfaces/node.h>
#include <logging.h>
#include <qt/configurenamedialog.h>
#include <qt/guiutil.h>
#include <qt/platformstyle.h>
#include <qt/walletmodel.h>
#include <rpc/protocol.h>

#include <univalue.h>

#include <QMessageBox>

#include <optional>

BuyNamesPage::BuyNamesPage(const PlatformStyle *platformStyle, QWidget *parent) :
    QWidget(parent),
    platformStyle(platformStyle),
    ui(new Ui::BuyNamesPage),
    walletModel(nullptr)
{
    ui->setupUi(this);

    ui->registerNameButton->hide();

    connect(ui->registerName, &QLineEdit::textEdited, this, &BuyNamesPage::onNameEdited);
    connect(ui->registerNameButton, &QPushButton::clicked, this, &BuyNamesPage::onRegisterNameAction);

    ui->registerName->installEventFilter(this);
}

BuyNamesPage::~BuyNamesPage()
{
    delete ui;
}

void BuyNamesPage::setModel(WalletModel *walletModel)
{
    this->walletModel = walletModel;
}

bool BuyNamesPage::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        if (object == ui->registerName)
        {
            ui->registerNameButton->setDefault(true);
        }
    }
    return QWidget::eventFilter(object, event);
}

void BuyNamesPage::onNameEdited(const QString &name)
{
    if (!walletModel)
        return;

    const QString availableError = name_available(name);

    if (availableError == "")
    {
        ui->statusLabel->setText(tr("%1 is available to register!").arg(name));
        ui->registerNameButton->show();
    }
    else
    {
        ui->statusLabel->setText(availableError);
        ui->registerNameButton->hide();
    }
}

void BuyNamesPage::onRegisterNameAction()
{
    if (!walletModel)
        return;

    QString name = ui->registerName->text();

    WalletModel::UnlockContext ctx(walletModel->requestUnlock());
    if (!ctx.isValid())
        return;

    ConfigureNameDialog dlg(platformStyle, name, "{}", this);
    dlg.setModel(walletModel);

    if (dlg.exec() != QDialog::Accepted)
        return;

    const QString &newValue = dlg.getReturnData();
    const std::optional<QString> transferToAddress = dlg.getTransferTo();

    const QString err_msg = this->registerName(name, newValue, transferToAddress);
    if (!err_msg.isEmpty() && err_msg != "ABORTED")
    {
        QMessageBox::critical(this, tr("Name registration error"), err_msg);
        return;
    }

    // reset UI text
    ui->registerName->setText("p/");
    ui->registerNameButton->setDefault(true);
}

// Returns empty string if available, otherwise a description of why it is not
// available.
QString BuyNamesPage::name_available(const QString &name) const
{
    const std::string strName = name.toStdString();
    LogPrint(BCLog::QT, "wallet attempting name_show: name=%s\n", strName);

    UniValue params(UniValue::VOBJ);
    params.pushKV ("name", strName);

    const std::string walletURI = "/wallet/" + walletModel->getWalletName().toStdString();

    try
    {
        walletModel->node().executeRpc("name_show", params, walletURI);
    }
    catch (const UniValue& e)
    {
        const UniValue code = find_value(e, "code");
        const int codeInt = code.getInt<int>();
        if (codeInt == RPC_WALLET_ERROR)
        {
            // Name doesn't exist, so it's available.
            return QString("");
        }

        const UniValue message = find_value(e, "message");
        const std::string errorStr = message.get_str();
        LogPrint(BCLog::QT, "name_show error: %s\n", errorStr);
        return QString::fromStdString(errorStr);
    }

    return tr("%1 is already registered, sorry!").arg(name);
}

QString BuyNamesPage::registerName(const QString &name, const std::optional<QString> &value, const std::optional<QString> &transferTo) const
{
    const std::string strName = name.toStdString();
    LogPrint(BCLog::QT, "wallet attempting name_register: name=%s\n", strName);

    UniValue params(UniValue::VOBJ);
    params.pushKV ("name", strName);

    if (value)
    {
        params.pushKV ("value", value.value().toStdString());
    }

    if (transferTo)
    {
        UniValue options(UniValue::VOBJ);
        options.pushKV ("destAddress", transferTo.value().toStdString());
        params.pushKV ("options", options);
    }

    const std::string walletURI = "/wallet/" + walletModel->getWalletName().toStdString();

    try {
        walletModel->node().executeRpc("name_register", params, walletURI);
    }
    catch (const UniValue& e) {
        const UniValue message = find_value(e, "message");
        const std::string errorStr = message.get_str();
        LogPrint(BCLog::QT, "name_register error: %s\n", errorStr);
        return QString::fromStdString(errorStr);
    }
    return tr ("");
}
