#include <cstdio>
#include <cstdlib>

const int N = 400005;
int n, k;
char str[N];
int sum[N];

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		sum[str[i]]++;
	}
	
	char cur = ' ';
	for (char c = 'a'; c <= 'z'; c++) {
		if (sum[c] <= k) {
			k -= sum[c];
		} else {
			cur = c;
			break;
		}
	}
	
	if (cur == ' ') {
		return 0;
	} else {
		for (int i = 1; i <= n; i++) {
			if (str[i] > cur) {
				printf("%c", str[i]);
			} else if (str[i] == cur) {
				if (k == 0) {
					printf("%c", cur);
				} else {
					k--;
				}
			}
		}
	}
	
	return 0;
}