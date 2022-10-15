#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

typedef long long ll;
using namespace std;

int n;

int main() {
	cin >> n;
	vector<pair<int, int>> a, b, c, d;
	for (size_t i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a.push_back(make_pair(x, y));
		c.push_back(make_pair(y, x));
	}
	for (size_t i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		b.push_back(make_pair(x, y));
		d.push_back(make_pair(y, x));
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	reverse(d.begin(), d.end());
	for (size_t i = 0; i < n; i++)
	{
		a[i].first += b[i].first;
		c[i].first += d[i].first;
	}
	cout << a[0].first << " " << c[0].first;
	return 0;
}