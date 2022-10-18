#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n;
long long r1, r2, r3, d, a[MAXN], a1[MAXN], a2[MAXN];

int main(){
	scanf("%d %lld %lld %lld %lld", &n, &r1, &r2, &r3, &d);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		
		a1[i] = r1 * a[i] + r3;
		a2[i] = min(a1[i], min(r2 + r1, r1 * (a[i] + 2)));
	}
		
	long long sum1 = 0, sum2 = 0, sum3 = 0;
	for(int i = 0; i < n; i++){
		if(i == 0){
			sum1 = a1[i] + d;
			sum2 = a2[i] + 2 * d;
			sum3 = a2[i] + 3 * d;
		}else if(i == n - 1){
			printf("%lld\n", min(min(sum1, sum2) + a1[i], sum3 + a2[i]));
		}else{
			long long _sum1, _sum2, _sum3;
			_sum1 = min(sum1 + a1[i] + d, sum3 + a2[i] + d);
			_sum2 = min(sum2, min(sum3, sum1)) + a2[i] + 2 * d;
			_sum3 = min(sum1, sum3) + a2[i] + 3 * d;
			
			sum1 = _sum1;
			sum2 = _sum2;
			sum3 = _sum3;
		}
	}
	
	return 0;
}