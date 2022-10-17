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
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, mx = 0, mn = inf;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			mx = max(mx, x);
			mn = min(mn, x);
		}
		if(mn == mx)          
			printf("%d\n", n);
		else
			printf("%d\n", 1);
	}	
}