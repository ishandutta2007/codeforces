#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define BT 20

using namespace std;
typedef long long int ll;

struct P
{
	ll x,y;
	P(ll x=0,ll y=0):x(x),y(y){}
};
bool under(P p,P q,P r)//p.x<q.x<r.x
{
	ll a=r.y-p.y;
	ll b=-r.x+p.x;//b<0
	ll c=p.y*r.x-p.x*r.y;
	//a*q.x+b*q.y+c>0 --> under not overflow!
	return a*q.x+b*q.y+c>0;
}
ll px[SIZE],py[SIZE];
int id[SIZE];
P pos[SIZE];
int dep[SIZE],par[SIZE][BT];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d %I64d",&px[i],&py[i]);
	}
	int sz=0;
	for(int i=n-1;i>=0;i--)
	{
		if(i==n-1)
		{
			dep[i]=0;
			par[i][0]=-1;
			id[sz]=i;
			pos[sz++]=P(px[i],py[i]);
		}
		else
		{
			while(sz>=2&&under(P(px[i],py[i]),pos[sz-1],pos[sz-2])) sz--;
			int to=id[sz-1];
			dep[i]=dep[to]+1;
			par[i][0]=to;
			id[sz]=i;
			pos[sz++]=P(px[i],py[i]);
		}
	}
	for(int i=0;i<BT-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j][i]==-1) par[j][i+1]=-1;
			else par[j][i+1]=par[par[j][i]][i];
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		if(i!=0) printf(" ");
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		if(dep[a]>dep[b]) swap(a,b);
		for(int j=BT-1;j>=0;j--)
		{
			if(par[b][j]==-1||dep[par[b][j]]<dep[a]) continue;
			b=par[b][j];
		}
		if(a==b) printf("%d",a+1);
		else
		{
			for(int j=BT-1;j>=0;j--)
			{
				if(par[a][j]!=par[b][j])
				{
					a=par[a][j];
					b=par[b][j];
				}
			}
			printf("%d",par[a][0]+1);
		}
	}puts("");
	return 0;
}