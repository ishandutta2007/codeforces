#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
using namespace std;

typedef long long int64;

template<class T> T gcd(T a, T b) {
	return b ? gcd(b, a % b) : a;
}

struct Frac {
	int64 a, b; // a/b b>0
	Frac(int64 _a, int64 _b) :
			a(_a), b(_b) {
//		int64 g = gcd(a, b);
//		a /= g;
//		b /= g;
		if (b < 0) {
			b *= -1;
			a *= -1;
		}
	}

	Frac(int64 x) :
			a(x), b(1) {
	}

	Frac() :
			a(0), b(1) {
	}

	Frac operator+(const Frac&o) const {
		return Frac(a * o.b + b * o.a, b * o.b);
	}

	Frac operator-(const Frac&o) const {
		return Frac(a * o.b - b * o.a, b * o.b);
	}

	Frac operator*(const Frac&o) const {
		return Frac(a * o.a, b * o.b);
	}

	Frac operator/(const Frac&o) const {
		return Frac(a * o.b, b * o.a);
	}

	Frac&operator+=(const Frac&o) {
		return (*this) = (*this) + o;
	}

	Frac&operator-=(const Frac&o) {
		return (*this) = (*this) - o;
	}

	Frac&operator*=(const Frac&o) {
		return (*this) = (*this) * o;
	}

	Frac&operator/=(const Frac&o) {
		return (*this) = (*this) / o;
	}

	int signum() const {
		return a < 0 ? -1 : a > 0;
	}

	int compareTo(const Frac&o) const {
		return ((*this) - o).signum();
	}

	bool operator<(const Frac&o) const {
		return compareTo(o) < 0;
	}

	bool operator<=(const Frac&o) const {
		return compareTo(o) <= 0;
	}

	bool operator>(const Frac&o) const {
		return compareTo(o) > 0;
	}

	bool operator>=(const Frac&o) const {
		return compareTo(o) >= 0;
	}

	bool operator==(const Frac&o) const {
		return compareTo(o) == 0;
	}
};

int64 Y1, Y2;
int64 t1, t2, x1, x2, t0;
Frac minOver;

void tryIt(int64 y1, int64 y2) {
	if (0 <= y1 && y1 <= x1 && y2 >= 0 && y2 <= x2 && y1 + y2 > 0) {
		Frac f = Frac(y1 * t1 + y2 * t2) / (y1 + y2);
		if (f >= t0) {
			Frac over = f - t0;
			if (over < minOver) {
				minOver = over;
				Y1 = y1, Y2 = y2;
			} else if (over == minOver) {
				if (y1 + y2 > Y1 + Y2) {
					Y1 = y1;
					Y2 = y2;
				}
			}
		}
	}
}

int main() {
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if (t1 == t2) {
		cout << x1 << " " << x2 << endl;
	} else if (t1 == t0) {
		cout << x1 << " " << 0 << endl;
	} else if (t2 == t0) {
		cout << 0 << " " << x2 << endl;
	} else {
		minOver = 1e10;
		tryIt(0, x2);
		for (int64 y1 = 1; y1 <= x1; ++y1) {
			int64 y2 = y1 * (t0 - t1) / (t2 - t0) - 1;
			for (int k = 0; k < 5; ++k) {
				tryIt(y1, y2);
				++y2;
			}
		}
		cout << Y1 << " " << Y2 << endl;
	}
	return 0;
}