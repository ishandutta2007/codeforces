#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, k, s, ss;
pii a[N];
vector< int > ans;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].f;
		a[i].s =  i;
		ss += a[i].f;
	}
	s = k = a[1].f;
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		if(a[i].f * 2 > k)
			break;
		ans.pb(a[i].s);
		s += a[i].f;
	}
	if(s * 2 <= ss){
		cout << 0;
		return 0;
	}
	ans.pb(1);
	cout << ans.size() << endl;
	for(auto it : ans)
		cout << it << " ";

	return 0;
}