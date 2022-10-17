#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=20;

int n,m,in[N],bef[1<<N],e[1<<N];

ll c[N],f[1<<N],val[1<<N],lst[1<<N];

int ans[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		c[u]+=w;
		c[v]-=w;
		in[v]|=(1<<u-1);
		e[1<<(u-1)]|=(1<<v-1);
		e[1<<(v-1)]|=(1<<u-1);
	}
	int all=(1<<n)-1;
	for(int S=0;S<=all;S++)
		for(int i=1;i<=n;i++)
			if(S&(1<<(i-1)))
				bef[S]|=in[i],val[S]+=c[i],e[S]|=e[1<<(i-1)];
	for(int S=0;S<=all;S++)
		f[S]=1e18;
	f[0]=0;
	for(int S=0;S<all;S++)
	{
		f[S]+=val[S];
		for(int T=(S+1)|S;;T=(T+1)|S)
		{
			int nw=T^S;
			if((S&bef[nw])!=bef[nw]||(e[nw]&nw))
			{
				if(T!=all)
					continue;	
				else
					break;
			}
			ll nv=f[S];
			if(nv<f[T])
				f[T]=nv,lst[T]=nw;
			if(T==all)
				break;
		}
	}
	int j=0;
	for(int S=all;S;S-=lst[S],j++)
		for(int i=1;i<=n;i++)
			if(lst[S]&(1<<(i-1)))
				ans[i]=j;
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i]," \n"[i==n]);
}