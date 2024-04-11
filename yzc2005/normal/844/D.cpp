#include <bits/stdc++.h>
using namespace std;
 
const int N = 50005;
int n, s, x, a[N];
 
int main() {
	srand(time(NULL));
	scanf("%d%d%d", &n, &s, &x);
	for(int i = 1; i <= 666; ++i) {
		printf("? %d\n", s), fflush(stdout);
		int val; scanf("%d%d", &val, &s);
		if(val >= x) printf("! %d\n", val), fflush(stdout), exit(0);
		if(s == -1) puts("! -1"), fflush(stdout), exit(0);
	}
	for(int i = 1; i <= n; ++i) a[i] = i;
	random_shuffle(a + 1, a + n + 1);
	int mx = 0;
	for(int i = 1; i <= 666; ++i) {
		printf("? %d\n", a[i]), fflush(stdout);
		int val, nxt; scanf("%d%d", &val, &nxt);
		if(val >= x) continue;
		if(val > mx) mx = val, s = nxt;
	}
	for(int i = 1; i < 668; ++i) {		
		if(s == -1) puts("! -1"), fflush(stdout), exit(0);
		printf("? %d\n", s), fflush(stdout);
		int val; scanf("%d%d", &val, &s);
		if(val >= x) printf("! %d\n", val), fflush(stdout), exit(0);
	}
}