#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define base 127
#define cs 123
#define N 3010
#define M 1000000007
using namespace std;

ll n,K,ans,tt,dp[N][N],num[N],gg[N];
struct Node
{
	ll son[2];
}node[N*N];

int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);
	ll i,j,k,p,q,t,h,now;
	gg[12]=gg[10]=gg[7]=gg[15]=1;
	tt=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		now=1;
		for(j=i;j>=1;j--)
		{
			t=0;
			for(k=i;k>=max(i-3,j);k--)
			{
				t=t*2+num[k];
				if(k==i-3&&gg[t]) break;
				if(k>j) p=dp[j][k-1];
				else p=1;
//				cerr<<' '<<j<<' '<<i<<' '<<k<<" "<<p<<endl;
				dp[j][i]+=p,dp[j][i]%=M;
			}
			if(node[now].son[num[j]])
			{
				now=node[now].son[num[j]];
				continue;
			}
			node[now].son[num[j]]=++tt;
			now=node[now].son[num[j]];
			ans+=dp[j][i];
//			cerr<<j<<" "<<i<<" "<<dp[j][i]<<" "<<ans<<endl;
			ans%=M;
		}
		printf("%lld\n",ans);
	}
}