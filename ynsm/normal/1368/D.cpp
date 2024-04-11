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
ll ans = 0;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		for(int j = 0; j < 20; j++)
			if((x >> j) & 1)
				a[j]++;
	}
	for(int i = 0; i < n; i++){
		int x = 0;
		for(int j = 0; j < 20; j++)
			if(a[j])
				a[j]--, x += (1 << j);
		ans += 1ll * x * x;
	}
	printf("%lld", ans);
}