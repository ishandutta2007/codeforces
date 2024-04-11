#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=2e5+5;
int T;
int n;
struct graph
{
	vector<int>e[maxn];int in[maxn];
	void clear(){for(int i=1;i<=n;i++)e[i].clear(),in[i]=0;}
	void add(int x,int y){e[x].push_back(y);in[y]++;}
	int f[maxn],cnt;
	queue<int>q;
	int topo()
	{
		for(int i=1;i<=n;i++)f[i]=0;cnt=0;
		for(int i=1;i<=n;i++)if(!in[i])q.push(i);
		while(!q.empty())
		{
			int x=q.front();q.pop();cnt++;
			for(int i:e[x])
			{
				f[i]=max(f[i],f[x]+(x>i));
				if(!--in[i])q.push(i);
			}
		}
		if(cnt!=n)return -1;
		int ret=0;
		for(int i=1;i<=n;i++)ret=max(ret,f[i]);
		return ret+1;
	}
}o;
int main()
{
	T=read();
	while(T--)
	{
		n=read();o.clear();
		for(int i=1;i<=n;i++)
		{
			int k=read();
			for(int j=1;j<=k;j++)o.add(read(),i);
		}
		printf("%d\n",o.topo());
	}
	return 0;
}