#include <cstdio>
#include <cassert>
#include <cstdlib>
using namespace std;

const int N = 100;

int A[N];
int was[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		bool bad = false;
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[j]);
			if (was[A[j]] == i)
				bad = true;
			was[A[j]] = i;
		}
		if (!bad) {
			for (int j = 0; j < n; j++)
				printf("%d%c", (A[j] == 0) ? n : A[j], " \n"[j + 1 == n]);
			return 0;
		}
	}
	assert(false);
}