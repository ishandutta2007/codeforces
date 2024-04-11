def r() gets.to_s.split.map &:to_i end
n,x,o=*r,*r;
n.times do
  a,b=*r;o||=[a,b,7-a,7-b].include? x
end
print o ? "NO" : "YES"