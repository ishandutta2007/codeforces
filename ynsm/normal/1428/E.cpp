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
 
int n, k, a[N], cnt[N];
set< pll > st;
ll ans;
ll get(ll x, ll k){
	ll a, b, ca, cb;
	a = x / k;
	b = x / k + 1;
	cb = x % k;
	ca = k - cb;
	return a * a * ca + b * b * cb;
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cnt[i] = 1;
		ans += get(a[i], cnt[i]);
		st.insert({get(a[i], cnt[i] + 1) - get(a[i], cnt[i]), i});
	}	
	k -= n;
	while(k--){
		int i = st.begin() -> s;
		ans += st.begin() -> f;
		st.erase({get(a[i], cnt[i] + 1) - get(a[i], cnt[i]), i});
		cnt[i]++;
		st.insert({get(a[i], cnt[i] + 1) - get(a[i], cnt[i]), i});
	}
	printf("%lld", ans);
}