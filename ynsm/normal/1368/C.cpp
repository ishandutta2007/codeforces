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
	int n;
	scanf("%d", &n);
	n += 1;
	int x = 0;
	printf("%d\n", n * 7 + 1);
	while(n--){                 
		printf("%d %d\n", x, x);    
		printf("%d %d\n", x + 1, x);
		printf("%d %d\n", x + 2, x);
		printf("%d %d\n", x, x + 1);
		printf("%d %d\n", x, x + 2);
		printf("%d %d\n", x + 1, x + 2);
		printf("%d %d\n", x + 2, x + 1);
		if(n == 0)
        	printf("%d %d\n", x + 2, x + 2);
		x += 2;
	}
}