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
const int N=1e6+7, mod=1e9+7;
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
int n, cnt, lst[N], w[N], f[N], sum[N];
char str[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	read(str+1), n=strlen(str+1);
	if (count(str+1, str+n+1, 48)==n) printf("%d\n", n), exit(0);
	int l=1, r=n;
	while (str[l]==48) l++; while (str[r]==48) r--;
	for (int i=l+1, lst=l; i<=r; i++)
		if (str[i]==49) w[++cnt]=i-lst-1, lst=i;
	int ans=(ll)l*(n-r+1)%mod; f[0]=sum[0]=1;
	for (int i=0; i<=n; i++) lst[i]=0;
	for (int i=1; i<=cnt; i++) {
		for (int j=0; j<=w[i]; j++) {
			inc(f[i], sum[i-1]);
			if (lst[j]) dec(f[i], sum[lst[j]-1]);
		}
		fill(lst, lst+w[i]+1, i), sum[i]=add(sum[i-1], f[i]);
	}
	mul(ans, sum[cnt]), printf("%d\n", ans);
	return 0;
}