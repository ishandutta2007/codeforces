#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+20;
int n;
pair<int,ll>ans;
string s;
int f[maxn][8],g[8][8];
struct graph
{
	vector<pair<int,int>>e[maxn];
	void add(int x,int y,int z){e[x].push_back({y,z});}
	void bfs(int col)
	{
		for(int i=0;i<n+8;i++)f[i][col]=1e9;
		deque<int>q;
		for(int i=0;i<n;i++)if(s[i]-'a'==col)f[i][col]=0,q.push_front(i);
		while(!q.empty())
		{
			int x=q.front();q.pop_front();
			for(auto &i:e[x])
				if(f[i.first][col]>f[x][col]+i.second)
				{
					f[i.first][col]=f[x][col]+i.second;
					if(i.second)q.push_back(i.first);
					else q.push_front(i.first);
				}
		}
		for(int i=0;i<8;i++)g[col][i]=1e9;
		for(int i=0;i<n;i++)g[col][s[i]-'a']=min(g[col][s[i]-'a'],f[i][col]);
	}
}o;
void upd(int v1,int v2)
{
	if(ans.first<v1){ans.first=v1;ans.second=v2;}
	else if(ans.first==v1)ans.second+=v2;
}
int cnt[8][256],id[maxn];
int getid(int u)
{
	int ret=0;
	for(int i=0;i<8;i++)
		if(f[u][i]==g[s[u]-'a'][i]+1)ret|=(1<<i);
	return ret;
}
int calc(int c1,int s1,int c2,int s2)
{
	int ret=1e9;
	for(int i=0;i<8;i++)
		ret=min(ret,g[c1][i]+g[c2][i]+((s1>>i)&1)+((s2>>i)&1)+1);
	return ret;
}
int main()
{
	n=read();cin>>s;
	for(int i=0;i+1<n;i++)o.add(i,i+1,1),o.add(i+1,i,1);
	for(int i=0;i<n;i++)o.add(i,n+s[i]-'a',1),o.add(n+s[i]-'a',i,0);
	for(int i=0;i<8;i++)o.bfs(i);
	for(int i=0;i<n;i++)id[i]=getid(i);
	for(int i=0;i<n;i++)
	{
		for(int j=max(0,i-15);j<i;j++)
		{
			int dis=min(i-j,calc(s[j]-'a',id[j],s[i]-'a',id[i]));
			upd(dis,1);
		}
		for(int j=0;j<8;j++)
			for(int k=0;k<256;k++)
				if(cnt[j][k])upd(calc(j,k,s[i]-'a',id[i]),cnt[j][k]);
		if(i>=15)cnt[s[i-15]-'a'][id[i-15]]++;
	}
	printf("%d %lld\n",ans.first,ans.second);
	return 0;
}