object Form1: TForm1
  Left = 456
  Top = 148
  Width = 778
  Height = 617
  Caption = 'ADF4350'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label13: TLabel
    Left = 630
    Top = 20
    Width = 41
    Height = 16
    Caption = 'Ver 3.0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label14: TLabel
    Left = 630
    Top = 39
    Width = 98
    Height = 16
    Caption = 'November, 2013'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clDefault
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label15: TLabel
    Left = 12
    Top = 556
    Width = 3
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Reference: TGroupBox
    Left = 10
    Top = 10
    Width = 208
    Height = 151
    Caption = 'Reference'
    TabOrder = 0
    object Edit2: TEdit
      Left = 79
      Top = 30
      Width = 80
      Height = 24
      BiDiMode = bdLeftToRight
      ParentBiDiMode = False
      TabOrder = 0
      Text = '10'
      OnChange = Edit2Change
    end
    object StaticText1: TStaticText
      Left = 167
      Top = 30
      Width = 31
      Height = 20
      Caption = 'MHz'
      TabOrder = 1
    end
    object StaticText2: TStaticText
      Left = 10
      Top = 30
      Width = 68
      Height = 20
      Caption = 'Frequency'
      TabOrder = 2
    end
    object Edit1: TEdit
      Left = 79
      Top = 108
      Width = 80
      Height = 24
      BiDiMode = bdLeftToRight
      ParentBiDiMode = False
      TabOrder = 3
      Text = '1'
      OnChange = Edit1Change
    end
  end
  object OtherOptions: TGroupBox
    Left = 10
    Top = 164
    Width = 751
    Height = 85
    Caption = 'Other Options'
    ParentShowHint = False
    ShowHint = False
    TabOrder = 1
  end
  object Button7: TButton
    Left = 197
    Top = 188
    Width = 100
    Height = 40
    Caption = 'Register 2'
    TabOrder = 2
    OnClick = Button7Click
  end
  object Button9: TButton
    Left = 59
    Top = 188
    Width = 100
    Height = 40
    Caption = 'Register 1'
    TabOrder = 3
    OnClick = Button9Click
  end
  object Button5: TButton
    Left = 473
    Top = 188
    Width = 99
    Height = 40
    Caption = 'Register 4'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button10: TButton
    Left = 335
    Top = 188
    Width = 99
    Height = 40
    Caption = 'Register 3'
    TabOrder = 5
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 610
    Top = 188
    Width = 100
    Height = 40
    Caption = 'Register 5'
    TabOrder = 6
    OnClick = Button11Click
  end
  object GroupBox1: TGroupBox
    Left = 226
    Top = 10
    Width = 189
    Height = 151
    Caption = 'Outputs'
    TabOrder = 7
    object StaticText5: TStaticText
      Left = 39
      Top = 22
      Width = 22
      Height = 20
      Caption = 'Icp'
      TabOrder = 0
    end
    object StaticText6: TStaticText
      Left = 158
      Top = 22
      Width = 24
      Height = 20
      Caption = 'mA'
      TabOrder = 1
    end
    object ComboBox3: TComboBox
      Left = 69
      Top = 51
      Width = 80
      Height = 24
      Hint = 'Default=+5'
      ItemHeight = 16
      ItemIndex = 4
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      Text = '+5'
      OnChange = ComboBox3Change
      Items.Strings = (
        'Off'
        '-4'
        '-1'
        '+2'
        '+5')
    end
    object StaticText7: TStaticText
      Left = 20
      Top = 51
      Width = 42
      Height = 20
      Caption = 'Output'
      TabOrder = 3
    end
    object StaticText8: TStaticText
      Left = 20
      Top = 81
      Width = 46
      Height = 20
      Caption = 'AuxOut'
      TabOrder = 4
    end
    object ComboBox4: TComboBox
      Left = 69
      Top = 81
      Width = 80
      Height = 24
      Hint = 'Default=Off'
      ItemHeight = 16
      ItemIndex = 0
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      Text = 'Off'
      OnChange = ComboBox4Change
      Items.Strings = (
        'Off'
        '-4'
        '-1'
        '+2'
        '+5')
    end
    object StaticText9: TStaticText
      Left = 10
      Top = 110
      Width = 54
      Height = 20
      Caption = 'MUX out'
      TabOrder = 6
    end
    object ComboBox5: TComboBox
      Left = 69
      Top = 110
      Width = 109
      Height = 24
      Hint = 'Default=Three-State Output'
      ItemHeight = 16
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
    Left = 423
    Top = 10
    Width = 189
    Height = 151
    Caption = 'Options'
    TabOrder = 8
    object RadioButton3: TRadioButton
      Left = 20
      Top = 22
      Width = 119
      Height = 20
      Caption = 'Low Spur Mode'
      TabOrder = 0
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 20
      Top = 51
      Width = 129
      Height = 21
      Caption = 'Low Noise Mode'
      Checked = True
      TabOrder = 1
      TabStop = True
      OnClick = RadioButton4Click
    end
    object CheckBox3: TCheckBox
      Left = 20
      Top = 86
      Width = 149
      Height = 21
      Caption = 'Cycle Slip Reduction'
      TabOrder = 2
      OnClick = CheckBox3Click
    end
    object CheckBox6: TCheckBox
      Left = 20
      Top = 116
      Width = 99
      Height = 21
      Caption = 'Fast Lock'
      TabOrder = 3
      OnClick = CheckBox6Click
    end
  end
  object ComboBox1: TComboBox
    Left = 89
    Top = 79
    Width = 80
    Height = 24
    Hint = 'Default=1'
    ItemHeight = 16
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
    Left = 20
    Top = 79
    Width = 47
    Height = 20
    Caption = '/2, 1, x2'
    TabOrder = 10
  end
  object StaticText4: TStaticText
    Left = 20
    Top = 118
    Width = 68
    Height = 20
    Caption = 'Divider (R)'
    TabOrder = 11
  end
  object ComboBox2: TComboBox
    Left = 295
    Top = 31
    Width = 80
    Height = 24
    Hint = 'Default=2.5'
    ItemHeight = 16
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
    Left = 10
    Top = 252
    Width = 326
    Height = 218
    Caption = 'Output Frequency'
    TabOrder = 13
    object RadioButton1: TRadioButton
      Left = 39
      Top = 30
      Width = 90
      Height = 20
      Caption = 'Activate f1'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 39
      Top = 59
      Width = 90
      Height = 21
      Caption = 'Activate f2'
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object Edit3: TEdit
      Left = 138
      Top = 20
      Width = 100
      Height = 24
      TabOrder = 2
      Text = '1000'
      OnChange = Edit3Change
    end
    object Edit4: TEdit
      Left = 138
      Top = 49
      Width = 100
      Height = 24
      TabOrder = 3
      Text = '1001'
      OnChange = Edit4Change
    end
    object StaticText11: TStaticText
      Left = 20
      Top = 89
      Width = 106
      Height = 20
      Caption = 'Channel Spacing'
      TabOrder = 4
    end
    object Edit5: TEdit
      Left = 138
      Top = 79
      Width = 100
      Height = 24
      TabOrder = 5
      Text = '100'
      OnChange = Edit5Change
    end
    object StaticText12: TStaticText
      Left = 246
      Top = 30
      Width = 31
      Height = 20
      Caption = 'MHz'
      TabOrder = 6
    end
    object StaticText13: TStaticText
      Left = 246
      Top = 59
      Width = 31
      Height = 20
      Caption = 'MHz'
      TabOrder = 7
    end
    object StaticText14: TStaticText
      Left = 246
      Top = 89
      Width = 27
      Height = 20
      Caption = 'kHz'
      TabOrder = 8
    end
    object Button1: TButton
      Left = 286
      Top = 20
      Width = 30
      Height = 40
      Caption = '+'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 286
      Top = 59
      Width = 30
      Height = 41
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = Button2Click
    end
    object GroupBox4: TGroupBox
      Left = 10
      Top = 118
      Width = 306
      Height = 90
      Caption = 'Dynamic'
      TabOrder = 11
      object StaticText15: TStaticText
        Left = 10
        Top = 30
        Width = 119
        Height = 20
        Caption = 'Approximate Delay'
        TabOrder = 0
      end
      object Edit6: TEdit
        Left = 128
        Top = 20
        Width = 100
        Height = 24
        TabOrder = 1
        Text = '250'
        OnChange = Edit6Change
      end
      object StaticText16: TStaticText
        Left = 236
        Top = 30
        Width = 22
        Height = 20
        Caption = 'ms'
        TabOrder = 2
      end
      object RadioButton5: TRadioButton
        Left = 39
        Top = 59
        Width = 61
        Height = 21
        Caption = 'Stop'
        Checked = True
        TabOrder = 3
        TabStop = True
        OnClick = RadioButton5Click
      end
      object RadioButton6: TRadioButton
        Left = 128
        Top = 59
        Width = 90
        Height = 21
        Caption = 'Alternate'
        TabOrder = 4
        OnClick = RadioButton6Click
      end
      object RadioButton7: TRadioButton
        Left = 217
        Top = 59
        Width = 80
        Height = 21
        Caption = 'Sweep'
        TabOrder = 5
        OnClick = RadioButton7Click
      end
    end
  end
  object GroupBox5: TGroupBox
    Left = 345
    Top = 252
    Width = 414
    Height = 169
    Caption = 'Settings'
    TabOrder = 14
    object Label2: TLabel
      Left = 10
      Top = 49
      Width = 166
      Height = 16
      Caption = 'VCO Frequency = 4000 MHz'
    end
    object Label3: TLabel
      Left = 10
      Top = 69
      Width = 89
      Height = 16
      Caption = 'Prescaler = 4/5'
    end
    object Label4: TLabel
      Left = 10
      Top = 89
      Width = 109
      Height = 16
      Caption = 'Output Devider = 4'
    end
    object Label5: TLabel
      Left = 10
      Top = 108
      Width = 196
      Height = 16
      Caption = 'VCO Channel Spacing = 400 kHz '
    end
    object Label6: TLabel
      Left = 10
      Top = 128
      Width = 151
      Height = 16
      Caption = 'PFD Frequency = 10 MHz'
    end
    object Label7: TLabel
      Left = 295
      Top = 30
      Width = 56
      Height = 16
      Caption = 'INT = 400'
    end
    object Label8: TLabel
      Left = 295
      Top = 49
      Width = 56
      Height = 16
      Caption = 'FRAC = 0'
    end
    object Label9: TLabel
      Left = 295
      Top = 69
      Width = 58
      Height = 16
      Caption = 'MOD = 25'
    end
    object Label10: TLabel
      Left = 295
      Top = 89
      Width = 30
      Height = 16
      Caption = 'R = 1'
    end
    object Label11: TLabel
      Left = 295
      Top = 108
      Width = 69
      Height = 16
      Caption = 'Clk Div = 80'
    end
    object Label12: TLabel
      Left = 295
      Top = 128
      Width = 59
      Height = 16
      Caption = 'Phase = 1'
    end
    object Label1: TLabel
      Left = 10
      Top = 30
      Width = 176
      Height = 16
      Caption = 'Output Frequency = 1000 MHz'
    end
  end
  object Button3: TButton
    Left = 502
    Top = 430
    Width = 100
    Height = 40
    Caption = 'REGISTER'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = Button3Click
  end
  object StaticText17: TStaticText
    Left = 620
    Top = 123
    Width = 142
    Height = 36
    Cursor = crHandPoint
    Caption = '   eliasum  '
    Color = clBlue
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWhite
    Font.Height = -23
    Font.Name = 'Arial Black'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 16
    OnDblClick = StaticText17DblClick
  end
  object GroupBox6: TGroupBox
    Left = 10
    Top = 472
    Width = 749
    Height = 79
    Caption = 'Com Port Configuration'
    TabOrder = 17
    object Label16: TLabel
      Left = 10
      Top = 20
      Width = 31
      Height = 16
      Caption = 'Com:'
    end
    object Label17: TLabel
      Left = 100
      Top = 20
      Width = 67
      Height = 16
      Caption = 'Baud Rate:'
    end
    object SendDirect: TLabel
      Left = 10
      Top = 49
      Width = 175
      Height = 16
      Caption = 'Send direction: to Synthesizer'
    end
    object PB_proc: TProgressBar
      Left = 248
      Top = 20
      Width = 492
      Height = 40
      Min = 0
      Max = 127
      Smooth = True
      TabOrder = 0
    end
    object CB_ComNum: TComboBox
      Left = 49
      Top = 20
      Width = 41
      Height = 24
      ItemHeight = 16
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
      Left = 171
      Top = 20
      Width = 70
      Height = 24
      ItemHeight = 16
      TabOrder = 2
      Text = '2400'
      OnChange = CB_BaudRateChange
      Items.Strings = (
        '2400'
        '9600')
    end
  end
  object B_Open: TPanel
    Left = 660
    Top = 430
    Width = 99
    Height = 40
    BevelInner = bvRaised
    Caption = 'START'
    Color = 8486399
    TabOrder = 18
    OnMouseDown = B_OpenMouseDown
    OnMouseUp = B_OpenMouseUp
  end
  object Button4: TButton
    Left = 345
    Top = 430
    Width = 99
    Height = 40
    Caption = 'IF Control'
    TabOrder = 19
    OnClick = Button4Click
  end
  object Timer1: TTimer
    Interval = 0
    OnTimer = Timer1Timer
    Left = 16
    Top = 280
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 150
    OnTimer = Timer2Timer
    Left = 224
    Top = 520
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
    Left = 192
    Top = 520
  end
  object Timer3: TTimer
    Interval = 500
    OnTimer = Timer3Timer
    Left = 632
    Top = 432
  end
end
