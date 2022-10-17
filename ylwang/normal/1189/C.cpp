#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647/3
#define ll long long
using namespace std;
inline int read()
{
    int num=0;char c=' ';
    for(;c>'9'||c<'0';c=getchar());
    for(;c>='0'&&c<='9';num=(num*10+c-48),c=getchar());
    return num;
}
#define MAXN 100005
int n, a[MAXN];
int sum[MAXN];
int main()
{
	n = read();
	For(i, 1, n) a[i] = read(), sum[i] = sum[i-1] + a[i];
	int Querynum = read();
	while(Querynum--) {
		int l = read(), r = read();
		printf("%d\n", (sum[r] - sum[l-1]) / 10);
	}
	return 0;
}