#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<utility>
using namespace std;
struct node
{
	int x,y,next;
}a[1010000];int len,last[510000];
inline void ins(int x,int y)
{
	len++;a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int tt[510000];
int col[510000];
int cnt,belong[510000];
bool dfs(int x,int c)
{
	if(col[x]!=-1)return col[x]==c;
	col[x]=c;
	belong[x]=cnt;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(tt[x]!=tt[y])continue;
		if(!dfs(y,1-c))return false;
	}
	return true;
}
bool b[510000];
int tg[510000];
struct edge
{
	int x,y,c,next;
	bool bk;
}e[1010000];
map<int,map<int,int>> east;
inline void ins(int x,int y,int c)
{
	len++;
	e[len].x=x;e[len].y=y;e[len].c=c;
	e[len].next=east[x][tg[y]];east[x][tg[y]]=len;
	e[len].bk=true;
}
int Al,Be,Ga;bool De;
void color(int x,int c)
{
	if(col[x]<Ga)
	{
		col[x]=c;
		int ty=tg[x]==Al?Be:Al;
		for(int k=east[x][ty];k>0;k=e[k].next)
		{
			int y=e[k].y;
			e[k].bk=false;
			color(y,c^e[k].c);
		}
	}
	else if(col[x]==(c^1))De=false;
}
set<pair<int,int>> S;
int main()
{
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&tt[i]);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	memset(col,-1,sizeof(col));
	memset(b,true,sizeof(b));
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(col[i]==-1&&b[tt[i]])
		{
			cnt++;
			if(!dfs(i,0))
			{
				k--;
				b[tt[i]]=false;
			}
		}
	}
	for(int i=1;i<=n;i++)tg[belong[i]]=tt[i];
	len=0;
	for(int i=1;i<=m;i++)
	{
		int x=a[i*2].x,y=a[i*2].y;
		if(b[tt[x]]&&b[tt[y]]&&tt[x]!=tt[y])
		{
			ins(belong[x],belong[y],col[x]^col[y]);
			ins(belong[y],belong[x],col[x]^col[y]);
		}
	}
	memset(col,-1,sizeof(col));
	Ga=0;
	for(int i=1;i<=len;i+=2)
	{
		int x=e[i].x,y=e[i].y;
		if(tg[x]>tg[y])x^=y^=x^=y;
		if(e[i].bk)
		{
			Al=tg[x];Be=tg[y];De=true;color(x,Ga);
			if(!De)S.insert({tg[x],tg[y]});
			Ga+=2;
		}
	}
	printf("%lld\n",1ll*k*(k-1)/2-S.size());
	return 0;
}