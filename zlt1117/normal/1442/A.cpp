#include<bits/stdc++.h>
using namespace std;
const int maxn=40005;
int a[maxn],b[maxn],n;
int T;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)b[i]=a[i];
		reverse(a+1,a+n+1);reverse(b+1,b+n+1);
		int minv=a[1],now=0;
		for(int i=2;i<=n-1;++i)
		{
			minv=min(minv,b[i]-now);
			a[i]-=minv;
			now=max(now,a[i]);
		}
		minv=a[n];
		for(int i=n-1;i>=2;--i)
		{
			minv=min(minv,b[i]);
			a[i]-=minv;
		}
		bool ok=1;
		for(int i=2;i<=n-1;++i)
		{
			if(a[i]>0)
			{
				cout<<"NO\n";
				ok=0;
				break;
			}
		}
		if(ok)cout<<"YES\n";
	}
	return 0;
}