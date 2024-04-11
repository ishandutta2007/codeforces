#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n;
long long a[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	if(n == 1){
		printf("1 1\n%lld\n", -a[0]);
		printf("1 1\n0\n");
		printf("1 1\n0\n");
		return 0;
	}
		
	printf("1 1\n%lld\n", -a[0]);
	
	printf("2 %d\n", n);
	for(int i = 1; i < n; i++){
		long long x = (a[i] + 1000000000LL * n) % n;
		
		if(i > 1)printf(" ");
		printf("%lld", x * (n - 1));
		
		a[i] += x * (n - 1);
	}
	printf("\n");
	
	printf("1 %d\n", n);
	for(int i = 0; i < n; i++){
		if(i == 0)printf("0");
		else printf(" %lld", -a[i]);
	}
	printf("\n");
	
	return 0;
}