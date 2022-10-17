#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define N 100100
#define M 998244353
using namespace std;

ll T,n,ans,num[N];
char str[N];
map<ll,ll>cnt;

int main()
{
	ll i,j,t;
	cin>>T;
	while(T--)
	{
		t=ans=0,cnt.clear();
		scanf("%lld",&n);
		scanf("%s",str+1);
		cnt[0]++;
		for(i=1;i<=n;i++)
		{
			num[i]=str[i]-'0'-1;
			t+=num[i];
			ans+=cnt[t];
			cnt[t]++;
		}
		printf("%lld\n",ans);
	}
}