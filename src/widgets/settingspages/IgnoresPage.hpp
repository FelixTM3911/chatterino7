#pragma once

#include "controllers/ignores/EmoteBlacklistModel.hpp"
#include "widgets/settingspages/SettingsPage.hpp"

#include <QStringListModel>


class QVBoxLayout;

namespace chatterino {

class IgnoresPage : public SettingsPage
{
public:
    IgnoresPage();

    void onShow() final;

private:
    QStringListModel userListModel_;
};

}  // namespace chatterino
