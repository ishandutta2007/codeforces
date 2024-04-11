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
const ll INF = 2e18;


int n, q;
ll a[N], pre[N];
vector< ll > v;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	
	for(int i = 1; i + 1 <= n; i++)
		v.pb(a[i + 1] - a[i]);
	sort(v.begin(), v.end());	
	
	for(int i = 0; i < v.size(); i++){
		pre[i] = v[i];
		if(i)
			pre[i] += pre[i - 1];
	}

	scanf("%d", &q);
	while(q--){
		ll l, r;
		scanf("%lld%lld", &l, &r);
		ll x = r - l + 1;
		int id = upper_bound(v.begin(), v.end(), x) - v.begin();
		ll res = 0;
		if(id)
			res += pre[id - 1];
		res += x * (n - id);
		printf("%lld ", res);
	}
	return 0;
}