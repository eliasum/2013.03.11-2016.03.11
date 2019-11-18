object F_AboutBox: TF_AboutBox
  Left = 583
  Top = 209
  Width = 273
  Height = 371
  Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
  Color = clBtnFace
  Constraints.MaxHeight = 371
  Constraints.MaxWidth = 273
  Constraints.MinHeight = 371
  Constraints.MinWidth = 273
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 7
    Top = 8
    Width = 250
    Height = 289
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    object ProductName: TLabel
      Left = 34
      Top = 12
      Width = 165
      Height = 13
      Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1057#1090#1077#1085#1076' '#1080#1089#1087#1099#1090#1072#1085#1080#1081' '#1085#1072
      IsControl = True
    end
    object Version_view: TLabel
      Left = 96
      Top = 72
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
      Left = 84
      Top = 92
      Width = 73
      Height = 13
      Caption = #1054#1040#1054' "'#1054#1082#1090#1072#1074#1072'"'
      IsControl = True
    end
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
      Left = 42
      Top = 32
      Width = 149
      Height = 13
      Caption = #1085#1072#1076#1077#1078#1085#1086#1089#1090#1100' '#1054#1076#1085#1086#1094#1074#1077#1090#1085#1080#1082#1086#1074'  '
      IsControl = True
    end
    object ST_Email: TStaticText
      Left = 72
      Top = 132
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
    object Chart3: TChart
      Left = 38
      Top = 152
      Width = 170
      Height = 135
      AllowPanning = pmNone
      AllowZoom = False
      BackWall.Brush.Color = clWhite
      BackWall.Brush.Style = bsClear
      BackWall.Pen.Visible = False
      Foot.Font.Charset = DEFAULT_CHARSET
      Foot.Font.Color = clRed
      Foot.Font.Height = -12
      Foot.Font.Name = 'Arial'
      Foot.Font.Style = [fsItalic]
      Foot.Frame.Color = clScrollBar
      MarginBottom = 0
      MarginLeft = 0
      MarginRight = 0
      MarginTop = 0
      Title.Frame.Color = clScrollBar
      Title.Text.Strings = (
        'TChart Component')
      Title.Visible = False
      AxisVisible = False
      BottomAxis.Visible = False
      ClipPoints = False
      Frame.Visible = False
      LeftAxis.Visible = False
      Legend.Visible = False
      RightAxis.Visible = False
      TopAxis.Visible = False
      View3DOptions.Elevation = 315
      View3DOptions.Orthogonal = False
      View3DOptions.Perspective = 0
      View3DOptions.Rotation = 360
      View3DWalls = False
      BevelOuter = bvNone
      TabOrder = 1
      Constraints.MaxHeight = 135
      Constraints.MaxWidth = 170
      Constraints.MinHeight = 135
      Constraints.MinWidth = 170
      object PieSeries1: TPieSeries
        Marks.ArrowLength = 8
        Marks.Style = smsLabelPercent
        Marks.Visible = False
        SeriesColor = clRed
        Circled = True
        OtherSlice.Text = 'Other'
        PieValues.DateTime = False
        PieValues.Name = 'Y'
        PieValues.Multiplier = 1
        PieValues.Order = loNone
        Left = 134
        Top = 13
      end
    end
  end
  object B_Exit: TButton
    Left = 96
    Top = 304
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 1
    OnClick = B_ExitClick
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 220
    Top = 251
  end
end
