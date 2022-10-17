#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
using namespace std;
inline int read()
{
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 200005
int n, fa[MAXN], s[MAXN];
int main()
{
	int n = read();
	For(i, 2, n) fa[i] = read();
	For(i, 1, n) s[i] = read(), s[i] = (~s[i]) ? s[i] : 1e9+1;
	For(i, 2, n) s[fa[i]] = min(s[i], s[fa[i]]);
	ll ans = 0;
	For(i, 1, n) {
		if(s[i] < s[fa[i]]) return puts("-1"), 0;
		if(s[i] <= 1e9) ans += s[i] - s[fa[i]];
	}
	cout << ans << endl;
	return 0;
}