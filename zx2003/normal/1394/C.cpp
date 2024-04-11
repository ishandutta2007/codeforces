#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,i,j,L,R,M,x[N],y[N],xx,yy,lb[N],rb[N],ly=N,ry,p[N];
char c[N];
inline bool ck(int M){
	for(i=ly;i<=ry;++i)lb[i]=0,rb[i]=N;lb[0]=1;
	int v1,v2;
	v1=1<<30;v2=-v1;
	for(i=ry,j=n;i>=ly;--i){
		for(;j && y[p[j]]>=i;--j)v1=min(v1,x[p[j]]-y[p[j]]),v2=max(v2,x[p[j]]);
		lb[i]=max(lb[i],v2-M);rb[i]=min(rb[i],v1+i+M);
	}
	v1=1<<30;v2=-v1;
	for(i=ly,j=1;i<=ry;++i){
		for(;j<=n && y[p[j]]<=i;++j)v1=min(v1,x[p[j]]),v2=max(v2,x[p[j]]-y[p[j]]);
		lb[i]=max(lb[i],v2+i-M);rb[i]=min(rb[i],v1+M);
	}
	for(i=max(ly,ry-M);i<=min(ry,ly+M);++i)if(lb[i]<=rb[i])
		return xx=lb[i],yy=i,1;
	return 0;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%s",c);
		for(j=0;c[j];++j)++(c[j]=='N'?x:y)[i];
		ly=min(ly,y[i]);ry=max(ry,y[i]);p[i]=i;
	}
	sort(p+1,p+n+1,[&](int a,int b){return y[a]<y[b];});
	L=0;R=5e5;
	for(;L<R;){
		M=L+R>>1;
		if(ck(M))R=M;else L=M+1;
	}
	ck(L);
	printf("%d\n",L);for(;xx--;)putchar('N');for(;yy--;)putchar('B');puts("");
}