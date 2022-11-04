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

string ans[10] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string str;
int n;

int main() {
	scanf("%d", &n);
	cin >> str;
	for (int i = 0; i < 8; i++) {
		if (ans[i].size() != n) {
			continue;
		}
		
		int flag = 1;
		for (int j = 0; j < n; j++) {
			if (str[j] != '.' && str[j] != ans[i][j]) {
				flag = 0;
				break;
			}
		}
		
		if (flag) {
			cout << ans[i] << endl;
			return 0;
		}
	}
	
	return 0;
}