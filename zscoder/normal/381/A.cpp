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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	deque<int> dq;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		dq.pb(x);
	}
	int a = 0; int b = 0;
	for(int i = 0; i < n; i++)
	{
		if(i&1) b += max(dq.front(), dq.back());
		else a += max(dq.front(), dq.back());
		if(dq.front()> dq.back()) dq.pop_front();
		else dq.pop_back();
	}
	cout << a << ' ' << b;
}