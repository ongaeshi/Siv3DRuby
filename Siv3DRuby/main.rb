# coding: utf-8
a = 1
b = 3
array = [1, 2, 3]
# array.each { |e| }
r = a + b + array[0] + array[1] + array[2]

println "Hello mruby #{r}"
println "こんにちは, Siv3DRuby"
# wait_key

while System.update do
  Circle.new(100, 100, 100).draw
  # Circle.new(Point.new(100, 100), 100).draw
end

