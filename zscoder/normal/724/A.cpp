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

map<string,int> ma;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ma["monday"] = 1;
	ma["tuesday"] = 2;
	ma["wednesday"] = 3;
	ma["thursday"] = 4;
	ma["friday"] = 5;
	ma["saturday"] = 6;
	ma["sunday"] = 7;
	string s1, s2;
	cin>>s1>>s2;
	int a, b;
	a = ma[s1]; b = ma[s2];
	int d = b - a;
	if(d < 0) d += 7;
	if(d == 0 || d == 2 || d == 3) cout << "YES";
	else cout << "NO";
}