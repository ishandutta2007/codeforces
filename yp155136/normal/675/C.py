from collections import Counter

n = int(input())
c = Counter();

num = list(map(int,input().split()));

for i in range(1,n) :
    num[i] += num[i-1];
c.update(num);
print(n - c.most_common()[0][1])