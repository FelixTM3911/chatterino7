#pragma once

#include "common/ChatterinoSetting.hpp"
#include "common/SignalVector.hpp"
#include "common/SignalVectorModel.hpp"

#include <QString>


namespace chatterino {

class EmoteBlacklistModel : public SignalVectorModel<QString>
{
public:
    explicit EmoteBlacklistModel(QObject *parent);
    virtual ~EmoteBlacklistModel() = default;

    // Add initialized method
    EmoteBlacklistModel *initialized(
        ChatterinoSetting<std::vector<QString>> *setting);

protected:
    // turn a vector item into a model row
    QString getItemFromRow(std::vector<QStandardItem *> &row,
                           const QString &original) override;

    // turns a row in the model into a vector item
    void getRowFromItem(const QString &item,
                        std::vector<QStandardItem *> &row) override;

private:
    ChatterinoSetting<std::vector<QString>> *setting_{nullptr};
    SignalVector<QString> items_;
};

}  // namespace chatterino
