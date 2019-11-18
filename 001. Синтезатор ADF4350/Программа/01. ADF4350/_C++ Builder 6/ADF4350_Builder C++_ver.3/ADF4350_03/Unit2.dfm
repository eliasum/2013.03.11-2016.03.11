object Form2: TForm2
  Left = 630
  Top = 224
  Width = 368
  Height = 250
  Caption = 'FastLock'
  Color = clBtnFace
  Constraints.MaxHeight = 250
  Constraints.MaxWidth = 368
  Constraints.MinHeight = 250
  Constraints.MinWidth = 368
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
  object StaticText1: TStaticText
    Left = 80
    Top = 8
    Width = 195
    Height = 20
    Caption = 'Enter Fast lock Timer Value'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 112
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '150'
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 112
    Top = 80
    Width = 121
    Height = 21
    Enabled = False
    TabOrder = 2
    Text = '15'
  end
  object Edit3: TEdit
    Left = 112
    Top = 120
    Width = 121
    Height = 21
    Enabled = False
    TabOrder = 3
    Text = '0'
  end
  object StaticText2: TStaticText
    Left = 240
    Top = 48
    Width = 68
    Height = 17
    Caption = 'Clk Div Value'
    TabOrder = 4
  end
  object StaticText3: TStaticText
    Left = 240
    Top = 88
    Width = 106
    Height = 17
    Caption = 'BW Time Interval [us]'
    TabOrder = 5
  end
  object StaticText4: TStaticText
    Left = 240
    Top = 128
    Width = 53
    Height = 17
    Caption = 'PFD[MHz]'
    TabOrder = 6
  end
  object Button1: TButton
    Left = 64
    Top = 168
    Width = 89
    Height = 33
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 7
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 200
    Top = 168
    Width = 89
    Height = 33
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 8
    OnClick = Button2Click
  end
end
