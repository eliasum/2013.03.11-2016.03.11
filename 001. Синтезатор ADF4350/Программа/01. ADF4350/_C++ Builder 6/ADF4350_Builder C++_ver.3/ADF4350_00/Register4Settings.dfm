object Form7: TForm7
  Left = 664
  Top = 193
  Width = 316
  Height = 328
  Caption = 'Register 4 Settings'
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
    Left = 10
    Top = 10
    Width = 287
    Height = 199
    Caption = 'Options'
    TabOrder = 0
    object StaticText1: TStaticText
      Left = 30
      Top = 39
      Width = 66
      Height = 20
      Caption = 'Feedback'
      TabOrder = 0
    end
    object StaticText2: TStaticText
      Left = 30
      Top = 59
      Width = 42
      Height = 20
      Caption = 'Select'
      TabOrder = 1
    end
    object ComboBox1: TComboBox
      Left = 108
      Top = 49
      Width = 149
      Height = 24
      Hint = 'Default=FUNDAMENTAL'
      ItemHeight = 16
      ItemIndex = 1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      Text = 'FUNDAMENTAL'
      OnChange = ComboBox1Change
      Items.Strings = (
        'DIVIDED'
        'FUNDAMENTAL')
    end
    object ComboBox3: TComboBox
      Left = 108
      Top = 91
      Width = 149
      Height = 24
      Hint = 'Default=DISABLED'
      ItemHeight = 16
      ItemIndex = 0
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      Text = 'DISABLED'
      OnChange = ComboBox3Change
      Items.Strings = (
        'DISABLED'
        'ENABLED')
    end
    object ComboBox4: TComboBox
      Left = 108
      Top = 132
      Width = 149
      Height = 24
      Hint = 'Default=DIVIDED OUTPUT'
      ItemHeight = 16
      ItemIndex = 0
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      Text = 'DIVIDED OUTPUT'
      OnChange = ComboBox4Change
      Items.Strings = (
        'DIVIDED OUTPUT'
        'FUNDAMENTAL')
    end
    object StaticText4: TStaticText
      Left = 30
      Top = 91
      Width = 41
      Height = 20
      Caption = 'MTLD'
      TabOrder = 5
    end
    object StaticText5: TStaticText
      Left = 30
      Top = 114
      Width = 49
      Height = 20
      Caption = 'Aux Out'
      TabOrder = 6
    end
    object StaticText6: TStaticText
      Left = 30
      Top = 134
      Width = 42
      Height = 20
      Caption = 'Select'
      TabOrder = 7
    end
  end
  object Button1: TButton
    Left = 10
    Top = 229
    Width = 109
    Height = 41
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 187
    Top = 229
    Width = 110
    Height = 41
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = Button2Click
  end
end
