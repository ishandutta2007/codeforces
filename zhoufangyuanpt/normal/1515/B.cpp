#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		long double x=n/4.0;
		long double lx=sqrt(x);
		int l=lx-20,r=lx+20;
		if(l<1)l=1;
		bool bk=false;
		for(int i=l;i<=r;i++)
		{
			if(i*i*4==n){bk=true;break;}
		}
		if(bk){puts("YES");continue;}
		x=n/2.0;lx=sqrt(x);
		l=lx-20,r=lx+20;
		if(l<1)l=1;
		bk=false;
		for(int i=l;i<=r;i++)
		{
			if(i*i*2==n){bk=true;break;}
		}
		if(bk)puts("YES");
		else puts("NO");
	}
	return 0;
}