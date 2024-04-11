#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1505;
int n,lim,a[maxn][maxn];
vector<pair<short,int>>dis[maxn][maxn];
bool vis[maxn*maxn];
void adjust(vector<pair<short,int>>&v)
{
	sort(v.begin(),v.end());
	static vector<pair<short,int>>ret;
	for(auto &i:v)
	{
		if(!vis[i.second])ret.push_back(i);
		vis[i.second]=true;
	}
	for(auto &i:v)vis[i.second]=false;
	while(ret.size()>lim)ret.pop_back();
	v=ret;ret.clear();
}
void mg(vector<pair<short,int>>&to,vector<pair<short,int>>&fr)
{
	for(auto &i:fr)to.push_back({i.first+1,i.second});
	adjust(to);
}
int dif[maxn];
int main()
{
	n=read();lim=read()+1;
	for(int i=1;i<=n;i++)generate_n(a[i]+1,n,read);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j].reserve(lim<<1);
	for(int i=1;i<=n;i++)
	{
		vector<pair<int,int>>v;
		for(int j=1;j<=n;j++)
		{
			for(auto k=v.begin();k!=v.end();k++)
				if(k->first==a[i][j]){v.erase(k);break;}
			v.push_back({a[i][j],j});
			if(v.size()>lim)v.erase(v.begin());
			for(auto &k:v)dis[i][j].push_back({j-k.second,k.first});
		}
	}

	for(int i=1;i<=n;i++)
	{
		vector<pair<int,int>>v;
		for(int j=1;j<=n;j++)
		{
			for(auto k=v.begin();k!=v.end();k++)
				if(k->first==a[j][i]){v.erase(k);break;}
			v.push_back({a[j][i],j});
			if(v.size()>lim)v.erase(v.begin());
			for(auto &k:v)dis[j][i].push_back({j-k.second,k.first});
		}
	}
	for(int i=1;i<=n;i++)adjust(dis[i][1]),adjust(dis[1][i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=n&&j!=n)mg(dis[i+1][j+1],dis[i][j]);
			if(dis[i][j].size()<lim)dif[min(i,j)]++;
			else dif[min({i,j,(int)dis[i][j][lim-1].first})]++;
			dis[i][j].clear();dis[i][j].shrink_to_fit();
		}
	}
	for(int i=n;i>=1;i--)dif[i]+=dif[i+1];
	for(int i=1;i<=n;i++)printf("%d\n",dif[i]);
	return 0;
}