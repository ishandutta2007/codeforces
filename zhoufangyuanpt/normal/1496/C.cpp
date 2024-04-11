#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[110000],b[110000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=2*n;i++)
		{
			long long x,y;scanf("%lld%lld",&x,&y);
			if(x<0)x=-x;
			if(y<0)y=-y;
			if(x==0)a[++cnt1]=y;
			else b[++cnt2]=x;
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		double ss=0;
		for(int i=1;i<=n;i++)ss+=sqrt(double(a[i]*a[i]+b[i]*b[i]));
		printf("%.15lf\n",ss);
	}
	return 0;
}