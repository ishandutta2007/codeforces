#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() {
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc();
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=17, mod=1e9+7;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int m, b[N], id[N], pos[N];
using T=vector<vector<int> >;
T solve(int n, const T tmp) {
	if (!n) return tmp; T vec=solve(n-1, tmp);
	for (int i=0; i<=(int)vec.size()-2; i++) vec[i].push_back(i&1);
	vec.back().push_back(0); auto Tmp=vec.back(); Tmp.back()^=1;
	for (int i=vec.size()-2; ~i; i--) vec.push_back(vec[i]), vec.back().back()^=1;
	vec.push_back(vector<int>(vec.back().size()-1, 0)), vec.back().push_back(1), vec.push_back(Tmp);
	return vec;
}
#define GG return (void)puts("-1");
inline void work() {
	m=read();
	for (int i=0; i<m; i++) b[i]=read();
	iota(id, id+m, 0), sort(id, id+m, [&](const int &x, const int &y) {return b[x]>b[y];});
	for (int i=0; i<m; i++) pos[id[i]]=i;
	sort(b, b+m, greater<int>()); T ans;
	if (b[0]>=4) {GG;}
	else if (b[0]==3) {
		if (m>=2 && b[1]>=2) GG;
		ans=solve(m-1, {{3}, {1}, {2}});
	} else if (b[0]==2) {
		if (m>=3 && b[2]==2) GG;
		if (m==1 || b[1]==1) ans=solve(m-1, {{2}, {1}});
		else ans=solve(m-2, {{2, 2}, {0, 1}, {1, 2}, {2, 0}, {1, 0}, {2, 1}, {0, 2}, {1, 1}});
	} else {
		if (m==1) ans={{1}};
		else ans=solve(m-2, {{1, 0}, {1, 1}, {0, 1}});
	}
	for (auto &x:ans)
		for (int i=0; i<m; i++)
			printf("%d%c", x[pos[i]], " \n"[i==m-1]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	for (int T=read(); T; T--) work();
	return 0;
}