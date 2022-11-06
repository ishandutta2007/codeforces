#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;


vector<ld>quad_equa(ld a,ld b,ld c) {
	ld root = b*b - 4 * a*c;
	if (abs(root) < eps) {
		ld ans = -b / (2 * a);
		return vector<ld>(2,ans);
	}
	else if (root > 0) {
		ld ans = -b / (2 * a);
		vector<ld>anss(2);
		anss[0] = ans + sqrt(root) / (2 * a);
		anss[1] = ans - sqrt(root) / (2 * a);
		return anss;
	}
	else {
		return vector<ld>();
	}

}

int main() {
	int N; cin >> N;
	vector<ld>as, bs;
	for (int i = 0; i < N; ++i) {
		ld a; scanf("%lf", &a);
		as.push_back(a);
		//cout << a << endl;
	}
	for (int i = 0; i < N; ++i) {
		ld b; scanf("%lf", &b);
		bs.push_back(b);
		//cout << b << endl;
	}
	ld suma = 0;
	ld sumb = 0;
	ld ansa = 0;
	ld ansb = 0;
	vector<vector<ld>>finanss(2, vector<ld>(N));
	for (int i = 0; i < N; ++i) {
		suma += as[N - i - 1];
		sumb += bs[N - i - 1];
		ld a = 1;
		ld b = -(suma + sumb);
		ld c = sumb;
		vector<ld>anss = quad_equa(a, b, c);
		if (anss.empty()){}
		else {
			if (anss[0]+eps > ansa) {
				finanss[0][N - i - 1] = anss[0] - ansa;
				finanss[1][N - i - 1] = anss[1] - ansb;
				ansa = anss[0];
				ansb = anss[1];
			}
			else {
				swap(anss[0], anss[1]);
				finanss[0][N - i - 1] = anss[0] - ansa;
				finanss[1][N - i - 1] = anss[1] - ansb;
				ansa = anss[0];
				ansb = anss[1];
			}
		}
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%lf", finanss[i][j]);
			if (j == N - 1)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}