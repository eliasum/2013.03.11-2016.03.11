object Form5: TForm5
  Left = 499
  Top = 234
  Width = 867
  Height = 273
  Caption = 'Register 2 Settings'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object GroupBox1: TGroupBox
    Left = 20
    Top = 10
    Width = 257
    Height = 139
    Caption = 'Lock Detect'
    TabOrder = 0
    object ComboBox1: TComboBox
      Left = 79
      Top = 30
      Width = 90
      Height = 24
      Hint = 'Default=FRAC-N'
      ItemHeight = 16
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
      Left = 30
      Top = 30
      Width = 29
      Height = 20
      Caption = 'LDF'
      TabOrder = 1
    end
    object StaticText2: TStaticText
      Left = 30
      Top = 79
      Width = 30
      Height = 20
      Caption = 'LDP'
      TabOrder = 2
    end
    object ComboBox2: TComboBox
      Left = 79
      Top = 79
      Width = 90
      Height = 24
      Hint = 'Default=6ns'
      ItemHeight = 16
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
    Left = 295
    Top = 10
    Width = 258
    Height = 139
    Caption = 'Charge Pump'
    TabOrder = 1
    object ComboBox3: TComboBox
      Left = 108
      Top = 30
      Width = 90
      Height = 24
      Hint = 'Default=Positive'
      ItemHeight = 16
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
      Left = 20
      Top = 20
      Width = 22
      Height = 20
      Caption = 'CP'
      TabOrder = 1
    end
    object StaticText4: TStaticText
      Left = 20
      Top = 69
      Width = 22
      Height = 20
      Caption = 'CP'
      TabOrder = 2
    end
    object ComboBox4: TComboBox
      Left = 108
      Top = 79
      Width = 90
      Height = 24
      Hint = 'Default=Disabled'
      ItemHeight = 16
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
      Left = 20
      Top = 39
      Width = 49
      Height = 20
      Caption = 'Polarity'
      TabOrder = 4
    end
    object StaticText6: TStaticText
      Left = 20
      Top = 89
      Width = 75
      Height = 20
      Caption = 'Three-State'
      TabOrder = 5
    end
  end
  object GroupBox3: TGroupBox
    Left = 581
    Top = 10
    Width = 257
    Height = 139
    Caption = 'Charge Pump'
    TabOrder = 2
    object CheckBox1: TCheckBox
      Left = 20
      Top = 30
      Width = 119
      Height = 20
      Caption = 'Power Down'
      TabOrder = 0
      OnClick = CheckBox1Click
    end
    object CheckBox2: TCheckBox
      Left = 20
      Top = 59
      Width = 208
      Height = 21
      Caption = 'Double Buffering Out Div'
      TabOrder = 1
      OnClick = CheckBox2Click
    end
    object CheckBox3: TCheckBox
      Left = 20
      Top = 89
      Width = 119
      Height = 21
      Caption = 'Counter Reset'
      TabOrder = 2
      OnClick = CheckBox3Click
    end
  end
  object Button1: TButton
    Left = 295
    Top = 177
    Width = 110
    Height = 41
    Caption = 'OK'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 443
    Top = 177
    Width = 110
    Height = 41
    Caption = 'Cancel'
    TabOrder = 4
    OnClick = Button2Click
  end
end
