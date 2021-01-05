//---------------------------------------------------------------------------
/*
Copyright (c) 2020 White-door Inc. (Yasushi Shirato)
Released under the MIT license
http://opensource.org/licenses/mit-license.php
*/

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TMainMenu *MainMenu1;
	TMenuItem *FileF1;
	TMenuItem *N1;
	TMenuItem *O1;
	TMenuItem *W1;
	TMenuItem *Q1;
	TMenuItem *I1;
	TMenuItem *N2;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TEdit *Edit1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit2;
	TLabel *Label3;
	TEdit *Edit3;
	TOpenDialog *OpenDialog1;
	TMemo *Memo1;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *Edit10;
	TLabel *Label10;
	TEdit *Edit11;
	TLabel *Label11;
	TEdit *Edit12;
	TEdit *Edit13;
	TLabel *Label12;
	TComboBox *ComboBox1;
	TLabel *Label13;
	TEdit *Edit14;
	TLabel *Label14;
	TMemo *Memo2;
	TEdit *Edit15;
	TLabel *Label15;
	TLabel *Label16;
	TEdit *Edit16;
	TEdit *Edit17;
	TCheckBox *CheckBox1;
	TLabel *Label17;
	TComboBox *ComboBox2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall O1Click(TObject *Sender);
	void __fastcall Q1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
private:	// ユーザー宣言
	UnicodeString exePath;
	int __fastcall CalcDelay( void );
	bool fLoaded;

	UnicodeString __fastcall StripComment( UnicodeString uStrSrc );
	int __fastcall LoadFromLocalAppData( void );
    int __fastcall LoadRegData( UnicodeString uStrKeyName );
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
