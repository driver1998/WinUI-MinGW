#pragma once
#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/base.h>

#include <functional>

using namespace winrt::Windows::Foundation;
using namespace winrt::Microsoft::UI::Xaml::Input;

namespace winrt::WinUIMinGW::implementation {
    struct SimpleCommand : winrt::implements<SimpleCommand, ICommand> {
        SimpleCommand(std::function<void(IInspectable)> action);

        bool CanExecute(IInspectable parameter);
        void Execute(IInspectable parameter);
        winrt::event_token CanExecuteChanged(EventHandler<IInspectable> const &handler);
        void CanExecuteChanged(winrt::event_token const &token) noexcept;

      private:
        std::function<void(IInspectable)> m_action;
        winrt::event<EventHandler<IInspectable>> m_eventToken;
    };
} // namespace winrt::WinUIMinGW::implementation