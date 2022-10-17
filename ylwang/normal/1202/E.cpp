#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define Pair pair < int, int >
#define mkp make_pair
#define rint register int
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define Foe(i, u) for(register int i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin);freopen(s".out", "w", stdout)
#define INF ((1 << 30) - 1)
#define dprintf(x) fprintf(stderr, "%d ", x)
#define dprintfln(x) fprintf(stderr, "%d\n", x)
#define dln fprintf(stderr, "\n")
#define ull unsigned long long
#define int long long
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
    for(;isdigit(c);num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 5e5 + 5;
int n; string t, s; 
struct ACAM {
	int nxt[MAXN][26], tot, fail[MAXN], f[MAXN], cnt[MAXN];
	ACAM() {tot = 0; mst(cnt, 0); mst(f, 0);}
	void insert(string s) {
		int p = 0; 
		For(i, 0, (int)s.size()-1) {
			if(!nxt[p][s[i]-'a'])  nxt[p][s[i]-'a'] = ++tot;
			p = nxt[p][s[i]-'a'];
		}
		cnt[p]++;
	}
	void getfail() {
		queue < int > q; int p = 0; fail[0] = 0;
		For(i, 0, 25)
			if(nxt[0][i]) fail[nxt[0][i]] = 0, q.push(nxt[0][i]);
		while(!q.empty()) {
			p = q.front(); q.pop();
//			cout << p << endl;
			For(i, 0, 25) {
				int v = nxt[p][i]; 
//				cout << p << ' ' << v << endl; 
				if(v) q.push(v), fail[v] = nxt[fail[p]][i];
				else nxt[p][i] = nxt[fail[p]][i];
			}
			cnt[p] += cnt[fail[p]];
		}
			
		
	}
	void AC(string s) {
		int u = 0;
		For(i, 0, (int)s.size()-1) {
			u = nxt[u][s[i] - 'a'];
			f[i] = cnt[u];
		}
	}
	
}A, B;

signed main()
{
	IOS;
	cin >> t >> n;
	For(i, 1, n) {
		cin >> s, A.insert(s);
		reverse(s.begin(), s.end()); B.insert(s); 
	}
	A.getfail(); B.getfail();
	A.AC(t);reverse(t.begin(), t.end());B.AC(t);
	int res = 0;
	For(i, 0, (int)t.size()-2) {
		res += A.f[i] * B.f[t.size()-2-i];
	}
	cout << res << endl; 
    return 0;
}