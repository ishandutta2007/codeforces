#include <bits/stdc++.h>
using namespace std;

int t, n, x, a, b;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &n, &x, &a, &b);
		
		printf("%d\n", min(n - 1, abs(a - b) + x));
	}
	return 0;
}