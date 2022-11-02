#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define int long long
char s1[200010];
char s2[200010];
int q1[200010], q2[200010];
signed main() {
	int n; cin >> n;
	cin >> s1 + 1 >> s2 + 1;
	int p1 = 0, p2 = 0;
	for (int i = 1; i <= n; i++) {
		if (s1[i] == 'a'&&s2[i] == 'b') {
			q1[++p1] = i;
		}
		if (s1[i] == 'b'&&s2[i] == 'a') {
			q2[++p2] = i;
		}
	}

	if ((p1 + p2) % 2) {
		cout << "-1" << endl;
	}
	else {
		if (p1 % 2 == 0) {
			cout << (p1 + p2)/2 << endl;
			for (int i = 1; i <= p1; i+=2) {
				cout << q1[i] << " " << q1[i + 1] << endl;
			}
			for (int i = 1; i <= p2; i += 2) {
				cout << q2[i] << " " << q2[i + 1] << endl;
			}
		}
		else {
			cout << (p1 + p2)/2 + 1 << endl;
			for (int i = 1; i < p1; i += 2) {
				cout << q1[i] << " " << q1[i + 1] << endl;
			}
			for (int i = 1; i < p2; i += 2) {
				cout << q2[i] << " " << q2[i + 1] << endl;
			}
			cout << q1[p1] << " " << q1[p1] << endl;
			cout << q1[p1] << " " << q2[p2] << endl;
		}
	}

}