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

			FillFormBloodList();

			FillFormDonorsComboBox();
			//throw "123";
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
		System::Windows::Forms::CheckBox^ cb1gen;
		System::Windows::Forms::CheckBox^ cb0gen;
		System::Windows::Forms::CheckBox^ cb4gr;
		System::Windows::Forms::CheckBox^ cb3gr;
		System::Windows::Forms::CheckBox^ cb2gr;
		System::Windows::Forms::CheckBox^ cd1gr;
		System::Windows::Forms::Button^ useBlood;
		System::Windows::Forms::Button^ changeBlood;
		System::Windows::Forms::Button^ deleteBlood;
		System::Windows::Forms::Button^ addBlood;
		System::Windows::Forms::TabControl^ tabControl;
		System::Windows::Forms::TabPage^ tabPage1;
		System::Windows::Forms::TabPage^ tabPage2;
		System::Windows::Forms::TabPage^ tabPage3;
		System::Windows::Forms::ListBox^ lbBlood;
		System::Windows::Forms::RadioButton^ rbFactorM;
		System::Windows::Forms::RadioButton^ rbFactorP;
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::ComboBox^ cbGroup;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::ComboBox^ cbDonor;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cbDonor = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbGroup = (gcnew System::Windows::Forms::ComboBox());
			this->rbFactorM = (gcnew System::Windows::Forms::RadioButton());
			this->rbFactorP = (gcnew System::Windows::Forms::RadioButton());
			this->lbBlood = (gcnew System::Windows::Forms::ListBox());
			this->cb1gen = (gcnew System::Windows::Forms::CheckBox());
			this->cb0gen = (gcnew System::Windows::Forms::CheckBox());
			this->cb4gr = (gcnew System::Windows::Forms::CheckBox());
			this->cb3gr = (gcnew System::Windows::Forms::CheckBox());
			this->cb2gr = (gcnew System::Windows::Forms::CheckBox());
			this->cd1gr = (gcnew System::Windows::Forms::CheckBox());
			this->useBlood = (gcnew System::Windows::Forms::Button());
			this->changeBlood = (gcnew System::Windows::Forms::Button());
			this->deleteBlood = (gcnew System::Windows::Forms::Button());
			this->addBlood = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
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
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->lbBlood);
			this->tabPage1->Controls->Add(this->cb1gen);
			this->tabPage1->Controls->Add(this->cb0gen);
			this->tabPage1->Controls->Add(this->cb4gr);
			this->tabPage1->Controls->Add(this->cb3gr);
			this->tabPage1->Controls->Add(this->cb2gr);
			this->tabPage1->Controls->Add(this->cd1gr);
			this->tabPage1->Controls->Add(this->useBlood);
			this->tabPage1->Controls->Add(this->changeBlood);
			this->tabPage1->Controls->Add(this->deleteBlood);
			this->tabPage1->Controls->Add(this->addBlood);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(774, 424);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"���� �����";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->cbDonor);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->cbGroup);
			this->groupBox1->Controls->Add(this->rbFactorM);
			this->groupBox1->Controls->Add(this->rbFactorP);
			this->groupBox1->Location = System::Drawing::Point(444, 34);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(322, 347);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"��������� � �����";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 17);
			this->label3->TabIndex = 17;
			this->label3->Text = L"�����";
			// 
			// cbDonor
			// 
			this->cbDonor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbDonor->FormattingEnabled = true;
			this->cbDonor->Location = System::Drawing::Point(121, 124);
			this->cbDonor->Name = L"cbDonor";
			this->cbDonor->Size = System::Drawing::Size(195, 24);
			this->cbDonor->TabIndex = 16;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 17);
			this->label2->TabIndex = 15;
			this->label2->Text = L"����� ������";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"������ �����";
			// 
			// cbGroup
			// 
			this->cbGroup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbGroup->FormattingEnabled = true;
			this->cbGroup->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"A", L"B", L"AB" });
			this->cbGroup->Location = System::Drawing::Point(121, 37);
			this->cbGroup->Name = L"cbGroup";
			this->cbGroup->Size = System::Drawing::Size(195, 24);
			this->cbGroup->TabIndex = 13;
			// 
			// rbFactorM
			// 
			this->rbFactorM->AutoSize = true;
			this->rbFactorM->Location = System::Drawing::Point(241, 82);
			this->rbFactorM->Name = L"rbFactorM";
			this->rbFactorM->Size = System::Drawing::Size(34, 21);
			this->rbFactorM->TabIndex = 12;
			this->rbFactorM->TabStop = true;
			this->rbFactorM->Text = L"-";
			this->rbFactorM->UseVisualStyleBackColor = true;
			// 
			// rbFactorP
			// 
			this->rbFactorP->AutoSize = true;
			this->rbFactorP->Location = System::Drawing::Point(164, 82);
			this->rbFactorP->Name = L"rbFactorP";
			this->rbFactorP->Size = System::Drawing::Size(37, 21);
			this->rbFactorP->TabIndex = 11;
			this->rbFactorP->TabStop = true;
			this->rbFactorP->Text = L"+";
			this->rbFactorP->UseVisualStyleBackColor = true;
			// 
			// lbBlood
			// 
			this->lbBlood->FormattingEnabled = true;
			this->lbBlood->ItemHeight = 16;
			this->lbBlood->Location = System::Drawing::Point(14, 73);
			this->lbBlood->Name = L"lbBlood";
			this->lbBlood->Size = System::Drawing::Size(319, 308);
			this->lbBlood->TabIndex = 10;
			this->lbBlood->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox1_SelectedIndexChanged);
			// 
			// cb1gen
			// 
			this->cb1gen->AutoSize = true;
			this->cb1gen->Checked = true;
			this->cb1gen->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb1gen->Location = System::Drawing::Point(102, 6);
			this->cb1gen->Name = L"cb1gen";
			this->cb1gen->Size = System::Drawing::Size(39, 21);
			this->cb1gen->TabIndex = 9;
			this->cb1gen->Text = L"�";
			this->cb1gen->UseVisualStyleBackColor = true;
			// 
			// cb0gen
			// 
			this->cb0gen->AutoSize = true;
			this->cb0gen->Checked = true;
			this->cb0gen->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb0gen->Location = System::Drawing::Point(102, 33);
			this->cb0gen->Name = L"cb0gen";
			this->cb0gen->Size = System::Drawing::Size(39, 21);
			this->cb0gen->TabIndex = 8;
			this->cb0gen->Text = L"�";
			this->cb0gen->UseVisualStyleBackColor = true;
			// 
			// cb4gr
			// 
			this->cb4gr->AutoSize = true;
			this->cb4gr->Checked = true;
			this->cb4gr->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb4gr->Location = System::Drawing::Point(57, 33);
			this->cb4gr->Name = L"cb4gr";
			this->cb4gr->Size = System::Drawing::Size(48, 21);
			this->cb4gr->TabIndex = 7;
			this->cb4gr->Text = L"AB";
			this->cb4gr->UseVisualStyleBackColor = true;
			// 
			// cb3gr
			// 
			this->cb3gr->AutoSize = true;
			this->cb3gr->Checked = true;
			this->cb3gr->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb3gr->Location = System::Drawing::Point(12, 34);
			this->cb3gr->Name = L"cb3gr";
			this->cb3gr->Size = System::Drawing::Size(39, 21);
			this->cb3gr->TabIndex = 6;
			this->cb3gr->Text = L"B";
			this->cb3gr->UseVisualStyleBackColor = true;
			// 
			// cb2gr
			// 
			this->cb2gr->AutoSize = true;
			this->cb2gr->Checked = true;
			this->cb2gr->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb2gr->Location = System::Drawing::Point(57, 6);
			this->cb2gr->Name = L"cb2gr";
			this->cb2gr->Size = System::Drawing::Size(39, 21);
			this->cb2gr->TabIndex = 5;
			this->cb2gr->Text = L"A";
			this->cb2gr->UseVisualStyleBackColor = true;
			// 
			// cd1gr
			// 
			this->cd1gr->AutoSize = true;
			this->cd1gr->Checked = true;
			this->cd1gr->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cd1gr->Location = System::Drawing::Point(13, 6);
			this->cd1gr->Name = L"cd1gr";
			this->cd1gr->Size = System::Drawing::Size(38, 21);
			this->cd1gr->TabIndex = 4;
			this->cd1gr->Text = L"0";
			this->cd1gr->UseVisualStyleBackColor = true;
			// 
			// useBlood
			// 
			this->useBlood->Enabled = false;
			this->useBlood->Location = System::Drawing::Point(444, 387);
			this->useBlood->Name = L"useBlood";
			this->useBlood->Size = System::Drawing::Size(158, 29);
			this->useBlood->TabIndex = 3;
			this->useBlood->Text = L"������������";
			this->useBlood->UseVisualStyleBackColor = true;
			// 
			// changeBlood
			// 
			this->changeBlood->Enabled = false;
			this->changeBlood->Location = System::Drawing::Point(608, 387);
			this->changeBlood->Name = L"changeBlood";
			this->changeBlood->Size = System::Drawing::Size(158, 29);
			this->changeBlood->TabIndex = 2;
			this->changeBlood->Text = L"��������";
			this->changeBlood->UseVisualStyleBackColor = true;
			this->changeBlood->Click += gcnew System::EventHandler(this, &MainForm::changeBlood_Click);
			// 
			// deleteBlood
			// 
			this->deleteBlood->Enabled = false;
			this->deleteBlood->Location = System::Drawing::Point(175, 387);
			this->deleteBlood->Name = L"deleteBlood";
			this->deleteBlood->Size = System::Drawing::Size(158, 29);
			this->deleteBlood->TabIndex = 1;
			this->deleteBlood->Text = L"�������";
			this->deleteBlood->UseVisualStyleBackColor = true;
			this->deleteBlood->Click += gcnew System::EventHandler(this, &MainForm::deleteBlood_Click);
			// 
			// addBlood
			// 
			this->addBlood->Location = System::Drawing::Point(11, 387);
			this->addBlood->Name = L"addBlood";
			this->addBlood->Size = System::Drawing::Size(158, 29);
			this->addBlood->TabIndex = 0;
			this->addBlood->Text = L"��������";
			this->addBlood->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(774, 424);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"������";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(774, 424);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"������";
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
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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

		Void UpdateBloodList();
		Void UpdateDonorsList();

		Void FillDonorsList();
		Void FillBloodList();
		Void FillData();

		Void FillFormBloodList();
		Void FillFormDonorsList();
		Void FillFormDonorsComboBox();

	private: 
		System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			if (this->lbBlood->SelectedIndex != -1) {
				this->deleteBlood->Enabled = true;
				this->changeBlood->Enabled = true;
				this->useBlood->Enabled = true;

				auto selectBlood = (Blood^)this->lbBlood->SelectedItem;
				this->cbGroup->SelectedIndex = (int)selectBlood->getGroup() - 1;
				this->rbFactorM->Checked = !(bool)selectBlood->getRhFactor();
				this->rbFactorP->Checked = (bool)selectBlood->getRhFactor();
				this->cbDonor->SelectedIndex = this->cbDonor->Items->IndexOf(selectBlood->getDonor()->getName());
			}
			else {
				this->deleteBlood->Enabled = false;
				this->changeBlood->Enabled = false;
				this->useBlood->Enabled = false;

				this->rbFactorM->Checked = false;
				this->rbFactorP->Checked = false;
			}
		}
		System::Void changeBlood_Click(System::Object^ sender, System::EventArgs^ e) {
			auto selectBlood = (Blood^)this->lbBlood->SelectedItem;
			
			auto group = Convert::ToInt32(this->cbGroup->SelectedIndex) + 1;
			auto rhFactor = !this->rbFactorM->Checked;
			
			selectBlood->setGroup(group);
			selectBlood->setRhFactor(rhFactor);

			if (this->cbDonor->SelectedIndex != -1) {
				Donor^ donor = donors[this->cbDonor->SelectedIndex];
				selectBlood->setDonor(donor);
			}
			auto index = this->lbBlood->SelectedIndex;

			WriteBloodFile();
			FillFormBloodList();

			this->lbBlood->SelectedIndex = index;
		}
		System::Void deleteBlood_Click(System::Object^ sender, System::EventArgs^ e) {
			if (MessageBox::Show("������� �����?", "��������!", System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
				auto selectBlood = (Blood^)this->lbBlood->SelectedItem;
				blood.Remove(selectBlood);
				WriteBloodFile();
				FillFormBloodList();
			}
		}
};
}
