#include<bits/stdc++.h>
using namespace std;
const int C=3010,R=3010,N=C*R*2;
const int x_[8]={-1,-1,-1,0,0,1,1,1},y_[8]={1,-1,0,1,-1,1,-1,0};
int n,m,k,root[N]={},ans=0,g1[C]={},g2[C]={},tot=0;
bool del[R][C+C]={};
inline int f(int a,int b) { return (a-1)*(m+m)+b; }
int get_root(int r)
{
	++tot,g1[tot]=r,g2[tot]=root[r];
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
void merge(int u,int v)
{
	u=get_root(u),v=get_root(v);
	++tot,g1[tot]=u,g2[tot]=root[u];
	root[u]=v;
}
void work(int x,int y)
{
	int s=f(x,y);
	for(int j=0;j<8;++j)
	{
		int x1=x+x_[j],y1=y+y_[j];
		if(y1==0) y1=m+m;
		if(y1>m+m) y1=1;
		if(del[x1][y1])
			merge(s,f(x1,y1));
	}
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m+m;++j)
			{
				int d=f(i,j);
				root[d]=d;
				del[i][j]=false;
			} 
		for(int i=1,x=0,y=0;i<=k;++i)
		{
			tot=0;
			scanf("%d%d",&x,&y);
			del[x][y]=del[x][y+m]=true;
			work(x,y);
			work(x,y+m);
			if(get_root(f(x,y))==get_root(f(x,y+m)))
			{
				del[x][y]=del[x][y+m]=false;
				for(int j=tot;j>=1;--j)
					root[g1[j]]=g2[j];
			}
			else
				++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}