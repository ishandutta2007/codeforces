#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n,a[N],L[N],i,j,k,xb,l[N],r[N],f[N][N][N],w;
map<int,int>mp;int z[N];
inline void upa(int&a,int b){a<b?a=b:0;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",a+i,L+i),mp[a[i]-L[i]]=mp[a[i]]=mp[a[i]+L[i]]=0;
	for(auto&u:mp)z[u.second=++xb]=u.first;
	for(i=1;i<=n;++i)l[mp[a[i]]]=mp[a[i]-L[i]],r[mp[a[i]]]=mp[a[i]+L[i]];
	memset(f,-1,sizeof f);f[1][1][1]=0;
	for(i=2;i<=xb;++i)for(j=1,w=z[i]-z[i-1];j<=i-1;++j)for(k=i-1;k<=xb;++k)if(f[i-1][j][k]!=-1){
		upa(f[i][j==i-1?i:j][max(i,k)],f[i-1][j][k]+(j<i-1 || k>i-1?w:0));
		if(j==i-1)upa(f[i][j][max(i,k)],f[i-1][j][k]+w);
		if(l[i] && l[i]<=j)upa(f[i][i][max(i,k)],f[i-1][j][k]+w);
		if(r[i]>=k){
			upa(f[i][j==i-1?i:j][r[i]],f[i-1][j][k]+(j<i-1 || k>i-1?w:0));
			if(j==i-1)upa(f[i][j][r[i]],f[i-1][j][k]+w);
		}
	}
	printf("%d\n",f[xb][xb][xb]);
	return 0;
}