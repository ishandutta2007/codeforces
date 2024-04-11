#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
int n,m,k,s,a[maxn];
vector<int>G[maxn];
int b[maxn][110],q[maxn],l,r;
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=k;++i){
		l=r=0;
		for(int j=1;j<=n;++j)
			if(a[j]==i)q[r++]=j,b[j][i]=0;
		while(l<r){
			int u=q[l++];
			for(auto p:G[u])if(b[p][i]>b[u][i]+1)
				b[p][i]=b[u][i]+1,q[r++]=p;
		}
	}
	for(int i=1;i<=n;++i){
		int ans=0;
		nth_element(b[i]+1,b[i]+s,b[i]+k+1);
		for(int j=1;j<=s;++j)ans+=b[i][j];
		printf("%d ",ans);
	}
}