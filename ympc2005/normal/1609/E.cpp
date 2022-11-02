#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, q, f[N<<2][3][3];

char s[N], t[N];

void up_(int o) {
	int lc = o<<1, rc = o<<1|1;
	memset(f[o], 0x3f, sizeof(f[o]));
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; i + j < 3; j++) {
			for (int k = 0; k <= j; k++) {
				f[o][i][j] = min(f[o][i][j], f[lc][i][k] + f[rc][i + k][j - k]);
			}
		}
	}
}

void build_(int o, int l, int r) {
	if (l == r) {
		f[o][s[l] - 'a'][0] = 1;
		return;
	}
	
	int mid = (l + r)>>1;
	
	build_(o<<1, l, mid);
	build_(o<<1|1, mid + 1, r);
	
	up_(o);
}

void upd_(int o, int l, int r, int x, int k) {
	if (l == r) {
		memset(f[o], 0, sizeof(f[o]));
		f[o][k][0] = 1;
		return;
	}
	
	int mid = (l + r)>>1;
	
	if (x <= mid) {
		upd_(o<<1, l, mid, x, k);
	} else {
		upd_(o<<1|1, mid + 1, r, x, k);
	}
	
	up_(o);
}

int main() {
	scanf("%d%d%s", &n, &q, s + 1);
	
	build_(1, 1, n);
	
	for (int x, i = 1; i <= q; i++) {
		scanf("%d%s", &x, t + 1);
		upd_(1, 1, n, x, t[1] - 'a');
		printf("%d\n", min(f[1][0][0], min(f[1][0][1], f[1][0][2]))); 
	}
}