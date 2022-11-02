#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const int N=200200;
const long long INF=0x3fffffff;
int n,m;
long long d1[N]={},d2[2][N]={};
struct node
{
	long long dis[2][2];
	int l,r;
}t[N<<2]={},empty={},sum;
char ch[2][N]={};
node merge(const node &n1,const node &n2)
{
	int d=n1.r;
	node n={INF,INF,INF,INF,n1.l,n2.r};
	n.dis[0][0]=min(n.dis[0][0],n1.dis[0][0]+n2.dis[0][0]+d2[0][d]);
	n.dis[0][0]=min(n.dis[0][0],n1.dis[0][1]+n2.dis[1][0]+d2[1][d]);
	n.dis[0][0]=min(n.dis[0][0],n1.dis[0][0]+n2.dis[1][0]+\
								min(d2[0][d]+d1[d+1],d2[1][d]+d1[d]));
	n.dis[0][0]=min(n.dis[0][0],n1.dis[0][1]+n2.dis[0][0]+\
								min(d2[0][d]+d1[d],d2[1][d]+d1[d+1]));
	
	n.dis[1][1]=min(n.dis[1][1],n1.dis[1][1]+n2.dis[1][1]+d2[1][d]);
	n.dis[1][1]=min(n.dis[1][1],n1.dis[1][0]+n2.dis[0][1]+d2[0][d]);
	n.dis[1][1]=min(n.dis[1][1],n1.dis[1][1]+n2.dis[0][1]+\
								min(d2[1][d]+d1[d+1],d2[0][d]+d1[d]));
	n.dis[1][1]=min(n.dis[1][1],n1.dis[1][0]+n2.dis[1][1]+\
								min(d2[1][d]+d1[d],d2[0][d]+d1[d+1]));
	
	n.dis[0][1]=min(n.dis[0][1],n1.dis[0][0]+n2.dis[1][1]+\
								min(d1[d]+d2[1][d],d1[d+1]+d2[0][d]));
	n.dis[0][1]=min(n.dis[0][1],n1.dis[0][1]+n2.dis[0][1]+\
								min(d1[d]+d2[0][d],d1[d+1]+d2[1][d]));
	n.dis[0][1]=min(n.dis[0][1],n1.dis[0][1]+n2.dis[1][1]+d2[1][d]);
	n.dis[0][1]=min(n.dis[0][1],n1.dis[0][0]+n2.dis[0][1]+d2[0][d]);
	
	n.dis[1][0]=min(n.dis[1][0],n1.dis[1][1]+n2.dis[0][0]+\
								min(d1[d]+d2[0][d],d1[d+1]+d2[1][d]));
	n.dis[1][0]=min(n.dis[1][0],n1.dis[1][0]+n2.dis[1][0]+\
								min(d1[d]+d2[1][d],d1[d+1]+d2[0][d]));
	n.dis[1][0]=min(n.dis[1][0],n1.dis[1][0]+n2.dis[0][0]+d2[0][d]);
	n.dis[1][0]=min(n.dis[1][0],n1.dis[1][1]+n2.dis[1][0]+d2[1][d]);
	return n;
}
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=l+r>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)+1);
		t[k]=merge(t[k<<1],t[(k<<1)+1]);
	}
	else
	{
		t[k].dis[0][0]=(ch[0][l]=='.') ? 0 : INF;
		t[k].dis[1][1]=(ch[1][l]=='.') ? 0 : INF;
		t[k].dis[0][1]=t[k].dis[1][0]=(ch[0][l]=='.' && ch[1][l]=='.') ? 1 : INF;
		t[k].l=l;
		t[k].r=r;
	}
}
void init()
{
	scanf("%d%d\n",&n,&m);
	scanf("%s\n",ch[0]+1);
	scanf("%s\n",ch[1]+1);
	for(int i=1;i<=n;++i)
		d1[i]=(ch[0][i]=='.' && ch[1][i]=='.') ? 1 : INF;
	for(int i=1;i<n;++i)
	{
		d2[0][i]=(ch[0][i]=='.' && ch[0][i+1]=='.') ? 1 : INF;
		d2[1][i]=(ch[1][i]=='.' && ch[1][i+1]=='.') ? 1 : INF;
	}
	make_tree(1,n,1);
}
void query(const int &L,const int &R,int k)
{
	if(t[k].l>=L && t[k].r<=R)
	{
		if(sum.l==0 || sum.r==0)
			sum=t[k];
		else
			sum=merge(sum,t[k]);
		return;
	}
	if(t[k<<1].r>=L)
		query(L,R,k<<1);
	if(t[(k<<1)+1].l<=R)
		query(L,R,(k<<1)+1);
}
void work()
{
	int u,v;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		int u1=(u-1)/n,u2=(u-1)%n+1,v1=(v-1)/n,v2=(v-1)%n+1;
		sum=empty;
		if(u2>v2)
		{
			swap(u1,v1);
			swap(u2,v2);
		}
		query(u2,v2,1);
		if(sum.dis[u1][v1]<INF)
			printf("%I64d\n",sum.dis[u1][v1]);
		else
			printf("-1\n");
	}
}
int main()
{	
	init();
	work();
	return 0;
}