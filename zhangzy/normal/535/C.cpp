%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long a,b,n,st,t,m;

long long dik(long long x)
{
	return a+(x-1)*b;
}

bool pd(long long en)
{
	if (dik(en)>t) return 0;
	if ( ( dik(st)+dik(en) ) * (en-st+1) /2 > t*m ) return 0;
	return 1;
}

int main()
{
	cin>>a>>b>>n;
	long long l,r,mid,ans;
	while (n--)
	{
		cin>>st>>t>>m;
		l=st;
		r=l+1741741;
		ans=-1;
		while (l<=r)
		{
			mid=(l+r)>>1;
			if (pd(mid))
			{
				ans=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		printf("%d\n",ans);
	}
}