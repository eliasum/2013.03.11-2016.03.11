object F_IFControl: TF_IFControl
  Left = 611
  Top = 146
  Width = 256
  Height = 292
  Caption = 'IF Control'
  Color = clBtnFace
  Constraints.MaxHeight = 292
  Constraints.MaxWidth = 256
  Constraints.MinHeight = 292
  Constraints.MinWidth = 256
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
  object Label1: TLabel
    Left = 48
    Top = 8
    Width = 153
    Height = 13
    Caption = 'Receiver amplification factor, dB'
  end
  object Label2: TLabel
    Left = 48
    Top = 56
    Width = 162
    Height = 13
    Caption = 'Transmitter amplification factor, dB'
  end
  object Label3: TLabel
    Left = 48
    Top = 104
    Width = 176
    Height = 13
    Caption = 'Receiver filter cut-off frequency, MHz'
  end
  object Label4: TLabel
    Left = 48
    Top = 152
    Width = 185
    Height = 13
    Caption = 'Transmitter filter cut-off frequency, MHz'
  end
  object CB_Raf: TComboBox
    Left = 48
    Top = 24
    Width = 153
    Height = 21
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 0
    Text = '0'
    OnChange = CB_RafChange
    Items.Strings = (
      '0'
      '0,5'
      '1'
      '1,5'
      '2'
      '2,5'
      '3'
      '3,5'
      '4'
      '4,5'
      '5'
      '5,5'
      '6'
      '6,5'
      '7'
      '7,5'
      '8'
      '8,5'
      '9'
      '9,5'
      '10'
      '10,5'
      '11'
      '11,5'
      '12'
      '12,5'
      '13'
      '13,5'
      '14'
      '14,5'
      '15'
      '15,5'
      '16'
      '16,5'
      '17'
      '17,5'
      '18'
      '18,5'
      '19'
      '19,5'
      '20'
      '20,5'
      '21'
      '21,5'
      '22'
      '22,5'
      '23'
      '23,5'
      '24'
      '24,5'
      '25'
      '25,5'
      '26'
      '26,5'
      '27'
      '27,5'
      '28'
      '28,5'
      '29'
      '29,5'
      '30'
      '30,5'
      '31'
      '31,5')
  end
  object CB_Taf: TComboBox
    Left = 48
    Top = 72
    Width = 153
    Height = 21
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 1
    Text = '0'
    OnChange = CB_TafChange
    Items.Strings = (
      '0'
      '0,5'
      '1'
      '1,5'
      '2'
      '2,5'
      '3'
      '3,5'
      '4'
      '4,5'
      '5'
      '5,5'
      '6'
      '6,5'
      '7'
      '7,5'
      '8'
      '8,5'
      '9'
      '9,5'
      '10'
      '10,5'
      '11'
      '11,5'
      '12'
      '12,5'
      '13'
      '13,5'
      '14'
      '14,5'
      '15'
      '15,5'
      '16'
      '16,5'
      '17'
      '17,5'
      '18'
      '18,5'
      '19'
      '19,5'
      '20'
      '20,5'
      '21'
      '21,5'
      '22'
      '22,5'
      '23'
      '23,5'
      '24'
      '24,5'
      '25'
      '25,5'
      '26'
      '26,5'
      '27'
      '27,5'
      '28'
      '28,5'
      '29'
      '29,5'
      '30'
      '30,5'
      '31'
      '31,5')
  end
  object CB_Rfcf: TComboBox
    Left = 48
    Top = 120
    Width = 153
    Height = 21
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 2
    Text = '970'
    OnChange = CB_RfcfChange
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
  object CB_Tfcf: TComboBox
    Left = 48
    Top = 168
    Width = 153
    Height = 21
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 3
    Text = '970'
    OnChange = CB_TfcfChange
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
  object B_OK: TButton
    Left = 24
    Top = 208
    Width = 81
    Height = 33
    Caption = 'OK'
    TabOrder = 4
    OnClick = B_OKClick
  end
  object B_Cancel: TButton
    Left = 144
    Top = 208
    Width = 81
    Height = 33
    Caption = 'Cancel'
    TabOrder = 5
    OnClick = B_CancelClick
  end
end
