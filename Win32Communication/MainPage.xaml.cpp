// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "pch.h"
#include "MainPage.xaml.h"
#include <ppltasks.h>

using namespace Win32Communication;

using namespace Concurrency;
using namespace Platform;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::System;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}

void MainPage::HandleProtocolActivation(ProtocolActivatedEventArgs^ args)
{
	auto uri = args->Uri;
	ProtocolResponseText->Text = uri->Query;
}


void MainPage::Launch_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ProtocolResponseText->Text = L"";
	Uri^ uri = ref new Uri(L"com.stammen.launcherapp:?protocol=com.stammen.win32communication:");
	auto task = create_task(Launcher::LaunchUriAsync(uri));
	task.then([this](bool result)
	{

	});
}

