#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int T,n,a[N];

map<int,int>cnt;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnt.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),cnt[a[i]]++;
		auto p=cnt.begin();
		bool ok=1;
		for(int i=1;i<=n;i++)
			ok&=(p->first&a[i])==p->first;
		ok&=p->second>=2;
		if(!ok)
			puts("0");
		else
		{
			int ans=1;
			for(int i=1;i<=n-2;i++)
				ans=1ll*ans*i%P;
			ans=1ll*ans*p->second%P*(p->second-1)%P;
			printf("%d\n",ans);
		}
	}
}