#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, a[N];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		bool ok = 1;
		int x = inf, y = 0;
		for(int i = 0; i < n; i++){
			if(y > a[i]){
				ok = 0;
				break;
			}
			x = min(x, a[i] - y);
			y = a[i] - x;
		}
		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
}