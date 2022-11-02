n,k = map(int, raw_input().split(' '))
a = map(int, raw_input().split(' '))
b = filter(lambda x: x not in a, range(1,n*k+1))
for i in range(0,k):
    print ' '.join(map(str,[a[i]]+b[i*(n-1):(i+1)*(n-1)]))