#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int ans1, ans2, in, now;
char str[100005];

void update(int now, int in) {
	if (in) {
		if (now != 0) {
			ans2++;
		}
	} else {
		if (now > ans1) {
			ans1 = now;
		}
	}
}

int n;

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	scanf("%s", str + 1);
	in = 0;
	now = 0;
	for (int i = 1; i <= n; i++) {
		//printf("%d %d %d\n", i, ans1, ans2);
		if (str[i] == '(') {
			update(now, in);
			in = 1 - in;
			now = 0;
		} else if (str[i] == ')') {
			update(now, in);
			in = 1 - in;
			now = 0;
		} else if (str[i] == '_') {
			update(now, in);
			now = 0;
		} else {
			now++;
		}
	}
	
	update(now, in);
	printf("%d %d\n", ans1, ans2);
	return 0;
}