object F_AboutBox: TF_AboutBox
  Left = 0
  Top = 0
  Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
  ClientHeight = 330
  ClientWidth = 265
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 8
    Top = 9
    Width = 250
    Height = 281
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    object ProductName: TLabel
      Left = 41
      Top = 12
      Width = 175
      Height = 13
      Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072' ApertureControlProgram'
      IsControl = True
    end
    object Version_view: TLabel
      Left = 98
      Top = 52
      Width = 54
      Height = 13
      Caption = #1042#1077#1088#1089#1080#1103' 1.0'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      IsControl = True
    end
    object Copyright: TLabel
      Left = 88
      Top = 72
      Width = 72
      Height = 13
      Caption = #1054#1040#1054' "'#1054#1082#1090#1072#1074#1072'"'
      IsControl = True
    end
    object Comments: TLabel
      Left = 72
      Top = 92
      Width = 113
      Height = 17
      AutoSize = False
      Caption = #1053#1086#1074#1086#1089#1080#1073#1080#1088#1089#1082', 2015 '#1075'.'
      WordWrap = True
      IsControl = True
    end
    object Device: TLabel
      Left = 57
      Top = 32
      Width = 144
      Height = 13
      Caption = #1059#1089#1090#1088#1086#1081#1089#1090#1074#1086': '#1040#1087#1077#1088#1090#1091#1088#1072'-'#1054
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      IsControl = True
    end
    object ST_Email: TLabel
      Left = 77
      Top = 112
      Width = 95
      Height = 13
      Caption = 'eliasum@yandex.ru'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = ST_EmailClick
      OnMouseDown = ST_EmailMouseDown
      OnMouseUp = ST_EmailMouseUp
    end
    object Chart3: TChart
      Left = 8
      Top = 131
      Width = 230
      Height = 145
      AllowPanning = pmNone
      BackWall.Brush.Color = clWhite
      BackWall.Brush.Style = bsClear
      BackWall.Pen.Visible = False
      Foot.Font.Height = -12
      Foot.Frame.Color = clScrollBar
      Legend.Visible = False
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
      RightAxis.Visible = False
      TopAxis.Visible = False
      View3DOptions.Elevation = 315
      View3DOptions.Orthogonal = False
      View3DOptions.Perspective = 0
      View3DOptions.Rotation = 360
      View3DWalls = False
      Zoom.Allow = False
      BevelOuter = bvNone
      TabOrder = 0
      Constraints.MaxHeight = 145
      Constraints.MaxWidth = 230
      Constraints.MinHeight = 145
      Constraints.MinWidth = 230
      ColorPaletteIndex = 13
      object PieSeries1: TPieSeries
        Marks.Arrow.Visible = True
        Marks.Callout.Brush.Color = clBlack
        Marks.Callout.Arrow.Visible = True
        Marks.Style = smsLabelPercent
        Marks.Visible = False
        SeriesColor = clRed
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
        Circled = True
        Gradient.Direction = gdRadial
        OtherSlice.Legend.Visible = False
        OtherSlice.Text = 'Other'
        PieValues.Name = 'Y'
        PieValues.Order = loNone
        Frame.InnerBrush.BackColor = clRed
        Frame.InnerBrush.Gradient.EndColor = clGray
        Frame.InnerBrush.Gradient.MidColor = clWhite
        Frame.InnerBrush.Gradient.StartColor = 4210752
        Frame.InnerBrush.Gradient.Visible = True
        Frame.MiddleBrush.BackColor = clYellow
        Frame.MiddleBrush.Gradient.EndColor = 8553090
        Frame.MiddleBrush.Gradient.MidColor = clWhite
        Frame.MiddleBrush.Gradient.StartColor = clGray
        Frame.MiddleBrush.Gradient.Visible = True
        Frame.OuterBrush.BackColor = clGreen
        Frame.OuterBrush.Gradient.EndColor = 4210752
        Frame.OuterBrush.Gradient.MidColor = clWhite
        Frame.OuterBrush.Gradient.StartColor = clSilver
        Frame.OuterBrush.Gradient.Visible = True
        Frame.ParentSeries = PieSeries1
        Frame.Visible = False
        Frame.Width = 4
        Left = 134
        Top = 13
      end
    end
  end
  object B_Exit: TButton
    Left = 96
    Top = 296
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 1
    OnClick = B_ExitClick
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 221
    Top = 251
  end
end
