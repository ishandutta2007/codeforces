#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAX_N = int(1e6) + 10;

int cnt[2][2] = { };
int n;
string a, b;

int main() {
	int n;
	cin >> n;
	cin >> a >> b;
	for (int i = 0; i < n * 2; ++i) {
		cnt[a[i] - '0'][b[i] - '0']++;
	}

	int cnta[2] = { }, cntb[2] = { };

	for (int i = 0; i < n; ++i) {
		int A[4][2] = { { 1, 1 }, { 1, 0 }, { 0, 1 }, { 0, 0 } };
		int B[4][2] = { { 1, 1 }, { 0, 1 }, { 1, 0 }, { 0, 0 } };

		//a
		for (int i = 0; i < 4; ++i) {
			int x = A[i][0], y = A[i][1];
			if (cnt[x][y] > 0) {
				cnta[x]++;
				--cnt[x][y];
				break;
			}
		}

		//b
		for (int i = 0; i < 4; ++i) {
			int x = B[i][0], y = B[i][1];
			if (cnt[x][y] > 0) {
				cntb[y]++;
				--cnt[x][y];
				break;
			}
		}
	}

	if (cnta[1] > cntb[1])
		cout << "First";
	else if (cnta[1] == cntb[1])
		cout << "Draw";
	else
		cout << "Second";
	cout << endl;
}