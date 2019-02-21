// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>

#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.System.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::System;

#pragma comment(lib, "WindowsApp.lib")

int main(int argc, char *argv[])
{
    winrt::init_apartment();

    std::string s(argv[1]);
    std::wstring protocol(s.begin(), s.end());
    protocol.append(L"?response=ConsoleApplication1-Response");
    Uri uri(protocol.c_str());
    Launcher::LaunchUriAsync(uri);
    std::wcout << L"Launched " << uri.ToString().c_str() << std::endl;
    std::cout << "Press any key to exit...\n";
    _getch();
}


