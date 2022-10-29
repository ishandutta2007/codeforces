#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	int x,y,next;
	long long c;
	bool gg;
}a[410000];int len,last[1100];
inline void ins(int x,int y,long long c)
{
	len++;
	a[len].x=x;a[len].y=y;a[len].c=c;a[len].gg=false;
	a[len].next=last[x];last[x]=len;
}
long long d[610][610],f[610];
inline long long mymin(long long x,long long y){return x<y?x:y;}
inline long long mymax(long long x,long long y){return x>y?x:y;}
int A[180000],B[180000];long long l[180000];
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	memset(d,63,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;long long c;scanf("%d%d%lld",&x,&y,&c);
		ins(x,y,c);ins(y,x,c);
		d[x][y]=mymin(d[x][y],c);d[y][x]=mymin(d[y][x],c);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)d[i][j]=mymin(d[i][j],d[i][k]+d[k][j]);
		}
	}
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d%d%lld",&A[i],&B[i],&l[i]);
	int ss=0;
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=n;i++)f[i]=-1;
		for(int i=1;i<=q;i++)
		{
			f[A[i]]=mymax(f[A[i]],l[i]-d[x][B[i]]);
			f[B[i]]=mymax(f[B[i]],l[i]-d[x][A[i]]);
		}
		for(int k=last[x];k>0;k=a[k].next)
		{
			int y=a[k].y;
			if(a[k].gg)continue;
			bool bk=false;
			for(int i=1;i<=n;i++)
			{
				if(a[k].c+d[y][i]<=f[i]){bk=true;break;}
			}
			if(bk)
			{
				a[k].gg=true;
				if(k&1)a[k+1].gg=true;
				else a[k-1].gg=true;
				ss++;
			}
		}
	}
	printf("%d\n",ss);
	return 0;
}