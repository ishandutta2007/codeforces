#include<cstdio>
#include<cstring>
using namespace std;
int a[110000];
int p[110000];
bool b[110000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(b,false,sizeof(b));
		int ms=0;
		bool bk=true;
		int j=1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			int x=a[i];
			if(ms<x)ms=p[i]=x;
			else if(ms==x)
			{
				while(b[j])j++;
				if(j<=ms)p[i]=j;
				else
				{
					bk=false;break;
				}
			}
			else
			{
				bk=false;break;
			}
			b[p[i]]=true;
		}
		if(bk)
		{
			for(int i=1;i<n;i++)printf("%d ",p[i]);
			printf("%d\n",p[n]);
		}
		else puts("-1");
	}
	return 0;
}