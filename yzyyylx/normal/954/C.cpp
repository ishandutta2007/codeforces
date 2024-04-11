#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;

ll n,ans,last,now,y,mx;
vector<ll>vec;

int main()
{
	ll i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&now);
		if(i>1&&abs(now-last)>1)
		{
			if(!y) y=abs(now-last);
			else if(y!=abs(now-last))
			{
				puts("NO");
				return 0;
			}
		}
		if(i>1&&now==last)
		{
			puts("NO");
			return 0;
		}
		if(i>1&&abs(now-last)==1) vec.push_back(min(now,last));
		last=now;
		mx=max(mx,now);
	}
	if(y)
	for(i=0;i<vec.size();i++)
	{
		if(vec[i]%y==0)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	if(y)
		cout<<1000000000<<" "<<y;
	else cout<<1000000000<<" "<<mx;
}