#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, k;
		scanf("%d %d", &n, &k);
		
		vector <int> a(n), b(k), ind(n);
		vector <bool> stars(n, true);
		
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			a[i]--;
			
			ind[a[i]] = i;
		}
		
		for(int i = 0; i < k; i++){
			scanf("%d", &b[i]);
			b[i]--;
			stars[ind[b[i]]] = false;
		}
		
		long long res = 1;
		for(int i = 0; i < k; i++){
			int j = ind[b[i]];
			
			int cur = 0;
			if(j > 0 && stars[j - 1])cur++;
			if(j + 1 < n && stars[j + 1])cur++;
			
			if(cur == 0){
				res = 0;
				break;
			}
			
			res = res * cur % MOD;
			stars[j] = true;
		}
		printf("%lld\n", res);
	}
	return 0;
}