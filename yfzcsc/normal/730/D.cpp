#include<bits/stdc++.h>

using namespace std;

const int maxn=200020;

int n;

long long l[maxn],t[maxn];

long long ans;

vector <long long> a;

long long ti;

int main()
{
	cin>>n>>ti;
	for(int i=1;i<=n;i++)
		scanf("%d",&l[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		if(t[i]<l[i])
		{
			printf("-1");
			return 0;
		}
	}
	long long last=0,now=0;
	for(int i=1;i<=n;i++)
	{
		if(last>l[i])
		{
			last-=l[i];
			now+=l[i];
			continue;
		}
		l[i]-=last;
		t[i]-=last;
		now+=last;
		last=0;
		if(l[i]<<1<t[i])
		{
			now+=l[i]<<1;
			continue;
		}
		long long x=((l[i]<<1)-t[i]+ti-1)/ti;
		long long nowx=now;
		long long final=(((l[i])<<1)-t[i])%ti;
		last=(ti-final)%ti;
		ans+=x;
		now+=t[i];
		if(ans>100000)	
		{
			continue;
		}
		nowx+=t[i]-(x*ti-last);
		while(x--)
		{
			a.push_back(nowx);
			nowx+=ti;
		}
	}
	cout<<ans<<endl;
	if(ans<=100000)
	{
		for(int i=0;i<a.size();i++)
			printf("%I64d ",a[i]);
	}
}