#include<cstdio>
#include<cstring>
using namespace std;
char a[110][110];
inline int mymax(int x,int y){return x>y?x:y;}
inline int mymin(int x,int y){return x<y?x:y;}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	int l=100,r=0,x=100,y=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='*')
			{
				l=mymin(l,j);
				r=mymax(r,j);
				x=mymin(x,i);
				y=mymax(y,i);
			}
		}
	}
	for(int i=x;i<=y;i++)
	{
		for(int j=l;j<=r;j++)
		{
			putchar(a[i][j]);
		}
		putchar('\n');
	}
	return 0;
}