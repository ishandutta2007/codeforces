#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const int MAXM = 1000005;
const int MAXK = 2000015;

int n, x, y, a[MAXN], b[MAXK];
long long sum[MAXK], sumi[MAXK];

int main(){
	scanf("%d %d %d", &n, &x, &y);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	
	for(int i = 1; i < MAXK; i++){
		sum[i] = b[i] + sum[i - 1];
		sumi[i] = 1LL * (MAXK - i) * b[i] + sumi[i - 1];
	}
	
	long long res = 1LL << 60;
	for(int g = 2; g < MAXM; g++){
		long long cur = 0;
		bool ok = false;
		
		for(int d = g; d - g < MAXM; d += g){
			int z = x / y;
			
			cur += 1LL * y * (sumi[d] - sumi[d - min(z + 1, g)] - 1LL * (MAXK - d) * (sum[d] - sum[d - min(z + 1, g)]));			
			cur += 1LL * x * (sum[d - min(z + 1, g)] - sum[d - g]);
		}
		res = min(res, cur);
	}
	printf("%I64d\n", res);
	
	return 0;
}