object F_AboutBox: TF_AboutBox
  Left = 192
  Top = 114
  Width = 274
  Height = 245
  Caption = 'F_AboutBox'
  Color = clBtnFace
  Constraints.MaxHeight = 245
  Constraints.MaxWidth = 274
  Constraints.MinHeight = 245
  Constraints.MinWidth = 274
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object sPanel1: TsPanel
    Left = 8
    Top = 8
    Width = 250
    Height = 161
    TabOrder = 0
    SkinData.SkinSection = 'PANEL'
    object Comments: TLabel
      Left = 72
      Top = 112
      Width = 113
      Height = 17
      AutoSize = False
      Caption = #1053#1086#1074#1086#1089#1080#1073#1080#1088#1089#1082', 2014 '#1075'.'
      WordWrap = True
      IsControl = True
    end
    object Copyright: TLabel
      Left = 84
      Top = 92
      Width = 73
      Height = 13
      Caption = #1054#1040#1054' "'#1054#1082#1090#1072#1074#1072'"'
      IsControl = True
    end
    object Version_view: TLabel
      Left = 96
      Top = 72
      Width = 55
      Height = 13
      Caption = #1042#1077#1088#1089#1080#1103' 2.0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object Device: TLabel
      Left = 17
      Top = 52
      Width = 210
      Height = 13
      Caption = #1059#1089#1090#1088#1086#1081#1089#1090#1074#1086': '#1057#1090#1077#1085#1076' '#1054#1076#1085#1086#1094#1074#1077#1090#1085#1080#1082#1086#1074
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      IsControl = True
    end
    object Label1: TLabel
      Left = 10
      Top = 32
      Width = 222
      Height = 13
      Caption = #1092#1072#1081#1083#1086#1074' '#1080#1089#1087#1099#1090#1072#1085#1080#1081' '#1089#1090#1077#1085#1076#1072' '#1054#1076#1085#1086#1094#1074#1077#1090#1085#1080#1082#1086#1074'  '
      IsControl = True
    end
    object ProductName: TLabel
      Left = 18
      Top = 12
      Width = 205
      Height = 13
      Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1089#1086#1079#1076#1072#1085#1080#1103' '#1080' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
      IsControl = True
    end
    object ST_Email: TsWebLabel
      Left = 72
      Top = 132
      Width = 103
      Height = 13
      Caption = 'eliasum@yandex.com'
      ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      HoverFont.Charset = DEFAULT_CHARSET
      HoverFont.Color = clWindowText
      HoverFont.Height = -11
      HoverFont.Name = 'MS Sans Serif'
      HoverFont.Style = []
    end
  end
  object B_Exit: TButton
    Left = 96
    Top = 176
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 1
  end
end
