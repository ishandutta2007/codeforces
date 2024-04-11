#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

vi a;
vi ans;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, m;
	cin >> n >> m;
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		a.pb(x);
	}
	ll sum = 0;
	sort(a.begin(), a.end());
	ll idx = 1; ll cnt = 0;
	while(sum + idx <= m)
	{
		if(!binary_search(a.begin(), a.end(), idx))
		{
			sum += idx;
			if(sum <= m)
			{
				ans.pb(idx);
			}
			cnt++;
		}
		idx++;
	}
	cout << cnt << "\n";
	for(int i = 0; i < cnt; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}