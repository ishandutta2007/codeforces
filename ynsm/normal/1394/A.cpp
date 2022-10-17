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
 
int n, d, m;
ll ans, sum;
vector< int > a, b;
int main()
{
	scanf("%d%d%d", &n, &d, &m);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(x <= m)
			a.pb(x);
		else
			b.pb(x);
	}                        
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int i = 0; i < a.size(); i++)
		sum += a[i];
	ans = max(ans, sum);
    for(int i = 0, j = a.size(); i < b.size(); i++){
		if(1ll * i * (d + 1) + 1 > n)
			continue;
		sum += b[i];
		int mx = n - i * (d + 1) - 1;
		while(j > 0 && j > mx)
			sum -= a[--j];
		ans = max(ans, sum);
    }
    printf("%lld", ans);
}