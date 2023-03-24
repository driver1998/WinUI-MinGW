#pragma once
#include <winrt/base.h>
#include <winrt/Microsoft.UI.Xaml.h>

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::WinUIMinGW::implementation
{
    struct MainWindowView : WindowT<MainWindowView>
    {
        MainWindowView() = default;
        void InitializeComponent();
    };
}
