#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 Int;
inline Int read() {
	Int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
template<class T> inline void write(T x) { if (x>9) write(x/10); putchar(x%10+48); }
template<class T> inline void writeln(T x) { write(x), putchar(10); }
const int N=507;
int n, K, num, cnt[N*N], pos[N], a[N][N];
inline void add(int x) {if (!cnt[x]++) num++;}
inline void del(int x) {if (!--cnt[x]) num--;}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	n=read(), K=read();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) add(a[i][j]=read());
	if (num<=K) printf("%d\n", K-num), exit(0);
	bool fl=false;
	for (int i=1; i<=n; i++) {
		num=0, fill(cnt+1, cnt+n*n+1, 0);
		for (int j=1; j<=n; j++)
			for (int k=1; k<=n; k++) add(a[j][k]);
		pos[1]=0;
		for (int j=1; j<=n; j++) {
			while (max(i, j)+pos[j]-1<n && num>K) {
				int t=++pos[j];
				for (int k=i; k<i+t; k++) del(a[k][j+t-1]);
				for (int k=j; k<j+t-1; k++) del(a[i+t-1][k]);
			}
			fl|=num==K || num==K-1, pos[j+1]=max(pos[j]-1, 0);
			int t=pos[j];
			if (t) {
				for (int k=i; k<i+t; k++) add(a[k][j]);
				for (int k=j+1; k<j+t; k++) add(a[i+t-1][k]);
			}
		}
	}
	if (fl) puts("1");
	else puts("2");
	return 0;
}