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

const int N = 100005;

string first[N], last[N];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> first[i];
		cin >> last[i];
		if (last[i] < first[i]) {
			swap(first[i], last[i]);
		}
	}
	
	string now = "";
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (now < first[x]) {
			now = first[x];
		} else if (now < last[x]) {
			now = last[x];
		} else {
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	return 0;
}