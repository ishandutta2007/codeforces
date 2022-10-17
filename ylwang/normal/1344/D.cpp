#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define rint register int
#define INF ((1ll << 63) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(int i = (k); i >= (j); i--)
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
#define int long long
const int P = 1000000007; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(ll x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MAXN = 1e5 + 5;
#define add(i, x) ((x < a[i]) ? (a[i] - 3 * (x + 1) * (x + 1) + 3 * (x + 1) - 1) : -LLONG_MAX)
int n, K, a[MAXN];
bool check(int t) {
	int cnt = 0;
	For(i, 1, n) {
		int l = 0, r = a[i] - 1, pos = 0;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(-add(i, mid) < t) pos = mid + 1, l = mid + 1;
			else r = mid - 1;
		}
		cnt += pos;
	}
//	cerr << t << ' ' << cnt << endl;
	return cnt < K;
}
int ans[MAXN];
struct Node {
	int x, y;
	Node (int tx, int ty) : x(tx), y(ty) {}
	bool operator < (const Node &b) const {return y < b.y;}
};
priority_queue < Node > q;
void solve(int t) {
//	cerr << t << endl;
	For(i, 1, n) {
		int l = 0, r = a[i] - 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(-add(i, mid) < t) ans[i] = mid + 1, l = mid + 1;
			else r = mid - 1;
		}
		K -= ans[i]; 
//		cerr << ans[i] << ' ';
	}
//	cerr << K << endl;
	For(i, 1, n) {
//		cerr << add(i, ans[i]) << ' ' << t << endl;
		if(-add(i, ans[i]) == t) ans[i]++, K--;
		if(!K) break;
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE 
    	file("pro");
    #endif
	n = read(), K = read();
	For(i, 1, n) a[i] = read();
	ll l = -4e18, r = 4e18;
	while(l <= r - 2) {
//		cerr << l << ' ' << r << endl;
		int mid = (l + r) >> 1;
		if(check(mid)) {
			l = mid;
		} else r = mid;
	}
//	cerr << l << ' ' << r << endl;
//cerr << check(l) << endl;
	r = check(r) ? r : l;
	solve(r);
	For(i, 1, n) printf("%lld ", ans[i]);
    return FastIO::Fflush(), 0;
}
/*
ai - s3x^2 + 3x - 1
*/