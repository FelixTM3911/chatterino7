#include "controllers/ignores/EmoteBlacklistModel.hpp"

#include "common/SignalVectorModel.hpp"
#include "singletons/Settings.hpp"
#include "util/StandardItemHelper.hpp"
#include <QStandardItem>

namespace chatterino {

EmoteBlacklistModel::EmoteBlacklistModel(QObject *parent)
    : SignalVectorModel<QString>(1, parent)
{
}

EmoteBlacklistModel *EmoteBlacklistModel::initialized(
    ChatterinoSetting<std::vector<QString>> *setting)
{
    this->setting_ = setting;
    
    // Initialize with the SignalVector from Settings
    SignalVectorModel::initialize(&getSettings()->getBlacklistedEmotesVector());
    
    return this;
}

QString EmoteBlacklistModel::getItemFromRow(std::vector<QStandardItem *> &row,
                                          const QString &original)
{
    return row[0]->data(Qt::DisplayRole).toString();
}

void EmoteBlacklistModel::getRowFromItem(const QString &item,
                                        std::vector<QStandardItem *> &row)
{
    setStringItem(row[0], item);
}

}  // namespace chatterino











