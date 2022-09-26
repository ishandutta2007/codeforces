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

vector<ii> a;
vector<ii> b;
vector<ll> sa;
vector<ll> sb;

ii idx[1000001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; a.resize(n); b.resize(n); sa.resize(n + 1); sb.resize(n + 1);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].fi; a[i].se = i + 1;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i].fi; b[i].se = i + 1;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sa[0] = 0; sb[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		sa[i] = sa[i - 1] + a[i - 1].fi;
		sb[i] = sb[i - 1] + b[i - 1].fi;
	}
	bool swapped = false;
	if(sa[n] > sb[n])
	{
		swap(a, b);
		swap(sa, sb);
		swapped = true;
	}
	int j = 0;
	for(int i = 0; i <= n - 1; i++)
	{
		idx[i] = ii(-1, -1);
	}
	ii A, B;
	for(int i = 0; i <= n; i++)
	{
		while(sa[i] - sb[j] >= n)
		{
			j++;
		}
		int diff = sa[i] - sb[j];
		if(idx[diff] == ii(-1, -1))
		{
			idx[diff] = ii(i, j);
		}
		else
		{
			A = idx[diff];
			B = ii(i, j);
			break;
		}
	}
	
	if(swapped)
	{
		swap(a, b);
		swap(sa, sb);
		swap(A.fi, A.se); swap(B.fi, B.se);
	}
	
	cout << B.fi - A.fi << '\n';
	for(int i = A.fi + 1; i <= B.fi; i++)
	{
		cout << a[i-1].se << ' ';
	}
	cout << '\n';
	cout << B.se - A.se << '\n';
	for(int i = A.se + 1; i <= B.se; i++)
	{
		cout << b[i-1].se << ' ';
	}
	cout << '\n';
	return 0;
}