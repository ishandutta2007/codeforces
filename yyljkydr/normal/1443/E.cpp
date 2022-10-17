#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,s[N],a[N],q,fac[N];

vector<int>S;

signed main()
{
	scanf("%lld%lld",&n,&q);
	fac[0]=1;
	for(int i=1;i<=20;i++)
		fac[i]=fac[i-1]*i;
	for(int i=1;i<=n;i++)
		a[i]=i,s[i]=s[i-1]+a[i];
	int pnow=0;
	while(q--)
	{
		int op;
		scanf("%lld",&op);
		if(op==1)
		{
			int l,r;
			scanf("%lld%lld",&l,&r);
			if(n<=15)
			{
				int ans=0;
				for(int i=l;i<=r;i++)
					ans+=a[i];
				printf("%lld\n",ans);
			}
			else
			{
				int ans=0;
				if(r>n-15)
				{
					if(l<=n-15)
					{
						ans=s[n-15]-s[l-1];
						for(int i=n-15+1;i<=r;i++)
							ans+=a[i];
					}
					else
						for(int i=l;i<=r;i++)
							ans+=a[i];
				}
				else
					ans=s[r]-s[l-1];
				printf("%lld\n",ans);
			}
		}
		else
		{
			int x;
			scanf("%lld",&x);
			pnow+=x;
			S.clear();
			if(n<=15)
			{
				pnow%=fac[n];
				for(int i=1;i<=n;i++)
					S.push_back(i);
				int tmp=pnow;
				for(int i=1;i<=n;i++)
				{
					int t=0;
					for(auto x:S)
					{
						++t;
						if(tmp<fac[n-i])
						{
							a[i]=x;
							S.erase(S.begin()+t-1);
							break;
						}
						tmp-=fac[n-i];
					}
				}
			}
			else
			{
				for(int i=n-14;i<=n;i++)
					S.push_back(i);
				int tmp=pnow;
				for(int i=n-14;i<=n;i++)
				{
					int t=0;
					for(auto x:S)
					{
						++t;
						if(tmp<fac[n-i])
						{
							a[i]=x;
							S.erase(S.begin()+t-1);
							break;
						}
						tmp-=fac[n-i];
					}
				}
			}
		}
	}
}