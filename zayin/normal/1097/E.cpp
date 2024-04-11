#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n,a[maxn];

void _init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",a+i);
}

int dp[maxn],prt[maxn];

int q[maxn];
vector<int> lds[maxn];

bool vis[maxn];

LL C2(LL x)	{
	return x*(x+1)/2;
}

void calc(int dep,int N)
{
	if (!N)	{
		printf("%d\n",dep);
		return ;
	}
	
	for (int i=1;i<=n;++i)	lds[i].clear();
	
	int k=0;
	for (int i=1;i<=n;++i)
	{
		if (vis[i])	continue;
		int l=0,r=dp[k];
		while (l<r)
		{
			int mid=(l+r+1)>>1;
			if (a[q[mid]]<=a[i])
				l=mid;
			else
				r=mid-1;
		}
		
		prt[i]=q[l++],q[dp[i]=l]=i;
		lds[l].push_back(a[i]);
		if (dp[k]<dp[i])
			k=i;
	}
	
	if (C2(dp[k])>=N)
	{
		N-=dp[k];
		vector<int> val;
		for (;k;k=prt[k])	vis[k]=1,val.push_back(a[k]);
		
		calc(dep+1,N);
		
		reverse(val.begin(),val.end());
		printf("%d ",val.size());
		for (int x:val)
			printf("%d ",x);
		putchar('\n');
	} else
	{
		printf("%d \n",dep+dp[k]);
		for (int i=1;i<=dp[k];++i)
		{
			printf("%d ",lds[i].size());
			for (int x:lds[i])
				printf("%d ",x);
			putchar('\n');
		}
	}
}

void solve()
{
	for (int i=1;i<=n;++i)	vis[i]=0;
	calc(0,n);
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		_init();
		solve();
	}
	return 0;
}