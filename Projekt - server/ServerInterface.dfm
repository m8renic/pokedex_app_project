object Server: TServer
  Left = 0
  Top = 0
  Caption = 'Server'
  ClientHeight = 430
  ClientWidth = 669
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 24
  Font.Name = 'Calibri'
  Font.Style = []
  Menu = MainMenu1
  OnCreate = FormCreate
  TextHeight = 24
  object Shape1: TShape
    Left = 16
    Top = 18
    Width = 321
    Height = 32
  end
  object Label1: TLabel
    Left = 19
    Top = 21
    Width = 145
    Height = 24
    Caption = 'Current server IP:'
  end
  object Status: TShape
    Left = 427
    Top = 64
    Width = 41
    Height = 41
  end
  object IPRO: TEdit
    Left = 176
    Top = 18
    Width = 161
    Height = 32
    ReadOnly = True
    TabOrder = 0
    TextHint = 'IP'
  end
  object GetIP: TButton
    Left = 342
    Top = 18
    Width = 98
    Height = 32
    Caption = 'Get IP'
    TabOrder = 1
    OnClick = GetIPClick
  end
  object Button1: TButton
    Left = 19
    Top = 64
    Width = 198
    Height = 41
    Caption = 'Start'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 223
    Top = 64
    Width = 198
    Height = 41
    Caption = 'Stop'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Messages: TListBox
    Left = 19
    Top = 120
    Width = 402
    Height = 289
    ItemHeight = 24
    TabOrder = 4
  end
  object Users: TListBox
    Left = 440
    Top = 120
    Width = 209
    Height = 289
    ItemHeight = 24
    TabOrder = 5
  end
  object RESTRequest1: TRESTRequest
    Client = IPRESTClient
    Params = <
      item
        Name = 'format'
        Value = 'text'
      end>
    Response = RESTResponse1
    Left = 576
    Top = 16
  end
  object RESTResponse1: TRESTResponse
    ContentType = 'text/plain'
    Left = 608
    Top = 16
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    Left = 639
    Top = 16
    object LinkControlToField1: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTResponse1
      FieldName = 'Content'
      Control = IPRO
      Track = True
    end
  end
  object ChatServer: TIdTCPServer
    Bindings = <
      item
        Port = 25565
      end>
    DefaultPort = 25565
    OnConnect = ChatServerConnect
    OnDisconnect = ChatServerDisconnect
    ReuseSocket = rsTrue
    OnExecute = ChatServerExecute
    Left = 448
    Top = 16
  end
  object UDPClient: TIdUDPClient
    Active = True
    BroadcastEnabled = True
    Port = 25567
    ReuseSocket = rsTrue
    Left = 488
    Top = 64
  end
  object UsersConnection: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=Users' +
      '.mdb;Mode=Share Deny None;Persist Security Info=False;Jet OLEDB:' +
      'System database="";Jet OLEDB:Registry Path="";Jet OLEDB:Database' +
      ' Password="";Jet OLEDB:Engine Type=5;Jet OLEDB:Database Locking ' +
      'Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk' +
      ' Transactions=1;Jet OLEDB:New Database Password="";Jet OLEDB:Cre' +
      'ate System Database=False;Jet OLEDB:Encrypt Database=False;Jet O' +
      'LEDB:Don'#39't Copy Locale on Compact=False;Jet OLEDB:Compact Withou' +
      't Replica Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 600
    Top = 56
  end
  object UsersTable: TADOTable
    Active = True
    Connection = UsersConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    TableName = 'Userlist'
    Left = 632
    Top = 56
    object UsersTableUsername: TWideStringField
      FieldName = 'Username'
      Size = 50
    end
    object UsersTablePassword: TWideStringField
      FieldName = 'Password'
      Size = 50
    end
  end
  object Hash: THash
    CryptoLibrary = CryptographicLibrary1
    Left = 600
    Top = 88
    HashId = 'native.hash.SHA-256'
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 632
    Top = 88
  end
  object MainMenu1: TMainMenu
    object Manageusers1: TMenuItem
      Caption = 'Manage users'
      OnClick = Manageusers1Click
    end
  end
  object TCPForward: TIdTCPClient
    ConnectTimeout = 0
    Port = 25566
    ReadTimeout = -1
    ReuseSocket = rsTrue
    Left = 480
    Top = 16
  end
  object IPRESTClient: TRESTClient
    Accept = 'application/json, text/plain; q=0.9, text/html;q=0.8,'
    AcceptCharset = 'utf-8, *;q=0.8'
    BaseURL = 'https://api.ipify.org'
    Params = <>
    Left = 544
    Top = 16
  end
  object Symetric: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 568
    Top = 90
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-256'
    ChainId = 'native.CBC'
  end
end
