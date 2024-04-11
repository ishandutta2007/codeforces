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
#define MAXN 200505
int a[MAXN], p[MAXN];
struct Node {
	int num, num1;
	bool operator < (const Node b) const {return num > b.num;}
}cnt[MAXN];
priority_queue < int > wyl;
signed main()
{
	int T = read();
	while(T--) {
		int n = read();
		For(i, 1, n+500) cnt[i].num = cnt[i].num1 = 0;
		while(!wyl.empty()) wyl.pop();
		For(i, 1, n) {
			a[i] = read(), p[i] = read();
			cnt[a[i]].num++; cnt[a[i]].num1 += p[i];
		}
		sort(cnt+1, cnt+1+n);
		int ans = 0, ans1 = 0, pos = 1;
		for(int i = n; i >= 1; i--) {
			while(cnt[pos].num >= i) {
				wyl.push(cnt[pos].num1); pos++;
			}
			if(wyl.empty()) continue;
			int u = wyl.top(); wyl.pop();
			ans1 += min(u, i); ans += i;
		}
		printf("%d %d\n", ans, ans1);
	}
    return 0;
}