

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Controls.Primitives.h>

#include "MainWindowView.h"
#include "MainWindowViewModel.h"

using namespace winrt::Windows::Foundation;
using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Controls;

namespace winrt::WinUIMinGW::implementation
{
    void MainWindowView::InitializeComponent()
    {
        Uri uri(L"ms-appx:///MainWindowView.xaml");
        Application::LoadComponent(*this, uri);

        auto viewModel = winrt::make<MainWindowViewModel>();
        auto viewModelImpl = winrt::get_self<MainWindowViewModel>(viewModel);
        viewModelImpl->UserName(L"MinGW");

        auto content = this->Content().as<FrameworkElement>();
        content.DataContext(viewModel);

        auto btn2 = content.FindName(L"btn2").as<Button>();
        if (btn2)
        {
            btn2.Click([](IInspectable const& sender, RoutedEventArgs const& args) -> winrt::fire_and_forget {
                ContentDialog dialog;
                dialog.Title(winrt::box_value(L"About"));
                dialog.Content(winrt::box_value(L"MinGW WinUI 3 Demo"));
                dialog.CloseButtonText(L"OK");

                auto btn = sender.try_as<Button>();
                dialog.XamlRoot(btn.XamlRoot());

                co_await dialog.ShowAsync();
            });
        }
    }
}
