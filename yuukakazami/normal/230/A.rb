def r() gets.to_s.split.map &:to_i end
s,n=*r
a=[];n.times {a<<r}
a.sort.each do |x|
  if x[0]>=s then print 'NO';exit(0);end
  s+=x[1]
end
print 'YES'