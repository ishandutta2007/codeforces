#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 3000
#define N 200100
#define M 1000000007
using namespace std;

ll T,n,m,a,b;
bool in[N];
vector<ll>ans;

int main()
{
	ll i,j,k,ah,bh,ab,bb,t;
	cin>>T;
	while(T--)
	{
		ans.clear();
		scanf("%lld%lld",&a,&b);
		n=a+b;
		for(i=0;i<=n;i++)
		{
			j=n-i;
			if(abs(i-j)>1) continue;
			for(k=0;k<=i;k++)
			{
				ah=k,ab=i-k;
				bb=a-ah,bh=b-ab;
				if(ah>=0 && ab>=0 && bb>=0 && bh>=0)
				{
					t=ab+bb;
					if(!in[t])
					{
						in[t]=1;
						ans.push_back(t);
					}
				}
			}
		}
		sort(ans.begin(),ans.end());
		printf("%lld\n",(ll)ans.size());
		for(i=0;i<ans.size();i++) printf("%lld ",ans[i]),in[ans[i]]=0;
		puts("");
	}
}