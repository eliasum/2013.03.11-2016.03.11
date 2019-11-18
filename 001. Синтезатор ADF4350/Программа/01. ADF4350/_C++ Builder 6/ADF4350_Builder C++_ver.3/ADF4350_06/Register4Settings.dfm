object Form7: TForm7
  Left = 669
  Top = 197
  Width = 258
  Height = 269
  Caption = 'Register 4 Settings'
  Color = clBtnFace
  Constraints.MaxHeight = 269
  Constraints.MaxWidth = 258
  Constraints.MinHeight = 269
  Constraints.MinWidth = 258
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
    Left = 8
    Top = 8
    Width = 233
    Height = 162
    Caption = 'Options'
    TabOrder = 0
    object StaticText1: TStaticText
      Left = 24
      Top = 32
      Width = 52
      Height = 17
      Caption = 'Feedback'
      TabOrder = 0
    end
    object StaticText2: TStaticText
      Left = 24
      Top = 48
      Width = 34
      Height = 17
      Caption = 'Select'
      TabOrder = 1
    end
    object ComboBox1: TComboBox
      Left = 88
      Top = 40
      Width = 121
      Height = 21
      Hint = 'Default=FUNDAMENTAL'
      ItemHeight = 13
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
      Left = 88
      Top = 74
      Width = 121
      Height = 21
      Hint = 'Default=DISABLED'
      ItemHeight = 13
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
      Left = 88
      Top = 107
      Width = 121
      Height = 21
      Hint = 'Default=DIVIDED OUTPUT'
      ItemHeight = 13
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
      Left = 24
      Top = 74
      Width = 34
      Height = 17
      Caption = 'MTLD'
      TabOrder = 5
    end
    object StaticText5: TStaticText
      Left = 24
      Top = 93
      Width = 42
      Height = 17
      Caption = 'Aux Out'
      TabOrder = 6
    end
    object StaticText6: TStaticText
      Left = 24
      Top = 109
      Width = 34
      Height = 17
      Caption = 'Select'
      TabOrder = 7
    end
  end
  object Button1: TButton
    Left = 8
    Top = 186
    Width = 89
    Height = 33
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 152
    Top = 186
    Width = 89
    Height = 33
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = Button2Click
  end
end
