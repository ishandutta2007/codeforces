#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

char str[16];
int n, h, m;

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	scanf("%s", str + 1);
	int h = (str[1] - '0') * 10 + (str[2] - '0');
	int m = (str[4] - '0') * 10 + (str[5] - '0');
	if (m > 59) {
		m = m - 60;
	}

	if (n == 12) {
		if (h < 1 || h > 12) {
			if (h % 10 == 0) {
				h = 10;
			} else {
				h = h % 10;
			}
		}
	} else {
		if (h > 23) {
			h %= 20;
		}
	}
	
	printf("%02d:%02d\n", h, m);
	return 0;
}