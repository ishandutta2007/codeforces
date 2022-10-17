#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
int a[MAXN], p[MAXN];
int cnt[MAXN];
int used[MAXN];
bool cmp(int a, int b) {return a > b;}
signed main()
{
	int T = read();
	while(T--) {
		int n = read();
		For(i, 1, n) cnt[i] = 0, used[i] = 0;
		For(i, 1, n) {
			a[i] = read();
			cnt[a[i]]++; 
//			p[i] = read();
		}
		sort(cnt+1, cnt+1+n, cmp);
		int ans = 0;
		For(i, 1, n) {
			if(cnt[i] == 0) break;
			ans += cnt[i];
			cnt[i+1] = min(cnt[i+1], cnt[i]-1);
		}
		printf("%d\n", ans);
	}
    return 0;
}