#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9;
const ll INF = 1e18;

int n, ptr;
ll ans, dp[N];
pair< pll, ll> a[N];
vector< pll > v;
double cross(pll a, pll b){
	return 1.0 * (a.s - b.s) / (b.f - a.f);
}
void add(ll k, ll b){
	pll x = {k, b};
	while(v.size() >= 2){        
		pll l2 = v[v.size() - 1];
		pll l1 = v[v.size() - 2];
		if(cross(l2, x) < cross(l1, x))
			v.pop_back();	
		else
			break;
	}
	v.pb(x);
}
ll pl(pll a, ll x){
	return a.f * x + a.s;
}
ll get(ll x){
    if(v.empty())
    	return 0;
	ptr = min(ptr, (int)v.size() - 1);
	while(ptr + 1 < v.size() && pl(v[ptr], x) < pl(v[ptr + 1], x))
		ptr++;
	return v[ptr].f * x + v[ptr].s;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld%lld%lld", &a[i].f.f, &a[i].f.s, &a[i].s);
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		ll x = a[i].f.f;
		ll y = a[i].f.s;
		dp[i] = x * y - a[i].s + max(0ll, get(-y));
		add(x, dp[i]);	
		ans = max(ans, dp[i]);
	}
	printf("%lld", ans);
	return 0;
}