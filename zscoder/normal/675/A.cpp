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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a, b, c; cin >> a >> b >> c;
	if(c==0)
	{
		if(a==b) cout << "YES";
		else cout << "NO";
		return 0;
	}
	if(a==b)
	{
		cout << "YES"; return 0;
	}
	if(c>0&&a>b)
	{
		cout << "NO"; return 0;
	}
	if(c < 0&&a<b)
	{
		cout << "NO"; return 0;
	}
	if((abs(b-a))%abs(c) == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}