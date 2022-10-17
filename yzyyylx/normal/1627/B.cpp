#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100100
#define M 
using namespace std;
 
ll T,n,m,A,B,ans,num[N];
 
int main()
{
	ll i,j,a,b;
	cin>>T;
	while(T--)
	{
		ll tt=0;
		scanf("%lld%lld",&m,&n);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				num[++tt]=max(max(i+j-2,m-i+j-1),max(n-j+i-1,n-j+m-i));
			}
		}
		sort(num+1,num+tt+1);
		for(i=0;i<m*n;i++) printf("%lld ",num[i+1]);
		puts("");
	}
}