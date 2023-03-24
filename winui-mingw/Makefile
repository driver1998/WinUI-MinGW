CXX=c++
WINDRES=windres
CXXFLAGS=-std=c++20 -mcx16 -g
INCLUDES=-Icppwinrt -Iinclude -Iwinappsdk/include
LIBS=-lole32 -loleaut32 winappsdk/lib/win10-x64/Microsoft.WindowsAppRuntime.Bootstrap.lib
LDFLAGS=-mwindows -static

all: winui-mingw.exe

cppwinrt-headers:
	cppwinrt -pch . -input references/Windows.winmd -input winappsdk/lib/uap10.0 -input winappsdk/lib/uap10.0.18362 -output cppwinrt
	touch cppwinrt-headers

%.o: %.cpp %.h cppwinrt-headers
	${CXX} -c ${CXXFLAGS} ${INCLUDES} $< -o $@

main.o: main.cpp cppwinrt-headers
	${CXX} -c ${CXXFLAGS} ${INCLUDES} $< -o $@

res.o: app.rc app.manifest
	${WINDRES} app.rc -o res.o

winui-mingw.exe: App.o MainWindowView.o MainWindowViewModel.o CustomProperty.o SimpleCommand.o main.o res.o
	${CXX} $^ ${LIBS} ${LDFLAGS} -o $@
	cp winappsdk/runtimes/win10-x64/native/Microsoft.WindowsAppRuntime.Bootstrap.dll ./

clean:
	rm -rf *.exe *.dll *.winmd *.o *.res cppwinrt cppwinrt-headers
