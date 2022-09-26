n = gets.to_i
puts [n, (Float(n.abs)/10).floor * n/n.abs, (((Float(n.abs)/100).floor*10)+(n.abs%10)) * n/n.abs].max