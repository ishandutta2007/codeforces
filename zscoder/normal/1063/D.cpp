#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll naive(ll n, ll l, ll r, ll k)
{
	l--; r--;
	int ans=-1;
	for(int i=0;i<(1<<n);i++)
	{
		vector<int> vec(n);
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) vec[j]=2;
			else vec[j]=1;
		}
		int cur=l; int lastguy=l;
		ll candy=k;
		while(candy>0)
		{
			candy--;
			if(vec[cur]==2&&candy>0) candy--;
			lastguy=cur; cur=(cur+1)%n;
		}
		if(lastguy==r){ans=max(ans,__builtin_popcount(i));}
	}
	return ans;
}

ll solve(ll n, ll l, ll r, ll k)
{
	if(l>r) r+=n;
	ll rem = (r-l+1)%n;
	if(rem==0)
	{
		ll ans = -1;
		{
			vector<ll> divi;
			for(ll i=1;i*i<=k;i++)
			{
				if(k%i==0)
				{
					divi.pb(i);
					if(i*i!=k) divi.pb(k/i);
				}
			}
			for(ll v:divi)
			{
				if(v>=n&&v<=2LL*n) ans=max(ans,v-n);
			}
		}
		{
			k++;
			vector<ll> divi;
			for(ll i=1;i*i<=k;i++)
			{
				if(k%i==0)
				{
					divi.pb(i);
					if(i*i!=k) divi.pb(k/i);
				}
			}
			for(ll v:divi)
			{
				if(v>=n+1&&v<=2LL*n) ans=max(ans,v-n);
			}
		}
		return ans;
	}
	else
	{
		ll C = k - rem;
		if(C<0){return -1;}
		ll ans=-1;
		const ll HF = ll(4e5);//ll(5e5);
		const ll HF2 = ll(4e5);//ll(5e5);
		{
			for(ll i=1;i<=HF;i++)
			{
				//n + x = i
				if(i>=n&&i<=2*n)
				{
					ll x = i - n;
					ll y = C%i;
					ll miny = x + rem - n;
					ll maxy = min(x, rem);
					if(y>=miny&&y<=maxy) ans=max(ans,x);
				}
			}
			for(ll i=0;i<=HF2;i++)
			{
				//R = i
				ll R = i;
				ll lo = 0; ll hi = n; ll res=-1;
				while(lo<=hi)
				{
					ll mid=(lo+hi)>>1;
					if(R*(n+mid)+max(mid+rem-n,0LL)<=C)
					{
						res=max(res,mid);
						lo=mid+1;
					}
					else hi=mid-1;
				}		
				if(res!=-1)
				{
					if(C<=R*(n+res)+min(res,rem))
					{
						ans=max(ans,res);
					}
				}
			}
		}
		{
			C++;
			for(ll i=1;i<=HF;i++)
			{
				//n + x = i
				if(i>=n&&i<=2*n)
				{
					ll x = i - n;
					ll y = C%i;
					ll miny = max(1LL, x + rem - n);
					ll maxy = min(x, rem);
					if(y>=miny&&y<=maxy) ans=max(ans,x);
				}
			}
			for(ll i=0;i<=HF2;i++)
			{
				//R = i
				ll R = i;
				ll lo = 1; ll hi = n; ll res=-1;
				while(lo<=hi)
				{
					ll mid=(lo+hi)>>1;
					if(R*(n+mid)+max(mid+rem-n,1LL)<=C)
					{
						res=max(res,mid);
						lo=mid+1;
					}
					else hi=mid-1;
				}		
				if(res!=-1)
				{
					if(C<=R*(n+res)+min(res,rem))
					{
						ans=max(ans,res);
					}
				}
			}
		}
		return ans;
	}
}

const bool DEBUG=0;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,l,r,k;
	for(int cc=1;;cc++)
	{ 
		if(!DEBUG) cin>>n>>l>>r>>k;
		else
		{
			n=rand()%6+1;
			l=rand()%n+1;
			r=rand()%n+1;
			k=rand()%60+1;
		}
		if(!DEBUG)
		{
			cout<<solve(n,l,r,k)<<'\n'; return 0;
		}
		ll ans1 = naive(n,l,r,k);
		ll ans2 = solve(n,l,r,k);
		cerr<<"SLOW : "<<ans1<<'\n';
		cerr<<"FAST : "<<ans2<<'\n';
		if(ans1!=ans2)
		{
			freopen("candies-for-child.txt","w",stdout);
			cout<<n<<' '<<l<<' '<<r<<' '<<k<<'\n';
			return 0;
		}
		cerr<<"Case #"<<cc<<" completed\n";
	}
}