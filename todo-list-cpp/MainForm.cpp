#include "MainForm.h"
//#include <msclr\marshal_cppstd.h>


using namespace System;
using namespace System::Windows::Forms;
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	todolist::MainForm form;
	Application::Run(% form);
}