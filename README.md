# UWP to Win32 App Communication without an App Service

Win32Communication is an example of how to communicate between a UWP app and an external Win32 Desktop app. 

Note: This sample is a [Desktop Bridge](https://developer.microsoft.com/en-us/windows/bridges/desktop) app that uses a Desktop Extension to launch the external Win32 Desktop app.

The solutions contains the following projects:

* Win32Communication - the main UWP App

* LauncherApp - the Desktop Extension used by the UWP app to launch the external Win32 Desktop App

* ConsoleApplication1 - the external Win32 Desktop App

* PackagingProject - A Desktop Bridge packaging project to package Win32Communication and LauncherApp into an AppX. Also makes debugging easier. 

## Requirements

* Visual Studio 2017 with the following workloads installed

	* Universal Windows Platform development. Make sure you add the C++ workload.
	
## Setup Instructions

You will need to configure the path to the ConsoleApplication1.exe after you do a build. ConsoleApplication1.exe should be in

	\Win32Communication\<Platform>\<Configuration>\ConsoleApplication1.exe
	
For example, if you did a x64/Debug build, it will be in:

	\Win32Communication\x64\Debug\ConsoleApplication1.exe

Update the DESKTOP_APP_PATH define (line 15) in the LauncherApp.cpp file in the LauncherApp project to the correct path. You need to specify the full path. For example:

	"D:\\github\\Win32Communication\\x64\\Debug\\ConsoleApplication1.exe"

Make sure you use \\\\ for each backslash in your path.

## Build and run Win32Communication

1. Open Win32Communication.sln

1. Make sure you have selected the x86 or x64 configuration. No not use the AnyCPU configuration.

1. Set the Packaging Project as the startup project

1. Press F5 to build and run the app.

1. A UWP app will appear. Click on the Launch Win32 App button. The external Win32 app (a console app) will launch and return a value to the UWP app

## Debugging the Win32Communication Apps

Since we are using the Packaging project to package and start the MFC app, we need to change the Debug properties of the Packaging project to use the Native Debugger.

* Right-click on the Packaging project.

* Select the Debug Tab

* Set Debugger Type | Application process to Native

* Set Debugger Type | Background task process to Native




##  Contributing

This project welcomes contributions and suggestions.  Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.microsoft.com.

When you submit a pull request, a CLA-bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., label, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.


## Reporting Security Issues

Security issues and bugs should be reported privately, via email, to the Microsoft Security
Response Center (MSRC) at [secure@microsoft.com](mailto:secure@microsoft.com). You should
receive a response within 24 hours. If for some reason you do not, please follow up via
email to ensure we received your original message. Further information, including the
[MSRC PGP](https://technet.microsoft.com/en-us/security/dn606155) key, can be found in
the [Security TechCenter](https://technet.microsoft.com/en-us/security/default).
