#include <cstdio>
#include <cstring>

const int MAXN=210;

int x[MAXN], y[MAXN];
int n;

bool up(int xx, int yy) {
	for (int i=0; i<n; i++) {
		if (xx==x[i] && y[i]>yy) return true;
	}
	return false;
}

bool down(int xx, int yy) {
	for (int i=0; i<n; i++) {
		if (xx==x[i] && y[i]<yy) return true;
	}
	return false;
}

bool left(int xx, int yy) {
	for (int i=0; i<n; i++) {
		if (xx>x[i] && y[i]==yy) return true;
	}
	return false;
}

bool right(int xx, int yy) {
	for (int i=0; i<n; i++) {
		if (xx<x[i] && y[i]==yy) return true;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d%d", x+i, y+i);
	}
	int ret=0;
	for (int i=0; i<n; i++) {
		if (up(x[i], y[i]) && down(x[i], y[i]) && left(x[i], y[i]) && right(x[i], y[i])) {
			ret++;
		}
	}
	printf("%d\n", ret);
	return 0;
}