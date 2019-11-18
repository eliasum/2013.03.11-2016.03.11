object Form2: TForm2
  Left = 625
  Top = 220
  Width = 458
  Height = 297
  Caption = 'FastLock'
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
  object StaticText1: TStaticText
    Left = 98
    Top = 10
    Width = 226
    Height = 24
    Caption = 'Enter Fast lock Timer Value'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 138
    Top = 49
    Width = 149
    Height = 24
    TabOrder = 1
    Text = '150'
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 138
    Top = 98
    Width = 149
    Height = 24
    Enabled = False
    TabOrder = 2
    Text = '15'
  end
  object Edit3: TEdit
    Left = 138
    Top = 148
    Width = 149
    Height = 24
    Enabled = False
    TabOrder = 3
    Text = '0'
  end
  object StaticText2: TStaticText
    Left = 295
    Top = 59
    Width = 84
    Height = 20
    Caption = 'Clk Div Value'
    TabOrder = 4
  end
  object StaticText3: TStaticText
    Left = 295
    Top = 108
    Width = 131
    Height = 20
    Caption = 'BW Time Interval [us]'
    TabOrder = 5
  end
  object StaticText4: TStaticText
    Left = 295
    Top = 158
    Width = 66
    Height = 20
    Caption = 'PFD[MHz]'
    TabOrder = 6
  end
  object Button1: TButton
    Left = 79
    Top = 207
    Width = 109
    Height = 40
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 7
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 246
    Top = 207
    Width = 110
    Height = 40
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 8
    OnClick = Button2Click
  end
end
