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

struct query {
	int t;
	int r;
	int c;
	int x;
};

int main() {
	int N, M, Q; cin >> N >> M >> Q;
	vector<vector<int>>vs(N, vector<int>(M));
	vector<query>qs;
	for (int i = 0; i < Q; ++i) {
		int t; cin >> t;
		int r, c, x;
		if (t == 3) {
			cin >> r >> c >> x;
			r--; c--;
			qs.push_back(query{ t,r,c,x });
		}
		else if(t==1){
			cin >> r;
			r--;
			qs.push_back(query{ t,r,0,0 });

		}
		else {
			cin >> c;
			c--;
			qs.push_back(query{ t,0,c,0 });
		}
	}
	reverse(qs.begin(), qs.end());
	for (int i = 0; i < Q; ++i) {
		query q(qs[i]);
		int t = q.t;
		if (t == 1) {
			int r= q.r;
			int aa = vs[r][M-1];
			for (int i = M-2; i>=0; --i) {
				vs[r][i+1] = vs[r][i];

			}
			vs[r][0] = aa;
		}
		else if (t == 2) {
			int c = q.c;
			int aa = vs[N-1][c];
			for (int i = N-2; i >=0; --i) {
				vs[i+1][c] = vs[i][c];
			}
			vs[0][c] = aa;
		}
		else if (t == 3) {
			int r, c, x; r = q.r; c = q.c; x = q.x;
			vs[r][c] = x;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << vs[i][j];
			if (j == M - 1)cout << endl;
			else cout << " ";
		}
	}
	return 0;
}