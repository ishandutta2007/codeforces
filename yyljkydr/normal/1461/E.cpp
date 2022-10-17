#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N=1e6+1e3+7;
 
ll k,l,r,t,x,y;
 
unordered_map<int,int>vis;
 
int main()
{
	cin>>k>>l>>r>>t>>x>>y;
	if(k<l||k>r)
	{
		puts("No");
		return 0;
	} 
	if(x>y)
	{
		if(k+y>r)
			k-=x,t--;
		ll s=(k-l)/(x-y);
		if(s<t)
			puts("No");
		else
			puts("Yes");
		return 0;
	}
	else
	{
		while(1)
		{
			if(k+y<=r)
				k+=y;
			if(vis[k])
			{
				puts("Yes");
				return 0;
			}
			vis[k]=1;
	//		k - s * x + y <= r
	//		s >= (k + y - r) / x
			ll s=min((k+y-r+x-1)/x,t);
			k-=s*x;
			t-=s;
			if(k<l)
			{
				puts("No");
				return 0;
			}
			if(!t)
			{
				puts("Yes");
				return 0;
			}
		}
	}
}