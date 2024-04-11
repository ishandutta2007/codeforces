#pragma GCC optimize(3)
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
 
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
 
inline void printarray(int *a, int n) {For(i, 1, n) fprintf(stderr, "%d ", a[i]); fprintf(stderr, "\n");}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 2e5 + 5;
int vis[MAXN], prime[MAXN], mu[MAXN], phi[MAXN], cnt = 0; 
void init(int n) {
    mu[1] = phi[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) prime[++cnt] = i, mu[i] = -1, phi[i] = i - 1;
        for(int j = 1; j <= cnt && i* prime[j] <= n; j++) {
            vis[i * prime[j]] = 1;
            if(i % prime[j] != 0) {
                mu[i * prime[j]] = -mu[i];
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            } else {
                mu[i * prime[j]] = 0;
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}
int n;
int ask(char c, int a) {
	printf("%c %lld\n", c, a);
	fflush(stdout);
	int x; scanf("%lld", &x);
	return x;
}
int find(int x) {
	int l = 1, r = 0, res = 0;
	while(ksm(x, r + 1) <= n) r++;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(ask('A', ksm(x, mid))) {
			l = mid + 1, res = ksm(x, mid);
		} else {
			r = mid - 1;
		}
	}
	return res;
}
vector < int > fac;
int p[MAXN];
signed main()
{
	srand(time(0));
    cin >> n;
    init(n);
    For(i, 1, min(67ll, cnt)) {
    	int x = ask('B', prime[i]), y = ask('A', prime[i]);
    	if(y) fac.pb(i);
	}
	const int T = 68;
	if(cnt >= T) {
		int now = 0, lst = T, tot = ask('A', 1);
		For(i, T, cnt) p[i] = i;
		random_shuffle(p + T, p + 1 + cnt);
		For(i, T, cnt) {
			int x = ask('B', prime[p[i]]);
			if(x > 1) {
				fac.pb(p[i]); break;
			}
			now++;
			if(now == 500 || i == cnt) {
				now = 0;
				if(ask('A', 1) != tot - (i - T + 1)) {
					For(j, lst, i) if(ask('B', prime[p[j]])) {
						cout << 'C' << ' ' << prime[p[j]] << endl;
						fflush(stdout); return 0;
					}
				}
				lst = i;
			}
		}
	}
	
//	assert(ask('A', 1) == 2);
	int res = 1;
	for(auto v : fac) {
		res *= find(prime[v]);
	}
	cout << 'C' << ' ' << res << endl;
	fflush(stdout);
    return FastIO::Fflush(), 0;
}
/*
Think twice :
mod ?
INF ?
n = 1 ?
long long ?
Fastio::Fflush() ?
 
*/