#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%lld",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mod 1000000007
#define bitcount    __builtin_popcountll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
ll dp[11][2][1030][70];
ll len[12],a[100];
ll f(ll b,ll in,ll m,ll pos)
{
	if(dp[b][in][m][pos]!=-1)
		return dp[b][in][m][pos];
	if(pos==0)
	{
		if(in!=0&&m==0)
			return dp[b][in][m][pos]=1;
		else
			return dp[b][in][m][pos]=0;
		return dp[b][in][m][pos];
	}
	ll j=0;
	if(in==0)
		j+=f(b,0,m,pos-1);
	else
		j+=f(b,1,(m^1),pos-1);
	for(ll i=1;i<b;i++)
		j+=f(b,1,(m^(1<<i)),pos-1);
	dp[b][in][m][pos]=j;
	return j;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n,i,j,k,in;
    ll ans,l,r,m,q,b;
    k=1e18;
    memset(dp,-1,sizeof dp);
    for(i=2;i<=10;i++)
    {
    	len[i]=1;
    	j=i;
    	while(j<k)
    	{
    		len[i]++;
    		j*=i;
    	}
    	f(i,0,0,len[i]+1);
    }
    sd(q);
    while(q--)
    {
    	sd(b);
    	sd(l);
    	sd(r);
    	ans=0;
    	l--;
    	if(l)
    	{
    		j=l;
    		i=0;
    		while(j)
    		{
    			a[i]=j%b;
    			j/=b;
    			i++;
    		}
    		m=0;
    		in=0;
    		for(j=i-1;j>=0;j--)
    		{
    			for(k=0;k<a[j];k++)
    			{
    				if(k!=0)
    					in=1;
    				if(in==0)
    					ans-=dp[b][0][m][j];
    				else
    					ans-=dp[b][1][(m^(1<<k))][j];
    			}
    			if(in|a[j])
    			{
    				in=1;
    				m=(m^(1<<a[j]));
    			}
    		}
    		ans-=dp[b][in][m][0];
    	}
    	j=r;
    	i=0;
    	while(j)
    	{
    		a[i]=j%b;
    		j/=b;
    		i++;
    	}
    	in=0;
    	m=0;
		for(j=i-1;j>=0;j--)
		{
			for(k=0;k<a[j];k++)
			{
				if(k!=0)
					in=1;
				if(in==0)
					ans+=dp[b][0][m][j];
				else
					ans+=dp[b][1][(m^(1<<k))][j];
			}
			if(in|a[j])
			{
				in=1;
				m=(m^(1<<a[j]));
			}
		}
		ans+=dp[b][in][m][0];
		printf("%lld\n",ans);
    }
    return 0;
}