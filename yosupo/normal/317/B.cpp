#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
	int n, t;
	scanf("%d%d", &n, &t);
	int ant[141][141] = {};
	ant[70][70] = n;
	int flag = 1, m = 0;
	while(flag) {
		flag = 0;
		for(int i = 0; i < 141; i++) {
			for(int j = 0; j < 141; j++) {
				if(ant[i][j] >= 4) {
					m = ant[i][j] / 4;
					flag = 1;
					ant[i][j] %= 4;
					ant[i+1][j] += m;
					ant[i-1][j] += m;
					ant[i][j+1] += m;
					ant[i][j-1] += m;
				}
			}
		}
	}
	int x, y;
	for(int i = 0; i < t; i++) {
		scanf("%d%d", &x, &y);
		if(x < -70 || 70 < x || y < -70 || 70 < y) {
			printf("%d\n", 0);
		} else {
			printf("%d\n", ant[x+70][y+70]);
		}
	}
	return 0;
}