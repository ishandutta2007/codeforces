#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
#define M 
using namespace std;

ll T,n,m,K,ans[N];
P num[N],og[N];
map<ll,ll>high;
vector<ll>gg[N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j,l,r,mid,t;
	cin>>T;
	while(T--)
	{
		ll tot,sum,cnt;
		high.clear();
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&num[i].fi,&num[i].se);
			og[i]=num[i];
			high[num[i].fi]+=num[i].se;
		}
		sort(num+1,num+n+1);
		
		tot=sum=cnt=0;
		for(i=0;i<=n+1;i++) gg[i].clear();
		for(i=1;i<=n;i=j)
		{
			for(j=0;j<gg[i].size();j++) cnt--,sum-=num[gg[i][j]].fi,tot-=num[gg[i][j]].se;
			high[num[i].fi]+=tot-(cnt*num[i].fi-sum);
			for(j=i;j<=n && num[j].fi==num[i].fi;j++)
			{
				sum+=num[j].fi,tot+=num[j].se,cnt++;
				for(l=1,r=n+1;l<r;)
				{
					mid=((l+r)>>1);
					if(num[mid].fi<num[j].fi+num[j].se) l=mid+1;
					else r=mid;
				}
//				cout<<" gg:"<<l<<" "<<j<<endl;
				gg[l].push_back(j);
			}
		}
		
		/*
		for(i=1;i<=n;i++)
		{
			if(num[i].fi!=num[i-1].fi)
				cout<<" "<<num[i].fi<<" "<<high[num[i].fi]<<endl;
		}
		return 0;
		//*/
		
		tot=cnt=sum=0;
		for(i=0;i<=n+1;i++) gg[i].clear();
		for(i=n;i>=1;i=j)
		{
			for(j=0;j<gg[i].size();j++) cnt--,sum-=num[gg[i][j]].fi,tot-=num[gg[i][j]].se;
			high[num[i].fi]+=tot-(sum-cnt*num[i].fi);
			for(j=i;j>=1 && num[j].fi==num[i].fi;j--)
			{
				sum+=num[j].fi,tot+=num[j].se,cnt++;
				for(l=1,r=n+1;l<r;)
				{
					mid=((l+r)>>1);
					if(num[mid].fi<num[j].fi-num[j].se) l=mid+1;
					else r=mid;
				}
				gg[l-1].push_back(j);
			}
		}
		
		/*
		for(i=1;i<=n;i++)
		{
			if(num[i].fi!=num[i-1].fi)
				cout<<" "<<num[i].fi<<" "<<high[num[i].fi]<<endl;
		}
		//*/
		ll A,B,C,ma,mb,mc;
		ma=mb=mc=-INF;
		A=B=C=0;
		for(i=1;i<=n;i++)
		{
			if(i>1 && num[i].fi==num[i-1].fi || high[num[i].fi]<=m) continue;
			t=high[num[i].fi]-num[i].fi;if(t>ma) ma=t,A=num[i].fi;
			t=high[num[i].fi];if(t>mb) mb=t,B=num[i].fi;
			t=high[num[i].fi]+num[i].fi;if(t>mc) mc=t,C=num[i].fi;
		}
//		cout<<" "<<A<<" "<<B<<" "<<C<<endl;
//		cout<<" "<<ma<<" "<<mb<<" "<<mc<<endl;
		for(i=1;i<=n;i++)
		{
			ans[i]=1;
			if(A)
			{
				high[A]-=max(0ll,og[i].se-abs(og[i].fi-A));
				if(high[A]>m) ans[i]=0;
				high[A]+=max(0ll,og[i].se-abs(og[i].fi-A));
			}
			if(B)
			{
				high[B]-=max(0ll,og[i].se-abs(og[i].fi-B));
				if(high[B]>m) ans[i]=0;
				high[B]+=max(0ll,og[i].se-abs(og[i].fi-B));
			}
			if(C)
			{
				high[C]-=max(0ll,og[i].se-abs(og[i].fi-C));
				if(high[C]>m) ans[i]=0;
				high[C]+=max(0ll,og[i].se-abs(og[i].fi-C));
			}
		}
		for(i=1;i<=n;i++) printf("%lld",ans[i]);
		puts("");
	}
}