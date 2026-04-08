#include "QuoteClient.h"
#include <QNetworkRequest>
#include <QUrl>

QuoteClient::QuoteClient(QObject *parent)
    : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::finished,
            this, &QuoteClient::onReplyFinished);
}

void QuoteClient::fetchQuote()
{
    QUrl url("https://api.quotable.io/random");
    QNetworkRequest request(url);

    manager.get(request);
}

void QuoteClient::onReplyFinished(QNetworkReply* reply)
{
    QByteArray data = reply->readAll();

    // Simples (sem parse JSON ainda)
    emit quoteReceived(QString::fromUtf8(data));

    reply->deleteLater();
}
