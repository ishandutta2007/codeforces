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
		int a, b, n, c = 0;
		scanf("%d%d%d", &a, &b, &n);
		while(max(a, b) <= n){
			if(a > b)
				b += a;		
			else
				a += b;
			c++;
		}
		printf("%d\n", c);
	}	
}