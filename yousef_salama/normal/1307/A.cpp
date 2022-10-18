#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int t, n, d, a[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &d);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
			
		long long r = 0;
		for(int i = 0; i < n; i++){
			if(a[i] * i <= d){
				d -= a[i] * i;
				r += a[i];
			}else{
				r += d / i;
				break;
			}
		}
		printf("%lld\n", r);
	}
	
	return 0;
}