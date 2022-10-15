#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void A() {
	int x;
	cin >> x;
	int a, b;
	if (x == 1) {
		cout << -1;
	}
	else {
		cout << x << " " << x;
	}
}
void B() {
	int n, k;
	cin >> n >> k;
	set<int> q;
	for (size_t i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.insert(x);
	}
	vector<int> v;
	for (auto w : q) {
		v.push_back(w);
	}
	sort(v.begin(), v.end());
	if (k-- > 0) {
		cout << v[0] << endl;
	}
	int ind = 1;
	while (k-- > 0) {
		if (ind == v.size())
			cout << 0 << endl;
		else {
			cout << v[ind] - v[ind - 1] << endl;
			ind++;
		}
	}
}
void C() {
	int n;
	cin >> n;
	vector<long long> v;
	for (size_t i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	long long s = 0;
	cout << n + 1 << endl;
	for (size_t i = 0; i < n; i++)
	{
		long long w = (2001*2-1-i-(v[n-i-1]+s)%2001)%2001;
		s += w;
		cout << 1 << " " << n - i << " " << w<<endl;
	}
	cout << 2 << " " << n << " " << 2001;
}
void D() {

}
void E() {

}
int main() {
	char problem = 'C';
	switch (problem)
	{
	case 'A':
		A();
		break;
	case 'B':
		B();
		break;
	case 'C':
		C();
		break;
	case 'D':
		D();
		break;
	case 'E':
		E();
		break;
	}
	return 0;
}