#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	ll n, k;
	string s, t;
	ll ans = 0;	
	cin >> n >> k;
	cin >> s;
	cin >> t;
	ll cur = 0;
	ll len = 0;
	for(int j = 0; j < n; j++){
		len <<= 1;
		if(s[j] == 'b')
			len--;
		if(t[j] == 'b')
			len++;
		ll cnt = min(k, len + 1 - cur);
		ans += cnt * (n - j);
		k -= cnt;
		cur += cnt;
		if(k == 0)
			break;
	}
	cout << ans;
	return 0;
}