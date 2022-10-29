#include<cstdio>
#include<cstring>
using namespace std;
char a[110][110];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,m;scanf("%d%d",&n,&m);
		bool b1=false,b2=false;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",a[i]+1);
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='R')
				{
					if(i+j&1)b1=true;
					else b2=true;
				}
				else if(a[i][j]=='W')
				{
					if(i+j&1)b2=true;
					else b1=true;
				}
			}
		}
		if(b1==true&&b2==true)
		{
			puts("NO");
		}
		else
		{
			if(b2==false)b1=true;
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(i+j&1)
					{
						if(b1)putchar('R');
						else putchar('W');
					}
					else
					{
						if(b1)putchar('W');
						else putchar('R');
					}
				}
				putchar('\n');
			}
		}
	}
	return 0;
}