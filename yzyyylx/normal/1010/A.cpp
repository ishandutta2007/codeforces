#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 1010
using namespace std;

int n,m;
db a[N],b[N];

inline bool pd(db now)
{
	int i;
//	now-=(now+m)/a[1];
	for(i=1;i<=n&&now>=0;i++)
	{
		now-=(now+m)/a[i];
		now-=(now+m)/b[i];
	}
//	if(now>0) now-=(now+m)/b[n];
	return now>0;
}

int main()
{
	int i,j;
	db l,r,mid;
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%lf",&a[i]);
	for(i=1;i<=n;i++) scanf("%lf",&b[i]);
	for(l=0,r=2e9,i=1;i<=100;i++)
	{
		mid=(l+r)/2;
		pd(mid)?r=mid:l=mid;
	}
	if(l<1e9+10) printf("%.10f",l);
	else puts("-1");
}