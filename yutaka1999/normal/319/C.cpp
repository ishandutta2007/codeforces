#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define EPS 1e-8

using namespace std;
typedef long long int ll;

struct L
{
	ll a,b;//y=ax+b
	L(ll a=0,ll b=0):a(a),b(b){}
	ll val(ll x)
	{
		return x*a+b;
	}
};
bool up(L p,L q,L r)//p.a>q.a>r.a>0
{
	return (double) (q.a-p.a)*(double) (p.b-r.b)-EPS<=(double) (p.a-r.a)*(double) (q.b-p.b);
}
struct getmin
{
	L que[SIZE];
	int s,e;
	
	void init()
	{
		s=e=0;
	}
	void add(L l)
	{
		while(s<e-1&&up(que[e-2],que[e-1],l)) e--;
		que[e++]=l;
	}
	ll get(ll x)
	{
		while(s+1<e&&que[s].val(x)>=que[s+1].val(x)) s++;
		return que[s].val(x);
	}
};
getmin que;
ll val[SIZE],in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%llld",&val[i]);
	for(int i=0;i<n;i++) scanf("%llld",&in[i]);
	que.init();
	for(int i=0;i<n;i++)
	{
		ll dp;
		if(i==0) dp=0;
		else dp=que.get(val[i]);
		if(i==n-1) printf("%llld\n",dp);
		else que.add(L(in[i],dp));
	}
	return 0;
}