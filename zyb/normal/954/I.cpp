#include<bits/stdc++.h>
#define pi acos(-1.0)
#define N 130005
#define eps 1e-8
using namespace std;
struct node {
	double x,y;
}A[N*4],B[N*4],w[2][N*4];
int i,j,k,l,s,n,m,M,rev[N*4];
int ans[N*4][6][6],Ans,fa[N];
char c[N],c1[N];
inline node operator + (node a,node b) { return (node) {a.x+b.x,a.y+b.y};}
inline node operator - (node a,node b) { return (node) {a.x-b.x,a.y-b.y};}
inline node operator * (node a,node b) { return (node) {a.x*b.x-a.y*b.y,a.x*b.y+b.x*a.y};}
inline void pre() {
	for (int i=0;i<M;i++) {
		int j=i,y=0;
		for (int x=1;x<M;x<<=1,j>>=1) (y<<=1)+=j&1;
		rev[i]=y;
	}
	for (int i=0;i<M;i++) w[0][i]=(node){cos(2*pi*i/M),sin(2*pi*i/M)},w[1][i]=(node){cos(2*pi*i/M),-sin(2*pi*i/M)};
}
inline void FFT(node *A,int p) {
	for (int i=0;i<M;i++) if (i<rev[i]) swap(A[i],A[rev[i]]);
	for (int i=1;i<M;i<<=1) 
	for (int j=0,t=M/(i<<1);j<M;j+=i<<1)
	for (int k=0,l=0;k<i;k++,l+=t) {
		node x=w[p][l]*A[i+j+k];
		node y=A[j+k];
		A[j+k]=y+x;
		A[j+k+i]=y-x;
	}
	if (p) for (int i=0;i<M;i++) A[i].x/=M;
}
inline int get(int x) {
	if (fa[x]==x) return x;	
	return fa[x]=get(fa[x]);
}
int main() {
	scanf("%s%s",c,c1);
	n=strlen(c),m=strlen(c1);
	for (M=1;M<=n;M<<=1); 	M<<=1;
	pre();	
	for (i=0;i<6;i++) for (j=0;j<6;j++) {
		if (i==j) continue;
		for (k=0;k<M;k++) A[k].x=A[k].y=B[k].x=B[k].y=0;
		for (k=0;k<n;k++) if (c[k]-97==i) A[k].x=1;
		else A[k].x=0;
		for (k=0;k<m;k++) if (c1[k]-97==j) B[m-k].x=1;
		else B[m-k].x=0;
		FFT(A,0),FFT(B,0);
		for (k=0;k<M;k++) A[k]=A[k]*B[k];
		FFT(A,1);
		for (k=m;k<M;k++) ans[k-m][i][j]=(A[k].x>eps);
	}
	for (i=0;i<=n-m;i++) {
		for (j=0;j<6;j++) fa[j]=j;
		for (j=0;j<6;j++) for (k=0;k<6;k++) if (ans[i][j][k]) fa[get(j)]=get(k);
		for (j=0;j<6;j++) Ans-=(get(j)==j);
		Ans+=6;
		printf("%d ",Ans);
		Ans=0;
	}
	puts("");
}