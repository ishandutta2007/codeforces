#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n, a[MAXN];

long long calc(long long d){
	long long ret = 0, r = 0;
	
	for(int i = 0; i < n; i++){
		int ai = a[i] % d;
		
		r += ai;
		if(r >= d)r -= d;
		
		if(r * 2 < d)ret += r;
		else ret += d - r;
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	
	long long sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	long long res = -1;
	
	for(long long d = 2; d * d <= sum; d++){
		if(sum % d == 0){
			while(sum % d == 0)sum /= d;
			
			long long cur = calc(d);
			if(res == -1 || cur < res)res = cur;
		}
	}
	
	if(sum > 1){
		long long cur = calc(sum);
		if(res == -1 || cur < res)res = cur;
	}
	
	printf("%lld\n", res);
	
	return 0;
}