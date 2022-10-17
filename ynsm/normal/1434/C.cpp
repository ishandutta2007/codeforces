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
 
/*
cnt 
h = cnt * a - tick * b
tick =  cnt * c - (c, c - d, c - 2d .. c - id) (0 <= i < (cnt, c / d)
c - i * d >= 0
c > i * d
c / d > i
i < c / d

tick = cnt* c - ( c * x - x * (x - 1) / 2 * d )
tick = cnt * c - cx + x(x-1)/2*d 
h = cnt * a - cnt * c + c * x - x * (x - 1) / 2 * d;

h = cnt * a - cnt * (cnt - 1) / 2 * d
cnt >= x
h = cnt * a - cnt 


x * a - x * (x - 1) / 2 * d -> max


2xa - xxd + xd
-xxd + x(2a+d)
-2xd +2a + d
x = (2a+d)/2d
x (2 * a - (x - 1) * d)

*/
void solve(){
	ll a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	ll x = (c + d - 1) / d;
	if(a - c * b > 0)
		printf("-1\n");
	if(a - c * b == 0)	
		printf("%lld\n", x * c * b - x * (x - 1) / 2 * d * b);
	if(a - c * b < 0){
		ll y = (a + a + d * b) / (d * b + d * b);	
		y = min(y, x);
		ll ans = 0;
		//cerr << y << " " << x << endl;
		for(ll i = max(0ll, y - 100); i <= min(x, y + 100); i++){
			ans = max(ans, i * a - i * (i - 1) / 2 * d * b); 	
			//cerr << i << " " << ans << endl;
		}
		printf("%lld\n", ans);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}