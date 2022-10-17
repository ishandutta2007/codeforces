#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,q;

int a[N];

int p[N],ptot,vis[N],to[N];

void pre()
{
	vis[1]=1;
	for(int i=2;i<=1e6;i++)
	{
		if(!vis[i])
			p[++ptot]=i,to[i]=i;
		for(int j=1;j<=ptot&&i*p[j]<=1e6;j++)
		{
			to[i*p[j]]=p[j];
			vis[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
}

int ans[3];

unordered_map<int,int>cnt;

int main()
{
	pre();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnt.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			int x=a[i];
			int r=1;
			while(x!=1)
			{
				int t=to[x],th=0;
				while(x%t==0)
					x/=t,th++;
				if(th&1)
					r=r*t;
			}
			cnt[r]++;
		}
		ans[0]=1;
		ans[1]=0;
		int s1=0;
		for(auto i:cnt)
		{
			ans[0]=max(ans[0],i.second);
			if(i.second%2==0||i.first==1)
				s1+=i.second;
			else
				ans[1]=max(ans[1],i.second);
		}
		ans[1]=max(ans[1],s1);
		scanf("%d",&q);
		while(q--)
		{
			long long s;
			scanf("%lld",&s);
			if(s==0)
				printf("%d\n",ans[s]);
			else
				printf("%d\n",ans[1]);
		}
	}
}