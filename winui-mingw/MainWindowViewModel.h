#pragma once
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Microsoft.UI.Xaml.Data.h>

using namespace winrt::Microsoft::UI::Xaml::Data;
using namespace winrt::Microsoft::UI::Xaml::Input;
using namespace winrt::Microsoft::UI::Xaml::Interop;
using winrt::Windows::UI::Xaml::Interop::TypeName;

namespace winrt::WinUIMinGW::implementation
{
    struct MainWindowViewModel : winrt::implements<MainWindowViewModel, ICustomPropertyProvider, INotifyPropertyChanged>
    {
        MainWindowViewModel();

        hstring Message();
        void Message(hstring const& value);
        hstring UserName();
        void UserName(hstring const& value);
        ICommand GreetingCommand();

        winrt::event_token PropertyChanged(PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

        ICustomProperty GetCustomProperty(hstring const& name);
        ICustomProperty GetIndexedProperty(hstring const& name, TypeName const& type);
        hstring GetStringRepresentation();
        TypeName Type();

        private:
        hstring m_message;
        hstring m_userName;
        ICommand m_greetingCommand;
        winrt::event<PropertyChangedEventHandler> m_propertyChangedEvent;
        
        static std::map<hstring, ICustomProperty> m_propertyMap;
    };
}
