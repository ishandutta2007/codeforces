#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define eps 1e-10
#define INF 1e16
#define N 100100
#define M
using namespace std;

ll n,zf,T=300;
db xx,pos;
struct Node
{
	db x,y;
}node[N];

inline db pf(db u){return u*u;}
inline bool check(db r)
{
	ll i,j;
	db mx=INF,mn=-INF,t,tmp;
	for(i=1;i<=n;i++)
	{
		t=sqrt(2*r*node[i].y-pf(node[i].y));
		mx=min(mx,node[i].x+t);
		mn=max(mn,node[i].x-t);
	}
//	cout<<mx<<" "<<mn<<endl;
	return mx+eps>mn;
}

int main()
{
	ll i,j;
	db l,r,mid;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&node[i].x,&node[i].y);
		xx=max(xx,abs(node[i].y));
		if(node[i].y>eps)
		{
			if(zf<0)
			{
				puts("-1");
				return 0;
			}
			zf=1;
		}
		else if(node[i].y<-eps)
		{
			if(zf>0)
			{
				puts("-1");
				return 0;
			}
			zf=-1;
		}
		else while(1);
	}
//	cout<<pos<<endl;
//	cout<<check(6)<<endl;
	for(i=1;i<=n;i++) node[i].y=fabs(node[i].y);
	for(l=xx/2.0,r=INF;T;T--)
	{
		mid=(l+r)/2.0;
		if(check(mid)) r=mid;
		else l=mid;
	}
//	if(n>1000) while(1);
	printf("%.8f",l);
}