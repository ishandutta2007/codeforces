#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a, b, g;
ll ans[N];
int dp[N];

ll sum;

ll get(ll r, ll g){
	ll res = (r % g + 1) * (r/ g);
	r -= r % g + 1;
	if(r < 0)
		return res;
	r /= g;
	return res + g * r * (r + 1) / 2;
}
ll get(ll l, ll r, ll g){
	return get(r, g) - get(l, g) + l / g + r - l + 1;
}
int main()
{
	cin >> n >> a >> b;
	g = __gcd(a, b);
	
	for(int i = 0; i < N; i++)
		dp[i] = inf;
	dp[0] = 0;
	set< pii > st;
	st.insert({dp[0], 0});
	while(!st.empty()){
		int v = st.begin() -> s;
		st.erase(st.begin());
		if(v + a < N && dp[v + a] > max(dp[v], v + a)){
			st.erase({dp[v + a], v + a});
			dp[v + a] = max(dp[v], v + a);
			st.insert({dp[v + a], v + a});
		}
        if(v - b >= 0 && dp[v - b] > dp[v]){
			st.erase({dp[v - b], v - b});
			dp[v - b] = dp[v];
			st.insert({dp[v - b], v - b});
		}
	}
	for(int i = 0; i < N; i++)
		if(dp[i] < N)
			ans[dp[i]]++;
	for(int i = 1; i < N; i++)
		ans[i] += ans[i - 1];

	if(n < N){
		for(int i = 0; i <= n; i++)
			sum += ans[i];
		cout << sum;
	}else{
		for(int i = 0; i < N; i++)
			sum += ans[i];
		cout << sum + get(N, n, g);
	}

	return 0;
}