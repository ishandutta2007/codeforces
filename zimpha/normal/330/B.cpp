#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN=1005;

bool used[MAXN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	memset(used, 0, sizeof(used));
	for (int a, b, i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		used[a]=used[b]=true;
	}
	for (int i=1; i<=n; i++)
		if (!used[i]) {
			printf("%d\n", n-1);
			for (int j=1; j<=n; j++) 
				if (i!=j) printf("%d %d\n", i, j);
			break;
		}
	return 0;
}