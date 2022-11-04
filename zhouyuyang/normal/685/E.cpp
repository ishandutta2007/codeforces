#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010,M=200200;
int i,j,k,n,m,ch,now,q;
int a[N][N],ans[M];
struct cc { int x,y;} A[M];
struct dd { int l,r,s,t,q;} Q[M];
void R(int &x) {
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
bool cmp(const dd &a,const dd &b) {
	return a.r<b.r;
}
void work() {
	now++;
	int x=A[now].x,y=A[now].y;
	a[x][y]=a[y][x]=now;
	for (int i=1;i<=n;i++) a[x][i]=a[y][i]=max(a[x][i],a[y][i]);
}
int main() {
	R(n);R(m);R(q);
	for (i=1;i<=m;i++) R(A[i].x),R(A[i].y);
	for (i=1;i<=q;i++) {
		R(Q[i].l);R(Q[i].r);
		R(Q[i].s);R(Q[i].t);
		Q[i].q=i;
	}
	sort(Q+1,Q+q+1,cmp);
	now=0;
	for (i=1;i<=q;i++) {
		while (now<Q[i].r) work();
		if (a[Q[i].t][Q[i].s]>=Q[i].l) ans[Q[i].q]=1;
	}
	for (i=1;i<=q;i++) {
		if (ans[i]) puts("Yes");
		else puts("No");
	}
}