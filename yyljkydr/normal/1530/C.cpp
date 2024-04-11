#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],b[N],sa[N],sb[N];

int chk(int x)
{
	int no=(x+n)/4;
	int ca=sa[n]-sa[no]+x*100;
	int cb=sb[n]-sb[max(0,no-x)];
	return ca>=cb;
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
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)
			sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i];
		int l=-1,r=3*n;
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