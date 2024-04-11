#include <bits/stdc++.h>
using namespace std;
inline char getc() {
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=buf+fread(p1=buf, 1, 1<<23, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
const int N=1e5+7;
int n, Q, a[N], lg[N], st1[18][17][N], st2[18][17][N];
inline int qmn(int i, int l, int r) {
	int k=lg[r-l+1];
	return min(st1[i][k][l], st1[i][k][r-(1<<k)+1]);
}
inline int qmx(int i, int l, int r) {
	int k=lg[r-l+1];
	return max(st2[i][k][l], st2[i][k][r-(1<<k)+1]);
}
inline void init_st() {
	lg[0]=-1; for (int i=1; i<=n; i++) lg[i]=lg[i>>1]+1, st1[0][0][i]=st2[0][0][i]=a[i];
	for (int j=1; j<=lg[n]; j++)
		for (int i=1; i+(1<<j)-1<=n; i++) {
			st1[0][j][i]=min(st1[0][j-1][i], st1[0][j-1][i+(1<<j-1)]);
			st2[0][j][i]=max(st2[0][j-1][i], st2[0][j-1][i+(1<<j-1)]);
		}
	for (int k=1; k<=lg[n]+1; k++)
		for (int j=1; j<=lg[n]; j++)
			for (int i=1; i+(1<<j)-1<=n; i++) {
				st1[k][j][i]=qmn(k-1, st1[k-1][j][i], st2[k-1][j][i]);
				st2[k][j][i]=qmx(k-1, st1[k-1][j][i], st2[k-1][j][i]);
			}
}
int main() {
	n=read(), Q=read();
	for (int i=1; i<=n; i++) a[i]=read();
	init_st();
	while (Q--) {
		int l=read(), r=read(), ans=0;
		if (l==1 && r==n) {puts("0"); continue;}
		for (int i=lg[n]+1; ~i; i--) {
			int L=qmn(i, l, r), R=qmx(i, l, r);
			if (L!=1 || R!=n) l=L, r=R, ans|=1<<i;
		}
		tie(l, r)=make_pair(qmn(0, l, r), qmx(0, l, r)), ans++;
		if (l!=1 || r!=n) puts("-1"); else printf("%d\n", ans);
	}
	return 0;
}