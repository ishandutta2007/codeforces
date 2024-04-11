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
	string a, b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	int pos = a.length();
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] != '0')
		{
			pos = i;
			break;
		}
	}
	if(pos == a.length())
	{
		if(b == "0") cout<<"OK";
		else cout<<"WRONG_ANSWER";
		return 0;
	}
	string s;
	s += a[pos];
	for(int i = 0; i < pos; i++) s += "0";
	for(int i = pos + 1; i < a.length(); i++) s += a[i];
	if(b == s) cout << "OK";
	else cout << "WRONG_ANSWER";
}