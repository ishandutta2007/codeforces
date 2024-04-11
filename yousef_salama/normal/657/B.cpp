#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, k, a[MAXN], b[MAXN];
int main(){
	scanf("%d %d", &n, &k);
	n++;

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	for(int i = 0; i < n - 1; i++){
		if(a[i] > 0){
			a[i + 1] += a[i] / 2;
			a[i] %= 2;
		}else if(a[i] < 0){
			a[i + 1] += (a[i] - 1) / 2;
			a[i] = -a[i] % 2;
		}
	}

	int s = 0;
	while(a[s] == 0)s++;

	long long x = 0;
	int res = 0;

	for(int i = n - 1; i >= 0; i--){
		x += a[i];

		if(i <= s){
			if(i == n - 1){
				if(llabs(-x + b[i]) <= k && -x + b[i] != 0)res++;
			}else if(llabs(-x + b[i]) <= k)res++;
		}

		if(llabs(x) >= 1LL << 50)break;

		x *= 2;
	}
	printf("%d\n", res);

	return 0;
}