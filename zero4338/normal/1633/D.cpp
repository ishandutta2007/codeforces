#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e3+5;
const int maxm=2e4+5;
int n,k;
int dis[maxn],b[maxn],c[maxn];
int f[maxm];
void bfs()
{
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=1;i<=x;i=x/(x/i)+1)		
			if(x+x/i<=1000&&!dis[x+x/i]){dis[x+x/i]=dis[x]+1;q.push(x+x/i);}
	}
}
int main()
{
	bfs();
	int T=read();
	while(T--)
	{
		n=read();k=min(20000,read());
		generate_n(b+1,n,read);
		generate_n(c+1,n,read);
		for(int i=0;i<=k;i++)f[i]=0;
		for(int i=1;i<=n;i++)b[i]=dis[b[i]];
		for(int i=1;i<=n;i++)
			for(int j=k;j>=b[i];j--)f[j]=max(f[j],f[j-b[i]]+c[i]);
		printf("%d\n",f[k]);
	}
	return 0;
}