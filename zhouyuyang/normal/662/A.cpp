#include <cstdio>
#include <algorithm>
int N,D;
long long A,a[500000];
using namespace std;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		long long x, y;
		scanf("%lld%lld", &x, &y);
		a[i] = x ^ y;
		A ^= x;
	}
	for (int i = 59; ~i; i--){
		int f = find_if(a, a + N, [i] (long long x) { return x >> i & 1; }) - a;
		if (f == N)
			continue;
		D++;
		long long w = a[f];
		if (A >> i & 1)
			A ^= w;
		for (int j = 0; j < N; j++)
			if (a[j] >> i & 1)
				a[j] ^= w;
	}
	if (A)
		puts("1/1");
	else
		printf("%lld/%lld\n", (1LL << D) - 1, 1LL << D);
	return 0;
}