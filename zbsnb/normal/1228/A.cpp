#include<iostream>
using namespace std;
int main() {
	int l, r; cin >> l >> r;
	for (int i = l; i <= r; i++) {
		int a[10], cnt=0;
		int tmp = i;
		while (tmp) {
			a[cnt++] = tmp % 10;
			tmp /= 10;
		}
		int flg = 0;
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < cnt; j++) {
				if (i == j)continue;
				if (a[i] == a[j])flg = 1;
			}
		}
		if (!flg) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}