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
	/// Summary for RecognizeForm
	/// </summary>
	public ref class RecognizeForm : public System::Windows::Forms::Form
	{
		Form^ form;
		static const int width = 7, height = 7, num_data = 10;
	public:
		fann *brain;
		fann_train_data *data;
		array<float,2> ^inputs, ^outputs;
		array<String^,1> ^names;
		array<String^,1> ^artists;
		array<Bitmap^,1> ^pictures;
		array<int,1> ^years;
		RecognizeForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		RecognizeForm(Form^ form)//,array<String^,1> ^names,array<String^,1> ^artists,array<Bitmap^,1> ^pictures,array<int,1> ^years,fann *brain,fann_train_data *data,array<float,2> ^inputs,array<float,2> ^outputs)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->form = form;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RecognizeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  mainPanel;
	protected: 
	private: System::Windows::Forms::Label^  yearLabel;
	private: System::Windows::Forms::Label^  artistLabel;
	private: System::Windows::Forms::Label^  nameLabel;
	private: System::Windows::Forms::Label^  insertAlbumLabel;
	private: System::Windows::Forms::PictureBox^  albumPictureBox;
	private: System::Windows::Forms::PictureBox^  logoPictureBox;
	private: System::Windows::Forms::Button^  optionButton;
	private: System::Windows::Forms::Button^  homeButton;
	private: System::Windows::Forms::Button^  backButton;
	private: System::Windows::Forms::Panel^  batteryPanel;
	private: System::Windows::Forms::Label^  percentLabel;
	private: System::Windows::Forms::Label^  timeLabel;
	private: System::Windows::Forms::PictureBox^  signalPictureBox;
	private: System::Windows::Forms::PictureBox^  speakerPictureBox;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RecognizeForm::typeid));
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->yearLabel = (gcnew System::Windows::Forms::Label());
			this->artistLabel = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->insertAlbumLabel = (gcnew System::Windows::Forms::Label());
			this->albumPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->logoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->optionButton = (gcnew System::Windows::Forms::Button());
			this->homeButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->batteryPanel = (gcnew System::Windows::Forms::Panel());
			this->percentLabel = (gcnew System::Windows::Forms::Label());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->signalPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->speakerPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->mainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->albumPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->BeginInit();
			this->batteryPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->signalPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speakerPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->BackColor = System::Drawing::SystemColors::ControlText;
			this->mainPanel->Controls->Add(this->yearLabel);
			this->mainPanel->Controls->Add(this->artistLabel);
			this->mainPanel->Controls->Add(this->nameLabel);
			this->mainPanel->Controls->Add(this->insertAlbumLabel);
			this->mainPanel->Controls->Add(this->albumPictureBox);
			this->mainPanel->Controls->Add(this->logoPictureBox);
			this->mainPanel->Controls->Add(this->optionButton);
			this->mainPanel->Controls->Add(this->homeButton);
			this->mainPanel->Controls->Add(this->backButton);
			this->mainPanel->Location = System::Drawing::Point(0, 32);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(290, 268);
			this->mainPanel->TabIndex = 8;
			// 
			// yearLabel
			// 
			this->yearLabel->AutoSize = true;
			this->yearLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->yearLabel->Location = System::Drawing::Point(112, 167);
			this->yearLabel->Name = L"yearLabel";
			this->yearLabel->Size = System::Drawing::Size(10, 13);
			this->yearLabel->TabIndex = 5;
			this->yearLabel->Text = L"-";
			// 
			// artistLabel
			// 
			this->artistLabel->AutoSize = true;
			this->artistLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->artistLabel->Location = System::Drawing::Point(112, 142);
			this->artistLabel->Name = L"artistLabel";
			this->artistLabel->Size = System::Drawing::Size(10, 13);
			this->artistLabel->TabIndex = 5;
			this->artistLabel->Text = L"-";
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nameLabel->Location = System::Drawing::Point(112, 117);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(10, 13);
			this->nameLabel->TabIndex = 5;
			this->nameLabel->Text = L"-";
			// 
			// insertAlbumLabel
			// 
			this->insertAlbumLabel->AutoSize = true;
			this->insertAlbumLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->insertAlbumLabel->Location = System::Drawing::Point(102, 83);
			this->insertAlbumLabel->Name = L"insertAlbumLabel";
			this->insertAlbumLabel->Size = System::Drawing::Size(90, 13);
			this->insertAlbumLabel->TabIndex = 5;
			this->insertAlbumLabel->Text = L"Recognize Image";
			// 
			// albumPictureBox
			// 
			this->albumPictureBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"albumPictureBox.BackgroundImage")));
			this->albumPictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->albumPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->albumPictureBox->Location = System::Drawing::Point(21, 105);
			this->albumPictureBox->Name = L"albumPictureBox";
			this->albumPictureBox->Size = System::Drawing::Size(85, 85);
			this->albumPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->albumPictureBox->TabIndex = 4;
			this->albumPictureBox->TabStop = false;
			this->albumPictureBox->Click += gcnew System::EventHandler(this, &RecognizeForm::albumPictureBox_Click);
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
			// homeButton
			// 
			this->homeButton->BackColor = System::Drawing::SystemColors::ControlText;
			this->homeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"homeButton.Image")));
			this->homeButton->Location = System::Drawing::Point(133, 232);
			this->homeButton->Name = L"homeButton";
			this->homeButton->Size = System::Drawing::Size(25, 25);
			this->homeButton->TabIndex = 3;
			this->homeButton->UseVisualStyleBackColor = false;
			this->homeButton->Click += gcnew System::EventHandler(this, &RecognizeForm::homeButton_Click);
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
			this->backButton->Click += gcnew System::EventHandler(this, &RecognizeForm::backButton_Click);
			// 
			// batteryPanel
			// 
			this->batteryPanel->BackColor = System::Drawing::SystemColors::WindowText;
			this->batteryPanel->Controls->Add(this->percentLabel);
			this->batteryPanel->Controls->Add(this->timeLabel);
			this->batteryPanel->Controls->Add(this->signalPictureBox);
			this->batteryPanel->Controls->Add(this->speakerPictureBox);
			this->batteryPanel->Controls->Add(this->pictureBox1);
			this->batteryPanel->Location = System::Drawing::Point(0, 1);
			this->batteryPanel->Name = L"batteryPanel";
			this->batteryPanel->Size = System::Drawing::Size(291, 31);
			this->batteryPanel->TabIndex = 7;
			// 
			// percentLabel
			// 
			this->percentLabel->AutoSize = true;
			this->percentLabel->BackColor = System::Drawing::SystemColors::ControlText;
			this->percentLabel->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->percentLabel->Location = System::Drawing::Point(232, 15);
			this->percentLabel->Name = L"percentLabel";
			this->percentLabel->Size = System::Drawing::Size(27, 13);
			this->percentLabel->TabIndex = 1;
			this->percentLabel->Text = L"39%";
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
			this->timeLabel->Text = L"14:02";
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
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::DarkRed;
			this->pictureBox1->Location = System::Drawing::Point(258, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(20, 15);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog1";
			this->openFileDialog->Filter = L"Images | *.png;*.jpg;*.bmp";
			// 
			// RecognizeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(290, 300);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->batteryPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"RecognizeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RecognizeForm";
			this->mainPanel->ResumeLayout(false);
			this->mainPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->albumPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->EndInit();
			this->batteryPanel->ResumeLayout(false);
			this->batteryPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->signalPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speakerPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Hide();
				 form->Show();
			 }
private: System::Void albumPictureBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					Bitmap ^image = gcnew Bitmap(openFileDialog->FileName);

					//grayscale
					for(int i = 0; i < image->Width; i++){
						for(int j = 0; j < image->Height; j++){
							Color color = image->GetPixel(i,j);

							int average = (color.R + color.G + color.B)/3;
							image->SetPixel(i,j,Color::FromArgb(average,average,average));
						}
					}
					//threshold
					for(int i = 0; i < image->Width; i++){
						for(int j = 0; j < image->Height; j++){
							Color color = image->GetPixel(i,j);
							int thresh = (color.R < 127) ? 0 : 255;
							image->SetPixel(i,j,Color::FromArgb(thresh,thresh,thresh));
						}
					}
					//remove noise
					int xMin = 0, xMax = 0, yMin = 0, yMax = 0;
					bool found = false;

					for(int i = 0; i < image->Width && found == false; i++){
						for(int j = 0; j < image->Height; j++){
							if(image->GetPixel(i,j).R == 0){
								xMin = i;
								found = true;
								break;
							}
						}
					}
					found = false;
					for(int i = 0; i < image->Height && found == false; i++){
						for(int j = 0; j < image->Width; j++){
							if(image->GetPixel(j,i).R == 0){
								yMin = i;
								found = true;
								break;
							}
						}
					}
					found = false;
					for(int i = image->Width-1; i >= 0 && found == false; i--){
						for(int j = image->Height-1; j >= 0; j--){
							if(image->GetPixel(i,j).R == 0){
								xMax = i;
								found = true;
								break;
							}
						}
					}
					found = false;
					for(int i = image->Height-1; i >= 0 && found == false; i--){
						for(int j = image->Width-1; j >= 0; j--){
							if(image->GetPixel(j,i).R == 0){
								yMax = i;
								found = true;
								break;
							}
						}
					}

					Bitmap^ removed = gcnew Bitmap(xMax-xMin, yMax-yMin);

					for(int i = 0; i < removed->Width; i++){
						for(int j = 0; j < removed->Height; j++){
							removed->SetPixel(i,j,image->GetPixel(xMin+i,yMin+j));
						}
					}
					image = (Bitmap^)removed->Clone();

					//scale
					Bitmap^ scaled = gcnew Bitmap(width, height);

					Graphics^ g = Graphics::FromImage(scaled);

					g->DrawImage(image,0,0,width,height);

					Bitmap^ trained = gcnew Bitmap(scaled);

					albumPictureBox->Image = trained;
					
					fann_type *input, *output;

					input = (fann_type*) calloc(width*height,sizeof(fann_type));

					 for(int i = 0; i < trained->Width; i++){
						 for(int j = 0; j < trained->Height; j++){
							 input[i*trained->Width+j] = trained->GetPixel(i,j).R/255;
						 }
					 }

					 output = fann_run(brain,input);
				
					 for(int i = 0; ; i++){

						 if(names[i] != nullptr && output[i] == 1){

							 nameLabel->Text = names[i];
							 artistLabel->Text = artists[i];
							 yearLabel->Text = years[i]+"";
							 albumPictureBox->Image = pictures[i];

							 break;
						 }else if(names[i+1] == nullptr && output[i] != 1){
							 MessageBox::Show("No data to be recognized! ");//+i);
							 
							 nameLabel->Text = "-";
							 artistLabel->Text = "-";
							 yearLabel->Text = "-";
							 albumPictureBox->Image = nullptr;

							 break;
						 }

					 }

				 }
		 }
private: System::Void homeButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Hide();
				 form->Show();
		 }
};
}
