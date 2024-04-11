#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for(int j = 0; j < 30; j++){
		int c = 0;
		for(int i = 0; i < n; i++)
			if(a[i] & (1 << j))c++;
		
		for(int i = 0; i < n; i++){
			if(i < c)a[i] |= 1 << j;
			else a[i] &= ~(1 << j);
		}
	}
	
	long long res = 0;
	for(int i = 0; i < n; i++)
		res += 1LL * a[i] * a[i];
	printf("%lld\n", res);
	
	return 0;
}