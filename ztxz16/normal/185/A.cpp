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

const int mo = 1000000007;

struct Matrix {
	int n;
	int v[3][3];
	
	void init(int _n) {
		n = _n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = 0;
			}
		}
	}
	
	friend Matrix operator * (const Matrix &a, const Matrix &b) {
		Matrix c;
		int n = a.n;
		c.init(n);
		for (int k = 1; k <= 2; k++) {
			for (int i = 1; i <= 2; i++) {
				for (int j = 1; j <= 2; j++) {
					(c.v[i][j] += (long long)a.v[i][k] * b.v[k][j] % mo) %= mo;
				}
			}
		}
		
		return c;
	}
} x, ret;

long long n;

int main() {
	x.init(2);
	x.v[1][1] = x.v[2][2] = 3;
	x.v[1][2] = x.v[2][1] = 1;
	ret.init(2);
	ret.v[1][1] = ret.v[2][2] = 1;
	//scanf("%d", &n);
	cin >> n;
	while (n) {
		if (n & 1) {
			ret = ret * x;
		}
		
		x = x * x;
		n >>= 1;
	}
	
	printf("%d\n", ret.v[1][1]);
	return 0;
}