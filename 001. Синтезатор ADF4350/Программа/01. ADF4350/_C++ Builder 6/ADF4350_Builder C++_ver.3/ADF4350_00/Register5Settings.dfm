object Form8: TForm8
  Left = 712
  Top = 333
  Width = 313
  Height = 169
  Caption = 'Register 5 Settings'
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
  object ComboBox1: TComboBox
    Left = 118
    Top = 10
    Width = 179
    Height = 24
    Hint = 'Default=Digital Lock Detect'
    ItemHeight = 16
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
    Left = 10
    Top = 10
    Width = 97
    Height = 20
    Caption = 'Lock Detect Pin'
    TabOrder = 1
  end
  object Button1: TButton
    Left = 20
    Top = 69
    Width = 109
    Height = 41
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 177
    Top = 69
    Width = 110
    Height = 41
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = Button2Click
  end
end
