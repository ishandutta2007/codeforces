#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int T,n,q;

int a[N];

ll s[N];

map<ll,int>vis;

void solve(int l,int r)
{
	vis[s[r]-s[l-1]]=1;
	if(a[l]==a[r])
		return;
	int mid=(a[l]+a[r])>>1;
	int M=upper_bound(a+l,a+r+1,mid)-a;
	solve(l,M-1);
	solve(M,r);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		vis.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		solve(1,n);
		while(q--)
		{
			int x;
			scanf("%d",&x);
			if(vis.find(x)!=vis.end())
				puts("Yes");
			else
				puts("No");
		}
	}
}