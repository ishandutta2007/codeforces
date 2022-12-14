#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point {
	ll x, y;
	Point(ll x = 0, ll y = 0) : x(x), y(y) {}
	ll operator^(const Point& other) const {
		return x * other.y - y * other.x;
	}
	int quad() const {
		return y>0||(y==0&&x>=0);
	}
	bool operator<(const Point& other) const {
		Point l = quad() ? Point(-x, -y) : (*this);
		Point r = other.quad() ? Point(-other.x, -other.y) : other;
		return (l ^ r) > 0;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Point> p(n);
	for(int i=0;i<n;i++)
		cin >> p[i].x >> p[i].y;
	ll ans = 0;
	auto C2 = [&](const int& x) -> ll {
		return 1LL * x * (x - 1) / 2;
	};
	for(int i=0;i<n;i++) {
		vector<Point> cur;
		for(int j=0;j<n;j++)
			if(i != j)
				cur.emplace_back(p[j].x - p[i].x, p[j].y - p[i].y);
		sort(cur.begin(), cur.end());
		int l = 0, r = 0;
		for(auto &o : cur)
			if(o.quad())	r++;
			else	l++;
		for(auto &o : cur) {
			if(o.quad())	r--;
			else	l--;
			ans += C2(l) * C2(r);
			if(o.quad())	l++;
			else	r++;	
		}
	}
	cout << ans / 2 << endl;
}