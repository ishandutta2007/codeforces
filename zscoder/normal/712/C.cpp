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
	int x, y;
	cin >> x >> y;
	swap(y,x);
	int t = 0;
	int a[3];
	a[0] = x; a[1] = x; a[2] = x;
	while(!(a[0]==y&&a[1]==y&&a[2]==y))
	{
		a[0] = min(y, a[1]+a[2]-1);
		t++;
		sort(a,a+3);
	}
	cout << t << '\n';
}