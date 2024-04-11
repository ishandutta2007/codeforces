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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
typedef vector<ll>::iterator vit;

ll a[400001];
bool inset[400001];
deque<ll> dq[400001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	set<ii> s;
	int n,k; cin>>n>>k;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		dq[a[i]].pb(i);
	}
	ll ans=0;
	int INF =1000000;
	for(int i=0;i<=n;i++) dq[i].pb(INF);
	for(int i=0;i<n;i++)
	{
		if(!inset[a[i]])
		{
			while(s.size()>=k)
			{
				set<ii>::iterator it = s.begin();
				assert(-(*it).fi>i);
				assert((*it).se!=a[i]);
				inset[(*it).se]=0;
				s.erase(it);
			}
			s.insert(mp(-i,a[i]));
			inset[a[i]]=1;
			ans++;
		}
		s.erase(mp(-dq[a[i]].front(),a[i]));
		assert(dq[a[i]].front()==i);
		dq[a[i]].pop_front();
		s.insert(mp(-dq[a[i]].front(),a[i]));
	}
	cout<<ans<<'\n';
}