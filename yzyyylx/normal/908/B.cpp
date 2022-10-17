#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#define N
#define ll long long
using namespace std;

int m,n,dir[30][4],dd,sx,sy,now,ans;
char mm[110][110],tmp;
string str;

void dfs(int nx,int ny,int pos)
{
//	cout<<nx<<" "<<ny<<" "<<m<<" "<<n<<endl;
	if(pos>str.size()||mm[nx][ny]=='#'||!nx||!ny||nx>m||ny>n) return;
//	cout<<pos<<" "<<dir[now][str[pos]-48]<<endl;
	if(mm[nx][ny]=='E')
	{
		ans++;
		return;
	}
	if(dir[now][str[pos]-48]==0)
	{
		dfs(nx+1,ny,pos+1);
	}
	else if(dir[now][str[pos]-48]==1)
	{
		dfs(nx-1,ny,pos+1);
	}
	else if(dir[now][str[pos]-48]==2)
	{
		dfs(nx,ny+1,pos+1);
	}
	else if(dir[now][str[pos]-48]==3)
	{
		dfs(nx,ny-1,pos+1);
	}
}

int main()
{
	register int i,j,k,l;
	cin>>m>>n;
	for(i=1;i<=m;i++)
	{
		tmp=getchar();
		for(j=1;j<=n;j++)
		{
			mm[i][j]=getchar();
			if(mm[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
		}
	}
	cin>>str;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j ++)
		{
			if(j==i) continue;
			for(k=0;k<4;k++)
			{
				if(k==i||k==j) continue;
				for(l=0;l<4;l++)
				{
					if(l==i||l==j||l==k) continue;
					dd++;
					dir[dd][0]=i;
					dir[dd][1]=j;
					dir[dd][2]=k;
					dir[dd][3]=l;
				}
			}
		}
	}
//	cout<<sx<<" "<<sy<<" ";
	for(now=1;now<=dd;now++)
	{
		dfs(sx,sy,0);
	}
	cout<<ans;
}