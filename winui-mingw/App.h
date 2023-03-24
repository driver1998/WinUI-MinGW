#pragma once
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#include <winrt/Microsoft.UI.Xaml.XamlTypeInfo.h>

using namespace winrt::Windows::Foundation;
using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Markup;
using namespace winrt::Microsoft::UI::Xaml::XamlTypeInfo;
using winrt::Windows::UI::Xaml::Interop::TypeName;

namespace winrt::WinUIMinGW::implementation
{
    struct App : public ApplicationT<App, IXamlMetadataProvider>
    {
    public:
        void OnLaunched(LaunchActivatedEventArgs const&);
        IXamlType GetXamlType(TypeName const& type);
        IXamlType GetXamlType(hstring const& fullname);
        com_array<XmlnsDefinition> GetXmlnsDefinitions();
    private:
        Window window{ nullptr };
        XamlControlsXamlMetaDataProvider provider;
    };
}