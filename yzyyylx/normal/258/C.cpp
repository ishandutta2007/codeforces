#include<bits/stdc++.h>
#define N 100010
#define ll long long
#define M 1000000007
using namespace std;

ll n,a,cnt[N],sum[N],mx,an,ans;

ll pow(ll u,ll v)
{
	ll i,z=1;
	while(v!=0)
	{
		if(v&1)
		z=z*u%M;
		u=u*u%M;
		v=(v >> 1);
	}
	return z;
}

ll fj(ll u)
{
	ll i,j=0,v;
	v=(ll)sqrt(u+0.5);
	for(i=1;i<=v;i++)
	{
		if(u%i==0)
		{
			j++;
			cnt[j]=i;
			if(i*i!=u)
			{
				j++;
				cnt[j]=u/i;
			}
		}
	}
	return j;
}

void js(ll z)
{
	ll i,j,len,gs,k;
	an=1;
	len=fj(z);
	sort(cnt+1,cnt+len+1);
	for(i=1;i<len;i++)
	{
		an=(an*pow(i,sum[cnt[i+1]-1]-sum[cnt[i]-1]))%M;
	}
	gs=n-sum[cnt[len]-1];
	k=(pow(len,gs)+M-pow(len-1,gs))%M;
	an=(an*k)%M;
	ans=(ans+an)%M;
}

int main()
{
	ll i,j,p=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		mx=max(mx,a);
		sum[a]++;
	}

	for(i=1;i<N;i++)
	{
		sum[i]+=sum[i-1];
	}
	
	for(i=1;i<=mx;i++)
	{
		js(i);
	}
	cout<<ans;
}