object Chat: TChat
  Left = 0
  Top = 0
  Caption = 'Chat'
  ClientHeight = 531
  ClientWidth = 724
  Color = 3947734
  Constraints.MaxHeight = 570
  Constraints.MaxWidth = 740
  Constraints.MinHeight = 570
  Constraints.MinWidth = 740
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 20
  Font.Name = 'Calibri'
  Font.Style = []
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 20
  object Shape1: TShape
    Left = 24
    Top = 16
    Width = 577
    Height = 129
    Brush.Color = 10921638
  end
  object L1: TLabel
    Left = 32
    Top = 29
    Width = 60
    Height = 20
    Caption = 'Server IP:'
  end
  object L2: TLabel
    Left = 32
    Top = 69
    Width = 70
    Height = 20
    Caption = 'Username:'
  end
  object Status: TShape
    Left = 616
    Top = 16
    Width = 89
    Height = 89
  end
  object SendImg: TImage
    Left = 516
    Top = 479
    Width = 28
    Height = 28
    Picture.Data = {
      0954506E67496D61676589504E470D0A1A0A0000000D494844520000001C0000
      001C0802000000FD6F48C30000000467414D410000B18F0BFC61050000000970
      48597300000EC100000EC101B8916BED0000001874455874536F667477617265
      007061696E742E6E657420342E312E338D24FD67000000FB4944415478DAE5D4
      4D0E45301000605DF8B9853A8035B1B07606AB721B6E80057772062E608584D7
      3C8908FDD3CCE6E5CDA2C974F1653AD316F57D6F4007FA4D74DFF7755D2DCB82
      44E7792ECB320882388E1DC7013B3E4DD334BDA600280DDFF7DBB6A5ADC8F35C
      8F66A374EDBA8EAEDBB669D0ECE95F5DE33BC02CCBD469EE953A9A80103A77D4
      69117A2DF6152DBAFC3CF70842088F96BCA867135468093A4D531445BC626FF4
      49C92B6D9AC6344DB04AE17B2A10059C1CADEBFAF663493911FA2C5391E3A237
      F1152742ABAAB26D5B8363A3C330244972A600FF297DD74551789E1786A1EBBA
      1A1C035D96651C478CB136C73E3E48FC39FA01C8E9D559E8AB52FF0000000049
      454E44AE426082}
    Stretch = True
    OnClick = SendImgClick
  end
  object L3: TLabel
    Left = 32
    Top = 107
    Width = 66
    Height = 20
    Caption = 'Password:'
  end
  object Messages: TListBox
    Left = 23
    Top = 160
    Width = 521
    Height = 305
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = 20
    Font.Name = 'Calibri'
    Font.Style = []
    ItemHeight = 20
    ParentFont = False
    ScrollWidth = 2
    TabOrder = 0
  end
  object Users: TListBox
    Left = 568
    Top = 160
    Width = 137
    Height = 305
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = 20
    Font.Name = 'Calibri'
    Font.Style = []
    ItemHeight = 20
    ParentFont = False
    TabOrder = 1
  end
  object Message: TEdit
    Left = 24
    Top = 479
    Width = 486
    Height = 28
    TabOrder = 2
    TextHint = 'Start typing here to message other online users'
    OnKeyPress = MessageKeyPress
  end
  object IPEdit: TEdit
    Left = 176
    Top = 26
    Width = 169
    Height = 28
    TabOrder = 3
    TextHint = 'Public IP'
  end
  object User: TEdit
    Left = 176
    Top = 66
    Width = 169
    Height = 28
    TabOrder = 4
    TextHint = 'Your username'
  end
  object B1: TButton
    Left = 488
    Top = 24
    Width = 105
    Height = 33
    Caption = 'Connect'
    TabOrder = 5
    OnClick = B1Click
  end
  object B2: TButton
    Left = 488
    Top = 63
    Width = 105
    Height = 34
    Caption = 'Disconnect'
    TabOrder = 6
    OnClick = B2Click
  end
  object Pass: TEdit
    Left = 176
    Top = 100
    Width = 169
    Height = 28
    TabOrder = 7
    TextHint = 'Your password'
  end
  object TCPClient: TIdTCPClient
    ConnectTimeout = 0
    Port = 25565
    ReadTimeout = -1
    ReuseSocket = rsTrue
    Left = 360
    Top = 24
  end
  object UDPServer: TIdUDPServer
    Active = True
    BroadcastEnabled = True
    Bindings = <>
    DefaultPort = 25567
    ReuseSocket = rsTrue
    OnUDPRead = UDPServerUDPRead
    Left = 360
    Top = 64
  end
  object CryptographicLibrary: TCryptographicLibrary
    Left = 648
    Top = 480
  end
  object Assymetric: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary
    Left = 616
    Top = 480
    StreamCipherId = 'native.RSA'
    BlockCipherId = ''
    ChainId = 'native.CBC'
  end
  object Signatory: TSignatory
    Codec = Assymetric
    Left = 680
    Top = 480
  end
  object Hashing: THash
    CryptoLibrary = CryptographicLibrary
    Left = 360
    Top = 112
    HashId = 'native.hash.SHA-256'
  end
  object TCPServer: TIdTCPServer
    Bindings = <
      item
        Port = 25566
      end>
    DefaultPort = 25566
    OnExecute = TCPServerExecute
    Left = 392
    Top = 24
  end
  object Symetric: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary
    Left = 584
    Top = 480
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-256'
    ChainId = 'native.CBC'
  end
end
