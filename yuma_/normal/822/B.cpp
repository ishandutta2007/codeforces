#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M; cin >> N >> M;
	string s, t; cin >> s >> t;
	pair<int, int>ans(-1, -1);
	for (int i = 0; i <= M - N; ++i) {
		int num = 0;
		for (int x = i; x < i + N; ++x) {
			num += s[x - i] == t[x];
		}
		ans = max(ans,make_pair(num,i));
	}
	vector<int>v;
	{
		int i = ans.second;
		for (int x = i; x < i + N; ++x) {
			if(s[x-i]!=t[x])v.emplace_back(x - i + 1);
		}
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i == v.size() - 1)cout << endl;
		else cout << " ";
	}

	return 0;
}