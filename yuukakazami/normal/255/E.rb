gets;x,A,B=0,[4,16,82,6724,50626,2562991876],[0,1,2,0,3,1,2]
for a in gets.split.map &:to_i do
  x^=B[A.count {|i| a>=i}]
end
puts (x==0?"Rublo":"Furlo")