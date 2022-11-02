k,d=map(int,raw_input().split(' '))
if d==0:
    print ["No solution","0"][k==1]
else:
    print ("%d" % d)+"0"*(k-1)