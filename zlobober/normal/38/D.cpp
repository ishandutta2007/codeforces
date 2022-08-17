#include <iostream>
using namespace std;

long long abs(long long x)
{
	return (x < 0) ? -x : x;
}

struct vt
{
	long long x, y;
	vt(double _x, double _y)
	{
		x = _x, y = _y;
	}
	friend vt operator +(vt a, vt b)
	{
		return vt(a.x + b.x, a.y + b.y);
	}
	friend vt operator /(vt a, double d)
	{
		return vt(a.x / d, a.y / d);
	}
	friend vt operator *(vt a, long long d)
	{
		return vt(a.x * d, a.y * d);
	}
	vt(){}
};

struct cube
{
	vt a, b;
	vt cm()
	{
		return (a + b);
	}
	bool has(vt x, long long kop)
	{
		vt _a = a * 2 * kop, _b = b * 2 * kop;
		if (_a.x > _b.x)
			swap(_a.x, _b.x);
		if (_a.y > _b.y)
			swap(_a.y, _b.y);
		return (_a.x <= x.x && x.x <= _b.x && _a.y <= x.y && x.y <= _b.y);
	}
	double mass()
	{
		return abs((a.y - b.y) * (a.y - b.y) * (a.y - b.y));
	}
	cube(){}
} C[100];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> C[i].a.x >> C[i].a.y >> C[i].b.x >> C[i].b.y;
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			vt cm(0.0, 0.0);
			long long kop = 0;
			for (int k = j; k <= i; k++)
				cm = cm + C[k].cm() * C[k].mass(), kop += C[k].mass();
			if (!C[j - 1].has(cm, kop))
			{
				cout << i;
				return 0;
			}
		}
	}
	cout << n;
}