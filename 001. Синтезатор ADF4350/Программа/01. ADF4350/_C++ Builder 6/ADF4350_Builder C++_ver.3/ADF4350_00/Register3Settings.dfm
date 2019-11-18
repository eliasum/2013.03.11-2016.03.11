object Form6: TForm6
  Left = 601
  Top = 186
  Width = 297
  Height = 421
  Caption = 'Register 3 Settings'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 59
    Top = 286
    Width = 174
    Height = 16
    Caption = 'tsync >= worst case lock time!'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object CheckBox1: TCheckBox
    Left = 89
    Top = 10
    Width = 119
    Height = 21
    Caption = 'Phase Resync'
    TabOrder = 0
    OnClick = CheckBox1Click
  end
  object GroupBox1: TGroupBox
    Left = 30
    Top = 39
    Width = 227
    Height = 130
    Caption = 'CLK DIV VALUE'
    TabOrder = 1
    object StaticText1: TStaticText
      Left = 69
      Top = 30
      Width = 86
      Height = 20
      Caption = '1 -> 4095 Only'
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 49
      Top = 59
      Width = 110
      Height = 24
      TabOrder = 1
      Text = '0'
      OnChange = Edit1Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 30
    Top = 187
    Width = 227
    Height = 90
    Caption = 'tsync'
    TabOrder = 2
    object Edit2: TEdit
      Left = 49
      Top = 30
      Width = 110
      Height = 24
      Enabled = False
      TabOrder = 0
      Text = '0'
    end
    object StaticText2: TStaticText
      Left = 167
      Top = 30
      Width = 18
      Height = 20
      Caption = 'us'
      TabOrder = 1
    end
  end
  object Button1: TButton
    Left = 20
    Top = 325
    Width = 99
    Height = 41
    Caption = 'OK'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 167
    Top = 325
    Width = 100
    Height = 41
    Caption = 'Cancel'
    TabOrder = 4
    OnClick = Button2Click
  end
end
