#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi fisrt
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100010 
#define M 
using namespace std;

ll m,n,t,a[N],b[N],ans,mn[N],qa[N],qb[N];

int main()
{
	ll i,j,l,r,tmp,gg;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
	{
		ans+=max(a[i],b[i])+1;
	}
	cout<<ans;
}