#include "bits/stdc++.h"
using namespace std;

int main() {
	int N; cin >> N;
	{
		vector<int>anss;
		for (int i = 1; i < N; i += 2) {
			anss.push_back(i);
		}
		for (int i = 0; i < N; i += 2) {
			anss.push_back(i);
		}
		for (int i = 1; i < N; i += 2) {
			anss.push_back(i);
		}
		cout << anss.size() << endl;
		for (int i = 0; i < anss.size(); ++i) {
			cout << anss[i]+1;
			if (i == anss.size() - 1)cout << endl;
			else cout << " ";
		}
	}
	return 0;
}