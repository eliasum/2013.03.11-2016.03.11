object Form4: TForm4
  Left = 686
  Top = 288
  Width = 328
  Height = 225
  Caption = 'Register 1 Settings'
  Color = clBtnFace
  Constraints.MaxHeight = 225
  Constraints.MaxWidth = 328
  Constraints.MinHeight = 225
  Constraints.MinWidth = 328
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
  object GroupBox1: TGroupBox
    Left = 16
    Top = 16
    Width = 289
    Height = 105
    Caption = 'Phase'
    TabOrder = 0
    object StaticText1: TStaticText
      Left = 104
      Top = 16
      Width = 73
      Height = 17
      Caption = '0 -> 4095 Only'
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 80
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '1'
      OnChange = Edit1Change
    end
  end
  object Button1: TButton
    Left = 48
    Top = 144
    Width = 89
    Height = 33
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 176
    Top = 144
    Width = 89
    Height = 33
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = Button2Click
  end
end
