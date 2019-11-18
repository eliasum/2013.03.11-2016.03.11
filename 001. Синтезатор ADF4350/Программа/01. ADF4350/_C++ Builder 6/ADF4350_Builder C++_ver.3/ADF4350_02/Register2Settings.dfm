object Form5: TForm5
  Left = 159
  Top = 238
  Width = 707
  Height = 228
  Caption = 'Register 2 Settings'
  Color = clBtnFace
  Constraints.MaxHeight = 228
  Constraints.MaxWidth = 707
  Constraints.MinHeight = 228
  Constraints.MinWidth = 707
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 209
    Height = 113
    Caption = 'Lock Detect'
    TabOrder = 0
    object ComboBox1: TComboBox
      Left = 64
      Top = 24
      Width = 73
      Height = 21
      Hint = 'Default=FRAC-N'
      ItemHeight = 13
      ItemIndex = 0
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      Text = 'FRAC-N'
      OnChange = ComboBox1Change
      Items.Strings = (
        'FRAC-N'
        'INT-N')
    end
    object StaticText1: TStaticText
      Left = 24
      Top = 24
      Width = 24
      Height = 17
      Caption = 'LDF'
      TabOrder = 1
    end
    object StaticText2: TStaticText
      Left = 24
      Top = 64
      Width = 25
      Height = 17
      Caption = 'LDP'
      TabOrder = 2
    end
    object ComboBox2: TComboBox
      Left = 64
      Top = 64
      Width = 73
      Height = 21
      Hint = 'Default=6ns'
      ItemHeight = 13
      ItemIndex = 1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      Text = '6ns'
      OnChange = ComboBox2Change
      Items.Strings = (
        '10ns'
        '6ns')
    end
  end
  object GroupBox2: TGroupBox
    Left = 240
    Top = 8
    Width = 209
    Height = 113
    Caption = 'Charge Pump'
    TabOrder = 1
    object ComboBox3: TComboBox
      Left = 88
      Top = 24
      Width = 73
      Height = 21
      Hint = 'Default=Positive'
      ItemHeight = 13
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      Text = 'Positive'
      OnChange = ComboBox3Change
      Items.Strings = (
        'Negative'
        'Positive')
    end
    object StaticText3: TStaticText
      Left = 16
      Top = 16
      Width = 18
      Height = 17
      Caption = 'CP'
      TabOrder = 1
    end
    object StaticText4: TStaticText
      Left = 16
      Top = 56
      Width = 18
      Height = 17
      Caption = 'CP'
      TabOrder = 2
    end
    object ComboBox4: TComboBox
      Left = 88
      Top = 64
      Width = 73
      Height = 21
      Hint = 'Default=Disabled'
      ItemHeight = 13
      ItemIndex = 0
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      Text = 'Disabled'
      OnChange = ComboBox4Change
      Items.Strings = (
        'Disabled'
        'Enabled')
    end
    object StaticText5: TStaticText
      Left = 16
      Top = 32
      Width = 38
      Height = 17
      Caption = 'Polarity'
      TabOrder = 4
    end
    object StaticText6: TStaticText
      Left = 16
      Top = 72
      Width = 60
      Height = 17
      Caption = 'Three-State'
      TabOrder = 5
    end
  end
  object GroupBox3: TGroupBox
    Left = 472
    Top = 8
    Width = 209
    Height = 113
    Caption = 'Charge Pump'
    TabOrder = 2
    object CheckBox1: TCheckBox
      Left = 16
      Top = 24
      Width = 97
      Height = 17
      Caption = 'Power Down'
      TabOrder = 0
      OnClick = CheckBox1Click
    end
    object CheckBox2: TCheckBox
      Left = 16
      Top = 48
      Width = 169
      Height = 17
      Caption = 'Double Buffering Out Div'
      TabOrder = 1
      OnClick = CheckBox2Click
    end
    object CheckBox3: TCheckBox
      Left = 16
      Top = 72
      Width = 97
      Height = 17
      Caption = 'Counter Reset'
      TabOrder = 2
      OnClick = CheckBox3Click
    end
  end
  object Button1: TButton
    Left = 240
    Top = 144
    Width = 89
    Height = 33
    Caption = 'OK'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 360
    Top = 144
    Width = 89
    Height = 33
    Caption = 'Cancel'
    TabOrder = 4
    OnClick = Button2Click
  end
end
