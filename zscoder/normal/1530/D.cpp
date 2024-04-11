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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

void prt(vi &a)
{
	set<int> S;
	for(int i=0;i<a.size();i++)
	{
		assert(a[i]!=i); S.insert(a[i]);
		cout<<a[i]+1;
		if(i+1<a.size()) cout<<' ';
	}
	assert(int(S.size())==int(a.size()));
	cout<<'\n';
}

void solve()
{
	int n; cin>>n;
	vi a(n);
	set<int> S;
	set<int> missing;
	for(int i=0;i<n;i++) missing.insert(i);
	for(int i=0;i<n;i++) {cin>>a[i]; a[i]--; S.insert(a[i]); missing.erase(a[i]);}
	//ans is just S.size();
	vi leftover;
	for(int x:missing) leftover.pb(x);
	vi ans(n);
	for(int i=0;i<n;i++) ans[i]=a[i];
	cout<<S.size()<<'\n';
	if(S.size()==n)
	{
		prt(ans); return ;
	}
	if(S.size()==n-1)
	{
		int val = leftover[0];
		set<int> T; int dupval=-1;
		for(int i=0;i<n;i++)
		{
			if(T.find(a[i])!=T.end())
			{
				dupval=a[i];
			}
			T.insert(a[i]);
		}
		//check the two positions of dupval
		for(int i=0;i<n;i++)
		{
			if(a[i]==dupval)
			{
				if(i!=val)
				{
					ans[i]=val; break;
				}
			}
		}
		prt(ans);
		return ;
	}
	//otherwise, firstly get the positions
	set<int> T;
	vi duppos;
	for(int i=0;i<n;i++)
	{
		if(T.find(a[i])!=T.end())
		{
			duppos.pb(i);
		}
		T.insert(a[i]);
	}
	//random_shuffle till u get it, prob high
	while(1)
	{
		bool pos=1;
		random_shuffle(duppos.begin(),duppos.end());
		for(int i=0;i<duppos.size();i++)
		{
			if(duppos[i]==leftover[i]) {pos=0; break;}
		}
		if(pos)
		{
			for(int i=0;i<duppos.size();i++)
			{
				ans[duppos[i]]=leftover[i];
			}
			prt(ans); return ;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	int t; cin>>t;
	while(t--) solve();
}