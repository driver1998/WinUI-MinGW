#include <Windows.h>
#include <MddBootstrap.h>
#include <WindowsAppSDK-VersionInfo.h>

#ifdef GetCurrentTime
#undef GetCurrentTime
#endif

#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/base.h>

#include "App.h"

using namespace winrt::Windows::Foundation;
using namespace winrt::Microsoft::UI::Xaml;

int main() {
    winrt::init_apartment(winrt::apartment_type::single_threaded);

    if (FAILED(MddBootstrapInitialize2(WINDOWSAPPSDK_RELEASE_MAJORMINOR,
                                       WINDOWSAPPSDK_RELEASE_VERSION_TAG_W,
                                       PACKAGE_VERSION{WINDOWSAPPSDK_RUNTIME_VERSION_UINT64},
                                       MddBootstrapInitializeOptions_None))) {
        throw std::runtime_error("Error in Bootstrap initialization");
    }

    Application::Start(
        [](auto &&) { auto app = winrt::make<winrt::WinUIMinGW::implementation::App>(); });

    MddBootstrapShutdown();
}
