object Main_Form: TMain_Form
  Left = 203
  Top = 96
  Width = 1101
  Height = 621
  Caption = 'ControlTesting'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
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
    Top = 32
    Width = 105
    Height = 105
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
  object L_S: TLabel
    Left = 688
    Top = 144
    Width = 12
    Height = 13
    Caption = '00'
    Visible = False
  end
  object L_M: TLabel
    Left = 672
    Top = 144
    Width = 12
    Height = 13
    Caption = '00'
    Visible = False
  end
  object L_H: TLabel
    Left = 656
    Top = 144
    Width = 12
    Height = 13
    Caption = '00'
    Visible = False
  end
  object Label7: TLabel
    Left = 912
    Top = 64
    Width = 32
    Height = 13
    Caption = 'Label7'
  end
  object Label10: TLabel
    Left = 912
    Top = 88
    Width = 38
    Height = 13
    Caption = 'Label10'
  end
  object GB_Commands: TGroupBox
    Left = 240
    Top = 32
    Width = 177
    Height = 105
    Hint = #1050#1086#1084#1072#1085#1076#1099'|'#1050#1086#1084#1072#1085#1076#1099
    Caption = #1050#1086#1084#1072#1085#1076#1099
    TabOrder = 0
    object Label2: TLabel
      Left = 113
      Top = 48
      Width = 54
      Height = 13
      Caption = 'Baud Rate:'
      Visible = False
    end
    object Label16: TLabel
      Left = 120
      Top = 8
      Width = 24
      Height = 13
      Caption = 'Com:'
    end
    object L_SendDirect: TLabel
      Left = 16
      Top = 88
      Width = 125
      Height = 13
      Caption = #1053#1072#1087#1088'-'#1077' '#1087#1077#1088#1077#1076#1072#1095#1080': '#1060#1056#1051#1055
      Visible = False
    end
    object B_Ready: TButton
      Left = 8
      Top = 16
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
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 2
      Text = '1'
      OnChange = CB_ComNumChange
      OnKeyPress = CB_SignCKeyPress
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
      Enabled = False
      ItemHeight = 13
      ItemIndex = 1
      TabOrder = 3
      Text = '57600'
      Visible = False
      OnChange = CB_BaudRateChange
      Items.Strings = (
        '9600'
        '57600')
    end
  end
  object P_SystemTime: TPanel
    Left = 648
    Top = 184
    Width = 129
    Height = 33
    Hint = #1057#1080#1089#1090#1077#1084#1085#1086#1077' '#1074#1088#1077#1084#1103'|'#1057#1080#1089#1090#1077#1084#1085#1086#1077' '#1074#1088#1077#1084#1103
    Caption = '2014.01.01 00:00:00'
    TabOrder = 1
  end
  object StaticText4: TStaticText
    Left = 648
    Top = 168
    Width = 98
    Height = 17
    Caption = #1057#1080#1089#1090#1077#1084#1085#1086#1077' '#1074#1088#1077#1084#1103':'
    TabOrder = 2
  end
  object GB_Message: TGroupBox
    Left = 648
    Top = 224
    Width = 281
    Height = 313
    Caption = #1057#1086#1086#1073#1097#1077#1085#1080#1103
    TabOrder = 3
    object E_EnterComment: TEdit
      Left = 8
      Top = 48
      Width = 185
      Height = 21
      TabOrder = 0
    end
    object M_Log: TMemo
      Left = 8
      Top = 112
      Width = 265
      Height = 193
      ReadOnly = True
      ScrollBars = ssVertical
      TabOrder = 1
      Visible = False
    end
    object StaticText6: TStaticText
      Left = 8
      Top = 24
      Width = 192
      Height = 17
      Caption = #1057#1090#1088#1086#1082#1072' '#1074#1074#1086#1076#1072' '#1089#1086#1086#1073#1097#1077#1085#1080#1081' '#1086#1087#1077#1088#1072#1090#1086#1088#1072':'
      TabOrder = 2
    end
    object StaticText7: TStaticText
      Left = 8
      Top = 88
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
      Top = 88
      Width = 153
      Height = 17
      Caption = #1057#1082#1088#1099#1090#1100' '#1086#1082#1085#1086' '#1089#1086#1086#1073#1097#1077#1085#1080#1081
      Checked = True
      State = cbChecked
      TabOrder = 5
      OnClick = ChB_LogClick
    end
  end
  object PC_Main: TPageControl
    Left = 8
    Top = 145
    Width = 625
    Height = 392
    ActivePage = Tsh_Control
    BiDiMode = bdRightToLeftNoAlign
    MultiLine = True
    ParentBiDiMode = False
    TabIndex = 0
    TabOrder = 4
    object Tsh_Control: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      ImageIndex = 2
      object SB_Data1: TScrollBox
        Left = 0
        Top = 0
        Width = 615
        Height = 361
        VertScrollBar.Position = 239
        VertScrollBar.Range = 600
        VertScrollBar.Smooth = True
        VertScrollBar.Size = 10
        AutoScroll = False
        BorderStyle = bsNone
        TabOrder = 0
        object GB_Command1: TGroupBox
          Left = 8
          Top = -231
          Width = 561
          Height = 57
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1053#1072#1095#1072#1090#1100' '#1088#1072#1073#1086#1090#1091'"'
          TabOrder = 0
          object CB_Command1: TComboBox
            Left = 24
            Top = 24
            Width = 233
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 0
            Text = #1042#1082#1083'. '#1087#1080#1090#1072#1085#1080#1077' '#1057#1042#1063' '#1091#1089#1080#1083#1080#1090#1077#1083#1077#1081
            OnChange = CB_Command1Change
            Items.Strings = (
              #1042#1082#1083'. '#1087#1080#1090#1072#1085#1080#1077' '#1057#1042#1063' '#1091#1089#1080#1083#1080#1090#1077#1083#1077#1081
              #1042#1099#1082#1083'. '#1087#1080#1090#1072#1085#1080#1077' '#1057#1042#1063' '#1091#1089#1080#1083#1080#1090#1077#1083#1077#1081
              #1055#1080#1090#1072#1085#1080#1077' '#1057#1042#1063' '#1091#1089#1080#1083#1080#1090#1077#1083#1077#1081' '#1085#1077' '#1080#1079#1084#1077#1085#1103#1090#1100)
          end
        end
        object GB_Command3: TGroupBox
          Left = 8
          Top = -167
          Width = 561
          Height = 161
          Caption = 
            #1050#1086#1084#1072#1085#1076#1099' "'#1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1041#1058'", "'#1042#1088#1077#1084#1103' '#1079#1072#1076#1077#1088#1078#1082#1080' '#1041#1058'", "'#1044#1086#1087#1083#1077#1088#1086#1074#1089#1082#1080#1081' '#1089#1076#1074#1080#1075 +
            ' '#1095#1072#1089#1090#1086#1090#1099' '#1041#1058'".'
          TabOrder = 1
          object StaticText10: TStaticText
            Left = 208
            Top = 48
            Width = 58
            Height = 17
            Caption = #1053#1086#1084#1077#1088' '#1041#1058':'
            TabOrder = 0
          end
          object StaticText11: TStaticText
            Left = 32
            Top = 104
            Width = 79
            Height = 17
            Caption = #1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1041#1058':'
            TabOrder = 1
          end
          object E_Command3: TEdit
            Left = 24
            Top = 128
            Width = 145
            Height = 21
            TabOrder = 2
            Text = '255'
            OnChange = E_Command3Change
            OnExit = E_Command3Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object E_Command3_0: TEdit
            Left = 24
            Top = 72
            Width = 145
            Height = 21
            TabOrder = 3
            Text = '1'
            OnChange = E_Command3_0Change
            OnExit = E_Command3_0Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText49: TStaticText
            Left = 32
            Top = 48
            Width = 83
            Height = 17
            Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1041#1058':'
            TabOrder = 4
          end
          object CB_Command3_1: TComboBox
            Left = 200
            Top = 72
            Width = 145
            Height = 21
            ItemHeight = 13
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
            Left = 208
            Top = 104
            Width = 131
            Height = 17
            Caption = #1042#1088#1077#1084#1103' '#1079#1072#1076#1077#1088#1078#1082#1080' '#1041#1058' ['#1085#1089']:'
            TabOrder = 7
          end
          object E_Command4: TEdit
            Left = 200
            Top = 128
            Width = 145
            Height = 21
            TabOrder = 8
            Text = '0'
            OnChange = E_Command4Change
            OnExit = E_Command4Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText15: TStaticText
            Left = 384
            Top = 104
            Width = 163
            Height = 17
            Caption = #1044#1086#1087#1083#1077#1088'. '#1089#1076#1074#1080#1075' '#1095#1072#1089#1090#1086#1090#1099' '#1041#1058' ['#1043#1094']:'
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
            ItemHeight = 13
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
        end
        object GB_Command6: TGroupBox
          Left = 8
          Top = -1
          Width = 561
          Height = 226
          Caption = 
            #1050#1086#1084#1072#1085#1076#1099' "'#1057#1076#1074#1080#1075' '#1088#1072#1079#1088'.", "'#1062#1077#1085#1090#1088'-'#1103' '#1095#1072#1089#1090#1086#1090#1072' '#1088#1072#1073#1086#1095#1077#1081' '#1087#1086#1083#1086#1089#1099'", "'#1050#1086#1101#1092'-'#1090 +
            ' '#1086#1089#1083#1072#1073#1083#1077#1085#1080#1103' '#1087#1077#1088#1077#1076#1072#1090#1095#1080#1082#1072' '#1055#1055#1056#1052'-2".'
          TabOrder = 2
          object Label6: TLabel
            Left = 360
            Top = 160
            Width = 194
            Height = 13
            Caption = #1044#1080#1072#1087#1072#1079#1086#1085' '#1079#1085#1072#1095#1077#1085#1080#1081' 8500...17500 '#1052#1043#1094'.'
          end
          object ChB_Command6: TCheckBox
            Left = 24
            Top = 24
            Width = 153
            Height = 17
            Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
            TabOrder = 0
          end
          object E_Command6: TEdit
            Left = 376
            Top = 128
            Width = 145
            Height = 21
            TabOrder = 1
            Text = '8500'
            OnChange = E_Command6Change
            OnExit = E_Command6Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object CB_Command7: TComboBox
            Left = 24
            Top = 184
            Width = 145
            Height = 21
            ItemHeight = 13
            ItemIndex = 63
            TabOrder = 2
            Text = '-31,5'
            OnChange = CB_Command7Change
            OnExit = CB_Command7Change
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
          object StaticText12: TStaticText
            Left = 32
            Top = 48
            Width = 112
            Height = 17
            Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1084#1086#1076#1091#1083#1077#1081':'
            TabOrder = 3
          end
          object E_NumbOfMods: TEdit
            Left = 24
            Top = 72
            Width = 145
            Height = 21
            TabOrder = 4
            Text = '1'
            OnChange = E_NumbOfModsChange
            OnExit = E_NumbOfModsExit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText20: TStaticText
            Left = 384
            Top = 48
            Width = 59
            Height = 17
            Caption = #1052#1086#1076#1091#1083#1100' '#8470':'
            TabOrder = 5
          end
          object CB_Modulus: TComboBox
            Left = 376
            Top = 72
            Width = 145
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 6
            Text = '1'
            OnChange = CB_ModulusChange
            OnKeyPress = CB_SignCKeyPress
            Items.Strings = (
              '1')
          end
          object StaticText50: TStaticText
            Left = 32
            Top = 104
            Width = 122
            Height = 17
            Caption = #1048#1085#1076#1080#1074#1080#1076'-'#1099#1081' '#8470' '#1084#1086#1076#1091#1083#1103':'
            TabOrder = 7
          end
          object E_Mod: TEdit
            Left = 24
            Top = 128
            Width = 145
            Height = 21
            TabOrder = 8
            Text = '1'
            OnChange = E_ModChange
            OnExit = E_ModExit
          end
          object StaticText52: TStaticText
            Left = 208
            Top = 48
            Width = 102
            Height = 17
            Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1095#1072#1089#1090#1086#1090':'
            TabOrder = 9
          end
          object E_NumbOfFreq: TEdit
            Left = 200
            Top = 72
            Width = 145
            Height = 21
            TabOrder = 10
            Text = '1'
            OnChange = E_NumbOfFreqChange
            OnExit = E_NumbOfFreqExit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText53: TStaticText
            Left = 208
            Top = 104
            Width = 63
            Height = 17
            Caption = #1063#1072#1089#1090#1086#1090#1072' '#8470':'
            TabOrder = 11
          end
          object CB_Frequency: TComboBox
            Left = 200
            Top = 128
            Width = 145
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 12
            Text = '1'
            OnChange = CB_FrequencyChange
            OnKeyPress = CB_SignCKeyPress
            Items.Strings = (
              '1')
          end
          object StaticText54: TStaticText
            Left = 384
            Top = 104
            Width = 146
            Height = 17
            Caption = #1062#1077#1085#1090#1088#1072#1083#1100#1085#1072#1103' '#1095#1072#1089#1090#1086#1090#1072' ['#1052#1043#1094']:'
            TabOrder = 13
          end
          object StaticText55: TStaticText
            Left = 32
            Top = 160
            Width = 127
            Height = 17
            Caption = #1050#1086#1101#1092'-'#1090' '#1086#1089#1083#1072#1073#1083#1077#1085#1080#1103' ['#1076#1041']:'
            TabOrder = 14
          end
          object StaticText56: TStaticText
            Left = 208
            Top = 160
            Width = 88
            Height = 17
            Caption = #1057#1076#1074#1080#1075' '#1088#1072#1079#1088#1103#1076#1086#1074':'
            TabOrder = 15
          end
          object CB_Shift: TComboBox
            Left = 200
            Top = 184
            Width = 145
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 16
            Text = '0'
            OnChange = CB_ShiftChange
            OnExit = CB_ShiftChange
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
        object GroupBox1: TGroupBox
          Left = 8
          Top = 231
          Width = 561
          Height = 57
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1055#1086#1076#1072#1074#1083#1077#1085#1080#1077' I-'#1075#1086' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1085#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072'".'
          TabOrder = 3
          object ChB_Command8: TCheckBox
            Left = 24
            Top = 24
            Width = 153
            Height = 17
            Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
            TabOrder = 0
          end
          object CB_Command8: TComboBox
            Left = 200
            Top = 24
            Width = 233
            Height = 21
            ItemHeight = 13
            ItemIndex = 256
            TabOrder = 1
            Text = '0'
            OnChange = CB_Command8Change
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
        object GroupBox2: TGroupBox
          Left = 8
          Top = 294
          Width = 561
          Height = 57
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1055#1086#1076#1072#1074#1083#1077#1085#1080#1077' Q-'#1075#1086' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1085#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072'".'
          TabOrder = 4
          object ChB_Command9: TCheckBox
            Left = 24
            Top = 24
            Width = 153
            Height = 17
            Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
            TabOrder = 0
          end
          object CB_Command9: TComboBox
            Left = 200
            Top = 24
            Width = 233
            Height = 21
            ItemHeight = 13
            ItemIndex = 256
            TabOrder = 1
            Text = '0'
            OnChange = CB_Command9Change
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
    object Tsh_Testing: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
      ImageIndex = 3
      object SB_Data2: TScrollBox
        Left = 0
        Top = 0
        Width = 615
        Height = 361
        VertScrollBar.Range = 1230
        VertScrollBar.Smooth = True
        AutoScroll = False
        BorderStyle = bsNone
        TabOrder = 0
        object GB_Com1: TGroupBox
          Left = 8
          Top = 8
          Width = 561
          Height = 57
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1053#1072#1095#1072#1090#1100' '#1088#1072#1073#1086#1090#1091'"'
          TabOrder = 0
          object CB_Com1: TComboBox
            Left = 24
            Top = 24
            Width = 233
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 0
            Text = #1042#1082#1083'. '#1087#1080#1090#1072#1085#1080#1077' '#1057#1042#1063' '#1091#1089#1080#1083#1080#1090#1077#1083#1077#1081
            OnChange = CB_Com1Change
            Items.Strings = (
              #1042#1082#1083'. '#1087#1080#1090#1072#1085#1080#1077' '#1057#1042#1063' '#1091#1089#1080#1083#1080#1090#1077#1083#1077#1081
              #1042#1099#1082#1083'. '#1087#1080#1090#1072#1085#1080#1077' '#1057#1042#1063' '#1091#1089#1080#1083#1080#1090#1077#1083#1077#1081
              #1055#1080#1090#1072#1085#1080#1077' '#1057#1042#1063' '#1091#1089#1080#1083#1080#1090#1077#1083#1077#1081' '#1085#1077' '#1080#1079#1084#1077#1085#1103#1090#1100)
          end
        end
        object GB_Com3: TGroupBox
          Left = 8
          Top = 72
          Width = 561
          Height = 160
          Caption = 
            #1050#1086#1084#1072#1085#1076#1099' "'#1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1073#1083#1077#1089#1090#1103#1097#1077#1081' '#1090#1086#1095#1082#1080' ('#1041#1058')", "'#1042#1088#1077#1084#1103' '#1079#1072#1076#1077#1088#1078#1082#1080' '#1041#1058'", "' +
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
            Left = 384
            Top = 48
            Width = 58
            Height = 17
            Caption = #1053#1086#1084#1077#1088' '#1041#1058':'
            TabOrder = 1
          end
          object StaticText17: TStaticText
            Left = 32
            Top = 104
            Width = 79
            Height = 17
            Caption = #1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1041#1058':'
            TabOrder = 2
          end
          object E_Com3_0: TEdit
            Left = 200
            Top = 72
            Width = 145
            Height = 21
            TabOrder = 3
            Text = '1'
            OnChange = E_Com3_0Change
            OnExit = E_Com3_0Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object E_Com3: TEdit
            Left = 24
            Top = 128
            Width = 145
            Height = 21
            TabOrder = 4
            Text = '255'
            OnChange = E_Com3Change
            OnExit = E_Com3Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText51: TStaticText
            Left = 208
            Top = 48
            Width = 83
            Height = 17
            Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1041#1058':'
            TabOrder = 5
          end
          object CB_Com3_1: TComboBox
            Left = 376
            Top = 72
            Width = 145
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 6
            Text = '1'
            OnChange = CB_Com3_1Change
            OnKeyPress = CB_SignCKeyPress
            Items.Strings = (
              '1')
          end
          object StaticText19: TStaticText
            Left = 208
            Top = 104
            Width = 131
            Height = 17
            Caption = #1042#1088#1077#1084#1103' '#1079#1072#1076#1077#1088#1078#1082#1080' '#1041#1058' ['#1085#1089']:'
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
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText21: TStaticText
            Left = 384
            Top = 104
            Width = 163
            Height = 17
            Caption = #1044#1086#1087#1083#1077#1088'. '#1089#1076#1074#1080#1075' '#1095#1072#1089#1090#1086#1090#1099' '#1041#1058' ['#1043#1094']:'
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
            ItemHeight = 13
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
            Left = 32
            Top = 48
            Width = 88
            Height = 17
            Caption = #1057#1076#1074#1080#1075' '#1088#1072#1079#1088#1103#1076#1086#1074':'
            TabOrder = 12
          end
          object CB_Shift_: TComboBox
            Left = 24
            Top = 72
            Width = 145
            Height = 21
            ItemHeight = 13
            TabOrder = 13
            Text = '0'
            OnChange = CB_Shift_Change
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
          Left = 8
          Top = 239
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
            ItemHeight = 13
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
          Left = 8
          Top = 303
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
            ItemHeight = 13
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
          Left = 8
          Top = 363
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
            ItemHeight = 13
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
          Left = 8
          Top = 427
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
            ItemHeight = 13
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
          Left = 8
          Top = 492
          Width = 561
          Height = 82
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1050#1086#1076' '#1091#1087#1088#1072#1074#1083#1077#1085#1080#1103' '#1074#1093#1086#1076#1085#1099#1084' '#1087#1088#1077#1089#1077#1083#1077#1082#1090#1086#1088#1086#1084'"'
          TabOrder = 6
          object Label8: TLabel
            Left = 440
            Top = 16
            Width = 110
            Height = 52
            Caption = 
              '1 - 7800...11300 '#1052#1075#1094';'#13#10'2 - 10200...13500 '#1052#1075#1094';'#13#10'3 - 12500...15700' +
              ' '#1052#1075#1094';'#13#10'4 - 14700...18500 '#1052#1075#1094'.'
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
            ItemHeight = 13
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
          Left = 8
          Top = 580
          Width = 561
          Height = 82
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1050#1086#1076' '#1091#1087#1088#1072#1074#1083#1077#1085#1080#1103' '#1074#1099#1093#1086#1076#1085#1099#1084' '#1087#1088#1077#1089#1077#1083#1077#1082#1090#1086#1088#1086#1084'"'
          TabOrder = 7
          object Label9: TLabel
            Left = 440
            Top = 16
            Width = 110
            Height = 52
            Caption = 
              '1 - 7800...11300 '#1052#1075#1094';'#13#10'2 - 10200...13500 '#1052#1075#1094';'#13#10'3 - 12500...15700' +
              ' '#1052#1075#1094';'#13#10'4 - 14700...18500 '#1052#1075#1094'.'
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
            ItemHeight = 13
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
        object GB_Com12: TGroupBox
          Left = 8
          Top = 668
          Width = 561
          Height = 82
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1050#1086#1076' '#1091#1087#1088#1072#1074#1083#1077#1085#1080#1103' '#1073#1083#1086#1082#1086#1084' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1086#1074'"'
          TabOrder = 8
          object ChB_Com12: TCheckBox
            Left = 24
            Top = 48
            Width = 153
            Height = 17
            Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
            TabOrder = 0
          end
          object CB_Com12: TComboBox
            Left = 200
            Top = 48
            Width = 233
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 1
            Text = '11.7'
            OnChange = CB_Com12Change
            Items.Strings = (
              '11.7'
              '14.2')
          end
          object StaticText24: TStaticText
            Left = 200
            Top = 24
            Width = 162
            Height = 17
            Caption = #1063#1072#1089#1090#1086#1090#1072' '#1075#1077#1090#1077#1088#1086#1076#1080#1085#1072' '#1057#1042#1063' ['#1043#1043#1094']:'
            TabOrder = 2
          end
        end
        object GB_Com13: TGroupBox
          Left = 8
          Top = 755
          Width = 561
          Height = 475
          Caption = #1050#1086#1084#1072#1085#1076#1072' "'#1056#1072#1073#1086#1095#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1099' '#1089#1080#1085#1090#1077#1079#1072#1090#1086#1088#1072' '#1087#1083#1072#1090#1099' '#1055#1055#1056#1052'-2. '#1055#1072#1082#1077#1090' 1...8"'
          TabOrder = 9
          object ChB_Com13: TCheckBox
            Left = 24
            Top = 24
            Width = 153
            Height = 17
            Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1099
            TabOrder = 0
          end
          object E_Com13_1: TEdit
            Left = 200
            Top = 48
            Width = 100
            Height = 21
            TabOrder = 1
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText25: TStaticText
            Left = 200
            Top = 24
            Width = 104
            Height = 17
            Caption = '1 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "0"'
            TabOrder = 2
          end
          object E_Com13_2: TEdit
            Left = 320
            Top = 48
            Width = 100
            Height = 21
            TabOrder = 3
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText26: TStaticText
            Left = 320
            Top = 24
            Width = 104
            Height = 17
            Caption = '2 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "0"'
            TabOrder = 4
          end
          object E_Com13_3: TEdit
            Left = 440
            Top = 48
            Width = 100
            Height = 21
            TabOrder = 5
            Text = '200'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText27: TStaticText
            Left = 440
            Top = 24
            Width = 104
            Height = 17
            Caption = '3 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "0"'
            TabOrder = 6
          end
          object StaticText28: TStaticText
            Left = 200
            Top = 80
            Width = 104
            Height = 17
            Caption = '4 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "0"'
            TabOrder = 7
          end
          object E_Com14_1: TEdit
            Left = 200
            Top = 104
            Width = 100
            Height = 21
            TabOrder = 8
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText29: TStaticText
            Left = 320
            Top = 80
            Width = 104
            Height = 17
            Caption = '1 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "1"'
            TabOrder = 9
          end
          object StaticText30: TStaticText
            Left = 440
            Top = 80
            Width = 104
            Height = 17
            Caption = '2 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "1"'
            TabOrder = 10
          end
          object E_Com14_3: TEdit
            Left = 440
            Top = 104
            Width = 100
            Height = 21
            TabOrder = 11
            Text = '128'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText31: TStaticText
            Left = 200
            Top = 136
            Width = 104
            Height = 17
            Caption = '3 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "1"'
            TabOrder = 12
          end
          object E_Com15_1: TEdit
            Left = 200
            Top = 160
            Width = 100
            Height = 21
            TabOrder = 13
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText32: TStaticText
            Left = 320
            Top = 136
            Width = 104
            Height = 17
            Caption = '4 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "1"'
            TabOrder = 14
          end
          object E_Com15_2: TEdit
            Left = 320
            Top = 160
            Width = 100
            Height = 21
            TabOrder = 15
            Text = '8'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText33: TStaticText
            Left = 440
            Top = 136
            Width = 104
            Height = 17
            Caption = '1 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "2"'
            TabOrder = 16
          end
          object E_Com15_3: TEdit
            Left = 440
            Top = 160
            Width = 100
            Height = 21
            TabOrder = 17
            Text = '194'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText34: TStaticText
            Left = 200
            Top = 192
            Width = 104
            Height = 17
            Caption = '2 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "2"'
            TabOrder = 18
          end
          object StaticText35: TStaticText
            Left = 320
            Top = 192
            Width = 104
            Height = 17
            Caption = '3 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "2"'
            TabOrder = 19
          end
          object StaticText36: TStaticText
            Left = 440
            Top = 192
            Width = 104
            Height = 17
            Caption = '4 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "2"'
            TabOrder = 20
          end
          object E_Com16_1: TEdit
            Left = 200
            Top = 216
            Width = 100
            Height = 21
            TabOrder = 21
            Text = '78'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object E_Com16_2: TEdit
            Left = 320
            Top = 216
            Width = 100
            Height = 21
            TabOrder = 22
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object E_Com16_3: TEdit
            Left = 440
            Top = 216
            Width = 100
            Height = 21
            TabOrder = 23
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText37: TStaticText
            Left = 200
            Top = 248
            Width = 104
            Height = 17
            Caption = '1 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "3"'
            TabOrder = 24
          end
          object StaticText38: TStaticText
            Left = 320
            Top = 248
            Width = 104
            Height = 17
            Caption = '2 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "3"'
            TabOrder = 25
          end
          object StaticText39: TStaticText
            Left = 440
            Top = 248
            Width = 104
            Height = 17
            Caption = '3 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "3"'
            TabOrder = 26
          end
          object E_Com17_1: TEdit
            Left = 200
            Top = 272
            Width = 100
            Height = 21
            TabOrder = 27
            Text = '179'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object E_Com17_2: TEdit
            Left = 320
            Top = 272
            Width = 100
            Height = 21
            TabOrder = 28
            Text = '4'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object E_Com17_3: TEdit
            Left = 440
            Top = 272
            Width = 100
            Height = 21
            TabOrder = 29
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText40: TStaticText
            Left = 200
            Top = 304
            Width = 104
            Height = 17
            Caption = '4 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "3"'
            TabOrder = 30
          end
          object E_Com18_1: TEdit
            Left = 200
            Top = 328
            Width = 100
            Height = 21
            TabOrder = 31
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText41: TStaticText
            Left = 320
            Top = 304
            Width = 104
            Height = 17
            Caption = '1 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "4"'
            TabOrder = 32
          end
          object E_Com18_2: TEdit
            Left = 320
            Top = 328
            Width = 100
            Height = 21
            TabOrder = 33
            Text = '36'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText42: TStaticText
            Left = 440
            Top = 304
            Width = 104
            Height = 17
            Caption = '2 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "4"'
            TabOrder = 34
          end
          object E_Com18_3: TEdit
            Left = 440
            Top = 328
            Width = 100
            Height = 21
            TabOrder = 35
            Text = '1'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText43: TStaticText
            Left = 200
            Top = 360
            Width = 104
            Height = 17
            Caption = '3 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "4"'
            TabOrder = 36
          end
          object E_Com19_1: TEdit
            Left = 200
            Top = 384
            Width = 100
            Height = 21
            TabOrder = 37
            Text = '165'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText44: TStaticText
            Left = 320
            Top = 360
            Width = 104
            Height = 17
            Caption = '4 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "4"'
            TabOrder = 38
          end
          object E_Com19_2: TEdit
            Left = 320
            Top = 384
            Width = 100
            Height = 21
            TabOrder = 39
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText45: TStaticText
            Left = 440
            Top = 360
            Width = 104
            Height = 17
            Caption = '1 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "5"'
            TabOrder = 40
          end
          object E_Com19_3: TEdit
            Left = 440
            Top = 384
            Width = 100
            Height = 21
            TabOrder = 41
            Text = '5'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText46: TStaticText
            Left = 200
            Top = 416
            Width = 104
            Height = 17
            Caption = '2 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "5"'
            TabOrder = 42
          end
          object E_Com20_1: TEdit
            Left = 200
            Top = 440
            Width = 100
            Height = 21
            TabOrder = 43
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText47: TStaticText
            Left = 320
            Top = 416
            Width = 104
            Height = 17
            Caption = '3 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "5"'
            TabOrder = 44
          end
          object E_Com20_2: TEdit
            Left = 320
            Top = 440
            Width = 100
            Height = 21
            TabOrder = 45
            Text = '88'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object StaticText48: TStaticText
            Left = 440
            Top = 416
            Width = 104
            Height = 17
            Caption = '4 '#1073#1072#1081#1090' '#1088#1077#1075#1080#1089#1090#1088#1072' "5"'
            TabOrder = 46
          end
          object E_Com20_3: TEdit
            Left = 440
            Top = 440
            Width = 100
            Height = 21
            TabOrder = 47
            Text = '0'
            OnExit = E_Com13_1Exit
            OnKeyPress = E_Command3_0KeyPress
          end
          object GB_Parameters: TGroupBox
            Left = 16
            Top = 136
            Width = 169
            Height = 185
            Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1089#1080#1085#1090#1077#1079#1072#1090#1086#1088#1072
            Color = clBtnFace
            Enabled = False
            ParentColor = False
            TabOrder = 48
            object Label1: TLabel
              Left = 8
              Top = 24
              Width = 117
              Height = 13
              Caption = #1052#1086#1097#1085#1086#1089#1090#1100' '#1085#1072' '#1074#1099#1093#1086#1076#1077' 1'
            end
            object Label3: TLabel
              Left = 8
              Top = 72
              Width = 117
              Height = 13
              Caption = #1052#1086#1097#1085#1086#1089#1090#1100' '#1085#1072' '#1074#1099#1093#1086#1076#1077' 2'
            end
            object Label4: TLabel
              Left = 8
              Top = 120
              Width = 92
              Height = 13
              Caption = #1042#1099#1093#1086#1076#1085#1072#1103' '#1095#1072#1089#1090#1086#1090#1072
            end
            object Label5: TLabel
              Left = 104
              Top = 144
              Width = 21
              Height = 13
              Caption = #1052#1043#1094
            end
            object CB_Output: TComboBox
              Left = 16
              Top = 44
              Width = 65
              Height = 21
              Hint = 'Default=+5'
              Color = clSilver
              ItemHeight = 13
              ItemIndex = 1
              ParentShowHint = False
              ShowHint = True
              TabOrder = 0
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
              Left = 16
              Top = 92
              Width = 65
              Height = 21
              Hint = 'Default=Off'
              Color = clSilver
              ItemHeight = 13
              ItemIndex = 1
              ParentShowHint = False
              ShowHint = True
              TabOrder = 1
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
              Left = 16
              Top = 140
              Width = 81
              Height = 21
              Color = clSilver
              TabOrder = 2
              Text = '1000'
              OnChange = E_OutFreqChange
              OnExit = E_OutFreqExit
              OnKeyPress = E_Command3_0KeyPress
            end
          end
          object RG_param_reg: TRadioGroup
            Left = 16
            Top = 48
            Width = 169
            Height = 81
            Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099'/'#1088#1077#1075#1080#1089#1090#1088#1099
            TabOrder = 49
          end
          object RB_parameters: TRadioButton
            Left = 24
            Top = 72
            Width = 153
            Height = 17
            Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1089#1080#1085#1090#1077#1079#1072#1090#1086#1088#1072
            TabOrder = 50
            OnClick = RB_parametersClick
          end
          object RB_registers: TRadioButton
            Left = 24
            Top = 96
            Width = 153
            Height = 17
            Caption = #1056#1077#1075#1080#1089#1090#1088#1099' '#1089#1080#1085#1090#1077#1079#1072#1090#1086#1088#1072
            Checked = True
            TabOrder = 51
            TabStop = True
            OnClick = RB_registersClick
          end
        end
        object E_Com14_2: TEdit
          Left = 328
          Top = 859
          Width = 100
          Height = 21
          TabOrder = 10
          Text = '201'
          OnExit = E_Com13_1Exit
          OnKeyPress = E_Command3_0KeyPress
        end
      end
    end
    object Tsh_Kalibr: TTabSheet
      Caption = #1063#1072#1089#1090#1086#1090#1085#1072#1103' '#1082#1072#1083#1080#1073#1088#1086#1074#1082#1072' '#1042#1057#1050'-2'
      ImageIndex = 4
      TabVisible = False
    end
    object Sar_invisible: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077' Sar'
      ImageIndex = 3
      TabVisible = False
      object LV_Sar1: TListView
        Left = 0
        Top = 32
        Width = 593
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
            Caption = #1053#1072#1087#1088'-'#1077' '#1087#1086#1083#1105#1090#1072' ['#1075#1088#1072#1076'.]'
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
      object LV_Sar2: TListView
        Left = 0
        Top = 120
        Width = 609
        Height = 57
        Columns = <
          item
            Caption = #1050#1091' '#1091#1089#1080#1083'-'#1083#1103'1 ['#1076#1041']'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1050#1091' '#1091#1089#1080#1083'-'#1083#1103'2 ['#1076#1041']'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = 'f'#1089#1088' '#1092#1080#1083#1100#1090#1088#1072'1 ['#1075#1088#1072#1076'.]'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = 'f'#1089#1088' '#1092#1080#1083#1100#1090#1088#1072'2 ['#1075#1088#1072#1076'.]'
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
        TabOrder = 1
        ViewStyle = vsReport
        OnDblClick = LV_Sar2DblClick
      end
      object LV_Sar3: TListView
        Left = 0
        Top = 208
        Width = 569
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
        TabOrder = 2
        ViewStyle = vsReport
        OnDblClick = LV_Sar3DblClick
      end
      object LV_Sar4: TListView
        Left = 0
        Top = 296
        Width = 593
        Height = 57
        Columns = <
          item
            Caption = #1041#1072#1081#1090'13'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'14'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'15'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'16'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'17'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'18'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'19'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'20'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'21'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'22'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'23'
            Width = -2
            WidthType = (
              -2)
          end
          item
            Caption = #1041#1072#1081#1090'24'
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
        TabOrder = 3
        ViewStyle = vsReport
        OnDblClick = LV_Sar4DblClick
      end
      object StaticText2: TStaticText
        Left = 272
        Top = 8
        Width = 76
        Height = 17
        Caption = #1044#1072#1085#1099#1077' sar '#8470'1'
        TabOrder = 4
      end
      object StaticText5: TStaticText
        Left = 272
        Top = 96
        Width = 76
        Height = 17
        Caption = #1044#1072#1085#1099#1077' sar '#8470'2'
        TabOrder = 5
      end
      object StaticText8: TStaticText
        Left = 272
        Top = 184
        Width = 76
        Height = 17
        Caption = #1044#1072#1085#1099#1077' sar '#8470'3'
        TabOrder = 6
      end
      object StaticText9: TStaticText
        Left = 272
        Top = 272
        Width = 76
        Height = 17
        Caption = #1044#1072#1085#1099#1077' sar '#8470'4'
        TabOrder = 7
      end
    end
    object DataSensors: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1099#1093' '#1076#1072#1090#1095#1080#1082#1086#1074
      ImageIndex = 4
      TabVisible = False
      object B_DataOn: TButton
        Left = 48
        Top = 96
        Width = 81
        Height = 33
        Hint = #1042#1082#1083#1102#1095#1080#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093'|'#1042#1082#1083#1102#1095#1080#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093
        Caption = #1042#1082#1083'. '#1076#1072#1085#1085#1099#1077
        TabOrder = 0
        OnClick = B_DataOnClick
      end
      object B_DataOff: TButton
        Left = 48
        Top = 160
        Width = 81
        Height = 33
        Hint = #1042#1099#1082#1083#1102#1095#1080#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093'|'#1042#1099#1082#1083#1102#1095#1080#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093
        Caption = #1042#1099#1082#1083'. '#1076#1072#1085#1085#1099#1077
        Enabled = False
        TabOrder = 1
        OnClick = B_DataOffClick
      end
      object StaticText1: TStaticText
        Left = 158
        Top = 40
        Width = 163
        Height = 17
        Caption = #1044#1072#1085#1085#1099#1077' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1099#1093' '#1076#1072#1090#1095#1080#1082#1086#1074
        TabOrder = 2
      end
      object P_U5V: TPanel
        Left = 264
        Top = 64
        Width = 105
        Height = 33
        Caption = '0 '#1042
        TabOrder = 3
      end
      object P_U12V: TPanel
        Left = 264
        Top = 96
        Width = 105
        Height = 33
        Caption = '0 '#1042
        TabOrder = 4
      end
      object P_I12V: TPanel
        Left = 264
        Top = 160
        Width = 105
        Height = 33
        Caption = '0 '#1040
        TabOrder = 5
      end
      object P_I5V: TPanel
        Left = 264
        Top = 128
        Width = 105
        Height = 33
        Caption = '0 '#1040
        TabOrder = 6
      end
      object P_Temp: TPanel
        Left = 264
        Top = 192
        Width = 105
        Height = 33
        Caption = #1075#1088#1072#1076'. '#1057
        TabOrder = 7
      end
      object P_Power: TPanel
        Left = 256
        Top = 224
        Width = 113
        Height = 33
        Caption = 'dBm'
        TabOrder = 8
      end
      object P_1: TPanel
        Left = 160
        Top = 64
        Width = 105
        Height = 33
        Hint = '|'#1047#1085#1072#1095#1077#1085#1080#1077' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' '#1080#1089#1090#1086#1095#1085#1080#1082#1072' +5 '#1042
        Caption = 'U '#1080#1089#1090#1086#1095#1085#1080#1082#1072' +5 '#1042
        TabOrder = 9
      end
      object P_2: TPanel
        Left = 160
        Top = 96
        Width = 105
        Height = 33
        Hint = '|'#1047#1085#1072#1095#1077#1085#1080#1077' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' '#1080#1089#1090#1086#1095#1085#1080#1082#1072' +12V'
        Caption = 'U '#1080#1089#1090#1086#1095#1085#1080#1082#1072' +12 '#1042
        TabOrder = 10
      end
      object P_3: TPanel
        Left = 160
        Top = 128
        Width = 105
        Height = 33
        Hint = '|'#1058#1086#1082' '#1087#1086#1090#1088#1077#1073#1083#1077#1085#1080#1103' '#1080#1089#1090#1086#1095#1085#1080#1082#1072' +5V'
        Caption = 'I '#1080#1089#1090#1086#1095#1085#1080#1082#1072' +5 '#1042
        TabOrder = 11
      end
      object P_4: TPanel
        Left = 160
        Top = 160
        Width = 105
        Height = 33
        Hint = '|'#1058#1086#1082' '#1087#1086#1090#1088#1077#1073#1083#1077#1085#1080#1103' '#1080#1089#1090#1086#1095#1085#1080#1082#1072' +12V'
        Caption = 'I '#1080#1089#1090#1086#1095#1085#1080#1082#1072' +12 '#1042
        TabOrder = 12
      end
      object P_5: TPanel
        Left = 160
        Top = 192
        Width = 105
        Height = 33
        Hint = '|'#1058#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '#1086#1082#1088#1091#1078#1072#1102#1097#1077#1081' '#1089#1088#1077#1076#1099
        Caption = 'T '#1089#1088#1077#1076#1099
        TabOrder = 13
      end
      object P_6: TPanel
        Left = 160
        Top = 224
        Width = 105
        Height = 33
        Hint = '|'#1057#1042#1063' '#1084#1086#1097#1085#1086#1089#1090#1100' '#1074' '#1090#1086#1095#1082#1077' '#1042#1057#1050'2'
        Caption = 'P '#1074' '#1090#1086#1095#1082#1077' '#1042#1057#1050'-2'
        TabOrder = 14
      end
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1093
    Height = 33
    Caption = 'ToolBar1'
    Images = ImageList1
    TabOrder = 5
    object ToolButton3: TToolButton
      Left = 0
      Top = 2
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 1
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
      OnClick = TB_LoadBlpClick
    end
    object ToolButton1: TToolButton
      Left = 31
      Top = 2
      Width = 8
      Caption = 'ToolButton1'
      ImageIndex = 7
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
      OnClick = TB_LoadSarClick
    end
    object ToolButton5: TToolButton
      Left = 62
      Top = 2
      Width = 35
      Caption = 'ToolButton5'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object TB_SaveControl: TToolButton
      Left = 97
      Top = 2
      Hint = 
        #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077 +
        #1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      ImageIndex = 2
      OnClick = TB_SaveControlClick
    end
    object ToolButton7: TToolButton
      Left = 120
      Top = 2
      Width = 8
      Caption = 'ToolButton7'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object TB_SaveTesting: TToolButton
      Left = 128
      Top = 2
      Hint = 
        #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' ' +
        #1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
      ImageIndex = 3
      OnClick = TB_SaveTestingClick
    end
    object ToolButton2: TToolButton
      Left = 151
      Top = 2
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object TB_LoadControl: TToolButton
      Left = 159
      Top = 2
      Hint = 
        #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077 +
        #1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Caption = 'TB_LoadControl'
      ImageIndex = 4
      OnClick = TB_LoadControlClick
    end
    object ToolButton4: TToolButton
      Left = 182
      Top = 2
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 5
      Style = tbsSeparator
    end
    object TB_LoadTesting: TToolButton
      Left = 190
      Top = 2
      Hint = 
        #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077'|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083' ' +
        #1088#1077#1079#1091#1083#1100#1090#1072#1090#1086#1074' '#1074' '#1088#1077#1078#1080#1084#1077' '#1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
      Caption = 'TB_LoadTesting'
      ImageIndex = 5
      OnClick = TB_LoadTestingClick
    end
    object ToolButton6: TToolButton
      Left = 213
      Top = 2
      Width = 35
      Caption = 'ToolButton6'
      ImageIndex = 6
      Style = tbsSeparator
    end
    object TB_About: TToolButton
      Left = 248
      Top = 2
      Hint = 
        #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093'|'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1088#1086#1075 +
        #1088#1072#1084#1084#1077', '#1085#1086#1084#1077#1088#1077' '#1074#1077#1088#1089#1080#1080' '#1080' '#1087#1088#1072#1074#1072#1093
      Caption = 'TB_About'
      ImageIndex = 6
      OnClick = TB_AboutClick
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 549
    Width = 1093
    Height = 19
    AutoHint = True
    Panels = <>
    SimplePanel = False
  end
  object RG_Mode: TRadioGroup
    Left = 120
    Top = 32
    Width = 113
    Height = 105
    Caption = #1056#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099
    ItemIndex = 0
    Items.Strings = (
      #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077
      #1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077)
    TabOrder = 7
  end
  object RG_Calibr: TRadioGroup
    Left = 552
    Top = 32
    Width = 97
    Height = 105
    Caption = 'f '#1082#1072#1083#1080#1073#1088'. '#1042#1057#1050'-2'
    TabOrder = 8
  end
  object RB_5GHz: TRadioButton
    Left = 568
    Top = 56
    Width = 73
    Height = 17
    Caption = '5 '#1043#1043#1094
    Checked = True
    TabOrder = 9
    TabStop = True
    OnClick = RB_5GHzClick
  end
  object RB_8GHz: TRadioButton
    Left = 568
    Top = 104
    Width = 73
    Height = 17
    Caption = '8 '#1043#1043#1094
    TabOrder = 10
    OnClick = RB_8GHzClick
  end
  object StaticText3: TStaticText
    Left = 792
    Top = 168
    Width = 80
    Height = 17
    Caption = #1042#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099':'
    TabOrder = 11
  end
  object P_WorkTime: TPanel
    Left = 792
    Top = 184
    Width = 129
    Height = 33
    Hint = #1042#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099'|'#1042#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099
    Caption = '00:00:00'
    TabOrder = 12
  end
  object GB_TCommand: TGroupBox
    Left = 424
    Top = 32
    Width = 121
    Height = 105
    Caption = 'T '#1084'/'#1076' '#1082#1086#1084#1072#1085#1076#1072#1084#1080', '#1084#1089
    TabOrder = 13
    object E_Delay: TEdit
      Left = 8
      Top = 24
      Width = 105
      Height = 21
      TabOrder = 0
      Text = '1'
      OnChange = E_DelayChange
      OnKeyPress = E_Command3_0KeyPress
    end
    object B_EnterDelay: TButton
      Left = 8
      Top = 56
      Width = 105
      Height = 33
      Hint = #1042#1074#1077#1089#1090#1080' '#1089#1086#1086#1073#1097#1077#1085#1080#1077' '#1086#1087#1077#1088#1072#1090#1086#1088#1072'|'#1042#1074#1077#1089#1090#1080' '#1089#1086#1086#1073#1097#1077#1085#1080#1077' '#1086#1087#1077#1088#1072#1090#1086#1088#1072
      Caption = #1042#1074#1077#1089#1090#1080' '#1079#1072#1076#1077#1088#1078#1082#1091
      TabOrder = 1
      OnClick = B_EnterDelayClick
    end
  end
  object GB_AvailableCom: TGroupBox
    Left = 656
    Top = 32
    Width = 233
    Height = 105
    Caption = #1044#1086#1089#1090#1091#1087#1085#1099#1077' Com-'#1087#1086#1088#1090#1099
    TabOrder = 14
    object LB_AvailableCom: TListBox
      Left = 8
      Top = 16
      Width = 121
      Height = 81
      ItemHeight = 13
      TabOrder = 0
    end
    object B_AvailableCom: TButton
      Left = 144
      Top = 64
      Width = 81
      Height = 33
      Caption = #1059#1079#1085#1072#1090#1100
      TabOrder = 1
      OnClick = B_AvailableComClick
    end
  end
  object SystemTimer: TTimer
    Interval = 10
    OnTimer = SystemTimerTimer
    Left = 744
    Top = 184
  end
  object SaveDialog: TSaveDialog
    Left = 832
    Top = 136
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'blp'
    Filter = #1076#1072#1085#1085#1099#1077' '#1041#1058' (*.blp)|*.blp'
    Title = #1054#1090#1082#1088#1099#1090#1080#1077' '#1092#1072#1081#1083#1072' '#1076#1072#1085#1085#1099#1093' '#1041#1058
    Left = 768
    Top = 136
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'sar'
    Filter = #1076#1072#1085#1085#1099#1077' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103' (*.sar)|*.sar'
    Title = #1054#1090#1082#1088#1099#1090#1080#1077' '#1092#1072#1081#1083#1072' '#1076#1072#1085#1085#1099#1093' '#1056#1051#1057' '#1080' '#1084#1086#1076#1091#1083#1103
    Left = 800
    Top = 136
  end
  object ImageList1: TImageList
    Left = 864
    Top = 136
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
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
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
    Left = 896
    Top = 136
  end
  object NIDAQmxTimer: TTimer
    Enabled = False
    Interval = 50
    OnTimer = NIDAQmxTimerTimer
    Left = 736
    Top = 136
  end
  object MainMenu: TMainMenu
    Left = 704
    Top = 136
    object File: TMenuItem
      Caption = #1060#1072#1081#1083
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
        OnClick = TB_LoadTestingClick
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Exit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        Hint = #1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099'|'#1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
        OnClick = ExitClick
      end
    end
    object Help: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object HelpAboutProg: TMenuItem
        Caption = #1055#1086#1084#1086#1097#1100
        OnClick = HelpAboutProgClick
      end
      object HelpAboutItem: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = TB_AboutClick
      end
    end
  end
  object WorkTimer: TTimer
    Enabled = False
    OnTimer = WorkTimerTimer
    Left = 888
    Top = 184
  end
end
