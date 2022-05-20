#pragma once

namespace BloodAccounting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для UseBloodForm
	/// </summary>
	public ref class UseBloodForm : public System::Windows::Forms::Form
	{
	public:
		String^ Name;
		Int32^ Age;
		Boolean^ Gender;

		UseBloodForm(void)
		{
			InitializeComponent();
		}

	protected:
		~UseBloodForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::TextBox^ tbFathername;
	private: System::Windows::Forms::TextBox^ tbSurname;
	private: System::Windows::Forms::NumericUpDown^ nudAge;
	private: System::Windows::Forms::ComboBox^ cbGender;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nudAge = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbGender = (gcnew System::Windows::Forms::ComboBox());
			this->tbFathername = (gcnew System::Windows::Forms::TextBox());
			this->tbSurname = (gcnew System::Windows::Forms::TextBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAge))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->nudAge);
			this->groupBox1->Controls->Add(this->cbGender);
			this->groupBox1->Controls->Add(this->tbFathername);
			this->groupBox1->Controls->Add(this->tbSurname);
			this->groupBox1->Controls->Add(this->tbName);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(403, 189);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Данные потребителя";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 157);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 17);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Возраст";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(34, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Пол";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 102);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Отчество";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Фамилимя";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Имя";
			// 
			// nudAge
			// 
			this->nudAge->Location = System::Drawing::Point(265, 155);
			this->nudAge->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->nudAge->Name = L"nudAge";
			this->nudAge->Size = System::Drawing::Size(132, 22);
			this->nudAge->TabIndex = 4;
			// 
			// cbGender
			// 
			this->cbGender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbGender->FormattingEnabled = true;
			this->cbGender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"муж", L"жен" });
			this->cbGender->Location = System::Drawing::Point(265, 125);
			this->cbGender->Name = L"cbGender";
			this->cbGender->Size = System::Drawing::Size(132, 24);
			this->cbGender->TabIndex = 3;
			// 
			// tbFathername
			// 
			this->tbFathername->Location = System::Drawing::Point(155, 97);
			this->tbFathername->Name = L"tbFathername";
			this->tbFathername->Size = System::Drawing::Size(242, 22);
			this->tbFathername->TabIndex = 2;
			// 
			// tbSurname
			// 
			this->tbSurname->Location = System::Drawing::Point(155, 69);
			this->tbSurname->Name = L"tbSurname";
			this->tbSurname->Size = System::Drawing::Size(242, 22);
			this->tbSurname->TabIndex = 1;
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(155, 41);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(242, 22);
			this->tbName->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(298, 207);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Использовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UseBloodForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(18, 207);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 17);
			this->label1->TabIndex = 2;
			// 
			// UseBloodForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 246);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"UseBloodForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Использование";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAge))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			
			if (tbName->Text->Trim()->Length < 2) {
				label1->Text = "Имя должно состоять минимум из 2х символов";
				return;
			}
			if (tbSurname->Text->Trim()->Length < 2) {
				label1->Text = "Фамилия должна состоять минимум из 2х символов";
				return;
			}
			if (cbGender->SelectedIndex == -1) {
				label1->Text = "Вы должны выбрать пол";
				return;
			}
			
			Name = tbSurname->Text->Trim() + " " + tbName->Text->Trim() + " " + tbFathername->Text->Trim();
			Age = Convert::ToInt32(nudAge->Value);
			Gender = cbGender->SelectedIndex == 0;
			//0 - муж / 1 - жен
			//true - муж/false - жен
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	};
}
