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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vector<pair<ii,int> > vec;

struct PBDS
{
	tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> t;
	int timer;
	
	PBDS(){timer = 0;}
	void insert(int x)
	{
		t.insert(mp(x, timer));
		timer++;
	}
	
	int lower(int x)
	{
		return t.order_of_key(ii(x, -1));
	}
	
	void del(int x) //make sure x exists
	{
		ii tmp = (*t.find_by_order(lower(x)));
		t.erase(tmp);
	}
	
	int higher(int x)
	{
		int tmp = lower(x+1);
		return (int(t.size()) - tmp);
	}
};


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		int x,y; cin>>x>>y;
		vec.pb(mp(mp(x,y),i+1));
	}
	sort(vec.begin(),vec.end());
	PBDS t;
	for(int i = 0; i < k; i++) t.insert(vec[i].fi.se);
	int range = -1; int bestidx = -1;
	for(int i = k - 1; i < n; i++)
	{
		int l = vec[i].fi.fi;
		int r = (*t.t.find_by_order(int(t.t.size()) - k)).fi;
		//cerr<<l<<' '<<r<<'\n';
		int ran = max(r-l+1, 0);
		if(ran>range)
		{
			range=ran;
			bestidx=i;
		}
		if(i+1<n) t.insert(vec[i+1].fi.se);
	}
	//cerr<<range<<' '<<bestidx<<'\n';
	vector<ii> v;
	for(int i = 0; i <= bestidx; i++)
	{
		v.pb(mp(vec[i].fi.se,vec[i].se));
	}
	cout<<range<<'\n';
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int maxi = -1000000001;
	int mini = 1000000001;
	for(int i = 0; i < k; i++)
	{
		cout<<v[i].se<<' ';
		//maxi=max(vec[v[i].se-1].fi.fi,maxi);
		//mini=min(vec[v[i].se-1].fi.se,mini);
	}
	//int rang = max(mini-maxi+1,0);
	//cerr<<rang<<' '<<range<<'\n';
	//assert(rang==range);
}