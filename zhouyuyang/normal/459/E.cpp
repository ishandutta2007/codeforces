#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 300005
using namespace std;
struct edge{
	int x,y,u;
}e[N];
int n,m,ans,d[N],f[N],i,j,k;
bool cmp(edge a,edge b){return a.u<b.u;}
int read(){
	int k=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) k=k*10+ch-48;
	return k;
}
int main(){
	n=read();
	m=read();
	for (i=1;i<=m;i++){
		e[i].x=read();
		e[i].y=read();
		e[i].u=read();
	}
	sort(e+1,e+m+1,cmp);
	for (i=1;i<=m;i++){
		for (j=i;e[j].u==e[i].u&&j<=m;j++);
		for (k=i;k<j;k++) f[e[k].y]=max(f[e[k].y],d[e[k].x]+1);
		for (k=i;k<j;k++) d[e[k].y]=max(f[e[k].y],d[e[k].y]);
		i=j-1;
	}
	ans=0;
	for (i=1;i<=n;i++) ans=max(ans,d[i]);
	printf("%d",ans);
}