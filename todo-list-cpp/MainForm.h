#pragma once

namespace todolist {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			taskListBox->SelectedIndexChanged += gcnew EventHandler(this, &MainForm::DeleteTask);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ taskInput;
	private: System::Windows::Forms::Button^ addTaskBtn;
	protected:


	private: System::Windows::Forms::ListBox^ taskListBox;
	private: System::Windows::Forms::Label^ deleteLabel;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->taskInput = (gcnew System::Windows::Forms::TextBox());
			this->addTaskBtn = (gcnew System::Windows::Forms::Button());
			this->taskListBox = (gcnew System::Windows::Forms::ListBox());
			this->deleteLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Fira Code SemiBold", 8.999999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(39, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Add Task";
			// 
			// taskInput
			// 
			this->taskInput->Font = (gcnew System::Drawing::Font(L"Fira Code", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->taskInput->Location = System::Drawing::Point(37, 66);
			this->taskInput->Name = L"taskInput";
			this->taskInput->Size = System::Drawing::Size(217, 27);
			this->taskInput->TabIndex = 1;
			// 
			// addTaskBtn
			// 
			this->addTaskBtn->Font = (gcnew System::Drawing::Font(L"Fira Code SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addTaskBtn->Location = System::Drawing::Point(260, 66);
			this->addTaskBtn->Name = L"addTaskBtn";
			this->addTaskBtn->Size = System::Drawing::Size(75, 31);
			this->addTaskBtn->TabIndex = 2;
			this->addTaskBtn->Text = L"Add";
			this->addTaskBtn->UseVisualStyleBackColor = true;
			this->addTaskBtn->Click += gcnew System::EventHandler(this, &MainForm::AddTaskBtnClick);
			// 
			// taskListBox
			// 
			this->taskListBox->Font = (gcnew System::Drawing::Font(L"Fira Code", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->taskListBox->FormattingEnabled = true;
			this->taskListBox->ItemHeight = 24;
			this->taskListBox->Location = System::Drawing::Point(37, 112);
			this->taskListBox->Name = L"taskListBox";
			this->taskListBox->Size = System::Drawing::Size(298, 244);
			this->taskListBox->TabIndex = 3;
			this->taskListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::DeleteTask);
			// 
			// deleteLabel
			// 
			this->deleteLabel->AutoSize = true;
			this->deleteLabel->Font = (gcnew System::Drawing::Font(L"Fira Code Light", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteLabel->Location = System::Drawing::Point(33, 364);
			this->deleteLabel->Name = L"deleteLabel";
			this->deleteLabel->Size = System::Drawing::Size(202, 21);
			this->deleteLabel->TabIndex = 4;
			this->deleteLabel->Text = L"Click a task to delete.!";
			this->deleteLabel->Visible = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(371, 403);
			this->Controls->Add(this->deleteLabel);
			this->Controls->Add(this->taskListBox);
			this->Controls->Add(this->addTaskBtn);
			this->Controls->Add(this->taskInput);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"To do List";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void AddTaskBtnClick(System::Object^ sender, System::EventArgs^ e) {

		String^ task = taskInput->Text;

		if (task == "")
		{
		}

		else
		{
			task = "• " + Char::ToUpper(task[0]) + task->Substring(1);
			taskListBox->Items->Add(task);
			deleteLabel->Visible = true;
		}
		taskInput->Text = "";
	}



	private: System::Void DeleteTask(System::Object^ sender, System::EventArgs^ e) {

		if (taskListBox->SelectedIndex != -1) {
			taskListBox->Items->RemoveAt(taskListBox->SelectedIndex);
		}
	}

	};
}
