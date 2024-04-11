#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define N 100100
#define M
using namespace std;

ll T,n,m,sum,ans,L,R,num[N];
char A[N],B[N];

int main()
{
	ll i,j,t;
	cin>>T;
	while(T--)
	{
		ll cnt=0,ca,cb;
		ca=cb=0;
		scanf("%lld",&n);
		scanf("%s%s",A+1,B+1);
		for(i=1;i<=n;i++)
		{
			if(A[i]!=B[i])
				cnt++;
			if(A[i]=='1') ca++;
			if(B[i]=='1') cb++;
		}
		if(!cnt)
		{
			puts("0");
			continue;
		}
		if(!ca)
		{
			puts("-1");
			continue;
		}
		if(ca==cb && n-ca+1!=cb) printf("%lld\n",cnt);
		else if(n-ca+1==cb)
		{
			ans=1;
			bool ok=0;
			for(i=1;i<=n;i++) if(B[i]=='1' && A[i]=='1') ans+=2;
			ans-=2;
			if(ca==cb) ans=min(ans,cnt);
			printf("%lld\n",ans);
		}
		else puts("-1");
	}
}