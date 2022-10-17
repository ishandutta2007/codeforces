#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,d,m,a[N];

vector<int>b,s;

ll sum[N];

int main()
{
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]>m)
			b.push_back(a[i]);
		else
			s.push_back(a[i]);
	sort(b.begin(),b.end());
	sort(s.begin(),s.end());
	ll tots=0;
	for(int i=0;i<s.size();i++)
		tots+=s[i];
	for(int i=0;i<s.size();i++)
		sum[i+1]=sum[i]+s[i];
	ll ans=0;
	if((int)b.size())
	{
		ll ss=0;
		for(int i=b.size()-1;i>=0;i--)
		{
			ss+=b[i];
			int res=i,tot=(int)b.size()-i;
			if(tot+1ll*(tot-1)*d>n)
				break;
			ll blk=(tot-1)*d;
			blk-=res;
			if(blk<0)
				blk=0;
			if(blk>s.size())
				blk=s.size();
			ans=max(ans,ss+tots-sum[blk]);
		}
	}
	else
	{
		for(int i=0;i<s.size();i++)
			ans+=s[i];
	}
	printf("%lld\n",ans);
}