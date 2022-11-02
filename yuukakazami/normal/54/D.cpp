#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
#define PRINT_LINE \
		cout<<"At:"__LINE__<<endl;
using namespace std;

bool can[200][200] = { };
int p1[200][200], p2[200][200];

int main() {
	int n, k;
	cin >> n >> k;
	string p;
	cin >> p;
	string need;
	cin >> need;
	int next[200][26];
	vector<string> ss;
	for (int i = 0; i <= p.size(); ++i) {
		ss.push_back(p.substr(0, i));
	}
	for (int i = 0; i < ss.size(); ++i) {
		string s = ss[i];
		for (int j = 0; j < k; ++j) {
			string ns = s + char('a' + j);
			for (int l = 0; l < ss.size(); ++l) {
				if (ss[l].size() <= ns.size() && ns.substr(ns.size() - ss[l].size()) == ss[l]) {
					next[i][j] = l;
				}
			}
		}
	}
	can[0][0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < ss.size(); ++j) {
			if (can[i][j]) {
				for (int l = 0; l < k; ++l) {
					int ns = next[j][l];
					if (i >= p.size() - 1) {
						if ((ns == p.size()) != (need[i - p.size() + 1] == '1'))
							continue;
					}
					can[i + 1][ns] = true;
					p1[i + 1][ns] = l;
					p2[i + 1][ns] = j;
				}
			}
		}
	}
	for (int j = 0; j < ss.size(); ++j) {
		if (can[n][j]) {
			string ans;
			while (n > 0) {
				ans += p1[n][j] + 'a';
				j = p2[n][j];
				--n;
			}
			reverse(ans.begin(), ans.end());
			cout << ans << endl;
			return 0;
		}
	}
	cout << "No solution" << endl;
	return 0;
}