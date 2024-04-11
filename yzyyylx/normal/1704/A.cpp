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

ll T,n,m;
char A[N],B[N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		scanf("%s%s",A+1,B+1);
		for(j=2;j<=m;j++)
		{
			if(B[j]!=A[n-(m-j)])
				break;
		}
		if(j<=m)
		{
			puts("NO");
			continue;
		}
		for(i=1;i<=n-m+1;i++)
		{
			if(A[i]==B[1])
				break;
		}
		puts(i>n-m+1?"NO":"YES");
	}
}