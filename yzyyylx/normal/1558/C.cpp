#include<bits/stdc++.h>
#define ll long long
#define db double
#define PP pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 4000000
#define N 4001000
using namespace std;

ll T,n,m,num[N],pos[N];
vector<ll>ans;

inline void work(ll u)
{
	ans.push_back(u);
	ll i,j;
	for(i=1,j=u;i<=j;i++,j--)
	{
		swap(num[i],num[j]);
		pos[num[i]]=i;
		pos[num[j]]=j;
	}
}

int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		ans.clear();
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&num[i]),pos[num[i]]=i;
		for(i=1;i<=n;i++) if((num[i]&1) != (i&1)) break;
		if(i<=n)
		{
			puts("-1");
			continue;
		}
		for(i=n;i>1;i-=2)
		{
//			cout<<i<<endl;
			if(pos[i-1]!=pos[i]-1)
			{
				if(pos[i]!=pos[i-1]-1)
				{
					if(pos[i]!=1) work(pos[i]);
					if(pos[i-1]!=2) work(pos[i-1]-1);
				}
				work(pos[i-1]+1);
				work(3),work(i);
			}
			else if(i!=pos[i])
			{
				work(pos[i]),work(i);
			}
		}
		printf("%lld\n",(ll)ans.size());
		for(i=0;i<ans.size();i++) printf("%lld ",ans[i]);
		puts("");
	}
}