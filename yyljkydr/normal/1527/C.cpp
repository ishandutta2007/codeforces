#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,a[N];

map<int,long long>s;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		s.clear();
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			ans+=1ll*s[a[i]]*(n-i+1);
			s[a[i]]+=i;
		}
		printf("%lld\n",ans);
	}
}