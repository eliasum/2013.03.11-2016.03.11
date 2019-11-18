object Form4: TForm4
  Left = 681
  Top = 284
  Width = 402
  Height = 272
  Caption = 'Register 1 Settings'
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
  object GroupBox1: TGroupBox
    Left = 20
    Top = 20
    Width = 355
    Height = 129
    Caption = 'Phase'
    TabOrder = 0
    object StaticText1: TStaticText
      Left = 128
      Top = 20
      Width = 86
      Height = 20
      Caption = '0 -> 4095 Only'
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 98
      Top = 49
      Width = 149
      Height = 24
      TabOrder = 1
      Text = '1'
      OnChange = Edit1Change
    end
  end
  object Button1: TButton
    Left = 59
    Top = 177
    Width = 110
    Height = 41
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 217
    Top = 177
    Width = 109
    Height = 41
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = Button2Click
  end
end
