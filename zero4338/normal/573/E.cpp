#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
const int maxm=400;
int n;
ll ans;
int p[maxn];
int bl[maxn],siz;
struct point
{
	int x;ll y;int id;
	const bool operator <(const point &a)const{if(x!=a.x)return x<a.x;return y<a.y;}
	const point operator -(const point &a)const{return point{x-a.x,y-a.y};}
	const ll operator *(const point &a)const{return x*a.y-a.x*y;}
};
struct block
{
	vector<point>po,con;
	ll addtag;int ktag;
	ll val(point &i){return (ll)i.x*ktag+i.y+addtag;}
	int mx;
	void rebuild(int x=0)
	{
		if(x)
		{
			for(auto i=po.begin();i!=po.end();i++)if(i->id==x){po.erase(i);break;}
			for(int i=0;i<po.size();i++)
			{
				if(po[i].id<x)po[i].y=po[i].y+p[x];
				else po[i].y=po[i].y+po[i].x;
			}
		}
		con.clear();
		for(point i:po)
		{
			while(con.size()&&i.y>=con[con.size()-1].y)con.pop_back();
			while(con.size()>=2&&(i-con[con.size()-1])*(con[con.size()-1]-con[con.size()-2])<=0)con.pop_back();
			con.push_back(i);
		}
		if(!con.size())return;mx=0;
		while(mx+1<con.size()&&val(con[mx])<val(con[mx+1]))mx++;
	}
	void mul(){ktag+=1;while(mx+1<con.size()&&val(con[mx])<val(con[mx+1]))mx++;}
	pair<ll,int>query(){return make_pair(val(con[mx]),con[mx].id);}
}b[maxm];int bnum;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)p[i]=read();
	siz=sqrt(n);
	for(int i=1;i<=n;i++)bl[i]=(i-1)/siz+1;
	bnum=(n-1)/siz+1;
	for(int i=1;i<=n;i++)b[bl[i]].po.push_back(point{p[i],p[i],i});
	for(int i=1;i<=bnum;i++)sort(b[i].po.begin(),b[i].po.end());
	for(int i=1;i<=bnum;i++)b[i].rebuild();
	for(int i=1;i<=n;i++)
	{
		int now=0;ll nowval=-1;
		for(int j=1;j<=bnum;j++){if(!b[j].con.size())continue;pair<ll,int>v=b[j].query();if(v.first>nowval)now=v.second,nowval=v.first;}
		if(nowval<0)break;
		ans+=nowval;
		for(int j=1;j<bl[now];j++){b[j].addtag+=p[now];}
		for(int j=bl[now]+1;j<=bnum;j++){b[j].mul();}
		b[bl[now]].rebuild(now);
	}
	printf("%lld\n",ans);
	return 0;
}