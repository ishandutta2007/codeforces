#include<bits/stdc++.h>
using namespace std;
struct gg{
	int w,id;
}node[200010];
int n,k,r[200010],ans[200010],nw[200010],id[200010];
vector<int>mp[200010];
bool cmp(gg mo,gg ha)
{return mo.w<ha.w;}
int find(int l,int r,int x,int w)
{
	int ans=-1,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(mp[x][mid]<w)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>node[i].w,node[i].id=i;
	int u,v;	
	for(int i=1;i<=k;i++)
		cin>>u>>v,mp[u].push_back(node[v].w),mp[v].push_back(node[u].w);
	for(int i=1;i<=n;i++)sort(mp[i].begin(),mp[i].end());	
	sort(node+1,node+n+1,cmp);
	for(int i=1;i<=n;i++)nw[i]=node[i].w,id[i]=node[i].id;
	int pos,ps;
	for(int i=1;i<=n;i++)
	{
		pos=lower_bound(nw+1,nw+n+1,nw[i])-nw;
		if(pos>n)pos=n;while(nw[pos]==nw[i]&&pos>=1)pos--;
		ps=find(0,mp[id[i]].size()-1,id[i],nw[i])+1;
		ans[id[i]]=max(0,pos-ps);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}