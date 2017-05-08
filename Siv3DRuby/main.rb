# coding: utf-8
font = Font.new(30)

while System.update do
  Circle.new(Mouse.pos, 100).draw
  # font["こんにちは"].draw
  # font[Mouse.pos.to_s].draw
  font["マウス座標: #{Mouse.pos}"].draw
  # font[Mouse.pos].draw(50, 200)
  # font[Mouse.pos].draw(50, 200, Pallete::Orange)
end
