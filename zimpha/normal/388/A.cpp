#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 110;

bool vis[MAXN];
int a[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	sort(a, a + n);
	int ret = 0, cnt = n;
	memset(vis, 0 , sizeof(vis));
	while (cnt) {
		for (int size = 0; ; ++ size) {
			bool find = false;
			for (int i = 0; i < n; ++ i) {
				if (!vis[i] && a[i] >= size) {
					vis[i] = 1; cnt --;
					find = true;
					break;
				}
			}
			if (!find) {
				ret ++;
				break;
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}