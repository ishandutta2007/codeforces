#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
int f[maxn],n,a[maxn],m,k,fans;
vector<int>vec[maxn];
bool vis[maxn];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int u,v;scanf("%d%d",&u,&v);
		vis[u]=vis[v]=true;
		f[find(u)]=find(v);
	}
	for(int i=1;i<=n;++i)if(vis[i])
		vec[find(i)].push_back(a[i]);
	for(int i=1;i<=n;++i)if(vis[i]&&f[i]==i){
		sort(vec[i].begin(),vec[i].end());
		int ans=1,len=1;
		for(int j=1;j<vec[i].size();++j){
			if(vec[i][j-1]==vec[i][j])len++;
			else ans=max(ans,len),len=1;
		}
		ans=max(ans,len);
		fans+=vec[i].size()-ans;
	}
	printf("%d",fans);
}