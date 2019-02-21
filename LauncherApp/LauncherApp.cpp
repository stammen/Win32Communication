// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <Windows.h>
#include<string>
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.System.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::System;

#pragma comment(lib, "WindowsApp.lib")

#define DESKTOP_APP_PATH "D:\\github\\Win32Communication\\x64\\Debug\\ConsoleApplication1.exe"

static PROCESS_INFORMATION launchProcess(std::string app, std::wstring arg)
{
	// Prepare handles.
	STARTUPINFO si;
	PROCESS_INFORMATION pi; // The function returns this
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	//Prepare CreateProcess args
	std::wstring app_w(app.length(), L' '); // Make room for characters
	std::copy(app.begin(), app.end(), app_w.begin()); // Copy string to wstring.

	std::wstring input = app_w + L" " + arg;
	wchar_t* arg_concat = const_cast<wchar_t*>(input.c_str());
	const wchar_t* app_const = app_w.c_str();

	// Start the child process.
	if (!CreateProcessW(
		app_const,      // app path
		arg_concat,     // Command line (needs to include app path as first argument. args seperated by whitepace)
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		throw std::exception("Could not create child process");
	}


	// Return process handle
	return pi;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	Uri uri(lpCmdLine);
	auto protocol = uri.QueryParsed().GetFirstValueByName(L"protocol");
	auto s = protocol.c_str();
	PROCESS_INFORMATION pi = launchProcess(DESKTOP_APP_PATH, protocol.c_str());

	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

    return 0;
}

