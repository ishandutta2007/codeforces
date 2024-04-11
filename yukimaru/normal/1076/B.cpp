/*************************************************************************
    > File Name: 1076_B.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Wed 14 Nov 2018 10:31:49 PM CST
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

int main()
{
	ll n;
	while(scanf("%lld", &n) != EOF)
	{
		ll ans=0;
		if(n%(ll)2 == 0)
			ans=(ll)n/(ll)2;
		else
		{
			ll tmp=-1;
			for(ll i=3; i*i<=n; i+=2)
				if(n%i == 0)
				{
					tmp=i;
					break;
				}
			if(n>1 && tmp==-1) tmp=n;
			ans=(ll)(n-tmp)/(ll)2;
			ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}