/*********************************************************************
    > File Name: 1082_A.cpp
    > Author: yuki
 *********************************************************************/

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

typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ll n, x, y, d;
		scanf("%lld%lld%lld%lld", &n, &x, &y, &d);
		if(abs(y-x)%d!=0 && abs(y-1)%d!=0 && abs(n-y)%d!=0)
			printf("-1\n");
		else
		{
			ll ans=-1, tmp=0;
			if(abs(y-x)%d == 0)
			{
				tmp=abs(y-x)/d;
				if(ans==-1 || tmp<ans) ans=tmp;
			}
			if(abs(y-1)%d == 0)
			{
				if(abs(x-1)%d == 0) tmp=abs(x-1)/d;
				else tmp=abs(x-1)/d+1;
				tmp+=abs(y-1)/d;
				if(ans==-1 || tmp<ans) ans=tmp;
			}
			if(abs(n-y)%d == 0)
			{
				if(abs(n-x)%d == 0) tmp=abs(n-x)/d;
				else tmp=abs(n-x)/d+1;
				tmp+=abs(n-y)/d;
				if(ans==-1 || tmp<ans) ans=tmp;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}