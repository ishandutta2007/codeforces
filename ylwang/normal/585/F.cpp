#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1ll << 62) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); --i)
#define For(i, k, j) for(rint i = (k); i <= (j); ++i)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
#define int long long
const int P = 1000000007; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {a = (a + b + P) % P;}
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
const int MAXN = 1e5 + 5;
int n, d;
struct ACAM {
	int nxt[MAXN][26], cnt[MAXN], tot, fail[MAXN];
	ACAM() {tot = 1;}
	void insert(string s) {
		int p = 1;
		For(i, 0, (int)s.size()-1) {
//			cerr << s << endl;
			if(!nxt[p][s[i]-'0'])  nxt[p][s[i]-'0'] = ++tot;
			p = nxt[p][s[i]-'0'];
		}
		cnt[p] = 1;
	}
	void getfail() {
		queue < int > q; int p = 1; fail[1] = 1;
		For(i, 0, 9)
			if(nxt[1][i]) fail[nxt[1][i]] = 1, q.push(nxt[1][i]);
			else nxt[1][i] = 1;
		while(!q.empty()) {
			p = q.front(); q.pop();
			For(i, 0, 9) {
				int v = nxt[p][i]; 
				if(v) q.push(v), fail[v] = nxt[fail[p]][i];
				else nxt[p][i] = nxt[fail[p]][i];
			}
		}
//		cnt[p] += cnt[fail[p]];
	}
	int f[55][1005*55][2], p[55][2];
	int dp(string t, int d) {
		p[d+1][0] = p[d+1][1] = 1;
		foR(i, d, 0) p[i][0] = p[i+1][0] * 10 % P, p[i][1] = ((t[i] - '0') * p[i+1][0] + p[i+1][1]) % P;
		mst(f, 0);
		f[0][1][1] = 1;
		For(i, 0, d-1) {
			For(j, 1, tot) {
				if(!cnt[j]) {
//					cerr << j << endl;
					For(k, 0, 9) {
						int o = nxt[j][k];
						addmod(f[i+1][o][0], f[i][j][0]);
						if (k < t[i+1] - '0') addmod(f[i+1][o][0], f[i][j][1]);
						if (k == t[i+1] - '0') addmod(f[i+1][o][1], f[i][j][1]);
					}
				}
			}
		}
		int ans = 0;
		For(i, 1, d) For(j, 1, tot) {
			if (cnt[j]) addmod(ans, (f[i][j][0] * p[i+1][0] % P + f[i][j][1] * p[i+1][1] % P) % P);
		}
//		cerr << ans << endl;
		return ans;
	}
	
}tr;
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	string s, x, y; cin >> s >> x >> y;
//	cerr << s << ' ' << x << ' ' << y << endl;
	n = s.size(), d = y.size(); x = ' ' + x, y = ' ' + y;
	int k = d;
	while (x[k] == '0') x[k--] = '9'; x[k]--;
//	cerr << x << endl;
//	cerr << n - d / 2 << endl;
	For(i, 0, n - d / 2) {
		string t = "";
		For(j, i, i + d / 2 - 1) {
			t += s[j];
		}
//		cerr << t << endl;
		tr.insert(t);
//		cerr << "*";
	} 
	tr.getfail();
	printf("%lld\n", (tr.dp(y, d) - tr.dp(x, d) + P) % P);
    return FastIO::Fflush(), 0;
}
/*
LXRXLXL
*/