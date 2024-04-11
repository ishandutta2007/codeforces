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

const int N = 2005;

char s[N], p[N];
int l1, l2;
int f[N][N], g[N][N], succ[N][N];

int main() {
	scanf("%s", s + 1);
	scanf("%s", p + 1);
	l1 = strlen(s + 1);
	for (char ch = 'a'; ch <= 'z'; ch++) {
		succ[1][ch] = 0;
	}
	
	for (int i = 1; i <= l1; i++) {
		for (char ch = 'a'; ch <= 'z'; ch++) {
			succ[i][ch] = succ[i - 1][ch];
		}
		
		succ[i][s[i - 1]] = i - 1;
	}
	
	l2 = strlen(p + 1);
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			if (s[i] != p[j]) {
				g[i][j] = 0;
				continue;
			}
			
			if (j == 1) {
				g[i][j] = i;
			} else {
				int now = succ[i][p[j - 1]];
				if (now == 0) {
					g[i][j] = 0;
				} else {
					g[i][j] = g[now][j - 1];
				}
			}
		}
	}
	
	for (int i = 1; i <= l1; i++) {
		if (g[i][l2] != 0) {
			int need = (i - g[i][l2] + 1) - l2;
			for (int j = need; j <= i - l2; j++) {
				f[i][j] = max(f[i][j], f[g[i][l2] - 1][j - need] + 1);
			}
		}
		
		for (int j = 0; j <= i; j++) {
			if (j) {
				f[i][j] = max(f[i][j], f[i - 1][j - 1]);
			}
			
			f[i][j] = max(f[i][j], f[i - 1][j]);
		}
	}
	
	for (int i = 0; i <= l1; i++) {
		if (i == l1) {
			printf("%d\n", f[l1][i]);
		} else {
			printf("%d ", f[l1][i]);
		}
	}
	
	return 0;
}