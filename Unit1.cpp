//---------------------------------------------------------------------------
/*
Copyright (c) 2020 White-door Inc. (Yasushi Shirato)
Released under the MIT license
http://opensource.org/licenses/mit-license.php
*/

#include <vcl.h>
#include <System.IOUtils.hpp>
#include <System.SysUtils.hpp>
#include <Registry.hpp>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	//
	UnicodeString uStr;

	fLoaded = false;
	uStr = System::Ioutils::TPath::GetCachePath();
	if( DirectoryExists( uStr )) {
		exePath = uStr;
		Edit1->Text = uStr + L"\\ChiTuBox";

		uStr = System::Ioutils::TPath::GetDocumentsPath();
		OpenDialog1->InitialDir = uStr;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
	//
	int ret;

	if( fLoaded == false ) {
		//一回のみLOCALデータから設定を読み込む
		ret = LoadFromLocalAppData();

		fLoaded = true;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	//設定フォルダを開く
	if( Edit1->Text.IsEmpty() ) {
		return;
	}
	if( !DirectoryExists( Edit1->Text ) ) {
		if( CheckBox1->Checked ) {
			ShowMessage( L"The LOCAL APP path has not been entered." );
		} else {
			ShowMessage( L"LOCALAPPパスが未入力です。" );
		}
	}
	ShellExecute( Form1->Handle, L"open", L"explorer.exe", Edit1->Text.w_str(), NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	//
	UnicodeString uStr, uStrFileName, uStrPrnName, uStrSrhText, uStrPrnPath, uStrCfgName;
	UnicodeString uStrHeight, uStrLiftSpeed, uStrDropSpeed, uStrTmp, uStrOffTime;
	int n, index, i;

	uStrPrnName =  L"";

	if( ComboBox1->ItemIndex == -1 ) {
		if( CheckBox1->Checked ) {
			ShowMessage( L"The installation version is not selected." );
		} else {
			ShowMessage( L"インストールバージョンが未選択です。" );
		}
		return;
	}

	if( CheckBox1->Checked ) {
		OpenDialog1->Title = L"Select Config File";
	} else {
		OpenDialog1->Title = L"設定ファイル選択";
	}
	OpenDialog1->Filter = L"cfg files (*.cfg)|*.cfg|All files (*.*)|*.*";
	OpenDialog1->FilterIndex = 1;
	//ファイルを選択する
	if( OpenDialog1->Execute() ) {
		uStrFileName = OpenDialog1->FileName;
		if( FileExists( uStrFileName ) ) {
			Edit2->Text = uStrFileName;

			OpenDialog1->InitialDir = ExtractFilePath( uStrFileName );
			//ファイルを読み込む
			Edit4->Text = L"";
			Edit5->Text = L"";
			Edit6->Text = L"";
			Edit7->Text = L"";
			Edit8->Text = L"";
			Edit9->Text = L"";
			Edit10->Text = L"";
			Edit11->Text = L"";
			Edit12->Text = L"";
			Edit13->Text = L"";

			Memo1->Clear();
			Memo1->Lines->LoadFromFile( uStrFileName, TEncoding::UTF8 );
			Edit16->Text = ExtractFileName( uStrFileName );

			//@@の行を飛ばして読み込む
			for( i = 0; i < Memo1->Lines->Count; i++ ) {
				//
				uStr = Memo1->Lines->Strings[i];
				uStrTmp = uStr.SubString( 0, 2 );
				if( uStrTmp == L"@@" ) {
					continue;
				}

				uStrSrhText = L"machineType:";
				n = uStr.Pos( uStrSrhText );
				if( n == 1 ) {
					uStrPrnName = uStr.SubString( uStrSrhText.Length() +1, 100 );
					Edit3->Text = uStrPrnName;
				} else {
					//__inherit:
					uStrSrhText = L"__inherit:";
					n = uStr.Pos( uStrSrhText );
					if( n == 1 ) {
						uStrPrnName = uStr.SubString( uStrSrhText.Length() +1, 100 );
						Edit3->Text = uStrPrnName;
					}
				}

				uStrSrhText = L"normalLayerLiftHeight:";
				n = uStr.Pos( uStrSrhText );
				if( n == 1 ) {
					uStrHeight = uStr.SubString( uStrSrhText.Length() +1, 10 );
					Edit4->Text = StripComment( uStrHeight );
				}
				uStrSrhText = L"normalLayerLiftSpeed:";
				n = uStr.Pos( uStrSrhText );
				if( n == 1 ) {
					uStrLiftSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
					Edit5->Text = StripComment( uStrLiftSpeed );
				}
				uStrSrhText = L"normalLayerDropSpeed:";
				n = uStr.Pos( uStrSrhText );
				if( n == 1 ) {
					uStrDropSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
					Edit6->Text = StripComment( uStrDropSpeed );
				} else {
					uStrSrhText = L"normalDropSpeed:";
					n = uStr.Pos( uStrSrhText );
					if( n == 1 ) {
						uStrDropSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
						Edit6->Text = StripComment( uStrDropSpeed );
					}
				}
				uStrSrhText = L"lightOffTime:";
				n = uStr.Pos( uStrSrhText );
				if( n == 1 ) {
					uStrOffTime = uStr.SubString( uStrSrhText.Length() +1, 10 );
					Edit12->Text = StripComment( uStrOffTime );
				}

			}
			Memo1->Perform(EM_LINESCROLL, 0, Memo1->Lines->Count);

			//マシン情報を読み込む
			if( !uStrPrnName.IsEmpty() ) {
				//
				uStrCfgName = System::Sysutils::StringReplace( uStrPrnName, L" ", L"_", TReplaceFlags() << rfReplaceAll << rfIgnoreCase );
				uStrPrnPath = Edit14->Text + L"\\resource\\machine\\" +  uStrCfgName + L".cfg";
				Edit15->Text = uStrPrnPath;
				if( FileExists( uStrPrnPath ) ) {
					//読み込む
					Memo2->Clear();
					Memo2->Lines->LoadFromFile( uStrPrnPath, TEncoding::UTF8 );
					Edit17->Text = ExtractFileName( uStrPrnPath );

					for( i = 0; i < Memo2->Lines->Count; i++ ) {
						//
						uStr = Memo2->Lines->Strings[i];
						uStrTmp = uStr.SubString( 0, 2 );
						if( uStrTmp == L"@@" ) {
							continue;
						}
						if( Edit4->Text.IsEmpty() ) {
							uStrSrhText = L"normalLayerLiftHeight:";
							n = uStr.Pos( uStrSrhText );
							if( n == 1 ) {
								uStrHeight = uStr.SubString( uStrSrhText.Length() +1, 10 );
								Edit4->Text = StripComment( uStrHeight );
							}
						}
						if( Edit5->Text.IsEmpty() ) {
							uStrSrhText = L"normalLayerLiftSpeed:";
							n = uStr.Pos( uStrSrhText );
							if( n == 1 ) {
								uStrLiftSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
								Edit5->Text = StripComment( uStrLiftSpeed );
							}
						}
						if( Edit6->Text.IsEmpty() ) {
							uStrSrhText = L"normalLayerDropSpeed:";
							n = uStr.Pos( uStrSrhText );
							if( n == 1 ) {
								uStrDropSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
								Edit6->Text = StripComment( uStrDropSpeed );
							} else {
								uStrSrhText = L"normalDropSpeed:";
								n = uStr.Pos( uStrSrhText );
								if( n == 1 ) {
									uStrDropSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
									Edit6->Text = StripComment( uStrDropSpeed );
								}
							}
						}
						if( Edit12->Text.IsEmpty() ) {
							uStrSrhText = L"lightOffTime:";
							n = uStr.Pos( uStrSrhText );
							if( n == 1 ) {
								uStrOffTime = uStr.SubString( uStrSrhText.Length() +1, 10 );
								Edit12->Text = StripComment( uStrOffTime );
							}
						}
					}
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
int __fastcall TForm1::CalcDelay( void )
{
	//


	return(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{

	//Install Version Change
	int n;
	UnicodeString uStr, retStr, uStrRKeyName;


	if( !fLoaded ) {
		return;
	}

	if( ComboBox1->ItemIndex < 0 ) {
		return;
	}

	uStrRKeyName = L"Software\\" + ComboBox1->Items->Strings[ ComboBox1->ItemIndex ];

	TRegistry* reg = new TRegistry(KEY_READ);
	reg->RootKey = HKEY_CURRENT_USER;

	reg->Access = KEY_READ;
	bool openResult = reg->OpenKey( uStrRKeyName, false );
	if(!openResult) {
		//キーが作成出来なかった
		if( CheckBox1->Checked ) {
			ShowMessage( ComboBox1->Items->Strings[ ComboBox1->ItemIndex ] + L" doesn't seem to be installed." );
		} else {
			ShowMessage( ComboBox1->Items->Strings[ ComboBox1->ItemIndex ] + L" はインストールされていないようです。" );
		}
		reg->Free();
		return;
	} else {
		retStr = reg->ReadString( L"" );
		if( !retStr.IsEmpty() ) {
			Edit14->Text = retStr;
		} else {
			if( CheckBox1->Checked ) {
				ShowMessage( ComboBox1->Items->Strings[ ComboBox1->ItemIndex ] + L" のインストール先が設定されていませんでした。" );
			} else {
				ShowMessage( ComboBox1->Items->Strings[ ComboBox1->ItemIndex ] + L"\nThe installation destination was not set." );
			}
		}
	}
	reg->Free();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
	//プリンタ情報の読込
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
	//計算
	double height, upspeed, dropspeed;
	double upspeedS, dropspeedS, upTime, dropTime, totalTime, offTime, difTime;

	if( Edit4->Text.IsEmpty() || Edit5->Text.IsEmpty() ||
		Edit6->Text.IsEmpty() || Edit12->Text.IsEmpty() ) {
		//
		if( CheckBox1->Checked ) {
			ShowMessage( L"Enter the lift height, lift speed (min), and retract speed (min)." );
		}  else {
			ShowMessage( L"リフト高さ・上昇速度(分)・リトラクト速度(分)を入力してください。" );
		}
		return;
	}

	try {
		height = Edit4->Text.ToDouble();
		upspeed = Edit5->Text.ToDouble();
		dropspeed = Edit6->Text.ToDouble();
		offTime = Edit12->Text.ToDouble();

		upspeedS = upspeed / 60.0;
		Edit7->Text = UnicodeString( upspeedS );

		dropspeedS = dropspeed / 60.0;
		Edit8->Text = UnicodeString( dropspeedS );

		upTime = height * 60.0 / upspeed;
		Edit9->Text = UnicodeString( upTime );

		dropTime = height * 60.0 / dropspeed;
		Edit10->Text = UnicodeString( dropTime );

		totalTime = upTime + dropTime;
		Edit11->Text = UnicodeString( totalTime );

		difTime = offTime - totalTime;
		Edit13->Text = UnicodeString( difTime );

		if( difTime < 0 ) {
			Edit13->Color = clYellow;
		} else {
			Edit13->Color = clWindow;
		}

	} catch (...) {
	}



}
//---------------------------------------------------------------------------
void __fastcall TForm1::O1Click(TObject *Sender)
{
	//　メインメニュー　プロファイル読込
	SpeedButton1Click( Sender );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Q1Click(TObject *Sender)
{
	//メインメニュー　終了
	Form1->Close();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
	//メインメニュー　バージョン情報

	ShowMessage( L"ChituBox LightOffDelayChecker\n            Ver. 0.1.4\n            (C)2020 White-door Inc." );
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TForm1::StripComment( UnicodeString uStrSrc )
{
	//タブやスペースや#を取り除いた文字列を返す
	UnicodeString uStr, uStrRet;
	int n, nTab, nSharp, nSpace, min;

	if( uStrSrc.IsEmpty() ) {
		return( L"" );
	}
	min = 1024;
	uStrRet = uStrSrc;

	n = uStrSrc.Pos(L"	" );
	if( n > 0 ) {
		nTab = n;
		if( min > n ) {
			min = n;
		}
	}
	n = uStrSrc.Pos(L"#" );
	if( n > 0 ) {
		nSharp = n;
		if( min > n ) {
			min = n;
		}
	}
	n = uStrSrc.Pos(L" " );
	if( n > 0 ) {
		nSpace = n;
		if( min > n ) {
			min = n;
		}
	}
	if( nTab == 0 && nSharp ==0 && nSpace == 0 ) {
		return( uStrSrc );
	}
	if( min > 1 ) {
		uStrRet = uStrSrc.SubString(0, min -1 );
	}
	return( uStrRet );

}
//---------------------------------------------------------------------------
int __fastcall TForm1::LoadFromLocalAppData( void )
{
	// ユーザー設定フォルダから読み込む
	UnicodeString uStr, uStrGlobalCfgName, uStrSrhText, uStrVersion, uStrPrnName;
	int ct, i, j, ret, n;
	bool openResult;
	UnicodeString uStrFileName, uStrPrnPath, uStrCfgName, InstName, uStrRKeyName;
	UnicodeString uStrHeight, uStrLiftSpeed, uStrDropSpeed, uStrTmp, uStrOffTime, retStr;

	uStrPrnName =  L"";
	ret = -255;

	uStrGlobalCfgName = Edit1->Text + L"\\global.cfg";

	if( !FileExists( uStrGlobalCfgName ) ) {
		return( -1);
	}
	TStringList* sl = new TStringList();

	try {
		sl->LoadFromFile( uStrGlobalCfgName, TEncoding::UTF8 );
	} catch (...) {
		delete sl;
		return( -2 );
	}
	if( sl->Count <= 0 ) {
		delete sl;
		return( -3);
	}

	TRegistry* reg = new TRegistry(KEY_READ);
	for( j =0; j < sl->Count; j++ ) {
		//
		uStr = sl->Strings[j];

		//最終バージョン文字列の取得
		uStrSrhText = L"lastVersion:v";
		n = uStr.Pos( uStrSrhText );
		if( n == 1 ) {
			uStrVersion = uStr.SubString( uStrSrhText.Length() +1, 100 );
			//ret = LoadRegData( uStrVersion );

			reg->RootKey = HKEY_CURRENT_USER;
			reg->Access = KEY_READ;

			InstName = L"CHITUBOX " + uStrVersion;
			uStrRKeyName = L"Software\\" + InstName;
			openResult = reg->OpenKey( uStrRKeyName, false );
			if(!openResult) {
				//キーが開けなかった
				InstName = L"CHITUBOX " + uStrVersion + L" Beta";
				uStrRKeyName = L"Software\\" + InstName;
				openResult = reg->OpenKey( uStrRKeyName, false );
				if(!openResult) {
					//キーが開けなかった
					break;
				} else {
					retStr = reg->ReadString( L"" );
					if( !retStr.IsEmpty() ) {
						Edit14->Text = retStr;
						ret = 0;
					}
				}
			} else {
				retStr = reg->ReadString( L"" );
				if( !retStr.IsEmpty() ) {
					Edit14->Text = retStr;
					ret = 0;
				}
			}

			if( ret == 0 ) {
				for( i =0; i < ComboBox1->Items->Count; i++ ) {
					if( ComboBox1->Items->Strings[i] == InstName ) {
						fLoaded = false;
						ComboBox1->ItemIndex = i;
						break;
					}
				}
			}

		}
		//現在のプリンター名の取得
		uStrSrhText = L"currMachine:";
		n = uStr.Pos( uStrSrhText );
		if( n == 1 ) {
			uStrPrnName = uStr.SubString( uStrSrhText.Length() +1, 100 );
			Edit3->Text = uStrPrnName;
		}
	}
	reg->Free();
	delete sl;
	//

	uStrFileName = exePath + L"\\ChiTuBox\\machine\\1.cfg";;
	if( FileExists( uStrFileName ) ) {
		Edit2->Text = uStrFileName;

		Memo1->Clear();
		Memo1->Lines->LoadFromFile( uStrFileName, TEncoding::UTF8 );
		Edit16->Text = ExtractFileName( uStrFileName );

		//@@の行を飛ばして読み込む
		for( i = 0; i < Memo1->Lines->Count; i++ ) {
			//
			uStr = Memo1->Lines->Strings[i];
			uStrTmp = uStr.SubString( 0, 2 );
			if( uStrTmp == L"@@" ) {
				continue;
			}

			uStrSrhText = L"normalLayerLiftHeight:";
			n = uStr.Pos( uStrSrhText );
			if( n == 1 ) {
				uStrHeight = uStr.SubString( uStrSrhText.Length() +1, 10 );
				Edit4->Text = StripComment( uStrHeight );
			}
			uStrSrhText = L"normalLayerLiftSpeed:";
			n = uStr.Pos( uStrSrhText );
			if( n == 1 ) {
				uStrLiftSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
				Edit5->Text = StripComment( uStrLiftSpeed );
			}
			uStrSrhText = L"normalLayerDropSpeed:";
			n = uStr.Pos( uStrSrhText );
			if( n == 1 ) {
				uStrDropSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
				Edit6->Text = StripComment( uStrDropSpeed );
			} else {
				uStrSrhText = L"normalDropSpeed:";
				n = uStr.Pos( uStrSrhText );
				if( n == 1 ) {
					uStrDropSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
					Edit6->Text = StripComment( uStrDropSpeed );
				}
			}
			uStrSrhText = L"lightOffTime:";
			n = uStr.Pos( uStrSrhText );
			if( n == 1 ) {
				uStrOffTime = uStr.SubString( uStrSrhText.Length() +1, 10 );
				Edit12->Text = StripComment( uStrOffTime );
			}

		}
		Memo1->Perform(EM_LINESCROLL, 0, Memo1->Lines->Count);

		//マシン情報を読み込む
		if( !uStrPrnName.IsEmpty() && ret == 0 && !Edit14->Text.IsEmpty() ) {
			//
			uStrCfgName = System::Sysutils::StringReplace( uStrPrnName, L" ", L"_", TReplaceFlags() << rfReplaceAll << rfIgnoreCase );
			uStrPrnPath = Edit14->Text + L"\\resource\\machine\\" +  uStrCfgName + L".cfg";
			Edit15->Text = uStrPrnPath;
			if( FileExists( uStrPrnPath ) ) {
				//読み込む
				Memo2->Clear();
				Memo2->Lines->LoadFromFile( uStrPrnPath, TEncoding::UTF8 );
				Edit17->Text = ExtractFileName( uStrPrnPath );

				for( i = 0; i < Memo2->Lines->Count; i++ ) {
					//
					uStr = Memo2->Lines->Strings[i];
					uStrTmp = uStr.SubString( 0, 2 );
					if( uStrTmp == L"@@" ) {
						continue;
					}
					if( Edit4->Text.IsEmpty() ) {
						uStrSrhText = L"normalLayerLiftHeight:";
						n = uStr.Pos( uStrSrhText );
						if( n == 1 ) {
							uStrHeight = uStr.SubString( uStrSrhText.Length() +1, 10 );
							Edit4->Text = StripComment( uStrHeight );
						}
					}
					if( Edit5->Text.IsEmpty() ) {
						uStrSrhText = L"normalLayerLiftSpeed:";
						n = uStr.Pos( uStrSrhText );
						if( n == 1 ) {
							uStrLiftSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
							Edit5->Text = StripComment( uStrLiftSpeed );
						}
					}
					if( Edit6->Text.IsEmpty() ) {
						uStrSrhText = L"normalLayerDropSpeed:";
						n = uStr.Pos( uStrSrhText );
						if( n == 1 ) {
							uStrDropSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
							Edit6->Text = StripComment( uStrDropSpeed );
						} else {
							uStrSrhText = L"normalDropSpeed:";
							n = uStr.Pos( uStrSrhText );
							if( n == 1 ) {
								uStrDropSpeed = uStr.SubString( uStrSrhText.Length() +1, 10 );
								Edit6->Text = StripComment( uStrDropSpeed );
							}
						}
					}
					if( Edit12->Text.IsEmpty() ) {
						uStrSrhText = L"lightOffTime:";
						n = uStr.Pos( uStrSrhText );
						if( n == 1 ) {
							uStrOffTime = uStr.SubString( uStrSrhText.Length() +1, 10 );
							Edit12->Text = StripComment( uStrOffTime );
						}
					}
				}
			}
		}
		if( !Edit4->Text.IsEmpty() && !Edit5->Text.IsEmpty() &&
			!Edit6->Text.IsEmpty() && !Edit12->Text.IsEmpty() ) {
			//計算を行う
            SpeedButton4Click( this );

		}
	}

	return( 0 );
}
//---------------------------------------------------------------------------

int __fastcall TForm1::LoadRegData( UnicodeString uStrKeyName )
{

	//Install Version Change
	int n;
	UnicodeString uStr, retStr, uStrRKeyName;

	uStrRKeyName = L"Software\\CHITUBOX " + uStrKeyName;

	TRegistry* reg = new TRegistry(KEY_READ);
	reg->RootKey = HKEY_CURRENT_USER;

	reg->Access = KEY_READ;
	bool openResult = reg->OpenKey( uStrRKeyName, false );
	if(!openResult) {
		//キーが作成出来なかった
		if( CheckBox1->Checked ) {
			ShowMessage( ComboBox1->Items->Strings[ ComboBox1->ItemIndex ] + L" doesn't seem to be installed." );
		} else {
			ShowMessage( ComboBox1->Items->Strings[ ComboBox1->ItemIndex ] + L" はインストールされていないようです。" );
		}
		reg->Free();
		return( -1 );
	} else {
		retStr = reg->ReadString( L"" );
		if( !retStr.IsEmpty() ) {
			Edit14->Text = retStr;
		} else {
			if( CheckBox1->Checked ) {
				ShowMessage( ComboBox1->Items->Strings[ ComboBox1->ItemIndex ] + L" のインストール先が設定されていませんでした。" );
			} else {
				ShowMessage( ComboBox1->Items->Strings[ ComboBox1->ItemIndex ] + L"\nThe installation destination was not set." );
			}
			reg->Free();
			return( -2 );
		}
	}
	reg->Free();
	return( 0 );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	//日本語・英語表示切り替え
	if( CheckBox1->Checked ) {
		//英語
		SpeedButton1->Caption = L"Open AppData Folder";
		SpeedButton2->Caption = L"Read Profile";
		SpeedButton3->Caption = L"Read PrinterInfo";
		SpeedButton4->Caption = L"Calc the Required Time";

		FileF1->Caption = L"File(&F)";
		N1->Caption = L"Open AppData Folder";
		O1->Caption = L"Read Profile(&O)";
		W1->Caption = L"Close(&W)";
		Q1->Caption = L"Quit(&Q)";
		I1->Caption = L"Config(&I)";
		N2->Caption = L"About this Program";

		Label1->Caption = L"Folder Path";
		Label2->Caption = L"Profile FileName";
		Label3->Caption = L"Printer Name";
		Label4->Caption = L"Lift Height (mm)";
		Label5->Caption = L"Lift Speed (mm/min)";
		Label6->Caption = L"Retract Speed (mm/min)";
		Label7->Caption = L"⇒　Lift Speed (mm/sec)";
		Label8->Caption = L"⇒　Retract Speed (mm/sec)";
		Label9->Caption = L"Lift Time Required (sec)";
		Label10->Caption = L"Retract Time Required (sec)";
		Label11->Caption = L"Total Time Required (sec)";
		Label12->Caption = L"Light Off Time (sec)";
		Label13->Caption = L"Installed Version";
		Label14->Caption = L"Install Folder";
		Label15->Caption = L"Light Off Time - Total Time Required (sec)";
		Label16->Caption = L"Printer Info FileName";

	} else {
		//日本語
		SpeedButton1->Caption = L"設定フォルダを開く";
		SpeedButton2->Caption = L"プロファイルの読込";
		SpeedButton3->Caption = L"プリンタ情報の読込";
		SpeedButton4->Caption = L"計算";

		FileF1->Caption = L"File(&F)";
		N1->Caption = L"設定フォルダを開く";
		O1->Caption = L"プロファイルの読込(&O)";
		W1->Caption = L"閉じる(&W)";
		Q1->Caption = L"終了(&Q)";
		I1->Caption = L"設定(&I)";
		N2->Caption = L"バージョン情報";

		Label1->Caption = L"フォルダパス";
		Label2->Caption = L"プロファイル名";
		Label3->Caption = L"プリンター名";
		Label4->Caption = L"リフト高さ(mm)";
		Label5->Caption = L"上昇速度(mm/分)";
		Label6->Caption = L"リトラクト速度(mm/分)";
		Label7->Caption = L"⇒　上昇速度(mm/秒)";
		Label8->Caption = L"⇒　リトラクト速度(mm/秒)";
		Label9->Caption = L"上昇所用時間(秒)";
		Label10->Caption = L"リトラクト所用時間(秒)";
		Label11->Caption = L"合計所用時間(秒)";
		Label12->Caption = L"消灯遅延時間(秒)";
		Label13->Caption = L"インストールバージョン";
		Label14->Caption = L"インストール先";
		Label15->Caption = L"消灯遅延時間　－　合計所用時間(秒)";
		Label16->Caption = L"マシン設定ファイル";

	}
}
//---------------------------------------------------------------------------

