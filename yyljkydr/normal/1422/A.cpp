#include<bits/stdc++.h>
using namespace std;

int T,a,b,c;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%lld\n",1ll*a+b+c-1);
	}
}