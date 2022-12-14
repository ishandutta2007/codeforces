#include<bits/stdc++.h>
using namespace std;

int x[200010], y[200010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, H;
	cin >> n >> H;
	for(int i=1;i<=n;i++)
		cin >> x[i] >> y[i];
	for(int i=1;i<=n;i++)
		x[i] = x[i] - x[n], y[i] = y[i] - (y[n] + H);
	vector<int> v(n);
	for(int i=0;i<n;i++)
		v[i] = i + 1;
	sort(v.begin(), v.end(), [&](const int& a, const int& b) {
		return 1LL * x[a] * y[b] - 1LL * x[b] * y[a] > 0;	
	});
	int j = 0;
	double ans = 0;
	auto cross = [&](const int& x1, const int& y1, const int& x2, const int& y2) -> long long {
		return 1LL * x1 * y2 - 1LL * x2 * y1;	
	};
	auto dist = [&](const int& x1, const int& y1, const double& x2, const double& y2) -> double {
		return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	};
	for(int i=1;i<n;i++) {
		while(v[j] <= i)	j++;
		int k = v[j];
		double cur = 0;
		long long c1 = cross(x[k], y[k], x[i], y[i]);
		long long c2 = cross(x[k], y[k], x[i+1], y[i+1]);
		if(c1 < 0) {
			if(c2 == 0) {
				cur = dist(x[i], y[i], x[i + 1], y[i + 1]);
			}
			else {
				double X = (c2 * x[i] - c1 * x[i+1]) / (double) (c2 - c1);
				double Y = (c2 * y[i] - c1 * y[i+1]) / (double) (c2 - c1);
				cur = dist(x[i], y[i], X, Y);
			}
		}
		else if(c1 == 0) {
			if(c2 == 0) {
				cur = dist(x[i], y[i], x[i + 1], y[i + 1]);
			}
		}
		ans += cur;
	}
	cout << fixed << setprecision(10) << ans << endl;
}