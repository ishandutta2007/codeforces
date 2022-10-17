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
 
int n, a[N], ans = inf;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i + 2 < n; i++){
		if((a[i] ^ a[i + 1]) > a[i + 2]){
			printf("1");
			return 0;
		}
		if(a[i] > (a[i + 1] ^ a[i + 2])){
			printf("1");
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
	    int x = 0;
		for(int j = i - 1; j >= 0; j--){
			x ^= a[j];
			int y = 0;
			for(int q = i; q < n; q++){
				y ^= a[q];
				if(x > y)
					ans = min(ans, (i - j - 1) + (q - i)); 	
			}
		}
	}
	if(ans == inf)
		ans = -1;
	printf("%d", ans);
}