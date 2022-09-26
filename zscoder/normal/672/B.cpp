#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<ii, ll> iii;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	set<char> dist;
	for(int i = 0; i < n; i++)
	{
		dist.insert(s[i]);
	}
	int ans = n - dist.size();
	if(n  >= 27) cout << -1;
	else cout << ans;
	return 0;
}