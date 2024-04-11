#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi fisrt
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 2010 
#define M 
using namespace std;

ll m,n,t,a[N],b[N],ans,mn[N],qa[N],qb[N];

int main()
{
	memset(mn,0x3f,sizeof(mn));
	mn[0]=0;
	ll i,j,l,r,tmp,gg;
	cin>>m>>n;
	for(i=1;i<=m;i++) scanf("%lld",&a[i]),qa[i]=qa[i-1]+a[i];
	for(i=1;i<=n;i++) scanf("%lld",&b[i]),qb[i]=qb[i-1]+b[i];
	cin>>t;
	for(i=1;i<=m;i++)
	{
		for(j=i;j<=m;j++)
		{
//			cout<<mn[j-i+1]<<qa[j]-qa[i-1]<<endl;
			mn[j-i+1]=min(mn[j-i+1],qa[j]-qa[i-1]);
		}
	}
	
//	for(i=1;i<=m;i++) cout<<mn[i]<<' ';return 0;
	
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			tmp=qb[j]-qb[i-1];
			tmp=t/tmp;
			gg=upper_bound(mn+1,mn+m+1,tmp)-mn-1;
			ans=max(ans,(j-i+1)*gg);
		}
	}
	cout<<ans;
}