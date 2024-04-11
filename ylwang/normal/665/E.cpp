#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= MOD ? t - MOD : t); }
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
#define MAXN 1000005
int n, k, a[MAXN];
ll ans = 0;
int Trie[MAXN*18][2], tot = 1, sz[MAXN*18];
inline void insert(int x) {
	int p = 1; sz[p]++;
	for(int i = (1 << 30); i; i >>= 1) { 
		int opt = ((x & i) > 0);
		if(!Trie[p][opt])
			Trie[p][opt] = ++tot;
		p = Trie[p][opt]; sz[p]++;
	}
}
inline int query(int x, int y) {
	int p = 1, ans = 0;
	for(int i = (1 << 30); i; i >>= 1) {
		bool opt = ((x & i) > 0) ^ 1;
		bool q = ((y & i) > 0);
		if(!q) ans += sz[Trie[p][opt]], p = Trie[p][opt^1];
		else p = Trie[p][opt];
	}
	return ans+sz[p];
}
signed main()
{
	cin >> n >> k;
	For(i, 1, n)
		a[i] = read() ^ a[i-1];
	insert(0);
	For(i, 1, n) {
		ans += query(a[i], k);
		insert(a[i]);
	}
	cout << ans << endl;
    return 0;
}