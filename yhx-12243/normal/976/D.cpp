#include <bits/stdc++.h>
#define N 1005
#define E 1000005
using namespace std;

int n, V, offset;
int d[N];
int u[E], v[E], cnt = 0;

inline void print(int u, int v) {::u[++cnt] = u + offset; ::v[cnt] = v + offset;}

int main(){
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", d + i);
	V = d[n] + 1;
	for (offset = 1; ; ++offset) {
		if (!d[1]) {
			offset = V - d[n];
			for (i = 1; i < n; ++i) d[i] = d[i + 1];
			d[n--] = 0;
		}
		if (n <= 1) {
			for (i = 0; i < d[1]; ++i)
				for (j = i + 1; j <= d[1]; ++j)
					print(i, j);
			break;
		}
		for (i = 1; i <= d[n]; ++i) print(0, i);
		for (i = 1; i <= n; ++i) --d[i];
		if (!d[1]) {
			d[n--] = 0; if(n <= 1) break;
		}
	}
	printf("%d\n", cnt);
	for (i = 1; i <= cnt; ++i)
		printf("%d %d\n", u[i], v[i]);
	return 0;
}