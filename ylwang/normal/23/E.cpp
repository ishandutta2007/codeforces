#pragma GCC optimize("Ofast")
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

struct bigint{
	static const int MAXN = 115;
    int d[MAXN], len;
	void clean() { while(len > 1 && !d[len-1]) len--; }
    bigint() { memset(d, 0, sizeof(d)); len = 1; }
    bigint(int num) { *this = num; } 
	bigint(char* num) { *this = num; }
    bigint operator = (const char* num){
        memset(d, 0, sizeof(d)); len = strlen(num);
        for(int i = 0; i < len; i++) d[i] = num[len-1-i] - '0';
        clean();
		return *this;
    }
    bigint operator = (int num) {
        char s[20]; sprintf(s, "%d", num);
        *this = s; return *this;
    }
 
    bigint operator + (const bigint& b) {
        bigint c = *this; int i;
        for (i = 0; i < b.len; i++){
        	c.d[i] += b.d[i];
        	if (c.d[i] > 9) c.d[i]%=10, c.d[i+1]++;
		}
		while (c.d[i] > 9) c.d[i++]%=10, c.d[i]++;
		c.len = max(len, b.len);
		if (c.d[i] && c.len <= i) c.len = i+1;
        return c;
    }
    bigint operator - (const bigint& b) {
        bigint c = *this; int i;
        for (i = 0; i < b.len; i++){
        	c.d[i] -= b.d[i];
        	if (c.d[i] < 0) c.d[i]+=10, c.d[i+1]--;
		}
		while (c.d[i] < 0) c.d[i++]+=10, c.d[i]--;
		c.clean();
		return c;
    }
    bigint operator * (const bigint& b)const {
        int i, j; bigint c; c.len = len + b.len; 
        for(j = 0; j < b.len; j++) for(i = 0; i < len; i++) 
			c.d[i+j] += d[i] * b.d[j];
        for(i = 0; i < c.len-1; i++)
            c.d[i+1] += c.d[i]/10, c.d[i] %= 10;
        c.clean();
		return c;
    }
    bigint operator / (const bigint& b) const {
    	int i, j;
		bigint c = *this, a = 0;
    	for (i = len - 1; i >= 0; i--) {
    		a = a*10 + d[i];
    		for (j = 0; j < 10; j++) if (a < b*(j+1)) break;
    		c.d[i] = j;
    		a = a - b*j;
    	}
    	c.clean();
    	return c;
    }
    bigint operator % (const bigint& b) const {
    	int i, j;
		bigint a = 0;
    	for (i = len - 1; i >= 0; i--) {
    		a = a*10 + d[i];
    		for (j = 0; j < 10; j++) if (a < b*(j+1)) break;
    		a = a - b*j;
    	}
    	return a;
    }
    bool operator <(const bigint& b) const{
        if(len != b.len) return len < b.len;
        for(int i = len-1; i >= 0; i--)
            if(d[i] != b.d[i]) return d[i] < b.d[i];
        return false;
    }
    bigint operator /= (const bigint &b) { *this  = *this / b; return *this; }
    bigint operator *= (const bigint &b) { *this  = *this * b; return *this; }
    bigint operator += (const bigint &b) { *this  = *this + b; return *this; }
    bigint operator -= (const bigint &b) { *this  = *this - b; return *this; }
    bool operator >(const bigint& b) const{return b < *this;}
    bool operator<=(const bigint& b) const{return !(b < *this);}
    bool operator>=(const bigint& b) const{return !(*this < b);}
    bool operator!=(const bigint& b) const{return b < *this || *this < b;}
    bool operator==(const bigint& b) const{return !(b < *this) && !(b > *this);}
    string str() const {
        char s[MAXN]={};
        for(int i = 0; i < len; i++) s[len-1-i] = d[i]+'0';
        return s;
    }
};
istream& operator >> (istream& in, bigint& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator << (ostream& out, const bigint& x)
{
    out << x.str();
    return out;
}
const int MAXN = 705;
vector < int > e[MAXN];
int n, siz[MAXN];

bigint f[MAXN][MAXN], g[MAXN];
void dfs(int u, int fa) {
	siz[u] = 1, f[u][1] = 1;
	for(auto v : e[u]) {
		if(v == fa) continue;
		dfs(v, u);  mst(g, 0);
		For(i, 1, siz[u]) g[i] = f[u][i];
		foR(i, siz[u], 1)
			For(j, 0, siz[v]) {
				bigint t = f[u][i] * f[v][j];
				if(t > g[i+j]) g[i+j] = t;
			}
		siz[u] += siz[v];
		For(i, 1, siz[u]) f[u][i] = g[i];
	}
	For(i, 1, siz[u]) if(f[u][0] < f[u][i] * i) f[u][0] = f[u][i] * i;
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n);
	For(i, 1, n-1) {
		int u, v; FI(u), FI(v); 
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1, 0);
//	For(i, 1, n) {
//		For(j, 0, n) {
//			cerr << f[i][j] << ' ';
//		}
//		cerr << endl;
//	}
//	
	cout << f[1][0] << endl;
    return FastIO::Fflush(), 0;
}
/*

*/