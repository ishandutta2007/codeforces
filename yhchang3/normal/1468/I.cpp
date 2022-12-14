#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int dx[5], dy[5];
	cin >> dx[0] >> dy[0] >> dx[1] >> dy[1];
	if(abs(1LL * dx[0] * dy[1] - 1LL * dx[1] * dy[0]) != n) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	dx[3] = dx[0], dy[3] = dy[0];
	dx[0] = dy[0] = dx[4] = dy[4] = 0;
	dx[2] = dx[1] + dx[3], dy[2] = dy[1] + dy[3];
	auto diff = [&](const int& x,const int& y) -> bool {
		for(int i=1;i<3;i++)
			if(1LL * (x - dx[i]) * (y - dy[i + 1]) == 1LL * (x - dx[i + 1]) * (y - dy[i]))
			return false;
		return true;
	};
	int D = min({dy[0], dy[1], dy[2], dy[3]});
	int U = max({dy[0], dy[1], dy[2], dy[3]});
	for(int y=D;y<=U;y++) {
		vector<double> X;
		for(int i=0;i<4;i++) {
			if(dy[i + 1] == dy[i] && y == dy[i]) {
				X.emplace_back(dx[i]);
				X.emplace_back(dx[i + 1]);
				continue;
			}
			if(dy[i] == y) {
				X.emplace_back(dx[i]);
				continue;
			}
			if(dy[i + 1] == y) {
				X.emplace_back(dx[i + 1]);
				continue;
			}
			if(dy[i] > y && dy[i + 1] > y)
				continue;
			if(dy[i] < y && dy[i + 1] < y)
				continue;
			double x = 1LL * dx[i + 1] * (y - dy[i]) + 1LL * dx[i] * (dy[i + 1] - y);
			x /= (dy[i + 1] - dy[i]);
			X.emplace_back(x);
		}
		double L = *min_element(X.begin(), X.end());
		double R = *max_element(X.begin(), X.end());
		for(int x=L-1;x<=R+1;x++) {
			if(x >= L && x <= R) {
				if(diff(x, y)) {
					cout << x << ' ' << y << '\n';
				}
			}
		}
	}
}