#include <Windows.h>
#include "donor.h"
#include "blood.h"

#pragma once

namespace BloodAccounting {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class BloodAdd : public System::Windows::Forms::Form
	{
	public:
		Int32^ Group;
		Boolean^ RhFactor;
		String^ DonorName;
		BloodAdd(String^ donorsFile)
		{
			InitializeComponent();

			StreamReader^ reader;
			try {
				reader = gcnew StreamReader(donorsFile);
				String^ line;
				while (line = reader->ReadLine()) {
					line = line->Trim();
					if (line != String::Empty) {
						auto buffer = line->Split(';');
						auto name = buffer[0];
						this->cbDonor->Items->Add(name);
					}
				}
			}
			catch (Exception^ ex) {
#ifdef DEBUG 
				MessageBox::Show(ex->Message);
				throw;
#else
				MessageBox::Show("Ошибка чтения файла");
				Application::Exit();
#endif
			}
			finally {
				reader->Close();
			}

		}

	protected:
		~BloodAdd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label3;
	protected:
	private: System::Windows::Forms::ComboBox^ cbDonor;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cbGroup;
	private: System::Windows::Forms::RadioButton^ rbFactorM;
	private: System::Windows::Forms::RadioButton^ rbFactorP;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label5;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cbDonor = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbGroup = (gcnew System::Windows::Forms::ComboBox());
			this->rbFactorM = (gcnew System::Windows::Forms::RadioButton());
			this->rbFactorP = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
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
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->cbDonor);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->cbGroup);
			this->groupBox1->Controls->Add(this->rbFactorM);
			this->groupBox1->Controls->Add(this->rbFactorP);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(361, 167);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Данные";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(264, 185);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 33);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BloodAdd::bCreateChart2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(12, 185);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 17);
			this->label5->TabIndex = 17;
			// 
			// BloodAdd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(387, 225);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"BloodAdd";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Новая кровь";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		System::Void bCreateChart2_Click(System::Object^ sender, System::EventArgs^ e) {
			if (cbGroup->SelectedIndex == -1) {
				this->label5->Text = "поле \"группа крови\" не \nдолжно быть пустым";
				return;
			}
			if (!rbFactorM->Checked && !rbFactorP->Checked) {
				this->label5->Text = "поле \"резус фактор\" не \nдолжно быть пустым";
				return;
			}
			if (cbDonor->SelectedIndex == -1) {
				this->label5->Text = "поле \"донор\" не \nдолжно быть пустым";
				return;
			}

			this->Group = this->cbGroup->SelectedIndex + 1;
			this->RhFactor = !this->rbFactorM->Checked;
			this->DonorName = this->cbDonor->SelectedItem->ToString();

			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();

		}
	};
}
