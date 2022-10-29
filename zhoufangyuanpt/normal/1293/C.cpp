#include<cstdio>
#include<cstring>
using namespace std;
bool b[2][110000];
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	memset(b,false,sizeof(b));
	int cnt=0,ff=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		x--;
		if(b[x][y]==false)
		{
			if((x==0&&y==1)||(x==1&&y==n))ff++;
			cnt+=b[x^1][y-1]+b[x^1][y]+b[x^1][y+1];
		}
		else
		{
			if((x==0&&y==1)||(x==1&&y==n))ff--;
			cnt-=b[x^1][y-1]+b[x^1][y]+b[x^1][y+1];
		}
		b[x][y]^=1;
		if(ff>0||cnt>0)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}