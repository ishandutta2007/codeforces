a,b,c,d = map(int,(input().split() ))
print(256*min(a,min(c,d)) + 32*(min(b,a-min(a,min(c,d)))))