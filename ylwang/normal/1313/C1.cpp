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
#define int long long
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
    for(;isdigit(c);num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 500005;
int n, a[MAXN], l[MAXN], r[MAXN];
vector < pair < int, int > > v;
signed main()
{
	n = read();
	For(i, 1, n) a[i] = read();
	v.pb(mkp(0, 0)); v.pb(mkp(1, a[1])); l[1] = a[1];
	For(i, 2, n) {
		while(a[i] < v[v.size()-1].second) v.pop_back();
		int k = v[v.size()-1].first;
		l[i] = l[k] + (i - k) * a[i];
		v.pb(mkp(i, a[i]));
	}
	v.clear();
	v.pb(mkp(n+1, 0)); v.pb(mkp(n, a[n])); r[n] = a[n];
	foR(i, n-1, 1) {
		while(a[i] < v[v.size()-1].second) v.pop_back();
		int k = v[v.size()-1].first;
		r[i] = r[k] + (k - i) * a[i];
		v.pb(mkp(i, a[i]));
	}
//	For(i, 1, n) cout << l[i] << ' ' << r[i] <<endl;
	int pos = 0;
	For(i, 1, n) {
		if(r[i] + l[i] - a[i] > r[pos] + l[pos] - a[pos])
			pos = i;
	}
	foR(i, pos-1, 1)
		ckmin(a[i], a[i+1]);
	For(i, pos+1, n)
		ckmin(a[i], a[i-1]);
	For(i, 1, n) {
		printf("%d ", a[i]);
	} 
    return 0;
}