#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<int,int> mp,id,vis;int a[400000],c[400000];int ori[400000];
vector<int> P,ed[400000],V[400000],E[400000];
bool f[400000];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0,m=0;scanf("%d%d",&n,&m);mp.clear(),id.clear(),vis.clear();
		int cnt=0;
		for(int i=1;i<=n;i++){scanf("%d",&a[i]),mp[a[i]]++;if(!id[a[i]])id[a[i]]=++cnt,f[i]=1,ori[cnt]=a[i];}
		for(int i=1;i<=n;i++)
		{
			if(mp[a[i]])
			{
				c[id[a[i]]]=mp[a[i]];V[c[id[a[i]]]].push_back(a[i]);mp[a[i]]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(V[i].size()){P.push_back(i);sort(V[i].begin(),V[i].end());reverse(V[i].begin(),V[i].end());}
		}
		//for(int i=0;i<P.size();i++)printf("%d ",P[i]);puts("");
		for(int i=1,x=0,y=0;i<=m;i++)
		{
			scanf("%d%d",&x,&y);ed[id[x]].push_back(y),ed[id[y]].push_back(x);
		}
		for(int i=1;i<=cnt;i++)ed[i].push_back(ori[i]);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!f[i])continue;
			int k=id[a[i]];sort(ed[k].begin(),ed[k].end());
			for(int j=ed[k].size()-1;j>=0;j--)E[c[id[ed[k][j]]]].push_back(ed[k][j]);
			for(int j=0;j<P.size();j++)
			{
				int u=P[j];
				for(int l=0;l<V[u].size();l++)
				{
					//printf("%d %d\n",a[i],V[u][l]);
					if(l==E[u].size()||E[u][l]!=V[u][l])
					{
					//	puts("OJBK");
						ans=max(ans,(long long)(c[k]+u)*(a[i]+V[u][l]));break;
					}
				}
				E[u].clear();
			}
			
		}
		printf("%lld\n",ans);
		
		for(int i=1;i<=n;i++)a[i]=c[i]=ori[i]=f[i]=0,V[i].clear(),ed[i].clear();P.clear();vis.clear();
	}
}