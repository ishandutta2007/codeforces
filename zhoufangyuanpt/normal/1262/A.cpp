#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		int ll=0x3f3f3f3f,rr=0xc0c0c0c0;
		for(int i=1;i<=n;i++)
		{
			int l,r;scanf("%d%d",&l,&r);
			if(r<ll)ll=r;
			if(l>rr)rr=l;
		}
		if(rr-ll<0)puts("0");
		else printf("%d\n",rr-ll);
	}
	return 0;
}