n=int(input())
a=input().split()
bad=False
for x in a:
    if(x=='1'):
        bad=True
if(bad):
    print("hard");
else:
    print("easy");