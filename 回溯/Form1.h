#pragma once
#include<string>
#include<cstdlib>
#include <msclr\marshal_cppstd.h> 
#include <iostream>
#include<strstream>
#include<fstream>
using namespace System;
using namespace System::Collections::Generic;
using namespace msclr::interop;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO ;
using namespace System::Text;  
using namespace std;
using namespace System::Media;
namespace 回溯
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		array<Label^,2>^lab;
		array<int,2>^ Puzzle;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

			 array<int,2>^ mark;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			lab=gcnew array<Label^,2>(9,9);
			Puzzle=gcnew array<int,2>(9,9);
			mark=gcnew array<int,2>(9,9);
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;

	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(30, 26);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(600, 600);
			this->panel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(661, 269);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"开始";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(657, 167);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"演示回溯法";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(657, 214);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(274, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"求解一个简单数独的过程";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(657, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 24);
			this->label3->TabIndex = 4;
			this->label3->Text = L"点击“开始”";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(946, 651);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		{ 
			initial();
		}

		void initial()
		{
			int p[9][9]={  
				3,0,6,5,0,8,4,0,0,
				5,2,0,0,0,0,0,0,0,
				0,8,7,0,0,0,0,3,1,
				0,0,3,0,1,0,0,8,0,
				9,0,0,8,6,3,0,0,5,
				0,5,0,0,9,0,6,0,0,
				1,3,0,0,0,0,2,5,0,
				0,0,0,0,0,0,0,7,4,
				0,0,5,2,0,6,3,0,0
			};
			int i,j;
			for(i=0;i<9;i++)
				for(j=0;j<9;j++)
				{
					lab[i,j]=gcnew Label();
					Puzzle[i,j]=p[i][j];
					if(Puzzle[i,j])
					{
						mark[i,j]=1;
						strstream ss;
						string str;
						ss<<Puzzle[i,j];
						ss>>str;
						String^a=marshal_as<String^>(str);

						int w=50,h=50;
						lab[i,j]->Width=w; 
						lab[i,j]->Height=h;
						lab[i,j]->Left=j*w;
						lab[i,j]->Top=i*h;
						lab[i,j]->Text = a;
						lab[i,j]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
						lab[i,j]->BorderStyle=System::Windows::Forms::BorderStyle::FixedSingle;
						lab[i,j]->ForeColor = System::Drawing::Color::Red;
						lab[i,j]->Font=(gcnew System::Drawing::Font(L"黑体", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
						panel1->Controls->Add(lab[i,j]);
					}
					else
					{
						mark[i,j]=0;

						int w=50,h=50;
						lab[i,j]->Width=w; 
						lab[i,j]->Height=h;
						lab[i,j]->Left=j*w;
						lab[i,j]->Top=i*h;
						lab[i,j]->Text="";
						lab[i,j]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
						lab[i,j]->BorderStyle=System::Windows::Forms::BorderStyle::FixedSingle;
						lab[i,j]->ForeColor = System::Drawing::Color::Blue;
						lab[i,j]->Font=(gcnew System::Drawing::Font(L"黑体", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
						panel1->Controls->Add(lab[i,j]);

					}
			}
		}

		void solvePuzzle(array<int,2>^ Puzzle,int i,int j)  
		{
			int num;
			if(mark[i,j])
			{  
				if(j>=8)
				{  
					if(i==8) ;
						//PRINT(Puzzle);
					else   
						solvePuzzle(Puzzle,i+1,0);
				}  
				else
					solvePuzzle(Puzzle,i,j+1);
				return;
			}

		   for(num=1;num<=9;num++)  
		   {  
			   int k;
			   for(k=0;k<9;k++)
				   if(Puzzle[i,k]==num)
					   goto NEXT;

			   for(k=0;k<9;k++)
				   if(Puzzle[k,j]==num)
					   goto NEXT;

				int h=i/3,l=j/3;;
				for(int m=0;m<3;m++)
					for(int n=0;n<3;n++)
						if(Puzzle[(h*3+m),(l*3)+n]==num)
							goto NEXT;

				{
					Puzzle[i,j]=num;
					strstream ss;
					string str;
					ss<<Puzzle[i,j];
					ss>>str;
					String^a=marshal_as<String^>(str);
					lab[i,j]->Text=a;
					//必须加入Application::DoEvents();不然会导致程序假死
					Application::DoEvents();
					//动态显示的关键，让程序在这里停0.1ms
					System::Threading::Thread::Sleep(100);
				}

				if(j>=8)
				{
					if(i==8) ;
						//PRINT(Puzzle);
					else
						solvePuzzle(Puzzle,i+1,0);
				}
				else  
					solvePuzzle(Puzzle,i,j+1);
				NEXT: ;
		   }
		   Puzzle[i,j]=0;
		   lab[i,j]->Text="";
		}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			solvePuzzle(Puzzle,0,0);
		 }
};
}

