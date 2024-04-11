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

const int N = 1005;

char str[N];
int n, p, end;

int main() {
	scanf("%d %d", &n, &p);
	scanf("%s", str + 1);
	if (n == 1) {
		if (str[1] + 1 <= 'a' + p - 1) {
			printf("%c", str[1] + 1);
		} else {
			printf("NO\n");
		}
		
		return 0;
	}
	
	if (p == 2) {
		if (n == 2) {
			if (str[1] == 'a') {
				if (str[2] == 'a') {
					printf("ab\n");
				} else {
					printf("ba\n");
				}
			} else {
				printf("NO\n");
			}
		} else {
			printf("NO\n");
		}
		
		return 0;
	}
	
	for (int i = 2; i <= n; i++) {
		if (str[i] == str[i - 1] || str[i] == str[i - 2]) {
			end = i;
			break;
		}
	}
	
	if (!end) {
		end = n;	
	}
	
	for (int i = end; i >= 1; i--) {
		for (char ch = str[i] + 1; ch <= 'a' + p - 1; ch++) {
			if (i == 1 || (ch != str[i - 1] && ch != str[i - 2])) {
				str[i] = ch;
				for (int j = i + 1; j <= n; j++) {
					for (char ch = 'a'; ch <= 'a' + p - 1; ch++) {
						if (ch != str[j - 1] && ch != str[j - 2]) {
							str[j] = ch;
							break;
						}
					}
				}
				
				printf("%s\n", str + 1);
				return 0;
			}
		}
	}
	
	printf("NO\n");
	return 0;
}