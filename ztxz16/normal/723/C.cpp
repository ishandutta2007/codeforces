#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 2005;
 
int n, m, others, ans, ans2;
int a[N], s[N];

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] <= m) {
			s[a[i]]++;
		} else {
			others++;
		}
	}
	
	for (int i = 0; i <= n; i++) {
		int canChange = others, need = 0;
		for (int j = 1; j <= m; j++) {
			if (s[j] < i) {
				need += (i - s[j]);
			} else {
				canChange += (s[j] - i);
			}
		}
		
		if (canChange >= need) {
			ans = i;
		} else {
			break;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i] > m || s[a[i]] > ans) {
			int after = 0;
			for (int j = 1; j <= m; j++) {
				if (s[j] < ans) {
					after = j;
				}
			}
			
			if (after == 0) {
				break;
			}
			
			s[after]++;
			if (a[i] <= m) {
				s[a[i]]--;
			}
			
			a[i] = after;
			ans2++;
		}
	}
	
	printf("%d %d\n", ans, ans2);
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}