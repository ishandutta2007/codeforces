#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int maxl = 1; int minr = n;
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		if(x > y) swap(x, y);
		maxl = max(maxl, x);
		minr = min(minr, y);
	}
	cout << max(0, minr - maxl);
}