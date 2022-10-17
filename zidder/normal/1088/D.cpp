#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int N = 30;
long long get_int(vector<int> a) {
	long long s = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		s += a[i];
		s <<= 1;
	}
	return s>>1;
}
int ask(vector<int> c, vector<int> d) {
	cout << "? " << get_int(c) << " " << get_int(d) << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
void D() {
	vector<int> c(N, 0), d(N, 0), a(N, 0), b(N, 0);

	int zero = ask(c, d);
	for (size_t i = 0; i < N; i++)
	{
		c[i] = 1;
		d[i] = 1;
		int q = ask(c, d);
		if ((zero >= 0) && (q >= 0) || (zero <= 0) && (q <= 0)) {
			c[i] = 0;
			int w = ask(c, d);
			if (w >= 0) {
				a[i] = 1;
				b[i] = 1;
				c[i] = 1;
				d[i] = 1;
			}
			else {
				a[i] = 0;
				b[i] = 0;
				c[i] = 0;
				d[i] = 0;
			}
			zero = q;
			continue;
		}
		if (zero >= 0 && q <= 0) {
			a[i] = 1;
			b[i] = 0;
			c[i] = 1;
			d[i] = 0;
			zero = ask(c, d);
			continue;
		}
		if (q >= 0 && zero <= 0) {
			b[i] = 1;
			a[i] = 0;
			d[i] = 1;
			c[i] = 0;
			zero = ask(c, d);
			continue;
		}
	}
	cout << "! " << get_int(a) << " " << get_int(b) << endl;
	fflush(stdout);
}
void E() {

}
int main() {
	char problem = 'D';
	switch (problem)
	{
	case 'D':
		D();
		break;
	case 'E':
		E();
		break;
	}
	return 0;
}