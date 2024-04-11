#include <iostream>
#include <iomanip>
#include <set>
#include <cstdio>
using namespace std;

//#define TASK ""

typedef long double ldouble;

set<ldouble> S;

const ldouble EPS = 1e-8;

const int N = 10500;

ldouble a[N];
	
int n;
int k;
	

bool great(ldouble x)
{
	ldouble G = 0, L = 0;
	ldouble alpha = (ldouble)k / 100.0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x)
			G += a[i] - x;
		else
			L += x - a[i];
	}
	return ((1 - alpha) * G > L);
}

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ldouble A = 0, B = 1000;
	while (B - A > EPS)
	{
		if (great((B + A) / 2))
			A = (A + B) / 2;
		else
			B = (A + B) / 2;
	}
	cout << fixed << setprecision(10) << (A + B) / 2 << endl;
	return 0;
}