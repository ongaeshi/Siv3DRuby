# coding: utf-8
a = 1
b = 3
array = [1, 2, 3]
# array.each { |e| }
r = a + b + array[0] + array[1] + array[2]

println "Hello mruby #{r}"
println "こんにちは, Siv3DRuby"
# wait_key

x = -100
y = 480

while System.update do
  Circle.new(Point.new(x, y), 50).draw
  if x > 800
    x = -100
    y = 480
  end
  x += 1

  if x > 320 - 50
    y += 1
  else
    y -= 1
  end
end

