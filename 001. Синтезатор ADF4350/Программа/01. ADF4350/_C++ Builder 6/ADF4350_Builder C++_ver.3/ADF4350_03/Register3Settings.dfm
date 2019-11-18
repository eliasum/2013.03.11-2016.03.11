object Form6: TForm6
  Left = 606
  Top = 189
  Width = 240
  Height = 353
  Caption = 'Register 3 Settings'
  Color = clBtnFace
  Constraints.MaxHeight = 353
  Constraints.MaxWidth = 240
  Constraints.MinHeight = 353
  Constraints.MinWidth = 240
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 232
    Width = 142
    Height = 13
    Caption = 'tsync >= worst case lock time!'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object CheckBox1: TCheckBox
    Left = 72
    Top = 8
    Width = 97
    Height = 17
    Caption = 'Phase Resync'
    TabOrder = 0
    OnClick = CheckBox1Click
  end
  object GroupBox1: TGroupBox
    Left = 24
    Top = 32
    Width = 185
    Height = 105
    Caption = 'CLK DIV VALUE'
    TabOrder = 1
    object StaticText1: TStaticText
      Left = 56
      Top = 24
      Width = 73
      Height = 17
      Caption = '1 -> 4095 Only'
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 40
      Top = 48
      Width = 89
      Height = 21
      TabOrder = 1
      Text = '0'
      OnChange = Edit1Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 24
    Top = 152
    Width = 185
    Height = 73
    Caption = 'tsync'
    TabOrder = 2
    object Edit2: TEdit
      Left = 40
      Top = 24
      Width = 89
      Height = 21
      Enabled = False
      TabOrder = 0
      Text = '0'
    end
    object StaticText2: TStaticText
      Left = 136
      Top = 24
      Width = 15
      Height = 17
      Caption = 'us'
      TabOrder = 1
    end
  end
  object Button1: TButton
    Left = 16
    Top = 264
    Width = 81
    Height = 33
    Caption = 'OK'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 136
    Top = 264
    Width = 81
    Height = 33
    Caption = 'Cancel'
    TabOrder = 4
    OnClick = Button2Click
  end
end
