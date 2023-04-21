object DownDB: TDownDB
  Left = 0
  Top = 0
  Caption = 'Download DB'
  ClientHeight = 191
  ClientWidth = 361
  Color = 3947734
  Constraints.MaxHeight = 230
  Constraints.MaxWidth = 377
  Constraints.MinHeight = 230
  Constraints.MinWidth = 377
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 20
  Font.Name = 'Calibri'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 20
  object Shape1: TShape
    Left = 8
    Top = 8
    Width = 341
    Height = 25
    Brush.Color = 10921638
  end
  object L1: TLabel
    Left = 112
    Top = 11
    Width = 150
    Height = 20
    Caption = 'Download Pokemon DB'
  end
  object Progress: TProgressBar
    Left = 8
    Top = 157
    Width = 341
    Height = 26
    TabOrder = 0
  end
  object CLimits: TComboBox
    Left = 8
    Top = 103
    Width = 177
    Height = 28
    Style = csDropDownList
    Enabled = False
    ItemIndex = 0
    TabOrder = 1
    Text = 'No limit'
    OnChange = CLimitsChange
    Items.Strings = (
      'No limit'
      '50 kb/s'
      '100 kb/s'
      '250 kb/s'
      '500 kb/s')
  end
  object BDownload: TButton
    Left = 208
    Top = 81
    Width = 141
    Height = 33
    Caption = 'Download'
    TabOrder = 2
    OnClick = BDownloadClick
  end
  object BCancel: TButton
    Left = 208
    Top = 120
    Width = 141
    Height = 31
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = BCancelClick
  end
  object E: TEdit
    Left = 8
    Top = 39
    Width = 341
    Height = 28
    TabOrder = 4
    TextHint = 'Insert link here'
  end
  object IdInterceptThrottler1: TIdInterceptThrottler
    BitsPerSec = 0
    RecvBitsPerSec = 0
    SendBitsPerSec = 0
    Left = 40
    Top = 72
  end
  object HTTP: TIdHTTP
    Intercept = IdInterceptThrottler1
    IOHandler = IdSSLIOHandlerSocketOpenSSL1
    OnWork = HTTPWork
    OnWorkBegin = HTTPWorkBegin
    OnWorkEnd = HTTPWorkEnd
    HandleRedirects = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 8
    Top = 72
  end
  object IdSSLIOHandlerSocketOpenSSL1: TIdSSLIOHandlerSocketOpenSSL
    Intercept = IdInterceptThrottler1
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Method = sslvTLSv1_2
    SSLOptions.SSLVersions = [sslvTLSv1_2]
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 72
    Top = 72
  end
end
