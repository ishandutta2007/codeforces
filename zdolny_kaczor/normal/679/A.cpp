# include <cstdio>
bool div(int x) {
	printf("%d\n", x);
	fflush(stdout);
	char ans[10];
	scanf("%s", ans);
	return ans[0] == 'y';
}
bool isprime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int primes[4] = {2, 3, 5, 7};
int main() {
	for (int p : primes) {
		if (div(p)) {
			for (int x = 2; x * p <= 100; ++x) {
				if (isprime(x) && div(x * p)) {
					printf("composite\n");
					return 0;
				}
			}
			printf("prime\n");
			return 0;
		}
	}
	printf("prime\n");
}