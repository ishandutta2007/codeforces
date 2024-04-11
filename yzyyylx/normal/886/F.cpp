#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#define db double
#define eps 1e-8
#define N 2010
using namespace std;

int n,ans;
db sx,sy,d[N];
bool gg[N];
struct Node
{
	db x,y,jj;
	Node operator + (const Node &u) const{return (Node){x+u.x,y+u.y};}
	Node operator - (const Node &u) const{return (Node){x-u.x,y-u.y};}
	db operator * (const Node &u) const{return x*u.x+y*u.y;}
	Node operator / (const db &u) const{return (Node){x/u,y/u};}
	bool operator == (const Node &u) const{return fabs(x-u.x)<eps && fabs(y-u.y)<eps;}
	void calc(){if(fabs(y)>eps) jj=atan(x/y);}
	bool operator < (const Node &u) const
	{
		if(fabs(y)<eps)
		{
			if(fabs(u.y)<eps) return x<u.x;
			return 1;
		}
		if(fabs(u.y)<eps) return 0;
		return jj<u.jj;
	}
}node[N];
struct Xn
{
	Node u,v;
	void rot()
	{
		swap(v.x,v.y);
		v.x=-v.x;
	}
};
vector<Node>use;

inline db cj(Node u,Node v){return u.x*v.y-u.y*v.x;}
inline db lenf(Node u,Node v){return (u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y);}
inline db len(Node u,Node v){return sqrt(lenf(u,v));}
inline db dx(Node u,Xn v){return fabs(cj(u-v.u,v.v))/len(v.u,v.u+v.v);}

inline bool check(Xn u)
{
	u.rot();
	int i,j;
	db t;
	for(i=1;i<=n;i++)
	{
		d[i]=(node[i]-u.u)*u.v/sqrt(u.v*u.v);
	}
	sort(d+1,d+n+1);
	t=d[1]+d[n];
	for(i=2;i<n;i++)
	{
		if(fabs(d[i]+d[n-i+1]-t)>eps) return 0;
	}
	return 1;
}

int main()
{
	int i,j;
	use.clear();
	ans=sx=sy=0;
	memset(gg,0,sizeof(gg));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&node[i].x,&node[i].y);
		sx+=node[i].x;
			sy+=node[i].y;
	}
	sx/=(db)n;
	sy/=(db)n;
	for(i=1;i<=n;i++)
	{
		node[i].x-=sx;
		node[i].y-=sy;
	}
	for(i=1;i<=n;i++)
	{
		if(gg[i]) continue;
		for(j=i+1;j<=n;j++)
		{
			if(gg[j]) continue;
			if(fabs(node[i].x+node[j].x)<eps && fabs(node[i].y+node[j].y)<eps) break;
		}
		if(j<=n) gg[i]=gg[j]=1;
	}
	for(i=1,j=0;i<=n;i++)
	{
		if(gg[i]) continue;
		node[++j]=node[i];
	}
	n=j;
	if(n<=2)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			use.push_back((node[i]+node[j])/2.0);
			use[use.size()-1].calc();
		}
	}
	sort(use.begin(),use.end());
	for(i=0;i<use.size();i=j)
	{
		for(j=i+1;j<use.size();j++)
		{
			if(fabs(cj(use[i],use[j]))>eps) break;
		}
		if(j-i>=n/2)
		{
			ans+=check((Xn){(Node){0,0},use[i]});
		}
	}
	printf("%d\n",ans);
}