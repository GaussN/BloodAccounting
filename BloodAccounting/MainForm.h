#pragma once
#include "donor.h"
#include "blood.h"
#include "BloodAddForm.h"
#include "UseBloodForm.h"

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
		String^ IncrementFile = "data\\increment.txt";
		int increment;
	public:
		List<Blood^> blood;
		List<Donor^> donors;
	public:
		MainForm(void)
		{
			CheckFiles();
			SetIncrement();
			InitializeComponent();
			FillData();

			FillFormBloodList();

			FillFormDonorsComboBox();
		
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

		System::Windows::Forms::ComboBox^ cbDonorS;
		System::Windows::Forms::Button^ bFindBlood;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::GroupBox^ groupBox2;
		System::Windows::Forms::Button^ bReset;
		System::Windows::Forms::CheckBox^ cb4gr;
		System::Windows::Forms::CheckBox^ cb3gr;
		System::Windows::Forms::CheckBox^ cb2gr;
		System::Windows::Forms::CheckBox^ cb1gr;
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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->bReset = (gcnew System::Windows::Forms::Button());
			this->cbDonorS = (gcnew System::Windows::Forms::ComboBox());
			this->bFindBlood = (gcnew System::Windows::Forms::Button());
			this->cb1gr = (gcnew System::Windows::Forms::CheckBox());
			this->cb4gr = (gcnew System::Windows::Forms::CheckBox());
			this->cb2gr = (gcnew System::Windows::Forms::CheckBox());
			this->cb3gr = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cbDonor = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbGroup = (gcnew System::Windows::Forms::ComboBox());
			this->rbFactorM = (gcnew System::Windows::Forms::RadioButton());
			this->rbFactorP = (gcnew System::Windows::Forms::RadioButton());
			this->lbBlood = (gcnew System::Windows::Forms::ListBox());
			this->useBlood = (gcnew System::Windows::Forms::Button());
			this->changeBlood = (gcnew System::Windows::Forms::Button());
			this->deleteBlood = (gcnew System::Windows::Forms::Button());
			this->addBlood = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox2->SuspendLayout();
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
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->lbBlood);
			this->tabPage1->Controls->Add(this->useBlood);
			this->tabPage1->Controls->Add(this->changeBlood);
			this->tabPage1->Controls->Add(this->deleteBlood);
			this->tabPage1->Controls->Add(this->addBlood);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(774, 424);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Учет крови";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 17);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Список пакетов крови";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->bReset);
			this->groupBox2->Controls->Add(this->cbDonorS);
			this->groupBox2->Controls->Add(this->bFindBlood);
			this->groupBox2->Controls->Add(this->cb1gr);
			this->groupBox2->Controls->Add(this->cb4gr);
			this->groupBox2->Controls->Add(this->cb2gr);
			this->groupBox2->Controls->Add(this->cb3gr);
			this->groupBox2->Location = System::Drawing::Point(405, 207);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(361, 174);
			this->groupBox2->TabIndex = 20;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Поиск";
			// 
			// bReset
			// 
			this->bReset->Location = System::Drawing::Point(241, 59);
			this->bReset->Name = L"bReset";
			this->bReset->Size = System::Drawing::Size(109, 24);
			this->bReset->TabIndex = 20;
			this->bReset->Text = L"Сбросить";
			this->bReset->UseVisualStyleBackColor = true;
			this->bReset->Click += gcnew System::EventHandler(this, &MainForm::bReset_Click);
			// 
			// cbDonorS
			// 
			this->cbDonorS->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbDonorS->FormattingEnabled = true;
			this->cbDonorS->Location = System::Drawing::Point(15, 21);
			this->cbDonorS->Name = L"cbDonorS";
			this->cbDonorS->Size = System::Drawing::Size(199, 24);
			this->cbDonorS->TabIndex = 18;
			// 
			// bFindBlood
			// 
			this->bFindBlood->Location = System::Drawing::Point(241, 21);
			this->bFindBlood->Name = L"bFindBlood";
			this->bFindBlood->Size = System::Drawing::Size(109, 24);
			this->bFindBlood->TabIndex = 19;
			this->bFindBlood->Text = L"Поиск\r\n";
			this->bFindBlood->UseVisualStyleBackColor = true;
			this->bFindBlood->Click += gcnew System::EventHandler(this, &MainForm::bFindBlood_Click);
			// 
			// cb1gr
			// 
			this->cb1gr->AutoSize = true;
			this->cb1gr->Checked = true;
			this->cb1gr->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb1gr->Location = System::Drawing::Point(15, 62);
			this->cb1gr->Name = L"cb1gr";
			this->cb1gr->Size = System::Drawing::Size(38, 21);
			this->cb1gr->TabIndex = 4;
			this->cb1gr->Text = L"0";
			this->cb1gr->UseVisualStyleBackColor = true;
			// 
			// cb4gr
			// 
			this->cb4gr->AutoSize = true;
			this->cb4gr->Checked = true;
			this->cb4gr->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb4gr->Location = System::Drawing::Point(59, 97);
			this->cb4gr->Name = L"cb4gr";
			this->cb4gr->Size = System::Drawing::Size(48, 21);
			this->cb4gr->TabIndex = 7;
			this->cb4gr->Text = L"AB";
			this->cb4gr->UseVisualStyleBackColor = true;
			// 
			// cb2gr
			// 
			this->cb2gr->AutoSize = true;
			this->cb2gr->Checked = true;
			this->cb2gr->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb2gr->Location = System::Drawing::Point(59, 62);
			this->cb2gr->Name = L"cb2gr";
			this->cb2gr->Size = System::Drawing::Size(39, 21);
			this->cb2gr->TabIndex = 5;
			this->cb2gr->Text = L"A";
			this->cb2gr->UseVisualStyleBackColor = true;
			// 
			// cb3gr
			// 
			this->cb3gr->AutoSize = true;
			this->cb3gr->Checked = true;
			this->cb3gr->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb3gr->Location = System::Drawing::Point(15, 97);
			this->cb3gr->Name = L"cb3gr";
			this->cb3gr->Size = System::Drawing::Size(39, 21);
			this->cb3gr->TabIndex = 6;
			this->cb3gr->Text = L"B";
			this->cb3gr->UseVisualStyleBackColor = true;
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
			this->groupBox1->Location = System::Drawing::Point(405, 34);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(361, 167);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Инормация о крови";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 17);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Донор";
			// 
			// cbDonor
			// 
			this->cbDonor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbDonor->FormattingEnabled = true;
			this->cbDonor->Location = System::Drawing::Point(138, 127);
			this->cbDonor->Name = L"cbDonor";
			this->cbDonor->Size = System::Drawing::Size(212, 24);
			this->cbDonor->TabIndex = 16;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 17);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Резус фактор";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Группа крови";
			// 
			// cbGroup
			// 
			this->cbGroup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbGroup->FormattingEnabled = true;
			this->cbGroup->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"A", L"B", L"AB" });
			this->cbGroup->Location = System::Drawing::Point(138, 37);
			this->cbGroup->Name = L"cbGroup";
			this->cbGroup->Size = System::Drawing::Size(212, 24);
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
			this->lbBlood->Location = System::Drawing::Point(14, 41);
			this->lbBlood->Name = L"lbBlood";
			this->lbBlood->Size = System::Drawing::Size(357, 340);
			this->lbBlood->TabIndex = 10;
			this->lbBlood->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox1_SelectedIndexChanged);
			// 
			// useBlood
			// 
			this->useBlood->Enabled = false;
			this->useBlood->Location = System::Drawing::Point(444, 387);
			this->useBlood->Name = L"useBlood";
			this->useBlood->Size = System::Drawing::Size(158, 29);
			this->useBlood->TabIndex = 3;
			this->useBlood->Text = L"Использовать";
			this->useBlood->UseVisualStyleBackColor = true;
			this->useBlood->Click += gcnew System::EventHandler(this, &MainForm::useBlood_Click);
			// 
			// changeBlood
			// 
			this->changeBlood->Enabled = false;
			this->changeBlood->Location = System::Drawing::Point(608, 387);
			this->changeBlood->Name = L"changeBlood";
			this->changeBlood->Size = System::Drawing::Size(158, 29);
			this->changeBlood->TabIndex = 2;
			this->changeBlood->Text = L"Изменить";
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
			this->deleteBlood->Text = L"Списать";
			this->deleteBlood->UseVisualStyleBackColor = true;
			this->deleteBlood->Click += gcnew System::EventHandler(this, &MainForm::deleteBlood_Click);
			// 
			// addBlood
			// 
			this->addBlood->Location = System::Drawing::Point(11, 387);
			this->addBlood->Name = L"addBlood";
			this->addBlood->Size = System::Drawing::Size(158, 29);
			this->addBlood->TabIndex = 0;
			this->addBlood->Text = L"Добавить";
			this->addBlood->UseVisualStyleBackColor = true;
			this->addBlood->Click += gcnew System::EventHandler(this, &MainForm::addBlood_Click);
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
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
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
		Void CheckIncrementFile();
		Void CheckFiles();

		Void WriteBloodFile();
		Void WriteDonorsFile();
		Void WriteLog(String^ log);

		Void UpdateBloodList(List<Blood^> bloodList, Blood^ newBlood);
		Void UpdateDonorsList(List<Donor^> donorsList, Donor^ newDonor);

		Void SetIncrement();
		Void UpdateIncrement();

		Void FillDonorsList();
		Void FillBloodList();
		Void FillData();

		Void FillFormBloodList();
		Void FillFormBloodList(String^ donorName);
		Void FillFormBloodList(bool O, bool A, bool B, bool AB);
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
			if (MessageBox::Show("Списать пакет?", "Внимание!", System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
				auto selectBlood = (Blood^)this->lbBlood->SelectedItem;
				blood.Remove(selectBlood);
				WriteBloodFile();
				FillFormBloodList();
			}
		}
		System::Void bReset_Click(System::Object^ sender, System::EventArgs^ e) {
			this->cbGroup->SelectedIndex = -1;
			this->cbDonor->SelectedIndex = -1;
			this->cbDonorS->SelectedIndex = -1;
			FillFormBloodList();
		}
		System::Void addBlood_Click(System::Object^ sender, System::EventArgs^ e) {
			BloodAdd^ addForm = gcnew BloodAdd(DonorsFile);
			if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				Donor^ donor;
				String^ donorName = addForm->Name;
				for (int i = 0; i < donors.Count; i++) {
					if (donorName = donors[i]->getName()) {
						donor = donors[i];
						break;
					}
				}
				blood.Add(gcnew Blood(increment, addForm->Group, addForm->RhFactor, donor));
				UpdateIncrement();
				WriteBloodFile();
				FillFormBloodList();
			}
		}
		System::Void bFindBlood_Click(System::Object^ sender, System::EventArgs^ e) {
			if (cbDonorS->SelectedIndex != -1) {
				FillFormBloodList(cbDonorS->SelectedItem->ToString());
			}
			else {
				FillFormBloodList(cb1gr->Checked, cb2gr->Checked, cb3gr->Checked, cb4gr->Checked);
			}
		}
		System::Void useBlood_Click(System::Object^ sender, System::EventArgs^ e) {
			
			UseBloodForm^ useForm = gcnew UseBloodForm();
			if (useForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				auto selectBlood = (Blood^)this->lbBlood->SelectedItem;
				String^ name = useForm->Name->Trim();
				Int32^ age = useForm->Age;
				Boolean^ gender = useForm->Gender;

				String^ log = selectBlood->ToString() + ";" + name + ";" + age + ";" + gender;
				
				WriteLog(log);
				blood.Remove(selectBlood);
				WriteBloodFile();
				FillFormBloodList();
			}


			/*
				auto selectBlood = (Blood^)this->lbBlood->SelectedItem;
				blood.Remove(selectBlood);
				WriteBloodFile();
				FillFormBloodList();
			*/
		}
	};
}
