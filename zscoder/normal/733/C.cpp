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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll w[501];
ll s[501];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	int k; cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> s[i];
	}
	bool pos = true;
	ll cursum = 0; int cur = 0;
	for(int i = 0; i < n; i++)
	{
		if(cur >= k){pos=false;break;}
		cursum += w[i];
		if(cursum > s[cur])
		{
			pos = false; break;
		}
		if(cursum == s[cur])
		{
			cur++;
			cursum = 0;
		}
	}
	if(!pos){cout<<"NO"; return 0;}
	if(cur!=k){cout<<"NO"; return 0;}
	cursum = 0; cur = 0; int cnt = 0;
	vector<ii> interval(k+11);
	interval[0].fi = 0;
	for(int i = 0; i < n; i++)
	{
		cursum += w[i];
		cnt++;
		if(cursum == s[cur])
		{
			interval[cur].se = i;
			cur++;
			interval[cur].fi = i+1;
			cursum = 0;
			cnt = 0;
		}
	}
	vector<pair<int,char> > moves;
	int curr = 0;
	for(int i = 0; i < k; i++)
	{
		int l = interval[i].fi; int r = interval[i].se;
		cerr<<l<<' '<<r<<'\n';
		vector<ll> vec;
		vec.pb(ll(1e18));
		for(int j = l; j <= r; j++)
		{
			vec.pb(w[j]);
		}
		vec.pb(ll(1e18));
		while(vec.size()>3)
		{
			bool posi = false;
			for(int j = vec.size() - 2; j >= 1; j--)
			{
				if(vec[j]>vec[j-1])
				{
					vec[j]+=vec[j-1];
					moves.pb(mp(curr+j, 'L'));
					vec.erase(vec.begin()+j-1);
					posi = true;
					break;
				}
				else if(vec[j]>vec[j+1])
				{
					vec[j]+=vec[j+1];
					moves.pb(mp(curr+j, 'R'));
					vec.erase(vec.begin()+j+1);
					posi = true;
					break;
				}
			}
			if(!posi)
			{
				pos = false;
				break;
			}
		}
		if(!pos) break;
		curr++;
	}
	if(!pos)
	{
		pos = true;
		moves.clear();
		curr = 0;
		for(int i = 0; i < k; i++)
		{
			int l = interval[i].fi; int r = interval[i].se;
			cerr<<l<<' '<<r<<'\n';
			vector<ll> vec;
			vec.pb(ll(1e18));
			for(int j = l; j <= r; j++)
			{
				vec.pb(w[j]);
			}
			vec.pb(ll(1e18));
			while(vec.size()>3)
			{
				bool posi = false;
				for(int j = 1; j + 2 <= vec.size(); j++)
				{
					if(vec[j]>vec[j-1])
					{
						vec[j]+=vec[j-1];
						moves.pb(mp(curr+j, 'L'));
						vec.erase(vec.begin()+j-1);
						posi = true;
						break;
					}
					else if(vec[j]>vec[j+1])
					{
						vec[j]+=vec[j+1];
						moves.pb(mp(curr+j, 'R'));
						vec.erase(vec.begin()+j+1);
						posi = true;
						break;
					}
				}
				if(!posi)
				{
					pos = false;
					break;
				}
			}
			if(!pos) break;
			curr++;
		}
		if(!pos){cout<<"NO"; return 0;}
	}
	cout<<"YES\n";
	for(int i = 0; i < moves.size(); i++)
	{
		cout << moves[i].fi << ' ' << moves[i].se << '\n';
	}
}