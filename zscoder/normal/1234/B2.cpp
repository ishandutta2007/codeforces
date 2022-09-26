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


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	set<int> S;
	deque<int> dq;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		if(S.find(x)!=S.end()) continue;
		if(dq.size()>=k)
		{
			S.erase(dq.back());
			dq.pop_back();
		}
		S.insert(x);
		dq.push_front(x);
	}
	cout<<dq.size()<<'\n';
	for(int x:dq)
	{
		cout<<x<<' ';
	}
	cout<<'\n';
}