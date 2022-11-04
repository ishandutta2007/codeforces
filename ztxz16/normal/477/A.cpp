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

long long ans = 0, a, b;
const long long MO = 1000000007;

int main() {
	cin >> a >> b;
	ans = ((1 + a) * a / 2 % MO * b % MO + a) % MO * (b * (b - 1) / 2 % MO) % MO;
	cout << ans << endl;
	return 0;
}