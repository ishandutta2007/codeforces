#include<stdio.h>
#include<cstdlib>
#include<algorithm>
inline int Min(int p,int q){return p<q?p:q;}
int n,m,a[1000002],b[1000002],c[1000002],ans=1,l[1000002],r[1000002];
int main(){
	scanf("%d%d",&n,&m);c[n+1]=1e9+1;
	if(m>n)return puts("0")&0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=1;j<=m;j++)scanf("%d",&b[j]);
	for(int i=n;i>=1;i--)c[i]=Min(c[i+1],a[i]);l[m+1]=n+1;
	for(int i=1;i<=m;i++)l[i]=std::lower_bound(c+1,c+n+1,b[i])-c,r[i]=std::upper_bound(c+1,c+n+1,b[i])-c;
	if(l[1]!=1)return puts("0")&0;
	for(int i=1;i<=m;i++){
		if(c[l[i]]!=b[i])return puts("0")&0;
		if(i!=1)ans=1ull*ans*(r[i]-l[i])%998244353;
	}printf("%d",ans);
}