f[a,b,r]=if(a >= 2*r && b >= 2*r) then "First" else "Second"
main=interact$f.map read.words