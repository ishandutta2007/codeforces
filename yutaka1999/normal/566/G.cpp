#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;

struct P
{
	ll x,y;
	P(ll x=0,ll y=0):x(x),y(y){}
	bool operator<(const P&l) const
	{
		if(x!=l.x) return x<l.x;
		return y<l.y;
	}
};
bool under(P p,P q,P r)//p.x<=q.x<=r.x , p.x<r.x
{
	return (q.y-p.y)*(r.x-p.x)<(r.y-p.y)*(q.x-p.x);
}
P A[SIZE];
P C[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	ll DMDM,DNDN;
	scanf("%lld %lld",&DMDM,&DNDN);
	for(int i=0;i<n;i++)
	{
		ll a,b;
		scanf("%lld %lld",&a,&b);
		A[i]=P(a,b);
	}
	for(int i=0;i<m;i++)
	{
		ll c,d;
		scanf("%lld %lld",&c,&d);
		C[i]=P(c,d);
	}
	sort(C,C+m);
	vector <P> vx;
	for(int i=0;i<m;i++)
	{
		while(!vx.empty())
		{
			int sz=vx.size();
			if(vx[sz-1].y<=C[i].y) vx.pop_back();
			else if(sz>=2&&under(vx[sz-2],vx[sz-1],C[i])) vx.pop_back();
			else break;
		}
		vx.push_back(C[i]);
	}
	bool up=false;
	for(int i=0;i<n;i++)
	{
		int pos=lower_bound(vx.begin(),vx.end(),P(A[i].x+1,A[i].y))-vx.begin();
		if(pos==vx.size()) up=true;
		else
		{
			if(vx[pos].y<=A[i].y)
			{
				if(pos==0) up=true;
				else if(!under(vx[pos-1],A[i],vx[pos])) up=true;
			}
		}
	}
	if(up) puts("Max");
	else puts("Min");
	return 0;
}