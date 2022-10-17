
 #include<bits/stdc++.h>
#define ll long long
#define db double
#define N 300100
using namespace std;

ll n,m,Q,num[2][N],ans,sum[2][N],s2[2][N],now,hz[2][N];

int main()
{
	ll i,j,p,q,t;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&num[0][i]);
	for(i=1;i<=n;i++) scanf("%lld",&num[1][i]);
	for(i=n;i>=1;i--) sum[0][i]=sum[0][i+1]+num[0][i]*i;
	for(i=n;i>=1;i--) sum[1][i]=sum[1][i+1]+num[1][i]*i;
	for(i=n;i>=1;i--) s2[0][i]=s2[0][i+1]+num[0][i]*(n-i+1);
	for(i=n;i>=1;i--) s2[1][i]=s2[1][i+1]+num[1][i]*(n-i+1);
	for(i=n;i>=1;i--) hz[0][i]=hz[0][i+1]+num[0][i];
	for(i=n;i>=1;i--) hz[1][i]=hz[1][i+1]+num[1][i];
	for(i=1,t=0,j=0;i<=n;t++)
	{
		if(!j&&(i&1))
		{
			ans=max(ans,now+sum[0][i]+hz[0][i]*(t-i)+s2[1][i]+hz[1][i]*(2*n-(n-i+1)-1));
		}
		if(j&&(!(i&1)))
		{
			ans=max(ans,now+sum[1][i]+hz[1][i]*(t-i)+s2[0][i]+hz[0][i]*(2*n-(n-i+1)-1));
		}
		now+=num[j][i]*t;
		if(j&&(i&1))
		{
			ans=max(ans,now+sum[1][i+1]+hz[1][i+1]*(t-i)+s2[0][i+1]+hz[0][i+1]*(2*n-(n-i)-1));
		}
		if(!j&&(!(i&1)))
		{
			ans=max(ans,now+sum[0][i+1]+hz[0][i+1]*(t-i)+s2[1][i+1]+hz[1][i+1]*(2*n-(n-i)-1));
		}
		if((i&1)&&!j||(!(i&1))&&j)
		{
			j^=1;
		}
		else
		{
			i++;
		}
	}
	cout<<ans;
}