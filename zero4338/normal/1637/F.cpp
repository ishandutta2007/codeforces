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
const int maxn=2e5+5;
int n;
int h[maxn];
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	ll f[maxn];int mx[maxn];
	void dfs(int u,int fa)
	{
		for(int &i:e[u])
			if(i!=fa)
			{
				dfs(i,u);
				mx[u]=max(mx[u],mx[i]);
				f[u]+=f[i];
			}
		if(h[u]>mx[u])f[u]+=h[u]-mx[u];
		mx[u]=max(mx[u],h[u]);
	}
}o;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=1;i<n;i++)o.add(read(),read());
	int pos=max_element(h+1,h+n+1)-h;
	o.dfs(pos,0);
	ll ans=0;
	for(int &i:o.e[pos])ans+=o.f[i];
	if(o.e[pos].size()==1)ans+=h[pos]+h[pos]-o.mx[o.e[pos][0]];
	else
	{
		vector<int>tmp;
		for(int &i:o.e[pos])tmp.push_back(o.mx[i]);
		sort(tmp.begin(),tmp.end());
		ans+=2*h[pos]-tmp[tmp.size()-1]-tmp[tmp.size()-2];
	}
	printf("%lld\n",ans);
	return 0;
}