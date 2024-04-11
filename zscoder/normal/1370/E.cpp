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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	string t; cin>>t;
	set<int> A[2];
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!=t[i])
		{
			A[s[i]-'0'].insert(i);
		}
	}
	if(A[0].size()!=A[1].size()) {cout<<-1<<'\n'; return 0;}
	while(!A[0].empty())
	{
		//cerr<<A[0].size()<<' '<<A[1].size()<<'\n';
		assert(A[0].size()==A[1].size());
		int cur=0;
		if((*A[1].begin())<(*A[0].begin())) cur=1;
		vi vec;
		int curv = (*A[cur].begin());
		int oricur=cur;
		while(curv<n)
		{
			vec.pb(curv);
			cur^=1;
			auto it = A[cur].lower_bound(curv);
			if(it==A[cur].end()) break;
			curv=(*it);
		}
		cur^=1;
		if(cur==oricur) vec.pop_back();
		for(int i=0;i<vec.size();i++)
		{
			int ps = (i&1)^oricur;
			A[ps].erase(vec[i]);
		}
		ans++;
	}
	cout<<ans<<'\n';
}