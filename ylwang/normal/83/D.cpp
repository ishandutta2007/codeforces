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
//#define int long long
const int P = 998244353; //
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
const int MAXN = 3e7 + 5;
int tot = -1, prime[MAXN];
bool vis[MAXN], t[MAXN];
int l, r, k;
void init() {
	vis[1] = 0;
	For(i, 2, max(r / 70, 70)) {
		if(!vis[i]) prime[++tot] = i;
		for(int j = 0; j <= tot && i * prime[j] <= max(r / 70, 70); j++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
//	For(i, 0, tot) {
//		cerr << prime[i] << endl;
//	}
//	cerr << prime[0] << endl;
	For(i, 1, r / 70) t[i] = 1;
	For(i, 0, tot) {
		if(prime[i] >= k) break;
		for(int j = 1; prime[i] * j <= r / 70; j++)
			t[prime[i] * j] = 0;
	}
//	For(i, 1, r / 70) cerr << (t[i] ^ 1) << endl;
//	cerr << endl;
}
int solve(int x) {
	if(k == 2) return x / 2;
	if(k == 3) return x / 3 - x / 6;
	if(k == 5) return x / 5 - x / 10 - x / 15 + x / 30;
	if(k <= 70) {
		int pos = 0; while(prime[pos] != k) pos++; pos--; 
//		cerr << pos << ' ' << prime[pos] << endl;
		ll res = 0; 
		for(int st = 0; st < (1 << (pos+1)); st++) {
			int cnt = 0; ll mul = k;
			for(int i = 0; i <= pos; i++) {
				if((st >> i) & 1) {
					cnt++, mul *= prime[i];
					if(mul > x) goto tend;
				}
			}
			res += ((cnt & 1) ? -1 : 1) * (x / mul);
			tend:;
		}
//		cerr << x << ' ' << res << endl;
		return res;
	}
//	cerr << x << endl;
	int res = 0;
	for(int i = 1; i <= x / k; i++) {
		res += t[i];
	}
	return res;
}
bool isprime(int x) {
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) return 0;
	}
	return 1;
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	cin >> l >> r >> k;
//	cerr << l <<' ' << r << ' ' <<k << endl;
	if(!isprime(k)) return printf("0\n"), 0;
	if(1ll * k * k > r) {
		if(k > r) return printf("0\n"), 0;
		else if(k >= l) return printf("1\n"), 0;
	}
	init(); 
//	cerr << r << endl;
	printf("%d\n", solve(r) - solve(l - 1));
    return FastIO::Fflush(), 0;
}
/*

*/