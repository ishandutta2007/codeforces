#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

int a[9][4];

int dot(const int &x1, const int &y1, const int &z1, const int &x2, const int &y2, const int &z2) {
	return ((long long)x1 * x2 + (long long)y1 * y2 + (long long)z1 * z2) > 0LL;
}

int ok() {
	for (int i = 2; i <= 8; i++) {
		int dx1 = a[i][1] - a[1][1], dx2 = a[i][2] - a[1][2], dx3 = a[i][3] - a[1][3];
		if (!dx1 && !dx2 && !dx3) {
			continue;
		}
		
		long long dd = (long long)dx1 * dx1 + (long long)dx2 * dx2 + (long long)dx3 * dx3;
		for (int j = i + 1; j <= 8; j++) {
			int dy1 = a[j][1] - a[1][1], dy2 = a[j][2] - a[1][2], dy3 = a[j][3] - a[1][3];
			if ((long long)dy1 * dy1 + (long long)dy2 * dy2 + (long long)dy3 * dy3 != dd) {
				continue;
			}
			
			if (dot(dx1, dx2, dx3, dy1, dy2, dy3)) {
				continue;
			}
			
			for (int k = i + 1; k <= 8; k++) {
				int dz1 = a[k][1] - a[1][1], dz2 = a[k][2] - a[1][2], dz3 = a[k][3] - a[1][3];
				if ((long long)dz1 * dz1 + (long long)dz2 * dz2 + (long long)dz3 * dz3 != dd) {
					continue;
				}
				
				if (dot(dx1, dx2, dx3, dz1, dz2, dz3) || dot(dy1, dy2, dy3, dz1, dz2, dz3)) {
					continue;
				}
				
				int now = 0;
				for (int l = 2; l <= 8; l++) {
					int dn1 = a[l][1] - a[1][1], dn2 = a[l][2] - a[1][2], dn3 = a[l][3] - a[1][3];
					int x = 0;
					if (dn1 == dx1 + dy1 && dn2 == dx2 + dy2 && dn3 == dx3 + dy3) {
						x = 1;
					}
					
					if (dn1 == dx1 + dz1 && dn2 == dx2 + dz2 && dn3 == dx3 + dz3) {
						x = 2;
					}
					
					if (dn1 == dy1 + dz1 && dn2 == dy2 + dz2 && dn3 == dy3 + dz3) {
						x = 4;
					}
					
					if (dn1 == dx1 + dy1 + dz1 && dn2 == dx2 + dy2 + dz2 && dn3 == dx3 + dy3 + dz3) {
						x = 8;
					}
					
					now += x;
				}
				
				if (now == 15) {
					return 1;
				}
			}
		}
	}
	
	return 0;
}

void dfs(int i) {
	if (i > 8) {
		if (ok()) {
			printf("YES\n");
			for (int i = 1; i <= 8; i++) {
				printf("%d %d %d\n", a[i][1], a[i][2], a[i][3]);
			}
			
			exit(0);
		}
		
		return;
	}
	
	dfs(i + 1);
	swap(a[i][2], a[i][3]);
	dfs(i + 1);
	swap(a[i][1], a[i][3]);
	dfs(i + 1);
	swap(a[i][3], a[i][2]);
	dfs(i + 1);
	swap(a[i][1], a[i][3]);
	dfs(i + 1);
	swap(a[i][2], a[i][3]);
	dfs(i + 1);
}

int main() {
	for (int i = 1; i <= 8; i++) {
		scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
	}
	
	dfs(2);
	printf("NO\n");
	return 0;
}