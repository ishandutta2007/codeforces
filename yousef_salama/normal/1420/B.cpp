#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		map <int, int> mp;
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			
			mp[__builtin_clz(a)]++;
		}
		
		long long res = 0;
		for(auto p : mp)
			res += 1LL * p.second * (p.second - 1) / 2;
		printf("%lld\n", res);
	}
	return 0;
}