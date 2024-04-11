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
int main()
{
	LL i,j;
	LL n;
	LL x;
	cin>>n;
	LL ans=0;
	for(i=1;i<=n;i++)x=rin(),ans+=(x-1)*i+1;
	cout<<ans;
	return 0;
}