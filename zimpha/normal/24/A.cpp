#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN=100+10;

bool left[MAXN], right[MAXN];
int n;

int main() {
	scanf("%d", &n);
	memset(left, 0, sizeof(left));
	memset(right, 0, sizeof(right));
	int sum=0, ret=0;
	for (int a, b, c, i=0; i<n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		sum+=c;
		if (!left[a]) {
			if (right[b]) ret+=c, left[b]=true, right[a]=true;
			else left[a]=true, right[b]=true;
		}
		else {
			if (!left[b]) left[b]=true, right[a]=true, ret+=c;
		}
	}
	if (ret<sum-ret) printf("%d\n", ret);
	else printf("%d\n", sum-ret);
	return 0;
}