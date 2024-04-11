#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;



int main() {
	int N, M; cin >> N >> M;
	bool edges[500][500];
	memset(edges, false, sizeof(edges));
	for (int i = 0; i < M; ++i) {
		int s, t; cin >> s >> t;
		s--; t--;
		edges[s][t] = true;
		edges[t][s] = true;
	}
	vector<char>cs(N, 'd');
	bool ok = true;
	for (int i = 0; i < N; ++i) {
		if (cs[i] == 'd') {
			bool allconnect = true;
			for (int j = 0; j < N; ++j) {
				if (i == j)continue;
				if (!edges[i][j]) {
					allconnect = false;
					break;
				}
			}
			if (allconnect) {
				cs[i] = 'b';
			}
			else {
				cs[i] = 'a';
				for (int j = 0; j < N; ++j) {
					if (i == j)continue;
					if (!edges[i][j]) {
						if (cs[j] == 'c') {

						}
						else if (cs[j] == 'a') {
							ok = false;
							break;
						}
						else {
							cs[j] = 'c';
						}
					}
					else {
						if (cs[j] == 'c') {
							ok = false;
							break;
						}
					}
				}
			}
		}
		else if (cs[i] == 'a') {
			for (int j = 0; j < N; ++j) {
				if (i == j)continue;
				if (!edges[i][j]) {
					if (cs[j] == 'c') {

					}
					else if (cs[j] == 'a') {
						ok = false;
						break;
					}
					else {
						cs[j] = 'c';
					}
				}
				else {
					if (cs[j] == 'c') {
						ok = false;
						break;
					}
				}
			}
		}
		else if (cs[i] == 'c') {
			for (int j = 0; j < N; ++j) {
				if (i == j)continue;
				if (!edges[i][j]) {
					if (cs[j] == 'a') {

					}
					else if (cs[j] == 'c') {
						ok = false;
						break;
					}
					else {
						cs[j] = 'a';
					}
				}
				else {
					if (cs[j] == 'a') {
						ok = false;
						break;
					}
				}
			}
		}
	}
	if (ok) {
		cout << "Yes" << endl;
		for (int i = 0; i < N; ++i) {
			cout << cs[i];
		}
		cout << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}