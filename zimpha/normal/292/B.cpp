#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MAXN=100000+10;

int deg[MAXN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	memset(deg, 0, sizeof(deg));
	for (int x, y, i=0; i<m; i++) {
		scanf("%d%d", &x, &y);
		deg[x]++, deg[y]++;
	}
	if (n==m) {
		bool flag=true;
		for (int i=1; flag&&i<=n; i++)
			if (deg[i]!=2) flag=false;
		if (flag) puts("ring topology");
		else puts("unknown topology");
	}
	else if (m==n-1) {
		int cnt1=0, cnt2=0;
		for (int i=1; i<=n; i++) {
			if (deg[i]==1) cnt1++;
			if (deg[i]==2) cnt2++;
		}
		if (cnt1==n-1) puts("star topology");
		else if (cnt1==2&&cnt2==n-2) puts("bus topology");
		else puts("unknown topology");
	}
	else puts("unknown topology");
	return 0;
}