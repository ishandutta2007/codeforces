#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 200100
#define M 
using namespace std;

ll T,n,m,cnt,num[N],ri[N],qz[N];
vector<ll>ans;

inline void work(ll u)
{
	num[u]=num[u+1]=num[u+2]=(num[u]^num[u+1]^num[u+2]);
	ans.push_back(u);
}

inline void work(ll u,ll v)
{
	ll i,j,k;
	i=u,j=v-1;
	if((j-i)&1)
	{
		for(k=i;k<j;k+=2) work(k);
		for(k=j-1;k>i;k-=2) work(k-2);
	}
	else
	{
		for(k=i;k<j;k+=2) work(k);
	}
}

int main()
{
	ll i,j,p,q,t;
	cin>>T;
	while(T--)
	{
		cnt=0;
		ans.clear();
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			qz[i]=qz[i-1]+num[i];
			cnt+=num[i];
		}
		if((cnt&1) || cnt==n)
		{
			puts("NO");
			continue;
		}
		ri[n+1]=0;
		for(i=n;i>=1;i--)
		{
			if(!num[i]) ri[i]=0;
			else ri[i]=ri[i+1]+1;
		}
//		for(i=1;i<=n;i++) cout<<" "<<ri[i]<<" ";puts("");
		for(p=1;p<n;p++)
		{
			if(num[p] && !num[p+1])
			{
				if(!(qz[p]&1)) continue;
				for(q=p+1;q<n;q++) if(!num[q] && num[q+1]) break;
//				cout<<" "<<p<<" "<<q+1<<endl;
				if(q<n) work(p,q+1);
				else break;
			}
		}
//		puts("OK");
		for(i=1;i<=n-2;i++) if(!num[i] && num[i+1] && num[i+2]) work(i);
		for(i=n-2;i>=1;i--) if(!num[i+2] && num[i+1] && num[i]) work(i);
		for(i=1;i<=n;i++) if(num[i]) break;
		if(i<=n)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%lld\n",(ll)ans.size());
		for(i=0;i<ans.size();i++) printf("%lld ",ans[i]);
		puts("");
//		for(i=1;i<=n;i++) cout<<num[i];puts("");
	}
}
/*
2
19
1 1 1 0 0 0 1 1 1 1 0 0 1 1 0 0 1 1 1
11
1 0 0 1 0 0 1 0 0 1 0 0 1 0
*/