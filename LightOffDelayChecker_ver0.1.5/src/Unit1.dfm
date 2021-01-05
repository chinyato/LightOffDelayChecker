object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'LightOffDelayChecker'
  ClientHeight = 657
  ClientWidth = 884
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object SpeedButton1: TSpeedButton
    Left = 479
    Top = 0
    Width = 153
    Height = 49
    Caption = #35373#23450#12501#12457#12523#12480#12434#38283#12367
    OnClick = SpeedButton1Click
  end
  object SpeedButton2: TSpeedButton
    Left = 8
    Top = 0
    Width = 153
    Height = 49
    Caption = #12503#12525#12501#12449#12452#12523#12398#35501#36796
    OnClick = SpeedButton2Click
  end
  object SpeedButton3: TSpeedButton
    Left = 318
    Top = 0
    Width = 155
    Height = 49
    Caption = #12503#12522#12531#12479#24773#22577#12398#35501#36796
    Visible = False
    OnClick = SpeedButton3Click
  end
  object SpeedButton4: TSpeedButton
    Left = 167
    Top = 0
    Width = 145
    Height = 49
    Caption = #35336#31639
    OnClick = SpeedButton4Click
  end
  object Label1: TLabel
    Left = 6
    Top = 194
    Width = 54
    Height = 13
    Caption = #12501#12457#12523#12480#12497#12473
    Visible = False
  end
  object Label2: TLabel
    Left = 6
    Top = 114
    Width = 64
    Height = 13
    Caption = #12503#12525#12501#12449#12452#12523#21517
  end
  object Label3: TLabel
    Left = 6
    Top = 141
    Width = 55
    Height = 13
    Caption = #12503#12522#12531#12479#12540#21517
  end
  object Label4: TLabel
    Left = 8
    Top = 227
    Width = 67
    Height = 13
    Caption = #12522#12501#12488#39640#12373'(mm)'
  end
  object Label5: TLabel
    Left = 8
    Top = 254
    Width = 88
    Height = 13
    Caption = #19978#26119#36895#24230'(mm/'#20998')'
  end
  object Label6: TLabel
    Left = 8
    Top = 281
    Width = 103
    Height = 13
    Caption = #12522#12488#12521#12463#12488#36895#24230'(mm/'#20998')'
  end
  object Label7: TLabel
    Left = 248
    Top = 254
    Width = 105
    Height = 13
    Caption = #8658#12288#19978#26119#36895#24230'(mm/'#31186')'
  end
  object Label8: TLabel
    Left = 248
    Top = 281
    Width = 120
    Height = 13
    Caption = #8658#12288#12522#12488#12521#12463#12488#36895#24230'(mm/'#31186')'
  end
  object Label9: TLabel
    Left = 536
    Top = 254
    Width = 92
    Height = 13
    Caption = #19978#26119#25152#29992#26178#38291'('#31186')'
  end
  object Label10: TLabel
    Left = 535
    Top = 281
    Width = 107
    Height = 13
    Caption = #12522#12488#12521#12463#12488#25152#29992#26178#38291'('#31186')'
  end
  object Label11: TLabel
    Left = 536
    Top = 308
    Width = 92
    Height = 13
    Caption = #21512#35336#25152#29992#26178#38291'('#31186')'
  end
  object Label12: TLabel
    Left = 8
    Top = 334
    Width = 92
    Height = 13
    Caption = #28040#28783#36933#24310#26178#38291'('#31186')'
  end
  object Label13: TLabel
    Left = 6
    Top = 60
    Width = 100
    Height = 13
    Caption = #12452#12531#12473#12488#12540#12523#12496#12540#12472#12519#12531
  end
  object Label14: TLabel
    Left = 6
    Top = 87
    Width = 67
    Height = 13
    Caption = #12452#12531#12473#12488#12540#12523#20808
  end
  object Label15: TLabel
    Left = 450
    Top = 334
    Width = 192
    Height = 13
    Caption = #28040#28783#36933#24310#26178#38291#12288#65293#12288#21512#35336#25152#29992#26178#38291'('#31186')'
  end
  object Label16: TLabel
    Left = 8
    Top = 167
    Width = 86
    Height = 13
    Caption = #12510#12471#12531#35373#23450#12501#12449#12452#12523
  end
  object Label17: TLabel
    Left = 384
    Top = 60
    Width = 95
    Height = 13
    Caption = #35373#23450#20445#23384#12501#12457#12523#12480#21517
  end
  object Edit1: TEdit
    Left = 144
    Top = 190
    Width = 625
    Height = 21
    TabOrder = 0
    Visible = False
  end
  object Edit2: TEdit
    Left = 144
    Top = 109
    Width = 625
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 144
    Top = 136
    Width = 625
    Height = 21
    TabOrder = 2
  end
  object Memo1: TMemo
    Left = 8
    Top = 385
    Width = 425
    Height = 264
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 3
  end
  object Edit4: TEdit
    Left = 144
    Top = 224
    Width = 89
    Height = 21
    Color = clSkyBlue
    TabOrder = 4
  end
  object Edit5: TEdit
    Left = 144
    Top = 251
    Width = 89
    Height = 21
    Color = clSkyBlue
    TabOrder = 5
  end
  object Edit6: TEdit
    Left = 144
    Top = 278
    Width = 89
    Height = 21
    Color = clSkyBlue
    TabOrder = 6
  end
  object Edit7: TEdit
    Left = 399
    Top = 251
    Width = 114
    Height = 21
    TabOrder = 7
  end
  object Edit8: TEdit
    Left = 399
    Top = 278
    Width = 114
    Height = 21
    TabOrder = 8
  end
  object Edit9: TEdit
    Left = 680
    Top = 251
    Width = 89
    Height = 21
    TabOrder = 9
  end
  object Edit10: TEdit
    Left = 680
    Top = 278
    Width = 89
    Height = 21
    TabOrder = 10
  end
  object Edit11: TEdit
    Left = 680
    Top = 305
    Width = 89
    Height = 21
    TabOrder = 11
  end
  object Edit12: TEdit
    Left = 144
    Top = 331
    Width = 89
    Height = 21
    Color = clSkyBlue
    TabOrder = 12
  end
  object Edit13: TEdit
    Left = 680
    Top = 331
    Width = 89
    Height = 21
    TabOrder = 13
  end
  object ComboBox1: TComboBox
    Left = 144
    Top = 55
    Width = 224
    Height = 21
    DropDownCount = 20
    ItemIndex = 14
    TabOrder = 14
    Text = 'CHITUBOX 1.8.0 Beta'
    OnChange = ComboBox1Change
    Items.Strings = (
      'CHITUBOX 1.2.0'
      'CHITUBOX 1.3.0'
      'CHITUBOX 1.4.0'
      'CHITUBOX 1.5.0'
      'CHITUBOX 1.6.1'
      'CHITUBOX 1.6.2'
      'CHITUBOX 1.6.3'
      'CHITUBOX 1.6.4.1'
      'CHITUBOX 1.6.4.2 Beta'
      'CHITUBOX 1.6.4.3 Beta'
      'CHITUBOX 1.6.4.3'
      'CHITUBOX 1.6.5'
      'CHITUBOX 1.6.5.1'
      'CHITUBOX 1.7.0'
      'CHITUBOX 1.8.0 Beta'
      'CHITUBOX 1.8.0')
  end
  object Edit14: TEdit
    Left = 144
    Top = 82
    Width = 625
    Height = 21
    TabOrder = 15
    Text = 'C:\Program Files\CHITUBOX64 1.7.0'
  end
  object Memo2: TMemo
    Left = 439
    Top = 385
    Width = 437
    Height = 264
    Lines.Strings = (
      'Memo2')
    ScrollBars = ssBoth
    TabOrder = 16
  end
  object Edit15: TEdit
    Left = 144
    Top = 163
    Width = 625
    Height = 21
    ReadOnly = True
    TabOrder = 17
  end
  object Edit16: TEdit
    Left = 8
    Top = 358
    Width = 425
    Height = 21
    Color = clMedGray
    Enabled = False
    ReadOnly = True
    TabOrder = 18
  end
  object Edit17: TEdit
    Left = 439
    Top = 358
    Width = 437
    Height = 21
    Color = clMedGray
    Enabled = False
    ReadOnly = True
    TabOrder = 19
  end
  object CheckBox1: TCheckBox
    Left = 664
    Top = 8
    Width = 145
    Height = 17
    Caption = 'Language: English'
    TabOrder = 20
    OnClick = CheckBox1Click
  end
  object ComboBox2: TComboBox
    Left = 576
    Top = 55
    Width = 193
    Height = 21
    DropDownCount = 20
    ItemIndex = 14
    TabOrder = 21
    Text = 'ChiTuBox v1.8.0'
    Items.Strings = (
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox'
      'ChiTuBox v1.8.0'
      'ChiTuBox v1.8.0')
  end
  object MainMenu1: TMainMenu
    Left = 808
    Top = 136
    object FileF1: TMenuItem
      Caption = 'File(&F)'
      object N1: TMenuItem
        Caption = #35373#23450#12501#12457#12523#12480#12434#38283#12367
        Visible = False
      end
      object O1: TMenuItem
        Caption = #12503#12525#12501#12449#12452#12523#12398#35501#36796'(&O)'
        OnClick = O1Click
      end
      object W1: TMenuItem
        Caption = #38281#12376#12427'(&W)'
        Visible = False
      end
      object Q1: TMenuItem
        Caption = #32066#20102'(&Q)'
        OnClick = Q1Click
      end
    end
    object I1: TMenuItem
      Caption = #35373#23450'(&I)'
      object N2: TMenuItem
        Caption = #12496#12540#12472#12519#12531#24773#22577
        OnClick = N2Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 808
    Top = 80
  end
end
