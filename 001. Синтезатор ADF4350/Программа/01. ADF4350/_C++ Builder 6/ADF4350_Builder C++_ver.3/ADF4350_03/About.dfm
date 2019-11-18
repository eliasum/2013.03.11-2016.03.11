object Form3: TForm3
  Left = 577
  Top = 434
  BorderStyle = bsDialog
  Caption = 'About'
  ClientHeight = 193
  ClientWidth = 454
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 176
    Top = 144
    Width = 89
    Height = 33
    Caption = 'OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object StaticText17: TStaticText
    Left = -1
    Top = 0
    Width = 122
    Height = 31
    Caption = '   eliasum   '
    Color = clBlue
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWhite
    Font.Height = -19
    Font.Name = 'Arial Black'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 1
  end
  object StaticText1: TStaticText
    Left = 16
    Top = 48
    Width = 423
    Height = 20
    Caption = #1055#1072#1084#1103#1090#1080' '#1084#1086#1077#1075#1086' '#1086#1090#1094#1072' '#1052#1080#1085#1080#1085#1072' '#1052#1080#1093#1072#1080#1083#1072' '#1042#1072#1089#1080#1083#1100#1077#1074#1080#1095#1072' '#1087#1086#1089#1074#1103#1097#1072#1077#1090#1089#1103'.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object StaticText2: TStaticText
    Left = 120
    Top = 80
    Width = 212
    Height = 20
    Caption = #1052#1080#1085#1080#1085' '#1048#1083#1100#1103' '#1052#1080#1093#1072#1081#1083#1086#1074#1080#1095', 2013 '#1075'.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object StaticText3: TStaticText
    Left = 152
    Top = 112
    Width = 138
    Height = 20
    Cursor = crHandPoint
    Caption = 'eliasum@yandex.com'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    TabOrder = 4
    OnClick = StaticText3Click
    OnMouseDown = StaticText3MouseDown
    OnMouseUp = StaticText3MouseUp
  end
end
