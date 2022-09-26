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

set<ll> S;
const int N = 4000;
vi seq;

void gen()
{
	for(int i=1;seq.size()<=N;i++)
	{
		if(S.find(i)!=S.end()) continue;
		seq.pb(i); S.insert(i);
		for(int j=i+1;;j++)
		{
			if(S.find(j)==S.end()&&S.find((i^j))==S.end())
			{
				seq.pb(j); seq.pb(i^j);
				S.insert(j); S.insert(i^j);
				break;
			}
		}
	}
	for(int i=0;i<seq.size();i+=3)
	{
		cout<<seq[i]<<' '<<seq[i+1]<<' '<<seq[i+2]<<'\n';
	}
}

const vi p = {0,2,3,1};

ll getid(int bl, ll pos)
{
	if(bl==0) return 0;
	ll quadrantsiz = (1LL<<(2*bl))/4;
	ll quadrant = pos/quadrantsiz;
	//cerr<<bl<<' '<<pos<<' '<<quadrantsiz<<' '<<quadrant<<'\n';
	return p[quadrant]*1LL*quadrantsiz+getid(bl-1,pos%quadrantsiz);
}

vector<ll> gettriplet(ll x)
{
	ll cur=1; ll sum=0;
	int bl=0; //block 0 is [0,0], block 1 is [1,4], block 2 is [5,20]
	ll pos=0;
	while(x>sum)
	{
		pos=x-(sum+1);
		cur*=4;
		sum+=cur;
		bl++;
	}
	ll a = (1LL<<(2*bl))+pos;
	ll b = (1LL<<(2*bl+1))+getid(bl,pos);
	ll c = (a^b);
	return {a,b,c};
}

void solve()
{
	ll n; cin>>n;
	n--;
	vector<ll> tmp = gettriplet(n/3);
	cout<<tmp[n%3]<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//gen(); return 0;
	/*
	gen();
	for(int i=0;i<N-10;i+=3)
	{
		vector<ll> tmp = gettriplet(i/3);
		assert(tmp[0]==seq[i]);
		assert(tmp[1]==seq[i+1]);
		assert(tmp[2]==seq[i+2]);
	}
	*/
	int t; cin>>t;
	while(t--) solve();
}