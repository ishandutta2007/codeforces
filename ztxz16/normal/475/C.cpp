#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

const int N = 1005;
const int INF = 1000000000;

char str[N][N];

int n, m, l[N], r[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str[i] + 1);
	}
	
	for (int i = 1; i <= n; i++) {
		int ll = m + 1, rr = 0;
		for (int j = 1; j <= m; j++) {
			if (str[i][j] == 'X') {
				ll = j;
				break;
			}
		}
		
		for (int j = m; j >= 1; j--) {
			if (str[i][j] == 'X') {
				rr = j;
				break;
			}
		}
		
		for (int j = ll; j <= rr; j++) {
			if (str[i][j] != 'X') {
				printf("-1\n");
				return 0;
			}
		}
		
		l[i] = ll, r[i] = rr;
	}
	
	int st, end;
	for (int i = 1; i <= n; i++) {
		if (l[i] != m + 1) {
			st = i;
			break;
		}
	}
	
	for (int i = n; i >= 1; i--) {
		if (l[i] != m + 1) {
			end = i;
			break;
		}
	}
	
	for (int i = st; i <= end; i++) {
		if (l[i] == m + 1) {
			printf("-1\n");
			return 0;
		}
	}
	
	int ans1 = -1, ans2 = -1, flag = 0;
	for (int i = st + 1; i <= end; i++) {
		if (l[i] < l[i - 1] || r[i] < r[i - 1]) {
			printf("-1\n");
			return 0;
		}
		
		if (l[i] > r[i - 1]) {
			printf("-1\n");
			return 0;
		}
		
		if (r[i] > r[i - 1]) {
			flag = 1;
		}
		
		if (l[i] > l[i - 1] && ans1 == -1) {
			int last;
			for (last = i - 1; last >= st; last--) {
				if (r[last] != r[i]) {
					break;
				}
			}
			
			if (last < st) {
				last++;
			}
			
			ans1 = r[last] - l[i] + 1;
		}
	}
	
	int ans = INF;
	if (ans1 == -1) {
		if (st == end) {
			printf("1\n");
			return 0;
		} else {
			if (flag) {
				ans1 = r[st] - l[st] + 1;
			} else {
				printf("%d\n", min(end - st + 1, r[st] - l[st] + 1));
				return 0;
			}
		}
	}
	
	for (int ans1 = 1; ans1 <= r[st] - l[st] + 1; ans1++) {
	for (int ans2 = 1; ans2 <= end - st + 1; ans2++) {
		int ok = 1;
		for (int i = st; i <= st + ans2 - 1; i++) {
			if (l[i] != l[st]) {
				ok = 0;
				break;
			}
		}
		
		if (ok) {
			int top = st, bo = st + ans2 - 1, now = l[st];
			while (bo < end) {
				while (r[top] > now + ans1 - 1) {
					now++;
				}
				
				top++;
				bo++;
				if (now + ans1 - 1 > r[top]) {
					ok = 0;
				}
				
				if (now != l[bo]) {
					ok = 0;
				}
			}
			
			for (int i = top; i <= bo; i++) {
				if (r[i] != r[top]) {
					ok = 0;
				}
			}
		}
		
		if (ok) {
			ans = min(ans, ans1 * ans2);
		}
	}
	}
	
	if (ans == INF) {
		printf("-1\n");
		return 0;
	} else {
		printf("%d\n", ans);
	}
	
	return 0;
}