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
 
int n;
ll w;
pii a[N];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &w);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i].f);
			a[i].s = i;
		}
		sort(a, a + n);
		ll s = 0;
		for(int i = 0; i < n; i++){
			s += a[i].f;
			if((w + 1) / 2 <= a[i].f && a[i].f <= w){
				printf("%d\n%d\n", 1, a[i].s + 1);
				break;
			}
			if((w + 1) / 2 <= s && s <= w){
				printf("%d\n", i + 1);
				for(int j = 0; j <= i; j++)
			    	printf("%d ", a[j].s + 1);
				printf("\n");
				break;
			}
			if(i == n - 1){
				printf("-1\n");
			}
		}
	}
}