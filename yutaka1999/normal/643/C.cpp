#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define EPS 1e-10

using namespace std;
typedef long double ld;

struct L
{
	ld a,b;//ax+b
	L(ld a=0.0,ld b=0.0):a(a),b(b){}
	ld val(ld x)
	{
		return a*x+b;
	}
};
bool under(L p,L q,L r)//p.a>q.a>r.a
{
	return (q.b-p.b)*(p.a-r.a)<=(r.b-p.b)*(p.a-q.a);
}
struct getmx
{
	L que[SIZE];
	int s,e;
	
	void init()
	{
		s=e=0;
	}
	void add(L l)
	{
		while(s<e-1&&under(que[e-2],que[e-1],l)) e--;
		que[e++]=l;
	}
	ld get(ld x)
	{
		while(s+1<e&&que[s].val(x)+EPS<que[s+1].val(x)) s++;
		return que[s].val(x);
	}
};
getmx que;
ld dp[SIZE],now[SIZE];
int T[SIZE];
ld v1[SIZE],v2[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&T[i]);
	ld all=0.0;
	v1[n]=v2[n]=0.0;
	for(int i=n-1;i>=0;i--)
	{
		v1[i]=v1[i+1]+(ld) T[i];
		v2[i]=v2[i+1]+1.0/(ld) T[i];
		all+=(ld) T[i]*v2[i];
	}
	for(int i=0;i<=n;i++) dp[i]=0.0;
	for(int i=2;i<=k;i++)
	{
		que.init();
		for(int i=0;i<n;i++)
		{
			que.add(L(v1[i],dp[i]));
			ld gt=que.get(v2[i+1])-v1[i+1]*v2[i+1];
			now[i+1]=gt;
		}
		for(int i=0;i<n;i++) dp[i]=now[i];
	}
	ld mx=0.0;
	for(int i=0;i<n;i++) mx=max(mx,dp[i]);
	printf("%.10f\n",(double) (all-mx));
	return 0;
}