object F_Sar2: TF_Sar2
  Left = 282
  Top = 143
  AutoScroll = False
  Caption = #1044#1072#1085#1099#1077' sar '#8470'2'
  ClientHeight = 113
  ClientWidth = 881
  Color = clBtnFace
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
    Left = 696
    Top = 8
    Width = 176
    Height = 78
    Caption = 
      #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'#13#10#1054#1073#1086#1079#1085#1072#1095#1077#1085#1080#1103' '#1088#1072#1073#1086#1095#1080#1093' '#1076#1080#1072#1087#1072#1079#1086#1085#1086#1074':'#13#10'1 - 7800...11300 '#1052 +
      #1075#1094';'#13#10'2 - 10200...13500 '#1052#1075#1094';'#13#10'3 - 12500...15700 '#1052#1075#1094';'#13#10'4 - 14700..' +
      '.18500 '#1052#1075#1094'.'
    Constraints.MaxHeight = 78
    Constraints.MaxWidth = 176
    Constraints.MinHeight = 78
    Constraints.MinWidth = 176
  end
  object StaticText1: TStaticText
    Left = 24
    Top = 8
    Width = 87
    Height = 17
    Caption = #1050#1086#1101#1092'. '#1091#1089#1080#1083#1077#1085#1080#1103' '
    TabOrder = 0
  end
  object StaticText2: TStaticText
    Left = 136
    Top = 8
    Width = 84
    Height = 17
    Caption = #1050#1086#1101#1092'. '#1091#1089#1080#1083#1077#1085#1080#1103
    TabOrder = 1
  end
  object StaticText3: TStaticText
    Left = 248
    Top = 8
    Width = 79
    Height = 17
    Caption = #1063#1072#1089#1090#1086#1090#1072' '#1089#1088#1077#1079#1072
    TabOrder = 2
  end
  object StaticText4: TStaticText
    Left = 352
    Top = 8
    Width = 79
    Height = 17
    Caption = #1063#1072#1089#1090#1086#1090#1072' '#1089#1088#1077#1079#1072
    TabOrder = 3
  end
  object B_OK: TButton
    Left = 352
    Top = 72
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 4
    OnClick = B_OKClick
  end
  object B_Cancel: TButton
    Left = 456
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 5
    OnClick = B_CancelClick
  end
  object StaticText5: TStaticText
    Left = 24
    Top = 24
    Width = 87
    Height = 17
    Caption = #1091#1089#1080#1083#1080#1090#1077#1083#1103' 1 ['#1076#1041']'
    TabOrder = 6
  end
  object StaticText6: TStaticText
    Left = 136
    Top = 24
    Width = 87
    Height = 17
    Caption = #1091#1089#1080#1083#1080#1090#1077#1083#1103' 2 ['#1076#1041']'
    TabOrder = 7
  end
  object StaticText7: TStaticText
    Left = 248
    Top = 24
    Width = 91
    Height = 17
    Caption = #1092#1080#1083#1100#1090#1088#1072' 1 ['#1075#1088#1072#1076'.]'
    TabOrder = 8
  end
  object StaticText8: TStaticText
    Left = 352
    Top = 24
    Width = 91
    Height = 17
    Caption = #1092#1080#1083#1100#1090#1088#1072' 2 ['#1075#1088#1072#1076'.]'
    TabOrder = 9
  end
  object StaticText9: TStaticText
    Left = 464
    Top = 8
    Width = 97
    Height = 17
    Caption = #1056#1072#1073#1086#1095#1080#1081' '#1076#1080#1072#1087#1072#1079#1086#1085
    TabOrder = 10
  end
  object StaticText10: TStaticText
    Left = 480
    Top = 24
    Width = 60
    Height = 17
    Caption = #1087#1088#1080#1105#1084#1085#1080#1082#1072
    TabOrder = 11
  end
  object StaticText11: TStaticText
    Left = 576
    Top = 8
    Width = 97
    Height = 17
    Caption = #1056#1072#1073#1086#1095#1080#1081' '#1076#1080#1072#1087#1072#1079#1086#1085
    TabOrder = 12
  end
  object StaticText12: TStaticText
    Left = 592
    Top = 24
    Width = 68
    Height = 17
    Caption = #1087#1077#1088#1077#1076#1072#1090#1095#1080#1082#1072
    TabOrder = 13
  end
  object CB_1: TComboBox
    Left = 16
    Top = 40
    Width = 110
    Height = 21
    ItemHeight = 13
    TabOrder = 14
    Text = '0'
    OnChange = CB_1Change
    Items.Strings = (
      '0'
      '0,5'
      '1'
      '1,5'
      '2'
      '2,5'
      '3'
      '3,5'
      '4'
      '4,5'
      '5'
      '5,5'
      '6'
      '6,5'
      '7'
      '7,5'
      '8'
      '8,5'
      '9'
      '9,5'
      '10'
      '10,5'
      '11'
      '11,5'
      '12'
      '12,5'
      '13'
      '13,5'
      '14'
      '14,5'
      '15'
      '15,5'
      '16'
      '16,5'
      '17'
      '17,5'
      '18'
      '18,5'
      '19'
      '19,5'
      '20'
      '20,5'
      '21'
      '21,5'
      '22'
      '22,5'
      '23'
      '23,5'
      '24'
      '24,5'
      '25'
      '25,5'
      '26'
      '26,5'
      '27'
      '27,5'
      '28'
      '28,5'
      '29'
      '29,5'
      '30'
      '30,5'
      '31'
      '31,5')
  end
  object CB_2: TComboBox
    Left = 128
    Top = 40
    Width = 110
    Height = 21
    ItemHeight = 13
    TabOrder = 15
    Text = '0'
    OnChange = CB_2Change
    Items.Strings = (
      '0'
      '0,5'
      '1'
      '1,5'
      '2'
      '2,5'
      '3'
      '3,5'
      '4'
      '4,5'
      '5'
      '5,5'
      '6'
      '6,5'
      '7'
      '7,5'
      '8'
      '8,5'
      '9'
      '9,5'
      '10'
      '10,5'
      '11'
      '11,5'
      '12'
      '12,5'
      '13'
      '13,5'
      '14'
      '14,5'
      '15'
      '15,5'
      '16'
      '16,5'
      '17'
      '17,5'
      '18'
      '18,5'
      '19'
      '19,5'
      '20'
      '20,5'
      '21'
      '21,5'
      '22'
      '22,5'
      '23'
      '23,5'
      '24'
      '24,5'
      '25'
      '25,5'
      '26'
      '26,5'
      '27'
      '27,5'
      '28'
      '28,5'
      '29'
      '29,5'
      '30'
      '30,5'
      '31'
      '31,5')
  end
  object CB_3: TComboBox
    Left = 240
    Top = 40
    Width = 110
    Height = 21
    ItemHeight = 13
    TabOrder = 16
    Text = '970'
    OnChange = CB_3Change
    Items.Strings = (
      '970'
      '1000'
      '1030'
      '1055'
      '1085'
      '1120'
      '1155'
      '1195'
      '2335'
      '2430'
      '2530'
      '2655'
      '2770'
      '2940'
      '3145'
      '3400')
  end
  object CB_4: TComboBox
    Left = 352
    Top = 40
    Width = 110
    Height = 21
    ItemHeight = 13
    TabOrder = 17
    Text = '970'
    OnChange = CB_4Change
    Items.Strings = (
      '970'
      '1000'
      '1030'
      '1055'
      '1085'
      '1120'
      '1155'
      '1195'
      '2335'
      '2430'
      '2530'
      '2655'
      '2770'
      '2940'
      '3145'
      '3400')
  end
  object CB_5: TComboBox
    Left = 464
    Top = 40
    Width = 110
    Height = 21
    ItemHeight = 13
    TabOrder = 18
    Text = '1'
    OnChange = CB_5Change
    Items.Strings = (
      '1'
      '2'
      '3'
      '4')
  end
  object CB_6: TComboBox
    Left = 576
    Top = 40
    Width = 110
    Height = 21
    ItemHeight = 13
    TabOrder = 19
    Text = '1'
    OnChange = CB_6Change
    Items.Strings = (
      '1'
      '2'
      '3'
      '4')
  end
end
