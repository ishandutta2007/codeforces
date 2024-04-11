#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

ll k;
ll find_id(ll n,P p)//p=func(n)
{
	if(p.first==n) return p.second*(k+1);
	ll zan=n-(p.second-1)*(k+1);
	ll cnt=p.second-1+zan/k;
	ll ret=cnt*(k+1)+zan%k;
	if(zan%k==0) ret--;
	return ret;
}
ll get_ksum(ll start,ll ng)
{
	ll ret=k*(2*start+k-1)/2;
	if(start<=ng&&ng<=start+k-1) ret+=start+k-ng;
	return ret;
}
P func(ll n)
{
	if(n<k*(k+1)/2) return P(k*(k+1)/2,1);
	ll s=(((2LL*n)/k)-k+1)/2;
	P p=func(s);
	if(p.first==s)
	{
		ll id=find_id(s-1,p);
		ll start=s+(k+1-id%(k+1));
		id=(id/(k+1)+1)*(k+1)+1;
		return P(get_ksum(start,-1),id/(k+1)+1);
	}
	else
	{
		ll id=find_id(s,p);
		//printf("%lld : %lld [%lld %lld] %lld\n",n,s,p.first,p.second,id);
		if(id%(k+1)!=1||get_ksum(s,p.first)<n)
		{
			ll start=s+(k+1-id%(k+1));
			id=(id/(k+1)+1)*(k+1)+1;
			if(start>=p.first) start++;
			return P(get_ksum(start,p.first),id/(k+1)+1);
		}
		else
		{
			return P(get_ksum(s,p.first),id/(k+1)+1);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll n;
		scanf("%lld %lld",&n,&k);
		P p=func(n);
		//printf("* %lld %lld\n",p.first,p.second);
		printf("%lld\n",find_id(n,p));
	}
	return 0;
}