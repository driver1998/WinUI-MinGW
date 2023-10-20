#pragma once
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/base.h>

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::WinUIMinGW::implementation {
    struct MainWindowView : WindowT<MainWindowView> {
        MainWindowView() = default;
        void InitializeComponent();
    };
} // namespace winrt::WinUIMinGW::implementation
