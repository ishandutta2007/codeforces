#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,d,c,x,y,s;
int C(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>d)
	{
		c=s=0,x=1,y=d;
		while(n%d==0)
			n/=d,c++;
		if(c==1||c==2&&C(n))
		{
			puts("NO");
			continue;
		}
		if(!C(n))
		{
			puts("YES");
			continue;
		}
		for(int i=2;i<=d;i++)
			if(d%i==0)
			{
				d/=i,s++;
				while(d%i==0)
					d/=i,x*=i;
			}
		puts((s>1||(int)pow(x,c-1)%(y*__gcd(n,y))==0)?"YES":"NO");
	}
}