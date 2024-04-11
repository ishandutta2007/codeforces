#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[200010];
struct nod {
	int w, id;
	bool operator < (const nod x) {
		return w > x.w;
	}
}d[200010];
vector<int> vec[200010];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> d[i].w, d[i].id = i;
	sort(d + 1, d + n + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = d[i].id * 2 - 1;
	}
	int tot = n;
	for (int i = 1; i <= n; i++) {
		int ind = i + d[i].w - 1;
		if (ind >= tot) {
			a[++tot] = d[i].id * 2;
		}
		else {
			vec[ind].push_back(d[i].id * 2);
		}
	}
	for (int i = 1; i < tot; i++) {
		cout << a[i] << " " << a[i + 1] << endl;
	}
	for (int i = 1; i < tot; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << a[i] << " " << vec[i][j] << endl;
		}
	}
}