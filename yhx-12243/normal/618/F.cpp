#include <bits/stdc++.h>
#define N 1024404
using namespace std;

typedef long long ll;

int n, t, i, j;
int pos[N], gz[N];
ll __scx_t[2][N], *a = __scx_t[0], *b = __scx_t[1];

inline void out(int l, int r) {for(printf("%d\n", r - l); ++l <= r; printf("%d%c", l, l == r ? 10 : 32));} // (l, r]
	
int main(){
	bool swapped = false;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {scanf("%d", &t); a[i] = a[i - 1] + t;}
	for(i = 1; i <= n; ++i) {scanf("%d", &t); b[i] = b[i - 1] + t;}
	if(a[n] > b[n]) {swap(a, b); swapped = true;}
	memset(gz, -1, sizeof gz);
	gz[0] = pos[0] = j = 0;
	for(i = 1; i <= n; ++i){
		for(; j <= n && b[j] <= a[i]; ++j); --j;
		pos[i] = j; t = a[i] - b[j];
		if(~gz[t]){
			swapped ? void(0) : out(gz[t], i);
			out(pos[gz[t]], pos[i]);
			swapped ? out(gz[t], i) : void(0);
			return 0;
		}
		else gz[t] = i;
	}
	return putchar(45) & putchar(49);
}