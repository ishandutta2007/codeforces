#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int rem = n % 7; int quo = n/7;
	int mini, maxi;
	if(rem <= 5) mini = 2*quo;
	else if(rem == 6) mini = 2*quo + 1;
	if(rem == 0) maxi = 2*quo;
	else
	{
		if(n == 1) maxi = 1;
		else if(n == 2) maxi = 2;
		else
		{
			n -= 2;
			maxi = 2;
			rem = n % 7; quo = n/7;
			if(rem <= 5) maxi += 2*quo;
			else if(rem == 6) maxi += 2*quo + 1;
		}
	}
	cout << mini << ' ' << maxi;
	return 0;
}