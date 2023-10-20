#include "MainWindowViewModel.h"
#include "SimpleCommand.h"

using namespace winrt::Microsoft::UI::Xaml::Data;
using namespace winrt::Microsoft::UI::Xaml::Input;
using namespace winrt::Microsoft::UI::Xaml::Interop;

namespace winrt::WinUIMinGW::implementation {
    MainWindowViewModel::MainWindowViewModel() {
        GreetingCommand(
            winrt::make<SimpleCommand>([this](winrt::Windows::Foundation::IInspectable parameter) {
                std::wstring str;
                str += L"Hello, ";
                str += this->UserName().c_str();
                this->Message(str.c_str());
            }));
    }
} // namespace winrt::WinUIMinGW::implementation
