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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll intersect(ii a, ii b)
{
	ii inter = mp(max(a.fi,b.fi),min(a.se,b.se));
	if(inter.fi>inter.se) return 0;
	else return inter.se-inter.fi+1;
}

ll l[2],r[2],t[2];
ll g;
ll ans=0;

void test(ll k)
{
	ll L = l[0]+k*g; ll R = r[0]+k*g;
	ll x = L/t[1];
	L-=x*t[1]; R-=x*t[1];
	//cerr<<k<<' '<<l[0]+k*g<<' '<<r[0]+k*g<<'\n';
	for(int z=0;z<2;z++)
	{
		ans = max(ans, intersect(mp(L,R), mp(l[1], r[1])));
		L+=t[1]; R+=t[1];
	}
}

const bool DEBUG=0;

ll brute()
{
	ll res=0;
	for(ll i=0;i<t[1];i++)
	{
		for(ll j=0;j<t[0];j++)
		{
			res=max(res,intersect(mp(l[0]+i*t[0],r[0]+i*t[0]),mp(l[1]+j*t[1],r[1]+j*t[1])));
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);	
	for(int cc=1;;cc++){
	int tl[2],tr[2],tt[2];
	for(int i=0;i<2;i++)
	{		
		ans=0;
		if(!DEBUG) cin>>l[i]>>r[i]>>t[i];
		else
		{
			t[i]=rand()%100+2;
			do
			{
				l[i]=rand()%t[i];
				r[i]=rand()%t[i];
				if(l[i]>r[i]) swap(l[i],r[i]);
			}while(l[i]==0&&r[i]==t[i]-1);
		}
		tl[i]=l[i]; tr[i]=r[i]; tt[i]=t[i];
	}
	ll tmp = 1;
	if(DEBUG) brute();
for(int zzz=0;zzz<2;zzz++)
{
	g = __gcd(t[0],t[1]);
	for(int z=0;z<2;z++)
	{
		//cerr<<l[0]<<' '<<r[0]<<' '<<g<<' '<<l[1]<<' '<<r[1]<<'\n';
		test(0);
		ll lo = 0; ll hi = ll(2e9);
		ll as = 0;
		while(lo<=hi)
		{
			ll mid=(lo+hi)>>1;
			if(l[0]+g*mid<=l[1])
			{
				//cerr<<l[0]<<' '<<g<<' '<<mid<<' '<<l[1]<<'\n';
				as=max(as,mid); lo=mid+1;
			}
			else hi=mid-1;
		}
		//cerr<<as<<' '<<g<<' '<<l[0]+g*as<<' '<<l[1]<<'\n';
		test(as); test(as+1);
		l[1]+=t[1]; r[1]+=t[1];
	}
	for(int i=0;i<2;i++){l[i]=tl[i]; r[i]=tr[i]; t[i]=tt[i];}
	swap(t[0],t[1]);swap(l[0],l[1]);swap(r[0],r[1]);
}
	if(!DEBUG){cout<<ans<<'\n'; return 0;}
	cerr<<"ANS NAIVE "<<tmp<<'\n';
	cerr<<"ANS REAL "<<ans<<'\n';
	if(ans!=tmp)
	{
		freopen("lucky-days.txt","w",stdout);
		cout<<tl[0]<<' '<<tr[0]<<' '<<tt[0]<<'\n'<<tl[1]<<' '<<tr[1]<<' '<<tt[1]<<'\n';
		return 0;
	}
	cerr<<"Case #"<<cc<<" complete\n";
}
}