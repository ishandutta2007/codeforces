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
 
ll k, p[N], mx[5010], pre[5010][700], cnt[5010][700], dist[5010][5010];
int n, a[N];
int main()
{
	for(int i = 2; i <= 5000; i++){
		bool ok = 1;
		for(int j = 2; j < i; j++)
			if(i % j == 0)
				ok = 0;
		if(ok){
			p[k++] = i;
		}
	}
	for(int i = 1; i <= 5000; i++){
		int x = i;
		for(int j = 0; j < k; j++){
			cnt[i][j] = cnt[i - 1][j];
			while(x % p[j] == 0){
				x /= p[j];
				cnt[i][j]++;
				mx[i] = max(mx[i], (ll)j);
			}
		}			
	}
	for(int i = 1; i <= 5000; i++){
		for(int j = 0; j < k; j++){
			if(j)
				pre[i][j] = pre[i][j - 1];
			pre[i][j] += cnt[i][j];
		}
	}
	for(int i = 1; i <= 5000; i++){
	    ll lim = 0;
		for(int j = i + 1; j <= 5000; j++){
			lim = max(lim, mx[j]);
			if(lim != 0)
				dist[i][j] += pre[i][lim - 1] + pre[j][lim - 1];
			dist[i][j] += cnt[j][lim] - cnt[i][lim];
	    	dist[j][i] = dist[i][j];
		}
	}
	int n;
	scanf("%d", &n);
	while(n--){
		int x;
		scanf("%d", &x);
		if(x == 0)
			x = 1;
		a[x]++;
	}
	ll ans = 1e18;
	for(int i = 1; i <= 5000; i++){
		ll cur = 0;
		for(int j = 1; j <= 5000; j++)
			cur += dist[i][j] * a[j];
		ans = min(ans, cur);
	}
	printf("%lld", ans);
}