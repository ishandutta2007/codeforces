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
 
const ll K = 2e16;

ll x[N], y[N], ax, ay, bx, by, t;
ll ans, n;
ll f(int i, int j){
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
int main()
{
	cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
	n = 1;
	while(true){
		if(x[n - 1] * ax + bx > K)
			break;
		if(y[n - 1] * ay + by > K)
			break;                
		x[n] = x[n - 1] * ax + bx;
		y[n] = y[n - 1] * ay + by;				
		n++;
	}
	cin >> x[n] >> y[n] >> t;
	for(int i = 0; i < n; i++){
		ll cur = 0;
		for(int j = i; j < n; j++){
			if(j != i)
				cur += f(j , j - 1);
			if(cur + min(f(n, i), f(n, j)) <= t)
				ans = max(ans, j - i + 1ll);
		}	
	}
	cout << ans;
}