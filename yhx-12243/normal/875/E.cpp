#include <bits/stdc++.h>
#define N 100034
using namespace std;

int A, B, n, i;
int L, R, M;
int a[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

bool test(int x){
	int l = a[n] - x, r = a[n] + x;
	for(i = n - 1; i && l <= r; --i)
		if(l <= a[i] && a[i] <= r) {l = a[i] - x; r = a[i] + x;}
		else {up(l, a[i] - x); down(r, a[i] + x);}
	return (l <= A && A <= r) || (l <= B && B <= r);
}

int main(){
	scanf("%d%d%d", &n, &A, &B); up(R = A, B); down(L = A, B);
	for(i = 1; i <= n; ++i){
		scanf("%d", a + i); up(R, a[i]); down(L, a[i]);
	}
	for(R -= L, L = abs(A - B); L < R; )
		test(M = L + R >> 1) ? R = M : (L = M + 1);
	printf("%d\n", R);
	return 0;
}