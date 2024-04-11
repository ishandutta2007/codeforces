#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL rin()
{
	LL s=0;
	bool bj=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')bj=1,c=getchar();
	while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^'0'),c=getchar();
	if(bj)return -s;
	return s;
}

inline void work(LL &x)
{
	if(x&1)x=(x+1>>1)<<1;
	else x++;
	return;
}
int main()
{ 
	int i,j;
	LL n=rin();
	LL ans;
	if(n&1)
	{
		LL s_1=(n>>1);
		LL s_2=n-s_1;
		work(s_1);work(s_2);
		ans=(s_1*s_2<<1);
	}
	else
	{
		LL s=(n>>1);
		work(s);
		ans=(s*s);
	}
	printf("%lld\n",ans);
	return 0;
}