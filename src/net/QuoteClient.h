#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class QuoteClient : public QObject {
    Q_OBJECT

public:
    explicit QuoteClient(QObject *parent = nullptr);

    void fetchQuote();

signals:
    void quoteReceived(const QString& quote);

private slots:
    void onReplyFinished(QNetworkReply* reply);

private:
    QNetworkAccessManager manager;
};
