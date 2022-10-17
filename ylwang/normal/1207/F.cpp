#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
#define int long long
using namespace std;
inline int read()
{
    int num=0,flag=1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 500005
int n = 500000;
int a[MAXN], ans[1005][1005];
signed  main()
{
	int m = read(), siz = sqrt(n);
	while(m--) {
		int opt = read(), x = read(), y = read();
		if(opt == 1) {
			For(p, 1, siz) ans[p][x%p] += y;
			a[x] += y;
		} else {
			if(x <= siz) printf("%I64d\n", ans[x][y]);
			else {
				int sum = 0;
				for(int i = y; i <= n; i += x) sum += a[i];
				printf("%I64d\n", sum);
			}
		}
	}
	
	return 0;
}

/*
a ^ b = ans1 ^ ans2
*/