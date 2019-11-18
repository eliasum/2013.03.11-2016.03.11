object F_AboutBox: TF_AboutBox
  Left = 291
  Top = 138
  Width = 273
  Height = 227
  Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
  Color = clBtnFace
  Constraints.MaxHeight = 227
  Constraints.MaxWidth = 273
  Constraints.MinHeight = 227
  Constraints.MinWidth = 273
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 7
    Top = 8
    Width = 250
    Height = 145
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    object ProductName: TLabel
      Left = 66
      Top = 16
      Width = 112
      Height = 13
      Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072' BlazePoint'
      IsControl = True
    end
    object Version_view: TLabel
      Left = 96
      Top = 52
      Width = 55
      Height = 13
      Caption = #1042#1077#1088#1089#1080#1103' 1.0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object Copyright: TLabel
      Left = 44
      Top = 70
      Width = 163
      Height = 13
      Caption = #1056#1072#1079#1088#1072#1073#1086#1090#1072#1085#1072' '#1076#1083#1103' '#1054#1040#1054' "'#1054#1082#1090#1072#1074#1072'"'
      IsControl = True
    end
    object Comments: TLabel
      Left = 40
      Top = 88
      Width = 169
      Height = 17
      AutoSize = False
      Caption = #1052#1080#1085#1080#1085' '#1048#1083#1100#1103' '#1052#1080#1093#1072#1081#1083#1086#1074#1080#1095', 2014 '#1075'.'
      WordWrap = True
      IsControl = True
    end
    object Device: TLabel
      Left = 57
      Top = 34
      Width = 134
      Height = 13
      Caption = #1059#1089#1090#1088#1086#1081#1089#1090#1074#1086': '#1040#1087#1077#1088#1090#1091#1088#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      IsControl = True
    end
    object ST_Email: TStaticText
      Left = 72
      Top = 112
      Width = 107
      Height = 17
      Caption = 'eliasum@yandex.com'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
      TabOrder = 0
      OnClick = ST_EmailClick
      OnMouseDown = ST_EmailMouseDown
      OnMouseUp = ST_EmailMouseUp
    end
  end
  object B_Exit: TButton
    Left = 96
    Top = 160
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 1
    OnClick = B_ExitClick
  end
end
