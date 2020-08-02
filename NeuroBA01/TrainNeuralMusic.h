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
	/// Summary for TrainNeuralMusic
	/// </summary>
	public ref class TrainNeuralMusic : public System::Windows::Forms::Form
	{
		Form^ form;
		array<PictureBox^,1> ^images;
		array<Label^,1> ^labels;	
	public: 
		fann *brain;
		fann_train_data *data;
		array<float,2> ^inputs, ^outputs;
		static const int width = 7, height = 7, num_data = 10;
		array<Bitmap^,1> ^pictures;				
		array<String^,1> ^names;		
		
	public:

		TrainNeuralMusic(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		TrainNeuralMusic(Form^ form)//,array<String^,1> ^names,array<Bitmap^,1> ^pictures,fann *brain,fann_train_data *data,array<float,2> ^inputs,array<float,2> ^outputs)
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
		~TrainNeuralMusic()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  mainPanel;
	private: System::Windows::Forms::Button^  trainButton;
	protected: 







	private: System::Windows::Forms::Label^  trainNeuralLabel;


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
	private: System::Windows::Forms::Panel^  dataPanel;

	private: System::Windows::Forms::Label^  noDataLabel;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TrainNeuralMusic::typeid));
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->dataPanel = (gcnew System::Windows::Forms::Panel());
			this->noDataLabel = (gcnew System::Windows::Forms::Label());
			this->trainNeuralLabel = (gcnew System::Windows::Forms::Label());
			this->trainButton = (gcnew System::Windows::Forms::Button());
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
			this->mainPanel->SuspendLayout();
			this->dataPanel->SuspendLayout();
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
			this->mainPanel->Controls->Add(this->dataPanel);
			this->mainPanel->Controls->Add(this->logoPictureBox);
			this->mainPanel->Controls->Add(this->optionButton);
			this->mainPanel->Controls->Add(this->homeButton);
			this->mainPanel->Controls->Add(this->backButton);
			this->mainPanel->Location = System::Drawing::Point(2, 30);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(290, 268);
			this->mainPanel->TabIndex = 8;
			// 
			// dataPanel
			// 
			this->dataPanel->AutoScroll = true;
			this->dataPanel->Controls->Add(this->noDataLabel);
			this->dataPanel->Controls->Add(this->trainNeuralLabel);
			this->dataPanel->Controls->Add(this->trainButton);
			this->dataPanel->Location = System::Drawing::Point(21, 72);
			this->dataPanel->Name = L"dataPanel";
			this->dataPanel->Size = System::Drawing::Size(255, 154);
			this->dataPanel->TabIndex = 9;
			// 
			// noDataLabel
			// 
			this->noDataLabel->AutoSize = true;
			this->noDataLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->noDataLabel->Location = System::Drawing::Point(73, 32);
			this->noDataLabel->Name = L"noDataLabel";
			this->noDataLabel->Size = System::Drawing::Size(109, 13);
			this->noDataLabel->TabIndex = 5;
			this->noDataLabel->Text = L"No Data to be trained";
			this->noDataLabel->Visible = false;
			// 
			// trainNeuralLabel
			// 
			this->trainNeuralLabel->AutoSize = true;
			this->trainNeuralLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->trainNeuralLabel->Location = System::Drawing::Point(72, 9);
			this->trainNeuralLabel->Name = L"trainNeuralLabel";
			this->trainNeuralLabel->Size = System::Drawing::Size(110, 13);
			this->trainNeuralLabel->TabIndex = 5;
			this->trainNeuralLabel->Text = L"Training Neural Music";
			// 
			// trainButton
			// 
			this->trainButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->trainButton->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->trainButton->Location = System::Drawing::Point(70, 128);
			this->trainButton->Name = L"trainButton";
			this->trainButton->Size = System::Drawing::Size(115, 23);
			this->trainButton->TabIndex = 8;
			this->trainButton->Text = L"Train";
			this->trainButton->UseVisualStyleBackColor = false;
			this->trainButton->Visible = false;
			this->trainButton->Click += gcnew System::EventHandler(this, &TrainNeuralMusic::trainButton_Click);
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
			this->homeButton->Click += gcnew System::EventHandler(this, &TrainNeuralMusic::homeButton_Click);
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
			this->backButton->Click += gcnew System::EventHandler(this, &TrainNeuralMusic::backButton_Click);
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
			this->timeLabel->Text = L"14:01";
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
			// TrainNeuralMusic
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(290, 300);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->batteryPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"TrainNeuralMusic";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TrainNeuralMusic";
			this->Load += gcnew System::EventHandler(this, &TrainNeuralMusic::TrainNeuralMusic_Load);
			this->mainPanel->ResumeLayout(false);
			this->dataPanel->ResumeLayout(false);
			this->dataPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->EndInit();
			this->batteryPanel->ResumeLayout(false);
			this->batteryPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->signalPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speakerPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	

public: System::Void loadMusic()
		{
			
			 
			if(names[0] == nullptr){
				noDataLabel->Visible = true;
			}else{
				trainButton->Visible = true;
				if(images == nullptr) images = gcnew array<PictureBox^,1>(10);
				if(labels == nullptr) labels = gcnew array<Label^,1>(10);
				for(int i = 0; ; i++){
					if(names[i] != nullptr){
						if(images[i])images[i]->Image = pictures[i];
						else{
							images[i] = gcnew PictureBox();
							images[i]->Image = pictures[i];
							images[i]->SizeMode = PictureBoxSizeMode::StretchImage;
							images[i]->Size = System::Drawing::Size(50,50);
							images[i]->Location = Point(5,55*i+30);

							labels[i] = gcnew Label();
							labels[i]->Text = names[i];
							labels[i]->Location = Point(65,55*i+50);
							labels[i]->ForeColor = Color::White;

							dataPanel->Controls->Add(images[i]);
							dataPanel->Controls->Add(labels[i]);
							if(names[i+1] == nullptr){
								trainButton->Location = Point(70,55*(i+1)+30);
								break;
							}
						}
					}else break;
				}

			}
		}
private: System::Void train(int data_count){
		
		if(pictures[data_count]->Width != width){
			Bitmap^ grayscaled = (Bitmap ^) pictures[data_count]->Clone();

			//grayscale
				for(int i = 0; i < grayscaled->Width; i++){
					for(int j = 0; j < grayscaled->Height; j++){
						Color color = grayscaled->GetPixel(i,j);

						int average = (color.R + color.G + color.B)/3;
						grayscaled->SetPixel(i,j,Color::FromArgb(average,average,average));
					}
				}
				pictures[data_count] = grayscaled;
		
				/*loadMusic();
				 MessageBox::Show("grayscald "+data_count+"!");
				*/Bitmap^ thresholded = (Bitmap ^) pictures[data_count]->Clone();

				//threshold
				for(int i = 0; i < thresholded->Width; i++){
					for(int j = 0; j < thresholded->Height; j++){
						Color color = thresholded->GetPixel(i,j);
						int thresh = (color.R < 127) ? 0 : 255;
						thresholded->SetPixel(i,j,Color::FromArgb(thresh,thresh,thresh));
					}
				}
				pictures[data_count] = (Bitmap^)thresholded->Clone();
			
				/* loadMusic();
				 MessageBox::Show("thres "+data_count+"!");
				*/Bitmap^ removed = (Bitmap ^) pictures[data_count]->Clone();
			
				//remove noise
				int xMin = 0, xMax = 0, yMin = 0, yMax = 0;
				bool found = false;

				for(int i = 0; i < removed->Width && found == false; i++){
					for(int j = 0; j < removed->Height; j++){
						if(removed->GetPixel(i,j).R == 0){
							xMin = i;
							found = true;
							break;
						}
					}
				}
				found = false;
				for(int i = 0; i < removed->Height && found == false; i++){
					for(int j = 0; j < removed->Width; j++){
						if(removed->GetPixel(j,i).R == 0){
							yMin = i;
							found = true;
							break;
						}
					}
				}
				found = false;
				for(int i = removed->Width-1; i >= 0 && found == false; i--){
					for(int j = removed->Height-1; j >= 0; j--){
						if(removed->GetPixel(i,j).R == 0){
							xMax = i;
							found = true;
							break;
						}
					}
				}
				found = false;
				for(int i = removed->Height-1; i >= 0 && found == false; i--){
					for(int j = removed->Width-1; j >= 0; j--){
						if(removed->GetPixel(j,i).R == 0){
							yMax = i;
							found = true;
							break;
						}
					}
				}

				Bitmap^ noiseRemoved = gcnew Bitmap(xMax-xMin, yMax-yMin);

				for(int i = 0; i < noiseRemoved->Width; i++){
					for(int j = 0; j < noiseRemoved->Height; j++){
						noiseRemoved->SetPixel(i,j,removed->GetPixel(xMin+i,yMin+j));
					}
				}
		
			pictures[data_count] = (Bitmap^)noiseRemoved->Clone();
		
				 /*loadMusic();
				 MessageBox::Show("removed "+data_count+"!");
			*/
			//scale
		
			Bitmap^ scaled = gcnew Bitmap(width, height);

			Graphics^ g = Graphics::FromImage(scaled);

			g->DrawImage(pictures[data_count],0,0,width,height);

			pictures[data_count] = (Bitmap^)scaled->Clone();
		
				/*	loadMusic();
					MessageBox::Show("scaled "+data_count+"!");
		*/
			Bitmap^ trained = (Bitmap^) pictures[data_count]->Clone();
		
			for(int i = 0; i < trained->Width; i++){
				for(int j = 0; j < trained->Height; j++){
					inputs[data_count,i*trained->Width+j] = trained->GetPixel(i,j).R/255;
				}
			}

			for(int i = 0; i < data->num_data; i++){
				data->input[i] = (fann_type*)calloc(width*height,sizeof(fann_type));
				for(int j = 0; j < data->num_input; j++){
					data->input[i][j] = inputs[i,j];
				}
			}

			for(int i = 0; i < data->num_output; i++){
				if(i == data_count){
					outputs[data_count,i] = 1;
				}else{
					outputs[data_count,i] = 0;
				}						 
			}

			for(int i = 0; i < data->num_data; i++){
				data->output[i] = (fann_type*)calloc(num_data,sizeof(fann_type));
				for(int j = 0; j < data->num_output; j++){
					data->output[i][j] = outputs[i,j];
				}
			}
			/*char out[255];
			for(int i = 0; i < data->num_data; i++){
				for(int j = 0; j < data->num_output; j++){
				out[i*num_data+j+i] = data->output[i][j];
				}
				out[(i+1)*num_data] = 'z';
			}
			out[244] = '\0';
			MessageBox::Show(gcnew String(out));*/
	
			fann_train_on_data(brain,data,10000,10000,0.0000001);

	//		names[data_count] = inputTextBox->Text;

	//		MessageBox::Show(data_count+"th training succesful!");

	//		recognizeButton->Enabled = true;
	//		inputTextBox->Text = "";
		}
		 }

private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Hide();
				 form->Show();
			 }
private: System::Void homeButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Hide();
				 form->Show();
		 }
private: System::Void trainButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 int idx = 0;
				for(idx = 0; ; idx++){
					if(names[idx] == nullptr) break;
				}
				idx--;
			 if(names[idx] != nullptr && pictures[idx]->Width != width && pictures[idx]->Height != height){
				 for(int i = 0; ; i++){
					 if(names[i] != nullptr){
						train(i);
					 }else break;
				 }
				 loadMusic();
				 MessageBox::Show("Succesfully training neural!");
			 }else{
				MessageBox::Show("Data has been trained!");
			 }
		 }

private: System::Void TrainNeuralMusic_Load(System::Object^  sender, System::EventArgs^  e) {
			 loadMusic();
		 }
};
}
