object Main_Form: TMain_Form
  Left = 247
  Top = 126
  AutoScroll = False
  Caption = 'BlazePoint'
  ClientHeight = 568
  ClientWidth = 880
  Color = clBtnFace
  Constraints.MaxHeight = 622
  Constraints.MaxWidth = 888
  Constraints.MinHeight = 622
  Constraints.MinWidth = 888
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 550
    Width = 880
    Height = 18
    AutoHint = True
    Panels = <>
    SimplePanel = False
  end
  object PC_Main: TPageControl
    Left = 0
    Top = 33
    Width = 873
    Height = 512
    Hint = #1044#1072#1085#1085#1099#1077' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103'|'#1044#1072#1085#1085#1099#1077' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103
    ActivePage = BT
    BiDiMode = bdRightToLeftNoAlign
    MultiLine = True
    ParentBiDiMode = False
    TabIndex = 0
    TabOrder = 1
    object BT: TTabSheet
      Hint = #1044#1072#1085#1085#1099#1077' '#1041#1058'|'#1044#1072#1085#1085#1099#1077' '#1041#1058
      Caption = #1044#1072#1085#1085#1099#1077' '#1041#1058
      object Label1: TLabel
        Left = 0
        Top = 472
        Width = 18
        Height = 13
        Caption = '0, 0'
      end
      object Label2: TLabel
        Left = 544
        Top = 152
        Width = 32
        Height = 13
        Caption = 'Label2'
      end
      object Label3: TLabel
        Left = 496
        Top = 320
        Width = 50
        Height = 13
        Caption = 'PointIndex'
      end
      object Label4: TLabel
        Left = 560
        Top = 320
        Width = 53
        Height = 13
        Caption = 'ValueIndex'
      end
      object GroupBox79: TGroupBox
        Left = 632
        Top = 0
        Width = 225
        Height = 65
        Hint = #1047#1072#1076#1072#1085#1080#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1072' "'#1041#1083#1077#1089#1090#1103#1097#1080#1093' '#1090#1086#1095#1077#1082'"'
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086'  "'#1041#1083#1077#1089#1090#1103#1097#1080#1093' '#1090#1086#1095#1077#1082'"'
        TabOrder = 0
        object edLCBT: TEdit
          Left = 16
          Top = 24
          Width = 193
          Height = 21
          BiDiMode = bdLeftToRight
          Color = clYellow
          ParentBiDiMode = False
          TabOrder = 0
          OnChange = edLCBTChange
          OnClick = edLCBTClick
          OnExit = edLCBTExit
          OnKeyPress = PIntKeyPress
        end
      end
      object GroupBox85: TGroupBox
        Left = 632
        Top = 80
        Width = 225
        Height = 65
        Hint = #1042#1099#1073#1086#1088' '#1085#1086#1084#1077#1088#1072' "'#1041#1083#1077#1089#1090#1103#1097#1077#1081' '#1090#1086#1095#1082#1080'"'
        Caption = #1053#1086#1084#1077#1088' "'#1041#1083#1077#1089#1090#1103#1097#1077#1081' '#1090#1086#1095#1082#1080'"'
        TabOrder = 1
        object cbLCnBT: TComboBox
          Left = 16
          Top = 22
          Width = 193
          Height = 21
          Style = csDropDownList
          Enabled = False
          ItemHeight = 13
          TabOrder = 0
          OnChange = cbLCnBTChange
          Items.Strings = (
            '1')
        end
      end
      object GroupBox86: TGroupBox
        Left = 632
        Top = 160
        Width = 225
        Height = 161
        Hint = #1047#1072#1076#1072#1085#1080#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074' "'#1041#1083#1077#1089#1090#1103#1097#1080#1093' '#1090#1086#1095#1077#1082'"'
        Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099'  "'#1041#1083#1077#1089#1090#1103#1097#1080#1093' '#1090#1086#1095#1077#1082'"'
        TabOrder = 2
        object edLCx: TLabeledEdit
          Left = 16
          Top = 40
          Width = 193
          Height = 21
          EditLabel.Width = 108
          EditLabel.Height = 13
          EditLabel.BiDiMode = bdRightToLeftNoAlign
          EditLabel.Caption = '                             X, '#1084
          EditLabel.ParentBiDiMode = False
          Enabled = False
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 0
          Text = '0'
          OnChange = edLCxChange
          OnExit = edLCxExit
          OnKeyPress = PIntKeyPress
        end
        object edLCy: TLabeledEdit
          Left = 16
          Top = 80
          Width = 193
          Height = 21
          EditLabel.Width = 108
          EditLabel.Height = 13
          EditLabel.BiDiMode = bdRightToLeftNoAlign
          EditLabel.Caption = '                             Y, '#1084
          EditLabel.ParentBiDiMode = False
          Enabled = False
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 1
          Text = '0'
          OnChange = edLCyChange
          OnExit = edLCyExit
          OnKeyPress = PIntKeyPress
        end
        object LE_EPR: TLabeledEdit
          Left = 16
          Top = 120
          Width = 193
          Height = 21
          EditLabel.Width = 123
          EditLabel.Height = 13
          EditLabel.BiDiMode = bdRightToLeftNoAlign
          EditLabel.Caption = '                         '#1069#1055#1056', '#1084'^2'
          EditLabel.ParentBiDiMode = False
          Enabled = False
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 2
          Text = '0'
          OnChange = LE_EPRChange
          OnExit = LE_EPRExit
          OnKeyPress = PIntKeyPress
        end
      end
      object btnReDrawLC: TButton
        Left = 688
        Top = 331
        Width = 121
        Height = 33
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1075#1088#1072#1092#1080#1082' '#1083#1086#1078#1085#1086#1081' '#1094#1077#1083#1080
        Caption = #1054#1073#1085#1086#1074#1080#1090#1100' '#1075#1088#1072#1092#1080#1082
        Enabled = False
        TabOrder = 3
        OnClick = btnReDrawLCClick
      end
      object ChartLC: TChart
        Left = 0
        Top = 3
        Width = 490
        Height = 470
        AllowPanning = pmNone
        AnimatedZoom = True
        AnimatedZoomSteps = 0
        BackImageInside = True
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Gradient.EndColor = clWhite
        Gradient.StartColor = -1
        LeftWall.Brush.Color = clWhite
        MarginBottom = 0
        MarginLeft = 0
        MarginRight = 5
        MarginTop = 0
        Title.AdjustFrame = False
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWhite
        Title.Font.Height = -11
        Title.Font.Name = 'Arial'
        Title.Font.Style = []
        Title.Text.Strings = (
          #1055#1086#1088#1090#1088#1077#1090' '#1041#1058)
        OnClickSeries = ChartLCClickSeries
        OnUndoZoom = ChartLCUndoZoom
        OnZoom = ChartLCZoom
        BottomAxis.Automatic = False
        BottomAxis.AutomaticMaximum = False
        BottomAxis.AutomaticMinimum = False
        BottomAxis.Axis.Color = clWhite
        BottomAxis.ExactDateTime = False
        BottomAxis.Grid.Color = clRed
        BottomAxis.Grid.SmallDots = True
        BottomAxis.Increment = 1
        BottomAxis.LabelsFont.Charset = DEFAULT_CHARSET
        BottomAxis.LabelsFont.Color = clWhite
        BottomAxis.LabelsFont.Height = -11
        BottomAxis.LabelsFont.Name = 'Arial'
        BottomAxis.LabelsFont.Style = []
        BottomAxis.LabelsSeparation = 1
        BottomAxis.Maximum = 425
        BottomAxis.Minimum = -425
        BottomAxis.TickLength = 3
        BottomAxis.Ticks.Color = clWhite
        BottomAxis.Title.Caption = 'X'
        DepthAxis.ExactDateTime = False
        DepthAxis.Increment = 1
        DepthAxis.LabelsSeparation = 1
        DepthAxis.Title.Caption = 'Z'
        DepthAxis.Visible = True
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMaximum = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.Axis.Color = clWhite
        LeftAxis.Axis.Width = 3
        LeftAxis.ExactDateTime = False
        LeftAxis.Grid.Color = clRed
        LeftAxis.Grid.Style = psDashDotDot
        LeftAxis.Grid.SmallDots = True
        LeftAxis.Increment = 1
        LeftAxis.LabelsFont.Charset = DEFAULT_CHARSET
        LeftAxis.LabelsFont.Color = clWhite
        LeftAxis.LabelsFont.Height = -11
        LeftAxis.LabelsFont.Name = 'Arial'
        LeftAxis.LabelsFont.Style = []
        LeftAxis.LabelsSeparation = 1
        LeftAxis.Maximum = 850
        LeftAxis.TickLength = 3
        LeftAxis.Ticks.Color = clWhite
        LeftAxis.Title.Caption = 'Y'
        Legend.Frame.SmallDots = True
        Legend.ResizeChart = False
        Legend.ShadowSize = 2
        Legend.Visible = False
        MaxPointsPerPage = 32
        ScaleLastPage = False
        View3D = False
        View3DWalls = False
        OnAfterDraw = ChartLCAfterDraw
        BevelOuter = bvNone
        BevelWidth = 0
        BorderStyle = bsSingle
        Color = -1
        TabOrder = 4
        OnDblClick = ChartLCDblClick
        OnMouseMove = ChartLCMouseMove
        object Series1: TPointSeries
          Marks.ArrowLength = 7
          Marks.BackColor = clRed
          Marks.Style = smsValue
          Marks.Visible = False
          SeriesColor = clRed
          Pointer.InflateMargins = False
          Pointer.Style = psCircle
          Pointer.Visible = True
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
      object B_Sbros: TButton
        Left = 688
        Top = 368
        Width = 121
        Height = 33
        Caption = #1057#1073#1088#1086#1089#1080#1090#1100' '#1041#1058
        Enabled = False
        TabOrder = 5
        OnClick = B_SbrosClick
      end
      object BitBtn1: TBitBtn
        Left = 688
        Top = 404
        Width = 121
        Height = 33
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1082#1072#1088#1090#1091'...'
        TabOrder = 6
        OnClick = BitBtn1Click
        Glyph.Data = {
          56070000424D5607000000000000360400002800000028000000140000000100
          0800000000002003000000000000000000000001000000010000000000000000
          80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
          A600000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000F0FBFF00A4A0A000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00030303030303
          0303030303030303030303030303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303030303030303030303
          030303030303030303FFFFFFFFFFFFFFFFFFFFFFFFFFFF0303030303F8000000
          00000000000000000000030303030303F8F8F8F8F8F8F8F8F8F8F8F8F8F803FF
          03030303000007FB07FB07FB07FB07FB07FB000303030303F8F803FF03030303
          030303030303F8FF0303030300FF0007FB07FB07FB07FB07FB07000303030303
          F8FFF8FF03030303030303030303F803FF03030300FB00FB07FB07FB07FB07FB
          07FB070003030303F8FFF803FF03030303030303030303F8FF03030300FFFB00
          FB07FB07FB07FB07FB07FB0003030303F8FF03F8FF03030303030303030303F8
          03FF030300FBFF0007FB07FB07FB07FB07FB07FB00030303F8FF03F803FFFFFF
          FFFF030303030303F8FF030300FFFBFF000000000007FB07FB07FB0700030303
          F8FF0303F8F8F8F8F803FFFFFFFFFFFFF803030300FBFFFBFFFBFFFBFF000000
          0000000003030303F8FF03030303030303F8F8F8F8F8F8F80303030300FFFBFF
          FBFFFBFFFBFFFBFFFB00030303030303F8FF0303030303030303030303F8FF03
          0303030300FBFFFBFFFBFFFBFFFBFFFBFF00030303030303F8FF0303030303FF
          FFFFFFFFFFF803030303030300FFFBFFFBFF0000000000000003030303030303
          F807FFFFFFFFF8F8F8F8F8F8F803030303030303030000000000030303030303
          030303030303030303F8F8F8F8F8030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303030303030303030303
          0303030303030303030303030303030303030303030303030303}
        NumGlyphs = 2
      end
      object Button1: TButton
        Left = 688
        Top = 440
        Width = 121
        Height = 33
        Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1082#1072#1088#1090#1091
        TabOrder = 7
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 528
        Top = 168
        Width = 75
        Height = 25
        Caption = 'Button2'
        TabOrder = 8
      end
      object M_PointIndex: TMemo
        Left = 496
        Top = 344
        Width = 57
        Height = 89
        TabOrder = 9
      end
      object M_ValueIndex: TMemo
        Left = 560
        Top = 344
        Width = 57
        Height = 89
        TabOrder = 10
      end
    end
    object RLS1: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103
      ImageIndex = 1
      object LV_Sar1: TListView
        Left = 0
        Top = 32
        Width = 625
        Height = 57
        Columns = <
          item
            Caption = 'V '#1087#1086#1083#1105#1090#1072' '#1056#1057#1040' ['#1084'/'#1089']'
            Width = 120
          end
          item
            Caption = #1053#1077#1089#1091#1097#1072#1103' f ['#1052#1075#1094']'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1087#1086#1083#1105#1090#1072' ['#1075#1088#1072#1076'.]'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1055#1086#1083#1086#1078#1077#1085#1080#1077' '#1072#1085#1090#1077#1085#1085' '#1056#1057#1040' ['#1075#1088#1072#1076'.]'
            Width = 170
          end
          item
            Caption = 'D '#1076#1086' '#1094#1077#1083#1080' ['#1084']'
            Width = 80
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        GridLines = True
        MultiSelect = True
        ReadOnly = True
        RowSelect = True
        ParentFont = False
        TabOrder = 0
        ViewStyle = vsReport
        OnDblClick = LV_Sar1DblClick
      end
      object GroupBox2: TGroupBox
        Left = 648
        Top = 8
        Width = 121
        Height = 81
        Caption = #1044#1072#1085#1085#1099#1077' sar '#8470'1'
        TabOrder = 1
        object B_AddSar1: TBitBtn
          Left = 16
          Top = 16
          Width = 89
          Height = 25
          Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077'|'#1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          TabOrder = 0
          OnClick = B_AddSar1Click
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            3333333333333333333333330000333333333333333333333333F33333333333
            00003333344333333333333333388F3333333333000033334224333333333333
            338338F3333333330000333422224333333333333833338F3333333300003342
            222224333333333383333338F3333333000034222A22224333333338F338F333
            8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
            33333338F83338F338F33333000033A33333A222433333338333338F338F3333
            0000333333333A222433333333333338F338F33300003333333333A222433333
            333333338F338F33000033333333333A222433333333333338F338F300003333
            33333333A222433333333333338F338F00003333333333333A22433333333333
            3338F38F000033333333333333A223333333333333338F830000333333333333
            333A333333333333333338330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
        end
        object B_DeleteSar1: TBitBtn
          Left = 16
          Top = 48
          Width = 89
          Height = 25
          Hint = #1059#1076#1072#1083#1080#1090#1100' '#1076#1072#1085#1085#1099#1077'|'#1059#1076#1072#1083#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
          Caption = #1059#1076#1072#1083#1080#1090#1100
          TabOrder = 1
          OnClick = B_DeleteSar1Click
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00E7E7E718F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00310ED2F12900DFFF7070708FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00AEAEB2513015AEEAE7E7E718FFFFFF00FFFFFF00FFFF
            FF00492FC2D02900DFFF35296ED6D1D1D12EFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FEFEFE01584A98B52900DFFFB1AFBC50FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00320FD2F02900DFFF505050AFE9E9E916FFFFFF00FFFFFF00FCFC
            FC033518BBE72900DFFFEAEAEA15FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF002900DFFF2900DFFF6161619EF5F5F50AFCFCFC033518
            BBE72900DFFFEDEDED12FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF002900DFFF2B06D1F96B6B6B943517BBE82900
            DFFFEDEDED12FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00320FD2F02900DFFF2900DFFFDBDB
            DB24FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FCFCFC032C08D2F72900DFFF2900DFFF5959
            59A6E3E3E31CFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FCFCFC033518BBE72900DFFFE1E1E11E6F60B69F2900
            DFFF4B4A53B5C9C9C936FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FCFCFC033518BBE72900DFFFD4D4D42BFFFFFF00FFFFFF00D0CF
            D6302900DFFF42386EC79A9A9A65FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00F5F5F50A3316BBE92900DFFFB4B4B74BFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF002900DFFF351BB0E4CECECE31FFFFFF00FFFFFF00FFFFFF00FFFF
            FF002C08D2F72900DFFF6960949FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00A39EBD61FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF002900DFFF391FB0E0FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        end
      end
      object StaticText1: TStaticText
        Left = 272
        Top = 8
        Width = 76
        Height = 17
        Caption = #1044#1072#1085#1099#1077' sar '#8470'1'
        TabOrder = 2
      end
      object StaticText2: TStaticText
        Left = 272
        Top = 96
        Width = 76
        Height = 17
        Caption = #1044#1072#1085#1099#1077' sar '#8470'2'
        TabOrder = 3
        Visible = False
      end
      object GroupBox3: TGroupBox
        Left = 648
        Top = 96
        Width = 121
        Height = 81
        Caption = #1044#1072#1085#1085#1099#1077' sar '#8470'2'
        TabOrder = 4
        Visible = False
        object B_AddSar2: TBitBtn
          Left = 16
          Top = 16
          Width = 89
          Height = 25
          Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077'|'#1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          TabOrder = 0
          OnClick = B_AddSar2Click
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            3333333333333333333333330000333333333333333333333333F33333333333
            00003333344333333333333333388F3333333333000033334224333333333333
            338338F3333333330000333422224333333333333833338F3333333300003342
            222224333333333383333338F3333333000034222A22224333333338F338F333
            8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
            33333338F83338F338F33333000033A33333A222433333338333338F338F3333
            0000333333333A222433333333333338F338F33300003333333333A222433333
            333333338F338F33000033333333333A222433333333333338F338F300003333
            33333333A222433333333333338F338F00003333333333333A22433333333333
            3338F38F000033333333333333A223333333333333338F830000333333333333
            333A333333333333333338330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
        end
        object B_DeleteSar2: TBitBtn
          Left = 16
          Top = 48
          Width = 89
          Height = 25
          Hint = #1059#1076#1072#1083#1080#1090#1100' '#1076#1072#1085#1085#1099#1077'|'#1059#1076#1072#1083#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
          Caption = #1059#1076#1072#1083#1080#1090#1100
          TabOrder = 1
          OnClick = B_DeleteSar2Click
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00E7E7E718F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00310ED2F12900DFFF7070708FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00AEAEB2513015AEEAE7E7E718FFFFFF00FFFFFF00FFFF
            FF00492FC2D02900DFFF35296ED6D1D1D12EFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FEFEFE01584A98B52900DFFFB1AFBC50FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00320FD2F02900DFFF505050AFE9E9E916FFFFFF00FFFFFF00FCFC
            FC033518BBE72900DFFFEAEAEA15FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF002900DFFF2900DFFF6161619EF5F5F50AFCFCFC033518
            BBE72900DFFFEDEDED12FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF002900DFFF2B06D1F96B6B6B943517BBE82900
            DFFFEDEDED12FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00320FD2F02900DFFF2900DFFFDBDB
            DB24FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FCFCFC032C08D2F72900DFFF2900DFFF5959
            59A6E3E3E31CFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FCFCFC033518BBE72900DFFFE1E1E11E6F60B69F2900
            DFFF4B4A53B5C9C9C936FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FCFCFC033518BBE72900DFFFD4D4D42BFFFFFF00FFFFFF00D0CF
            D6302900DFFF42386EC79A9A9A65FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00F5F5F50A3316BBE92900DFFFB4B4B74BFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF002900DFFF351BB0E4CECECE31FFFFFF00FFFFFF00FFFFFF00FFFF
            FF002C08D2F72900DFFF6960949FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00A39EBD61FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF002900DFFF391FB0E0FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        end
      end
      object LV_Sar2: TListView
        Left = 0
        Top = 120
        Width = 625
        Height = 57
        Columns = <
          item
            Caption = #1050#1091' '#1091#1089#1080#1083'-'#1083#1103' 1 ['#1076#1041']'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1050#1091' '#1091#1089#1080#1083'-'#1083#1103' 2 ['#1076#1041']'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = 'f'#1089#1088' '#1092#1080#1083#1100#1090#1088#1072' 1 ['#1075#1088#1072#1076'.]'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = 'f'#1089#1088' '#1092#1080#1083#1100#1090#1088#1072' 2 ['#1075#1088#1072#1076'.]'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = 'W'#1088#1072#1073'. '#1087#1088#1080#1105#1084#1085'.'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = 'W'#1088#1072#1073'. '#1087#1077#1088#1077#1076#1072#1090'.'
            Width = 94
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        GridLines = True
        MultiSelect = True
        ReadOnly = True
        RowSelect = True
        ParentFont = False
        TabOrder = 5
        ViewStyle = vsReport
        Visible = False
        OnDblClick = LV_Sar2DblClick
      end
      object StaticText3: TStaticText
        Left = 272
        Top = 184
        Width = 76
        Height = 17
        Caption = #1044#1072#1085#1099#1077' sar '#8470'3'
        TabOrder = 6
        Visible = False
      end
      object LV_Sar3: TListView
        Left = 0
        Top = 208
        Width = 625
        Height = 57
        Columns = <
          item
            Caption = #1041#1072#1081#1090' 1'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 2'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 3'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 4'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 5'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 6'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 7'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 8'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 9'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 10'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 11'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 12'
            Width = 55
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        GridLines = True
        MultiSelect = True
        ReadOnly = True
        RowSelect = True
        ParentFont = False
        TabOrder = 7
        ViewStyle = vsReport
        Visible = False
        OnDblClick = LV_Sar3DblClick
      end
      object StaticText4: TStaticText
        Left = 272
        Top = 272
        Width = 76
        Height = 17
        Caption = #1044#1072#1085#1099#1077' sar '#8470'4'
        TabOrder = 8
        Visible = False
      end
      object GroupBox4: TGroupBox
        Left = 648
        Top = 184
        Width = 121
        Height = 81
        Caption = #1044#1072#1085#1085#1099#1077' sar '#8470'3'
        TabOrder = 9
        Visible = False
        object B_AddSar3: TBitBtn
          Left = 16
          Top = 16
          Width = 89
          Height = 25
          Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077'|'#1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          TabOrder = 0
          OnClick = B_AddSar3Click
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            3333333333333333333333330000333333333333333333333333F33333333333
            00003333344333333333333333388F3333333333000033334224333333333333
            338338F3333333330000333422224333333333333833338F3333333300003342
            222224333333333383333338F3333333000034222A22224333333338F338F333
            8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
            33333338F83338F338F33333000033A33333A222433333338333338F338F3333
            0000333333333A222433333333333338F338F33300003333333333A222433333
            333333338F338F33000033333333333A222433333333333338F338F300003333
            33333333A222433333333333338F338F00003333333333333A22433333333333
            3338F38F000033333333333333A223333333333333338F830000333333333333
            333A333333333333333338330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
        end
        object B_DeleteSar3: TBitBtn
          Left = 16
          Top = 48
          Width = 89
          Height = 25
          Hint = #1059#1076#1072#1083#1080#1090#1100' '#1076#1072#1085#1085#1099#1077'|'#1059#1076#1072#1083#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
          Caption = #1059#1076#1072#1083#1080#1090#1100
          TabOrder = 1
          OnClick = B_DeleteSar3Click
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00E7E7E718F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00310ED2F12900DFFF7070708FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00AEAEB2513015AEEAE7E7E718FFFFFF00FFFFFF00FFFF
            FF00492FC2D02900DFFF35296ED6D1D1D12EFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FEFEFE01584A98B52900DFFFB1AFBC50FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00320FD2F02900DFFF505050AFE9E9E916FFFFFF00FFFFFF00FCFC
            FC033518BBE72900DFFFEAEAEA15FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF002900DFFF2900DFFF6161619EF5F5F50AFCFCFC033518
            BBE72900DFFFEDEDED12FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF002900DFFF2B06D1F96B6B6B943517BBE82900
            DFFFEDEDED12FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00320FD2F02900DFFF2900DFFFDBDB
            DB24FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FCFCFC032C08D2F72900DFFF2900DFFF5959
            59A6E3E3E31CFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FCFCFC033518BBE72900DFFFE1E1E11E6F60B69F2900
            DFFF4B4A53B5C9C9C936FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FCFCFC033518BBE72900DFFFD4D4D42BFFFFFF00FFFFFF00D0CF
            D6302900DFFF42386EC79A9A9A65FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00F5F5F50A3316BBE92900DFFFB4B4B74BFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF002900DFFF351BB0E4CECECE31FFFFFF00FFFFFF00FFFFFF00FFFF
            FF002C08D2F72900DFFF6960949FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00A39EBD61FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF002900DFFF391FB0E0FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        end
      end
      object GroupBox5: TGroupBox
        Left = 648
        Top = 272
        Width = 121
        Height = 81
        Caption = #1044#1072#1085#1085#1099#1077' sar '#8470'4'
        TabOrder = 10
        Visible = False
        object B_AddSar4: TBitBtn
          Left = 16
          Top = 16
          Width = 89
          Height = 25
          Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077'|'#1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          TabOrder = 0
          OnClick = B_AddSar4Click
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            3333333333333333333333330000333333333333333333333333F33333333333
            00003333344333333333333333388F3333333333000033334224333333333333
            338338F3333333330000333422224333333333333833338F3333333300003342
            222224333333333383333338F3333333000034222A22224333333338F338F333
            8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
            33333338F83338F338F33333000033A33333A222433333338333338F338F3333
            0000333333333A222433333333333338F338F33300003333333333A222433333
            333333338F338F33000033333333333A222433333333333338F338F300003333
            33333333A222433333333333338F338F00003333333333333A22433333333333
            3338F38F000033333333333333A223333333333333338F830000333333333333
            333A333333333333333338330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
        end
        object B_DeleteSar4: TBitBtn
          Left = 16
          Top = 48
          Width = 89
          Height = 25
          Hint = #1059#1076#1072#1083#1080#1090#1100' '#1076#1072#1085#1085#1099#1077'|'#1059#1076#1072#1083#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
          Caption = #1059#1076#1072#1083#1080#1090#1100
          TabOrder = 1
          OnClick = B_DeleteSar4Click
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00E7E7E718F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00310ED2F12900DFFF7070708FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00AEAEB2513015AEEAE7E7E718FFFFFF00FFFFFF00FFFF
            FF00492FC2D02900DFFF35296ED6D1D1D12EFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FEFEFE01584A98B52900DFFFB1AFBC50FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00320FD2F02900DFFF505050AFE9E9E916FFFFFF00FFFFFF00FCFC
            FC033518BBE72900DFFFEAEAEA15FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF002900DFFF2900DFFF6161619EF5F5F50AFCFCFC033518
            BBE72900DFFFEDEDED12FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF002900DFFF2B06D1F96B6B6B943517BBE82900
            DFFFEDEDED12FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00320FD2F02900DFFF2900DFFFDBDB
            DB24FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FCFCFC032C08D2F72900DFFF2900DFFF5959
            59A6E3E3E31CFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FCFCFC033518BBE72900DFFFE1E1E11E6F60B69F2900
            DFFF4B4A53B5C9C9C936FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FCFCFC033518BBE72900DFFFD4D4D42BFFFFFF00FFFFFF00D0CF
            D6302900DFFF42386EC79A9A9A65FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00F5F5F50A3316BBE92900DFFFB4B4B74BFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF002900DFFF351BB0E4CECECE31FFFFFF00FFFFFF00FFFFFF00FFFF
            FF002C08D2F72900DFFF6960949FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00A39EBD61FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF002900DFFF391FB0E0FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        end
      end
      object LV_Sar4: TListView
        Left = 0
        Top = 296
        Width = 625
        Height = 57
        Columns = <
          item
            Caption = #1041#1072#1081#1090' 13'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 14'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 15'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 16'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 17'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 18'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 19'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 20'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 21'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 22'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 23'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090' 24'
            Width = 55
          end>
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        GridLines = True
        MultiSelect = True
        ReadOnly = True
        RowSelect = True
        ParentFont = False
        TabOrder = 11
        ViewStyle = vsReport
        Visible = False
        OnDblClick = LV_Sar4DblClick
      end
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 880
    Height = 33
    Caption = 'ToolBar1'
    Images = ImageList1
    TabOrder = 2
    object ToolButton1: TToolButton
      Left = 0
      Top = 2
      Width = 8
      Caption = 'ToolButton1'
      Style = tbsSeparator
    end
    object TB_LoadBlp: TToolButton
      Left = 8
      Top = 2
      Hint = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058
      ImageIndex = 0
      ParentShowHint = False
      ShowHint = True
      OnClick = LoadBlpClick
    end
    object ToolButton3: TToolButton
      Left = 31
      Top = 2
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 1
      Style = tbsSeparator
    end
    object TB_LoadSar: TToolButton
      Left = 39
      Top = 2
      Hint = 
        #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084 +
        #1086#1076#1091#1083#1103
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103
      ImageIndex = 1
      OnClick = LoadSarClick
    end
    object ToolButton5: TToolButton
      Left = 62
      Top = 2
      Width = 8
      Caption = 'ToolButton5'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object TB_SaveBlp: TToolButton
      Left = 70
      Top = 2
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058
      Caption = 'TB_SaveBlp'
      ImageIndex = 2
      OnClick = SaveBlpClick
    end
    object ToolButton7: TToolButton
      Left = 93
      Top = 2
      Width = 8
      Caption = 'ToolButton7'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object TB_SaveSar: TToolButton
      Left = 101
      Top = 2
      Hint = 
        #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084 +
        #1086#1076#1091#1083#1103
      Caption = 'TB_SaveSar'
      ImageIndex = 3
      OnClick = SaveSarClick
    end
    object ToolButton9: TToolButton
      Left = 124
      Top = 2
      Width = 8
      Caption = 'ToolButton9'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object TB_Exit: TToolButton
      Left = 132
      Top = 2
      Hint = #1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099'|'#1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
      Caption = 'TB_Exit'
      ImageIndex = 6
      OnClick = ExitClick
    end
    object ToolButton11: TToolButton
      Left = 155
      Top = 2
      Width = 8
      Caption = 'ToolButton11'
      ImageIndex = 5
      Style = tbsSeparator
    end
    object TB_About: TToolButton
      Left = 163
      Top = 2
      Hint = 
        #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093'|'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075 +
        #1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093
      Caption = 'TB_About'
      ImageIndex = 5
      OnClick = HelpAboutItemClick
    end
  end
  object MainMenu: TMainMenu
    Left = 224
    object File: TMenuItem
      Caption = '&'#1060#1072#1081#1083
      Hint = #1052#1077#1085#1102' '#1092#1072#1081#1083#1086#1074
      object LoadBlp: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' .blp'
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058'|'#1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058
        OnClick = LoadBlpClick
      end
      object LoadSar: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' .sar'
        Hint = 
          #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103'|'#1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083 +
          #1103
        OnClick = LoadSarClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object SaveBlp: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' .blp'
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058
        OnClick = SaveBlpClick
      end
      object SaveSar: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' .sar'
        Hint = 
          #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084 +
          #1086#1076#1091#1083#1103
        OnClick = SaveSarClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Exit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        Hint = #1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099'|'#1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
        OnClick = ExitClick
      end
    end
    object Help: TMenuItem
      Caption = '&'#1057#1087#1088#1072#1074#1082#1072
      Hint = #1052#1077#1085#1102' '#1089#1087#1088#1072#1074#1082#1080
      object HelpAboutProg: TMenuItem
        Caption = #1055#1086#1084#1086#1097#1100
        Hint = 
          #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093'|'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075 +
          #1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093
        OnClick = HelpAboutProgClick
      end
      object HelpAboutItem: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = HelpAboutItemClick
      end
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'blp'
    Filter = #1076#1072#1085#1085#1099#1077' '#1041#1058' (*.blp)|*.blp'
    Title = #1054#1090#1082#1088#1099#1090#1080#1077' '#1092#1072#1081#1083#1072' '#1076#1072#1085#1085#1099#1093' '#1041#1058
    Left = 256
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'blp'
    Filter = #1076#1072#1085#1085#1099#1077' '#1041#1058' (*.blp)|*.blp'
    Left = 288
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'sar'
    Filter = #1076#1072#1085#1085#1099#1077' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103' (*.sar)|*.sar'
    Title = #1054#1090#1082#1088#1099#1090#1080#1077' '#1092#1072#1081#1083#1072' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103
    Left = 320
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'sar'
    Filter = #1076#1072#1085#1085#1099#1077' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103' (*.sar)|*.sar'
    Left = 352
  end
  object ImageList1: TImageList
    Left = 384
    Bitmap = {
      494C010107000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FCFC
      FC03EAEAEA15CBCBCB34B6B6B649B1B1B14EB3B3B34CC3C3C33CE3E3E31CF8F8
      F807FEFEFE01FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00E7E7
      E718F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F3F3F30CFFFFFF00FFFFFF00FFFFFF00FFFFFF00F5F5F50AC1C1
      C13E988D88CDE8D3C8FDF0DCD1FFF0DCD1FFEFDBD0FFB8A89EF5585858A7A7A7
      A758EAEAEA15FEFEFE01FFFFFF00FFFFFF000000000000000000000000000000
      0000F718F700000000000000000000000000000000000000000000000000F718
      F700000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00310ED2F12900
      DFFF7070708FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00AEAEB2513015AEEAE7E7E718FFFFFF00FFFFFF00F3F3F30CA3A3A35DF2DF
      D5FFF2F4F5FFEBEEEFFFDFE2E3FFECEFF1FFEDF0F2FFEFF2F2FFF4E9E3FF8F81
      7AEF8383837CE5E5E51AFEFEFE01FFFFFF00000000000000000000000000A500
      BD0031319400C600CE0000000000000000000000000000000000C600CE003131
      9400C600CE000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00492FC2D02900
      DFFF35296ED6D1D1D12EFFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE01584A
      98B52900DFFFB1AFBC50FFFFFF00FFFFFF00F9F9F906A4A2A06DF6F1EFFFF0F4
      F5FFD5AB95FFBB5B2AFFC06133FFC67349FFBB5827FFC98767FFEDF0F2FFF4F6
      F6FFBBA99FF88C8C8C73EFEFEF10FFFFFF0000000000000000009C00BD003131
      94003963F70031319400C600CE000000000000000000C600CE0031319400315A
      F70031319400C600CE0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00320F
      D2F02900DFFF505050AFE9E9E916FFFFFF00FFFFFF00FCFCFC033518BBE72900
      DFFFEAEAEA15FFFFFF00FFFFFF00FFFFFF00DCDCDC23F6E8E1FFF2F7F8FFC36D
      43FFC36231FFCA622EFFC1C4C5FFFFFFFFFFC76330FFC46232FFBC5A28FFECEA
      E9FFF6F7F7FF675F5AE0BCBCBC43FCFCFC03000000000000000031319400638C
      EF001031E7001842EF0031319400C600CE00C600CE00313194002952EF001031
      E700396BF70031319400F718F700000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF002900DFFF2900DFFF6161619EF5F5F50AFCFCFC033518BBE72900DFFFEDED
      ED12FFFFFF00FFFFFF00FFFFFF00FFFFFF00D7C5BBEDF6F8F9FFCE8866FFC664
      33FFCC6734FFCC6633FFC98563FFDDA88FFFCC6431FFCC6634FFC66333FFBE5D
      2CFFF1F5F7FFF2DFD5FF7575758AF0F0F00F0000000000000000EF00EF003131
      94005A7BEF001031E7001842EF003131940031319400315AEF001031E7003963
      F70031319400C600CE0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF002900DFFF2B06D1F96B6B6B943517BBE82900DFFFEDEDED12FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F4E5DCFFF4F4F4FFC35E2BFFCD68
      36FFCC6734FFCC6532FFCB957CFFEAC0AAFFCB622EFFCC6633FFCC6734FFC563
      32FFDCB6A3FFF6F6F5FF524F4EC4DBDBDB24000000000000000000000000EF00
      EF00313194006384EF001031E7001842EF003152EF001031E7004263EF003131
      9400C600CE000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00320FD2F02900DFFF2900DFFFDBDBDB24FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FCF8F5FFE4BCA9FFCC6938FFCE68
      36FFCC6633FFCC6632FFC1AEA5FFFFFFFFFFCA5D28FFCC6633FFCD6734FFCB67
      35FFC77349FFF7F9FBFFB5A49CF1CECECE310000000000000000000000000000
      0000EF00EF00313194006384F7001031E7001031E700315AEF0031319400C600
      CE00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FCFCFC032C08D2F72900DFFF2900DFFF595959A6E3E3E31CFFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFEFEFFDFA081FFD26E3CFFCE69
      36FFCC6633FFCC6633FFC66839FFF1F6F8FFFAF1ECFFCA602BFFCC6734FFCE69
      37FFC86939FFF9FCFEFFC1B0A7F5CCCCCC330000000000000000000000000000
      0000C600CE00313194004A73F7001039EF001039EF002142EF0031319400C600
      CE00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FCFCFC033518BBE72900DFFFE1E1E11E6F60B69F2900DFFF4B4A53B5C9C9
      C936FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFBFBFFECB99FFFDA7644FFD06B
      38FFCC6633FFCC6633FFCC6633FFC5693AFFFCFFFFFFF5E0D7FFCD6531FFD26D
      3BFFCE7143FFFFFFFFFFBDADA4F1D5D5D52A000000000000000000000000C600
      CE00313194005A84F700184AF7004A73F7007394F7001842EF00214AEF003131
      9400C600CE000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FCFC
      FC033518BBE72900DFFFD4D4D42BFFFFFF00FFFFFF00D0CFD6302900DFFF4238
      6EC79A9A9A65FEFEFE01FFFFFF00FFFFFF00F8ECE6FFFEFAF7FFE8824FFFD872
      3FFFCF9071FFE7B9A3FFCB622DFFCC6633FFE1CDC2FFFFFFFFFFD06733FFD874
      41FFE5AB8EFFFFFEFEFF827A75C0EAEAEA150000000000000000C600CE003131
      9400739CFF001852F7005284F700313194003131940084A5F7001842EF002952
      EF0031319400C600CE0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00F5F5F50A3316
      BBE92900DFFFB4B4B74BFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF002900
      DFFF351BB0E4CECECE31FFFFFF00FFFFFF00EBD6CCFAFFFFFFFFFDA374FFF48F
      5CFFC69F8CFFFFFFFFFFE6B299FFD17F56FFFCFEFFFFEDEDECFFDF7641FFE077
      44FFFFFFFFFFF6E9E1FFA9A9A956F9F9F906000000000000000031319400C6DE
      FF003163FF005A8CFF0031319400C600CE00EF00EF00313194008CA5F700214A
      F7007394F70031319400EF21F700000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF002C08D2F72900
      DFFF6960949FFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00A39EBD61FFFFFF00FFFFFF00FFFFFF00E9E9E916FDFAF9FFFFFFFFFFFFB5
      80FFFFA26EFFD7CECBFFF5F9FBFFF7FBFCFFF1F6F9FFF19C73FFFA9360FFFEE2
      D2FFFFFFFFFFBCACA3E5E4E4E41BFEFEFE010000000000000000E700E7003131
      9400BDD6FF0031319400C600CE000000000000000000EF00EF0031319400B5CE
      F700313194009C00BD0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF002900DFFF391F
      B0E0FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE01C6B9B1C8FFFFFFFFFFFF
      FFFFFFEFC6FFFFDDA6FFFFC696FFFDBD8CFFFFBB87FFFFC28EFFFFFCF8FFFFFF
      FFFFF0DCD1FED0D0D02FFCFCFC03FFFFFF00000000000000000000000000DE00
      E70031319400C600CE0000000000000000000000000000000000EF00EF003131
      94009C00BD000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE01C4B7B1C4FCF7
      F5FFFFFFFFFFFFFFFFFFFFFFFDFFFFFFFCFFFFFFFDFFFFFFFFFFFFFFFFFFEDD9
      CEFDD4D4D42BFBFBFB04FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FEFEFE01EFEF
      EF10E6D4C8F6F6E9E1FFFDFAF9FFFEFCFBFFF9EEE9FFEEDACFFEA7A19F88EDED
      ED12FDFDFD02FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00B7BCBE485858
      58A7464646B96A6A6A959393936CBCBCBC43DADADA25EAEAEA15F2F2F20DF6F6
      F609FCFCFC03FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F9F9F9069F9F
      9F60E3E3E31CF6F6F609FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000AD5A5A00AD52
      5200A54A4A00AD949400C6CEC600CECEC600CECEC600C6CEC600C6CEC600B59C
      9C009C4242009C424200A552520000000000FFFFFF00F7F7F708FBFBFB04FEFE
      FE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F9F9F9064096BCFF2D93
      BFFF106387EF234E64DC394C56C64D5153B25B5B5BA47474748B9595956AB3B3
      B34CD2D2D22DE9E9E916FFFFFF00FFFFFF00FFFFFF00FFFFFF006D6D6DFF4444
      44FF343434EB494949BA7474748BBCBCBC43EFEFEF10FCFCFC03FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000BD7B7300CE636300CE6B
      6B00B55A5A009C848400BDA5A500E7CECE00FFF7F700FFFFF700F7F7F700CEB5
      B500942929009C313100C65A5A00AD5A5A00FEFEFE0181939A7E6B6B6B949999
      9966C7C7C738E5E5E51AF8F8F807FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BBC1C544308CB6FFB8EB
      FFFF69D2FCFF4DC3EFFF31A7D6FF1C8FBFFF0C6A91F31E526CE12E4D5CD1454E
      52BA595959A68282827DE3E3E31CFFFFFF00FFFFFF00FFFFFF00828282FF5353
      53FF444444FF00CCFFFF0C82DBFF293669FF3A3A3AD7585858A79595956ADADA
      DA25F5F5F50AFFFFFF00FFFFFF00FFFFFF0000000000BD7B7300CE636300CE63
      6300B55A5A009C7B7B009C424200B5737300E7DEDE00FFF7F700FFFFFF00D6B5
      B500943131009C313100BD5A5A00AD5A5A00FEFEFE0167C3E2FF6DD3FFFF37B7
      E6FF0D8CB8F7325F6FCD6565659A8C8C8C73BFBFBF40E0E0E01FF4F4F40BFEFE
      FE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BBC1C544278BBCFFC6EC
      F9FF7AE0FFFF7AE0FFFF7AE0FFFF7AE0FFFF7AE0FFFF5CCEF2FF3DB3DCFF269C
      C9FF126D94F3535353ACB0B0B04FF6F6F609FFFFFF00FFFFFF00858585FF5151
      51FF434343FFECD9CFFF93998FFF26A6BFFF0080FFFF0033FFFF203380FF3939
      39EF525252B1F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300CE636300CE63
      6300B55A5A00AD8484009C3939009C393900CEBDBD00EFEFEF00FFFFFF00E7C6
      C6009429290094313100BD5A5A00AD5A5A00FEFEFE014CBDECFFA9E9FFFF76DC
      FFFF76DCFFFF76DCFFFF76DCFFFF4AC4ECFF0FA2D2FF25657CDA5F5F5FA08888
      8877F0F0F00FFFFFFF00FFFFFF00FFFFFF00FFFFFF00BBC1C54454B6E1FF8FC6
      DCFF94EEFFFF85EBFFFF85EBFFFF85EBFFFF85EBFFFF85EBFFFF85EBFFFF85EB
      FFFF5DCDE9FF2A4959D579797986E6E6E619FFFFFF00FFFFFF00888888FF4E4E
      4EFF424242FF563370FF993300FFD9B39FFFFFFFFFFF0033FFFF1A3399FF6363
      63FF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300CE636300CE63
      6300B55A5A00B58C8C009C4A4A0094313100A59C9C00D6D6D600FFFFFF00E7C6
      C6009429290094313100BD5A5A00AD5A5A00FEFEFE0177D0FAFFF7FDFFFF80E6
      FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF1981
      A1EEB9B9B946FFFFFF00FFFFFF00FFFFFF00FFFFFF00BAC0C44561C6F0FF60AE
      D1FFC0F9FFFF8FF5FFFF8FF5FFFF8FF5FFFF8FF5FFFF8FF5FFFF8FF5FFFF8FF5
      FFFF9BF2FFFF207899F3565656A9B9B9B946FFFFFF00FFFFFF008B8B8BFF4C4C
      4CFF404040FF0033FFFF0033FFFF0033FFFF0033FFFF0033FFFF1A3399FF6060
      60FF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300CE636300CE63
      6300BD5A5A00C6948C00C6949400B5848400AD8C8C00BDA5A500E7C6C600DEAD
      AD00A5393900A5393900C65A5A00AD5A5A00FEFEFE0180D3FBFF80CCE6FF8AF0
      FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF9DF9
      FCFF6B6B6B94F7F7F708FFFFFF00FFFFFF00FFFFFF00A2ADB35D6DCAF2FF319E
      D1FFD6F9FCFF99FFFFFF99FFFFFF99FFFFFF99FFFFFF99FFFFFF99FFFFFF99FF
      FFFFABF2FFFF79CFE2FF354853CA77777788FFFFFF00FFFFFF008E8E8EFF4949
      49FF3C3C3CFF424242FF4F4F4FFF434343FF1D338CFF0633E6FF1A3399FF5E5E
      5EFF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300CE636300CE63
      6300CE636300CE636300CE636300CE636300CE636300C65A5A00C65A5A00CE63
      6300CE636300CE636300CE6B6B00AD525A00FEFEFE018BD8FDFF30B1E4FFA8FB
      FFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFFBBFF
      FFFF23647ADCCECECE31FFFFFF00FFFFFF00F8F8F8076483929B8FD9F9FF59BF
      ECFF80BFD9FFE7FFFFFFD9FFFFFFCBFFFFFFC0FFFFFFB9FFFFFFB9FFFFFFB9FF
      FFFFBAF2FFFFD6FFFFFF1F6682EB474747B8FFFFFF00FFFFFF00919191FF4646
      46FF383838FF333333FF333333FF333333FF535353FF333333FF4F4F4FFF5B5B
      5BFF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300B5525200B55A
      5A00C6848400D6A5A500D6ADAD00D6ADA500D6ADAD00D6A5A500D6A5A500D6AD
      A500D6ADAD00D69C9C00CE636300AD525200FEFEFE018CD8FFFF66CCFFFFF3FF
      FFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFCEFF
      FFFF9BE6F2FF7D7D7D82FBFBFB04FFFFFF00ACB6AC531A692AE52D8640FF1D83
      40FF076D2DFF006C2DFF208039FF408F4DFFCCE9F2FFDCFFFFFFD3FFFFFFD3FF
      FFFFCAF2FFFFEBFFFFFF76BCD6FF3D464BC2FFFFFF00FFFFFF00949494FF4444
      44FF464646FF424242FF393939FF333333FF4F4F4FFF333333FF333333FF5959
      59FF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300AD524A00E7CE
      CE00F7F7F700F7F7EF00F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F700F7F7F700DEBDBD00C65A5A00AD525A00F6F6F6099AE2FFFF74DAFFFF4AC3
      ECFF5EC4E6FF80CCE6FFDFF2F9FFCBFFFFFFC0FFFFFFC0FFFFFFC0FFFFFFE1FF
      FFFFE1FFFFFF355B67CADEDEDE21FFFFFF00CFD2CF30259037F038D16BFF32CB
      64FF28C150FF1CB538FF12AB23FF06850BFF49AFCCFF80B9D2FF8FC6DCFFBEE2
      EFFFE6F5FCFFFFFFFFFFEFF9FCFF406A7EBFFFFFFF00FFFFFF00979797FF4141
      41FF7DE3FFFF82E8FFFF87EDFFFF8CF2FFFF74ADB2FF475354FF474747FF5656
      56FF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300B5524A00EFD6
      D600FFF7F700F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EF
      EF00F7F7F700DEBDBD00C65A5A00AD525A00B7C1C54897ECFFFF85EBFFFF85EB
      FFFF85EBFFFF85EBFFFF85EBFFFF68C5E2FFF5FFFFFFEDFFFFFFE5FFFFFFF4FF
      FFFFF4FFFFFF89D2E9FF9B9B9B64FEFEFE01FFFFFF0072918F8D18912BFF38D1
      6BFF32CB64FF28C150FF1CB538FF0B8A15FF9FFFFFFF99FFFFFF86ECF2FF73D9
      E6FF0A6590F53B7086C46990A5C7A3AFB55CFFFFFF00FFFFFF009A9A9AFF3E3E
      3EFF82E8FFFF90F6FFFF8EF4FFFF96FCFFFF92F8FFFF97FDFFFF97FDFFFF5353
      53FF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300B5524A00EFD6
      D600EFEFEF00D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6
      D600EFEFEF00DEBDBD00C65A5A00AD525A00B7C1C548A8FAFFFF96FCFFFF96FC
      FFFF96FCFFFF96FCFFFF96FCFFFF96FCFFFF96FCFFFF8DF6FCFF5FD8ECFF2686
      A5E670C6E2FFBFE6F2FFD7D7D728FFFFFF00F5F5F50A3D7647C53FCE68FF42DB
      75FF38D16BFF32CB64FF28C150FF0F8F1EFF79B6D2FF91C9DFFF9FE0EFFFB4F0
      F9FF387B98D2D1D1D12EFBFBFB04FFFFFF00FFFFFF00FFFFFF009C9C9CFF3B3B
      3BFF8DF3FFFF88EEFFFF90F6FFFF8BF1FFFF91F7FFFF93F9FFFF98FEFFFF5151
      51FF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300B5524A00EFD6
      D600EFEFEF00DED6D600DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DED6
      D600EFEFEF00DEBDBD00C65A5A00AD525A00DEE0E121CCFBFFFF99FFFFFF99FF
      FFFF99FFFFFFD7FBFFFFC3FCFFFFAEFEFFFF99FFFFFF99FFFFFF99FFFFFF6E6E
      6E91FEFEFE01FFFFFF00FFFFFF00FFFFFF008DA08D7248D56FFF57F08AFF4DE6
      80FF42DB75FF38D16BFF32CB64FF15952BFF585858A7BCC0C343BCC2C5438C9F
      AA73C7CBCD38FBFBFB04FFFFFF00FFFFFF00FFFFFF00FFFFFF009F9F9FFF3939
      39FF6ED4FFFF73D9FFFF78DEFFFF7DE3FFFF82E8FFFF87EDFFFF94FAFFFF4E4E
      4EFF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300B5524A00EFD6
      D600F7F7EF00E7DEDE00E7DEDE00E7DEDE00E7DEDE00E7DEDE00E7DEDE00E7DE
      DE00EFEFEF00DEBDBD00C65A5A00AD525A00FFFFFF007BCBE6FFE1FDFFFFC3FE
      FFFFD5FEFFFF5B7F8BA4FBFBFB04CDD2D43279A0AE865C9FB7C56BC4E2FFE1E1
      E11EFFFFFF00FFFFFF00FFFFFF00FFFFFF00CFD2CF30329E44F061FA94FF57F0
      8AFF4DE680FF2EB751FF38D16BFF1A9933FF5C5C5CA3E7E7E718FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00A2A2A2FF3636
      36FF69CFFFFF6ED4FFFF73D9FFFF78DEFFFF7DE3FFFF82E8FFFF87EDFFFF4C4C
      4CFF3B3B3BD9F3F3F30CFFFFFF00FFFFFF0000000000BD7B7300B5524A00EFD6
      D600EFEFEF00D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6
      D600EFEFEF00DEBDBD00C65A5A00AD525A00FFFFFF00FFFFFF00FEFEFE01DEE0
      E121B8C2C647FBFBFB04FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CFD2CF30329E44F061FA
      94FF36BC56FF567756A9249036F11E9D37FF8F8F8F70EAEAEA15FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00A5A5A5FF3333
      33FF363636FF3F4C52FF527E91FF66B2CFFF78DEFFFF7DE3FFFF82E8FFFF4949
      49FF494949C9F8F8F807FFFFFF00FFFFFF0000000000BD7B7300B5524A00E7D6
      CE00FFF7F700F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EF
      EF00FFF7F700DEBDBD00C65A5A00AD525A00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CFD2CF302084
      2BEF91A1916EF6F6F609CFD2CF30227325E0EAEAEA15FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EFEF
      EF10B2B2B2548D8D8D94838383D2878787FF8A8A8AFF6C6C6CFF4C4C4CFF6666
      66B0FEFEFE01FFFFFF00FFFFFF00FFFFFF000000000000000000AD524A00CEB5
      B500D6D6D600CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00CECE
      CE00D6D6D600CEADAD00A54A4A0000000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FFFF000000000000F7EF0000
      00000000E3C7000000000000C183000000000000C001000000000000C0030000
      00000000E007000000000000F00F000000000000F00F000000000000E0070000
      00000000C003000000000000C001000000000000C183000000000000E3C70000
      00000000FFFF000000000000FFFF0000000000000000C0010000000000008000
      0000000000008000000000000000800000000000000080000000000000008000
      0000000000008000000000000000800000000000000080000000000000008000
      0000000000008000000000000000800000000000000080000000000000008000
      0000000000008000000000000000C00100000000000000000000000000000000
      000000000000}
  end
  object OpenDialog2: TOpenDialog
    DefaultExt = 'BMP'
    Filter = 'Jpeg Files|*.jpg|Bitmap Files|*.BMP'
    Options = [ofReadOnly, ofPathMustExist, ofFileMustExist]
    Title = 'Select a Bitmap File'
    Left = 420
    Top = 3
  end
end
