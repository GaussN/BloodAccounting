#pragma once
#include "donor.h"
#include "blood.h"
namespace BloodAccounting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		String^ BloodFile = "data\\blood.txt";
		String^ DonorsFile = "data\\donors.txt";
		String^ LogsFile = "data\\logs.txt";
		List<Blood^> blood;
		List<Donor^> donors;









		   


	public:
		MainForm(void)
		{
			CheckFiles();
			InitializeComponent();	
			FillData();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::TabControl^ tabControl;

		System::Windows::Forms::TabPage^ tabPage1;
		System::Windows::Forms::TabPage^ tabPage2;
		System::Windows::Forms::TabPage^ tabPage3;


		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPage1);
			this->tabControl->Controls->Add(this->tabPage2);
			this->tabControl->Controls->Add(this->tabPage3);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Multiline = true;
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(782, 453);
			this->tabControl->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(774, 424);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Учет крови";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(774, 424);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Доноры";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(774, 424);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Отчеты";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 453);
			this->Controls->Add(this->tabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BloodAccounting";
			this->tabControl->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	public:
		Void CheckBloodFile();
		Void CheckDonorsFile();
		Void CheckLogsFile();
		Void CheckDirectory();
		Void CheckFiles();

		Void WriteBloodFile();
		Void WriteDonorsFile();
		Void WriteLog(String^ log);

		Void FillDonorsList();
		Void FillBloodList();
		Void FillData();
	};
}
