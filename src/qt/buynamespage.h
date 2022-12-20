#ifndef BUYNAMESPAGE_H
#define BUYNAMESPAGE_H

#include <qt/platformstyle.h>

#include <QWidget>

class WalletModel;

namespace Ui {
    class BuyNamesPage;
}

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

/** Page for buying names */
class BuyNamesPage : public QWidget
{
    Q_OBJECT

public:
    explicit BuyNamesPage(const PlatformStyle *platformStyle, QWidget *parent = nullptr);
    ~BuyNamesPage();

    void setModel(WalletModel *walletModel);

private:
    const PlatformStyle *platformStyle;
    Ui::BuyNamesPage *ui;
    WalletModel *walletModel;

    QString name_available(const QString &name) const;
    QString registerName(const QString &name, const std::optional<QString> &value, const std::optional<QString> &transferTo) const;

private Q_SLOTS:
    bool eventFilter(QObject *object, QEvent *event);

    void onNameEdited(const QString &name);
    void onRegisterNameAction();
};

#endif // BUYNAMESPAGE_H
