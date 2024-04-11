#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN
#define N 200100
#define M 
using namespace std;
 
ll T,n,m,num[N];
char str[N];
 
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		for(i=1;i<=n;i++) num[i]=str[i]-'0';
		for(i=n-1;i>=1;i--) if(num[i]+num[i+1]>=10) break;
		if(i>=1)
		{
			for(j=1;j<i;j++) printf("%lld",num[j]);
			printf("%lld",num[i]+num[i+1]);
			for(j=i+2;j<=n;j++) printf("%lld",num[j]);
			puts("");
		}
		else
		{
			printf("%lld",num[1]+num[2]);
			for(j=3;j<=n;j++) printf("%lld",num[j]);
			puts("");
		}
	}
}