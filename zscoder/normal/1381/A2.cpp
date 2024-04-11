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

int getback(deque<int> &dq, int f, int r)
{
	if(r)
	{
		return dq[0]^f;
	}
	else
	{
		return dq.back()^f;
	}
}

void print(deque<int> &dq, int f, int r)
{
	if(r)
	{
		for(int i=int(dq.size())-1;i>=0;i--)
		{
			cerr<<(dq[i]^1)<<' ';
		}
		cerr<<'\n';
	}
	else
	{
		for(int i=0;i<dq.size();i++)
		{
			cerr<<(dq[i]^1)<<' ';
		}
		cerr<<'\n';
	}
}

void solve()
{
	int n; cin>>n;
	string s,t; cin>>s>>t;
	deque<int> dq;
	int flp = 0;
	int rev = 0;
	for(int i=0;i<n;i++) dq.pb(s[i]-'0');
	vi moves;
	for(int i=n-1;i>=0;i--)
	{
		int bk = getback(dq,flp,rev);
		int target = t[i]-'0';
		//cerr<<"START "<<i<<'\n';
		//print(dq,flp,rev);
		if(bk==target)
		{
			if(flp) dq.pop_front();
			else dq.pop_back();
			continue;
		}
		int frt = getback(dq,flp,rev^1); //get first element
		if(frt==target)
		{
			if(flp) dq[int(dq.size())-1]^=1;
			else dq[0]^=1;
			moves.pb(0);
		}
		rev^=1;
		flp^=1;
		moves.pb(i);
		int bb = getback(dq,flp,rev);
		assert(bb==target);
		if(flp) dq.pop_front();
		else dq.pop_back();
	}
	cout<<moves.size()<<' ';
	for(int x:moves)
	{
		cout<<x+1<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}