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
int n, a[206], q = 0;
string s;
signed main()
{
	cin >> n >> s;
	s = ' ' + s;
	For(i, 1, n)
		a[i] = s[i] == 'B', q += a[i] == 1 ? 1 : -1;
	if(abs(q) % 2 != n % 2) {
		printf("-1\n");
		return 0;
	}
	vector < int > ans;
	ans.clear();
	For(i, 1, n-1) {
		if(a[i] == 1) {
			a[i] ^= 1, a[i+1] ^= 1;
			ans.pb(i);
		}
	}
	if(!a[n]) {
		cout << ans.size() << endl;
		for(auto v : ans)
			cout << v << ' ';
		return 0;
	} else {
		if(n % 2 == 0) {
			printf("-1\n");
			return 0;
		}
		for(int i = 1; i < n; i += 2) {
			a[i] ^= 1, a[i+1] ^= 1;
			ans.pb(i);
		}
		cout << ans.size() << endl;
		for(auto v : ans)
			cout << v << ' ';
		return 0;
	}
    return 0;
}