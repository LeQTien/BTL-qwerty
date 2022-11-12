#pragma once
#include "Proceeds.h";
#include "OutputBill.h"
#include "Login_Admin.h"


namespace BTL_OOP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SqlClient;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{ 
		SqlConnection^ conect = gcnew SqlConnection("Data Source=.\\SQLEXPRESS;Initial Catalog=BTL_Data;Integrated Security=True");
	public:
		Main(void)
		{
			conect->Open();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//Add data menu
			SqlCommand^ Menu = gcnew  SqlCommand(" SELECT * FROM Menu", conect);
			SqlDataAdapter^ adap_menu = gcnew SqlDataAdapter(Menu);
			DataTable^ data_menu = gcnew DataTable();
			adap_menu->Fill(data_menu);
			this->dgv_Menu_->DataSource = data_menu;

			
			//Add data list table

			SqlDataAdapter^ adap_listtable = gcnew SqlDataAdapter("SELECT * FROM  [Table]", conect);
			DataTable^ data_list_table = gcnew DataTable();
			adap_listtable->Fill(data_list_table);
			cbx_choose_table->DisplayMember = "Table";
			cbx_choose_table->ValueMember = "Name";
			cbx_choose_table->DataSource = data_list_table;

			//Move table
			SqlDataAdapter^ adap_move = gcnew SqlDataAdapter("SELECT * FROM  [Table]", conect);
			DataTable^ data_move = gcnew DataTable();
			adap_move->Fill(data_move);
			cbx_move_table->DisplayMember = "Table";
			cbx_move_table->ValueMember = "Name";
			cbx_move_table->DataSource = data_move;


			//tbx totl bill
			for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
				tbx_total_bill->Text = Convert::ToString(double::Parse(tbx_total_bill->Text) + double::Parse(dgv_bill_table->Rows[i]->Cells[3]->Value->ToString()));
			}

			//busy table
		//	this.dataGridView1.Columns["CustomerID"].Visible = false;
			this->dgv_Menu_->Columns[2]->Visible = false;
		
			this->dgv_bill_table->Columns[4]->Visible = false;
			

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Declare


	private: System::Windows::Forms::DataGridView^ dgv_Menu_;
	private: System::Windows::Forms::Button^ btn_Add_;
	private: System::Windows::Forms::TextBox^ tbx_drink_name_;
	private: System::Windows::Forms::TextBox^ tbx_drink_;

	protected:



	private: System::Windows::Forms::TextBox^ tbx_total_drink_;

	private: System::Windows::Forms::TextBox^ tbx_price_drink;

	private: System::Windows::Forms::DataGridView^ dgv_bill_table;
	public: System::Windows::Forms::ComboBox^ cbx_choose_table;
	private:


	private: System::Windows::Forms::NumericUpDown^ number_;
	private: System::Windows::Forms::Button^ btn_Remove_;
	public: System::Windows::Forms::TextBox^ tbx_total_bill;
	private:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ adminToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ doanhThuToolStripMenuItem;
	public: System::Windows::Forms::Timer^ timer1;
	private:





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn_pay_bill;

	private: System::Windows::Forms::Button^ btn_move_table;
	private: System::Windows::Forms::ComboBox^ cbx_move_table;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::TextBox^ tbx_ID_drink;
private: System::Windows::Forms::Label^ label8;

private:
public: System::Windows::Forms::Label^ lbl_name_staff;




private: System::Windows::Forms::ToolStripMenuItem^ đăngXuấtToolStripMenuItem;



	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dgv_Menu_ = (gcnew System::Windows::Forms::DataGridView());
			this->btn_Add_ = (gcnew System::Windows::Forms::Button());
			this->tbx_drink_name_ = (gcnew System::Windows::Forms::TextBox());
			this->tbx_drink_ = (gcnew System::Windows::Forms::TextBox());
			this->tbx_total_drink_ = (gcnew System::Windows::Forms::TextBox());
			this->tbx_price_drink = (gcnew System::Windows::Forms::TextBox());
			this->dgv_bill_table = (gcnew System::Windows::Forms::DataGridView());
			this->cbx_choose_table = (gcnew System::Windows::Forms::ComboBox());
			this->number_ = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_Remove_ = (gcnew System::Windows::Forms::Button());
			this->tbx_total_bill = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->adminToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->doanhThuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_pay_bill = (gcnew System::Windows::Forms::Button());
			this->btn_move_table = (gcnew System::Windows::Forms::Button());
			this->cbx_move_table = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbx_ID_drink = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lbl_name_staff = (gcnew System::Windows::Forms::Label());
			this->đăngXuấtToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Menu_))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_bill_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number_))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgv_Menu_
			// 
			this->dgv_Menu_->AllowUserToAddRows = false;
			this->dgv_Menu_->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgv_Menu_->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle19->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle19->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle19->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle19->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle19->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle19->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_Menu_->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle19;
			this->dgv_Menu_->ColumnHeadersHeight = 29;
			this->dgv_Menu_->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->dgv_Menu_->Location = System::Drawing::Point(12, 115);
			this->dgv_Menu_->Name = L"dgv_Menu_";
			this->dgv_Menu_->ReadOnly = true;
			dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle20->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle20->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle20->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle20->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle20->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_Menu_->RowHeadersDefaultCellStyle = dataGridViewCellStyle20;
			this->dgv_Menu_->RowHeadersWidth = 51;
			dataGridViewCellStyle21->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dgv_Menu_->RowsDefaultCellStyle = dataGridViewCellStyle21;
			this->dgv_Menu_->RowTemplate->Height = 24;
			this->dgv_Menu_->Size = System::Drawing::Size(418, 566);
			this->dgv_Menu_->TabIndex = 0;
			this->dgv_Menu_->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Main::dgv_Menu__CellClick);
			// 
			// btn_Add_
			// 
			this->btn_Add_->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Add_->Location = System::Drawing::Point(490, 532);
			this->btn_Add_->Name = L"btn_Add_";
			this->btn_Add_->Size = System::Drawing::Size(135, 72);
			this->btn_Add_->TabIndex = 1;
			this->btn_Add_->Text = L"Thêm món";
			this->btn_Add_->UseVisualStyleBackColor = true;
			this->btn_Add_->Click += gcnew System::EventHandler(this, &Main::btn_Add__Click);
			// 
			// tbx_drink_name_
			// 
			this->tbx_drink_name_->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_drink_name_->Location = System::Drawing::Point(579, 250);
			this->tbx_drink_name_->Name = L"tbx_drink_name_";
			this->tbx_drink_name_->ReadOnly = true;
			this->tbx_drink_name_->Size = System::Drawing::Size(152, 34);
			this->tbx_drink_name_->TabIndex = 2;
			// 
			// tbx_drink_
			// 
			this->tbx_drink_->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_drink_->Location = System::Drawing::Point(989, 633);
			this->tbx_drink_->Name = L"tbx_drink_";
			this->tbx_drink_->ReadOnly = true;
			this->tbx_drink_->Size = System::Drawing::Size(144, 34);
			this->tbx_drink_->TabIndex = 3;
			// 
			// tbx_total_drink_
			// 
			this->tbx_total_drink_->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_total_drink_->Location = System::Drawing::Point(579, 468);
			this->tbx_total_drink_->Name = L"tbx_total_drink_";
			this->tbx_total_drink_->ReadOnly = true;
			this->tbx_total_drink_->Size = System::Drawing::Size(152, 34);
			this->tbx_total_drink_->TabIndex = 4;
			// 
			// tbx_price_drink
			// 
			this->tbx_price_drink->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_price_drink->Location = System::Drawing::Point(579, 317);
			this->tbx_price_drink->Name = L"tbx_price_drink";
			this->tbx_price_drink->ReadOnly = true;
			this->tbx_price_drink->Size = System::Drawing::Size(152, 34);
			this->tbx_price_drink->TabIndex = 5;
			// 
			// dgv_bill_table
			// 
			this->dgv_bill_table->AllowUserToAddRows = false;
			this->dgv_bill_table->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			dataGridViewCellStyle22->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle22->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle22->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle22->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle22->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle22->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle22->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_bill_table->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle22;
			this->dgv_bill_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_bill_table->GridColor = System::Drawing::SystemColors::ScrollBar;
			this->dgv_bill_table->Location = System::Drawing::Point(767, 115);
			this->dgv_bill_table->Name = L"dgv_bill_table";
			this->dgv_bill_table->ReadOnly = true;
			dataGridViewCellStyle23->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle23->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle23->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle23->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle23->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle23->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle23->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_bill_table->RowHeadersDefaultCellStyle = dataGridViewCellStyle23;
			this->dgv_bill_table->RowHeadersWidth = 51;
			dataGridViewCellStyle24->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dgv_bill_table->RowsDefaultCellStyle = dataGridViewCellStyle24;
			this->dgv_bill_table->RowTemplate->Height = 24;
			this->dgv_bill_table->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dgv_bill_table->Size = System::Drawing::Size(568, 504);
			this->dgv_bill_table->TabIndex = 6;
			this->dgv_bill_table->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Main::dgv_bill_table_CellClick);
			// 
			// cbx_choose_table
			// 
			this->cbx_choose_table->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbx_choose_table->FormattingEnabled = true;
			this->cbx_choose_table->Location = System::Drawing::Point(1197, 61);
			this->cbx_choose_table->Name = L"cbx_choose_table";
			this->cbx_choose_table->Size = System::Drawing::Size(138, 33);
			this->cbx_choose_table->TabIndex = 7;
			this->cbx_choose_table->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::cbx_choose_table_SelectedIndexChanged);
			// 
			// number_
			// 
			this->number_->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->number_->Location = System::Drawing::Point(579, 392);
			this->number_->Name = L"number_";
			this->number_->Size = System::Drawing::Size(152, 34);
			this->number_->TabIndex = 8;
			this->number_->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->number_->ValueChanged += gcnew System::EventHandler(this, &Main::number__ValueChanged);
			// 
			// btn_Remove_
			// 
			this->btn_Remove_->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Remove_->Location = System::Drawing::Point(989, 673);
			this->btn_Remove_->Name = L"btn_Remove_";
			this->btn_Remove_->Size = System::Drawing::Size(144, 54);
			this->btn_Remove_->TabIndex = 9;
			this->btn_Remove_->Text = L"Xóa";
			this->btn_Remove_->UseVisualStyleBackColor = true;
			this->btn_Remove_->Click += gcnew System::EventHandler(this, &Main::btn_Remove__Click);
			// 
			// tbx_total_bill
			// 
			this->tbx_total_bill->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_total_bill->Location = System::Drawing::Point(767, 633);
			this->tbx_total_bill->Name = L"tbx_total_bill";
			this->tbx_total_bill->ReadOnly = true;
			this->tbx_total_bill->Size = System::Drawing::Size(164, 34);
			this->tbx_total_bill->TabIndex = 10;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->adminToolStripMenuItem,
					this->doanhThuToolStripMenuItem, this->đăngXuấtToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1354, 30);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// adminToolStripMenuItem
			// 
			this->adminToolStripMenuItem->Name = L"adminToolStripMenuItem";
			this->adminToolStripMenuItem->Size = System::Drawing::Size(77, 26);
			this->adminToolStripMenuItem->Text = L"Admin";
			this->adminToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::adminToolStripMenuItem_Click);
			// 
			// doanhThuToolStripMenuItem
			// 
			this->doanhThuToolStripMenuItem->Name = L"doanhThuToolStripMenuItem";
			this->doanhThuToolStripMenuItem->Size = System::Drawing::Size(103, 26);
			this->doanhThuToolStripMenuItem->Text = L"Doanh thu";
			this->doanhThuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::doanhThuToolStripMenuItem_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Main::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(949, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 25);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Time";
			// 
			// btn_pay_bill
			// 
			this->btn_pay_bill->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_pay_bill->Location = System::Drawing::Point(767, 673);
			this->btn_pay_bill->Name = L"btn_pay_bill";
			this->btn_pay_bill->Size = System::Drawing::Size(164, 54);
			this->btn_pay_bill->TabIndex = 15;
			this->btn_pay_bill->Text = L"Thanh toán";
			this->btn_pay_bill->UseVisualStyleBackColor = true;
			this->btn_pay_bill->Click += gcnew System::EventHandler(this, &Main::btn_pay_bill_Click);
			// 
			// btn_move_table
			// 
			this->btn_move_table->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_move_table->Location = System::Drawing::Point(1187, 673);
			this->btn_move_table->Name = L"btn_move_table";
			this->btn_move_table->Size = System::Drawing::Size(148, 54);
			this->btn_move_table->TabIndex = 17;
			this->btn_move_table->Text = L"Chuyển bàn";
			this->btn_move_table->UseVisualStyleBackColor = true;
			this->btn_move_table->Click += gcnew System::EventHandler(this, &Main::btn_move_table_Click);
			// 
			// cbx_move_table
			// 
			this->cbx_move_table->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbx_move_table->FormattingEnabled = true;
			this->cbx_move_table->Location = System::Drawing::Point(1187, 634);
			this->cbx_move_table->Name = L"cbx_move_table";
			this->cbx_move_table->Size = System::Drawing::Size(148, 33);
			this->cbx_move_table->TabIndex = 18;
			this->cbx_move_table->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::cbx_move_table_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Ravie", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(97, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(170, 54);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Menu";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(446, 253);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(102, 26);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Tên món:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(446, 320);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 26);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Đơn giá:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(446, 394);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 26);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Số lượng:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(446, 471);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(118, 26);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Thành tiền:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(842, 62);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(232, 32);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Mặt hàng đã chọn";
			// 
			// tbx_ID_drink
			// 
			this->tbx_ID_drink->Location = System::Drawing::Point(646, 582);
			this->tbx_ID_drink->Name = L"tbx_ID_drink";
			this->tbx_ID_drink->Size = System::Drawing::Size(97, 22);
			this->tbx_ID_drink->TabIndex = 25;
			this->tbx_ID_drink->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(8, 705);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(162, 22);
			this->label8->TabIndex = 26;
			this->label8->Text = L"Nhân viên sử dụng:";
			// 
			// lbl_name_staff
			// 
			this->lbl_name_staff->AutoSize = true;
			this->lbl_name_staff->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_name_staff->Location = System::Drawing::Point(192, 704);
			this->lbl_name_staff->Name = L"lbl_name_staff";
			this->lbl_name_staff->Size = System::Drawing::Size(75, 23);
			this->lbl_name_staff->TabIndex = 28;
			this->lbl_name_staff->Text = L"Tên NV";
			// 
			// đăngXuấtToolStripMenuItem
			// 
			this->đăngXuấtToolStripMenuItem->Name = L"đăngXuấtToolStripMenuItem";
			this->đăngXuấtToolStripMenuItem->Size = System::Drawing::Size(102, 26);
			this->đăngXuấtToolStripMenuItem->Text = L"Đăng xuất";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1354, 739);
			this->Controls->Add(this->lbl_name_staff);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tbx_ID_drink);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cbx_move_table);
			this->Controls->Add(this->btn_move_table);
			this->Controls->Add(this->btn_pay_bill);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbx_total_bill);
			this->Controls->Add(this->btn_Remove_);
			this->Controls->Add(this->number_);
			this->Controls->Add(this->cbx_choose_table);
			this->Controls->Add(this->dgv_bill_table);
			this->Controls->Add(this->tbx_price_drink);
			this->Controls->Add(this->tbx_total_drink_);
			this->Controls->Add(this->tbx_drink_);
			this->Controls->Add(this->tbx_drink_name_);
			this->Controls->Add(this->btn_Add_);
			this->Controls->Add(this->dgv_Menu_);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Menu_))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_bill_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->number_))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void cbx_choose_table_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {


		int id = Convert::ToInt32(cbx_choose_table->SelectedValue);

#pragma region ShowTable







		if (id == 1) {
			SqlCommand^ cmd_table1 = gcnew SqlCommand("SELECT * FROM BillTable1", conect);
			SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_table1);
			DataTable^ list_table1 = gcnew DataTable();
			adap_table1->Fill(list_table1);
			this->dgv_bill_table->DataSource = list_table1;




			/*for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
				tbx_total_bill->Text = Convert::ToString(double::Parse(tbx_total_bill->Text) + double::Parse(dgv_bill_table->Rows[i]->Cells[3]->Value->ToString()));



				if (Convert::ToInt32(tbx_total_bill)==0) {
					lvs_table_->Items->Add("Phong ban");
					MessageBox::Show("right");
				}
			}*/
			//Load_Data();

		}
		else if (id == 2) {
			SqlCommand^ cmd_table2 = gcnew SqlCommand("SELECT * FROM BillTable2", conect);
			SqlDataAdapter^ adap_table2 = gcnew SqlDataAdapter(cmd_table2);
			DataTable^ list_table2 = gcnew DataTable();
			adap_table2->Fill(list_table2);
			this->dgv_bill_table->DataSource = list_table2;
			//Load_Data();


		}
		else if (id == 3) {
			SqlCommand^ cmd_table3 = gcnew SqlCommand("SELECT * FROM BillTable3", conect);
			SqlDataAdapter^ adap_table3 = gcnew SqlDataAdapter(cmd_table3);
			DataTable^ list_table3 = gcnew DataTable();
			adap_table3->Fill(list_table3);
			this->dgv_bill_table->DataSource = list_table3;
			//Load_Data();


		}
		else if (id == 4) {
			SqlCommand^ cmd_table4 = gcnew SqlCommand("SELECT * FROM BillTable4", conect);
			SqlDataAdapter^ adap_table4 = gcnew SqlDataAdapter(cmd_table4);
			DataTable^ list_table4 = gcnew DataTable();
			adap_table4->Fill(list_table4);
			this->dgv_bill_table->DataSource = list_table4;
			//Load_Data();


		}
		else if (id == 5) {
			SqlCommand^ cmd_table5 = gcnew SqlCommand("SELECT * FROM BillTable5", conect);
			SqlDataAdapter^ adap_table5 = gcnew SqlDataAdapter(cmd_table5);
			DataTable^ list_table5 = gcnew DataTable();
			adap_table5->Fill(list_table5);
			this->dgv_bill_table->DataSource = list_table5;
			//Load_Data();


		}
		else if (id == 6) {
			SqlCommand^ cmd_table6 = gcnew SqlCommand("SELECT * FROM BillTable6", conect);
			SqlDataAdapter^ adap_table6 = gcnew SqlDataAdapter(cmd_table6);
			DataTable^ list_table6 = gcnew DataTable();
			adap_table6->Fill(list_table6);
			this->dgv_bill_table->DataSource = list_table6;
			//Load_Data();


		}
		else if (id == 7) {
			SqlCommand^ cmd_table7 = gcnew SqlCommand("SELECT * FROM BillTable7", conect);
			SqlDataAdapter^ adap_table7 = gcnew SqlDataAdapter(cmd_table7);
			DataTable^ list_table7 = gcnew DataTable();
			adap_table7->Fill(list_table7);
			this->dgv_bill_table->DataSource = list_table7;
			//Load_Data();


		}
		else if (id == 8) {
			SqlCommand^ cmd_table8 = gcnew SqlCommand("SELECT * FROM BillTable8", conect);
			SqlDataAdapter^ adap_table8 = gcnew SqlDataAdapter(cmd_table8);
			DataTable^ list_table8 = gcnew DataTable();
			adap_table8->Fill(list_table8);
			this->dgv_bill_table->DataSource = list_table8;
			//Load_Data();


		}
		else if (id == 9) {
			SqlCommand^ cmd_table9 = gcnew SqlCommand("SELECT * FROM BillTable9", conect);
			SqlDataAdapter^ adap_table9 = gcnew SqlDataAdapter(cmd_table9);
			DataTable^ list_table9 = gcnew DataTable();
			adap_table9->Fill(list_table9);
			this->dgv_bill_table->DataSource = list_table9;
			//Load_Data();


		}

		else if (id == 10) {
			SqlCommand^ cmd_table10 = gcnew SqlCommand("SELECT * FROM BillTable10", conect);
			SqlDataAdapter^ adap_table10 = gcnew SqlDataAdapter(cmd_table10);
			DataTable^ list_table10 = gcnew DataTable();
			adap_table10->Fill(list_table10);
			this->dgv_bill_table->DataSource = list_table10;
			//Load_Data();


		}


#pragma endregion

		tbx_total_bill->Text = "0";
		for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
			tbx_total_bill->Text = Convert::ToString(double::Parse(tbx_total_bill->Text) + double::Parse(dgv_bill_table->Rows[i]->Cells[3]->Value->ToString()));

		}


	}
	private: System::Void btn_Add__Click(System::Object^ sender, System::EventArgs^ e) {
	

		if ( tbx_price_drink->Text == "" || tbx_drink_name_->Text == "") {
			MessageBox::Show(L"Lỗi chưa có dữ liệu", "Thông báo", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
		}
		else{
			int number = Convert::ToInt32(number_->Text);
			if (number == 0 || number == -1) {
				MessageBox::Show(L"Chưa nhập số lượng", L" Lỗi", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {

				int id = Convert::ToInt32(cbx_choose_table->SelectedValue);


#pragma region AddMenu
				if (id == 1) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable1(Name, Price, Amount,Total,ID) values(@Name, @Price, @Amount,@Total,@ID) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));
					cmd_add->Parameters->AddWithValue("@ID", Convert::ToInt32(tbx_ID_drink->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable1", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}
				else if (id == 2) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable2(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable2", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}



				else if (id == 3) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable3(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable3", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}


				else if (id == 4) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable4(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable4", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}

				else if (id == 5) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable5(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable5", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}

				else if (id == 6) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable6(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable6", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}


				else if (id == 7) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable7(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable7", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}


				else if (id == 8) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable8(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable8", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}

				else if (id == 9) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable9(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable9", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}


				else if (id == 10) {



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into BillTable10(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_drink_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_drink->Text));
					cmd_add->Parameters->AddWithValue("@Amount", Convert::ToInt32(number_->Text));
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_drink_->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable10", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_bill_table->DataSource = data;
					}
					else {
						MessageBox::Show(L"Thêm thất bại");

					}

				}

#pragma endregion
			}
			tbx_total_bill->Text = (Convert::ToInt32(tbx_total_drink_->Text) + Convert::ToInt32(tbx_total_bill->Text)).ToString();


			tbx_total_bill->Update();
		}

		

	};
	private: System::Void number__ValueChanged(System::Object^ sender, System::EventArgs^ e) {


		int number = Convert::ToInt32(number_->Value);
		int price = Convert::ToInt32(tbx_price_drink->Text);
		int total = number * price;
		tbx_total_drink_->Text = total.ToString();
	}
	private: System::Void btn_Remove__Click(System::Object^ sender, System::EventArgs^ e) {
		if (tbx_drink_->Text == "") {
			MessageBox::Show(L"Vui lòng chọn mặt hàng cần xóa", L"Lỗi", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
		}else{
			int id = Convert::ToInt32(cbx_choose_table->SelectedValue);
			int update_Total = Convert::ToInt32(tbx_ID_drink->Text);
			
#pragma region Delete Drink

			if (id == 1) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable1  where [Name]='" + tbx_drink_->Text + "' ", conect);


				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable1", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
					tbx_total_bill->Text = (Convert::ToInt32(tbx_total_bill->Text) - update_Total).ToString();
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}

			else if (id == 2) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable2   where [Name]='" + tbx_drink_->Text  + "' ", conect);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable2", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}


			else if (id == 3) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable3 where [Name]='" + tbx_drink_->Text + "' ", conect);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable3", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
					tbx_total_bill->Text = (Convert::ToInt32(tbx_total_bill->Text) - update_Total).ToString();
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}



			else if (id == 4) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable4  where [Name]='" + tbx_drink_->Text + "' ", conect);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable4", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
					tbx_total_bill->Text = (Convert::ToInt32(tbx_total_bill->Text) - update_Total).ToString();
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}




			else if (id == 5) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable5  where [Name]='" + tbx_drink_->Text + "' ", conect);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable5", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
					tbx_total_bill->Text = (Convert::ToInt32(tbx_total_bill->Text) - update_Total).ToString();
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}



			else if (id == 6) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable6  where [Name]='" + tbx_drink_->Text + "' ", conect);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable6", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
					tbx_total_bill->Text = (Convert::ToInt32(tbx_total_bill->Text) - update_Total).ToString();
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}



			if (id == 7) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable7  where [Name]='" + tbx_drink_->Text + "' ", conect);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable7", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
					tbx_total_bill->Text = (Convert::ToInt32(tbx_total_bill->Text) - update_Total).ToString();
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}




			if (id == 8) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable8  where [Name]='" + tbx_drink_->Text + "' ", conect);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable8", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
					tbx_total_bill->Text = (Convert::ToInt32(tbx_total_bill->Text) - update_Total).ToString();
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}



			if (id == 9) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable9  where [Name]='" + tbx_drink_->Text + "' ", conect);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable9", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
					tbx_total_bill->Text = (Convert::ToInt32(tbx_total_bill->Text) - update_Total).ToString();
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}



			if (id == 10) {
				SqlCommand^ cmd = gcnew SqlCommand("delete from BillTable10  where [Name]='" + tbx_drink_->Text + "' ", conect);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Xóa món thành công", L"Thông báo");

					SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable10", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_bill_table->DataSource = data;
					tbx_total_bill->Text = (Convert::ToInt32(tbx_total_bill->Text) - update_Total).ToString();
				}
				else {
					MessageBox::Show(L"Xóa món thất bại", L"Thông báo");

				}
			}
#pragma endregion
		}


		/*for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
			tbx_total_bill->Text = Convert::ToString(double::Parse(tbx_total_bill->Text) + double::Parse(dgv_bill_table->Rows[i]->Cells[3]->Value->ToString()));
		
		}*/

	}

	private: System::Void doanhThuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

			Proceeds^ psc = gcnew Proceeds;
			psc->ShowDialog();

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {


		this->label1->Text = String::Format(" {0}       {1}",
			DateTime::Now.ToString("dd/MM/yyyy"), DateTime::Now.ToString("hh:mm:ss tt"));

	}
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	public: int HD = 1234;
	private: System::Void btn_pay_bill_Click(System::Object^ sender, System::EventArgs^ e) {

		if (tbx_total_bill->Text == "0") {
			MessageBox::Show(L"Hiện không có hóa đơn để thanh toán", "Thông báo", MessageBoxButtons::RetryCancel, MessageBoxIcon::Information);
		}else{
		
			int id = Convert::ToInt32(cbx_choose_table->SelectedValue);
			if (MessageBox::Show(L"Bạn có muốn thanh toán bàn " + id + "?", "Thông báo", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
#pragma region SetBill
				if (MessageBox::Show(L"Bạn có muốn in hóa đơn? ", "Thông báo", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {



					int id = Convert::ToInt32(cbx_choose_table->SelectedValue);
					String^ staffname = L"Trần Quốc Chung";
					Proceeds^ prc = gcnew Proceeds();
					DateTime^ date = DateTime::Now;
					prc->dgv_proceeds;

					//	if (MessageBox::Show(L"Bạn có muốn in hóa đơn? ", "Thông báo", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					int total_count = 0;
					Bill^ Showbill = gcnew Bill();
					Showbill->lbl_HD->Text = HD.ToString();
					HD++;

					Showbill->lbl_totalBill->Text = tbx_total_bill->Text;


					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						total_count = Convert::ToInt32(total_count + Convert::ToInt32(dgv_bill_table->Rows[i]->Cells[2]->Value->ToString()));
					}
					Showbill->lbl_number->Text = total_count.ToString();
					Showbill->lbl_staff->Text = lbl_name_staff->Text;
#pragma endregion

#pragma region Input_Bill
					if (id == 1) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable1", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;

					}

					else if (id == 2) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable2", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;
					}
					else if (id == 3) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable3", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;
					}
					else if (id == 4) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable4", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;
					}
					else if (id == 5) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable5", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;
					}
					else if (id == 6) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable6", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;
					}
					else if (id == 7) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable7", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;
					}
					else if (id == 8) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable8", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;
					}
					else if (id == 9) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable9", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;
					}
					else if (id == 10) {

						SqlCommand^ Bill = gcnew  SqlCommand(" SELECT * FROM BillTable10", conect);
						SqlDataAdapter^ adap_bill = gcnew SqlDataAdapter(Bill);
						DataTable^ data_bill = gcnew DataTable();
						adap_bill->Fill(data_bill);
						Showbill->dgv_bill->DataSource = data_bill;
					}

					Showbill->ShowDialog();

#pragma endregion

#pragma region AddToProceeds



					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into Proceeds(Date, Staff, [Table] ,Total) values(@Date, @Staff, @Table , @Total) ", conect);

					cmd_add->Parameters->AddWithValue("@Date", date);
					cmd_add->Parameters->AddWithValue("@Staff", staffname);
					cmd_add->Parameters->AddWithValue("@Table", id);
					cmd_add->Parameters->AddWithValue("@Total", Convert::ToInt32(tbx_total_bill->Text));


					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thanh toán thành công");

						SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM Proceeds", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						prc->dgv_proceeds->DataSource = data;

					}
					else {
						MessageBox::Show(L"Thanh toán thất bại");
					}

#pragma endregion

#pragma region delete table(move)


					if (id == 1) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable1 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";
					}
					else if (id == 2) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable2 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";
					}
					else if (id == 3) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable3 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";
					}
					else if (id == 4) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable4 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";
					}
					else if (id == 5) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable5 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";
					}
					else if (id == 6) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable6 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";
					}
					else if (id == 7) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable7 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";

					}
					else if (id == 8) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable8 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";
					}
					else if (id == 9) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable9 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";
					}
					else if (id == 10) {
						SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable10 ", conect);
						SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
						DataTable^ data = gcnew DataTable();
						adap_remove->Fill(data);
						this->dgv_bill_table->DataSource = data;
						tbx_total_bill->Text = "0";
					}
#pragma endregion
				}
			}
		}


	}
	private: System::Void btn_move_table_Click(System::Object^ sender, System::EventArgs^ e) {

		int id = Convert::ToInt32(cbx_choose_table->SelectedValue);
		int move = Convert::ToInt32(cbx_move_table->SelectedValue);

		if (id == move) {
			MessageBox::Show(L"Bàn muốn chuyển trùng với bàn hiện tại", L"Lỗi" );
	
		}
		else {
			if (MessageBox::Show(L"Bạn có muốn chuyển bàn " + id.ToString() + L" sang bàn " + move.ToString(), "Thông báo", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK) {

#pragma region Add(Move Table)




				if (move == 1) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable1(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable1", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);
						}
						else {
							MessageBox::Show("False");
						}
					}
				}

				if (move == 2) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable2(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable2", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);
						}
						else {
							MessageBox::Show("False");
						}
					}
				}

				if (move == 3) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable3(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable3", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);
						}
						else {
							MessageBox::Show("False");
						}
					}
				}

				else if (move == 4) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable4(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable4", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);

						}
						else {
							MessageBox::Show("False");

						}
					}
					MessageBox::Show("Chuyển bàn thành công");
				}

				if (move == 5) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable5(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable5", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);
						}
						else {
							MessageBox::Show("False");
						}
					}
				}

				if (move == 6) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable6(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable6", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);
						}
						else {
							MessageBox::Show("False");
						}
					}
				}

				if (move == 7) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable7(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable7", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);
						}
						else {
							MessageBox::Show("False");
						}
					}
				}

				if (move == 8) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable8(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable8", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);
						}
						else {
							MessageBox::Show("False");
						}
					}
				}

				if (move == 9) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable9(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable9", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);
						}
						else {
							MessageBox::Show("False");
						}
					}
				}

				if (move == 10) {

					for (int i = 0; i < dgv_bill_table->Rows->Count; i++) {
						SqlCommand^ cmd_add = gcnew SqlCommand(
							"insert into BillTable10(Name, Price, Amount,Total) values(@Name, @Price, @Amount,@Total) ", conect);

						cmd_add->Parameters->AddWithValue("@Name", dgv_bill_table->Rows[i]->Cells[0]->Value);
						cmd_add->Parameters->AddWithValue("@Price", dgv_bill_table->Rows[i]->Cells[1]->Value);
						cmd_add->Parameters->AddWithValue("@Amount", dgv_bill_table->Rows[i]->Cells[2]->Value);
						cmd_add->Parameters->AddWithValue("@Total", dgv_bill_table->Rows[i]->Cells[3]->Value);

						if (cmd_add->ExecuteNonQuery() > 0) {

							SqlCommand^ cmd_add = gcnew SqlCommand("SELECT * FROM BillTable10", conect);
							SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd_add);
							DataTable^ data = gcnew DataTable();
							adap_table1->Fill(data);
						}
						else {
							MessageBox::Show("False");
						}
					}
				}
#pragma endregion

				MessageBox::Show(L"Chuyển bàn thành công");

#pragma region delete table


				if (id == 1) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable1 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
				else if (id == 2) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable2 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
				else if (id == 3) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable3 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
				else if (id == 4) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable4 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
				else if (id == 5) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable5 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
				else if (id == 6) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable6 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
				else if (id == 7) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable7 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;

				}
				else if (id == 8) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable8 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
				else if (id == 9) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable9 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
				else if (id == 10) {
					SqlCommand^ cmd_remove = gcnew SqlCommand("delete from BillTable10 ", conect);
					SqlDataAdapter^ adap_remove = gcnew SqlDataAdapter(cmd_remove);
					DataTable^ data = gcnew DataTable();
					adap_remove->Fill(data);
					this->dgv_bill_table->DataSource = data;
				}
#pragma endregion

			}
		}
	}

	private: System::Void cbx_move_table_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void dgv_Menu__CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		int index = e->RowIndex;
		DataGridViewRow^ data = dgv_Menu_->Rows[index];

		tbx_drink_name_->Text = data->Cells[0]->Value->ToString();
		tbx_price_drink->Text = data->Cells[1]->Value->ToString();
		tbx_total_drink_->Text = data->Cells[1]->Value->ToString();
		tbx_ID_drink->Text = data->Cells[2]->Value->ToString();
		number_->Value = 1;

	}
	public: System::Void dgv_bill_table_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		int index = e->RowIndex;
		DataGridViewRow^ data = dgv_bill_table->Rows[index];

		tbx_drink_->Text = data->Cells[0]->Value->ToString();
		tbx_ID_drink->Text = data->Cells[3]->Value->ToString();

	}
		   
	private: System::Void adminToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Login_Admin^ login_admin = gcnew Login_Admin();

		this->Hide();
		login_admin->ShowDialog();
		this->Show();
		
	}

};
}