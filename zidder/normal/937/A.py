n=input()
a=set(map(int,input().split()))
if 0 in a:
    print(len(a)-1)
else:
    print(len(a))