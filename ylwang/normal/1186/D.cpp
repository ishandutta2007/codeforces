#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define int long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 100005
double a[MAXN];
int b[MAXN];
int flag[MAXN];
signed main()
{
	int n = read();
	For(i, 1, n) {
		scanf("%lf", &a[i]);
		b[i] = floor(a[i]);
		if(a[i] - b[i] <= 1e-5) {
			flag[i] = 1;
		}
	}
	int sum = 0;
	For(i, 1, n) {
		sum += b[i];
	}
	For(i, 1, n) {
		if(flag[i]) continue;
		if(sum < 0) b[i]++, sum++;
		if(sum > 0) b[i]--, sum--;
	}
	For(i, 1, n) {
		printf("%lld\n", b[i]);
	}
    return 0;
}