# include <bits/stdc++.h>
using namespace std;
map <int, int> a;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n;++i) {
		int x;
		scanf("%d", &x);
		a[x]++;
		while (a[x] == 2) {
			a[x] -= 2;
			x++;
			a[x]++;
		}
	}
	int sum = 0, M = 0;
	for (auto x : a) {
		sum += x.second;
		M = max(M, x.first);
	}
	printf("%d\n", M - sum + 1);
}