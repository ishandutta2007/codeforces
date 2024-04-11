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

bool a[1001][1001];
int C = 1000;

void add(int u, int v)
{
	a[u][v] = a[v][u] = 1;
}

int l = 0; int r = 1;

void upd(int mode)
{
	add(l, l+2);
	l+=2;
	add(l, l+2);
	add(l, l+4);
	add(l+6, l+2);
	add(l+6, l+4);
	l+=6;
	if(r == 1)
	{
		add(0, r+2);
	}
	else
	{
		add(r, r+2);
	}
	r += 2;
	add(r, r + 2);
	r += 2;
	if(mode)
	{
		add(r, l);
	}
	add(r, r + 2);
	r += 2;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k; cin >> k;
	vi dig;
	while(k)
	{
		dig.pb(k&1);
		k>>=1;
	}
	dig.pop_back();
	reverse(dig.begin(), dig.end());
	for(int i = 0; i < dig.size(); i++)
	{
		upd(dig[i]);
	}
	add(l, 1);
	C = max(l, r) + 1;
	cout << C << '\n';
	for(int i = 0; i < C; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(a[i][j]) cout << "Y";
			else cout << "N";
		}
		cout << '\n';
	}
}