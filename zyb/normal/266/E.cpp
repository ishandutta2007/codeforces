#include<stdio.h>
#define P 1000000007
#define N 100005
using namespace std;
int C[10][10],a[N],i,j,k,l,s,n,m,x,y,z;
int F[2*N][10];
struct node {
	int s[6][6],x[6][6],d;
}f[N*4];

inline void doit() {
	for (i=0;i<=5;i++) 
	for (C[i][0]=1,j=1;j<=i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
}
inline int quick(int o,int p) {
	int s=1;
	while (p) {
		if (p&1) s=1ll*s*o%P;
		o=1ll*o*o%P;
		p>>=1;
	}
	return s;
}
inline void Up(int o) {
	for (int i=0;i<=5;i++) for (j=0;j<=i;j++) f[o].s[i][j]=(f[o*2].s[i][j]+f[o*2+1].s[i][j])%P,f[o].x[i][j]=(f[o*2].x[i][j]+f[o*2+1].x[i][j])%P;
}
inline void up(int o) {
	for (int i=0;i<=5;i++) for (j=0;j<=i;j++) f[o].s[i][j]=(f[o*2].s[i][j]+f[o*2+1].s[i][j])%P;
}
inline void build(int o,int l,int r) {
	f[o].d=-1;
	if (l==r) {
		for (int i=0;i<=5;i++)
		for (int j=0;j<=i;j++) {
			if (!F[l+N][i-j]) F[l+N][i-j]=quick(l,i-j);
			f[o].x[i][j]=(1ll*F[l+N][i-j]*C[i][j])%P,f[o].s[i][j]=(1ll*f[o].x[i][j]*a[l])%P;
		}
		return ;
	}
	int mid=(l+r)>>1;
	build(o*2,l,mid),build(o*2+1,mid+1,r);
	Up(o);
}
inline void down(int o,int l,int r) {
	int mid=(l+r)>>1;
	for (int i=0;i<=5;i++)
	for (int j=0;j<=i;j++)
	f[o*2].s[i][j]=(1ll*f[o].d*f[o*2].x[i][j])%P,f[o*2+1].s[i][j]=(1ll*f[o].d*f[o*2+1].x[i][j])%P;
	f[o*2].d=f[o*2+1].d=f[o].d;
	f[o].d=-1;
}
inline void change(int o,int l,int r,int ll,int rr,int p) {
	if (l==ll&&r==rr) {
		for (int i=0;i<=5;i++)
		for (int j=0;j<=i;j++)
		f[o].s[i][j]=(1ll*p*f[o].x[i][j])%P;
		f[o].d=p;
		return ;
	}
	if (f[o].d!=-1) down(o,l,r);
	int mid=(l+r)>>1;
	if (rr<=mid) change(o*2,l,mid,ll,rr,p);
	else if (ll>mid) change(o*2+1,mid+1,r,ll,rr,p);
	else change(o*2,l,mid,ll,mid,p),change(o*2+1,mid+1,r,mid+1,rr,p);
	up(o);
}
inline int ask(int o,int l,int r,int ll,int rr,int L,int p) {
	if (l==ll&&r==rr) {
		int s=0;
		for (int j=0;j<=p;j++) {
			if (!F[L+N][j]) F[L+N][j]=quick(L,j);
			s=(s+1ll*f[o].s[p][j]*F[L+N][j])%P;
		}
		return s;
	}
	int mid=(l+r)>>1;
	int s=0;
	if (f[o].d!=-1) down(o,l,r);
	if (rr<=mid) s=ask(o*2,l,mid,ll,rr,L,p);
	else if (ll>mid) s=ask(o*2+1,mid+1,r,ll,rr,L,p);
	else s=(ask(o*2,l,mid,ll,mid,L,p)+ask(o*2+1,mid+1,r,mid+1,rr,L,p))%P;
	return s;
}
inline int in() {
	char c=getchar();
	int s=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') s=s*10+c-48,c=getchar();
	return s;
}
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) a[i]=in();
	doit();
	build(1,1,n);
	for (i=1;i<=m;i++) {
		char c=getchar();
		while (c!='='&&c!='?') c=getchar();
		if (c=='=') {
			x=in(),y=in(),z=in();
			change(1,1,n,x,y,z);
		}	
		else {
			x=in(),y=in(),z=in();
			printf("%d\n",(ask(1,1,n,x,y,1-x,z)+P)%P);
		}	
	}
}