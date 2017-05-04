font = Font.new(30)

while System.update do
  Circle.new(Mouse.pos, 100).draw
  # font[Mouse::Pos()].draw(50, 200, Pallete::Orange)
  # font[Mouse::Pos()].draw(50, 200)
end
