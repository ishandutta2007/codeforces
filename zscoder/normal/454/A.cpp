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
	int cur = n/2;
	for(int i = 0; i <= n/2 ; i++)
	{
		for(int j = 0; j < cur; j++)
		{
			cout << "*";
		}
		for(int j = 0; j < n - 2*cur; j++)
		{
			cout << "D";
		}
		for(int j = 0; j < cur; j++)
		{
			cout << "*";
		}
		cout << '\n';
		cur--;
	}
	cur = 1;
	for(int i = 0; i < n/2 ; i++)
	{
		for(int j = 0; j < cur; j++)
		{
			cout << "*";
		}
		for(int j = 0; j < n - 2*cur; j++)
		{
			cout << "D";
		}
		for(int j = 0; j < cur; j++)
		{
			cout << "*";
		}
		cout << '\n';
		cur++;
	}
}