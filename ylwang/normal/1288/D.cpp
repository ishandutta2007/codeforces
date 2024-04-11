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
const int MAXN = 300005, MAXM = 10;
int a[MAXN][MAXM], n, m, b[MAXN], exi[2005];
pair < int, int > check(int mid) {
	mst(b, 0); mst(exi, 0);
	For(i, 1, n)
		For(j, 1, m) 
			b[i] = b[i] * 2 + (a[i][j] >= mid);
//	For(i, 1, n) if(b[i] == (1 << m) - 1) return mkp(i, i);
	For(i, 1, n) exi[b[i]] = 1;
	vector < int > tmp; tmp.clear();
	For(i, 0, (1 << m)) if(exi[i]) tmp.pb(i);
	for(auto u : tmp) {
		for(auto v : tmp) {
			if((u | v) == ((1 << m) - 1)) {
				pair < int, int > ans;
				For(i, 1, n) {
					if(b[i] == u) ans.first = i;
					if(b[i] == v) ans.second = i;
				}
				return ans;
			}
		}
	}
	return mkp(-1, -1);
}
signed main()
{
	cin >> n >> m;
	For(i, 1, n) For(j, 1, m)
		a[i][j] = read();
	int l = 0, r = 1000000000, ai = 1, aj = 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		pair < int, int > tmp = check(mid);
//		cout << tmp.first << ' ' << tmp.second << endl;
		if(tmp.first != -1) ai = tmp.first, aj = tmp.second, l = mid+1;
		else r = mid-1;
	}
	cout << ai << ' ' << aj << endl;
    return 0;
}