#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 1005
using namespace std;
int f[N][N],a[N],q[N],d[N],v[N],n,p,h,t,x,ans;
inline int read(){
	int k=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) k=k*10+ch-48;
	return k;
}
int main(){
	n=read();
	p=read();
	for (int i=1;i<=p;i++){
		for (int j=1;j<=n;j++) a[j]=read();
		for (int j=1;j<=n;j++)
			for (int k=j+1;k<=n;k++)
				f[a[j]][a[k]]++;
	}
	h=0;
	t=n;
	for (int i=1;i<=n;i++) q[i]=i,d[i]=v[i]=1;
	while (h<t){
		h++;
		x=a[h];
		v[x]=0;
		for (int i=1;i<=n;i++)
			if (f[x][i]==p&&d[x]+1>d[i]){
				d[i]=d[x]+1;
				if (!v[i]){
					v[i]=1;
					t++;
					q[t]=i;
				}
			}
	}
	ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,d[i]);
	printf("%d",ans);
}