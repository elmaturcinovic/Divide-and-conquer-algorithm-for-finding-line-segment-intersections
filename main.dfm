object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 459
  ClientWidth = 738
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Slika: TImage
    Left = 8
    Top = 8
    Width = 721
    Height = 377
    OnMouseDown = SlikaMouseDown
    OnMouseMove = SlikaMouseMove
  end
  object LabelKoordinate: TLabel
    Left = 584
    Top = 408
    Width = 56
    Height = 13
    Caption = 'Koordinate:'
  end
  object RadioButtonDodajDuzi: TRadioButton
    Left = 8
    Top = 403
    Width = 129
    Height = 25
    Hint = 'Dodavanje du'#382'i'
    Caption = 'Dodavanje du'#382'i'
    TabOrder = 0
  end
  object ButtonPresjekDuzi: TButton
    Left = 176
    Top = 403
    Width = 137
    Height = 25
    Caption = 'Prona'#273'i presjeke du'#382'i'
    TabOrder = 1
    OnClick = PresjekDuziClick
  end
  object EditKoordinate: TEdit
    Left = 655
    Top = 405
    Width = 73
    Height = 21
    Alignment = taCenter
    ParentColor = True
    TabOrder = 2
    Text = '(0, 0)'
  end
end
