#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll T,n,a[100005],l,r,mid,x,res;
const int inf=1e18;
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=2;i<=n;i++)
		{
			if(a[i]<a[i-1])goto tag2;
		}
		printf("0\n");
		continue;
		tag2:l=0;r=55;
		while(l<r)
		{
			mid=(l+r)/2;
			x=-inf;
			for(int i=1;i<=n;i++)
			{
				res=a[i]-x;
				if(res>=0||-res<=(1ll<<(mid+1ll))-1)
				{
					x=max(a[i],x);
					continue;
				}
				else goto tag;
			}
			r=mid;continue;
			tag:l=mid+1;
		}
		printf("%lld\n",l+1);
	}
	return 0;
}