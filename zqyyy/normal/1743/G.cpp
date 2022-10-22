#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use it in interactive problems!!!
	static char *p1, *p2, buf[1<<10];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<10, stdin), p1==p2?'\n':*p1++):*p1++; // '\n' for function isspace in function readstr 
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc(); (*s++)='\0';
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
const int mod=998244353;
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
int f, sum, fib[32];
vector<pair<int, int> >suf; // maintain fib suffix
int get(int x) { //(x+1)th
	if (x<=1) return x^1;
	int p=upper_bound(fib, fib+32, x)-fib-1;
	return get(x-fib[p]);
}
inline void add(int o) {
	int now=sub(sum, f);
	vector<pair<int, int> >tmp;
	if (o) tmp.push_back({1, f});
	for (auto &[l, v]:suf)
		if (get(l)==o){
			tmp.push_back({l+1, v});
			if (binary_search(fib, fib+32, l+1)) dec(now, v);
		}
	f=now, inc(sum, now), swap(suf, tmp);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	fib[0]=1, fib[1]=2, f=sum=1;
	for (int i=2; i<32; i++) fib[i]=fib[i-1]+fib[i-2];
	for (int n=read(); n; n--) {
		static char str[1007]; read(str+1); int m=strlen(str+1);
		for (int i=1; i<=m; i++) add(str[i]&1);
		printf("%d\n", f);
	}
	return 0;
}