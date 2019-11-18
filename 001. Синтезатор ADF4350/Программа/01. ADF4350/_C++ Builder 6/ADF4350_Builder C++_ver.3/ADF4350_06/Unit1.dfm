object Form1: TForm1
  Left = 296
  Top = 148
  AutoScroll = False
  Caption = 'ADF4350'
  ClientHeight = 471
  ClientWidth = 632
  Color = clBtnFace
  Constraints.MaxHeight = 505
  Constraints.MaxWidth = 640
  Constraints.MinHeight = 505
  Constraints.MinWidth = 640
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label13: TLabel
    Left = 512
    Top = 16
    Width = 34
    Height = 13
    Caption = 'Ver 3.1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label14: TLabel
    Left = 512
    Top = 32
    Width = 71
    Height = 13
    Caption = 'February, 2014'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clDefault
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label15: TLabel
    Left = 10
    Top = 452
    Width = 3
    Height = 13
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Reference: TGroupBox
    Left = 8
    Top = 8
    Width = 169
    Height = 123
    Caption = 'Reference'
    TabOrder = 0
    object Edit2: TEdit
      Left = 64
      Top = 24
      Width = 65
      Height = 21
      BiDiMode = bdLeftToRight
      ParentBiDiMode = False
      TabOrder = 0
      Text = '10'
      OnChange = Edit2Change
    end
    object StaticText1: TStaticText
      Left = 136
      Top = 24
      Width = 26
      Height = 17
      Caption = 'MHz'
      TabOrder = 1
    end
    object StaticText2: TStaticText
      Left = 8
      Top = 24
      Width = 54
      Height = 17
      Caption = 'Frequency'
      TabOrder = 2
    end
    object Edit1: TEdit
      Left = 64
      Top = 88
      Width = 65
      Height = 21
      BiDiMode = bdLeftToRight
      ParentBiDiMode = False
      TabOrder = 3
      Text = '1'
      OnChange = Edit1Change
    end
  end
  object OtherOptions: TGroupBox
    Left = 8
    Top = 133
    Width = 610
    Height = 69
    Caption = 'Other Options'
    ParentShowHint = False
    ShowHint = False
    TabOrder = 1
    object RB_ADF_filters: TRadioButton
      Left = 488
      Top = 24
      Width = 113
      Height = 17
      Caption = 'ADF4350 + Filters'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RB_ADF_filtersClick
    end
    object RB_Parallel_lines: TRadioButton
      Left = 488
      Top = 40
      Width = 113
      Height = 17
      Caption = 'Parallel lines'
      TabOrder = 1
      OnClick = RB_Parallel_linesClick
    end
  end
  object Button7: TButton
    Left = 112
    Top = 153
    Width = 81
    Height = 32
    Caption = 'Register 2'
    TabOrder = 2
    OnClick = Button7Click
  end
  object Button9: TButton
    Left = 16
    Top = 153
    Width = 81
    Height = 32
    Caption = 'Register 1'
    TabOrder = 3
    OnClick = Button9Click
  end
  object Button5: TButton
    Left = 304
    Top = 153
    Width = 81
    Height = 32
    Caption = 'Register 4'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button10: TButton
    Left = 208
    Top = 153
    Width = 81
    Height = 32
    Caption = 'Register 3'
    TabOrder = 5
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 400
    Top = 153
    Width = 81
    Height = 32
    Caption = 'Register 5'
    TabOrder = 6
    OnClick = Button11Click
  end
  object GroupBox1: TGroupBox
    Left = 184
    Top = 8
    Width = 153
    Height = 123
    Caption = 'Outputs'
    TabOrder = 7
    object StaticText5: TStaticText
      Left = 32
      Top = 18
      Width = 19
      Height = 17
      Caption = 'Icp'
      TabOrder = 0
    end
    object StaticText6: TStaticText
      Left = 128
      Top = 18
      Width = 19
      Height = 17
      Caption = 'mA'
      TabOrder = 1
    end
    object ComboBox3: TComboBox
      Left = 56
      Top = 41
      Width = 65
      Height = 21
      Hint = 'Default=+5'
      ItemHeight = 13
      ItemIndex = 1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      Text = '-4'
      OnChange = ComboBox3Change
      Items.Strings = (
        'Off'
        '-4'
        '-1'
        '+2'
        '+5')
    end
    object StaticText7: TStaticText
      Left = 16
      Top = 41
      Width = 36
      Height = 17
      Caption = 'Output'
      TabOrder = 3
    end
    object StaticText8: TStaticText
      Left = 16
      Top = 66
      Width = 39
      Height = 17
      Caption = 'AuxOut'
      TabOrder = 4
    end
    object ComboBox4: TComboBox
      Left = 56
      Top = 66
      Width = 65
      Height = 21
      Hint = 'Default=Off'
      ItemHeight = 13
      ItemIndex = 1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      Text = '-4'
      OnChange = ComboBox4Change
      Items.Strings = (
        'Off'
        '-4'
        '-1'
        '+2'
        '+5')
    end
    object StaticText9: TStaticText
      Left = 8
      Top = 89
      Width = 46
      Height = 17
      Caption = 'MUX out'
      TabOrder = 6
    end
    object ComboBox5: TComboBox
      Left = 56
      Top = 89
      Width = 89
      Height = 21
      Hint = 'Default=Three-State Output'
      ItemHeight = 13
      ParentShowHint = False
      ShowHint = True
      TabOrder = 7
      Text = 'Three-State Output'
      OnChange = ComboBox5Change
      Items.Strings = (
        'Three-State Output'
        'DVdd'
        'DGN'#1042
        'R Divider Output'
        'N Divider Output'
        'Analog Lock Detect'
        'Digital Lock Detect'
        'Reserved')
    end
  end
  object GroupBox2: TGroupBox
    Left = 344
    Top = 8
    Width = 153
    Height = 123
    Caption = 'Options'
    TabOrder = 8
    object RadioButton3: TRadioButton
      Left = 16
      Top = 18
      Width = 97
      Height = 16
      Caption = 'Low Spur Mode'
      TabOrder = 0
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 16
      Top = 41
      Width = 105
      Height = 18
      Caption = 'Low Noise Mode'
      Checked = True
      TabOrder = 1
      TabStop = True
      OnClick = RadioButton4Click
    end
    object CheckBox3: TCheckBox
      Left = 16
      Top = 70
      Width = 121
      Height = 17
      Caption = 'Cycle Slip Reduction'
      TabOrder = 2
      OnClick = CheckBox3Click
    end
    object CheckBox6: TCheckBox
      Left = 16
      Top = 94
      Width = 81
      Height = 17
      Caption = 'Fast Lock'
      TabOrder = 3
      OnClick = CheckBox6Click
    end
  end
  object ComboBox1: TComboBox
    Left = 72
    Top = 64
    Width = 65
    Height = 21
    Hint = 'Default=1'
    ItemHeight = 13
    ParentShowHint = False
    ShowHint = True
    TabOrder = 9
    Text = '1'
    OnChange = ComboBox1Change
    Items.Strings = (
      '/2'
      '1'
      'x2')
  end
  object StaticText3: TStaticText
    Left = 16
    Top = 64
    Width = 44
    Height = 17
    Caption = '/2, 1, x2'
    TabOrder = 10
  end
  object StaticText4: TStaticText
    Left = 16
    Top = 96
    Width = 54
    Height = 17
    Caption = 'Divider (R)'
    TabOrder = 11
  end
  object ComboBox2: TComboBox
    Left = 240
    Top = 25
    Width = 65
    Height = 21
    Hint = 'Default=2.5'
    ItemHeight = 13
    ItemIndex = 7
    ParentShowHint = False
    ShowHint = True
    TabOrder = 12
    Text = '2.50'
    OnChange = ComboBox2Change
    Items.Strings = (
      '0.31'
      '0.63'
      '0.94'
      '1.25'
      '1.56'
      '1.88'
      '2.19'
      '2.50'
      '2.81'
      '3.13'
      '3.44'
      '3.75'
      '4.06'
      '4.38'
      '4.69'
      '5.00')
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 205
    Width = 265
    Height = 177
    Caption = 'Output Frequency'
    TabOrder = 13
    object RadioButton1: TRadioButton
      Left = 32
      Top = 24
      Width = 73
      Height = 17
      Caption = 'Activate f1'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 32
      Top = 48
      Width = 73
      Height = 17
      Caption = 'Activate f2'
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object Edit3: TEdit
      Left = 112
      Top = 16
      Width = 81
      Height = 21
      TabOrder = 2
      Text = '1000'
      OnChange = Edit3Change
    end
    object Edit4: TEdit
      Left = 112
      Top = 40
      Width = 81
      Height = 21
      TabOrder = 3
      Text = '1001'
      OnChange = Edit4Change
    end
    object StaticText11: TStaticText
      Left = 16
      Top = 72
      Width = 85
      Height = 17
      Caption = 'Channel Spacing'
      TabOrder = 4
    end
    object Edit5: TEdit
      Left = 112
      Top = 64
      Width = 81
      Height = 21
      TabOrder = 5
      Text = '100'
      OnChange = Edit5Change
    end
    object StaticText12: TStaticText
      Left = 200
      Top = 24
      Width = 26
      Height = 17
      Caption = 'MHz'
      TabOrder = 6
    end
    object StaticText13: TStaticText
      Left = 200
      Top = 48
      Width = 26
      Height = 17
      Caption = 'MHz'
      TabOrder = 7
    end
    object StaticText14: TStaticText
      Left = 200
      Top = 72
      Width = 23
      Height = 17
      Caption = 'kHz'
      TabOrder = 8
    end
    object Button1: TButton
      Left = 232
      Top = 16
      Width = 25
      Height = 33
      Caption = '+'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 232
      Top = 48
      Width = 25
      Height = 33
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = Button2Click
    end
    object GroupBox4: TGroupBox
      Left = 8
      Top = 96
      Width = 249
      Height = 73
      Caption = 'Dynamic'
      TabOrder = 11
      object StaticText15: TStaticText
        Left = 8
        Top = 24
        Width = 92
        Height = 17
        Caption = 'Approximate Delay'
        TabOrder = 0
      end
      object Edit6: TEdit
        Left = 104
        Top = 16
        Width = 81
        Height = 21
        TabOrder = 1
        Text = '250'
        OnChange = Edit6Change
      end
      object StaticText16: TStaticText
        Left = 192
        Top = 24
        Width = 17
        Height = 17
        Caption = 'ms'
        TabOrder = 2
      end
      object RadioButton5: TRadioButton
        Left = 32
        Top = 48
        Width = 49
        Height = 17
        Caption = 'Stop'
        Checked = True
        TabOrder = 3
        TabStop = True
        OnClick = RadioButton5Click
      end
      object RadioButton6: TRadioButton
        Left = 104
        Top = 48
        Width = 73
        Height = 17
        Caption = 'Alternate'
        TabOrder = 4
        OnClick = RadioButton6Click
      end
      object RadioButton7: TRadioButton
        Left = 176
        Top = 48
        Width = 65
        Height = 17
        Caption = 'Sweep'
        TabOrder = 5
        OnClick = RadioButton7Click
      end
    end
  end
  object GroupBox5: TGroupBox
    Left = 280
    Top = 205
    Width = 337
    Height = 137
    Caption = 'Settings'
    TabOrder = 14
    object Label2: TLabel
      Left = 8
      Top = 40
      Width = 136
      Height = 13
      Caption = 'VCO Frequency = 4000 MHz'
    end
    object Label3: TLabel
      Left = 8
      Top = 56
      Width = 73
      Height = 13
      Caption = 'Prescaler = 8/9'
    end
    object Label4: TLabel
      Left = 8
      Top = 72
      Width = 90
      Height = 13
      Caption = 'Output Devider = 4'
    end
    object Label5: TLabel
      Left = 8
      Top = 88
      Width = 161
      Height = 13
      Caption = 'VCO Channel Spacing = 400 kHz '
    end
    object Label6: TLabel
      Left = 8
      Top = 104
      Width = 123
      Height = 13
      Caption = 'PFD Frequency = 10 MHz'
    end
    object Label7: TLabel
      Left = 240
      Top = 24
      Width = 48
      Height = 13
      Caption = 'INT = 400'
    end
    object Label8: TLabel
      Left = 240
      Top = 40
      Width = 46
      Height = 13
      Caption = 'FRAC = 0'
    end
    object Label9: TLabel
      Left = 240
      Top = 56
      Width = 49
      Height = 13
      Caption = 'MOD = 25'
    end
    object Label10: TLabel
      Left = 240
      Top = 72
      Width = 26
      Height = 13
      Caption = 'R = 1'
    end
    object Label11: TLabel
      Left = 240
      Top = 88
      Width = 58
      Height = 13
      Caption = 'Clk Div = 80'
    end
    object Label12: TLabel
      Left = 240
      Top = 104
      Width = 48
      Height = 13
      Caption = 'Phase = 1'
    end
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 146
      Height = 13
      Caption = 'Output Frequency = 1000 MHz'
    end
  end
  object Button3: TButton
    Left = 408
    Top = 349
    Width = 81
    Height = 33
    Caption = 'REGISTER'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = Button3Click
  end
  object StaticText17: TStaticText
    Left = 504
    Top = 100
    Width = 116
    Height = 31
    Cursor = crHandPoint
    Caption = '   eliasum  '
    Color = clBlue
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWhite
    Font.Height = -19
    Font.Name = 'Arial Black'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 16
    OnDblClick = StaticText17DblClick
  end
  object GroupBox6: TGroupBox
    Left = 8
    Top = 384
    Width = 609
    Height = 64
    Caption = 'Com Port Configuration'
    TabOrder = 17
    object Label16: TLabel
      Left = 8
      Top = 16
      Width = 24
      Height = 13
      Caption = 'Com:'
    end
    object Label17: TLabel
      Left = 81
      Top = 16
      Width = 54
      Height = 13
      Caption = 'Baud Rate:'
    end
    object SendDirect: TLabel
      Left = 8
      Top = 40
      Width = 140
      Height = 13
      Caption = 'Send direction: to Synthesizer'
    end
    object PB_proc: TProgressBar
      Left = 202
      Top = 16
      Width = 399
      Height = 33
      Min = 0
      Max = 127
      Smooth = True
      TabOrder = 0
    end
    object CB_ComNum: TComboBox
      Left = 40
      Top = 16
      Width = 33
      Height = 21
      ItemHeight = 13
      TabOrder = 1
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
      Left = 139
      Top = 16
      Width = 57
      Height = 21
      ItemHeight = 13
      TabOrder = 2
      Text = '2400'
      OnChange = CB_BaudRateChange
      Items.Strings = (
        '2400'
        '9600')
    end
  end
  object B_Open: TPanel
    Left = 536
    Top = 349
    Width = 81
    Height = 33
    BevelInner = bvRaised
    Caption = 'START'
    Color = 8486399
    TabOrder = 18
    OnMouseDown = B_OpenMouseDown
    OnMouseUp = B_OpenMouseUp
  end
  object Button4: TButton
    Left = 280
    Top = 349
    Width = 81
    Height = 33
    Caption = 'IF Control'
    TabOrder = 19
    OnClick = Button4Click
  end
  object Timer1: TTimer
    Interval = 0
    OnTimer = Timer1Timer
    Left = 8
    Top = 216
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 150
    OnTimer = Timer2Timer
    Left = 248
    Top = 400
  end
  object CommPort1: TCommPort
    ComNumber = 1
    InSize = 2048
    OutSize = 4096
    Baud = 2400
    BaudRate = cbr2400
    DataBits = 8
    MonitorEvents = [evRxChar, evTxEmpty, evCTS, evDSR, evRlsd, evBreak, evError, evRing]
    XoffLim = 1024
    XonChar = #17
    XoffChar = #19
    OnOpen = CommPort1Open
    OnClose = CommPort1Close
    Left = 208
    Top = 400
  end
  object Timer3: TTimer
    Interval = 500
    OnTimer = Timer3Timer
    Left = 512
    Top = 352
  end
end
