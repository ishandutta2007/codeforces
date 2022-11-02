n,x,y,c=gets.split.map &:to_i
l,r,x,y=-1,n*2,x-1,y-1
while l+1<r do
  m=(l+r)/2
  t=m*m+(m+1)**2
  4.times do
    t-=(m-x)**2 if x<m
    t+=(m-x-y-1)*(m-x-y)/2 if x+y+2<=m
    x,y=y,n-1-x
  end
  if t>=c then r=m else l=m end
end
p r