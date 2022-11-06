#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

const int My_Inf=2147483647;
const long long int My_LInf=9223372036854775807;

int main() {
	int N; cin >> N;
	vector<vector<int>>mins(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int a; cin >> a;
			mins[i][j] = a;
		}
	}
	vector<int>anss(N, -1);
	int num = 1;
	while (!all_of(anss.begin(), anss.end(), [](const int a) {return a >= 0; })) {
		for (int i = 0; i < N; ++i) {
			if (anss[i]==-1&&all_of(mins[i].begin(), mins[i].end(), [=](const int a) {return a <= num; })) {
				anss[i] = num;
				num ++;
				break;
			}
		}
	}
	for (int i = 0; i < anss.size(); ++i) {
		cout << anss[i];
		if (i != anss.size() - 1)cout << " ";
	}
	cout << endl;
	return 0;
}