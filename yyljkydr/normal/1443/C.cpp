#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N],b[N];

int chk(int w)
{
	int s=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>w)
		{
			s+=b[i];
			if(s>w)
				return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		int l=0,r=1e9;
		while(r-l>1)
		{
			int mid=(l+r)>>1;
			if(chk(mid))
				r=mid;
			else
				l=mid;
		}
		printf("%d\n",r);
	}
}