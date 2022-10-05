#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#define xxx 501
#define debug 0
using namespace std;
short f[xxx][xxx][xxx],be[xxx][xxx];
int ww[xxx],cnt=0,n,siz[xxx];
long long dd,d[xxx][xxx];
struct R{
	int to,was;
};
vector<R>r[xxx];
vector<int>ch[xxx];

void dis(int root,int x,int fa,long long t)
{
	d[root][x]=t;
	for (int i=0;i<r[x].size();i++)
		if (r[x][i].to!=fa)
			dis(root,r[x][i].to,x,t+(long long)r[x][i].was);
	return;
}

short tem[xxx];
void dfs(int x,int fa)
{
	siz[x]=1;
	for (int i=0;i<r[x].size();i++)
	{
		if (r[x][i].to!=fa)
		{
			dfs(r[x][i].to,x);
			siz[x]+=siz[r[x][i].to];
			ch[x].push_back(r[x][i].to); 
		}
	}
	if (debug) printf("%d %d %d\n",x,fa,siz[x]);
	int s,y,chsiz=ch[x].size();
	for (int i=1;i<=n;i++)
	{
		if (d[x][i]>dd) continue;
		for (int a=0;a<=siz[x];a++)
			tem[a]=520;
		tem[0]=tem[1]=0;
		s=1;
		for (int t=0;t<chsiz;t++)
		{
			y=ch[x][t];
			for (int a=min(s+siz[y],cnt);a>=0;a--)
			{
				short realtem=520;
				for (int b=max(0,a-s);b<=min(siz[y],a);b++)
				{
					realtem=min(realtem,(short)(tem[a-b]+f[y][b][i]));
					realtem=min(realtem,(short)(tem[a-b]+be[y][b]));
				}
				tem[a]=realtem;
			}
			s+=siz[y];
		}
		for (int a=0;a<=s;a++)
			f[x][a][i]=tem[a];
	}
	for (int a=0;a<siz[x];a++)
	{
		be[x][a+1]=520;
		for (int i=1;i<=n;i++)
			if (d[x][i]<=dd)
				be[x][a+1]=min(be[x][a+1],(short)(f[x][a][i]+ww[i]));
	}
	if (debug)
	{
		printf("%d:\n",x);
		for (int a=0;a<=s;a++)
		{
			printf("%d:",a);
	 		for (int i=1;i<=n;i++)cout<<" ("<<i<<")"<<f[x][a][i];
			cout<<"  best:"<<be[x][a]<<endl;
		}
	}
}

int main()
{
	memset(f,5,sizeof(f));
	memset(be,5,sizeof(be));
	scanf("%d%d",&n,&dd);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&ww[i]);
		cnt+=ww[i];
		ww[i]^=1;
	}
	int u,v,w;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		r[u].push_back((R){v,w});
		r[v].push_back((R){u,w});
	}
	for (int i=1;i<=n;i++)
		dis(i,i,0,(long long)0);
	if (debug){
		for (int i=1;i<=n;i++){for (int j=1;j<=n;j++) printf("%d ",d[i][j]);printf("\n");}
	}
	dfs(1,0);
	be[1][cnt] = be[1][cnt]>=520?-1:be[1][cnt];
	cout<<be[1][cnt]<<endl;
	return 0;
}