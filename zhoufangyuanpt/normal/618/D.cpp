#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	int x,y,next;
}a[410000];int len,last[210000];
inline void ins(int x,int y)
{
	len++;a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int f[210000][2];
void treedp(int x,int fa)
{
	f[x][0]=1;f[x][1]=1;
	int tt=0;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)
		{
			treedp(y,x);
			f[x][0]+=f[y][0];
			f[x][1]+=f[y][0];
			if(f[y][1]==f[y][0])tt++;
		}
	}
	if(tt>=2)f[x][0]-=2,f[x][1]--;
	else if(tt>=1)f[x][0]--,f[x][1]--;
}
int pp[210000];
int main()
{
	int n;long long x,y;
	scanf("%d%lld%lld",&n,&x,&y);
	len=0;memset(last,0,sizeof(last));
	memset(pp,0,sizeof(pp));bool bk=false;
	for(int i=1;i<n;i++)
	{
		int xx,yy;scanf("%d%d",&xx,&yy);
		ins(xx,yy);ins(yy,xx);
		pp[xx]++;pp[yy]++;
		if(pp[xx]==n-1||pp[yy]==n-1)bk=true;
	}
	if(x>=y)
	{
		printf("%lld\n",(n-1-bk)*y+bk*x);
	}
	else
	{
		treedp(1,0);
		printf("%lld\n",(n-f[1][0])*x+(f[1][0]-1)*y);
	}
	return 0;
}