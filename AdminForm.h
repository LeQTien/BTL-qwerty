#pragma once

namespace BTL_OOP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SqlClient;


	/// <summary>
	/// Summary for AdminForm
	/// </summary>
	public ref class AdminForm : public System::Windows::Forms::Form
	{
		SqlConnection^ conect = gcnew SqlConnection("Data Source=.\\SQLEXPRESS;Initial Catalog=BTL_Data;Integrated Security=True");
	public:
		AdminForm(void)
		{
			conect->Open();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			SqlCommand^ cmd_menu = gcnew  SqlCommand(" SELECT * FROM Menu", conect);
			SqlDataAdapter^ adap_menu = gcnew SqlDataAdapter(cmd_menu);
			DataTable^ data_menu = gcnew DataTable();
			adap_menu->Fill(data_menu);
			this->dgv_menu_admin->DataSource = data_menu;

			SqlCommand^ cmd_staff = gcnew  SqlCommand(" SELECT * FROM Account", conect);
			SqlDataAdapter^ adap_staff = gcnew SqlDataAdapter(cmd_staff);
			DataTable^ data_staff = gcnew DataTable();
			adap_staff->Fill(data_staff);
			this->dgv_admin_staff->DataSource = data_staff;


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tab_staff;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::DataGridView^ dgv_menu_admin;
	private: System::Windows::Forms::Button^ admin_remove_menu;
	private: System::Windows::Forms::Button^ admin_add_menu;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbx_price_;

	private: System::Windows::Forms::TextBox^ tbx_name_;
	private: System::Windows::Forms::Label^ back_;
	private: System::Windows::Forms::Button^ btn_edit;

	private: System::Windows::Forms::TextBox^ tbx_ID;



	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lable;
	private: System::Windows::Forms::TextBox^ tbx_staff_pass;

	private: System::Windows::Forms::TextBox^ tbx_staff_namelogin;

	private: System::Windows::Forms::TextBox^ tbx_IDStaff;

	private: System::Windows::Forms::TextBox^ tbx_SDT;

	private: System::Windows::Forms::TextBox^ tbx_fullname_staff;
	private: System::Windows::Forms::DataGridView^ dgv_admin_staff;
	private: System::Windows::Forms::Button^ btn_staff_edit;
	private: System::Windows::Forms::Button^ btn_staff_remove;
	private: System::Windows::Forms::Button^ btn_staff_add;
	private: System::Windows::Forms::Button^ btn_refresh;
	private: System::Windows::Forms::Button^ btn_refresh_;
	private: System::Windows::Forms::Button^ btn_back;
	private: System::Windows::Forms::Label^ label3;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tab_staff = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btn_back = (gcnew System::Windows::Forms::Button());
			this->btn_refresh = (gcnew System::Windows::Forms::Button());
			this->btn_staff_edit = (gcnew System::Windows::Forms::Button());
			this->btn_staff_remove = (gcnew System::Windows::Forms::Button());
			this->btn_staff_add = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lable = (gcnew System::Windows::Forms::Label());
			this->tbx_staff_pass = (gcnew System::Windows::Forms::TextBox());
			this->tbx_staff_namelogin = (gcnew System::Windows::Forms::TextBox());
			this->tbx_IDStaff = (gcnew System::Windows::Forms::TextBox());
			this->tbx_SDT = (gcnew System::Windows::Forms::TextBox());
			this->tbx_fullname_staff = (gcnew System::Windows::Forms::TextBox());
			this->dgv_admin_staff = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btn_refresh_ = (gcnew System::Windows::Forms::Button());
			this->tbx_ID = (gcnew System::Windows::Forms::TextBox());
			this->btn_edit = (gcnew System::Windows::Forms::Button());
			this->back_ = (gcnew System::Windows::Forms::Label());
			this->admin_remove_menu = (gcnew System::Windows::Forms::Button());
			this->admin_add_menu = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbx_price_ = (gcnew System::Windows::Forms::TextBox());
			this->tbx_name_ = (gcnew System::Windows::Forms::TextBox());
			this->dgv_menu_admin = (gcnew System::Windows::Forms::DataGridView());
			this->tab_staff->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_admin_staff))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_menu_admin))->BeginInit();
			this->SuspendLayout();
			// 
			// tab_staff
			// 
			this->tab_staff->Controls->Add(this->tabPage1);
			this->tab_staff->Controls->Add(this->tabPage2);
			this->tab_staff->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tab_staff->Location = System::Drawing::Point(2, 12);
			this->tab_staff->Name = L"tab_staff";
			this->tab_staff->SelectedIndex = 0;
			this->tab_staff->Size = System::Drawing::Size(1073, 635);
			this->tab_staff->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->btn_back);
			this->tabPage1->Controls->Add(this->btn_refresh);
			this->tabPage1->Controls->Add(this->btn_staff_edit);
			this->tabPage1->Controls->Add(this->btn_staff_remove);
			this->tabPage1->Controls->Add(this->btn_staff_add);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->lable);
			this->tabPage1->Controls->Add(this->tbx_staff_pass);
			this->tabPage1->Controls->Add(this->tbx_staff_namelogin);
			this->tabPage1->Controls->Add(this->tbx_IDStaff);
			this->tabPage1->Controls->Add(this->tbx_SDT);
			this->tabPage1->Controls->Add(this->tbx_fullname_staff);
			this->tabPage1->Controls->Add(this->dgv_admin_staff);
			this->tabPage1->Location = System::Drawing::Point(4, 35);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1065, 596);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Quản lí nhân viên";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btn_back
			// 
			this->btn_back->Location = System::Drawing::Point(949, 21);
			this->btn_back->Name = L"btn_back";
			this->btn_back->Size = System::Drawing::Size(110, 40);
			this->btn_back->TabIndex = 16;
			this->btn_back->Text = L"Quay lại";
			this->btn_back->UseVisualStyleBackColor = true;
			this->btn_back->Click += gcnew System::EventHandler(this, &AdminForm::btn_back_Click);
			// 
			// btn_refresh
			// 
			this->btn_refresh->Location = System::Drawing::Point(801, 21);
			this->btn_refresh->Name = L"btn_refresh";
			this->btn_refresh->Size = System::Drawing::Size(110, 40);
			this->btn_refresh->TabIndex = 15;
			this->btn_refresh->Text = L"Refresh";
			this->btn_refresh->UseVisualStyleBackColor = true;
			this->btn_refresh->Click += gcnew System::EventHandler(this, &AdminForm::button1_Click);
			// 
			// btn_staff_edit
			// 
			this->btn_staff_edit->Location = System::Drawing::Point(738, 485);
			this->btn_staff_edit->Name = L"btn_staff_edit";
			this->btn_staff_edit->Size = System::Drawing::Size(103, 77);
			this->btn_staff_edit->TabIndex = 14;
			this->btn_staff_edit->Text = L"Sửa";
			this->btn_staff_edit->UseVisualStyleBackColor = true;
			this->btn_staff_edit->Click += gcnew System::EventHandler(this, &AdminForm::btn_staff_edit_Click);
			// 
			// btn_staff_remove
			// 
			this->btn_staff_remove->Location = System::Drawing::Point(885, 485);
			this->btn_staff_remove->Name = L"btn_staff_remove";
			this->btn_staff_remove->Size = System::Drawing::Size(103, 77);
			this->btn_staff_remove->TabIndex = 13;
			this->btn_staff_remove->Text = L"Xóa";
			this->btn_staff_remove->UseVisualStyleBackColor = true;
			this->btn_staff_remove->Click += gcnew System::EventHandler(this, &AdminForm::btn_staff_remove_Click);
			// 
			// btn_staff_add
			// 
			this->btn_staff_add->Location = System::Drawing::Point(586, 485);
			this->btn_staff_add->Name = L"btn_staff_add";
			this->btn_staff_add->Size = System::Drawing::Size(103, 77);
			this->btn_staff_add->TabIndex = 12;
			this->btn_staff_add->Text = L"Thêm";
			this->btn_staff_add->UseVisualStyleBackColor = true;
			this->btn_staff_add->Click += gcnew System::EventHandler(this, &AdminForm::btn_staff_add_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(562, 196);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(75, 32);
			this->label8->TabIndex = 11;
			this->label8->Text = L"SDT:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(562, 417);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(189, 32);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Mã nhân viên:";
			this->label7->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(562, 343);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(140, 32);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Mật khẩu:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(562, 265);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(205, 32);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Tên đăng nhập:";
			// 
			// lable
			// 
			this->lable->AutoSize = true;
			this->lable->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lable->Location = System::Drawing::Point(562, 125);
			this->lable->Name = L"lable";
			this->lable->Size = System::Drawing::Size(103, 32);
			this->lable->TabIndex = 7;
			this->lable->Text = L"Họ tên:";
			// 
			// tbx_staff_pass
			// 
			this->tbx_staff_pass->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_staff_pass->Location = System::Drawing::Point(783, 340);
			this->tbx_staff_pass->Name = L"tbx_staff_pass";
			this->tbx_staff_pass->Size = System::Drawing::Size(231, 39);
			this->tbx_staff_pass->TabIndex = 6;
			// 
			// tbx_staff_namelogin
			// 
			this->tbx_staff_namelogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_staff_namelogin->Location = System::Drawing::Point(783, 262);
			this->tbx_staff_namelogin->Name = L"tbx_staff_namelogin";
			this->tbx_staff_namelogin->Size = System::Drawing::Size(231, 39);
			this->tbx_staff_namelogin->TabIndex = 5;
			// 
			// tbx_IDStaff
			// 
			this->tbx_IDStaff->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_IDStaff->Location = System::Drawing::Point(783, 410);
			this->tbx_IDStaff->Name = L"tbx_IDStaff";
			this->tbx_IDStaff->ReadOnly = true;
			this->tbx_IDStaff->Size = System::Drawing::Size(231, 39);
			this->tbx_IDStaff->TabIndex = 4;
			this->tbx_IDStaff->Visible = false;
			this->tbx_IDStaff->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AdminForm::tbx_IDStaff_KeyDown);
			// 
			// tbx_SDT
			// 
			this->tbx_SDT->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_SDT->Location = System::Drawing::Point(783, 193);
			this->tbx_SDT->Name = L"tbx_SDT";
			this->tbx_SDT->Size = System::Drawing::Size(231, 39);
			this->tbx_SDT->TabIndex = 3;
			this->tbx_SDT->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AdminForm::tbx_SDT_KeyDown);
			// 
			// tbx_fullname_staff
			// 
			this->tbx_fullname_staff->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_fullname_staff->Location = System::Drawing::Point(783, 122);
			this->tbx_fullname_staff->Name = L"tbx_fullname_staff";
			this->tbx_fullname_staff->Size = System::Drawing::Size(231, 39);
			this->tbx_fullname_staff->TabIndex = 2;
			// 
			// dgv_admin_staff
			// 
			this->dgv_admin_staff->AllowUserToAddRows = false;
			this->dgv_admin_staff->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dgv_admin_staff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_admin_staff->GridColor = System::Drawing::SystemColors::ButtonFace;
			this->dgv_admin_staff->Location = System::Drawing::Point(24, 122);
			this->dgv_admin_staff->Name = L"dgv_admin_staff";
			this->dgv_admin_staff->RowHeadersWidth = 51;
			this->dgv_admin_staff->RowTemplate->Height = 24;
			this->dgv_admin_staff->Size = System::Drawing::Size(505, 454);
			this->dgv_admin_staff->TabIndex = 1;
			this->dgv_admin_staff->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AdminForm::dgv_admin_staff_CellClick);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->btn_refresh_);
			this->tabPage2->Controls->Add(this->tbx_ID);
			this->tabPage2->Controls->Add(this->btn_edit);
			this->tabPage2->Controls->Add(this->back_);
			this->tabPage2->Controls->Add(this->admin_remove_menu);
			this->tabPage2->Controls->Add(this->admin_add_menu);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Controls->Add(this->tbx_price_);
			this->tabPage2->Controls->Add(this->tbx_name_);
			this->tabPage2->Controls->Add(this->dgv_menu_admin);
			this->tabPage2->Location = System::Drawing::Point(4, 35);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1065, 596);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Quản lí danh sách món ";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(540, 311);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 32);
			this->label3->TabIndex = 17;
			this->label3->Text = L"ID:";
			this->label3->Visible = false;
			// 
			// btn_refresh_
			// 
			this->btn_refresh_->Location = System::Drawing::Point(934, 20);
			this->btn_refresh_->Name = L"btn_refresh_";
			this->btn_refresh_->Size = System::Drawing::Size(110, 40);
			this->btn_refresh_->TabIndex = 16;
			this->btn_refresh_->Text = L"Refresh";
			this->btn_refresh_->UseVisualStyleBackColor = true;
			this->btn_refresh_->Click += gcnew System::EventHandler(this, &AdminForm::btn_refresh__Click);
			// 
			// tbx_ID
			// 
			this->tbx_ID->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_ID->Location = System::Drawing::Point(735, 304);
			this->tbx_ID->Name = L"tbx_ID";
			this->tbx_ID->ReadOnly = true;
			this->tbx_ID->Size = System::Drawing::Size(231, 39);
			this->tbx_ID->TabIndex = 9;
			this->tbx_ID->Visible = false;
			this->tbx_ID->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AdminForm::tbx_ID_KeyDown);
			// 
			// btn_edit
			// 
			this->btn_edit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_edit->Location = System::Drawing::Point(902, 365);
			this->btn_edit->Name = L"btn_edit";
			this->btn_edit->Size = System::Drawing::Size(142, 71);
			this->btn_edit->TabIndex = 8;
			this->btn_edit->Text = L"Sửa món";
			this->btn_edit->UseVisualStyleBackColor = true;
			this->btn_edit->Click += gcnew System::EventHandler(this, &AdminForm::btn_edit_Click);
			// 
			// back_
			// 
			this->back_->AutoSize = true;
			this->back_->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->back_->Location = System::Drawing::Point(603, 543);
			this->back_->Name = L"back_";
			this->back_->Size = System::Drawing::Size(379, 33);
			this->back_->TabIndex = 7;
			this->back_->Text = L"Nhấn vào đây để trở về trang chủ";
			this->back_->Click += gcnew System::EventHandler(this, &AdminForm::back__Click);
			// 
			// admin_remove_menu
			// 
			this->admin_remove_menu->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->admin_remove_menu->Location = System::Drawing::Point(716, 365);
			this->admin_remove_menu->Name = L"admin_remove_menu";
			this->admin_remove_menu->Size = System::Drawing::Size(142, 71);
			this->admin_remove_menu->TabIndex = 6;
			this->admin_remove_menu->Text = L"Xóa";
			this->admin_remove_menu->UseVisualStyleBackColor = true;
			this->admin_remove_menu->Click += gcnew System::EventHandler(this, &AdminForm::admin_remove_menu_Click);
			// 
			// admin_add_menu
			// 
			this->admin_add_menu->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->admin_add_menu->Location = System::Drawing::Point(526, 365);
			this->admin_add_menu->Name = L"admin_add_menu";
			this->admin_add_menu->Size = System::Drawing::Size(142, 71);
			this->admin_add_menu->TabIndex = 5;
			this->admin_add_menu->Text = L"Thêm";
			this->admin_add_menu->UseVisualStyleBackColor = true;
			this->admin_add_menu->Click += gcnew System::EventHandler(this, &AdminForm::admin_add_menu_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(540, 242);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 32);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Đơn giá:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(540, 166);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 32);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Tên món:";
			// 
			// tbx_price_
			// 
			this->tbx_price_->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_price_->Location = System::Drawing::Point(735, 239);
			this->tbx_price_->Name = L"tbx_price_";
			this->tbx_price_->Size = System::Drawing::Size(231, 39);
			this->tbx_price_->TabIndex = 2;
			this->tbx_price_->TextChanged += gcnew System::EventHandler(this, &AdminForm::tbx_price__TextChanged);
			this->tbx_price_->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AdminForm::tbx_price__KeyDown);
			// 
			// tbx_name_
			// 
			this->tbx_name_->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbx_name_->Location = System::Drawing::Point(735, 163);
			this->tbx_name_->Name = L"tbx_name_";
			this->tbx_name_->Size = System::Drawing::Size(231, 39);
			this->tbx_name_->TabIndex = 1;
			// 
			// dgv_menu_admin
			// 
			this->dgv_menu_admin->AllowUserToAddRows = false;
			this->dgv_menu_admin->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dgv_menu_admin->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_menu_admin->GridColor = System::Drawing::SystemColors::ButtonFace;
			this->dgv_menu_admin->Location = System::Drawing::Point(6, 50);
			this->dgv_menu_admin->Name = L"dgv_menu_admin";
			this->dgv_menu_admin->ReadOnly = true;
			this->dgv_menu_admin->RowHeadersWidth = 51;
			this->dgv_menu_admin->RowTemplate->Height = 24;
			this->dgv_menu_admin->Size = System::Drawing::Size(505, 526);
			this->dgv_menu_admin->TabIndex = 0;
			this->dgv_menu_admin->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AdminForm::dgv_menu_admin_CellClick);
			this->dgv_menu_admin->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AdminForm::dataGridView1_CellContentClick);
			// 
			// AdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1098, 684);
			this->Controls->Add(this->tab_staff);
			this->Name = L"AdminForm";
			this->Text = L"AdminForm";
			this->tab_staff->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_admin_staff))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_menu_admin))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {



	}

	private: System::Void admin_add_menu_Click(System::Object^ sender, System::EventArgs^ e) {

	
		if (tbx_name_->Text == "" || tbx_price_->Text == "") {
			MessageBox::Show(L"Vui lòng nhập đủ dữ liệu", L"Lỗi", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
		}
		
		else {
				if (MessageBox::Show("Thêm món " + tbx_name_->Text + " vào Menu", "Thông báo", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
		
					int id = dgv_menu_admin->Rows->Count + 1;
					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into Menu(Name, Price, ID) values(@Name, @Price,@ID) ", conect);

					cmd_add->Parameters->AddWithValue("@Name", this->tbx_name_->Text);
					cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_->Text));
					cmd_add->Parameters->AddWithValue("@ID", id);

					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Đã cập nhật menu");

						SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Menu", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_menu_admin->DataSource = data;
						tbx_ID->Clear();
						tbx_name_->Clear();
						tbx_price_->Clear();
						

					}
					else {
						MessageBox::Show(L"Thêm thất bại");
					}
				}
			
			}
		/*	for (int i = 0; i <= dgv_menu_admin->Rows->Count; i++) {

				if (Convert::ToInt32(tbx_ID->Text) == Convert::ToInt32(dgv_menu_admin->Rows[i]->Cells[2]->Value) || tbx_name_->Text == dgv_menu_admin->Rows[i]->Cells[0]->Value->ToString()) {
					MessageBox::Show(L"Lỗi trùng món", L"Lỗi", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
					break;
				}

				else {

						if (MessageBox::Show("Thêm món " + tbx_name_->Text + " vào Menu", "Thông báo", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {


							int id = Convert::ToInt32(tbx_ID->Text);
							SqlCommand^ cmd_add = gcnew SqlCommand(
								"insert into Menu(Name, Price, ID) values(@Name, @Price,@ID) ", conect);

							cmd_add->Parameters->AddWithValue("@Name", this->tbx_name_->Text);
							cmd_add->Parameters->AddWithValue("@Price", Convert::ToInt32(tbx_price_->Text));
							cmd_add->Parameters->AddWithValue("@ID", id);

							if (cmd_add->ExecuteNonQuery() > 0) {
								MessageBox::Show(L"Đã cập nhật menu");

								SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Menu", conect);
								SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd);
								DataTable^ data = gcnew DataTable();
								adap_table1->Fill(data);
								this->dgv_menu_admin->DataSource = data;
								tbx_ID->Clear();
								tbx_name_->Clear();
								tbx_price_->Clear();
								break;

							}
							else {
								MessageBox::Show(L"Thêm thất bại");
							}
							break;
						}
						

					}
				}
			*/
			}
	

private: System::Void back__Click(System::Object^ sender, System::EventArgs^ e) {
		
	this->Hide();
	

}
 
private: System::Void admin_remove_menu_Click(System::Object^ sender, System::EventArgs^ e) {
	if (tbx_name_->Text == "" || tbx_price_->Text == "") {
		MessageBox::Show(L"Vui lòng nhập đủ dữ liệu", L"Lỗi", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
	}
	else {
		if (MessageBox::Show(L"Xóa món " + tbx_name_->Text + L" khỏi Menu", L"Thông báo", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			int id = Convert::ToInt32(tbx_ID->Text);

			SqlCommand^ cmd = gcnew SqlCommand("delete from Menu  where [ID]='" + id + "' ", conect);
			if (cmd->ExecuteNonQuery() > 0) {
				MessageBox::Show(L"Xóa món thành công");
				SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Menu", conect);
				SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd);
				DataTable^ data = gcnew DataTable();
				adap_table1->Fill(data);
				this->dgv_menu_admin->DataSource = data;
				tbx_name_->Clear();
				tbx_price_->Clear();
				tbx_ID->Clear();
			}
			else {
				MessageBox::Show(L"Xóa món thất bại");

			}
		}
	}

}


private: System::Void dgv_menu_admin_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	int index = e->RowIndex;
	DataGridViewRow^ data = dgv_menu_admin->Rows[index];

	tbx_name_->Text = data->Cells[0]->Value->ToString();
	tbx_price_->Text = data->Cells[1]->Value->ToString();
	tbx_ID->Text = data->Cells[2]->Value->ToString();

}

private: System::Void btn_edit_Click(System::Object^ sender, System::EventArgs^ e) {

	if (MessageBox::Show(L"Bạn có muốn sửa món", L"Thông báo", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
		
		for (int i = 0; i < dgv_menu_admin->Rows->Count; i++) {
			
			if (tbx_ID->Text == dgv_menu_admin->Rows[i]->Cells[2]->Value->ToString()|| tbx_name_->Text == dgv_menu_admin->Rows[i]->Cells[0]->Value->ToString()) {
				MessageBox::Show(L"Lỗi trùng ID", L"Lỗi", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
			}
			else {
				int id = Convert::ToInt32(tbx_ID->Text);
				int price = Convert::ToInt32(tbx_price_->Text);

				SqlCommand^ cmd = gcnew SqlCommand("UPDATE Menu set Name = @name, Price = @price where ID='" + id + "'  ", conect);
				cmd->Parameters->AddWithValue("@name", tbx_name_->Text);
				cmd->Parameters->AddWithValue("@price", price);

				if (cmd->ExecuteNonQuery() > 0) {
					MessageBox::Show(L"Sửa món thành công");

					SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Menu", conect);
					SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd);
					DataTable^ data = gcnew DataTable();
					adap_table1->Fill(data);
					this->dgv_menu_admin->DataSource = data;
					tbx_name_->Clear();
					tbx_price_->Clear();
					tbx_ID->Clear();
				}
				else {
					MessageBox::Show(L"Sửa món thất bại");

				}
			}
			break;
		
		
		}

	
	}

}
private: System::Void tbx_ID_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (!((e->KeyCode >= Keys::NumPad0 && e->KeyCode <= Keys::NumPad9) ||

		((e->KeyCode >= Keys::D0 && e->KeyCode <= Keys::D9) && (!e->Shift)) ||

		e->KeyCode == Keys::Back || e->KeyCode == Keys::Delete || e->KeyCode ==

		Keys::Alt || e->KeyCode == Keys::Left || e->KeyCode == Keys::Right ||

		e->KeyCode == Keys::Shift || e->KeyCode == Keys::Home || e->KeyCode ==

		Keys::End || e->KeyCode == Keys::Decimal))

		e->SuppressKeyPress = true;
	
}
private: System::Void tbx_price__KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	if (!((e->KeyCode >= Keys::NumPad0 && e->KeyCode <= Keys::NumPad9) ||

		((e->KeyCode >= Keys::D0 && e->KeyCode <= Keys::D9) && (!e->Shift)) ||

		e->KeyCode == Keys::Back || e->KeyCode == Keys::Delete || e->KeyCode ==

		Keys::Alt || e->KeyCode == Keys::Left || e->KeyCode == Keys::Right ||

		e->KeyCode == Keys::Shift || e->KeyCode == Keys::Home || e->KeyCode ==

		Keys::End || e->KeyCode == Keys::Decimal))

		e->SuppressKeyPress = true;

}




private: System::Void tbx_search_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
	
}
private: System::Void dgv_admin_staff_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	int index = e->RowIndex;
	DataGridViewRow^ data = dgv_admin_staff->Rows[index];

	tbx_fullname_staff->Text = data->Cells[0]->Value->ToString();
	tbx_SDT->Text = data->Cells[1]->Value->ToString();
	tbx_IDStaff->Text = data->Cells[2]->Value->ToString();
	tbx_staff_namelogin->Text = data->Cells[3]->Value->ToString();
	tbx_staff_pass->Text = data->Cells[4]->Value->ToString();


}
private: System::Void btn_staff_add_Click(System::Object^ sender, System::EventArgs^ e) {
	int id = dgv_admin_staff->Rows->Count;
	int idstaff = 1000 + id + 1;
	if (tbx_fullname_staff->Text == "" || tbx_IDStaff->Text == ""||tbx_SDT->Text==""||tbx_staff_namelogin->Text==""||tbx_staff_pass->Text=="") {
		MessageBox::Show(L"Vui lòng nhập đủ dữ liệu", L"Lỗi", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
	}
	else {

			for (int i = 0; i < dgv_admin_staff->Rows->Count; i++) {
				if (tbx_IDStaff->Text == dgv_admin_staff->Rows[i]->Cells[2]->Value->ToString()|| tbx_SDT->Text == dgv_admin_staff->Rows[i]->Cells[1]->Value->ToString()|| tbx_staff_namelogin->Text == dgv_admin_staff->Rows[i]->Cells[3]->Value->ToString()) {
					MessageBox::Show(L"Lỗi trùng  thông tin nhân viên", L"Thông báo", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
				}
				else {

				
					SqlCommand^ cmd_add = gcnew SqlCommand(
						"insert into Account(FullName, SDT, IDStaff, Username, Password) values(@FullName, @SDT, @IDStaff, @Username, @Password) ", conect);

					cmd_add->Parameters->AddWithValue("@FullName", this->tbx_fullname_staff->Text);
					cmd_add->Parameters->AddWithValue("@SDT", Convert::ToInt32(tbx_SDT->Text));
					cmd_add->Parameters->AddWithValue("@IDStaff", idstaff);
					cmd_add->Parameters->AddWithValue("@Username ", this->tbx_staff_namelogin->Text);
					cmd_add->Parameters->AddWithValue("@Password", this->tbx_staff_pass->Text);

					if (cmd_add->ExecuteNonQuery() > 0) {
						MessageBox::Show(L"Thêm nhân viên thành công");

						SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Account", conect);
						SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd);
						DataTable^ data = gcnew DataTable();
						adap_table1->Fill(data);
						this->dgv_admin_staff->DataSource = data;
						tbx_fullname_staff->Clear();
						tbx_SDT->Clear();
						tbx_IDStaff->Clear();
						tbx_staff_namelogin->Clear();
						tbx_staff_pass->Clear();
					}
					else {
						MessageBox::Show(L"Thêm nhân viên thất bại");

					}
				
				}
				break;
				
			}

		
		
	}

}
private: System::Void tbx_price__TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbx_SDT_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	if (!((e->KeyCode >= Keys::NumPad0 && e->KeyCode <= Keys::NumPad9) ||

		((e->KeyCode >= Keys::D0 && e->KeyCode <= Keys::D9) && (!e->Shift)) ||

		e->KeyCode == Keys::Back || e->KeyCode == Keys::Delete || e->KeyCode ==

		Keys::Alt || e->KeyCode == Keys::Left || e->KeyCode == Keys::Right ||

		e->KeyCode == Keys::Shift || e->KeyCode == Keys::Home || e->KeyCode ==

		Keys::End || e->KeyCode == Keys::Decimal))

		e->SuppressKeyPress = true;
}
private: System::Void tbx_IDStaff_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	if (!((e->KeyCode >= Keys::NumPad0 && e->KeyCode <= Keys::NumPad9) ||

		((e->KeyCode >= Keys::D0 && e->KeyCode <= Keys::D9) && (!e->Shift)) ||

		e->KeyCode == Keys::Back || e->KeyCode == Keys::Delete || e->KeyCode ==

		Keys::Alt || e->KeyCode == Keys::Left || e->KeyCode == Keys::Right ||

		e->KeyCode == Keys::Shift || e->KeyCode == Keys::Home || e->KeyCode ==

		Keys::End || e->KeyCode == Keys::Decimal))

		e->SuppressKeyPress = true;
}
private: System::Void btn_staff_edit_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
	if (tbx_fullname_staff->Text == "" || tbx_IDStaff->Text == "" || tbx_SDT->Text == "" || tbx_staff_namelogin->Text == "" || tbx_staff_pass->Text == "") {
		MessageBox::Show(L"Vui lòng nhập đủ dữ liệu", L"Lỗi", MessageBoxButtons::OKCancel, MessageBoxIcon::Error);
	}
	else {

		int id = Convert::ToInt32(tbx_IDStaff->Text);
		//	int price = Convert::ToInt32(tbx_price_->Text);

		SqlCommand^ cmd = gcnew SqlCommand("UPDATE Account set FullName = @fullname, SDT = @sdt, IDStaff=@idstaff, Username =@username, Password=@password where IDStaff='" + id + "'  ", conect);

		cmd->Parameters->AddWithValue("@fullname", tbx_fullname_staff->Text);
		cmd->Parameters->AddWithValue("@sdt", Convert::ToInt32(tbx_SDT->Text));
		cmd->Parameters->AddWithValue("@idstaff", Convert::ToInt32(tbx_IDStaff->Text));
		cmd->Parameters->AddWithValue("@username ", tbx_staff_namelogin->Text);
		cmd->Parameters->AddWithValue("@password", tbx_staff_pass->Text);


		if (cmd->ExecuteNonQuery() > 0) {
			MessageBox::Show(L"Cập nhật thông tin nhân viên thành công");

			SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Account", conect);
			SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd);
			DataTable^ data = gcnew DataTable();
			adap_table1->Fill(data);
			this->dgv_admin_staff->DataSource = data;

			tbx_fullname_staff->Clear();
			tbx_SDT->Clear();
			tbx_IDStaff->Clear();
			tbx_staff_namelogin->Clear();
			tbx_staff_pass->Clear();
		}
		else {
			MessageBox::Show(L"Cập nhật thông tin nhân viên thất bại");

		}

	}
}
private: System::Void btn_staff_remove_Click(System::Object^ sender, System::EventArgs^ e) {

	if (tbx_IDStaff->Text == "" || tbx_staff_namelogin->Text == "") {
		MessageBox::Show(L"Vui lòng nhập mã và tên của nhân viên", L"Thông báo", MessageBoxButtons::OKCancel, MessageBoxIcon::Information);


	}
	else {

		int id = Convert::ToInt32(tbx_IDStaff->Text);

		SqlCommand^ cmd = gcnew SqlCommand("delete from Account  where [IDStaff]='" + id + " ' ", conect);
		if (cmd->ExecuteNonQuery() > 0) {
			MessageBox::Show(L"Xóa nhân viên thành công");

			SqlCommand^ cmd = gcnew SqlCommand("SELECT * FROM Account", conect);
			SqlDataAdapter^ adap_table1 = gcnew SqlDataAdapter(cmd);
			DataTable^ data = gcnew DataTable();
			adap_table1->Fill(data);
			this->dgv_admin_staff->DataSource = data;


			tbx_SDT->Visible = true;
			tbx_staff_namelogin->Visible = true;
			tbx_staff_pass->Visible = true;

			tbx_fullname_staff->Clear();
			tbx_SDT->Clear();
			tbx_IDStaff->Clear();
			tbx_staff_namelogin->Clear();
			tbx_staff_pass->Clear();

		}
		else {
			MessageBox::Show(L"Xóa nhân viên thất bại");

		}
	}


}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	tbx_fullname_staff->Clear();
	tbx_SDT->Clear();
	tbx_IDStaff->Clear();
	tbx_staff_namelogin->Clear();
	tbx_staff_pass->Clear();
}
private: System::Void btn_refresh__Click(System::Object^ sender, System::EventArgs^ e) {
	tbx_name_->Clear();
	tbx_ID->Clear();
	tbx_price_->Clear();
}
private: System::Void btn_back_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
