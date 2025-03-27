#pragma once

#include "widgets/settingspages/SettingsPage.hpp"

#include <QStringListModel>

#include "controllers/ignores/EmoteBlacklistModel.hpp"

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
