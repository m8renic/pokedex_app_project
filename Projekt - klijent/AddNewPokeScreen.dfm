object AddPokeForm: TAddPokeForm
  Left = 0
  Top = 0
  Caption = 'Add new pokemon'
  ClientHeight = 331
  ClientWidth = 444
  Color = 3947734
  Constraints.MaxHeight = 370
  Constraints.MaxWidth = 460
  Constraints.MinHeight = 370
  Constraints.MinWidth = 460
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 20
  Font.Name = 'Calibri'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 20
  object Shape1: TShape
    Left = 8
    Top = 5
    Width = 251
    Height = 321
    Brush.Color = 10921638
  end
  object L2: TLabel
    Left = 13
    Top = 50
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
  object L6: TLabel
    Left = 13
    Top = 213
    Width = 22
    Height = 20
    Caption = 'HP:'
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
  object L8: TLabel
    Left = 13
    Top = 288
    Width = 29
    Height = 20
    Caption = 'DEF:'
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
  object L10: TLabel
    Left = 106
    Top = 250
    Width = 50
    Height = 20
    Caption = 'SP. DEF:'
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
  object L1: TLabel
    Left = 13
    Top = 16
    Width = 94
    Height = 20
    Caption = 'Pokedex entry:'
    Color = 10921638
    ParentColor = False
  end
  object FinishAdd: TButton
    Left = 265
    Top = 286
    Width = 169
    Height = 40
    Caption = 'Add pokemon entry'
    TabOrder = 0
    OnClick = FinishAddClick
  end
  object DBEditDexEntry: TEdit
    Left = 137
    Top = 13
    Width = 42
    Height = 28
    NumbersOnly = True
    TabOrder = 1
  end
  object DBEditName: TEdit
    Left = 103
    Top = 47
    Width = 121
    Height = 28
    TabOrder = 2
  end
  object DBEditGen: TEdit
    Left = 130
    Top = 81
    Width = 17
    Height = 28
    TabOrder = 3
  end
  object DBEditPT: TEdit
    Left = 147
    Top = 118
    Width = 105
    Height = 28
    TabOrder = 4
  end
  object DBEditST: TEdit
    Left = 147
    Top = 159
    Width = 105
    Height = 28
    TabOrder = 5
  end
  object DBEditHP: TEdit
    Left = 60
    Top = 210
    Width = 30
    Height = 28
    TabOrder = 6
  end
  object DBEditATK: TEdit
    Left = 60
    Top = 247
    Width = 30
    Height = 28
    TabOrder = 7
  end
  object DBEditDEF: TEdit
    Left = 60
    Top = 285
    Width = 30
    Height = 28
    TabOrder = 8
  end
  object DBEditSPATK: TEdit
    Left = 176
    Top = 210
    Width = 30
    Height = 28
    TabOrder = 9
  end
  object DBEditSPDEF: TEdit
    Left = 176
    Top = 247
    Width = 30
    Height = 28
    TabOrder = 10
  end
  object DBEditSPD: TEdit
    Left = 176
    Top = 285
    Width = 30
    Height = 28
    TabOrder = 11
  end
  object AddImgBtn: TButton
    Left = 265
    Top = 8
    Width = 169
    Height = 41
    Caption = 'Add pokemon image'
    TabOrder = 12
    OnClick = AddImgBtnClick
  end
  object AddPokeLearnset: TButton
    Left = 265
    Top = 55
    Width = 169
    Height = 37
    Caption = 'Add poke learnset'
    TabOrder = 13
    OnClick = AddPokeLearnsetClick
  end
  object OpenPokePic: TOpenPictureDialog
    Filter = 
      'JPEG Image File (*.jpg)|*.jpg|JPEG Image File (*.jpeg)|*.jpeg|Po' +
      'rtable Network Graphics (*.png)|*.png|Bitmaps (*.bmp)|*.bmp'
    Left = 264
    Top = 104
  end
  object OpenLearnset: TOpenPictureDialog
    Filter = 
      'All ;*.jpg;*.jpeg;*png;*.bmp)|*.jpg;*.jpeg;*png;*.bmp;|JPEG Imag' +
      'e File (*.jpg)|*.jpg|JPEG Image File (*.jpeg)|*.jpeg|Portable Ne' +
      'twork Graphics (*.png)|*.png|Bitmaps (*.bmp)|*.bmp'
    Left = 296
    Top = 104
  end
end
