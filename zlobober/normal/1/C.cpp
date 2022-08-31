#include <cstdio>
#include <cassert>
#include <complex>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

typedef complex<double> vt;

const double EPS = 1e-6;
const double pi = 3.14159265358979323;

const int N = 105;
vt P[N];

double operator ^(vt a, vt b)
{
	return a.imag() * b.real() - b.imag() * a.real();
}

bool similar(vt a, vt b, vt c, vt d)
{
	return (abs(((a / c) * d) / b - vt(1, 0)) < EPS);
}

int main()
{
	vt A[3];
	for (int i = 0; i < 3; i++)
		scanf("%lf %lf", &A[i].real(), &A[i].imag());
	for (int n = 3; n <= 100; n++)
	{
		double S = 0;
		eprintf("n = %d\n", n);
		for (int i = 0; i < n; i++)
		{
			P[i] = vt(cos(i * 2 * pi / n), sin(i * 2 * pi / n));
			eprintf("%lf %lf\n", P[i].real(), P[i].imag());
		}
		for (int i = 0; i < n; i++)
			S += (P[i] ^ P[(i + 1) % n]);
		S /= 2;
		S = fabs(S);
		eprintf("S = %lf\n", S);
		for (int i = 1; i < n; i++)
			for (int j = 1; j < n; j++)
			{
				if (i == j)
					continue;
				if (similar(A[1] - A[0], A[2] - A[0], P[i] - P[0], P[j] - P[0]))
				{
					double ans = S * ((A[1] - A[0]) ^ (A[2] - A[0])) / ((P[i] - P[0]) ^ (P[j] - P[0]));
					printf("%.10lf\n", ans);
					return 0;
				}
			}
	}
	assert(false);
}