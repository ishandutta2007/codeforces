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
	string s;
	int x = 1;
	while(s.length() < 2000)
	{
		int t = x;
		string k;
		while(t > 0)
		{
			k.append(" ");
			k[int(k.length()) - 1] = (t%10) + '0';
			t /= 10;
		}
		reverse(k.begin(), k.end());
		s.append(k);
		x++;
	}
	//cout << s << '\n';
	cout << s[n-1];
	return 0;
}