#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,e;

int a[N];

int p[N],ptot,vis[N];

void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
			p[++ptot]=i;
		for(int j=1;j<=ptot&&i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii pos[N];

int main()
{
	pre(1e6);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&e);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		long long ans=0;
		for(int i=n;i>=1;i--)
		{
			pos[i]={1e9,1e9};
			if(i+e<=n)
				pos[i]=pos[i+e];
			if(a[i]>1)
				pos[i].sd=pos[i].fs,pos[i].fs=i;
			if(pos[i].fs>n||vis[a[pos[i].fs]])
				continue;
			ans+=(min(n+1,pos[i].sd)-pos[i].fs-1)/e+1;
			if(pos[i].fs==i)
				ans--;
		}
		printf("%lld\n",ans);
	}
}