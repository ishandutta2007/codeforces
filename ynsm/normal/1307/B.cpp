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
 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n, d, x, ans = inf;
		scanf("%d%d", &n, &d);
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			if(x > d)
				ans = min(ans, 2);
			else
				ans = min(ans, (d + x - 1) / x);
		}
		printf("%d\n", ans);
	}
}