object Form8: TForm8
  Left = 717
  Top = 337
  Width = 258
  Height = 141
  Caption = 'Register 5 Settings'
  Color = clBtnFace
  Constraints.MaxHeight = 141
  Constraints.MaxWidth = 258
  Constraints.MinHeight = 141
  Constraints.MinWidth = 258
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
  object ComboBox1: TComboBox
    Left = 96
    Top = 8
    Width = 145
    Height = 21
    Hint = 'Default=Digital Lock Detect'
    ItemHeight = 13
    ItemIndex = 0
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    Text = 'Digital Lock Detect'
    OnChange = ComboBox1Change
    Items.Strings = (
      'Digital Lock Detect'
      'Low'
      'High')
  end
  object StaticText1: TStaticText
    Left = 8
    Top = 8
    Width = 81
    Height = 17
    Caption = 'Lock Detect Pin'
    TabOrder = 1
  end
  object Button1: TButton
    Left = 16
    Top = 56
    Width = 89
    Height = 33
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 144
    Top = 56
    Width = 89
    Height = 33
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = Button2Click
  end
end
