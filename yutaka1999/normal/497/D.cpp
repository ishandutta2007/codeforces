#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#define SIZE 1005
#define EPS 1e-12
#define PI 3.141592653589793238

using namespace std;
typedef long double ld;
typedef long long int ll;
typedef pair <ll,ll> P;
typedef pair <P,ll> L;//((a,b),c) = (ax+by=c)

ll px[SIZE],py[SIZE],Px[SIZE],Py[SIZE];
ll qx[SIZE],qy[SIZE];

P diff(P q,P r)
{
	return P(q.first-r.first,q.second-r.second);
}
ll dist(P q,P r)
{
	ll x=q.first-r.first;
	ll y=q.second-r.second;
	return x*x+y*y;
}
ll gcd(ll a,ll b)
{
	if(a==0) return b;
	return gcd(b%a,a);
}
L ln(P p,P r)
{
	ll a=r.second-p.second;
	ll b=-r.first+p.first;
	ll c=p.second*r.first-p.first*r.second;
	ll g=gcd(gcd(a,b),c);
	return L(P(a/g,b/g),-c/g);
}
bool ok(L l,P p,ll r)
{
	ll x=l.first.first*p.first+l.first.second*p.second-l.second;
	ll y=l.first.first*l.first.first+l.first.second*l.first.second;
	return x*x<=r*y;
}
bool judge(int n,int m,ll x2,ll y2)
{
	ll r2=x2*x2+y2*y2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			P p=P(px[i],py[i]),q=P(qx[j],qy[j]),r=P(qx[(j+1)%m],qy[(j+1)%m]);
			P c1=diff(q,P(x2,y2)),c2=diff(r,P(x2,y2));
			ll R1=dist(p,c1),R2=dist(p,c2);
			if(R1<r2&&R2<r2) continue;
			if(R1<=r2||R2<=r2) return true;
			L l=ln(c1,c2);
			if(!ok(l,p,r2)) continue;
			P mc=P((c1.first+c2.first)/2,(c1.second+c2.second)/2);
			l=ln(q,r);//ax+by+c=0 -->bx-ay+hoge=0
			swap(l.first.first,l.first.second);
			l.first.second*=-1;
			l.second=l.first.first*mc.first+l.first.second*mc.second;
			if(!ok(l,p,dist(mc,c1))) continue;
			return true;
		}
	}
	return false;
}
int main()
{
	ll x1,y1;
	scanf("%I64d %I64d",&x1,&y1);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d %I64d",&px[i],&py[i]);
		px[i]-=x1;
		py[i]-=y1;
		px[i]*=2;
		py[i]*=2;
	}
	scanf("\n");
	ll x2,y2;
	scanf("%I64d %I64d",&x2,&y2);
	x2-=x1;y2-=y1;
	x2*=2;y2*=2;
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%I64d %I64d",&qx[i],&qy[i]);
		qx[i]-=x1;
		qy[i]-=y1;
		qx[i]*=2;
		qy[i]*=2;
	}
	if(judge(n,m,x2,y2))
	{
		puts("YES");
		return 0;
	}
	x1=-x2;y1=-y2;
	for(int i=0;i<n;i++)
	{
		px[i]-=x2;
		py[i]-=y2;
		Px[i]=px[i];
		Py[i]=py[i];
	}
	for(int i=0;i<m;i++)
	{
		qx[i]-=x2;
		qy[i]-=y2;
		px[i]=qx[i];
		py[i]=qy[i];
	}
	for(int i=0;i<n;i++)
	{
		qx[i]=Px[i];
		qy[i]=Py[i];
	}
	if(judge(m,n,x1,y1)) 
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}