object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'ApertureControlProgram'
  ClientHeight = 576
  ClientWidth = 940
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object SB_OnOff: TSpeedButton
    Left = 8
    Top = 39
    Width = 105
    Height = 98
    Hint = #1042#1082#1083#1102#1095#1080#1090#1100'/'#1074#1099#1082#1083#1102#1095#1080#1090#1100' '#1080#1079#1076#1077#1083#1080#1077'|'#1042#1082#1083#1102#1095#1080#1090#1100'/'#1074#1099#1082#1083#1102#1095#1080#1090#1100' '#1080#1079#1076#1077#1083#1080#1077
    AllowAllUp = True
    GroupIndex = 1
    Caption = #1042#1082#1083#1102#1095#1080#1090#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clGreen
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = SB_OnOffClick
  end
  object L_H: TLabel
    Left = 861
    Top = 39
    Width = 12
    Height = 13
    Caption = '00'
    Visible = False
  end
  object L_M: TLabel
    Left = 877
    Top = 39
    Width = 12
    Height = 13
    Caption = '00'
    Visible = False
  end
  object L_S: TLabel
    Left = 895
    Top = 39
    Width = 12
    Height = 13
    Caption = '00'
    Visible = False
  end
  object Label6: TLabel
    Left = 648
    Top = 281
    Width = 28
    Height = 13
    Caption = #1060#1056#1051#1055
  end
  object Label7: TLabel
    Left = 709
    Top = 281
    Width = 21
    Height = 13
    Caption = #1055#1056#1052
  end
  object Label9: TLabel
    Left = 773
    Top = 281
    Width = 21
    Height = 13
    Caption = #1055#1056#1044
  end
  object Label10: TLabel
    Left = 837
    Top = 281
    Width = 13
    Height = 13
    Caption = #1041#1057
  end
  object Label11: TLabel
    Left = 648
    Top = 335
    Width = 42
    Height = 13
    Caption = #1047#1072#1093#1074#1072#1090'1'
  end
  object Label17: TLabel
    Left = 773
    Top = 335
    Width = 38
    Height = 13
    Caption = #1042#1050'-'#1055#1056#1052
  end
  object Label18: TLabel
    Left = 773
    Top = 322
    Width = 31
    Height = 13
    Caption = #1044'1 '#1044'2'
  end
  object Label20: TLabel
    Left = 837
    Top = 335
    Width = 38
    Height = 13
    Caption = #1042#1050'-'#1055#1056#1044
  end
  object Label19: TLabel
    Left = 835
    Top = 322
    Width = 31
    Height = 13
    Caption = #1044'3 '#1044'4'
  end
  object Label21: TLabel
    Left = 896
    Top = 335
    Width = 38
    Height = 13
    Caption = #1042#1050'-'#1055#1056#1044
  end
  object Label12: TLabel
    Left = 898
    Top = 281
    Width = 14
    Height = 13
    Caption = #1059#1059
  end
  object Label14: TLabel
    Left = 709
    Top = 335
    Width = 42
    Height = 13
    Caption = #1047#1072#1093#1074#1072#1090'2'
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 940
    Height = 33
    Caption = 'ToolBar1'
    Images = ImageList1
    TabOrder = 0
    object ToolButton3: TToolButton
      Left = 0
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 1
      Style = tbsSeparator
    end
    object TB_LoadBlp: TToolButton
      Left = 8
      Top = 0
      Hint = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058
      ImageIndex = 0
      ParentShowHint = False
      ShowHint = True
      OnClick = TB_LoadBlpClick
    end
    object ToolButton1: TToolButton
      Left = 31
      Top = 0
      Width = 8
      Caption = 'ToolButton1'
      ImageIndex = 7
      Style = tbsSeparator
    end
    object TB_LoadSar: TToolButton
      Left = 39
      Top = 0
      Hint = 
        #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084 +
        #1086#1076#1091#1083#1103
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103
      ImageIndex = 1
      OnClick = TB_LoadSarClick
    end
    object ToolButton5: TToolButton
      Left = 62
      Top = 0
      Width = 35
      Caption = 'ToolButton5'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object TB_SaveControl: TToolButton
      Left = 97
      Top = 0
      Hint = 
        #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077 +
        #1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      ImageIndex = 2
      OnClick = TB_SaveControlClick
    end
    object ToolButton7: TToolButton
      Left = 120
      Top = 0
      Width = 8
      Caption = 'ToolButton7'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object TB_SaveTesting: TToolButton
      Left = 128
      Top = 0
      Hint = 
        #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' ' +
        #1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
      ImageIndex = 3
      OnClick = TB_SaveTestingClick
    end
    object ToolButton2: TToolButton
      Left = 151
      Top = 0
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object TB_LoadControl: TToolButton
      Left = 159
      Top = 0
      Hint = 
        #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077 +
        #1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Caption = 'TB_LoadControl'
      ImageIndex = 4
      OnClick = TB_LoadControlClick
    end
    object ToolButton4: TToolButton
      Left = 182
      Top = 0
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 5
      Style = tbsSeparator
    end
    object TB_LoadTesting: TToolButton
      Left = 190
      Top = 0
      Hint = 
        #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' ' +
        #1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
      Caption = 'TB_LoadTesting'
      ImageIndex = 5
      OnClick = TB_LoadTestingClick
    end
    object ToolButton6: TToolButton
      Left = 213
      Top = 0
      Width = 35
      Caption = 'ToolButton6'
      ImageIndex = 6
      Style = tbsSeparator
    end
    object TB_About: TToolButton
      Left = 248
      Top = 0
      Hint = 
        #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093'|'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075 +
        #1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093
      Caption = 'TB_About'
      ImageIndex = 6
      OnClick = TB_AboutClick
    end
  end
  object GB_AvailableCom: TGroupBox
    Left = 302
    Top = 32
    Width = 226
    Height = 105
    Hint = #1056#1072#1073#1086#1090#1072#1077#1090' '#1090#1086#1083#1100#1082#1086' '#1074' '#1088#1077#1078#1080#1084#1077' '#1040#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088#1072
    Caption = #1044#1086#1089#1090#1091#1087#1085#1099#1077' Com-'#1087#1086#1088#1090#1099
    TabOrder = 1
    object B_AvailableCom: TButton
      Left = 135
      Top = 64
      Width = 81
      Height = 33
      Hint = #1056#1072#1073#1086#1090#1072#1077#1090' '#1090#1086#1083#1100#1082#1086' '#1074' '#1088#1077#1078#1080#1084#1077' '#1040#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088#1072
      Caption = #1059#1079#1085#1072#1090#1100
      TabOrder = 0
      OnClick = B_AvailableComClick
    end
    object LB_AvailableCom: TListBox
      Left = 8
      Top = 16
      Width = 121
      Height = 81
      ItemHeight = 13
      TabOrder = 1
    end
  end
  object PC_Main: TPageControl
    Left = 17
    Top = 157
    Width = 625
    Height = 394
    ActivePage = Tsh_Control
    BiDiMode = bdRightToLeftNoAlign
    MultiLine = True
    ParentBiDiMode = False
    TabOrder = 2
    object Tsh_Control: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077' '#1074' '#1088#1077#1078#1080#1084#1077' '#1056#1072#1073#1086#1090#1072
      ImageIndex = 3
      object SB_Data2: TScrollBox
        Left = 0
        Top = 3
        Width = 615
        Height = 361
        VertScrollBar.Range = 2530
        VertScrollBar.Smooth = True
        VertScrollBar.Tracking = True
        AutoScroll = False
        BorderStyle = bsNone
        TabOrder = 0
        object GroupBox1: TGroupBox
          Left = 10
          Top = 14
          Width = 561
          Height = 57
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1047#1072#1090#1091#1093#1072#1085#1080#1077' '#1072#1090#1090#1077#1085#1102#1072#1090#1086#1088#1072' '#1087#1088#1080#1077#1084#1085#1080#1082#1072'". ['#1076#1041']'
          TabOrder = 0
          object CB_Att_PRM: TComboBox
            Left = 205
            Top = 24
            Width = 233
            Height = 21
            ItemIndex = 0
            TabOrder = 0
            Text = '0'
            Items.Strings = (
              '0'
              '-1'
              '-2'
              '-3'
              '-4'
              '-5'
              '-6'
              '-7'
              '-8'
              '-9'
              '-10'
              '-11'
              '-12'
              '-13'
              '-14'
              '-15'
              '-16'
              '-17'
              '-18'
              '-19'
              '-20'
              '-21'
              '-22'
              '-23'
              '-24'
              '-25'
              '-26'
              '-27'
              '-28'
              '-29'
              '-30'
              '-31')
          end
        end
        object GroupBox2: TGroupBox
          Left = 10
          Top = 77
          Width = 561
          Height = 57
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1047#1072#1090#1091#1093#1072#1085#1080#1077' '#1072#1090#1090#1077#1085#1102#1072#1090#1086#1088#1072' '#1087#1077#1088#1077#1076#1072#1090#1095#1080#1082#1072'". ['#1076#1041']'
          TabOrder = 1
          object CB_Att_PRD: TComboBox
            Left = 205
            Top = 25
            Width = 233
            Height = 21
            ItemIndex = 0
            TabOrder = 0
            Text = '0'
            Items.Strings = (
              '0'
              '-1'
              '-2'
              '-3'
              '-4'
              '-5'
              '-6'
              '-7'
              '-8'
              '-9'
              '-10'
              '-11'
              '-12'
              '-13'
              '-14'
              '-15'
              '-16'
              '-17'
              '-18'
              '-19'
              '-20'
              '-21'
              '-22'
              '-23'
              '-24'
              '-25'
              '-26'
              '-27'
              '-28'
              '-29'
              '-30'
              '-31')
          end
        end
        object GroupBox3: TGroupBox
          Left = 10
          Top = 140
          Width = 561
          Height = 57
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1042#1099#1073#1086#1088' '#1095#1072#1089#1090#1086#1090#1085#1086#1075#1086' '#1076#1080#1072#1087#1072#1079#1086#1085#1072'"'
          TabOrder = 2
          object CB_FreqRange: TComboBox
            Left = 205
            Top = 24
            Width = 233
            Height = 21
            ItemIndex = 0
            TabOrder = 0
            Text = 'L'
            OnChange = CB_FreqRangeChange
            OnExit = CB_FreqRangeExit
            Items.Strings = (
              'L'
              'C'
              'X1'
              'X2')
          end
        end
        object GroupBox5: TGroupBox
          Left = 10
          Top = 203
          Width = 561
          Height = 57
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1042#1099#1073#1086#1088' '#1087#1086#1084#1077#1093#1080'"'
          TabOrder = 3
          object RadioButton3: TRadioButton
            Left = 398
            Top = 24
            Width = 151
            Height = 17
            Caption = #1050#1086#1075#1077#1088#1077#1085#1090#1085#1072#1103
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object RadioButton4: TRadioButton
            Left = 205
            Top = 24
            Width = 145
            Height = 17
            Caption = #1063#1072#1089#1090#1080#1095#1085#1086'-'#1082#1086#1075#1077#1088#1077#1085#1090#1085#1072#1103
            TabOrder = 1
          end
        end
      end
    end
    object Sar_invisible: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077' Sar'
      ImageIndex = 3
      TabVisible = False
      object LE_V: TLabeledEdit
        Left = 37
        Top = 32
        Width = 121
        Height = 21
        EditLabel.Width = 136
        EditLabel.Height = 13
        EditLabel.BiDiMode = bdRightToLeftNoAlign
        EditLabel.Caption = #1057#1082#1086#1088#1086#1089#1090#1100' '#1087#1086#1083#1105#1090#1072' '#1056#1057#1040' ['#1084'/'#1089']'
        EditLabel.ParentBiDiMode = False
        TabOrder = 0
        Text = '0'
      end
      object LE_f: TLabeledEdit
        Left = 37
        Top = 80
        Width = 121
        Height = 21
        EditLabel.Width = 120
        EditLabel.Height = 13
        EditLabel.BiDiMode = bdRightToLeftNoAlign
        EditLabel.Caption = #1053#1077#1089#1091#1097#1072#1103' '#1095#1072#1089#1090#1086#1090#1072' ['#1052#1043#1094']'
        EditLabel.ParentBiDiMode = False
        TabOrder = 1
        Text = '900'
      end
      object LE_Fi: TLabeledEdit
        Left = 37
        Top = 128
        Width = 121
        Height = 21
        EditLabel.Width = 145
        EditLabel.Height = 13
        EditLabel.BiDiMode = bdRightToLeftNoAlign
        EditLabel.Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1087#1086#1083#1105#1090#1072' ['#1075#1088#1072#1076'.]'
        EditLabel.ParentBiDiMode = False
        TabOrder = 2
        Text = '0'
      end
      object LE_D: TLabeledEdit
        Left = 37
        Top = 176
        Width = 121
        Height = 21
        EditLabel.Width = 118
        EditLabel.Height = 13
        EditLabel.BiDiMode = bdRightToLeftNoAlign
        EditLabel.Caption = #1056#1072#1089#1089#1090#1086#1103#1085#1080#1077' '#1076#1086' '#1094#1077#1083#1080' ['#1084']'
        EditLabel.ParentBiDiMode = False
        TabOrder = 3
        Text = '0'
      end
      object GB_Message: TGroupBox
        Left = 208
        Top = 32
        Width = 281
        Height = 273
        Caption = #1057#1086#1086#1073#1097#1077#1085#1080#1103
        TabOrder = 4
        object E_EnterComment: TEdit
          Left = 8
          Top = 48
          Width = 185
          Height = 21
          TabOrder = 0
        end
        object M_Log: TMemo
          Left = 8
          Top = 104
          Width = 265
          Height = 161
          ReadOnly = True
          ScrollBars = ssVertical
          TabOrder = 1
          Visible = False
        end
        object StaticText6: TStaticText
          Left = 8
          Top = 24
          Width = 195
          Height = 17
          Caption = #1057#1090#1088#1086#1082#1072' '#1074#1074#1086#1076#1072' '#1089#1086#1086#1073#1097#1077#1085#1080#1081' '#1086#1087#1077#1088#1072#1090#1086#1088#1072':'
          TabOrder = 2
        end
        object StaticText7: TStaticText
          Left = 8
          Top = 80
          Width = 93
          Height = 17
          Caption = #1054#1082#1085#1086' '#1089#1086#1086#1073#1097#1077#1085#1080#1081':'
          TabOrder = 3
        end
        object B_Enter: TButton
          Left = 200
          Top = 48
          Width = 75
          Height = 25
          Hint = #1042#1074#1077#1089#1090#1080' '#1089#1086#1086#1073#1097#1077#1085#1080#1077' '#1086#1087#1077#1088#1072#1090#1086#1088#1072'|'#1042#1074#1077#1089#1090#1080' '#1089#1086#1086#1073#1097#1077#1085#1080#1077' '#1086#1087#1077#1088#1072#1090#1086#1088#1072
          Caption = #1042#1074#1077#1089#1090#1080
          TabOrder = 4
          OnClick = B_EnterClick
        end
        object ChB_Log: TCheckBox
          Left = 120
          Top = 80
          Width = 153
          Height = 17
          Caption = #1057#1082#1088#1099#1090#1100' '#1086#1082#1085#1086' '#1089#1086#1086#1073#1097#1077#1085#1080#1081
          Checked = True
          State = cbChecked
          TabOrder = 5
          OnClick = ChB_LogClick
        end
      end
    end
    object TSh_Service: TTabSheet
      Caption = #1057#1077#1088#1074#1080#1089#1085#1099#1081' '#1088#1077#1078#1080#1084
      ImageIndex = 3
      object PC_Service: TPageControl
        Left = 0
        Top = 0
        Width = 617
        Height = 370
        ActivePage = TSh_VIP
        TabOrder = 0
        object TSh_VIP: TTabSheet
          Caption = #1042#1048#1055
          object CheckBox13: TCheckBox
            Left = 34
            Top = 24
            Width = 185
            Height = 17
            Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1074#1089#1077' '#1082#1086#1084#1072#1085#1076#1099
            TabOrder = 0
          end
          object GroupBox6: TGroupBox
            Left = 10
            Top = 55
            Width = 561
            Height = 57
            Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1047#1072#1087#1086#1084#1085#1080#1090#1100' '#1076#1083#1103' '#1042#1050'-'#1055#1056#1044'"'
            TabOrder = 1
            object CheckBox6: TCheckBox
              Left = 24
              Top = 24
              Width = 153
              Height = 17
              Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
              TabOrder = 0
            end
            object RadioButton5: TRadioButton
              Left = 205
              Top = 24
              Width = 113
              Height = 17
              Caption = #1042#1082#1083
              TabOrder = 1
            end
            object RadioButton6: TRadioButton
              Left = 325
              Top = 24
              Width = 113
              Height = 17
              Caption = #1042#1099#1082#1083
              Checked = True
              TabOrder = 2
              TabStop = True
            end
          end
          object GroupBox7: TGroupBox
            Left = 10
            Top = 118
            Width = 561
            Height = 57
            Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1042#1082#1083#1102#1095#1080#1090#1100' -9 '#1042' '#1085#1072' '#1042#1050'-'#1055#1056#1044'"'
            TabOrder = 2
            object CheckBox7: TCheckBox
              Left = 24
              Top = 24
              Width = 153
              Height = 17
              Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
              TabOrder = 0
            end
            object RadioButton7: TRadioButton
              Left = 205
              Top = 24
              Width = 113
              Height = 17
              Caption = #1042#1082#1083
              TabOrder = 1
            end
            object RadioButton8: TRadioButton
              Left = 325
              Top = 24
              Width = 113
              Height = 17
              Caption = #1042#1099#1082#1083
              Checked = True
              TabOrder = 2
              TabStop = True
            end
          end
          object GroupBox8: TGroupBox
            Left = 10
            Top = 181
            Width = 561
            Height = 57
            Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1042#1082#1083#1102#1095#1080#1090#1100' +24 '#1042' '#1085#1072' '#1042#1050'-'#1055#1056#1044'"'
            TabOrder = 3
            object CheckBox8: TCheckBox
              Left = 24
              Top = 24
              Width = 153
              Height = 17
              Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
              TabOrder = 0
            end
            object RadioButton13: TRadioButton
              Left = 205
              Top = 24
              Width = 113
              Height = 17
              Caption = #1042#1082#1083
              TabOrder = 1
            end
            object RadioButton14: TRadioButton
              Left = 325
              Top = 24
              Width = 113
              Height = 17
              Caption = #1042#1099#1082#1083
              Checked = True
              TabOrder = 2
              TabStop = True
            end
          end
        end
        object TSh_FRLP_Control: TTabSheet
          Caption = #1060#1056#1051#1055', '#1059#1087#1088'.'
          ImageIndex = 1
          object ScrollBox5: TScrollBox
            Left = 0
            Top = 0
            Width = 615
            Height = 361
            VertScrollBar.Range = 2530
            VertScrollBar.Smooth = True
            VertScrollBar.Tracking = True
            AutoScroll = False
            BorderStyle = bsNone
            TabOrder = 0
            object CheckBox16: TCheckBox
              Left = 34
              Top = 24
              Width = 185
              Height = 17
              Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1074#1089#1077' '#1082#1086#1084#1072#1085#1076#1099
              TabOrder = 0
            end
            object GB_Command3: TGroupBox
              Left = 10
              Top = 55
              Width = 561
              Height = 161
              Caption = 
                #1050#1086#1084#1072#1085#1076#1099' "'#1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1041#1058'", "'#1057#1076#1074#1080#1075' '#1088#1072#1079#1088#1103#1076#1086#1074'", "'#1042#1088#1077#1084#1103' '#1079#1072#1076#1077#1088#1078#1082#1080' '#1041#1058'", "' +
                #1044#1086#1087#1083#1077#1088#1086#1074#1089#1082#1080#1081' '#1089#1076#1074#1080#1075' '#1095#1072#1089#1090#1086#1090#1099' '#1041#1058'"'
              TabOrder = 1
              object StaticText10: TStaticText
                Left = 200
                Top = 49
                Width = 54
                Height = 17
                Caption = #1053#1086#1084#1077#1088' '#1041#1058':'
                TabOrder = 0
              end
              object StaticText11: TStaticText
                Left = 27
                Top = 105
                Width = 79
                Height = 17
                Caption = #1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1041#1058':'
                TabOrder = 1
              end
              object E_Command3: TEdit
                Left = 25
                Top = 128
                Width = 142
                Height = 21
                TabOrder = 2
                Text = '255'
                OnChange = E_Command3Change
                OnExit = E_Command3Exit
                OnKeyPress = E_Command3KeyPress
              end
              object E_Command3_0: TEdit
                Left = 25
                Top = 72
                Width = 144
                Height = 21
                TabOrder = 3
                Text = '1'
                OnChange = E_Command3_0Change
                OnExit = E_Command3_0Exit
                OnKeyPress = E_Command3KeyPress
              end
              object StaticText49: TStaticText
                Left = 25
                Top = 49
                Width = 83
                Height = 17
                Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1041#1058':'
                TabOrder = 4
              end
              object CB_Command3_1: TComboBox
                Left = 199
                Top = 72
                Width = 145
                Height = 21
                ItemIndex = 0
                TabOrder = 5
                Text = '1'
                OnChange = CB_Command3_1Change
                OnKeyPress = CB_SignCKeyPress
                Items.Strings = (
                  '1')
              end
              object ChB_Command3: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1099
                TabOrder = 6
              end
              object StaticText13: TStaticText
                Left = 200
                Top = 105
                Width = 136
                Height = 17
                Caption = #1042#1088#1077#1084#1103' '#1079#1072#1076#1077#1088#1078#1082#1080' ('#1041#1058') ['#1085#1089']:'
                TabOrder = 7
              end
              object E_Command4: TEdit
                Left = 199
                Top = 128
                Width = 145
                Height = 21
                TabOrder = 8
                Text = '0'
                OnChange = E_Command4Change
                OnExit = E_Command4Exit
                OnKeyPress = E_Command3KeyPress
              end
              object StaticText15: TStaticText
                Left = 376
                Top = 105
                Width = 174
                Height = 17
                Caption = #1044#1086#1087#1083#1077#1088'. '#1089#1076#1074#1080#1075' '#1095#1072#1089#1090#1086#1090#1099' ('#1041#1058') ['#1043#1094']:'
                TabOrder = 9
              end
              object E_Command5: TEdit
                Left = 408
                Top = 128
                Width = 113
                Height = 21
                TabOrder = 10
                Text = '0'
                OnChange = E_Command5Change
                OnExit = E_Command5Exit
                OnKeyPress = E_Command5KeyPress
              end
              object CB_SignC: TComboBox
                Left = 376
                Top = 128
                Width = 33
                Height = 21
                ItemIndex = 0
                TabOrder = 11
                Text = '+'
                OnChange = CB_SignCChange
                OnExit = CB_SignCExit
                OnKeyPress = CB_SignCKeyPress
                Items.Strings = (
                  '+'
                  '-')
              end
              object CB_Shift: TComboBox
                Left = 376
                Top = 72
                Width = 145
                Height = 21
                ItemIndex = 0
                TabOrder = 12
                Text = '0'
                OnChange = CB_ShiftChange
                OnExit = CB_ShiftExit
                OnKeyPress = CB_SignCKeyPress
                Items.Strings = (
                  '0'
                  '1'
                  '2'
                  '3'
                  '4'
                  '5'
                  '6')
              end
              object StaticText14: TStaticText
                Left = 376
                Top = 49
                Width = 90
                Height = 17
                Caption = #1057#1076#1074#1080#1075' '#1088#1072#1079#1088#1103#1076#1086#1074':'
                TabOrder = 13
              end
            end
            object GB_Command7: TGroupBox
              Left = 10
              Top = 285
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1086#1089#1083#1072#1073#1083#1077#1085#1080#1103' '#1087#1077#1088#1077#1076#1072#1090#1095#1080#1082#1072' '#1055#1055#1056#1052'-2". ['#1076#1041']'
              TabOrder = 2
              object ChB_Command7: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Command7: TComboBox
                Left = 200
                Top = 24
                Width = 145
                Height = 21
                ItemIndex = 0
                TabOrder = 1
                Text = '0'
                OnChange = CB_Command7Change
                OnExit = CB_Command7Exit
                OnKeyPress = CB_SignCKeyPress
                Items.Strings = (
                  '0'
                  '-0,5'
                  '-1'
                  '-1,5'
                  '-2'
                  '-2,5'
                  '-3'
                  '-3,5'
                  '-4'
                  '-4,5'
                  '-5'
                  '-5,5'
                  '-6'
                  '-6,5'
                  '-7'
                  '-7,5'
                  '-8'
                  '-8,5'
                  '-9'
                  '-9,5'
                  '-10'
                  '-10,5'
                  '-11'
                  '-11,5'
                  '-12'
                  '-12,5'
                  '-13'
                  '-13,5'
                  '-14'
                  '-14,5'
                  '-15'
                  '-15,5'
                  '-16'
                  '-16,5'
                  '-17'
                  '-17,5'
                  '-18'
                  '-18,5'
                  '-19'
                  '-19,5'
                  '-20'
                  '-20,5'
                  '-21'
                  '-21,5'
                  '-22'
                  '-22,5'
                  '-23'
                  '-23,5'
                  '-24'
                  '-24,5'
                  '-25'
                  '-25,5'
                  '-26'
                  '-26,5'
                  '-27'
                  '-27,5'
                  '-28'
                  '-28,5'
                  '-29'
                  '-29,5'
                  '-30'
                  '-30,5'
                  '-31'
                  '-31,5')
              end
            end
            object GB_Command6: TGroupBox
              Left = 10
              Top = 222
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1062#1077#1085#1090#1088#1072#1083#1100#1085#1072#1103' '#1095#1072#1089#1090#1086#1090#1072' '#1088#1072#1073#1086#1095#1077#1081' '#1087#1086#1083#1086#1089#1099'". ['#1052#1043#1094']'
              TabOrder = 3
              object ChB_Command6: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Command6: TComboBox
                Left = 200
                Top = 24
                Width = 145
                Height = 21
                ItemIndex = 0
                TabOrder = 1
                Text = '1300'
                OnChange = CB_Command6Change
                OnExit = CB_Command6Exit
                OnKeyPress = CB_SignCKeyPress
                Items.Strings = (
                  '1300'
                  '5300'
                  '7800'
                  '9600')
              end
            end
            object RG_Mode: TRadioGroup
              Left = 10
              Top = 348
              Width = 113
              Height = 105
              Caption = #1056#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099
              ItemIndex = 0
              Items.Strings = (
                #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
                #1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077)
              TabOrder = 4
            end
          end
        end
        object TSh_FRLP_Testing: TTabSheet
          Caption = #1060#1056#1051#1055', '#1058#1077#1089#1090'.'
          ImageIndex = 2
          object ScrollBox2: TScrollBox
            Left = 0
            Top = 0
            Width = 615
            Height = 361
            VertScrollBar.Range = 2530
            VertScrollBar.Smooth = True
            VertScrollBar.Tracking = True
            AutoScroll = False
            BorderStyle = bsNone
            TabOrder = 0
            object CB_AllCom_: TCheckBox
              Left = 34
              Top = 24
              Width = 185
              Height = 17
              Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1074#1089#1077' '#1082#1086#1084#1072#1085#1076#1099
              TabOrder = 0
              OnClick = CB_AllCom_Click
            end
            object GB_Com3: TGroupBox
              Left = 10
              Top = 59
              Width = 561
              Height = 160
              Caption = 
                #1050#1086#1084#1072#1085#1076#1099' "'#1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1041#1058'", "'#1057#1076#1074#1080#1075' '#1088#1072#1079#1088#1103#1076#1086#1074'", "'#1042#1088#1077#1084#1103' '#1079#1072#1076#1077#1088#1078#1082#1080' '#1041#1058'", "' +
                #1044#1086#1087#1083#1077#1088#1086#1074#1089#1082#1080#1081' '#1089#1076#1074#1080#1075' '#1095#1072#1089#1090#1086#1090#1099' '#1041#1058'"'
              TabOrder = 1
              object ChB_Com3: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1099
                TabOrder = 0
              end
              object StaticText16: TStaticText
                Left = 200
                Top = 49
                Width = 54
                Height = 17
                Caption = #1053#1086#1084#1077#1088' '#1041#1058':'
                TabOrder = 1
              end
              object StaticText17: TStaticText
                Left = 24
                Top = 105
                Width = 79
                Height = 17
                Caption = #1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1041#1058':'
                TabOrder = 2
              end
              object E_Com3_0: TEdit
                Left = 24
                Top = 71
                Width = 144
                Height = 21
                TabOrder = 3
                Text = '1'
                OnChange = E_Com3_0Change
                OnExit = E_Com3_0Exit
                OnKeyPress = E_Command3KeyPress
              end
              object E_Com3: TEdit
                Left = 24
                Top = 128
                Width = 144
                Height = 21
                TabOrder = 4
                Text = '255'
                OnChange = E_Com3Change
                OnExit = E_Com3Exit
                OnKeyPress = E_Command3KeyPress
              end
              object StaticText51: TStaticText
                Left = 24
                Top = 48
                Width = 83
                Height = 17
                Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1041#1058':'
                TabOrder = 5
              end
              object CB_Com3_1: TComboBox
                Left = 200
                Top = 72
                Width = 145
                Height = 21
                ItemIndex = 0
                TabOrder = 6
                Text = '1'
                OnChange = CB_Com3_1Change
                OnKeyPress = CB_SignCKeyPress
                Items.Strings = (
                  '1')
              end
              object StaticText19: TStaticText
                Left = 200
                Top = 105
                Width = 136
                Height = 17
                Caption = #1042#1088#1077#1084#1103' '#1079#1072#1076#1077#1088#1078#1082#1080' ('#1041#1058') ['#1085#1089']:'
                TabOrder = 7
              end
              object E_Com4: TEdit
                Left = 200
                Top = 128
                Width = 145
                Height = 21
                TabOrder = 8
                Text = '0'
                OnChange = E_Com4Change
                OnExit = E_Com4Exit
                OnKeyPress = E_Command3KeyPress
              end
              object StaticText21: TStaticText
                Left = 374
                Top = 105
                Width = 174
                Height = 17
                Caption = #1044#1086#1087#1083#1077#1088'. '#1089#1076#1074#1080#1075' '#1095#1072#1089#1090#1086#1090#1099' ('#1041#1058') ['#1043#1094']:'
                TabOrder = 9
              end
              object E_Com5: TEdit
                Left = 408
                Top = 128
                Width = 113
                Height = 21
                TabOrder = 10
                Text = '0'
                OnChange = E_Com5Change
                OnExit = E_Com5Exit
                OnKeyPress = E_Command5KeyPress
              end
              object CB_SignT: TComboBox
                Left = 376
                Top = 128
                Width = 33
                Height = 21
                ItemIndex = 0
                TabOrder = 11
                Text = '+'
                OnChange = CB_SignTChange
                OnExit = CB_SignTExit
                OnKeyPress = CB_SignCKeyPress
                Items.Strings = (
                  '+'
                  '-')
              end
              object StaticText18: TStaticText
                Left = 374
                Top = 49
                Width = 90
                Height = 17
                Caption = #1057#1076#1074#1080#1075' '#1088#1072#1079#1088#1103#1076#1086#1074':'
                TabOrder = 12
              end
              object CB_Shift_: TComboBox
                Left = 374
                Top = 72
                Width = 147
                Height = 21
                ItemIndex = 0
                TabOrder = 13
                Text = '0'
                OnChange = CB_Shift_Change
                OnExit = CB_Shift_Exit
                OnKeyPress = CB_SignCKeyPress
                Items.Strings = (
                  '0'
                  '1'
                  '2'
                  '3'
                  '4'
                  '5'
                  '6')
              end
            end
            object GB_Com6: TGroupBox
              Left = 10
              Top = 225
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1086#1089#1083#1072#1073#1083#1077#1085#1080#1103' '#1087#1088#1080#1105#1084#1085#1080#1082#1072' '#1055#1055#1056#1052'-2". ['#1076#1041']'
              TabOrder = 2
              object ChB_Com6: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Com6: TComboBox
                Left = 200
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 32
                TabOrder = 1
                Text = '-16'
                OnChange = CB_Com6Change
                Items.Strings = (
                  '0'
                  '-0,5'
                  '-1'
                  '-1,5'
                  '-2'
                  '-2,5'
                  '-3'
                  '-3,5'
                  '-4'
                  '-4,5'
                  '-5'
                  '-5,5'
                  '-6'
                  '-6,5'
                  '-7'
                  '-7,5'
                  '-8'
                  '-8,5'
                  '-9'
                  '-9,5'
                  '-10'
                  '-10,5'
                  '-11'
                  '-11,5'
                  '-12'
                  '-12,5'
                  '-13'
                  '-13,5'
                  '-14'
                  '-14,5'
                  '-15'
                  '-15,5'
                  '-16'
                  '-16,5'
                  '-17'
                  '-17,5'
                  '-18'
                  '-18,5'
                  '-19'
                  '-19,5'
                  '-20'
                  '-20,5'
                  '-21'
                  '-21,5'
                  '-22'
                  '-22,5'
                  '-23'
                  '-23,5'
                  '-24'
                  '-24,5'
                  '-25'
                  '-25,5'
                  '-26'
                  '-26,5'
                  '-27'
                  '-27,5'
                  '-28'
                  '-28,5'
                  '-29'
                  '-29,5'
                  '-30'
                  '-30,5'
                  '-31'
                  '-31,5')
              end
            end
            object GB_Com7: TGroupBox
              Left = 10
              Top = 288
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1086#1089#1083#1072#1073#1083#1077#1085#1080#1103' '#1087#1077#1088#1077#1076#1072#1090#1095#1080#1082#1072' '#1055#1055#1056#1052'-2". ['#1076#1041']'
              TabOrder = 3
              object ChB_Com7: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Com7: TComboBox
                Left = 200
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 0
                TabOrder = 1
                Text = '0'
                OnChange = CB_Com7Change
                Items.Strings = (
                  '0'
                  '-0,5'
                  '-1'
                  '-1,5'
                  '-2'
                  '-2,5'
                  '-3'
                  '-3,5'
                  '-4'
                  '-4,5'
                  '-5'
                  '-5,5'
                  '-6'
                  '-6,5'
                  '-7'
                  '-7,5'
                  '-8'
                  '-8,5'
                  '-9'
                  '-9,5'
                  '-10'
                  '-10,5'
                  '-11'
                  '-11,5'
                  '-12'
                  '-12,5'
                  '-13'
                  '-13,5'
                  '-14'
                  '-14,5'
                  '-15'
                  '-15,5'
                  '-16'
                  '-16,5'
                  '-17'
                  '-17,5'
                  '-18'
                  '-18,5'
                  '-19'
                  '-19,5'
                  '-20'
                  '-20,5'
                  '-21'
                  '-21,5'
                  '-22'
                  '-22,5'
                  '-23'
                  '-23,5'
                  '-24'
                  '-24,5'
                  '-25'
                  '-25,5'
                  '-26'
                  '-26,5'
                  '-27'
                  '-27,5'
                  '-28'
                  '-28,5'
                  '-29'
                  '-29,5'
                  '-30'
                  '-30,5'
                  '-31'
                  '-31,5')
              end
            end
            object GB_Com8: TGroupBox
              Left = 10
              Top = 351
              Width = 561
              Height = 57
              Caption = 
                #1050#1086#1084#1072#1085#1076#1072' "'#1063#1072#1089#1090#1086#1090#1072' '#1089#1088#1077#1079#1072' '#1092#1080#1083#1100#1090#1088#1072' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1072' '#1087#1088#1080#1105#1084#1085#1080#1082#1072' '#1055#1055#1056#1052'-2". ['#1052#1043 +
                #1094']'
              TabOrder = 4
              object ChB_Com8: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Com8: TComboBox
                Left = 200
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 15
                TabOrder = 1
                Text = '3400'
                OnChange = CB_Com8Change
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
            end
            object GB_Com9: TGroupBox
              Left = 10
              Top = 414
              Width = 561
              Height = 57
              Caption = 
                #1050#1086#1084#1072#1085#1076#1072' "'#1063#1072#1089#1090#1086#1090#1072' '#1089#1088#1077#1079#1072' '#1092#1080#1083#1100#1090#1088#1072' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1072' '#1087#1077#1088#1077#1076#1072#1090#1095#1080#1082#1072' '#1055#1055#1056#1052'-2". [' +
                #1052#1075#1094']'
              TabOrder = 5
              object ChB_Com9: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Com9: TComboBox
                Left = 200
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 15
                TabOrder = 1
                Text = '3400'
                OnChange = CB_Com9Change
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
            end
            object GB_Com10: TGroupBox
              Left = 10
              Top = 477
              Width = 561
              Height = 82
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1050#1086#1076' '#1091#1087#1088#1072#1074#1083#1077#1085#1080#1103' '#1074#1093#1086#1076#1085#1099#1084' '#1087#1088#1077#1089#1077#1083#1077#1082#1090#1086#1088#1086#1084'"'
              TabOrder = 6
              object Label8: TLabel
                Left = 440
                Top = 16
                Width = 108
                Height = 52
                Caption = 
                  '1 - 900...1700 '#1052#1075#1094';'#13#10'2 - 4900...5700 '#1052#1075#1094';'#13#10'3 - 7100...8500 '#1052#1075#1094';'#13 +
                  #10'4 - 9200...10000 '#1052#1075#1094'.'
              end
              object ChB_Com10: TCheckBox
                Left = 24
                Top = 48
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Com10: TComboBox
                Left = 200
                Top = 48
                Width = 233
                Height = 21
                ItemIndex = 0
                TabOrder = 1
                Text = '1'
                OnChange = CB_Com10Change
                Items.Strings = (
                  '1'
                  '2'
                  '3'
                  '4')
              end
              object StaticText22: TStaticText
                Left = 200
                Top = 24
                Width = 156
                Height = 17
                Caption = #1044#1080#1072#1087#1072#1079#1086#1085' '#1092#1080#1083#1100#1090#1088#1072' '#1057#1042#1063' ['#1043#1043#1094']:'
                TabOrder = 2
              end
            end
            object GB_Com11: TGroupBox
              Left = 10
              Top = 565
              Width = 561
              Height = 82
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1050#1086#1076' '#1091#1087#1088#1072#1074#1083#1077#1085#1080#1103' '#1074#1099#1093#1086#1076#1085#1099#1084' '#1087#1088#1077#1089#1077#1083#1077#1082#1090#1086#1088#1086#1084'"'
              TabOrder = 7
              object Label2: TLabel
                Left = 440
                Top = 16
                Width = 108
                Height = 52
                Caption = 
                  '1 - 900...1700 '#1052#1075#1094';'#13#10'2 - 4900...5700 '#1052#1075#1094';'#13#10'3 - 7100...8500 '#1052#1075#1094';'#13 +
                  #10'4 - 9200...10000 '#1052#1075#1094'.'
              end
              object ChB_Com11: TCheckBox
                Left = 24
                Top = 48
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Com11: TComboBox
                Left = 200
                Top = 48
                Width = 233
                Height = 21
                ItemIndex = 0
                TabOrder = 1
                Text = '1'
                OnChange = CB_Com11Change
                Items.Strings = (
                  '1'
                  '2'
                  '3'
                  '4')
              end
              object StaticText23: TStaticText
                Left = 200
                Top = 24
                Width = 156
                Height = 17
                Caption = #1044#1080#1072#1087#1072#1079#1086#1085' '#1092#1080#1083#1100#1090#1088#1072' '#1057#1042#1063' ['#1043#1043#1094']:'
                TabOrder = 2
              end
            end
            object GB_Com13: TGroupBox
              Left = 10
              Top = 653
              Width = 561
              Height = 126
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1056#1072#1073#1086#1095#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1099' '#1089#1080#1085#1090#1077#1079#1072#1090#1086#1088#1072' '#1087#1083#1072#1090#1099' '#1055#1055#1056#1052'-2. '#1055#1072#1082#1077#1090' 1...8"'
              TabOrder = 8
              object Label1: TLabel
                Left = 200
                Top = 25
                Width = 118
                Height = 13
                Caption = #1052#1086#1097#1085#1086#1089#1090#1100' '#1085#1072' '#1074#1099#1093#1086#1076#1077' 1'
              end
              object Label3: TLabel
                Left = 352
                Top = 25
                Width = 118
                Height = 13
                Caption = #1052#1086#1097#1085#1086#1089#1090#1100' '#1085#1072' '#1074#1099#1093#1086#1076#1077' 2'
              end
              object Label4: TLabel
                Left = 200
                Top = 71
                Width = 95
                Height = 13
                Caption = #1042#1099#1093#1086#1076#1085#1072#1103' '#1095#1072#1089#1090#1086#1090#1072
              end
              object Label5: TLabel
                Left = 287
                Top = 94
                Width = 20
                Height = 13
                Caption = #1052#1043#1094
              end
              object ChB_Com13: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1099
                TabOrder = 0
              end
              object CB_Output: TComboBox
                Left = 201
                Top = 44
                Width = 65
                Height = 21
                Hint = 'Default=+5'
                ItemIndex = 1
                ParentShowHint = False
                ShowHint = True
                TabOrder = 1
                Text = '-4'
                OnChange = CB_OutputChange
                Items.Strings = (
                  'Off'
                  '-4'
                  '-1'
                  '+2'
                  '+5')
              end
              object CB_AuxOut: TComboBox
                Left = 352
                Top = 44
                Width = 65
                Height = 21
                Hint = 'Default=Off'
                ItemIndex = 1
                ParentShowHint = False
                ShowHint = True
                TabOrder = 2
                Text = '-4'
                OnChange = CB_AuxOutChange
                Items.Strings = (
                  'Off'
                  '-4'
                  '-1'
                  '+2'
                  '+5')
              end
              object E_OutFreq: TEdit
                Left = 200
                Top = 91
                Width = 81
                Height = 21
                TabOrder = 3
                Text = '1000'
                OnChange = E_OutFreqChange
              end
            end
            object GroupBox11: TGroupBox
              Left = 10
              Top = 785
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1055#1086#1076#1072#1074#1083#1077#1085#1080#1077' I-'#1075#1086' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1085#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072'".'
              TabOrder = 9
              object ChB_Com21: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Com21: TComboBox
                Left = 200
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 256
                TabOrder = 1
                Text = '0'
                OnChange = CB_Com21Change
                Items.Strings = (
                  '256'
                  '255'
                  '254'
                  '253'
                  '252'
                  '251'
                  '250'
                  '249'
                  '248'
                  '247'
                  '246'
                  '245'
                  '244'
                  '243'
                  '242'
                  '241'
                  '240'
                  '239'
                  '238'
                  '237'
                  '236'
                  '235'
                  '234'
                  '233'
                  '232'
                  '231'
                  '230'
                  '229'
                  '228'
                  '227'
                  '226'
                  '225'
                  '224'
                  '223'
                  '222'
                  '221'
                  '220'
                  '219'
                  '218'
                  '217'
                  '216'
                  '215'
                  '214'
                  '213'
                  '212'
                  '211'
                  '210'
                  '209'
                  '208'
                  '207'
                  '206'
                  '205'
                  '204'
                  '203'
                  '202'
                  '201'
                  '200'
                  '199'
                  '198'
                  '197'
                  '196'
                  '195'
                  '194'
                  '193'
                  '192'
                  '191'
                  '190'
                  '189'
                  '188'
                  '187'
                  '186'
                  '185'
                  '184'
                  '183'
                  '182'
                  '181'
                  '180'
                  '179'
                  '178'
                  '177'
                  '176'
                  '175'
                  '174'
                  '173'
                  '172'
                  '171'
                  '170'
                  '169'
                  '168'
                  '167'
                  '166'
                  '165'
                  '164'
                  '163'
                  '162'
                  '161'
                  '160'
                  '159'
                  '158'
                  '157'
                  '156'
                  '155'
                  '154'
                  '153'
                  '152'
                  '151'
                  '150'
                  '149'
                  '148'
                  '147'
                  '146'
                  '145'
                  '144'
                  '143'
                  '142'
                  '141'
                  '140'
                  '139'
                  '138'
                  '137'
                  '136'
                  '135'
                  '134'
                  '133'
                  '132'
                  '131'
                  '130'
                  '129'
                  '128'
                  '127'
                  '126'
                  '125'
                  '124'
                  '123'
                  '122'
                  '121'
                  '120'
                  '119'
                  '118'
                  '117'
                  '116'
                  '115'
                  '114'
                  '113'
                  '112'
                  '111'
                  '110'
                  '109'
                  '108'
                  '107'
                  '106'
                  '105'
                  '104'
                  '103'
                  '102'
                  '101'
                  '100'
                  '99'
                  '98'
                  '97'
                  '96'
                  '95'
                  '94'
                  '93'
                  '92'
                  '91'
                  '90'
                  '89'
                  '88'
                  '87'
                  '86'
                  '85'
                  '84'
                  '83'
                  '82'
                  '81'
                  '80'
                  '79'
                  '78'
                  '77'
                  '76'
                  '75'
                  '74'
                  '73'
                  '72'
                  '71'
                  '70'
                  '69'
                  '68'
                  '67'
                  '66'
                  '65'
                  '64'
                  '63'
                  '62'
                  '61'
                  '60'
                  '59'
                  '58'
                  '57'
                  '56'
                  '55'
                  '54'
                  '53'
                  '52'
                  '51'
                  '50'
                  '49'
                  '48'
                  '47'
                  '46'
                  '45'
                  '44'
                  '43'
                  '42'
                  '41'
                  '40'
                  '39'
                  '38'
                  '37'
                  '36'
                  '35'
                  '34'
                  '33'
                  '32'
                  '31'
                  '30'
                  '29'
                  '28'
                  '27'
                  '26'
                  '25'
                  '24'
                  '23'
                  '22'
                  '21'
                  '20'
                  '19'
                  '18'
                  '17'
                  '16'
                  '15'
                  '14'
                  '13'
                  '12'
                  '11'
                  '10'
                  '9'
                  '8'
                  '7'
                  '6'
                  '5'
                  '4'
                  '3'
                  '2'
                  '1'
                  '0'
                  '-1'
                  '-2'
                  '-3'
                  '-4'
                  '-5'
                  '-6'
                  '-7'
                  '-8'
                  '-9'
                  '-10'
                  '-11'
                  '-12'
                  '-13'
                  '-14'
                  '-15'
                  '-16'
                  '-17'
                  '-18'
                  '-19'
                  '-20'
                  '-21'
                  '-22'
                  '-23'
                  '-24'
                  '-25'
                  '-26'
                  '-27'
                  '-28'
                  '-29'
                  '-30'
                  '-31'
                  '-32'
                  '-33'
                  '-34'
                  '-35'
                  '-36'
                  '-37'
                  '-38'
                  '-39'
                  '-40'
                  '-41'
                  '-42'
                  '-43'
                  '-44'
                  '-45'
                  '-46'
                  '-47'
                  '-48'
                  '-49'
                  '-50'
                  '-51'
                  '-52'
                  '-53'
                  '-54'
                  '-55'
                  '-56'
                  '-57'
                  '-58'
                  '-59'
                  '-60'
                  '-61'
                  '-62'
                  '-63'
                  '-64'
                  '-65'
                  '-66'
                  '-67'
                  '-68'
                  '-69'
                  '-70'
                  '-71'
                  '-72'
                  '-73'
                  '-74'
                  '-75'
                  '-76'
                  '-77'
                  '-78'
                  '-79'
                  '-80'
                  '-81'
                  '-82'
                  '-83'
                  '-84'
                  '-85'
                  '-86'
                  '-87'
                  '-88'
                  '-89'
                  '-90'
                  '-91'
                  '-92'
                  '-93'
                  '-94'
                  '-95'
                  '-96'
                  '-97'
                  '-98'
                  '-99'
                  '-100'
                  '-101'
                  '-102'
                  '-103'
                  '-104'
                  '-105'
                  '-106'
                  '-107'
                  '-108'
                  '-109'
                  '-110'
                  '-111'
                  '-112'
                  '-113'
                  '-114'
                  '-115'
                  '-116'
                  '-117'
                  '-118'
                  '-119'
                  '-120'
                  '-121'
                  '-122'
                  '-123'
                  '-124'
                  '-125'
                  '-126'
                  '-127'
                  '-128'
                  '-129'
                  '-130'
                  '-131'
                  '-132'
                  '-133'
                  '-134'
                  '-135'
                  '-136'
                  '-137'
                  '-138'
                  '-139'
                  '-140'
                  '-141'
                  '-142'
                  '-143'
                  '-144'
                  '-145'
                  '-146'
                  '-147'
                  '-148'
                  '-149'
                  '-150'
                  '-151'
                  '-152'
                  '-153'
                  '-154'
                  '-155'
                  '-156'
                  '-157'
                  '-158'
                  '-159'
                  '-160'
                  '-161'
                  '-162'
                  '-163'
                  '-164'
                  '-165'
                  '-166'
                  '-167'
                  '-168'
                  '-169'
                  '-170'
                  '-171'
                  '-172'
                  '-173'
                  '-174'
                  '-175'
                  '-176'
                  '-177'
                  '-178'
                  '-179'
                  '-180'
                  '-181'
                  '-182'
                  '-183'
                  '-184'
                  '-185'
                  '-186'
                  '-187'
                  '-188'
                  '-189'
                  '-190'
                  '-191'
                  '-192'
                  '-193'
                  '-194'
                  '-195'
                  '-196'
                  '-197'
                  '-198'
                  '-199'
                  '-200'
                  '-201'
                  '-202'
                  '-203'
                  '-204'
                  '-205'
                  '-206'
                  '-207'
                  '-208'
                  '-209'
                  '-210'
                  '-211'
                  '-212'
                  '-213'
                  '-214'
                  '-215'
                  '-216'
                  '-217'
                  '-218'
                  '-219'
                  '-220'
                  '-221'
                  '-222'
                  '-223'
                  '-224'
                  '-225'
                  '-226'
                  '-227'
                  '-228'
                  '-229'
                  '-230'
                  '-231'
                  '-232'
                  '-233'
                  '-234'
                  '-235'
                  '-236'
                  '-237'
                  '-238'
                  '-239'
                  '-240'
                  '-241'
                  '-242'
                  '-243'
                  '-244'
                  '-245'
                  '-246'
                  '-247'
                  '-248'
                  '-249'
                  '-250'
                  '-251'
                  '-252'
                  '-253'
                  '-254'
                  '-255'
                  '-256')
              end
            end
            object GroupBox17: TGroupBox
              Left = 10
              Top = 848
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1055#1086#1076#1072#1074#1083#1077#1085#1080#1077' Q-'#1075#1086' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1085#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072'".'
              TabOrder = 10
              object ChB_Com22: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Com22: TComboBox
                Left = 200
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 256
                TabOrder = 1
                Text = '0'
                OnChange = CB_Com22Change
                Items.Strings = (
                  '256'
                  '255'
                  '254'
                  '253'
                  '252'
                  '251'
                  '250'
                  '249'
                  '248'
                  '247'
                  '246'
                  '245'
                  '244'
                  '243'
                  '242'
                  '241'
                  '240'
                  '239'
                  '238'
                  '237'
                  '236'
                  '235'
                  '234'
                  '233'
                  '232'
                  '231'
                  '230'
                  '229'
                  '228'
                  '227'
                  '226'
                  '225'
                  '224'
                  '223'
                  '222'
                  '221'
                  '220'
                  '219'
                  '218'
                  '217'
                  '216'
                  '215'
                  '214'
                  '213'
                  '212'
                  '211'
                  '210'
                  '209'
                  '208'
                  '207'
                  '206'
                  '205'
                  '204'
                  '203'
                  '202'
                  '201'
                  '200'
                  '199'
                  '198'
                  '197'
                  '196'
                  '195'
                  '194'
                  '193'
                  '192'
                  '191'
                  '190'
                  '189'
                  '188'
                  '187'
                  '186'
                  '185'
                  '184'
                  '183'
                  '182'
                  '181'
                  '180'
                  '179'
                  '178'
                  '177'
                  '176'
                  '175'
                  '174'
                  '173'
                  '172'
                  '171'
                  '170'
                  '169'
                  '168'
                  '167'
                  '166'
                  '165'
                  '164'
                  '163'
                  '162'
                  '161'
                  '160'
                  '159'
                  '158'
                  '157'
                  '156'
                  '155'
                  '154'
                  '153'
                  '152'
                  '151'
                  '150'
                  '149'
                  '148'
                  '147'
                  '146'
                  '145'
                  '144'
                  '143'
                  '142'
                  '141'
                  '140'
                  '139'
                  '138'
                  '137'
                  '136'
                  '135'
                  '134'
                  '133'
                  '132'
                  '131'
                  '130'
                  '129'
                  '128'
                  '127'
                  '126'
                  '125'
                  '124'
                  '123'
                  '122'
                  '121'
                  '120'
                  '119'
                  '118'
                  '117'
                  '116'
                  '115'
                  '114'
                  '113'
                  '112'
                  '111'
                  '110'
                  '109'
                  '108'
                  '107'
                  '106'
                  '105'
                  '104'
                  '103'
                  '102'
                  '101'
                  '100'
                  '99'
                  '98'
                  '97'
                  '96'
                  '95'
                  '94'
                  '93'
                  '92'
                  '91'
                  '90'
                  '89'
                  '88'
                  '87'
                  '86'
                  '85'
                  '84'
                  '83'
                  '82'
                  '81'
                  '80'
                  '79'
                  '78'
                  '77'
                  '76'
                  '75'
                  '74'
                  '73'
                  '72'
                  '71'
                  '70'
                  '69'
                  '68'
                  '67'
                  '66'
                  '65'
                  '64'
                  '63'
                  '62'
                  '61'
                  '60'
                  '59'
                  '58'
                  '57'
                  '56'
                  '55'
                  '54'
                  '53'
                  '52'
                  '51'
                  '50'
                  '49'
                  '48'
                  '47'
                  '46'
                  '45'
                  '44'
                  '43'
                  '42'
                  '41'
                  '40'
                  '39'
                  '38'
                  '37'
                  '36'
                  '35'
                  '34'
                  '33'
                  '32'
                  '31'
                  '30'
                  '29'
                  '28'
                  '27'
                  '26'
                  '25'
                  '24'
                  '23'
                  '22'
                  '21'
                  '20'
                  '19'
                  '18'
                  '17'
                  '16'
                  '15'
                  '14'
                  '13'
                  '12'
                  '11'
                  '10'
                  '9'
                  '8'
                  '7'
                  '6'
                  '5'
                  '4'
                  '3'
                  '2'
                  '1'
                  '0'
                  '-1'
                  '-2'
                  '-3'
                  '-4'
                  '-5'
                  '-6'
                  '-7'
                  '-8'
                  '-9'
                  '-10'
                  '-11'
                  '-12'
                  '-13'
                  '-14'
                  '-15'
                  '-16'
                  '-17'
                  '-18'
                  '-19'
                  '-20'
                  '-21'
                  '-22'
                  '-23'
                  '-24'
                  '-25'
                  '-26'
                  '-27'
                  '-28'
                  '-29'
                  '-30'
                  '-31'
                  '-32'
                  '-33'
                  '-34'
                  '-35'
                  '-36'
                  '-37'
                  '-38'
                  '-39'
                  '-40'
                  '-41'
                  '-42'
                  '-43'
                  '-44'
                  '-45'
                  '-46'
                  '-47'
                  '-48'
                  '-49'
                  '-50'
                  '-51'
                  '-52'
                  '-53'
                  '-54'
                  '-55'
                  '-56'
                  '-57'
                  '-58'
                  '-59'
                  '-60'
                  '-61'
                  '-62'
                  '-63'
                  '-64'
                  '-65'
                  '-66'
                  '-67'
                  '-68'
                  '-69'
                  '-70'
                  '-71'
                  '-72'
                  '-73'
                  '-74'
                  '-75'
                  '-76'
                  '-77'
                  '-78'
                  '-79'
                  '-80'
                  '-81'
                  '-82'
                  '-83'
                  '-84'
                  '-85'
                  '-86'
                  '-87'
                  '-88'
                  '-89'
                  '-90'
                  '-91'
                  '-92'
                  '-93'
                  '-94'
                  '-95'
                  '-96'
                  '-97'
                  '-98'
                  '-99'
                  '-100'
                  '-101'
                  '-102'
                  '-103'
                  '-104'
                  '-105'
                  '-106'
                  '-107'
                  '-108'
                  '-109'
                  '-110'
                  '-111'
                  '-112'
                  '-113'
                  '-114'
                  '-115'
                  '-116'
                  '-117'
                  '-118'
                  '-119'
                  '-120'
                  '-121'
                  '-122'
                  '-123'
                  '-124'
                  '-125'
                  '-126'
                  '-127'
                  '-128'
                  '-129'
                  '-130'
                  '-131'
                  '-132'
                  '-133'
                  '-134'
                  '-135'
                  '-136'
                  '-137'
                  '-138'
                  '-139'
                  '-140'
                  '-141'
                  '-142'
                  '-143'
                  '-144'
                  '-145'
                  '-146'
                  '-147'
                  '-148'
                  '-149'
                  '-150'
                  '-151'
                  '-152'
                  '-153'
                  '-154'
                  '-155'
                  '-156'
                  '-157'
                  '-158'
                  '-159'
                  '-160'
                  '-161'
                  '-162'
                  '-163'
                  '-164'
                  '-165'
                  '-166'
                  '-167'
                  '-168'
                  '-169'
                  '-170'
                  '-171'
                  '-172'
                  '-173'
                  '-174'
                  '-175'
                  '-176'
                  '-177'
                  '-178'
                  '-179'
                  '-180'
                  '-181'
                  '-182'
                  '-183'
                  '-184'
                  '-185'
                  '-186'
                  '-187'
                  '-188'
                  '-189'
                  '-190'
                  '-191'
                  '-192'
                  '-193'
                  '-194'
                  '-195'
                  '-196'
                  '-197'
                  '-198'
                  '-199'
                  '-200'
                  '-201'
                  '-202'
                  '-203'
                  '-204'
                  '-205'
                  '-206'
                  '-207'
                  '-208'
                  '-209'
                  '-210'
                  '-211'
                  '-212'
                  '-213'
                  '-214'
                  '-215'
                  '-216'
                  '-217'
                  '-218'
                  '-219'
                  '-220'
                  '-221'
                  '-222'
                  '-223'
                  '-224'
                  '-225'
                  '-226'
                  '-227'
                  '-228'
                  '-229'
                  '-230'
                  '-231'
                  '-232'
                  '-233'
                  '-234'
                  '-235'
                  '-236'
                  '-237'
                  '-238'
                  '-239'
                  '-240'
                  '-241'
                  '-242'
                  '-243'
                  '-244'
                  '-245'
                  '-246'
                  '-247'
                  '-248'
                  '-249'
                  '-250'
                  '-251'
                  '-252'
                  '-253'
                  '-254'
                  '-255'
                  '-256')
              end
            end
          end
        end
        object TSh_PRM_PRD: TTabSheet
          Caption = #1055#1056#1052' '#1080' '#1055#1056#1044
          ImageIndex = 3
          object ScrollBox1: TScrollBox
            Left = 0
            Top = 0
            Width = 615
            Height = 361
            VertScrollBar.Range = 2530
            VertScrollBar.Smooth = True
            VertScrollBar.Tracking = True
            AutoScroll = False
            BorderStyle = bsNone
            TabOrder = 0
            object CheckBox19: TCheckBox
              Left = 34
              Top = 24
              Width = 185
              Height = 17
              Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1074#1089#1077' '#1082#1086#1084#1072#1085#1076#1099
              TabOrder = 0
            end
            object GroupBox4: TGroupBox
              Left = 10
              Top = 59
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1042#1099#1073#1086#1088' '#1095#1072#1089#1090#1086#1090#1085#1086#1075#1086' '#1076#1080#1072#1087#1072#1079#1086#1085#1072' 2-'#1081' '#1089#1090#1091#1087#1077#1085#1080'"'
              TabOrder = 1
              object CheckBox4: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object RadioButton1: TRadioButton
                Left = 205
                Top = 24
                Width = 151
                Height = 17
                Caption = #1044'1'
                TabOrder = 1
              end
              object RadioButton2: TRadioButton
                Left = 327
                Top = 24
                Width = 145
                Height = 17
                Caption = #1044'2'
                Checked = True
                TabOrder = 2
                TabStop = True
              end
            end
            object GroupBox12: TGroupBox
              Left = 10
              Top = 122
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1047#1072#1090#1091#1093#1072#1085#1080#1077' '#1072#1090#1090#1077#1085#1102#1072#1090#1086#1088#1072' '#1087#1088#1080#1077#1084#1085#1080#1082#1072'". ['#1076#1041']'
              TabOrder = 2
              object CheckBox20: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object ComboBox4: TComboBox
                Left = 205
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 0
                TabOrder = 1
                Text = '0'
                Items.Strings = (
                  '0'
                  '-1'
                  '-2'
                  '-3'
                  '-4'
                  '-5'
                  '-6'
                  '-7'
                  '-8'
                  '-9'
                  '-10'
                  '-11'
                  '-12'
                  '-13'
                  '-14'
                  '-15'
                  '-16'
                  '-17'
                  '-18'
                  '-19'
                  '-20'
                  '-21'
                  '-22'
                  '-23'
                  '-24'
                  '-25'
                  '-26'
                  '-27'
                  '-28'
                  '-29'
                  '-30')
              end
            end
            object GroupBox15: TGroupBox
              Left = 10
              Top = 185
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1047#1072#1090#1091#1093#1072#1085#1080#1077' '#1072#1090#1090#1077#1085#1102#1072#1090#1086#1088#1072' '#1087#1077#1088#1077#1076#1072#1090#1095#1080#1082#1072'". ['#1076#1041']'
              TabOrder = 3
              object CheckBox21: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object ComboBox7: TComboBox
                Left = 205
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 0
                TabOrder = 1
                Text = '0'
                Items.Strings = (
                  '0'
                  '-1'
                  '-2'
                  '-3'
                  '-4'
                  '-5'
                  '-6'
                  '-7'
                  '-8'
                  '-9'
                  '-10'
                  '-11'
                  '-12'
                  '-13'
                  '-14'
                  '-15'
                  '-16'
                  '-17'
                  '-18'
                  '-19'
                  '-20'
                  '-21'
                  '-22'
                  '-23'
                  '-24'
                  '-25'
                  '-26'
                  '-27'
                  '-28'
                  '-29'
                  '-30')
              end
            end
            object GroupBox16: TGroupBox
              Left = 10
              Top = 248
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1042#1099#1073#1086#1088' '#1095#1072#1089#1090#1086#1090#1085#1086#1075#1086' '#1076#1080#1072#1087#1072#1079#1086#1085#1072'"'
              TabOrder = 4
              object CheckBox22: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object ComboBox8: TComboBox
                Left = 205
                Top = 24
                Width = 233
                Height = 21
                TabOrder = 1
                Text = #1044'1'
                Items.Strings = (
                  #1044'1'
                  #1044'2'
                  #1044'3.1'
                  #1044'3.2'
                  #1044'4')
              end
            end
          end
        end
        object TSh_UU: TTabSheet
          Caption = #1059#1059
          ImageIndex = 5
        end
        object TSh_BS: TTabSheet
          Caption = #1041#1057
          ImageIndex = 6
          object ScrollBox3: TScrollBox
            Left = 0
            Top = 0
            Width = 615
            Height = 361
            VertScrollBar.Range = 2530
            VertScrollBar.Smooth = True
            VertScrollBar.Tracking = True
            AutoScroll = False
            BorderStyle = bsNone
            TabOrder = 0
            object CheckBox18: TCheckBox
              Left = 34
              Top = 24
              Width = 185
              Height = 17
              Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1074#1089#1077' '#1082#1086#1084#1072#1085#1076#1099
              TabOrder = 0
            end
            object GroupBox9: TGroupBox
              Left = 10
              Top = 59
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1079#1072#1090#1091#1093#1072#1085#1080#1103' '#1072#1090#1090#1077#1085#1102#1072#1090#1086#1088#1072' '#1086#1089#1085#1086#1074#1085#1086#1075#1086' '#1082#1072#1085#1072#1083#1072'". ['#1076#1041']'
              TabOrder = 1
              object CheckBox10: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Att_BS: TComboBox
                Left = 205
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 63
                TabOrder = 1
                Text = '-31.5'
                Items.Strings = (
                  '0'
                  '-0.5'
                  '-1'
                  '-1.5'
                  '-2'
                  '-2.5'
                  '-3'
                  '-3.5'
                  '-4'
                  '-4.5'
                  '-5'
                  '-5.5'
                  '-6'
                  '-6.5'
                  '-7'
                  '-7.5'
                  '-8'
                  '-8.5'
                  '-9'
                  '-9.5'
                  '-10'
                  '-10.5'
                  '-11'
                  '-11.5'
                  '-12'
                  '-12.5'
                  '-13'
                  '-13.5'
                  '-14'
                  '-14.5'
                  '-15'
                  '-15.5'
                  '-16'
                  '-16.5'
                  '-17'
                  '-17.5'
                  '-18'
                  '-18.5'
                  '-19'
                  '-19.5'
                  '-20'
                  '-20.5'
                  '-21'
                  '-21.5'
                  '-22'
                  '-22.5'
                  '-23'
                  '-23.5'
                  '-24'
                  '-24.5'
                  '-25'
                  '-25.5'
                  '-26'
                  '-26.5'
                  '-27'
                  '-27.5'
                  '-28'
                  '-28.5'
                  '-29'
                  '-29.5'
                  '-30'
                  '-30.5'
                  '-31'
                  '-31.5')
              end
            end
            object GroupBox10: TGroupBox
              Left = 10
              Top = 122
              Width = 561
              Height = 57
              Caption = 
                #1050#1086#1084#1072#1085#1076#1072' "'#1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1079#1072#1090#1091#1093#1072#1085#1080#1103' '#1072#1090#1090#1077#1085#1102#1072#1090#1086#1088#1072' '#1088#1077#1079#1077#1088#1074#1085#1086#1075#1086' '#1082#1072#1085#1072#1083#1072'". ['#1076#1041 +
                ']'
              TabOrder = 2
              object CheckBox11: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object CB_Att_BSR: TComboBox
                Left = 205
                Top = 24
                Width = 233
                Height = 21
                ItemIndex = 63
                TabOrder = 1
                Text = '-31.5'
                Items.Strings = (
                  '0'
                  '-0.5'
                  '-1'
                  '-1.5'
                  '-2'
                  '-2.5'
                  '-3'
                  '-3.5'
                  '-4'
                  '-4.5'
                  '-5'
                  '-5.5'
                  '-6'
                  '-6.5'
                  '-7'
                  '-7.5'
                  '-8'
                  '-8.5'
                  '-9'
                  '-9.5'
                  '-10'
                  '-10.5'
                  '-11'
                  '-11.5'
                  '-12'
                  '-12.5'
                  '-13'
                  '-13.5'
                  '-14'
                  '-14.5'
                  '-15'
                  '-15.5'
                  '-16'
                  '-16.5'
                  '-17'
                  '-17.5'
                  '-18'
                  '-18.5'
                  '-19'
                  '-19.5'
                  '-20'
                  '-20.5'
                  '-21'
                  '-21.5'
                  '-22'
                  '-22.5'
                  '-23'
                  '-23.5'
                  '-24'
                  '-24.5'
                  '-25'
                  '-25.5'
                  '-26'
                  '-26.5'
                  '-27'
                  '-27.5'
                  '-28'
                  '-28.5'
                  '-29'
                  '-29.5'
                  '-30'
                  '-30.5'
                  '-31'
                  '-31.5')
              end
            end
            object GroupBox13: TGroupBox
              Left = 10
              Top = 185
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1042#1099#1073#1086#1088' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1072' '#1086#1089#1085#1086#1074#1085#1086#1075#1086' '#1082#1072#1085#1072#1083#1072' '#1076#1083#1103' '#1082#1086#1085#1090#1088#1086#1083#1103'"'
              TabOrder = 3
              object CheckBox14: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object RB_ReceiverHet: TRadioButton
                Left = 205
                Top = 24
                Width = 151
                Height = 17
                Caption = #1043#1077#1090#1077#1088#1086#1076#1080#1085' '#1087#1088#1080#1077#1084#1085#1080#1082#1072
                Checked = True
                TabOrder = 1
                TabStop = True
              end
              object RB_TransmitHet: TRadioButton
                Left = 384
                Top = 24
                Width = 145
                Height = 17
                Caption = #1043#1077#1090#1077#1088#1086#1076#1080#1085' '#1087#1077#1088#1077#1076#1072#1090#1095#1080#1082#1072
                TabOrder = 2
              end
            end
            object GroupBox14: TGroupBox
              Left = 10
              Top = 248
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1042#1099#1073#1086#1088' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1072' '#1088#1077#1079#1077#1088#1074#1085#1086#1075#1086' '#1082#1072#1085#1072#1083#1072' '#1076#1083#1103' '#1082#1086#1085#1090#1088#1086#1083#1103'"'
              TabOrder = 4
              object CheckBox15: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object RB_ReceiverHetR: TRadioButton
                Left = 205
                Top = 24
                Width = 151
                Height = 17
                Caption = #1043#1077#1090#1077#1088#1086#1076#1080#1085' '#1087#1088#1080#1077#1084#1085#1080#1082#1072
                Checked = True
                TabOrder = 1
                TabStop = True
              end
              object RB_TransmitHetR: TRadioButton
                Left = 384
                Top = 24
                Width = 145
                Height = 17
                Caption = #1043#1077#1090#1077#1088#1086#1076#1080#1085' '#1087#1077#1088#1077#1076#1072#1090#1095#1080#1082#1072
                TabOrder = 2
              end
            end
            object GroupBox36: TGroupBox
              Left = 10
              Top = 311
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1063#1072#1089#1090#1086#1090#1072' '#1089#1080#1085#1090#1077#1079#1072#1090#1086#1088#1072' '#1086#1089#1085#1086#1074#1085#1086#1075#1086' '#1082#1072#1085#1072#1083#1072'". ['#1043#1043#1094']'
              TabOrder = 5
              object CheckBox36: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object Edit32: TEdit
                Left = 205
                Top = 24
                Width = 233
                Height = 21
                TabOrder = 1
                Text = '5600'
              end
            end
            object GroupBox37: TGroupBox
              Left = 10
              Top = 374
              Width = 561
              Height = 57
              Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1063#1072#1089#1090#1086#1090#1072' '#1089#1080#1085#1090#1077#1079#1072#1090#1086#1088#1072' '#1088#1077#1079#1077#1088#1074#1085#1086#1075#1086' '#1082#1072#1085#1072#1083#1072'". ['#1043#1043#1094']'
              TabOrder = 6
              object CheckBox37: TCheckBox
                Left = 24
                Top = 24
                Width = 153
                Height = 17
                Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
                TabOrder = 0
              end
              object Edit33: TEdit
                Left = 205
                Top = 24
                Width = 233
                Height = 21
                TabOrder = 1
                Text = '5600'
              end
            end
          end
        end
        object TSh_VK_PRM: TTabSheet
          Caption = #1042#1050'-'#1055#1056#1052
          ImageIndex = 7
        end
        object TSh_VK_PRD: TTabSheet
          Caption = #1042#1050'-'#1055#1056#1044
          ImageIndex = 8
        end
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'U '#1080' I'
      ImageIndex = 3
      object ScrollBox4: TScrollBox
        Left = 6
        Top = 3
        Width = 615
        Height = 361
        VertScrollBar.Range = 2530
        VertScrollBar.Smooth = True
        VertScrollBar.Tracking = True
        AutoScroll = False
        BorderStyle = bsNone
        TabOrder = 0
        object P_5: TPanel
          Left = 3
          Top = 153
          Width = 89
          Height = 30
          Caption = 'I+27B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 0
        end
        object P_Ip27B: TPanel
          Left = 92
          Top = 153
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 1
        end
        object P_Um5B: TPanel
          Left = 92
          Top = 123
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 2
        end
        object P_4: TPanel
          Left = 3
          Top = 123
          Width = 89
          Height = 30
          Caption = 'U-5B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 3
        end
        object P_3: TPanel
          Left = 3
          Top = 93
          Width = 89
          Height = 30
          Caption = 'P'#1087#1088#1084
          Color = clSilver
          ParentBackground = False
          TabOrder = 4
        end
        object P_Pprm: TPanel
          Left = 92
          Top = 93
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 5
        end
        object P_Up12B: TPanel
          Left = 92
          Top = 63
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 6
        end
        object P_2: TPanel
          Left = 3
          Top = 63
          Width = 89
          Height = 30
          Caption = 'U+12B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 7
        end
        object P_Up5B: TPanel
          Left = 92
          Top = 33
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 8
        end
        object P_1: TPanel
          Left = 3
          Top = 33
          Width = 89
          Height = 30
          Caption = 'U+5B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 9
        end
        object P_PRMu: TPanel
          Left = 3
          Top = 3
          Width = 89
          Height = 30
          Caption = #1055#1056#1052
          ParentBackground = False
          TabOrder = 10
        end
        object P_PRDu: TPanel
          Left = 201
          Top = 3
          Width = 89
          Height = 30
          Caption = #1055#1056#1044
          ParentBackground = False
          TabOrder = 11
        end
        object P_1D: TPanel
          Left = 201
          Top = 33
          Width = 89
          Height = 30
          Caption = 'U+5B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 12
        end
        object P_2D: TPanel
          Left = 201
          Top = 63
          Width = 89
          Height = 30
          Caption = 'U+12B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 13
        end
        object P_Up12BD: TPanel
          Left = 290
          Top = 63
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 14
        end
        object P_Up5BD: TPanel
          Left = 290
          Top = 33
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 15
        end
        object P_PprmD: TPanel
          Left = 290
          Top = 93
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 16
        end
        object P_3D: TPanel
          Left = 201
          Top = 93
          Width = 89
          Height = 30
          Caption = 'P'#1087#1088#1084
          Color = clSilver
          ParentBackground = False
          TabOrder = 17
        end
        object P_4D: TPanel
          Left = 201
          Top = 123
          Width = 89
          Height = 30
          Caption = 'U-5B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 18
        end
        object P_Um5BD: TPanel
          Left = 290
          Top = 123
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 19
        end
        object P_Ip27BD: TPanel
          Left = 290
          Top = 153
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 20
        end
        object P_5D: TPanel
          Left = 201
          Top = 153
          Width = 89
          Height = 30
          Caption = 'I+27B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 21
        end
        object P_VIPu: TPanel
          Left = 401
          Top = 3
          Width = 89
          Height = 30
          Caption = #1042#1048#1055
          ParentBackground = False
          TabOrder = 22
        end
        object P_1V: TPanel
          Left = 401
          Top = 33
          Width = 89
          Height = 30
          Caption = 'U+12B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 23
        end
        object P_2V: TPanel
          Left = 401
          Top = 63
          Width = 89
          Height = 30
          Caption = 'U+27B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 24
        end
        object P_3V: TPanel
          Left = 401
          Top = 93
          Width = 89
          Height = 30
          Caption = 'I'#1074#1087#1088#1076
          Color = clSilver
          ParentBackground = False
          TabOrder = 25
        end
        object P_4V: TPanel
          Left = 401
          Top = 123
          Width = 89
          Height = 30
          Caption = 'U+5B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 26
        end
        object P_5V: TPanel
          Left = 401
          Top = 153
          Width = 89
          Height = 30
          Caption = 'I'#1074#1087#1088#1084
          Color = clSilver
          ParentBackground = False
          TabOrder = 27
        end
        object P_Ivprm: TPanel
          Left = 490
          Top = 153
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 28
        end
        object P_Up5BV: TPanel
          Left = 490
          Top = 123
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 29
        end
        object P_Up12BV: TPanel
          Left = 490
          Top = 33
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 30
        end
        object P_Ivprd: TPanel
          Left = 490
          Top = 93
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 31
        end
        object P_Up27BV: TPanel
          Left = 490
          Top = 63
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 32
        end
        object P_UUu: TPanel
          Left = 3
          Top = 247
          Width = 89
          Height = 30
          Caption = #1059#1059
          ParentBackground = False
          TabOrder = 33
        end
        object P_1U: TPanel
          Left = 3
          Top = 277
          Width = 89
          Height = 30
          Caption = 'U+5B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 34
        end
        object P_Up5BU: TPanel
          Left = 92
          Top = 277
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 35
        end
        object P_I: TPanel
          Left = 92
          Top = 307
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 36
        end
        object P_2U: TPanel
          Left = 3
          Top = 307
          Width = 89
          Height = 30
          Caption = 'U+12B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 37
        end
        object P_3U: TPanel
          Left = 3
          Top = 337
          Width = 89
          Height = 30
          Caption = 'P'#1087#1088#1084
          Color = clSilver
          ParentBackground = False
          TabOrder = 38
        end
        object P_Up12BU: TPanel
          Left = 92
          Top = 337
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 39
        end
        object P_BSu: TPanel
          Left = 201
          Top = 247
          Width = 89
          Height = 30
          Caption = #1041#1057
          ParentBackground = False
          TabOrder = 40
        end
        object P_1B: TPanel
          Left = 201
          Top = 277
          Width = 89
          Height = 30
          Caption = 'To'
          Color = clSilver
          ParentBackground = False
          TabOrder = 41
        end
        object P_2B: TPanel
          Left = 201
          Top = 307
          Width = 89
          Height = 30
          Caption = 'Tr'
          Color = clSilver
          ParentBackground = False
          TabOrder = 42
        end
        object P_7B: TPanel
          Left = 201
          Top = 457
          Width = 89
          Height = 30
          Caption = 'U-5B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 43
        end
        object P_4B: TPanel
          Left = 201
          Top = 367
          Width = 89
          Height = 30
          Caption = 'I+27B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 44
        end
        object P_5B: TPanel
          Left = 201
          Top = 397
          Width = 89
          Height = 30
          Caption = 'Po'
          Color = clSilver
          ParentBackground = False
          TabOrder = 45
        end
        object P_Po: TPanel
          Left = 290
          Top = 397
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 46
        end
        object P_Ip27BB: TPanel
          Left = 290
          Top = 367
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 47
        end
        object P_Um5BB: TPanel
          Left = 290
          Top = 457
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 48
        end
        object P_Tr: TPanel
          Left = 290
          Top = 307
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 49
        end
        object P_To: TPanel
          Left = 290
          Top = 277
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 50
        end
        object P_Pr: TPanel
          Left = 290
          Top = 427
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 51
        end
        object P_6B: TPanel
          Left = 201
          Top = 427
          Width = 89
          Height = 30
          Caption = 'Pr'
          Color = clSilver
          ParentBackground = False
          TabOrder = 52
        end
        object P_Up5BB: TPanel
          Left = 290
          Top = 337
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 53
        end
        object P_3B: TPanel
          Left = 201
          Top = 337
          Width = 89
          Height = 30
          Caption = 'U+5B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 54
        end
        object P_FRLPu: TPanel
          Left = 401
          Top = 247
          Width = 89
          Height = 30
          Caption = #1060#1056#1051#1055
          ParentBackground = False
          TabOrder = 55
        end
        object P_1F: TPanel
          Left = 401
          Top = 277
          Width = 89
          Height = 30
          Caption = 'Uucps'
          Color = clSilver
          ParentBackground = False
          TabOrder = 56
        end
        object P_2F: TPanel
          Left = 401
          Top = 307
          Width = 89
          Height = 30
          Caption = 'T'
          Color = clSilver
          ParentBackground = False
          TabOrder = 57
        end
        object P_3F: TPanel
          Left = 401
          Top = 337
          Width = 89
          Height = 30
          Caption = 'I+27B'
          Color = clSilver
          ParentBackground = False
          TabOrder = 58
        end
        object P_4F: TPanel
          Left = 401
          Top = 367
          Width = 89
          Height = 30
          Caption = 'Udet'
          Color = clSilver
          ParentBackground = False
          TabOrder = 59
        end
        object P_Udet: TPanel
          Left = 490
          Top = 367
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 60
        end
        object P_Ip27BF: TPanel
          Left = 490
          Top = 337
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 61
        end
        object P_T: TPanel
          Left = 490
          Top = 307
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 62
        end
        object P_Uucps: TPanel
          Left = 490
          Top = 277
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 63
        end
        object P_6V: TPanel
          Left = 401
          Top = 183
          Width = 89
          Height = 30
          Caption = 'U'#1074#1087#1088#1076
          Color = clSilver
          ParentBackground = False
          TabOrder = 64
        end
        object P_Uvkprd: TPanel
          Left = 490
          Top = 183
          Width = 89
          Height = 30
          Caption = 'Panel1'
          Color = clSilver
          ParentBackground = False
          TabOrder = 65
        end
      end
    end
  end
  object StaticText4: TStaticText
    Left = 648
    Top = 206
    Width = 95
    Height = 17
    Caption = #1057#1080#1089#1090#1077#1084#1085#1086#1077' '#1074#1088#1077#1084#1103':'
    TabOrder = 3
  end
  object P_SystemTime: TPanel
    Left = 648
    Top = 222
    Width = 129
    Height = 33
    Hint = #1057#1080#1089#1090#1077#1084#1085#1086#1077' '#1074#1088#1077#1084#1103'|'#1057#1080#1089#1090#1077#1084#1085#1086#1077' '#1074#1088#1077#1084#1103
    Caption = '2014.01.01 00:00:00'
    TabOrder = 4
  end
  object StaticText3: TStaticText
    Left = 803
    Top = 206
    Width = 79
    Height = 17
    Caption = #1042#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099':'
    TabOrder = 5
  end
  object P_WorkTime: TPanel
    Left = 803
    Top = 222
    Width = 129
    Height = 33
    Hint = #1042#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099'|'#1042#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099
    Caption = '00:00:00'
    TabOrder = 6
  end
  object Button1: TButton
    Left = 542
    Top = 96
    Width = 184
    Height = 33
    Hint = #1055#1077#1088#1077#1076#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1099'|'#1055#1077#1088#1077#1076#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1099
    Caption = #1044#1072#1085#1085#1099#1077' '#1074' '#1088#1077#1078#1080#1084#1077' '#1089#1072#1084#1086#1082#1086#1085#1090#1088#1086#1083#1100
    TabOrder = 7
    Visible = False
    OnClick = Button1Click
  end
  object GB_Commands: TGroupBox
    Left = 119
    Top = 32
    Width = 177
    Height = 105
    Hint = #1050#1086#1084#1072#1085#1076#1099'|'#1050#1086#1084#1072#1085#1076#1099
    Caption = #1050#1086#1084#1072#1085#1076#1099
    TabOrder = 8
    object Label16: TLabel
      Left = 120
      Top = 8
      Width = 25
      Height = 13
      Caption = 'Com:'
    end
    object Label13: TLabel
      Left = 113
      Top = 48
      Width = 54
      Height = 13
      Caption = 'Baud Rate:'
    end
    object L_SendDirect: TLabel
      Left = 16
      Top = 88
      Width = 122
      Height = 13
      Caption = #1053#1072#1087#1088'-'#1077' '#1087#1077#1088#1077#1076#1072#1095#1080': '#1060#1056#1051#1055
    end
    object B_Ready: TButton
      Left = 8
      Top = 17
      Width = 90
      Height = 33
      Hint = #1055#1086#1076#1075#1086#1090#1086#1074#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1099'|'#1055#1086#1076#1075#1086#1090#1086#1074#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1099
      Caption = #1055#1086#1076#1075#1086#1090#1086#1074#1080#1090#1100
      TabOrder = 0
      OnClick = B_ReadyClick
    end
    object B_Send: TButton
      Left = 8
      Top = 56
      Width = 90
      Height = 33
      Hint = #1055#1077#1088#1077#1076#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1099'|'#1055#1077#1088#1077#1076#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1099
      Caption = #1055#1077#1088#1077#1076#1072#1090#1100
      TabOrder = 1
      OnClick = B_SendClick
    end
    object CB_ComNum: TComboBox
      Left = 120
      Top = 24
      Width = 41
      Height = 21
      ItemIndex = 0
      TabOrder = 2
      Text = '1'
      OnChange = CB_ComNumChange
      Items.Strings = (
        '1'
        '2'
        '3'
        '4'
        '5'
        '6'
        '7'
        '8'
        '9'
        '10'
        '11'
        '12'
        '13'
        '14'
        '15'
        '16'
        '17'
        '18'
        '19'
        '20'
        '21'
        '22'
        '23'
        '24'
        '25'
        '26'
        '27'
        '28'
        '29'
        '30'
        '31'
        '32')
    end
    object CB_BaudRate: TComboBox
      Left = 112
      Top = 64
      Width = 57
      Height = 21
      ItemIndex = 1
      TabOrder = 3
      Text = '57600'
      OnChange = CB_BaudRateChange
      Items.Strings = (
        '9600'
        '57600')
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 557
    Width = 940
    Height = 19
    AutoHint = True
    DoubleBuffered = False
    Panels = <>
    ParentDoubleBuffered = False
    ParentShowHint = False
    ShowHint = True
    SimplePanel = True
  end
  object M_Debug: TMemo
    Left = 760
    Top = 56
    Width = 155
    Height = 144
    Lines.Strings = (
      '')
    TabOrder = 10
  end
  object P_FRLP: TPanel
    Left = 648
    Top = 300
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 11
  end
  object P_PRM: TPanel
    Left = 709
    Top = 300
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 12
  end
  object P_PRD: TPanel
    Left = 773
    Top = 300
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 13
  end
  object P_BS: TPanel
    Left = 837
    Top = 300
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 14
  end
  object P_Lock1: TPanel
    Left = 648
    Top = 354
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 15
  end
  object P_VK_PRM: TPanel
    Left = 773
    Top = 354
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 16
  end
  object P_VK_PRD1: TPanel
    Left = 837
    Top = 354
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 17
  end
  object P_VK_PRD2: TPanel
    Left = 898
    Top = 354
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 18
  end
  object P_OneSec: TPanel
    Left = 8
    Top = 141
    Width = 10
    Height = 10
    Color = clBlue
    ParentBackground = False
    TabOrder = 19
  end
  object P_UU: TPanel
    Left = 898
    Top = 300
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 20
  end
  object P_Lock2: TPanel
    Left = 709
    Top = 354
    Width = 17
    Height = 17
    Color = clSilver
    ParentBackground = False
    TabOrder = 21
  end
  object Button2: TButton
    Left = 668
    Top = 157
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 22
    OnClick = Button2Click
  end
  object NIDAQmxTimer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = NIDAQmxTimerTimer
    Left = 544
    Top = 65528
  end
  object OpenDialog1: TOpenDialog
    Title = #1054#1090#1082#1088#1099#1090#1080#1077' '#1092#1072#1081#1083#1072' '#1076#1072#1085#1085#1099#1093' '#1041#1058
    Left = 616
    Top = 65528
  end
  object SaveDialog1: TSaveDialog
    Left = 680
    Top = 65528
  end
  object ImageList1: TImageList
    Left = 744
    Top = 65528
    Bitmap = {
      494C010107000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      000000000000000000000000000000000000FFFFFF00FFFFFF00FEFEFE01FFFF
      FF00FFFFFF00FCFCFC05F7F7F610F4F4F216F3F3F118F5F5F314F9F9F80CFFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FEFEFD02FBFBFB07FAFAF90AF9F9F90BFAFAFA09FCFCFC05FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F9F9F906F9F9
      F906F9F9F906F9F9F906E5E5E51AE4E4E41BE4E4E41BE4E4E41BF7F7F708F9F9
      F906F9F9F906F9F9F906FEFEFE01FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00F3F1EB1EFFC23CC3F4B1
      21FFF8B933FAF7B933FBF7B72FFDF6B72EFEF6B62DFEF7B62EFEF6B730FCF7A8
      04FBEEA402FFD79504FFE2BB748BFFFFFF00FFFFFF00FEFEFE01FFD57788F5AF
      17FFF6B62BFDF7B72FFCF7B72DFDF7B72DFEF7B62CFEF7B62CFEF7B52AFDF7A9
      03FCE89F02FFCE9212EFEDE6D632FFFFFF00FFFFFF00FFFFFF00435E6EF9425E
      6EFD425E6EFD425E6DFDA9A8A7FFA5A5A5FFA5A5A5FFA3A4A4FF3C596AFC425E
      6EFD425E6EFD425E6EFBCDCDCD32FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00E6B03AFFEFBC50FEEEBD
      50FFEEBC50FFEEBC51FFEEBC51FFEFBD50FFE9BA50FFEEBB4FFFE8A30DFFE69E
      00FFE69E00FFE69E00FFE59C01FEF3D18E71FEFEFE01FDBC36C9EEBB4CFEEFBC
      4CFFEFBC4CFFEFBB4DFFEFBC4DFFEFBC4CFFEFBC4CFFEFBB4CFFE8A105FFE89F
      00FFE89F00FFE89E01FEE79E05FAFBFAF909FFFFFF00FFFFFF00A7ACB1FBA9AE
      B3FFA9AEB3FFA9AEB3FFBCC4CFFF749ED7FF759FD9FF91AED7FFAAAFB3FFA9AE
      B3FFA9AEB3FFA8ADB2FDCECECE33FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FBF9F60CEAC472FFEAC4
      73FFEAC373FFEAC473FFEAC474FFE4C278FF0045B1FF4F3F21FFB57B00FFD994
      00FFD79200FFD79300FFD89A12EDFFFFFF00FFFFFF00FFFFFF00E7BE69FFEAC3
      6FFEEAC36FFFEAC36FFFEAC370FFEAC26EFFEAC26EFFEAC370FFD99500FFD894
      00FFD99400FFD99402FDE6AC3AC5FFFFFF00FFFFFF00FFFFFF00D0D0D0FBD4D4
      D4FFD4D4D4FFD4D4D4FFC1C9D7FF5B8FD8FF5588D0FF7A9ED1FFD4D4D4FFD4D4
      D4FFD4D4D4FFD3D3D3FDCFCFCF33FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FAF8F40EDEB9
      6AFFE8CF98FDE8CF96FEE3CD98FF0078FFFF004DB8FF004DB8FF364752FF7550
      00FF8D6001FEB2852AD5FFFFFF00FFFFFF00FFFFFF00FFFFFF00FAF8F60DE2C1
      79FFE4CC8EFFEFD093FFE6CD91FFE8CD91FFE8CC8FFFCE900AFFCB8B00FFCC8A
      01FECC8C03FCD6A033CDFFFFFF00FFFFFF00FFFFFF00FFFFFF00DBDBDBFBE0E0
      E0FFE0E0E0FFE0E0E0FFC2CBD8FF5084CBFF4D80C7FF7D9DC8FFE0E0E0FFE0E0
      E0FFE0E0E0FFDFDFDFFCD0D0D033FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E5D8BB4DD5A94AEE83ADC2FE0280FEFF0052C4FF0052C3FF0051C1FF014F
      CFFEFEFEFE01FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BEE2
      D44C18D67EFD01F99CFE0E2218FDF5E1B5FEDDBE79FEC18502FDC18506F9BE83
      03FFEDE7DA30FDFDFE02FFFFFF00FFFFFF00FFFFFF00FFFFFF00E8E8E8FBEDED
      EDFFEDEDEDFFEDEDEDFFC2CCD9FF5083CBFF4D80C8FF7394C3FFECECECFFEDED
      EDFFEDEDEDFFECECECFEC4C4C444FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FDFDFD03038BFAFD88B6DEFF0057D1FF0057CFFF0056CCFF0053
      C6FF0754BFF86596D8A2FCFCFC05FFFFFF00FFFFFF00FBFBFB0603FEA3FF02FB
      9FFD01FA9FFE01F89DFE5BCC99ABECEBE824ECEAE629F3F2EF1AFFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E1E1E1FBF8F8
      F8FFF9F9F9FFF9F9F9FFC3CCD8FF477AC1FF4779C0FF6386B8FFF8F8F8FFF9F9
      F9FFF8F8F8FFF0F0F0FEC3C3C343FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0041B1FFBE008EFFFFD9D6D4FF005CDEFF005DDDFF005AD8FF0057
      D1FF0053C6FF0050BEFF004CB9FFF1F1F137FFFFFF00FFFFFF00FFFFFF001FF1
      A2E000F89DFF00F59BFF02C880FEFCFCFC05FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EDEDED128383837CB4B4B4FCEAEA
      EAFFFDFDFDFFFEFEFEFFC5CCD6FF4C72A9FF4C73A9FF6681A8FFFDFDFDFFFEFE
      FEFFF6F6F6FFC2C2C2FD75757497DADADA250000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00059EFEFBC6D7E3FFD6D5D4FF0061EBFF0063E9FF0060E2FF005C
      DAFF0056CEFF0052C3FF004DB9FF0049B2FFFFFFFF00FFFFFF00FFFFFF0001F9
      9EFE00F49BFF01F098FE04DF8EFDFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00565554FF212D41FEB5B5
      B6FFEBEBEBFFFDFDFDFFFEFEFEFFFFFFFFFFFFFFFFFFFEFEFEFFFEFEFEFFF7F7
      F7FFC3C3C3FF5D5D5FFE53514FF9FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000A7FFFF16A7F9FED9DCDDFFD9D8D8FF0066F5FF0067F4FF0063EBFF005F
      E0FF0059D3FF0054C8FF004FBCFF004AB4FFFFFFFF00FFFFFF00FFFFFF0002F5
      9BFD00F097FFDCF1E924EFF5F318F5F7F610FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF005B5A59FF2936
      48FEB6B6B6FFEBEBEBFFFEFEFEFFB4B4B4FFB5B5B5FFFCFCFCFFF7F7F7FFC3C3
      C3FF6A6A6BFE575653F9FAFAFA05FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00DAF2
      FD2602ADFEFDF9F2EFFFDDDEDEFFDBDBD9FF016AFCFF0069F9FF0064EFFF005F
      E3FF005AD7FF0054C9FF004FBDFF004BB5FFFFFFFF00FFFFFF00FFFFFF0001F2
      9AFE00EC95FFCAE9DD37FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00605F
      5EFF2F3C4CFEB6B6B7FFF2F2F2FFB3B3B3FFAFAFAFFFEFEFEFFFC3C3C3FF6C6C
      6DFF5D5B58FBF8F8F807FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FEFDFD0202B7
      FCFE4EC5F4FFE0DFDEFFDFDFDFFFDCDDDDFFCBD2DAFF5D97E7FF0060EDFF005E
      E2FF005AD5FF0153C8FE014FBCFE004BB5FFFFFFFF00FFFFFF00FFFFFF0002F1
      99FD00E691FF1EA770E1FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00656462FF35424EFEB6B6B7FFDFDFDFFFE9E9E9FFC3C3C3FF6E6F6FFF625F
      5DFFE0E0E0FBFFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF0071DFFF8E01BB
      FFFEF6F7F8FFE1E3E5FFDEE0E2FFDCDDDFFFD7D9DAFFD3D5D6FFCED0D2FFCBCE
      CEFE88B2DCFE789ED2950C54BFF3024BB2FFFFFFFF00FFFFFF00FFFFFF0062E8
      B29D01E08DFE02D083FDAFD9C853FCFCFC05FFFFFF00FDFDFD03EAF1EE1A006E
      41FF9DBFB171FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00696867FF3D4A54FEB7B7B7FFC5C4C4FF717272FE646260FCDFDF
      DFFFEEEEEEFBFFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF0005C2FCFA00C0
      FFFF00B7FFFF00B2FFFF00AAFFFF06A4FFF9079BFFF80794FFF8078DFFF80985
      FFF671B9FF8EFFFFFF00FDFDFD03FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0004D78AFD00CB7FFF02B772FD0E8D59F1439B75BC1C8454E3006D40FF0166
      3BFE046B40FBFBFCFC05FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF006F6D6CFF49565EFE797878FE696766FAF4F4F40B659D
      E5FE4882D5FEFFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FEFEFE011CCCFFE300C5FFFF00C2
      FFFF00BCFFFF01B7FFFE00AFFFFFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FEFEFE01FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FBFBFB0600C37CFF00B16EFF009B60FF008752FF007745FF006B3EFF0268
      3CFDE6ECEA22FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00757372FF6D6C6BFAF4F4F40BFEFEFE015797
      ECFD2C70D5FDFFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00F1F3F319F0F2F31AF0F2
      F31AF0F2F31AF1F3F319FCFCFC05FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF004FC096B002975DFD008350FF007746FF378E69C8FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F4F4F40BFFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B7BCBE485858
      58A7464646B96A6A6A959393936CBCBCBC43DADADA25EAEAEA15F2F2F20DF6F6
      F609FCFCFC030000000000000000000000000000000000000000F9F9F9069F9F
      9F60E3E3E31CF6F6F60900000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AD5A5A00AD52
      5200A54A4A00AD949400C6CEC600CECEC600CECEC600C6CEC600C6CEC600B59C
      9C009C4242009C424200A55252000000000000000000F7F7F708FBFBFB04FEFE
      FE01000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F9F9F9064096BCFF2D93
      BFFF106387EF234E64DC394C56C64D5153B25B5B5BA47474748B9595956AB3B3
      B34CD2D2D22DE9E9E916000000000000000000000000000000006D6D6DFF4444
      44FF343434EB494949BA7474748BBCBCBC43EFEFEF10FCFCFC03000000000000
      00000000000000000000000000000000000000000000BD7B7300CE636300CE6B
      6B00B55A5A009C848400BDA5A500E7CECE00FFF7F700FFFFF700F7F7F700CEB5
      B500942929009C313100C65A5A00AD5A5A00FEFEFE0181939A7E6B6B6B949999
      9966C7C7C738E5E5E51AF8F8F807FEFEFE010000000000000000000000000000
      00000000000000000000000000000000000000000000BBC1C544308CB6FFB8EB
      FFFF69D2FCFF4DC3EFFF31A7D6FF1C8FBFFF0C6A91F31E526CE12E4D5CD1454E
      52BA595959A68282827DE3E3E31C000000000000000000000000828282FF5353
      53FF444444FF00CCFFFF0C82DBFF293669FF3A3A3AD7585858A79595956ADADA
      DA25F5F5F50A00000000000000000000000000000000BD7B7300CE636300CE63
      6300B55A5A009C7B7B009C424200B5737300E7DEDE00FFF7F700FFFFFF00D6B5
      B500943131009C313100BD5A5A00AD5A5A00FEFEFE0167C3E2FF6DD3FFFF37B7
      E6FF0D8CB8F7325F6FCD6565659A8C8C8C73BFBFBF40E0E0E01FF4F4F40BFEFE
      FE010000000000000000000000000000000000000000BBC1C544278BBCFFC6EC
      F9FF7AE0FFFF7AE0FFFF7AE0FFFF7AE0FFFF7AE0FFFF5CCEF2FF3DB3DCFF269C
      C9FF126D94F3535353ACB0B0B04FF6F6F6090000000000000000858585FF5151
      51FF434343FFECD9CFFF93998FFF26A6BFFF0080FFFF0033FFFF203380FF3939
      39EF525252B1F3F3F30C000000000000000000000000BD7B7300CE636300CE63
      6300B55A5A00AD8484009C3939009C393900CEBDBD00EFEFEF00FFFFFF00E7C6
      C6009429290094313100BD5A5A00AD5A5A00FEFEFE014CBDECFFA9E9FFFF76DC
      FFFF76DCFFFF76DCFFFF76DCFFFF4AC4ECFF0FA2D2FF25657CDA5F5F5FA08888
      8877F0F0F00F00000000000000000000000000000000BBC1C54454B6E1FF8FC6
      DCFF94EEFFFF85EBFFFF85EBFFFF85EBFFFF85EBFFFF85EBFFFF85EBFFFF85EB
      FFFF5DCDE9FF2A4959D579797986E6E6E6190000000000000000888888FF4E4E
      4EFF424242FF563370FF993300FFD9B39FFFFFFFFFFF0033FFFF1A3399FF6363
      63FF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300CE636300CE63
      6300B55A5A00B58C8C009C4A4A0094313100A59C9C00D6D6D600FFFFFF00E7C6
      C6009429290094313100BD5A5A00AD5A5A00FEFEFE0177D0FAFFF7FDFFFF80E6
      FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF1981
      A1EEB9B9B94600000000000000000000000000000000BAC0C44561C6F0FF60AE
      D1FFC0F9FFFF8FF5FFFF8FF5FFFF8FF5FFFF8FF5FFFF8FF5FFFF8FF5FFFF8FF5
      FFFF9BF2FFFF207899F3565656A9B9B9B94600000000000000008B8B8BFF4C4C
      4CFF404040FF0033FFFF0033FFFF0033FFFF0033FFFF0033FFFF1A3399FF6060
      60FF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300CE636300CE63
      6300BD5A5A00C6948C00C6949400B5848400AD8C8C00BDA5A500E7C6C600DEAD
      AD00A5393900A5393900C65A5A00AD5A5A00FEFEFE0180D3FBFF80CCE6FF8AF0
      FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF9DF9
      FCFF6B6B6B94F7F7F708000000000000000000000000A2ADB35D6DCAF2FF319E
      D1FFD6F9FCFF99FFFFFF99FFFFFF99FFFFFF99FFFFFF99FFFFFF99FFFFFF99FF
      FFFFABF2FFFF79CFE2FF354853CA7777778800000000000000008E8E8EFF4949
      49FF3C3C3CFF424242FF4F4F4FFF434343FF1D338CFF0633E6FF1A3399FF5E5E
      5EFF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300CE636300CE63
      6300CE636300CE636300CE636300CE636300CE636300C65A5A00C65A5A00CE63
      6300CE636300CE636300CE6B6B00AD525A00FEFEFE018BD8FDFF30B1E4FFA8FB
      FFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFFBBFF
      FFFF23647ADCCECECE310000000000000000F8F8F8076483929B8FD9F9FF59BF
      ECFF80BFD9FFE7FFFFFFD9FFFFFFCBFFFFFFC0FFFFFFB9FFFFFFB9FFFFFFB9FF
      FFFFBAF2FFFFD6FFFFFF1F6682EB474747B80000000000000000919191FF4646
      46FF383838FF333333FF333333FF333333FF535353FF333333FF4F4F4FFF5B5B
      5BFF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300B5525200B55A
      5A00C6848400D6A5A500D6ADAD00D6ADA500D6ADAD00D6A5A500D6A5A500D6AD
      A500D6ADAD00D69C9C00CE636300AD525200FEFEFE018CD8FFFF66CCFFFFF3FF
      FFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFCEFF
      FFFF9BE6F2FF7D7D7D82FBFBFB0400000000ACB6AC531A692AE52D8640FF1D83
      40FF076D2DFF006C2DFF208039FF408F4DFFCCE9F2FFDCFFFFFFD3FFFFFFD3FF
      FFFFCAF2FFFFEBFFFFFF76BCD6FF3D464BC20000000000000000949494FF4444
      44FF464646FF424242FF393939FF333333FF4F4F4FFF333333FF333333FF5959
      59FF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300AD524A00E7CE
      CE00F7F7F700F7F7EF00F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F700F7F7F700DEBDBD00C65A5A00AD525A00F6F6F6099AE2FFFF74DAFFFF4AC3
      ECFF5EC4E6FF80CCE6FFDFF2F9FFCBFFFFFFC0FFFFFFC0FFFFFFC0FFFFFFE1FF
      FFFFE1FFFFFF355B67CADEDEDE2100000000CFD2CF30259037F038D16BFF32CB
      64FF28C150FF1CB538FF12AB23FF06850BFF49AFCCFF80B9D2FF8FC6DCFFBEE2
      EFFFE6F5FCFFFFFFFFFFEFF9FCFF406A7EBF0000000000000000979797FF4141
      41FF7DE3FFFF82E8FFFF87EDFFFF8CF2FFFF74ADB2FF475354FF474747FF5656
      56FF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300B5524A00EFD6
      D600FFF7F700F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EF
      EF00F7F7F700DEBDBD00C65A5A00AD525A00B7C1C54897ECFFFF85EBFFFF85EB
      FFFF85EBFFFF85EBFFFF85EBFFFF68C5E2FFF5FFFFFFEDFFFFFFE5FFFFFFF4FF
      FFFFF4FFFFFF89D2E9FF9B9B9B64FEFEFE010000000072918F8D18912BFF38D1
      6BFF32CB64FF28C150FF1CB538FF0B8A15FF9FFFFFFF99FFFFFF86ECF2FF73D9
      E6FF0A6590F53B7086C46990A5C7A3AFB55C00000000000000009A9A9AFF3E3E
      3EFF82E8FFFF90F6FFFF8EF4FFFF96FCFFFF92F8FFFF97FDFFFF97FDFFFF5353
      53FF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300B5524A00EFD6
      D600EFEFEF00D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6
      D600EFEFEF00DEBDBD00C65A5A00AD525A00B7C1C548A8FAFFFF96FCFFFF96FC
      FFFF96FCFFFF96FCFFFF96FCFFFF96FCFFFF96FCFFFF8DF6FCFF5FD8ECFF2686
      A5E670C6E2FFBFE6F2FFD7D7D72800000000F5F5F50A3D7647C53FCE68FF42DB
      75FF38D16BFF32CB64FF28C150FF0F8F1EFF79B6D2FF91C9DFFF9FE0EFFFB4F0
      F9FF387B98D2D1D1D12EFBFBFB040000000000000000000000009C9C9CFF3B3B
      3BFF8DF3FFFF88EEFFFF90F6FFFF8BF1FFFF91F7FFFF93F9FFFF98FEFFFF5151
      51FF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300B5524A00EFD6
      D600EFEFEF00DED6D600DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DED6
      D600EFEFEF00DEBDBD00C65A5A00AD525A00DEE0E121CCFBFFFF99FFFFFF99FF
      FFFF99FFFFFFD7FBFFFFC3FCFFFFAEFEFFFF99FFFFFF99FFFFFF99FFFFFF6E6E
      6E91FEFEFE010000000000000000000000008DA08D7248D56FFF57F08AFF4DE6
      80FF42DB75FF38D16BFF32CB64FF15952BFF585858A7BCC0C343BCC2C5438C9F
      AA73C7CBCD38FBFBFB04000000000000000000000000000000009F9F9FFF3939
      39FF6ED4FFFF73D9FFFF78DEFFFF7DE3FFFF82E8FFFF87EDFFFF94FAFFFF4E4E
      4EFF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300B5524A00EFD6
      D600F7F7EF00E7DEDE00E7DEDE00E7DEDE00E7DEDE00E7DEDE00E7DEDE00E7DE
      DE00EFEFEF00DEBDBD00C65A5A00AD525A00000000007BCBE6FFE1FDFFFFC3FE
      FFFFD5FEFFFF5B7F8BA4FBFBFB04CDD2D43279A0AE865C9FB7C56BC4E2FFE1E1
      E11E00000000000000000000000000000000CFD2CF30329E44F061FA94FF57F0
      8AFF4DE680FF2EB751FF38D16BFF1A9933FF5C5C5CA3E7E7E718000000000000
      0000000000000000000000000000000000000000000000000000A2A2A2FF3636
      36FF69CFFFFF6ED4FFFF73D9FFFF78DEFFFF7DE3FFFF82E8FFFF87EDFFFF4C4C
      4CFF3B3B3BD9F3F3F30C000000000000000000000000BD7B7300B5524A00EFD6
      D600EFEFEF00D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6
      D600EFEFEF00DEBDBD00C65A5A00AD525A000000000000000000FEFEFE01DEE0
      E121B8C2C647FBFBFB0400000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000CFD2CF30329E44F061FA
      94FF36BC56FF567756A9249036F11E9D37FF8F8F8F70EAEAEA15000000000000
      0000000000000000000000000000000000000000000000000000A5A5A5FF3333
      33FF363636FF3F4C52FF527E91FF66B2CFFF78DEFFFF7DE3FFFF82E8FFFF4949
      49FF494949C9F8F8F807000000000000000000000000BD7B7300B5524A00E7D6
      CE00FFF7F700F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EFEF00F7EF
      EF00FFF7F700DEBDBD00C65A5A00AD525A000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CFD2CF302084
      2BEF91A1916EF6F6F609CFD2CF30227325E0EAEAEA1500000000000000000000
      000000000000000000000000000000000000000000000000000000000000EFEF
      EF10B2B2B2548D8D8D94838383D2878787FF8A8A8AFF6C6C6CFF4C4C4CFF6666
      66B0FEFEFE010000000000000000000000000000000000000000AD524A00CEB5
      B500D6D6D600CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00CECE
      CE00D6D6D600CEADAD00A54A4A0000000000424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFC007C3FFC0018FFF8003C03F8000
      00FF8001C0078000000F8000C003800000078000C003800000078000C0038000
      00038000C003800000030000C003800000010000C003800000010000C0038000
      00008000C003800000010001C003800000070003C0038000800F003FC0038000
      C3FF803FC0038000FFFFC07FE007C00100000000000000000000000000000000
      000000000000}
  end
  object CommPort1: TCommPort
    ComNumber = 1
    InSize = 2048
    OutSize = 4096
    Baud = 57600
    BaudRate = cbr57600
    DataBits = 8
    MonitorEvents = [evRxChar, evTxEmpty, evCTS, evDSR, evRlsd, evBreak, evError, evRing]
    XoffLim = 1024
    XonChar = #17
    XoffChar = #19
    Left = 808
    Top = 65528
  end
  object SystemTimer: TTimer
    Interval = 10
    OnTimer = SystemTimerTimer
    Left = 744
    Top = 222
  end
  object WorkTimer: TTimer
    Enabled = False
    OnTimer = WorkTimerTimer
    Left = 899
    Top = 222
  end
  object MainMenu: TMainMenu
    Left = 872
    Top = 65528
    object File: TMenuItem
      Caption = #1060#1072#1081#1083
      Hint = #1060#1072#1081#1083
      object LoadBlp: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' .blp'
        Hint = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1041#1058
        OnClick = TB_LoadBlpClick
      end
      object LoadSar: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' .sar'
        Hint = 
          #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084 +
          #1086#1076#1091#1083#1103
        OnClick = TB_LoadSarClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object SaveCtr: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' .ctr'
        Hint = 
          #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077 +
          #1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
        OnClick = TB_SaveControlClick
      end
      object SaveTst: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' .tst'
        Hint = 
          #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' ' +
          #1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
        OnClick = TB_SaveTestingClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object LoadCtr: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' .ctr'
        Hint = 
          #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077 +
          #1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
        OnClick = TB_LoadControlClick
      end
      object LoadTst: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' .tst'
        Hint = 
          #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' ' +
          #1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Exit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        Hint = #1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099'|'#1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
      end
    end
    object Help: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      Hint = #1057#1087#1088#1072#1074#1082#1072
      object HelpAboutProg: TMenuItem
        Caption = #1055#1086#1084#1086#1097#1100
        Hint = #1055#1086#1084#1086#1097#1100
      end
      object HelpAboutItem: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        Hint = 
          #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093'|'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075 +
          #1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093
        OnClick = TB_AboutClick
      end
    end
  end
  object T_Sec1: TTimer
    Enabled = False
    OnTimer = T_Sec1Timer
    Left = 656
    Top = 392
  end
  object T_Sec2: TTimer
    Enabled = False
    OnTimer = T_Sec2Timer
    Left = 704
    Top = 392
  end
  object T_mSec1: TTimer
    Enabled = False
    Interval = 200
    OnTimer = T_mSec1Timer
    Left = 752
    Top = 392
  end
  object T_Sec3: TTimer
    Enabled = False
    OnTimer = T_Sec3Timer
    Left = 704
    Top = 440
  end
  object T_mSec2: TTimer
    Enabled = False
    Interval = 200
    OnTimer = T_mSec2Timer
    Left = 752
    Top = 440
  end
  object T_mSec3: TTimer
    Enabled = False
    Interval = 200
    OnTimer = T_mSec3Timer
    Left = 656
    Top = 488
  end
  object T_Sec4: TTimer
    Enabled = False
    OnTimer = T_Sec4Timer
    Left = 752
    Top = 488
  end
  object T_Sec5: TTimer
    Enabled = False
    OnTimer = T_Sec5Timer
    Left = 848
    Top = 488
  end
  object T_Sec35: TTimer
    Enabled = False
    OnTimer = T_Sec35Timer
    Left = 704
    Top = 488
  end
  object T_Sec45: TTimer
    Enabled = False
    OnTimer = T_Sec45Timer
    Left = 800
    Top = 488
  end
end
