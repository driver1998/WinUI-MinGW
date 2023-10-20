#pragma once
#include <functional>
#include <iostream>
#include <string_view>
#include <vector>
#include <winrt/Microsoft.UI.Xaml.Data.h>
#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/base.h>

#include "Property.hpp"

using namespace winrt::Microsoft::UI::Xaml::Data;
using namespace winrt::Microsoft::UI::Xaml::Input;
using namespace winrt::Microsoft::UI::Xaml::Interop;
using winrt::Windows::UI::Xaml::Interop::TypeName;

namespace winrt::WinUIMinGW::implementation {
    struct MainWindowViewModel
        : winrt::implements<MainWindowViewModel, ICustomPropertyProvider, INotifyPropertyChanged>,
          PropertyObject<MainWindowViewModel> {
        MainWindowViewModel();

        std::function<void(hstring const &name)> onPropertyChanged = [this](hstring const &name) {
            PropertyChanged.event(*this, PropertyChangedEventArgs{name});
        };

        Property<hstring> Message{L"Message", winrt::xaml_typename<hstring>(), onPropertyChanged};
        Property<hstring> UserName{L"UserName", winrt::xaml_typename<hstring>(), onPropertyChanged};
        Property<ICommand> GreetingCommand{L"GreetingCommand", winrt::xaml_typename<ICommand>(),
                                           onPropertyChanged};

        std::vector<IProperty *> PropertyList = {&Message, &UserName, &GreetingCommand};

        Event<PropertyChangedEventHandler> PropertyChanged;
    };
} // namespace winrt::WinUIMinGW::implementation
