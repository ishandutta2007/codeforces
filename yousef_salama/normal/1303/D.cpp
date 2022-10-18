#include <bits/stdc++.h>
using namespace std;

const int MAXM = 100005;
const int MAXL = 65;

int t, m, a[MAXM];
long long n, c[MAXL];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld %d", &n, &m);
		
		memset(c, 0, sizeof c);
		for(int i = 0; i < m; i++){
			scanf("%d", &a[i]);
			
			int d = 0;
			while(a[i] > 1){
				a[i] >>= 1;
				d++;
			}
			c[d]++;
		}
		
		long long res = 0;
		bool ok = true;
		
		for(int i = 0; i < 60; i++){
			if(n & (1LL << i)){
				if(c[i] == 0){
					bool found = false;
					for(int j = i + 1; j < 60; j++)if(c[j] > 0){
						while(j > i){
							c[j]--;
							c[j - 1] += 2;
							res++;
							j--;
						}
						
						found = true;
						break;
					}
					
					if(!found){
						ok = false;
						break;
					}
				}
				
				c[i]--;
			}
			c[i + 1] += c[i] >> 1;
		}
		
		
		if(!ok)printf("-1\n");
		else printf("%lld\n", res);
	}
	return 0;
}