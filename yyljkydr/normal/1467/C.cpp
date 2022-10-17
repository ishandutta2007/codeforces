#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n[3],a[3][N];

long long sum[N];

multiset<int>s[3];

long long get(int x,int y)
{
	long long ret=2e9;
	ret=min(ret,sum[x]);
	ret=min(ret,sum[y]);
	ret=min(ret,1ll**s[x].begin()+*s[y].begin());
	return ret;
}

int main()
{
	for(int i=0;i<3;i++)
		scanf("%d",&n[i]);
	long long ans=0;
	for(int i=0;i<3;i++)
		for(int j=1;j<=n[i];j++)
			scanf("%d",&a[i][j]),s[i].insert(a[i][j]),ans+=a[i][j],sum[i]+=a[i][j];
	long long mn=2e9;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(i!=j)
				mn=min(mn,get(i,j));
	printf("%lld\n",ans-1ll*mn*2);
}