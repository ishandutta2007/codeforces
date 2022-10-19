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
		ll k;
		scanf("%d%lld", &n, &k);
		int mn = inf;
		int mx = -inf;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			mn = min(mn, a[i]);
			mx = max(mx, a[i]);
		}
		if(k & 1)
			for(int i = 0; i < n; i++)
				printf("%d ", mx - a[i]);
    	else
    		for(int i = 0; i < n; i++)
				printf("%d ", a[i] - mn);
    	printf("\n");	
    }
}