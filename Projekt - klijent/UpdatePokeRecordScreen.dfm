object UPPokeEntry: TUPPokeEntry
  Left = 0
  Top = 0
  Caption = 'Update pokemon entry'
  ClientHeight = 331
  ClientWidth = 459
  Color = 3947734
  Constraints.MaxHeight = 370
  Constraints.MaxWidth = 475
  Constraints.MinHeight = 370
  Constraints.MinWidth = 475
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
    Width = 249
    Height = 315
    Brush.Color = 10921638
  end
  object L2: TLabel
    Left = 13
    Top = 51
    Width = 42
    Height = 20
    Caption = 'Name:'
    Color = 10921638
    ParentColor = False
  end
  object L3: TLabel
    Left = 13
    Top = 84
    Width = 76
    Height = 20
    Caption = 'Generation:'
    Color = 10921638
    ParentColor = False
  end
  object L4: TLabel
    Left = 13
    Top = 121
    Width = 85
    Height = 20
    Caption = 'Primary type:'
    Color = 10921638
    ParentColor = False
  end
  object L5: TLabel
    Left = 13
    Top = 162
    Width = 102
    Height = 20
    Caption = 'Secondary type:'
    Color = 10921638
    ParentColor = False
  end
  object L1: TLabel
    Left = 13
    Top = 16
    Width = 94
    Height = 20
    Caption = 'Pokedex entry:'
    Color = 10921638
    ParentColor = False
  end
  object L8: TLabel
    Left = 13
    Top = 288
    Width = 29
    Height = 20
    Caption = 'DEF:'
    Color = 10921638
    ParentColor = False
  end
  object L7: TLabel
    Left = 13
    Top = 250
    Width = 28
    Height = 20
    Caption = 'ATK:'
    Color = 10921638
    ParentColor = False
  end
  object L6: TLabel
    Left = 13
    Top = 213
    Width = 22
    Height = 20
    Caption = 'HP:'
    Color = 10921638
    ParentColor = False
  end
  object L11: TLabel
    Left = 106
    Top = 288
    Width = 29
    Height = 20
    Caption = 'SPD:'
    Color = 10921638
    ParentColor = False
  end
  object L10: TLabel
    Left = 106
    Top = 250
    Width = 50
    Height = 20
    Caption = 'SP. DEF:'
    Color = 10921638
    ParentColor = False
  end
  object L9: TLabel
    Left = 106
    Top = 213
    Width = 49
    Height = 20
    Caption = 'SP. ATK:'
    Color = 10921638
    ParentColor = False
  end
  object FinishUpdate: TButton
    Left = 263
    Top = 282
    Width = 187
    Height = 40
    Caption = 'Update pokemon entry'
    TabOrder = 0
    OnClick = FinishUpdateClick
  end
  object DBEditHPUP: TDBEdit
    Left = 59
    Top = 210
    Width = 30
    Height = 28
    DataField = 'HP'
    DataSource = Main.PokeDataSource
    TabOrder = 1
  end
  object DBEditATKUP: TDBEdit
    Left = 59
    Top = 247
    Width = 30
    Height = 28
    DataField = 'ATK'
    DataSource = Main.PokeDataSource
    TabOrder = 2
  end
  object DBEditDEFUP: TDBEdit
    Left = 59
    Top = 285
    Width = 30
    Height = 28
    DataField = 'DEF'
    DataSource = Main.PokeDataSource
    TabOrder = 3
  end
  object DBEditSPDEFUP: TDBEdit
    Left = 175
    Top = 247
    Width = 30
    Height = 28
    DataField = 'SPDEF'
    DataSource = Main.PokeDataSource
    TabOrder = 4
  end
  object DBEditSPATKUP: TDBEdit
    Left = 175
    Top = 210
    Width = 30
    Height = 28
    DataField = 'SPATK'
    DataSource = Main.PokeDataSource
    TabOrder = 5
  end
  object DBEditSPDUP: TDBEdit
    Left = 175
    Top = 285
    Width = 30
    Height = 28
    DataField = 'SPD'
    DataSource = Main.PokeDataSource
    TabOrder = 6
  end
  object DBEditNAME: TDBEdit
    Left = 98
    Top = 48
    Width = 150
    Height = 28
    DataField = 'Name'
    DataSource = Main.PokeDataSource
    TabOrder = 7
  end
  object DBEditDEXUP: TDBEdit
    Left = 132
    Top = 13
    Width = 34
    Height = 28
    DataField = 'DexEntry'
    DataSource = Main.PokeDataSource
    TabOrder = 8
  end
  object DBEditGENUP: TDBEdit
    Left = 128
    Top = 81
    Width = 15
    Height = 28
    DataField = 'Gen'
    DataSource = Main.PokeDataSource
    TabOrder = 9
  end
  object DBEditPTUP: TDBEdit
    Left = 149
    Top = 118
    Width = 100
    Height = 28
    DataField = 'PrimaryType'
    DataSource = Main.PokeDataSource
    TabOrder = 10
  end
  object DBEditSTUP: TDBEdit
    Left = 149
    Top = 159
    Width = 100
    Height = 28
    DataField = 'SecondaryType'
    DataSource = Main.PokeDataSource
    TabOrder = 11
  end
  object UpdatePokePicButton: TButton
    Left = 263
    Top = 8
    Width = 187
    Height = 41
    Caption = 'Update pokemon picture'
    TabOrder = 12
    OnClick = UpdatePokePicButtonClick
  end
  object UpdatePLearnset: TButton
    Left = 263
    Top = 55
    Width = 187
    Height = 34
    Caption = 'Update poke learnset'
    TabOrder = 13
    OnClick = UpdatePLearnsetClick
  end
  object UpdatePokePic: TOpenPictureDialog
    Filter = 
      'All (*.jpg;*.jpeg;*.png;*.bmp)|*.jpg;*.jpeg;*.png;*.bmp|JPEG Ima' +
      'ge File (*.jpg)|*.jpg|JPEG Image File (*.jpeg)|*.jpeg|Portable N' +
      'etwork Graphics (*.png)|*.png|Bitmaps (*.bmp)|*.bmp'
    Left = 264
    Top = 104
  end
  object UpdateLearnset: TOpenPictureDialog
    Filter = 
      'All (*.jpg;*.jpeg;*.png;*.bmp;)|*.jpg;*.jpeg;*.png;*.bmp;|JPEG I' +
      'mage File (*.jpg)|*.jpg|JPEG Image File (*.jpeg)|*.jpeg|Portable' +
      ' Network Graphics (*.png)|*.png|Bitmaps (*.bmp)|*.bmp'
    Left = 304
    Top = 104
  end
end
