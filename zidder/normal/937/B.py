def main():
    p,y=map(int,input().split())
    i=0
    while i<(10**5)*5:
        if y<=p:
            break
        i+=1
        pr=True
        for w in range(2,p+1):
            if w*w>y:
                break
            if y%w==0:
                pr=False
                break
        if pr:
            print(y)
            return
        y-=1
    print('-1')
main()