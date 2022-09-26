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

int a[150001];
set<ii> ans;
int n;

bool check(int i)
{
	if(i < 0) return 1;
	if(i >= n - 1) return 1;
	if((i&1) && (a[i] <= a[i + 1]))
	{
		return 0;
	}
	if(!(i&1) && (a[i] >= a[i + 1]))
	{
		return 0;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}	
	vi bad;
	for(int i = 0; i < n - 1; i++)
	{
		if((i&1) && (a[i] <= a[i + 1]))
		{
			bad.pb(i);
		}
		if(!(i&1) && (a[i] >= a[i + 1]))
		{
			bad.pb(i);
		}
	}
	if(bad.size() > 4)
	{
		cout << 0;
		return 0;
	}
	int x = bad[0];
	int y = x + 1;
	//cout << x << ' ' << y << endl;
	for(int i = 0; i < n; i++)
	{
		if(i == x) continue;
		bool pos = true;
		for(int j = 0; j < bad.size(); j++)
		{
			if(x == bad[j] || x - 1 == bad[j] || i - 1 == bad[j] || i == bad[j]){}
			else pos = false;
		}
		if(!pos) continue;
		swap(a[i], a[x]);
		if(check(i) && check(i - 1) && check(x) && check(x - 1))
		{
			ans.insert(ii(min(i, x), max(i, x)));
		}
		swap(a[i], a[x]);
	}
	for(int i = 0; i < n; i++)
	{
		if(i == y) continue;
		bool pos = true;
		for(int j = 0; j < bad.size(); j++)
		{
			if(y == bad[j] || y - 1 == bad[j] || i - 1 == bad[j] || i == bad[j]){}
			else pos = false;
		}
		if(!pos) continue;
		swap(a[i], a[y]);
		if(check(i) && check(i - 1) && check(y) && check(y - 1))
		{
			ans.insert(ii(min(i, y), max(i, y)));
		}
		swap(a[i], a[y]);
	}
	/*
	for(set<ii>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		cout << (*it).fi << ' ' << (*it).se << endl;
	}
	*/
	cout << ans.size();
	return 0;
}