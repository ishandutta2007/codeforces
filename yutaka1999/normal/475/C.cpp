#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 1005

using namespace std;

char str[SIZE][SIZE];
int L[SIZE],R[SIZE];
int imos[SIZE][SIZE];
int n,m;

int calc(int a,int b,int c,int d)//(a,b)`(c,d)
{
	int ret=imos[c][d];
	if(a>0) ret-=imos[a-1][d];
	if(b>0) ret-=imos[c][b-1];
	if(a>0&&b>0) ret+=imos[a-1][b-1];
	return ret;
}
bool ok(int x,int y)
{
	for(int i=0;i<n;i++)
	{
		if(L[i]==-1) continue;
		int px=i,py=L[i];
		if(px+x-1>=n||py+y-1>=m) return false;
		int all=x*y;
		while(1)
		{
			if(calc(px,py,px+x-1,py+y-1)<x*y) return false;
			int c=0,d=0;
			if(px+x<n&&calc(px+1,py,px+x,py+y-1)==x*y) c=1;
			if(py+y<m&&calc(px,py+1,px+x-1,py+y)==x*y) d=1;
			if(c==1&&d==1) return false;
			if(c==1)
			{
				px++;
				all+=y;
			}
			if(d==1)
			{
				py++;
				all+=x;
			}
			if(c==0&&d==0) break;
		}
		if(all<calc(0,0,n-1,m-1)) return false;
		break;
	}
	return true;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			imos[i][j]=str[i][j]=='X'?1:0;
			if(i>0) imos[i][j]+=imos[i-1][j];
			if(j>0) imos[i][j]+=imos[i][j-1];
			if(i>0&&j>0) imos[i][j]-=imos[i-1][j-1];
		}
	}
	int yy=n,tt=m;
	for(int i=0;i<n;i++)
	{
		L[i]=R[i]=-1;
		int c=0;
		bool up=false,nu=false;
		for(int j=0;j<m;j++)
		{
			if(str[i][j]=='X')
			{
				if(nu)
				{
					puts("-1");
					return 0;
				}
				if(!up)
				{
					up=true;
					L[i]=j;
				}
				R[i]=j;
				c++;
			}
			else
			{
				if(up)
				{
					nu=true;
				}
			}
		}
		if(c!=0) tt=min(tt,c);
	}
	for(int i=0;i<m;i++)
	{
		int c=0;
		bool up=false,nu=false;
		for(int j=0;j<n;j++)
		{
			if(str[j][i]=='X')
			{
				if(nu)
				{
					puts("-1");
					return 0;
				}
				if(!up)
				{
					up=true;
				}
				c++;
			}
			else
			{
				if(up)
				{
					nu=true;
				}
			}
		}
		if(c!=0) yy=min(yy,c);
	}
	int ret=n*m+1;
	for(int i=1;i<=m;i++)
	{
		if(ok(yy,i))
		{
			ret=min(ret,yy*i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ok(i,tt))
		{
			ret=min(ret,tt*i);
		}
	}
	if(ret>n*m) ret=-1;
	printf("%d\n",ret);
	return 0;
}