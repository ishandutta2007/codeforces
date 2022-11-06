#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

char ToLower(char cX) { return tolower(cX); }  // 



int N;
string mainst;

int aho[1100001][27];
int memo[11000];

pair<bool, vector<int>> check(const int from, int now) {
	if (from == N) {
		return make_pair(true, vector<int>());
	}
	if (memo[from])return make_pair(false, vector<int>());
	int place = from;
	while (aho[now][mainst[place] - 'a'] != -1) {
		now = aho[now][mainst[place] - 'a'];
		place++;
		if (aho[now][26] != -1) {
			pair<bool, vector<int>>p(check(place, 0));
			if (p.first) {
				p.second.push_back(aho[now][26]);
				return p;
			}
		}
		if (place == N)break;
	}
	memo[from] = 1;
	return  make_pair(false, vector<int>());
}


int main() {
	memset(memo, 0, sizeof(memo));
	cin >> N;  cin >> mainst;
	reverse(mainst.begin(), mainst.end());
	int M; cin >> M;
	vector<string>ori_sts;
	vector<string>low_sts;
	for (int i = 0; i < M; ++i) {
		string st; cin >> st;
		ori_sts.push_back(st);
		transform(st.begin(), st.end(), st.begin(), ToLower);
		low_sts.push_back(st);
	}

	for (int i = 0; i <= 26; ++i) {
		for (int j = 0; j < 1100001; ++j) {
			aho[j][i] = -1;
		}
	}
	int nex = 1;
	for (int i = 0; i < M; ++i) {
		int now = 0;
		int from = -1;
		for (int j = 0; j < low_sts[i].size(); ++j) {
			const int a = low_sts[i][j] - 'a';
			from = now;
			bool bb;
			bb = (aho[now][a] == -1);
			if (aho[now][a] == -1) {
				aho[now][a] = nex;
				now = nex;
				nex++;
			}
			else {
				now = aho[now][a];
			}
			/*if (!now) {
				cout<<bb<<" " << a<<" "<<i << " " << from <<" "<<nex<< endl;
					for (int j = 0; j < 1000; ++j) {

						for (int i = 0; i < 27; ++i) {
							cout << aho[j][i];
							cout << " ";
						}
						cout << endl;
					}
				
			}*/
		}
		aho[now][26] = i;
		
	}
	/*if (N == 9835) {
		for (int j = 0; j < 1000; ++j) {

			for (int i = 0; i < 27; ++i) {
				cout << aho[j][i];
				cout << " ";
			}
			cout << endl;
		}
	}*/
	vector<int>ans = check(0, 0).second;
	int nn = 0;
	for (auto i : ans) {
		nn += (ori_sts[i].size());
	}
	assert(nn = N);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ori_sts[ans[i]];
		if (i != ans.size() - 1)cout << " ";
		else cout << endl;
	}

	return 0;
}