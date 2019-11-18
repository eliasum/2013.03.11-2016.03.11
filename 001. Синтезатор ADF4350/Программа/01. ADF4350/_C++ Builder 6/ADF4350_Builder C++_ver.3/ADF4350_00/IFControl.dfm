object F_IFControl: TF_IFControl
  Left = 594
  Top = 142
  Width = 314
  Height = 354
  Caption = 'IF Control'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 59
    Top = 10
    Width = 192
    Height = 16
    Caption = 'Receiver amplification factor, dB'
  end
  object Label2: TLabel
    Left = 59
    Top = 69
    Width = 204
    Height = 16
    Caption = 'Transmitter amplification factor, dB'
  end
  object Label3: TLabel
    Left = 59
    Top = 128
    Width = 215
    Height = 16
    Caption = 'Receiver filter cut-off frequency, MHz'
  end
  object Label4: TLabel
    Left = 59
    Top = 187
    Width = 227
    Height = 16
    Caption = 'Transmitter filter cut-off frequency, MHz'
  end
  object CB_Raf: TComboBox
    Left = 59
    Top = 30
    Width = 188
    Height = 24
    ItemHeight = 16
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
    Left = 59
    Top = 89
    Width = 188
    Height = 24
    ItemHeight = 16
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
    Left = 59
    Top = 148
    Width = 188
    Height = 24
    ItemHeight = 16
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
    Left = 59
    Top = 207
    Width = 188
    Height = 24
    ItemHeight = 16
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
    Left = 30
    Top = 256
    Width = 99
    Height = 41
    Caption = 'OK'
    TabOrder = 4
    OnClick = B_OKClick
  end
  object B_Cancel: TButton
    Left = 177
    Top = 256
    Width = 100
    Height = 41
    Caption = 'Cancel'
    TabOrder = 5
    OnClick = B_CancelClick
  end
end
