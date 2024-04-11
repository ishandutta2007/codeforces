#include<iostream>
#include<algorithm>
using namespace std;
int a[2000][2000];
int c[4][4] = { {0,1,2,3},{2,3,0,1},{1,2,3,0},{3,0,1,2} };
int main() {
	int n; cin >> n;
	for (int i = 0; i < n / 4; i++) {
		for (int o = 0; o < n / 4; o++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++)
					a[i * 4 + j][o * 4 + k] = c[j][k];
			}
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			a[i * 2][j * 2] += (i*n / 2 + j) * 4;
			a[i * 2+1][j * 2] += (i*n / 2 + j) * 4;
			a[i * 2][j * 2+1] += (i*n / 2 + j) * 4;
			a[i * 2+1][j * 2+1] += (i*n / 2 + j) * 4;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}