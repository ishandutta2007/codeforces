#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

const int N = 1000100;

int n;
ll a[N], k;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		k += a[i];
	}
	k -= 1ll * (n - 1) * n / 2;
	if(k % n == 0)
		for(int i = 0; i < n; i++)
			printf("%lld ", k / n + i); 
	else
		for(int i = 0, j = 0; i < n; i++){
			if(i != k % n)
				j++;
			printf("%lld ", k / n + j);
		} 
	
}