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
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 1000005
#define MOD 998244353
int n, ans;
int a[MAXN];

inline int turn(int u) {
	int ans = 0;
	int pos[11], m = 0;
	while(u) {
		int qwq = u % 10; u /= 10;
		pos[++m] = qwq;
	}
	for(int i = m; i >= 1; i--) ans = (ans * 100 + pos[i]) % MOD;
	return ans;
}
signed main()
{
	n = read();
	For(i, 1, n) a[i] = read(); 
	For(i, 1, n) ans = (ans + (turn(a[i])) * 11 % MOD * n % MOD) % MOD;
	cout << ans << endl;
	return 0;
}