def main(a,b,w=False):
    if not b:
        return None if a else ''
    if len(a)<len(b):
        return ''.join(sorted(a)[::-1])
    if ''.join(sorted(a))>b:
        return
    if b[0] in a:
        i=a.index(b[0])
        a[i],a[0]=a[0],a[i]
        m=main(a[1:],b[1:],True)
        if m is not None:
            return a[0]+m
    for i in reversed(range(1-w,int(b[0]))):
        if str(i) in a:
            ind=a.index(str(i))
            a[ind],a[0]=a[0],a[ind]
            m=''.join(sorted(a[1:])[::-1])
            if m is not None:
                return a[0]+m
    return
a=input()
b=input()
print(main(list(a),b))