#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int a[2][2][1010][1010];
int n;
void update(int x,int y,int v)
{
	int i,j;
	for(i=x;i<=n;i+=i&-i)
		for(j=y;j<=n;j+=j&-j)
			a[x&1][y&1][i][j]^=v;
}
int query(int x,int y)
{
	int s=0;
	int i,j;
	for(i=x;i;i-=i&-i)
		for(j=y;j;j-=j&-j)
			s^=a[x&1][y&1][i][j];
	return s;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	int i;
	int x1,y1,x2,y2;
	int c;
	memset(a,0,sizeof a);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&c);
		if(c==1)
		{
			int s=0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			s^=query(x2,y2);
			s^=query(x1-1,y2);
			s^=query(x2,y1-1);
			s^=query(x1-1,y1-1);
			printf("%d\n",s);
		}
		else
		{
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
			update(x1,y1,c);
			update(x1,y2+1,c);
			update(x2+1,y1,c);
			update(x2+1,y2+1,c);
		}
	}
	return 0;
}