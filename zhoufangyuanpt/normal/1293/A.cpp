#include<cstdio>
#include<cstring>
using namespace std;
int a[5100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,r,m;scanf("%d%d%d",&n,&r,&m);
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		int i;
		for(i=0;i<=2000;i++)
		{
			if(r>i)
			{
				bool bk=true;
				for(int j=1;j<=m;j++)if(a[j]==r-i){bk=false;break;}
				if(bk)break;
			}
			if(r+i<=n)
			{
				bool bk=true;
				for(int j=1;j<=m;j++)if(a[j]==r+i){bk=false;break;}
				if(bk)break;
			}
		}
		printf("%d\n",i);
	}
	return 0;
}