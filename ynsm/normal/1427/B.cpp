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
 
int n, k;
char s[N];
void solve(){
	scanf("%d%d", &n, &k);
	scanf("%s", &s);
	vector< int > v;
	int ans = 0;
	for(int i = 0, j = 0; i < n; i = j){
		while(j < n && s[i] == s[j])
			j++;
		if(s[i] == 'L'){
			if(i == 0 || j == n)
				continue;
			v.pb(j - i);
		}else{
			ans += j - i + j - i - 1;
		}
	}
	sort(v.begin(), v.end());
	for(auto x : v){
		if(x <= k){
			k -= x;
			ans += 2 * x;
			ans++;
		}
	}
	if(ans == 0 && k > 0)
		ans--;
	ans += 2 * k;
	ans = min(ans, n + n - 1);
	printf("%d\n", ans);
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}