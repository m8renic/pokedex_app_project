object OptionsS: TOptionsS
  Left = 0
  Top = 0
  Caption = 'Options'
  ClientHeight = 251
  ClientWidth = 434
  Color = 3947734
  Constraints.MaxHeight = 290
  Constraints.MaxWidth = 450
  Constraints.MinHeight = 290
  Constraints.MinWidth = 450
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 20
  Font.Name = 'Calibri'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 20
  object Shape1: TShape
    Left = 17
    Top = 13
    Width = 403
    Height = 227
    Brush.Color = 10921638
  end
  object L1: TLabel
    Left = 40
    Top = 38
    Width = 67
    Height = 20
    Caption = 'Language:'
    Color = clNone
    ParentColor = False
  end
  object L2: TLabel
    Left = 40
    Top = 80
    Width = 116
    Height = 20
    Caption = 'Background color:'
    Color = clNone
    ParentColor = False
  end
  object L3: TLabel
    Left = 40
    Top = 129
    Width = 36
    Height = 20
    Caption = 'Font: '
    Color = clNone
    ParentColor = False
  end
  object ComboBox1: TComboBox
    Left = 147
    Top = 35
    Width = 63
    Height = 28
    ItemIndex = 0
    TabOrder = 0
    Text = 'ENG'
    Items.Strings = (
      'ENG'
      'HR')
  end
  object Button1: TButton
    Left = 176
    Top = 200
    Width = 114
    Height = 33
    Caption = 'Apply'
    TabOrder = 1
    OnClick = ApplySettingsClick
  end
  object Button2: TButton
    Left = 296
    Top = 200
    Width = 113
    Height = 33
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = CancelButtonClick
  end
  object Button3: TButton
    Left = 236
    Top = 73
    Width = 141
    Height = 30
    Caption = 'Pick a color'
    TabOrder = 3
    OnClick = ColorPickClick
  end
  object ComboBox2: TComboBox
    Left = 126
    Top = 129
    Width = 84
    Height = 28
    ItemIndex = 1
    TabOrder = 4
    Text = 'Calibri'
    Items.Strings = (
      'Arial'
      'Calibri'
      'Consolas')
  end
  object ColorPicking: TColorDialog
    Color = clNone
    Left = 389
    Top = 74
  end
end
