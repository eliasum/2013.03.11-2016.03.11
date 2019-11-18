object MainForm: TMainForm
  Left = 258
  Top = 330
  Width = 1035
  Height = 571
  Caption = #1057#1090#1077#1085#1076' '#1054#1076#1085#1086#1094#1074#1077#1090#1085#1080#1082#1086#1074
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object L_Danger: TLabel
    Left = 16
    Top = 472
    Width = 68
    Height = 16
    Caption = 'L_Danger'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 498
    Width = 1027
    Height = 19
    Panels = <>
  end
  object GB_Channel1: TGroupBox
    Left = 16
    Top = 32
    Width = 177
    Height = 433
    Caption = #1050#1072#1085#1072#1083' '#8470'1'
    TabOrder = 1
    object LE_U_IPO1: TLabeledEdit
      Left = 8
      Top = 96
      Width = 121
      Height = 21
      EditLabel.Width = 62
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1055#1054'1'
      ReadOnly = True
      TabOrder = 0
      Text = '0'
    end
    object StaticText1: TStaticText
      Left = 136
      Top = 104
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 1
    end
    object LE_I_IPO1: TLabeledEdit
      Left = 8
      Top = 48
      Width = 121
      Height = 21
      EditLabel.Width = 52
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1055#1054'1'
      ReadOnly = True
      TabOrder = 2
      Text = '0'
    end
    object StaticText2: TStaticText
      Left = 136
      Top = 56
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 3
    end
    object LE_U_IPP1: TLabeledEdit
      Left = 8
      Top = 192
      Width = 121
      Height = 21
      EditLabel.Width = 62
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1055#1055'1'
      ReadOnly = True
      TabOrder = 4
      Text = '0'
    end
    object StaticText3: TStaticText
      Left = 136
      Top = 200
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 5
    end
    object LE_I_IPP1: TLabeledEdit
      Left = 8
      Top = 144
      Width = 121
      Height = 21
      EditLabel.Width = 52
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1055#1055'1'
      ReadOnly = True
      TabOrder = 6
      Text = '0'
    end
    object StaticText4: TStaticText
      Left = 136
      Top = 152
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 7
    end
    object LE_U_IMP1: TLabeledEdit
      Left = 8
      Top = 288
      Width = 121
      Height = 21
      EditLabel.Width = 63
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1052#1055'1'
      ReadOnly = True
      TabOrder = 8
      Text = '0'
    end
    object StaticText5: TStaticText
      Left = 136
      Top = 296
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 9
    end
    object LE_I_IMP1: TLabeledEdit
      Left = 8
      Top = 240
      Width = 121
      Height = 21
      EditLabel.Width = 53
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1052#1055'1'
      ReadOnly = True
      TabOrder = 10
      Text = '0'
    end
    object StaticText6: TStaticText
      Left = 136
      Top = 248
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 11
    end
    object P_Mode1: TPanel
      Left = 8
      Top = 328
      Width = 17
      Height = 17
      TabOrder = 12
    end
    object StaticText7: TStaticText
      Left = 32
      Top = 328
      Width = 48
      Height = 17
      Caption = #1056#1077#1078#1080#1084' 1'
      TabOrder = 13
    end
    object P_Protection1: TPanel
      Left = 8
      Top = 352
      Width = 17
      Height = 17
      TabOrder = 14
    end
    object StaticText8: TStaticText
      Left = 32
      Top = 352
      Width = 52
      Height = 17
      Caption = #1047#1072#1097#1080#1090#1072' 1'
      TabOrder = 15
    end
    object RB_Selected1: TRadioButton
      Left = 8
      Top = 408
      Width = 113
      Height = 17
      Caption = #1042#1099#1073#1086#1088' '#1082#1072#1085#1072#1083#1072' 1'
      Checked = True
      TabOrder = 16
      TabStop = True
    end
    object P_Selected1: TPanel
      Left = 128
      Top = 408
      Width = 17
      Height = 17
      TabOrder = 17
    end
    object StaticText40: TStaticText
      Left = 32
      Top = 376
      Width = 122
      Height = 17
      Caption = #1055#1077#1088#1077#1075#1088#1077#1074' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072' 1'
      TabOrder = 18
    end
    object P_Overheat1: TPanel
      Left = 8
      Top = 376
      Width = 17
      Height = 17
      TabOrder = 19
    end
  end
  object GB_Channel2: TGroupBox
    Left = 200
    Top = 32
    Width = 177
    Height = 433
    Caption = #1050#1072#1085#1072#1083' '#8470'2'
    TabOrder = 2
    object LE_U_IPO2: TLabeledEdit
      Left = 8
      Top = 96
      Width = 121
      Height = 21
      EditLabel.Width = 62
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1055#1054'2'
      ReadOnly = True
      TabOrder = 0
      Text = '0'
    end
    object StaticText10: TStaticText
      Left = 136
      Top = 104
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 1
    end
    object LE_I_IPO2: TLabeledEdit
      Left = 8
      Top = 48
      Width = 121
      Height = 21
      EditLabel.Width = 52
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1055#1054'2'
      ReadOnly = True
      TabOrder = 2
      Text = '0'
    end
    object StaticText11: TStaticText
      Left = 136
      Top = 56
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 3
    end
    object LE_U_IPP2: TLabeledEdit
      Left = 8
      Top = 192
      Width = 121
      Height = 21
      EditLabel.Width = 62
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1055#1055'2'
      ReadOnly = True
      TabOrder = 4
      Text = '0'
    end
    object StaticText12: TStaticText
      Left = 136
      Top = 200
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 5
    end
    object LE_I_IPP2: TLabeledEdit
      Left = 8
      Top = 144
      Width = 121
      Height = 21
      EditLabel.Width = 52
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1055#1055'2'
      ReadOnly = True
      TabOrder = 6
      Text = '0'
    end
    object StaticText13: TStaticText
      Left = 136
      Top = 152
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 7
    end
    object LE_U_IMP2: TLabeledEdit
      Left = 8
      Top = 288
      Width = 121
      Height = 21
      EditLabel.Width = 63
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1052#1055'2'
      ReadOnly = True
      TabOrder = 8
      Text = '0'
    end
    object StaticText14: TStaticText
      Left = 136
      Top = 296
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 9
    end
    object LE_I_IMP2: TLabeledEdit
      Left = 8
      Top = 240
      Width = 121
      Height = 21
      EditLabel.Width = 53
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1052#1055'2'
      ReadOnly = True
      TabOrder = 10
      Text = '0'
    end
    object StaticText15: TStaticText
      Left = 136
      Top = 248
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 11
    end
    object P_Mode2: TPanel
      Left = 8
      Top = 328
      Width = 17
      Height = 17
      TabOrder = 12
    end
    object StaticText16: TStaticText
      Left = 32
      Top = 328
      Width = 48
      Height = 17
      Caption = #1056#1077#1078#1080#1084' 2'
      TabOrder = 13
    end
    object P_Protection2: TPanel
      Left = 8
      Top = 352
      Width = 17
      Height = 17
      TabOrder = 14
    end
    object StaticText17: TStaticText
      Left = 32
      Top = 352
      Width = 52
      Height = 17
      Caption = #1047#1072#1097#1080#1090#1072' 2'
      TabOrder = 15
    end
    object RB_Selected2: TRadioButton
      Left = 8
      Top = 408
      Width = 113
      Height = 17
      Caption = #1042#1099#1073#1086#1088' '#1082#1072#1085#1072#1083#1072' 2'
      TabOrder = 16
    end
    object P_Selected2: TPanel
      Left = 128
      Top = 408
      Width = 17
      Height = 17
      TabOrder = 17
    end
    object StaticText9: TStaticText
      Left = 32
      Top = 376
      Width = 122
      Height = 17
      Caption = #1055#1077#1088#1077#1075#1088#1077#1074' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072' 2'
      TabOrder = 18
    end
    object P_Overheat2: TPanel
      Left = 8
      Top = 376
      Width = 17
      Height = 17
      TabOrder = 19
    end
  end
  object GB_Channel3: TGroupBox
    Left = 384
    Top = 32
    Width = 177
    Height = 433
    Caption = #1050#1072#1085#1072#1083' '#8470'3'
    TabOrder = 3
    object LE_U_IPO3: TLabeledEdit
      Left = 8
      Top = 96
      Width = 121
      Height = 21
      EditLabel.Width = 62
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1055#1054'3'
      ReadOnly = True
      TabOrder = 0
      Text = '0'
    end
    object StaticText19: TStaticText
      Left = 136
      Top = 104
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 1
    end
    object LE_I_IPO3: TLabeledEdit
      Left = 8
      Top = 48
      Width = 121
      Height = 21
      EditLabel.Width = 52
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1055#1054'3'
      ReadOnly = True
      TabOrder = 2
      Text = '0'
    end
    object StaticText20: TStaticText
      Left = 136
      Top = 56
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 3
    end
    object LE_U_IPP3: TLabeledEdit
      Left = 8
      Top = 192
      Width = 121
      Height = 21
      EditLabel.Width = 62
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1055#1055'3'
      ReadOnly = True
      TabOrder = 4
      Text = '0'
    end
    object StaticText21: TStaticText
      Left = 136
      Top = 200
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 5
    end
    object LE_I_IPP3: TLabeledEdit
      Left = 8
      Top = 144
      Width = 121
      Height = 21
      EditLabel.Width = 52
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1055#1055'3'
      ReadOnly = True
      TabOrder = 6
      Text = '0'
    end
    object StaticText22: TStaticText
      Left = 136
      Top = 152
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 7
    end
    object LE_U_IMP3: TLabeledEdit
      Left = 8
      Top = 288
      Width = 121
      Height = 21
      EditLabel.Width = 63
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1052#1055'3'
      ReadOnly = True
      TabOrder = 8
      Text = '0'
    end
    object StaticText23: TStaticText
      Left = 136
      Top = 296
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 9
    end
    object LE_I_IMP3: TLabeledEdit
      Left = 8
      Top = 240
      Width = 121
      Height = 21
      EditLabel.Width = 53
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1052#1055'3'
      ReadOnly = True
      TabOrder = 10
      Text = '0'
    end
    object StaticText24: TStaticText
      Left = 136
      Top = 248
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 11
    end
    object P_Mode3: TPanel
      Left = 8
      Top = 328
      Width = 17
      Height = 17
      TabOrder = 12
    end
    object StaticText25: TStaticText
      Left = 32
      Top = 328
      Width = 48
      Height = 17
      Caption = #1056#1077#1078#1080#1084' 3'
      TabOrder = 13
    end
    object P_Protection3: TPanel
      Left = 8
      Top = 352
      Width = 17
      Height = 17
      TabOrder = 14
    end
    object StaticText26: TStaticText
      Left = 32
      Top = 352
      Width = 52
      Height = 17
      Caption = #1047#1072#1097#1080#1090#1072' 3'
      TabOrder = 15
    end
    object RB_Selected3: TRadioButton
      Left = 8
      Top = 408
      Width = 113
      Height = 17
      Caption = #1042#1099#1073#1086#1088' '#1082#1072#1085#1072#1083#1072' 3'
      TabOrder = 16
    end
    object P_Selected3: TPanel
      Left = 128
      Top = 408
      Width = 17
      Height = 17
      TabOrder = 17
    end
    object StaticText18: TStaticText
      Left = 32
      Top = 376
      Width = 122
      Height = 17
      Caption = #1055#1077#1088#1077#1075#1088#1077#1074' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072' 3'
      TabOrder = 18
    end
    object P_Overheat3: TPanel
      Left = 8
      Top = 376
      Width = 17
      Height = 17
      TabOrder = 19
    end
  end
  object GB_Channel4: TGroupBox
    Left = 568
    Top = 32
    Width = 177
    Height = 433
    Caption = #1050#1072#1085#1072#1083' '#8470'4'
    TabOrder = 4
    object LE_U_IPO4: TLabeledEdit
      Left = 8
      Top = 96
      Width = 121
      Height = 21
      EditLabel.Width = 62
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1055#1054'4'
      ReadOnly = True
      TabOrder = 0
      Text = '0'
    end
    object StaticText28: TStaticText
      Left = 136
      Top = 104
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 1
    end
    object LE_I_IPO4: TLabeledEdit
      Left = 8
      Top = 48
      Width = 121
      Height = 21
      EditLabel.Width = 52
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1055#1054'4'
      ReadOnly = True
      TabOrder = 2
      Text = '0'
    end
    object StaticText29: TStaticText
      Left = 136
      Top = 56
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 3
    end
    object LE_U_IPP4: TLabeledEdit
      Left = 8
      Top = 192
      Width = 121
      Height = 21
      EditLabel.Width = 62
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1055#1055'4'
      ReadOnly = True
      TabOrder = 4
      Text = '0'
    end
    object StaticText30: TStaticText
      Left = 136
      Top = 200
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 5
    end
    object LE_I_IPP4: TLabeledEdit
      Left = 8
      Top = 144
      Width = 121
      Height = 21
      EditLabel.Width = 52
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1055#1055'4'
      ReadOnly = True
      TabOrder = 6
      Text = '0'
    end
    object StaticText31: TStaticText
      Left = 136
      Top = 152
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 7
    end
    object LE_U_IMP4: TLabeledEdit
      Left = 8
      Top = 288
      Width = 121
      Height = 21
      EditLabel.Width = 63
      EditLabel.Height = 13
      EditLabel.Caption = #1053#1072#1087#1088'. '#1048#1052#1055'4'
      ReadOnly = True
      TabOrder = 8
      Text = '0'
    end
    object StaticText32: TStaticText
      Left = 136
      Top = 296
      Width = 34
      Height = 17
      Caption = #1042#1086#1083#1100#1090
      TabOrder = 9
    end
    object LE_I_IMP4: TLabeledEdit
      Left = 8
      Top = 240
      Width = 121
      Height = 21
      EditLabel.Width = 53
      EditLabel.Height = 13
      EditLabel.Caption = #1058#1086#1082' '#1048#1052#1055'4'
      ReadOnly = True
      TabOrder = 10
      Text = '0'
    end
    object StaticText33: TStaticText
      Left = 136
      Top = 248
      Width = 37
      Height = 17
      Caption = #1040#1084#1087#1077#1088
      TabOrder = 11
    end
    object P_Mode4: TPanel
      Left = 8
      Top = 328
      Width = 17
      Height = 17
      TabOrder = 12
    end
    object StaticText34: TStaticText
      Left = 32
      Top = 328
      Width = 48
      Height = 17
      Caption = #1056#1077#1078#1080#1084' 4'
      TabOrder = 13
    end
    object P_Protection4: TPanel
      Left = 8
      Top = 352
      Width = 17
      Height = 17
      TabOrder = 14
    end
    object StaticText35: TStaticText
      Left = 32
      Top = 352
      Width = 52
      Height = 17
      Caption = #1047#1072#1097#1080#1090#1072' 4'
      TabOrder = 15
    end
    object RB_Selected4: TRadioButton
      Left = 8
      Top = 408
      Width = 113
      Height = 17
      Caption = #1042#1099#1073#1086#1088' '#1082#1072#1085#1072#1083#1072' 4'
      TabOrder = 16
    end
    object P_Selected4: TPanel
      Left = 128
      Top = 408
      Width = 17
      Height = 17
      TabOrder = 17
    end
    object StaticText27: TStaticText
      Left = 32
      Top = 376
      Width = 122
      Height = 17
      Caption = #1055#1077#1088#1077#1075#1088#1077#1074' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072' 4'
      TabOrder = 18
    end
    object P_Overheat4: TPanel
      Left = 8
      Top = 376
      Width = 17
      Height = 17
      TabOrder = 19
    end
  end
  object StaticText38: TStaticText
    Left = 784
    Top = 72
    Width = 200
    Height = 17
    Caption = #1057#1090#1077#1085#1076' '#1080#1089#1087#1099#1090#1072#1085#1080#1081' '#1085#1072' '#1085#1072#1076#1105#1078#1085#1086#1089#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
  end
  object B_Go: TButton
    Left = 776
    Top = 112
    Width = 75
    Height = 33
    Caption = #1055#1059#1057#1050
    Enabled = False
    TabOrder = 6
  end
  object B_Stop: TButton
    Left = 912
    Top = 112
    Width = 75
    Height = 33
    Caption = #1057#1058#1054#1055
    Enabled = False
    TabOrder = 7
  end
  object LE_Cycles: TLabeledEdit
    Left = 888
    Top = 176
    Width = 121
    Height = 21
    EditLabel.Width = 98
    EditLabel.Height = 13
    EditLabel.Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1094#1080#1082#1083#1086#1074
    ReadOnly = True
    TabOrder = 8
    Text = '0'
  end
  object StaticText39: TStaticText
    Left = 840
    Top = 88
    Width = 96
    Height = 17
    Caption = #1054#1076#1085#1086#1094#1074#1077#1090#1085#1080#1082#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
  end
  object M_Log: TMemo
    Left = 936
    Top = 272
    Width = 65
    Height = 57
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 10
    Visible = False
  end
  object Button2: TButton
    Left = 896
    Top = 216
    Width = 107
    Height = 33
    Caption = #1047#1072#1082#1086#1085#1095#1080#1090#1100' '#1087#1088#1086#1074#1077#1088#1082#1091
    TabOrder = 11
  end
  object Memo1: TMemo
    Left = 776
    Top = 280
    Width = 89
    Height = 145
    TabOrder = 12
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1027
    Height = 29
    Caption = 'ToolBar1'
    Images = ImageList1
    TabOrder = 13
    object ToolButton1: TToolButton
      Left = 0
      Top = 2
      Width = 8
      Caption = 'ToolButton1'
      Style = tbsSeparator
    end
    object ToolButton4: TToolButton
      Left = 8
      Top = 2
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 1
      Style = tbsSeparator
    end
    object TB_LoadStend: TToolButton
      Left = 16
      Top = 2
      Caption = 'TB_LoadStend'
      ImageIndex = 0
    end
    object ToolButton6: TToolButton
      Left = 39
      Top = 2
      Width = 8
      Caption = 'ToolButton6'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object ToolButton7: TToolButton
      Left = 47
      Top = 2
      Width = 8
      Caption = 'ToolButton7'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object TB_HelpAboutItem: TToolButton
      Left = 55
      Top = 2
      Hint = 
        #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093'|'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075 +
        #1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093
      Caption = 'TB_HelpAboutItem'
      ImageIndex = 1
    end
  end
  object ST_Enterprise: TStaticText
    Left = 792
    Top = 40
    Width = 188
    Height = 33
    Caption = #1054#1040#1054' "'#1054#1050#1058#1040#1042#1040'"'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 14
  end
  object Button1: TButton
    Left = 776
    Top = 224
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 15
  end
  object T_Checkm6V: TTimer
    Enabled = False
    Interval = 5
    Left = 752
    Top = 440
  end
  object T_Checkp6V: TTimer
    Enabled = False
    Interval = 5
    Left = 784
    Top = 440
  end
  object T_Checkp20V: TTimer
    Enabled = False
    Interval = 5
    Left = 816
    Top = 440
  end
  object T_Work: TTimer
    Interval = 0
    Left = 848
    Top = 440
  end
  object T_Log: TTimer
    Enabled = False
    Interval = 10000
    Left = 880
    Top = 440
  end
  object T_Overheat: TTimer
    Interval = 250
    Left = 912
    Top = 440
  end
  object T_Pause: TTimer
    Interval = 0
    Left = 944
    Top = 440
  end
  object T_Danger: TTimer
    Enabled = False
    Left = 976
    Top = 440
  end
  object MainMenu: TMainMenu
    Left = 136
    object M_File: TMenuItem
      Caption = #1060#1072#1081#1083
      object LoadStend: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' .stend'
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = ExitClick
      end
    end
    object Help: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object HelpAboutItem: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      end
    end
  end
  object ImageList1: TImageList
    Left = 168
    Bitmap = {
      494C010102000400040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FEFEFE01DADA
      DA25F3F3F30C0000000000000000000000000000000000000000000000000000
      0000F9F9F9060000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000051514DD552524CFFAEAEAE5400000000000000000000
      00000000000000000000000000000000000000000000000000001D631DE25596
      55FC006200FFB7B7B748FEFEFE01E6E6E619EAEAEA1500000000F9F9F906701F
      14EB8C1302FFE2E2E21D00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000044443DEA002ACFFF0F56DFFF050564FAEFEFEF10000000000000
      00000000000000000000000000000000000000000000000000003B863BFC6CB2
      6CFF74BD74FE027502FD0607D0FF5050EFFC2626BBFF5A4343BC982316FDBA40
      38FEA22519FDB7B7B74800000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FEFEFE01E7E7
      E718DBDBDB24474641FC001ECEFF0045EFFF025CFFFF8D8E89A8000000000000
      00000000000000000000000000000000000000000000F3F4F30E256825FF0256
      02FF005800FF0C5208F80D0CE5FE0505E8FF0202C7FD7D7A7A85A35952D2BF51
      46F2E68079FFF0F0F00F00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000002A2A2AF83E3E
      3EFC484848FE686868FE31324BFF001ECEFF0127D5FEAFAEAB6800000000FDFD
      FD02373835FF4C4D4EFFCCCCCC33000000000000000000000000FDFDFD03F1F1
      F10E030303FC00090CFF006789FF0385A9FF004962FF010101FE000000FF7A7A
      7A85EEEEEE110000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000E2E2E21D2D2D2DFC3333
      33FF525252FF434343FFC2C2C2FF666660FF72726AFFFDFDFD02FEFEFE013534
      29FF0032E0FF196FF6FE36376AFD000000000000000000000000DEDEDE210404
      04FB014B61FE0088A6FF26C3E7FF55D0EFFF20A0BEFF0083A4FF015873FE0303
      04FC5B5B5BA4F2F2F20D00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000003F3F3FDE333333FE2424
      24FF444444FF777777FF585858FF6F6F6FFD8E8E8E81BBBBBB4F555555D74A4A
      47FF001ED0FF0045EEFF040E9BFB000000000000000000000000050505FA1451
      5DFE03CEF7FF3BE9FEFF9AFEFFFF23DCFFFF00C0E7FF01A8C9FF0F5462FF1516
      16FF030303FC8B8B8B7400000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000313131FF3B3B3BFF8888
      88FF1A1A1AFF525252FF6C6C6CFF505050FE444444FE535353CC565656FE6868
      68FF393A40FF0012CFFF363E93FF00000000FEFEFE010E0E0EF1191919FEE2E1
      E1FFFFFFFDFF0ED9FFFF1CDEFEFF00B8DFFF009ABBFFE0DDDDFFFAFAFAFF7575
      75FF101010FE000000FFE5E5E51A000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FDFDFD023A3A3AFC424242FF4C4C
      4CFF676767FF2C2C2CFF252525FF2B2B2BFF343434FF373737FE505050FF5B5B
      5BFFCFCFCFFF7D7D80FF494949FC0000000000000000000000FF242424FFFBFB
      FBFFE8E8E8FF535656FF79B2BDFF0286A2FF090605FF0B0B0BFFFEFEFEFFFEFE
      FEFF171717FF030303FCBFBFBF40000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FBFBFB04404040FD494949FF5353
      53FF5D5D5DFF666666FF6C6C6CFF0F0F0FFF4F4F4FFF2D2D2DFF4A4A4AFF8B8B
      8BFF646464FF4C4C4CFF3C3C3CFDFEFEFE0200000000020202FF626262FFFDFD
      FDFFFCFCFCFF2C2C2CFFFEFEFEFFB4B5B5FFAFAFAFFF121212FFFFFFFFFFFDFD
      FDFF313131FF030303FCBABABA45000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000484848FC505050FF5A5A
      5AFF646464FF626262FF232323FF4F4F4FFF202020FF323232FF292929FF3B3B
      3BFF313131FF272727FDC8C8C84B0000000000000000010101FE282828FFFBFB
      FBFFFEFEFEFFFCFCFCFFFDFDFDFFA7A7A7FFFFFFFFFFFFFFFFFFFFFFFFFFFCFC
      FCFF121212FF030303FCE3E3E31C000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FEFEFE02515151F8585858FF6262
      62FF606060FF585858FF4A4A4AFF3A3A3AFF383838FF454545FF505050FF6565
      65FF8A8A8AFDB9B9B9660000000000000000000000001A1A1AE51D1D1DFFF5F5
      F5FFFDFDFDFFFFFFFFFF6C6C6CFF646464FFFCFCFCFFFEFEFEFFFFFFFFFFFFFF
      FFFF010101FE000000FFFCFCFC03000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000008383838F606060FF6A6A
      6AFE8E8E8EFFAEAEAE70494949FF353535FF4A4A4AFF262626FF595959FF6565
      65FDB7B7B7680000000000000000000000000000000000000000060606F92424
      24FE636363FF7C7C7CFF626262FF555555FF4D4D4DFFFFFFFFFFFEFEFEFF0000
      00FF050505FAE1E1E11E00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000545454FF6060
      60FF0000000000000000313131FC4D4D4DFF363636FF565656FE656565FAACAC
      AC78000000000000000000000000000000000000000000000000000000000303
      03FC111111FE262626FF2E2E2EFF2E2E2EFF232323FF060606FF020202FE0505
      05FAB9B9B9460000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FDFDFD03FDFD
      FD0300000000000000004E4E4EFA474747FF545454FFA2A2A291000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000292929D6000000FF030303FC020202FD030303FC010101FF080808F70000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000E2E2E234FDFDFD0300000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FEFEFE010000000000000000FEFEFE010000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFFC7F700000000FC7FC04300000000
      F83FC00300000000C03F800300000000C021C007000000008001C00300000000
      8001C00300000000800100010000000000018001000000000000800100000000
      800180010000000000038001000000008007C00300000000CC0FE00700000000
      CC3FF01F00000000FE7FFEDF0000000000000000000000000000000000000000
      000000000000}
  end
  object OpenDialog1: TOpenDialog
    Left = 200
  end
end
