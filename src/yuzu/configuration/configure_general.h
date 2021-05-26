// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include <QWidget>

class ConfigureDialog;

namespace ConfigurationShared {
enum class CheckState;
}

class HotkeyRegistry;

namespace Ui {
class ConfigureGeneral;
}

class ConfigureGeneral : public QWidget {
    Q_OBJECT

public:
    explicit ConfigureGeneral(QWidget* parent = nullptr);
    ~ConfigureGeneral() override;

    void SetResetCallback(void (*callback)(ConfigureDialog*), ConfigureDialog *param);
    void ResetDefaults();
    void ApplyConfiguration();

private:
    void changeEvent(QEvent* event) override;
    void RetranslateUI();

    void SetConfiguration();

    void SetupPerGameUI();

    void (*ResetCallback)(ConfigureDialog*);
    ConfigureDialog *reset_callback_param;

    std::unique_ptr<Ui::ConfigureGeneral> ui;

    ConfigurationShared::CheckState use_frame_limit;
    ConfigurationShared::CheckState use_multi_core;
};
