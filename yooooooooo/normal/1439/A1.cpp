#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct node
{
	int x,y;
	node(int nx=0,int ny=0){x=nx;y=ny;}
}a[4];
vector<node>ans[4];
int gr[105][105],n,m,T,tot=0;
char s[105];
void add(int x,int y)
{
	if(gr[x][y])
	{
		a[++tot]=node(x,y);
		gr[x][y]=0;
	}
}
void add2(int x,int y)
{
	a[++tot]=node(x,y);
	gr[x][y]=!gr[x][y];
}
void push()
{
	tot=0;
	for(int i=1;i<=3;i++)ans[i].push_back(a[i]);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans[1].clear();ans[2].clear();ans[3].clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)gr[i][j]=s[j]-'0';
		}
		for(int i=1;i<n-1;i++)
		{
			for(int j=1;j<m;j++)
			{
				add(i,j);
				add(i,j+1);
				if(tot==0)continue;
				add2(i+1,j);
				if(tot<3)add2(i+1,j+1);
				push();
			}
		}
		int i=n-1;
		for(int j=1;j<m;j++)
		{
			//printf("%d %d\n",j,gr[i][j]);
			add(i,j);
			add(i+1,j);
			if(tot==0)continue;
			add2(i,j+1);
			if(tot<3)add2(i+1,j+1);
			push();
			//printf("@%d\n",ans[1].size());
		}
		if(gr[n-1][m]==1)
		{
			if(gr[n][m]==1)
			{
				add2(n-1,m-1);
				add2(n,m-1);
				add2(n,m);
				push();
				add2(n-1,m-1);
				add2(n,m-1);
				add2(n-1,m);
				push();
			}
			else
			{
				add2(n-1,m-1);
				add2(n-1,m);
				add2(n,m);
				push();
				add2(n-1,m);
				add2(n-1,m-1);
				add2(n,m-1);
				push();
				add2(n-1,m);
				add2(n,m);
				add2(n,m-1);
				push();
			}
		}
		else
		{
			if(gr[n][m]==1)
			{
			add2(n-1,m);
				add2(n,m);
				add2(n,m-1);
				push();
				add2(n-1,m-1);
				add2(n,m-1);
				add2(n,m);
				push();
				add2(n-1,m-1);
				add2(n-1,m);
				add2(n,m);
				push();
			}
		}
		printf("%d\n",ans[1].size());
		for(int i=0;i<ans[1].size();i++)
		{
			printf("%d %d %d %d %d %d\n",ans[1][i].x,ans[1][i].y,ans[2][i].x,ans[2][i].y,ans[3][i].x,ans[3][i].y);
		}
	}
	return 0;
}