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
int n,k;
int val[maxn],tot;
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int len[maxn];
	void dfs(int u,int fa)
	{
		int son=0;
		for(int &i:e[u])
		{
			if(i==fa)continue;
			dfs(i,u);
			if(len[i]>len[son])son=i;
		}
		len[u]=len[son]+1;
		for(int &i:e[u])if(i!=fa&&i!=son)val[++tot]=len[i];
	}
}o;
ll ans=-1e10;
int main()
{
	n=read();k=read();
	for(int i=1;i<=n-1;i++)o.add(read(),read());
	o.dfs(1,0);val[++tot]=o.len[1];
	sort(val+1,val+tot+1,greater<int>());
	int sum=0;
	for(int i=0;i<=min(k,tot);i++)
	{
		sum+=val[i];int b=min(n-sum,n/2);
		ans=max(ans,(ll)i*(n-i)-(ll)b*(n-b));
	}
	for(int i=tot+1;i<=k;i++)
	{
		int b=min(n-sum,n/2);
		ans=max(ans,(ll)i*(n-i)-(ll)b*(n-b));
	}
	printf("%lld\n",ans);
	return 0;
}