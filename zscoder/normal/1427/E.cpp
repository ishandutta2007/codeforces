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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<pair<int,ii> > moves;

void pt()
{
	cout<<moves.size()<<'\n';
	for(auto X:moves)
	{
		if(X.fi==0)
		{
			cout<<X.se.fi<<" + "<<X.se.se<<'\n';
		}
		else
		{
			cout<<X.se.fi<<" ^ "<<X.se.se<<'\n';
		}
	}
}
void xr(ll x, ll y)
{
	moves.pb({1,{x,y}});
	if((x^y)==1) 
	{
		pt();
		exit(0);
	}
}

void ad(ll x, ll y)
{
	moves.pb({0,{x,y}});
	if((x+y)==1) 
	{
		pt();
		exit(0);
	}
}

struct gausselim
{
	ll cnt[64][2];
	int rank;
	ll cyc[64];
	ll tmp;
	
	void init()
	{
		for(int i = 0; i < 62; i++)
		{
			cyc[i] = cnt[i][0] = cnt[i][1] = 0;
		}
		rank = tmp = 0;
	}
	void add(ll x)
	{
		tmp|=x;
		for(int i = 62; i >= 0; i--)
		{
			if(x&(1LL<<i))
			{
				if(cyc[i]==0)
				{
					cyc[i] = x;
					//cerr<<i<<' '<<cyc[i]<<'\n';
					rank++;
					break;
				}
			}
			if((x^cyc[i])<x)
			{
				xr(x,cyc[i]);
				x=(x^cyc[i]);
			}
		}	
	}
};

void solve(ll x)
{
	moves.clear();
	vector<ll> vec;
	vec.pb(x);
	for(int i=0;i<=30;i++)
	{
		ad(x*(1LL<<i),x*(1LL<<i));
		vec.pb(x*(1LL<<(i+1)));
	}
	//ad(x,x);
	//vec.pb(2*x);
	while(vec.size()<=1500)
	{
		ll l=vec[rand()%int(vec.size())];
		ll r=vec[rand()%int(vec.size())];
		int p=rand()%2;
		if(p<=2)
		{
			if(l+r<=ll(2e18))
			{
				ad(l,r);
				vec.pb(l+r);
			}	
		}
		else 
		{
			if((l^r)>0&&(l^r)<=ll(2e18))
			{
				vec.pb((l^r));
				xr(l,r);
			}
		}
	}
	gausselim G; G.init();
	for(auto X:vec)
	{
		G.add(X);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(1201);
	ll n; cin>>n; solve(n); return 0;
	/*
	ii mxsteps = {0,0};
	for(int i=3;i<=999999;i+=2)
	{
		int res = get_min_steps(i);
		mxsteps=max(mxsteps,{res,i});
		if(i%10000==1)
		{
			cerr<<"ITERATION TILL "<<i<<'\n';
			cerr<<"MXSTEPS = ("<<res<<", "<<i<<")\n";
		}
	}
	*/
	for(int i=3;i<=999999;i+=2)
	{
		solve(i);
		if(i%10000==1)
		{
			cerr<<"ITERATION TILL "<<i<<'\n';
		}
	}
}