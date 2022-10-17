#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 1000123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n;
ll r1, r2, r3, d, x, y, z, xx, yy, zz, a, b;
int main()
{
	scanf("%d", &n);
	scanf("%lld%lld%lld", &r1, &r2, &r3);
	scanf("%lld", &d);
	x = 0, y = INF, zz = 0;
	for(int i = 0; i < n; i++){
		ll v;
		scanf("%lld", &v);
		a = min(r1, r3) * v + r3;
		b = min(r2, min(r1, r3) * v + r1) + min(min(r1, r2), r3);
		b = min(b, a);     
		xx = min(x + a, y + b) + (i < n - 1) * d;    
    	yy = min(x + b + (i == n - 1) * 2 * d, y + b) + (i < n - 1) * 3 * d;
		zz = min(x + (i == n - 1) * 2 * d, z) + min(b + (i == n - 1) * 2 * d, a) + (i < n - 1) * 2 * d;  
		x = xx, y = yy, z = zz;
	}
	printf("%lld", min(min(x, y), z));
}