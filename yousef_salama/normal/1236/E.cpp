#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int SHIFT = 100005;

int n, m, a[MAXN], b[2 * MAXN];
long long calc(){
	memset(b, 0, sizeof b);
	
	int st = SHIFT;
	for(int i = 0; i < n; i++)
		b[st + i] = 1;
		
	for(int i = 0; i < m; i++){
		st--;
		
		if(a[i] > 0){
			b[st + a[i] - 1] += b[st + a[i]];
			b[st + a[i]] = 0;
		}
	}
	st--;
	
	long long ret = 0;
	for(int i = 0; i < n + m + 1; i++)
		ret += 1LL * min(i, n - 1) * b[st + i];
	return ret;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	
	if(n == 1){
		printf("0\n");
		return 0;
	}
	
	long long res = 0;
	res += calc();
	
	for(int i = 0; i < m; i++)
		a[i] = n - a[i] - 1;
	res += calc();
	res -= 1LL * n * (n - 1);
	res += n;
	
	printf("%lld\n", res);
	
	return 0;
}