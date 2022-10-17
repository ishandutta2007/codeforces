#pragma GCC optimize(2)
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
const int P = 998244352; //
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
};
int n;
const int MAXN = 200005;
struct Splay {
	int tot, rt, siz[MAXN], f[MAXN], val[MAXN], sum[MAXN], rep[MAXN], c[MAXN][2];
	void clear(int x) {f[x] = siz[x] = val[x] = sum[x] = rep[MAXN] = c[x][0] = c[x][1] = 0;}
	int create(int v) {
		val[++tot] = v;
		siz[tot] = rep[tot] = 1;
		c[tot][0] = c[tot][1] = 0;
		return tot;
	}
	bool get(int x) {return c[f[x]][1] == x;}
	void pushup(int x) {
		if(x) {
			siz[x] = rep[x], sum[x] = val[x] * rep[x];
			if(c[x][0]) siz[x] += siz[c[x][0]], sum[x] += sum[c[x][0]];
			if(c[x][1]) siz[x] += siz[c[x][1]], sum[x] += sum[c[x][1]];                
		}
	}
	void connect(int x, int y, int z) {
		if(x) f[x] = y;
		if(y) c[y][z] = x;
	}
	void rotate(int x) {
		int fa = f[x], ffa = f[fa], nx = get(x), nf = get(fa);
		connect(c[x][nx^1], fa, nx);
		connect(fa, x, nx^1);
		connect(x, ffa, nf);
		pushup(fa); pushup(x);
	}
	void splay(int x) {
		for(int fa; fa = f[x]; rotate(x)) {
			if(f[fa]) rotate(get(x)==get(fa) ? fa : x);
		}
		rt = x;
	}
	void insert(int v) {
//		cout << v << endl;
		if(!rt) {
			rt = create(v);
			return;
		}
		int now = rt, fa = 0;
		while(1) {
			if(val[now] == v) {
				rep[now]++;
				pushup(now); pushup(fa);
				splay(now);
				return;
			} 
			fa = now, now = c[now][v>val[now]];
			if(!now) {
				now = create(v);
				f[tot] = fa, c[fa][v>val[fa]] = tot;
				pushup(tot); pushup(fa);
				splay(tot);
				return;
			}
		}	
	}
	int getrank(int v) {
		int now = rt, ans = 0;
		while(1) {
			if(v < val[now])
				now = c[now][0];
			else {
				ans += siz[c[now][0]];
				if(v == val[now]) {splay(now); return ans + 1;}
				ans += rep[now], now = c[now][1];
			}
		}
	}
	int getval(int k) {
		int now = rt;
		while(1) {
			if(c[now][0] && k <= siz[c[now][0]])
				now = c[now][0];
			else {
				if(c[now][0]) k -= siz[c[now][0]];
				if(k <= rep[now]) {splay(now); return val[now];}
				k -= rep[now], now = c[now][1];
			}
		}
	}
	void del(int x) {
		int IAKIOI = getrank(x), tmp = rt;// splay 
		if(rep[rt] > 1) {
			rep[rt]--;
			pushup(rt);
		} else if(!c[rt][0] && !c[rt][1]) {
			clear(rt); rt = 0; // rt = 0 
		} else if(!c[rt][0]) {
			f[rt = c[rt][1]] = 0;
			clear(tmp);
		} else if(!c[rt][1]) {
			f[rt = c[rt][0]] = 0;
			clear(tmp);
		} else {
			int lef = c[rt][0];
			while(c[lef][1]) 
				lef = c[lef][1];
			splay(lef);
			connect(c[tmp][1], rt/*(rt)*/, 1);//
			clear(tmp); pushup(rt);
		}
	}
	int qval(int x) {
		if(x == 0) return 0;
		return getval(x);
	}
	int query(int x) {
		if(x == 0) return 0;
		int IAKIOI = getval(x);
		return sum[c[rt][0]] + val[rt] * (x - siz[c[rt][0]]);
	}
}tr;
int tot = 0, sum = 0, k;
multiset < int > s[2];
signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
	#endif
	cin >> n;
	s[1].insert(INF); s[0].insert(0);
	For(TTT, 1, n) {
//		cerr << TTT << endl;
		int o, d; FI(o); FI(d); sum += d;
		assert(sum >= 0);
		if(d < 0) {
			if(o == 0) k--;
			tr.del(-d); s[o].erase(s[o].find(-d));
		} else {
			if(o == 0) k++;
			tr.insert(d); s[o].insert(d);
		}
		int t0 = (*--s[0].end()), t1 = (*s[1].begin());
//		cerr << t0 << ' ' << t1 << endl;
//		cerr << TTT << endl;
//		cerr << k << ' ' << tr.query(k) << endl;
//cerr << k << ' ' << tr.qval(k) << endl;
		if(t0 >= t1) printf("%lld\n", sum * 2 - tr.query(k));
		else if(t1 != INF) printf("%lld\n", sum * 2 - tr.query(k) - t1 + t0);
		else printf("%lld\n", sum);
//		cerr << TTT << endl;
	}
    return FastIO::Fflush(), 0;
}