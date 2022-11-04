#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int val[100005],ls[100005],rs[100005],vis[100005];
int n,ans,rt;
map<int,int> mp;
void dfs(int x,int l,int r){
	if (x==-1) return;
	if (val[x]>=l&&val[x]<=r) mp[val[x]]=1;
	dfs(ls[x],l,min(r,val[x]-1));
	dfs(rs[x],max(l,val[x]+1),r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){ 
		scanf("%d%d%d",&val[i],&ls[i],&rs[i]);
		if (ls[i]!=-1) vis[ls[i]]=1;
		if (rs[i]!=-1) vis[rs[i]]=1;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) rt=i;
	dfs(rt,-1,1000000001);
	for (int i=1;i<=n;i++)
		if (!mp[val[i]]) ans++;
	printf("%d\n",ans);
}