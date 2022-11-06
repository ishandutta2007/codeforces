#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"


int main() {
	int N, M, P; cin >> N >> M >> P;
	string st; cin >> st;
	vector<int>cors(N+2);
	stack<int>sta;
	for (int i = 1; i <= st.size(); ++i) {
		if (st[i-1] == '(') {
			sta.push(i);
		}
		else {
			int atop(sta.top());
			cors[i] = atop;
			cors[atop] = i;
			sta.pop();
		}
	}
	string order; cin >> order;
	vector<pair<int, int>>moves(N+2);
	for (int i = 0; i <= N+1; ++i) {
		moves[i] = make_pair(i - 1, i + 1);
	}
	vector<int>lives(N, true);
	for (int i = 0; i < order.size(); ++i) {
		if (order[i] == 'R') {
			P = moves[P].second;
		}
		else if (order[i] == 'L') {
			P = moves[P].first;
		}
		else {
			int del_l = P;
			int del_r = cors[P];
			if (del_l > del_r) {
				swap(del_l, del_r);
			}

			const int al = moves[del_l].first;
			const int ar = moves[del_r].second;
			moves[al].second = ar;
			moves[ar].first = al;
			for (int x = del_l; x <= del_r;) {
				int next = moves[x].second;
				moves[x].first = al;
				lives[x-1] = false;
				moves[x].second = ar;
				x = next;
			}
			P = ar;
		}
		if (P == N + 1)P = moves[P].first;
	}
	for (int i = 0; i < st.size(); ++i) {
		if (lives[i])cout << st[i];
	}
	cout << endl;
	return 0;
}