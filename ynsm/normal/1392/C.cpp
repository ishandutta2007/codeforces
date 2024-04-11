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
 

int n, a[N];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll ans = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			if(i)
				ans += max(0, a[i - 1] - a[i]);
		}
		printf("%lld\n", ans);
	}
}