#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cmath>
#include<iterator>

using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	int sc[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
	scanf("%d", &t);
	map<string, vi> my1;
	for (int ii = 0; ii < t; ++ii) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			if (my1.find(s) == my1.end()) {
				my1[s] = vi(51, 0);
			}
			if (i < 10) {
				my1[s][0] -= sc[i];
			}
			--my1[s][i + 1];
		}
	}
	vector<string> words;
	vector<vi > scores;
    for (map<string, vi>::iterator it = my1.begin(); it != my1.end(); ++it) {
		words.push_back((*it).first);
		scores.push_back((*it).second);
		scores.back().push_back(words.size() - 1);
	}
	sort(scores.begin(), scores.end());
	cout << words[scores[0].back()] << endl;
	words.resize(0);
	scores.resize(0);
    for (map<string, vi>::iterator it = my1.begin(); it != my1.end(); ++it) {
		words.push_back((*it).first);
		scores.push_back((*it).second);
		scores.back().push_back(words.size() - 1);
		swap(scores.back()[0], scores.back()[1]);
	}
	sort(scores.begin(), scores.end());
	cout << words[scores[0].back()] << endl;
	return 0;
}