#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[222222];
const int C = 200;
const int N = 222222;
ii F[522222];

ll sum(ll n, ll m)
{
	ll q = n/m; ll r = n%m;
	ll ans = m*((q-1)*q)/2;
	ans+=q*(r+1);
	return ans;
}

ll sum(ll l, ll r, ll m)
{
	l=max(l,0LL);
	if(l>r) return 0;
	if(l==0) return sum(r,m);
	return sum(r,m)-sum(l-1,m);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n=s.length();
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+s[i-1]-'0';
	}
	for(int i=0;i<=520000;i++)
	{
		F[i]=mp(int(1e9),-1);
	}
	for(int i=0;i<=n;i++)
	{
		F[a[i]].fi=min(F[a[i]].fi,i);
		F[a[i]].se=max(F[a[i]].se,i);
	}	
	//# of pairs (i,j) with i<j such that a[j]-a[i]|j-i
	ll ans = 0;
	for(int i=1;i<=C;i++)
	{
		unordered_map<int,int> ma;
		for(int j=0;j<=n;j++)
		{
			ma[j-i*a[j]]++;
		}
		for(auto x:ma)
		{
			ans+=ll(x.se)*(ll(x.se)-1);
		}
	}
	ans>>=1;
	//for large quotients
	for(ll i=1;i<=N/C;i++)
	{
		for(int l=0;l<=n;l++)
		{
			int r=l+i;
			if(F[r].se==-1) break;
			ll l1 = F[l].fi; ll r1 = F[l].se;
			ll l2 = F[r].fi; ll r2 = F[r].se;
			//cerr<<i<<' '<<l<<' '<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' '<<ans<<'\n';
			ll minlen = (C+1)*i;
			l2-=l1; r1-=l1; r2-=l1; l1=0;
			//cerr<<i<<' '<<l<<' '<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' '<<ans<<'\n';
			if(r2<minlen) continue;
			ans+=sum(max(minlen,r2-r1),r2,i);
			ans-=sum(max(minlen-1,l2-r1-1),l2-1,i);
			/*
			//cerr<<sum(max(minlen,r2-r1),r2,i)<<' '<<sum(max(minlen-1,l2-r1-1),l2-1,i)<<' '<<minlen<<'\n';
			{
				ll minlencnt = max(0LL,min(min(l2,minlen)-(l2-r1),r2-l2));
				ans-=minlencnt*((minlen-1)/i);
				//cerr<<minlen<<' '<<minlencnt<<' '<<ans<<'\n';
			}
			*/
			ll L = max(minlen-(r2-l2),l2-r1);
			ll R = min(l2,minlen-1);
			ll minlencnt = max(0LL,R-L+1);
			ans-=minlencnt*((minlen-1)/i);
			//cerr<<"ANS: "<<ans<<'\n';
		}
	}
	cout<<ans<<'\n';
}