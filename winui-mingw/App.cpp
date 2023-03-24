#include "App.h"
#include <winrt/base.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Microsoft.UI.Xaml.Controls.Primitives.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#include <winrt/Microsoft.UI.Xaml.XamlTypeInfo.h>

#include "MainWindowView.h"

using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Controls;
using namespace winrt::Microsoft::UI::Xaml::Interop;
using namespace winrt::Microsoft::UI::Xaml::Markup;
using namespace winrt::Microsoft::UI::Xaml::XamlTypeInfo;
using winrt::Windows::UI::Xaml::Interop::TypeName;

namespace winrt::WinUIMinGW::implementation
{
    void App::OnLaunched(LaunchActivatedEventArgs const&)
    {
        this->Resources().MergedDictionaries().Append(XamlControlsResources());
        auto window = winrt::make<MainWindowView>();
        window.Activate();
    }
    IXamlType App::GetXamlType(TypeName const& type)
    {
        return provider.GetXamlType(type);
    }
    IXamlType App::GetXamlType(hstring const& fullname)
    {
        return provider.GetXamlType(fullname);
    }
    com_array<XmlnsDefinition> App::GetXmlnsDefinitions()
    {
        return provider.GetXmlnsDefinitions();
    }
}