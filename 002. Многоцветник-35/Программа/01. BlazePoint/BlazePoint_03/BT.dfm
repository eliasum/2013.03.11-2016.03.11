object F_BT: TF_BT
  Left = 276
  Top = 398
  AutoScroll = False
  Caption = #1044#1072#1085#1085#1099#1077' '#1041#1058
  ClientHeight = 97
  ClientWidth = 409
  Color = clBtnFace
  Constraints.MaxHeight = 131
  Constraints.MaxWidth = 417
  Constraints.MinHeight = 131
  Constraints.MinWidth = 417
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
  object E_1: TEdit
    Left = 8
    Top = 32
    Width = 100
    Height = 21
    TabOrder = 0
    OnChange = E_1Change
  end
  object E_2: TEdit
    Left = 104
    Top = 32
    Width = 100
    Height = 21
    TabOrder = 1
    OnChange = E_2Change
  end
  object E_3: TEdit
    Left = 200
    Top = 32
    Width = 100
    Height = 21
    TabOrder = 2
    OnChange = E_3Change
  end
  object E_4: TEdit
    Left = 296
    Top = 32
    Width = 100
    Height = 21
    TabOrder = 3
    OnChange = E_4Change
  end
  object StaticText1: TStaticText
    Left = 24
    Top = 8
    Width = 55
    Height = 17
    Caption = #1053#1086#1084#1077#1088' '#1041#1058
    TabOrder = 4
  end
  object StaticText2: TStaticText
    Left = 104
    Top = 8
    Width = 91
    Height = 17
    Caption = #1050#1086#1086#1088#1076#1080#1085#1072#1090#1072' X ['#1084']'
    TabOrder = 5
  end
  object StaticText3: TStaticText
    Left = 200
    Top = 8
    Width = 91
    Height = 17
    Caption = #1050#1086#1086#1088#1076#1080#1085#1072#1090#1072' Y ['#1084']'
    TabOrder = 6
  end
  object StaticText4: TStaticText
    Left = 312
    Top = 8
    Width = 55
    Height = 17
    Caption = #1069#1055#1056' ['#1084'^2]'
    TabOrder = 7
  end
  object B_OK: TButton
    Left = 112
    Top = 64
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 8
    OnClick = B_OKClick
  end
  object B_Cancel: TButton
    Left = 216
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 9
    OnClick = B_CancelClick
  end
end
