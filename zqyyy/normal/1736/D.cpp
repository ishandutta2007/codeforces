#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() {
	return getchar();
	static char *p1, *p2, buf[1<<20];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<20, stdin), p1==p2?EOF:*p1++):*p1++;
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
const int N=2e5+7;
int n;
char str[N];
inline void work() {
	n=read()*2, scanf("%s", str+1);
	if (count(str+1, str+n+1, '0')&1) {puts("-1"); return;}
	vector<int>vec;
	for (int i=1; i<=n; i+=2)
		if (str[i]!=str[i+1]) {
			int x=i+(str[i]=='1'), y=(i+1)^i^x;
			vec.push_back(vec.size()&1?x:y);
		}
	printf("%lu ", vec.size());
	for (int x:vec) cout<<x<<" "; cout<<endl;
	for (int i=2; i<=n; i+=2) printf("%d%c", i, " \n"[i==n]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}