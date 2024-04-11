#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
}
const int MAXN = 6e5 + 5;
int v[MAXN], n, m, ipw[MAXN], pw[MAXN], disc[MAXN], t;
Pair q[MAXN];
map < int, int > pos;
struct Segment_tree {
	int res[MAXN<<2], lv[MAXN<<2], rv[MAXN<<2], cnt[MAXN<<2];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void pushup(int k, int l, int r) {
//		cerr << k << ' ' << res[k] << endl;
		res[k] = ((res[ls] + res[rs]) % P + rv[ls] * lv[rs] % P) % P, cnt[k] = cnt[ls] + cnt[rs];
		lv[k] = (lv[ls] + lv[rs] * ipw[cnt[ls]]) % P;
		rv[k] = (rv[rs] + rv[ls] * ipw[cnt[rs]]) % P;
//		cerr << k << ' ' << lv[k] << ' ' << rv[k] << ' ' << res[k] << endl;
	}
	void update(int k, int l, int r, int pos, int v) {
		if(l == r) {
//			cerr << pos << ' ' << disc[pos] << ' ' << (1ll * disc[pos] * v * ipw[1] % P + P) % P << endl;
			return rv[k] = lv[k] = (1ll * disc[pos] * v * ipw[1] % P + P) % P, cnt[k] = v, void();
		}
		pos <= mid ? update(ls, l, mid, pos, v) : update(rs, mid+1, r, pos, v);
		pushup(k, l, r);
	}
	 
}tr;
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	pw[0] = ipw[0] = 1;
	For(i, 1, 600000) {
		pw[i] = pw[i-1] * 2 % P;
		ipw[i] = ipw[i-1] * 500000004ll % P;
	}
	FI(n);
	For(i, 1, n) FI(v[i]), disc[++t] = v[i];
	FI(m);
	For(i, 1, m) FI(q[i].first), FI(q[i].second), disc[++t] = q[i].second;
	sort(disc + 1, disc + 1 + t);
	For(i, 1, n) {
		int tmp = v[i];
		if(pos[tmp] == 0) {
			v[i] = pos[tmp] = lower_bound(disc + 1, disc + 1 + t, tmp) - disc;
		} else {
			v[i] = ++pos[tmp];
		} 
	}
	For(i, 1, m) {
		int tmp = q[i].second;
		if(pos[tmp] == 0) {
			q[i].second = pos[tmp] = lower_bound(disc + 1, disc + 1 + t, tmp) - disc;
		} else {
			q[i].second = ++pos[tmp];
		} 
	}
	For(i, 1, n) {
//		cerr << v[i] << ' ' << disc[v[i]] << endl;
		tr.update(1, 1, t, v[i], 1);
	}
//	cerr << endl;
	printf("%lld\n", tr.res[1]);
	For(i, 1, m) {
		tr.update(1, 1, t, v[q[i].first], 0);
		v[q[i].first] = q[i].second;
//		cerr << endl;
		tr.update(1, 1, t, v[q[i].first], 1);
		printf("%lld\n", tr.res[1]);
//		cerr << endl;
	}
	
    return FastIO::Fflush(), 0;
}
/*

*/