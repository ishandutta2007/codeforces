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
ll a[N];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	if(n == 1){
		printf("1 1\n0\n");
	}else{
		printf("%d %d\n", 2, n);
		for(int i = 1; i < n; i++)
			printf("%lld ", a[i] % n * (n - 1));
		printf("\n");
	}
	printf("%d %d\n", 1, 1);
	printf("%lld\n", -a[0]);
	printf("%d %d\n", 1, n);
	printf("0 ");
	for(int i = 1; i < n; i++)
		printf("%lld ", - a[i] - a[i] % n * (n - 1));	
}