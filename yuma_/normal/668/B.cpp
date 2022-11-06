#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;


//

int main() {
	int N, Q; cin >> N >> Q;
	int a = 0, b = 1;
	bool flag = false;
	for (int i = 0; i < Q; ++i) {
		int t; 
		scanf("%d", &t);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			x = N - x;
			if (x % 2) {

				a += (x/2)*2 + 2;
				b += (x / 2) * 2;
				swap(a, b);
			}
			else {
				a += (x / 2) * 2;
				b += (x / 2) * 2;
			}
			a %= N;
			b %= N;
		}
		else {
			swap(a, b);
			flag = !flag;
		}
	}
	vector<int>anss(N);
	
	int an = a;
	int bn = b;
	for (int i = 0; i < N / 2; ++i) {
		anss[2 * i] = an;
		anss[2 * i + 1] = bn;
		an += 2;
		bn += 2;
		an %= N;
		bn %= N;
	}
	
	for (int i = 0; i < N; ++i) {
		printf("%d", anss[i] + 1);
		if (i == N - 1)printf("\n");
		else printf(" ");
	}
	
	return 0;
}