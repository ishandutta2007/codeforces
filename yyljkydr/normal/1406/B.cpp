#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T;

int n,a[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii pmx[N],pmn[N],smx[N],smn[N];

signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		int ans=-1e18;
		for(int i=0;i<=5;i++)
		{
			int now=1;
			for(int j=1;j<=i;j++)
				now*=a[j];
			for(int j=n;j>=n-(5-i)+1;j--)
				now*=a[j];
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
}