#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int t, n, a[MAXN];
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		long long x = 0, s = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			
			s += a[i];
			x ^= a[i];
		}
		
		printf("3\n");
		
		long long r1 = (1LL << 40) + s;
		printf("%lld", r1);
		
		s += r1;
		x ^= r1;
		
		x <<= 1;
		
		printf(" %lld %lld\n", (x - s) >> 1, (x - s) >> 1);
	}
	return 0;
}