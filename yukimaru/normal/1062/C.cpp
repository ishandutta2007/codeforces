/*************************************************************************
    > File Name: 1062_C.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Thu 15 Nov 2018 12:12:07 AM CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
#include<cmath>
using namespace std;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

typedef long long ll;
const ll mod=1e9+7;

ll mypow(ll a, ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	ll n, q;
	while(scanf("%lld%lld", &n, &q) != EOF)
	{
		char s[100005]={0};
		scanf("%s", s+1);
		int cnt[100005]={0};
		cnt[0]=0;
		for(int i=1; i<=n; i++)
		{
			cnt[i]=cnt[i-1];
			if(s[i] == '1') cnt[i]++;
		}
		while(q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			ll ans=(mypow((ll)2, (ll)cnt[r]-cnt[l-1])%mod-(ll)1+mod)%mod*(mypow((ll)2, (ll)(r-l+1-(cnt[r]-cnt[l-1])))%mod)%mod;
			printf("%lld\n", ans);
		}
	}
	return 0;
}