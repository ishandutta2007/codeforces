#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const int INF = 1000000005;

int n, k, c[MAXN];
int main(){
	scanf("%d %d", &n, &k);

	long long s = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
		s += c[i];
	}

	int L = (s + n - 1) / n, R = INF;
	while(L < R){
		int mid = (L + R) / 2;

		long long e = 0;
		for(int i = 0; i < n; i++)
			if(c[i] > mid)e += c[i] - mid;

		if(e <= k)R = mid;
		else L = mid + 1;
	}
	int y = L;

	L = 0, R = s / n;
	while(L < R){
		int mid = (L + R + 1) / 2;

		long long e = 0;
		for(int i = 0; i < n; i++)
			if(c[i] < mid)e += mid - c[i];

		if(e <= k)L = mid;
		else R = mid - 1;
	}
	int x = L;

	printf("%d\n", y - x);

	return 0;
}