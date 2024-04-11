n,x=input().split()
summ=int(x)
ans1=0
ans2=0
for t in range(0,int(n)) :
    global summ,ans1,ans2
    i,j=input().split()
    if i=='+' :
        summ+=int(j)
        pass
    else :
        if summ<int(j) :
            ans2+=1
            pass
        else :
            summ-=int(j)
            pass
        
    
print(str(summ)+" "+str(ans2))