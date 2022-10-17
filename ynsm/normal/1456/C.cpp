#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, k;
ll a[N], f[N], g[N];
ll get(int l, int r){
	if(l > r)
		return 0;
	if(l)
		return a[r] - a[l - 1];
	else
		return a[r];
}
int main()
{
	scanf("%d%d", &n, &k);
	k++;
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	for(int i = 1; i < n; i++)
		a[i] += a[i - 1];
		
	ll ans = -INF;
	ll x = 0;
	for(int i = 0; i < n; i += k){
		for(int j = 0; i + j < n &&  j < k; j++)
			f[i + j] = x + get(i + j + 1, n - 1);
		x += get(i + k, n - 1);
	}
	for(int i = n - 1; i >= 0; i--)
		g[i] = g[i + 1] + get(i + 1, n - 1);
	for(int i = 0; i < n; i++)
		ans = max(ans, f[i] + g[i + 1]);
	
	printf("%lld", ans);
}