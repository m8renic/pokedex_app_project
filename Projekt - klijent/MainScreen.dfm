object Main: TMain
  Left = 0
  Top = 0
  HelpType = htKeyword
  Caption = 'Main'
  ClientHeight = 621
  ClientWidth = 1224
  Color = 3947734
  Constraints.MaxHeight = 680
  Constraints.MaxWidth = 1240
  Constraints.MinHeight = 680
  Constraints.MinWidth = 1240
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 20
  Font.Name = 'Calibri'
  Font.Style = []
  Menu = ExportPopUp
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 20
  object Shape1: TShape
    Left = 24
    Top = 25
    Width = 513
    Height = 185
    Brush.Color = 10921638
  end
  object Shape2: TShape
    Left = 668
    Top = 25
    Width = 545
    Height = 530
    Brush.Color = 10921638
  end
  object L2: TLabel
    Left = 40
    Top = 81
    Width = 76
    Height = 20
    Caption = 'Generation:'
  end
  object L3: TLabel
    Left = 40
    Top = 123
    Width = 87
    Height = 20
    Caption = 'Primary Type:'
  end
  object L1: TLabel
    Left = 41
    Top = 41
    Width = 102
    Height = 20
    Caption = 'Pokemon name:'
  end
  object Shape3: TShape
    Left = 24
    Top = 232
    Width = 625
    Height = 377
    Brush.Color = 10921638
  end
  object L4: TLabel
    Left = 40
    Top = 165
    Width = 104
    Height = 20
    Caption = 'Secondary Type:'
  end
  object Label2: TLabel
    Left = 768
    Top = 424
    Width = 47
    Height = 20
    Caption = 'Overall'
  end
  object GenSelect: TComboBox
    Left = 168
    Top = 81
    Width = 65
    Height = 28
    Color = clWhite
    DropDownCount = 4
    TabOrder = 0
    Text = 'All'
    Items.Strings = (
      'All'
      '1'
      '2'
      '3')
  end
  object PrimaryT: TComboBox
    Left = 186
    Top = 123
    Width = 90
    Height = 28
    DropDownCount = 19
    ItemIndex = 0
    TabOrder = 1
    Text = 'Any'
    Items.Strings = (
      'Any'
      'Normal'
      'Fighting'
      'Flying'
      'Poison'
      'Ground'
      'Rock'
      'Bug'
      'Ghost'
      'Steel'
      'Fire'
      'Water'
      'Grass'
      'Electric'
      'Psychic'
      'Ice'
      'Dragon'
      'Dark'
      'Fairy')
  end
  object SecondaryT: TComboBox
    Left = 215
    Top = 165
    Width = 90
    Height = 28
    DropDownCount = 20
    ItemIndex = 0
    TabOrder = 2
    Text = 'Any'
    Items.Strings = (
      'Any'
      'Normal'
      'Fighting'
      'Flying'
      'Poison'
      'Ground'
      'Rock'
      'Bug'
      'Ghost'
      'Steel'
      'Fire'
      'Water'
      'Grass'
      'Electric'
      'Psychic'
      'Ice'
      'Dragon'
      'Dark'
      'Fairy')
  end
  object SearchPokeName: TEdit
    Left = 206
    Top = 41
    Width = 163
    Height = 28
    TabOrder = 3
    TextHint = 'Enter pokemon name'
  end
  object SearchPoke: TButton
    Left = 351
    Top = 159
    Width = 172
    Height = 40
    Caption = 'Search for pokemon'
    TabOrder = 4
    OnClick = SearchPokeClick
  end
  object AddNewPoke: TButton
    Left = 668
    Top = 561
    Width = 154
    Height = 49
    Caption = 'Add new pokemon'
    TabOrder = 5
    OnClick = AddNewPokeClick
  end
  object UpdatePokeEntry: TButton
    Left = 828
    Top = 561
    Width = 186
    Height = 49
    Caption = 'Update pokemon entry'
    TabOrder = 6
    OnClick = UpdatePokeEntryClick
  end
  object DeletePokeEntry: TButton
    Left = 1020
    Top = 561
    Width = 193
    Height = 49
    Caption = 'Delete pokemon entry'
    TabOrder = 7
    OnClick = DeletePokeEntryClick
  end
  object DBGrid1: TDBGrid
    Left = 675
    Top = 36
    Width = 529
    Height = 512
    DataSource = PokeDataSource
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ReadOnly = True
    TabOrder = 8
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = 20
    TitleFont.Name = 'Calibri'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'DexEntry'
        Width = 69
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Name'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PrimaryType'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SecondaryType'
        Width = 100
        Visible = True
      end>
  end
  object ScrollBox1: TScrollBox
    Left = 31
    Top = 239
    Width = 610
    Height = 363
    Color = 10921638
    ParentColor = False
    TabOrder = 9
    object L5: TLabel
      Left = 15
      Top = 8
      Width = 94
      Height = 20
      Caption = 'Pokedex entry:'
      FocusControl = DBEditDEXENTRY
    end
    object L6: TLabel
      Left = 293
      Top = 8
      Width = 42
      Height = 20
      Caption = 'Name:'
      FocusControl = DBEditNAME
    end
    object L7: TLabel
      Left = 293
      Top = 42
      Width = 76
      Height = 20
      Caption = 'Generation:'
      FocusControl = DBEdit3
    end
    object L8: TLabel
      Left = 293
      Top = 79
      Width = 85
      Height = 20
      Caption = 'Primary type:'
      FocusControl = DBEditPTUP
    end
    object L9: TLabel
      Left = 293
      Top = 120
      Width = 102
      Height = 20
      Caption = 'Secondary type:'
      FocusControl = DBEdit5
    end
    object L10: TLabel
      Left = 294
      Top = 163
      Width = 22
      Height = 20
      Caption = 'HP:'
      FocusControl = DBEdit6
    end
    object L11: TLabel
      Left = 294
      Top = 200
      Width = 28
      Height = 20
      Caption = 'ATK:'
      FocusControl = DBEdit7
    end
    object L12: TLabel
      Left = 294
      Top = 238
      Width = 29
      Height = 20
      Caption = 'DEF:'
      FocusControl = DBEdit8
    end
    object L13: TLabel
      Left = 387
      Top = 163
      Width = 49
      Height = 20
      Caption = 'SP. ATK:'
      FocusControl = DBEdit9
    end
    object L14: TLabel
      Left = 387
      Top = 200
      Width = 50
      Height = 20
      Caption = 'SP. DEF:'
      FocusControl = DBEdit10
    end
    object L15: TLabel
      Left = 387
      Top = 238
      Width = 29
      Height = 20
      Caption = 'SPD:'
      FocusControl = DBEdit11
    end
    object L16: TLabel
      Left = 15
      Top = 300
      Width = 60
      Height = 20
      Caption = 'Learnset:'
    end
    object Learnset: TImage
      Left = 15
      Top = 326
      Width = 554
      Height = 533
      Proportional = True
      Stretch = True
    end
    object OVL: TLabel
      Left = 331
      Top = 280
      Width = 51
      Height = 20
      Caption = 'Overall:'
      FocusControl = OVEdit
    end
    object DBEditDEXENTRY: TDBEdit
      Left = 133
      Top = 5
      Width = 36
      Height = 28
      DataField = 'DexEntry'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 0
    end
    object DBEditNAME: TDBEdit
      Left = 358
      Top = 5
      Width = 150
      Height = 28
      DataField = 'Name'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 1
    end
    object DBEdit3: TDBEdit
      Left = 421
      Top = 39
      Width = 15
      Height = 28
      DataField = 'Gen'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 2
    end
    object DBEditPTUP: TDBEdit
      Left = 423
      Top = 76
      Width = 91
      Height = 28
      DataField = 'PrimaryType'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 3
    end
    object DBEdit5: TDBEdit
      Left = 424
      Top = 117
      Width = 91
      Height = 28
      DataField = 'SecondaryType'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 4
    end
    object DBEdit6: TDBEdit
      Left = 344
      Top = 160
      Width = 30
      Height = 28
      DataField = 'HP'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 5
    end
    object DBEdit7: TDBEdit
      Left = 344
      Top = 197
      Width = 30
      Height = 28
      DataField = 'ATK'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 6
    end
    object DBEdit8: TDBEdit
      Left = 344
      Top = 235
      Width = 30
      Height = 28
      DataField = 'DEF'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 7
    end
    object DBEdit9: TDBEdit
      Left = 460
      Top = 160
      Width = 30
      Height = 28
      DataField = 'SPATK'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 8
    end
    object DBEdit10: TDBEdit
      Left = 460
      Top = 197
      Width = 30
      Height = 28
      DataField = 'SPDEF'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 9
    end
    object DBEdit11: TDBEdit
      Left = 460
      Top = 235
      Width = 30
      Height = 28
      DataField = 'SPD'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 10
    end
    object DBImage1: TDBImage
      Left = 15
      Top = 39
      Width = 220
      Height = 220
      Color = 12237498
      DataField = 'PokeIcon'
      DataSource = PokeDataSource
      ReadOnly = True
      QuickDraw = False
      TabOrder = 11
    end
    object OVEdit: TDBEdit
      Left = 415
      Top = 277
      Width = 75
      Height = 28
      DataField = 'Overall'
      DataSource = PokeDataSource
      ReadOnly = True
      TabOrder = 12
    end
  end
  object PokeDBConnection: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Pokemon_OldAccessDB' +
      '.mdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 680
  end
  object ListOfPoke: TADOTable
    Active = True
    Connection = PokeDBConnection
    CursorType = ctStatic
    AfterScroll = ListOfPokeAfterScroll
    OnCalcFields = ListOfPokeCalcFields
    TableName = 'PokemonList'
    Left = 712
    object ListOfPokeID: TIntegerField
      FieldName = 'ID'
    end
    object ListOfPokeDexEntry: TWideStringField
      FieldName = 'DexEntry'
      Size = 255
    end
    object ListOfPokeGen: TIntegerField
      FieldName = 'Gen'
    end
    object ListOfPokeName: TWideStringField
      FieldName = 'Name'
      Size = 255
    end
    object ListOfPokePrimaryType: TWideStringField
      FieldName = 'PrimaryType'
      Size = 255
    end
    object ListOfPokeSecondaryType: TWideStringField
      FieldName = 'SecondaryType'
      Size = 255
    end
    object ListOfPokeHP: TIntegerField
      FieldName = 'HP'
    end
    object ListOfPokeATK: TIntegerField
      FieldName = 'ATK'
    end
    object ListOfPokeDEF: TIntegerField
      FieldName = 'DEF'
    end
    object ListOfPokeSPATK: TIntegerField
      FieldName = 'SPATK'
    end
    object ListOfPokeSPDEF: TIntegerField
      FieldName = 'SPDEF'
    end
    object ListOfPokeSPD: TIntegerField
      FieldName = 'SPD'
    end
    object ListOfPokeOverall: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'Overall'
      Calculated = True
    end
    object ListOfPokePokeIcon: TBlobField
      FieldName = 'PokeIcon'
    end
  end
  object PokeDataSource: TDataSource
    DataSet = ListOfPoke
    Left = 744
  end
  object ExportPopUp: TMainMenu
    object N1: TMenuItem
      Caption = 'Export'
      object S1: TMenuItem
        Caption = 'As PDF'
        OnClick = ExportAsPDF
      end
      object S2: TMenuItem
        Caption = 'As RTF'
        OnClick = ExportAsRTF
      end
      object S3: TMenuItem
        Caption = 'As PNG'
        OnClick = ExportAsPNG
      end
    end
    object N2: TMenuItem
      Caption = 'Options'
      OnClick = N2Click
    end
    object Chat1: TMenuItem
      Caption = 'Chat'
      OnClick = Chat1Click
    end
    object DownloadDB: TMenuItem
      Caption = 'DB gone?'
      OnClick = DownloadDBClick
    end
  end
  object PokeReportFile: TfrxReport
    Version = '2021.2.1'
    DataSet = PokeReportDB1
    DataSetName = 'frxDBDataset1'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 44678.796033622700000000
    ReportOptions.LastChange = 44734.510864282410000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      'end.')
    Left = 184
    Datasets = <
      item
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
      end
      item
        DataSet = PokeReportDB2
        DataSetName = 'frxDBDataset2'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      VGuides.Strings = (
        '-15,45')
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Color = 3947734
      Frame.Typ = []
      MirrorMode = []
      object Memo1: TfrxMemoView
        AllowVectorExport = True
        Left = 49.133890000000000000
        Top = 45.354360000000000000
        Width = 98.267780000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'Pokedex entry:')
      end
      object frxDBDataset1Name: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 347.716760000000000000
        Top = 45.354360000000000000
        Width = 124.724490000000000000
        Height = 18.897650000000000000
        DataField = 'Name'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."Name"]')
      end
      object Memo2: TfrxMemoView
        AllowVectorExport = True
        Left = 306.141930000000000000
        Top = 45.354360000000000000
        Width = 45.354360000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'Name:')
      end
      object frxDBDataset1Gen: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 381.732530000000000000
        Top = 79.370130000000000000
        Width = 26.456710000000000000
        Height = 18.897650000000000000
        DataField = 'Gen'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."Gen"]')
      end
      object Memo3: TfrxMemoView
        AllowVectorExport = True
        Left = 306.141930000000000000
        Top = 79.370130000000000000
        Width = 75.590600000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'Generation:')
      end
      object frxDBDataset1PrimaryType: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 389.291590000000000000
        Top = 113.385900000000000000
        Width = 90.708720000000000000
        Height = 18.897650000000000000
        DataField = 'PrimaryType'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."PrimaryType"]')
      end
      object Memo4: TfrxMemoView
        AllowVectorExport = True
        Left = 306.141930000000000000
        Top = 113.385900000000000000
        Width = 83.149660000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'Primary type:')
      end
      object Memo5: TfrxMemoView
        AllowVectorExport = True
        Left = 306.141930000000000000
        Top = 147.401670000000000000
        Width = 102.047310000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'Secondary type:')
      end
      object frxDBDataset1SecondaryType: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 408.189240000000000000
        Top = 147.401670000000000000
        Width = 102.047310000000000000
        Height = 18.897650000000000000
        DataField = 'SecondaryType'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."SecondaryType"]')
      end
      object Memo6: TfrxMemoView
        AllowVectorExport = True
        Left = 306.141930000000000000
        Top = 196.535560000000000000
        Width = 26.456710000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'HP:')
      end
      object Memo7: TfrxMemoView
        AllowVectorExport = True
        Left = 306.141930000000000000
        Top = 226.771800000000000000
        Width = 37.795300000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'ATK:')
      end
      object Memo8: TfrxMemoView
        AllowVectorExport = True
        Left = 306.141930000000000000
        Top = 257.008040000000000000
        Width = 34.015770000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'DEF:')
      end
      object frxDBDataset1HP: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 355.275820000000000000
        Top = 196.535560000000000000
        Width = 37.795300000000000000
        Height = 18.897650000000000000
        DataField = 'HP'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."HP"]')
      end
      object frxDBDataset1DEF: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 355.275820000000000000
        Top = 226.771800000000000000
        Width = 37.795300000000000000
        Height = 18.897650000000000000
        DataField = 'ATK'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."ATK"]')
      end
      object frxDBDataset1DEF1: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 355.275820000000000000
        Top = 257.008040000000000000
        Width = 37.795300000000000000
        Height = 18.897650000000000000
        DataField = 'DEF'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."DEF"]')
      end
      object Memo9: TfrxMemoView
        AllowVectorExport = True
        Left = 430.866420000000000000
        Top = 196.535560000000000000
        Width = 56.692950000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'SP.ATK:')
      end
      object Memo10: TfrxMemoView
        AllowVectorExport = True
        Left = 430.866420000000000000
        Top = 226.771800000000000000
        Width = 56.692950000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'SP.DEF:')
      end
      object Memo11: TfrxMemoView
        AllowVectorExport = True
        Left = 430.866420000000000000
        Top = 257.008040000000000000
        Width = 56.692950000000000000
        Height = 18.897650000000000000
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          'SPD:')
      end
      object frxDBDataset1SPATK: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 498.897960000000000000
        Top = 196.535560000000000000
        Width = 41.574830000000000000
        Height = 18.897650000000000000
        DataField = 'SPATK'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."SPATK"]')
      end
      object frxDBDataset1SPDEF: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 498.897960000000000000
        Top = 226.771800000000000000
        Width = 41.574830000000000000
        Height = 18.897650000000000000
        DataField = 'SPDEF'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."SPDEF"]')
      end
      object frxDBDataset1SPD: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 498.897960000000000000
        Top = 257.008040000000000000
        Width = 41.574830000000000000
        Height = 18.897650000000000000
        DataField = 'SPD'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."SPD"]')
      end
      object Picture1: TfrxPictureView
        AllowVectorExport = True
        Left = 49.133890000000000000
        Top = 83.149660000000000000
        Width = 188.976377950000000000
        Height = 188.976377950000000000
        DataField = 'PokeIcon'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        HightQuality = False
        Transparent = False
        TransparentColor = clWhite
      end
      object frxDBDataset1DexEntry: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 143.622140000000000000
        Top = 45.354360000000000000
        Width = 49.133890000000000000
        Height = 18.897650000000000000
        DataField = 'DexEntry'
        DataSet = PokeReportDB1
        DataSetName = 'frxDBDataset1'
        Frame.Typ = []
        Fill.BackColor = clScrollBar
        Memo.UTF8W = (
          '[frxDBDataset1."DexEntry"]')
      end
    end
  end
  object PokeReportDB1: TfrxDBDataset
    RangeBegin = rbCurrent
    RangeEnd = reCurrent
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSource = PokeDataSource
    BCDToCurrency = False
    Left = 120
  end
  object ExpAsPNG: TfrxPNGExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    Left = 288
  end
  object ExpAsPDF: TfrxPDFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    CreationTime = 44679.728247314820000000
    DataOnly = False
    EmbedFontsIfProtected = False
    InteractiveFormsFontSubset = 'A-Z,a-z,0-9,#43-#47 '
    OpenAfterExport = True
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Quality = 95
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    Creator = 'FastReport'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    PdfA = False
    PDFStandard = psNone
    PDFVersion = pv17
    Left = 224
  end
  object ExpAsRTF: TfrxRTFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    PictureType = gpPNG
    OpenAfterExport = False
    Wysiwyg = True
    Creator = 'FastReport'
    SuppressPageHeadersFooters = False
    HeaderFooterMode = hfText
    AutoSize = False
    Left = 256
  end
  object PokeL: TADOTable
    Active = True
    Connection = PokeDBConnection
    CursorType = ctStatic
    IndexFieldNames = 'ID'
    MasterFields = 'ID'
    MasterSource = PokeDataSource
    TableName = 'PokemonMoves'
    Left = 840
    object PokeLID: TIntegerField
      FieldName = 'ID'
    end
    object PokeLLearnset: TWideMemoField
      FieldName = 'Learnset'
      BlobType = ftWideMemo
    end
  end
  object PLC: TDataSource
    DataSet = PokeL
    Left = 872
  end
  object PokeReportDB2: TfrxDBDataset
    RangeBegin = rbCurrent
    RangeEnd = reCurrent
    UserName = 'frxDBDataset2'
    CloseDataSource = False
    DataSource = PLC
    BCDToCurrency = False
    Left = 152
  end
end
