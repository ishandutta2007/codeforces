#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define int long long
using namespace std;

inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MOD 1000000007
int l, r;
int getsum(int n) {
	if(n == 0) return 0;
	int pos[10], nowpos = 0, ans = 0, now = 1;
	pos[1]= 0, pos[2] = 0;
	for(int i = 0; nowpos <= n; i++) {
		int tmppos;
		if(nowpos == n) break;
		if(nowpos + (1ll << i) <= n) {
			nowpos += (1ll << i);
			tmppos = pos[now] + (1ll << i);
			pos[now]++;
		} else if(nowpos + (1ll << i) > n) {
			tmppos = (n - nowpos) + pos[now];
			pos[now]++;
			nowpos = n + 1;
		}
		int num = (tmppos - pos[now] + 1) % MOD;
		ans += (((pos[now] + tmppos) % MOD) * num - (now == 1) * num) % MOD;
		if(nowpos != n + 1) pos[now] = tmppos;
//		cout << now << ' ' << pos[1] << ' ' << pos[2] << ' ' << num << ' ' << ans << endl;
		if(now == 1) now = 2;
		else now = 1;
	}
//	cout << num << endl;
	return ans;
}
signed main()
{
	l = read(), r = read();
	cout << ((getsum(r) - getsum(l-1)) % MOD + MOD) % MOD << endl;
    return 0;
}
/*

*/