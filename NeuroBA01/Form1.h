#include "InsertAlbumForm.h"
#include "TrainNeuralMusic.h"
#include "RecognizeForm.h"
#include <fann.h>

#pragma once

namespace NeuroBA01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		InsertAlbumForm ^ insert;
		TrainNeuralMusic^ train;
		RecognizeForm^ recognize;

		fann *brain;
		fann_train_data *data;
		array<float,2> ^inputs, ^outputs;		

		array<String^,1>^ names;
		array<String^,1>^ artists;
		array<Bitmap^,1>^ pictures;
		array<int,1>^ years;
		
		static const int width = 7, height = 7, num_data = 10;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			if(!brain){

				//total layer, input(pixel size), [hidden], output)
				brain = fann_create_standard(3,width*height,2,num_data);

			}

			fann_set_activation_function_layer(brain, FANN_SIGMOID_STEPWISE,1);
			fann_set_activation_function_hidden(brain, FANN_SIGMOID_STEPWISE);
			fann_set_activation_function_output(brain, FANN_SIGMOID_STEPWISE);
				 
			data = (fann_train_data*) malloc(sizeof(fann_train_data));
			data->num_data = num_data; data->num_input = width*height; data->num_output = num_data;
			data->input = (fann_type**) calloc(num_data, sizeof(sizeof(fann_type*)));
			data->output = (fann_type**) calloc(num_data, sizeof(sizeof(fann_type*)));

			inputs = gcnew array<float,2>(num_data,width*height);
			outputs = gcnew array<float,2>(num_data,num_data);
			names = gcnew array<String^,1>(num_data);
			artists = gcnew array<String^,1>(num_data);
			pictures = gcnew array<Bitmap^,1>(num_data);
			years = gcnew array<int,1>(num_data);

//			data_count = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  logoPictureBox;
	private: System::Windows::Forms::PictureBox^  speakerPictureBox;
	protected: 

	private: System::Windows::Forms::Label^  timeLabel;
	private: System::Windows::Forms::Label^  percentLabel;
	private: System::Windows::Forms::Panel^  batteryPanel;
	private: System::Windows::Forms::Button^  backButton;
	private: System::Windows::Forms::Button^  homeButton;
	private: System::Windows::Forms::Button^  optionButton;
	private: System::Windows::Forms::PictureBox^  signalPictureBox;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  mainPanel;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  insertLabel;
	private: System::Windows::Forms::Button^  recognizeButton;

	private: System::Windows::Forms::Button^  trainButton;

	private: System::Windows::Forms::Button^  insertButton;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->logoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->speakerPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->percentLabel = (gcnew System::Windows::Forms::Label());
			this->batteryPanel = (gcnew System::Windows::Forms::Panel());
			this->signalPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->homeButton = (gcnew System::Windows::Forms::Button());
			this->optionButton = (gcnew System::Windows::Forms::Button());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->insertLabel = (gcnew System::Windows::Forms::Label());
			this->recognizeButton = (gcnew System::Windows::Forms::Button());
			this->trainButton = (gcnew System::Windows::Forms::Button());
			this->insertButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speakerPictureBox))->BeginInit();
			this->batteryPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->signalPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->mainPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// logoPictureBox
			// 
			this->logoPictureBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->logoPictureBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"logoPictureBox.BackgroundImage")));
			this->logoPictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->logoPictureBox->Location = System::Drawing::Point(83, 6);
			this->logoPictureBox->Name = L"logoPictureBox";
			this->logoPictureBox->Size = System::Drawing::Size(125, 60);
			this->logoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->logoPictureBox->TabIndex = 0;
			this->logoPictureBox->TabStop = false;
			// 
			// speakerPictureBox
			// 
			this->speakerPictureBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->speakerPictureBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"speakerPictureBox.BackgroundImage")));
			this->speakerPictureBox->Location = System::Drawing::Point(3, 3);
			this->speakerPictureBox->Name = L"speakerPictureBox";
			this->speakerPictureBox->Size = System::Drawing::Size(25, 25);
			this->speakerPictureBox->TabIndex = 0;
			this->speakerPictureBox->TabStop = false;
			// 
			// timeLabel
			// 
			this->timeLabel->AutoSize = true;
			this->timeLabel->BackColor = System::Drawing::SystemColors::ControlText;
			this->timeLabel->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->timeLabel->Location = System::Drawing::Point(158, 16);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(34, 13);
			this->timeLabel->TabIndex = 1;
			this->timeLabel->Text = L"13:57";
			// 
			// percentLabel
			// 
			this->percentLabel->AutoSize = true;
			this->percentLabel->BackColor = System::Drawing::SystemColors::ControlText;
			this->percentLabel->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->percentLabel->Location = System::Drawing::Point(232, 15);
			this->percentLabel->Name = L"percentLabel";
			this->percentLabel->Size = System::Drawing::Size(33, 13);
			this->percentLabel->TabIndex = 1;
			this->percentLabel->Text = L"100%";
			// 
			// batteryPanel
			// 
			this->batteryPanel->BackColor = System::Drawing::SystemColors::WindowText;
			this->batteryPanel->Controls->Add(this->percentLabel);
			this->batteryPanel->Controls->Add(this->timeLabel);
			this->batteryPanel->Controls->Add(this->signalPictureBox);
			this->batteryPanel->Controls->Add(this->speakerPictureBox);
			this->batteryPanel->Controls->Add(this->pictureBox1);
			this->batteryPanel->Location = System::Drawing::Point(0, 0);
			this->batteryPanel->Name = L"batteryPanel";
			this->batteryPanel->Size = System::Drawing::Size(291, 31);
			this->batteryPanel->TabIndex = 2;
			// 
			// signalPictureBox
			// 
			this->signalPictureBox->BackColor = System::Drawing::SystemColors::ControlText;
			this->signalPictureBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"signalPictureBox.BackgroundImage")));
			this->signalPictureBox->Location = System::Drawing::Point(198, 3);
			this->signalPictureBox->Name = L"signalPictureBox";
			this->signalPictureBox->Size = System::Drawing::Size(25, 25);
			this->signalPictureBox->TabIndex = 0;
			this->signalPictureBox->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::OliveDrab;
			this->pictureBox1->Location = System::Drawing::Point(260, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(20, 25);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// backButton
			// 
			this->backButton->BackColor = System::Drawing::SystemColors::ControlText;
			this->backButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"backButton.Image")));
			this->backButton->Location = System::Drawing::Point(52, 232);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(25, 25);
			this->backButton->TabIndex = 3;
			this->backButton->UseVisualStyleBackColor = false;
			this->backButton->Click += gcnew System::EventHandler(this, &Form1::backButton_Click);
			// 
			// homeButton
			// 
			this->homeButton->BackColor = System::Drawing::SystemColors::ControlText;
			this->homeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"homeButton.Image")));
			this->homeButton->Location = System::Drawing::Point(133, 232);
			this->homeButton->Name = L"homeButton";
			this->homeButton->Size = System::Drawing::Size(25, 25);
			this->homeButton->TabIndex = 3;
			this->homeButton->UseVisualStyleBackColor = false;
			// 
			// optionButton
			// 
			this->optionButton->BackColor = System::Drawing::SystemColors::ControlText;
			this->optionButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"optionButton.Image")));
			this->optionButton->Location = System::Drawing::Point(214, 232);
			this->optionButton->Name = L"optionButton";
			this->optionButton->Size = System::Drawing::Size(25, 25);
			this->optionButton->TabIndex = 3;
			this->optionButton->UseVisualStyleBackColor = false;
			// 
			// mainPanel
			// 
			this->mainPanel->BackColor = System::Drawing::SystemColors::ControlText;
			this->mainPanel->Controls->Add(this->logoPictureBox);
			this->mainPanel->Controls->Add(this->optionButton);
			this->mainPanel->Controls->Add(this->homeButton);
			this->mainPanel->Controls->Add(this->recognizeButton);
			this->mainPanel->Controls->Add(this->trainButton);
			this->mainPanel->Controls->Add(this->insertButton);
			this->mainPanel->Controls->Add(this->backButton);
			this->mainPanel->Controls->Add(this->insertLabel);
			this->mainPanel->Controls->Add(this->label1);
			this->mainPanel->Controls->Add(this->label2);
			this->mainPanel->Location = System::Drawing::Point(0, 31);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(290, 268);
			this->mainPanel->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->Location = System::Drawing::Point(20, 170);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Recognize Data";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(20, 128);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Train Neural Music";
			// 
			// insertLabel
			// 
			this->insertLabel->AutoSize = true;
			this->insertLabel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->insertLabel->Location = System::Drawing::Point(20, 86);
			this->insertLabel->Name = L"insertLabel";
			this->insertLabel->Size = System::Drawing::Size(91, 13);
			this->insertLabel->TabIndex = 4;
			this->insertLabel->Text = L"Insert Album Data";
			// 
			// recognizeButton
			// 
			this->recognizeButton->BackColor = System::Drawing::SystemColors::ControlText;
			this->recognizeButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->recognizeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"recognizeButton.Image")));
			this->recognizeButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->recognizeButton->Location = System::Drawing::Point(12, 156);
			this->recognizeButton->Name = L"recognizeButton";
			this->recognizeButton->Size = System::Drawing::Size(260, 40);
			this->recognizeButton->TabIndex = 3;
			this->recognizeButton->Text = L"Recognize Data";
			this->recognizeButton->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->recognizeButton->UseVisualStyleBackColor = false;
			this->recognizeButton->Click += gcnew System::EventHandler(this, &Form1::recognizeButton_Click);
			// 
			// trainButton
			// 
			this->trainButton->BackColor = System::Drawing::SystemColors::ControlText;
			this->trainButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->trainButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"trainButton.Image")));
			this->trainButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->trainButton->Location = System::Drawing::Point(12, 114);
			this->trainButton->Name = L"trainButton";
			this->trainButton->Size = System::Drawing::Size(260, 40);
			this->trainButton->TabIndex = 3;
			this->trainButton->Text = L"Train Neural Music";
			this->trainButton->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->trainButton->UseVisualStyleBackColor = false;
			this->trainButton->Click += gcnew System::EventHandler(this, &Form1::trainButton_Click);
			// 
			// insertButton
			// 
			this->insertButton->BackColor = System::Drawing::SystemColors::ControlText;
			this->insertButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->insertButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"insertButton.Image")));
			this->insertButton->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->insertButton->Location = System::Drawing::Point(12, 72);
			this->insertButton->Name = L"insertButton";
			this->insertButton->Size = System::Drawing::Size(260, 40);
			this->insertButton->TabIndex = 3;
			this->insertButton->Text = L"Insert Album Data";
			this->insertButton->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->insertButton->UseVisualStyleBackColor = false;
			this->insertButton->Click += gcnew System::EventHandler(this, &Form1::insertButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(290, 300);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->batteryPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speakerPictureBox))->EndInit();
			this->batteryPanel->ResumeLayout(false);
			this->batteryPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->signalPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->mainPanel->ResumeLayout(false);
			this->mainPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
private: System::Void insertButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			if(names[9] != nullptr){
				MessageBox::Show("Maximum data inserted!");
				return;
			}
			 if(insert == nullptr){				 
				 insert = gcnew InsertAlbumForm(this,names,artists,pictures,years);
			 }
			 this->Hide();
			 insert->Show();
		 }
private: System::Void trainButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(train == nullptr){				 
				 train = gcnew TrainNeuralMusic(this);
				 train->names = names;
				train->pictures = pictures;
				train->brain = brain;
				train->data = data;
				train->inputs = inputs;
				train->outputs = outputs;
			
			 }
			 train->loadMusic();
			 this->Hide();
			 train->Show();
		 }
private: System::Void recognizeButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(recognize == nullptr){				 
				 recognize = gcnew RecognizeForm(this);//,names,artists,pictures,years,brain,data,inputs,outputs);
				 
				recognize->names = names;
				recognize->artists = artists;
				recognize->pictures = pictures;
				recognize->years = years;
				recognize->brain = brain;
				recognize->data = data;
				recognize->inputs = inputs;
				recognize->outputs = outputs;
			 }
			 this->Hide();
			 recognize->Show();
		 }
};
}

