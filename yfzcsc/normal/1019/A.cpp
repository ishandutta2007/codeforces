#include<bits/stdc++.h>
#define maxn 3010
using namespace std;
int n,m,c[maxn],p[maxn],f[maxn],id[maxn],cho[maxn];
vector<int>G[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&p[i],&c[i]);
		G[p[i]].push_back(i);
		f[p[i]]++;
	}
	for(int i=1;i<=m;++i)
		sort(G[i].begin(),G[i].end(),[](int x,int y){
			return c[x]<c[y];
		});
	for(int i=1;i<=n;++i)id[i]=i;
	sort(id+1,id+n+1,[](int x,int y){
		return c[x]<c[y];
	});
	long long ans=9e18;
	for(int i=max(1,f[1]);i<=n;++i){
		long long sum=0;
		int a=i-f[1];
		for(int j=1;j<=n;++j)cho[j]=0;
		for(int j=2;j<=m;++j)
			for(int k=0;k<f[j]-i+1;++k)
				cho[G[j][k]]=1,sum+=c[G[j][k]],a--;
		for(int j=1;j<=n&&a>0;++j)if(!cho[id[j]]&&p[id[j]]!=1)sum+=c[id[j]],a--;
		ans=min(ans,sum);
	}
	printf("%lld",ans);
}