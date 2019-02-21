#include<Windows.h>
#include<iostream>
#include<string>

static PROCESS_INFORMATION launchProcess(std::string app, std::string arg)
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

	std::wstring arg_w(arg.length(), L' '); // Make room for characters
	std::copy(arg.begin(), arg.end(), arg_w.begin()); // Copy string to wstring.

	std::wstring input = app_w + L" " + arg_w;
	input = L"\"C:\\Program Files(x86)\\Google\\Chrome\\Application\\chrome.exe\" https://www.microsoft.com/";
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
		printf("CreateProcess failed (%d).\n", GetLastError());
		throw std::exception("Could not create child process");
	}
	else
	{
		std::cout << "[          ] Successfully launched child process" << std::endl;
	}

	// Return process handle
	return pi;
}


int main()
{
	ShowWindow(::GetConsoleWindow(), SW_HIDE);

	std::string args("https://www.apple.com/");
	std::string app("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe");

	PROCESS_INFORMATION pi = launchProcess(app, "");

	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

