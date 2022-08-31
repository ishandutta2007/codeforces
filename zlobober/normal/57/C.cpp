#include <iostream>
using namespace std;

const long long P = 1000000007;

long long powmod(long long x, long long a)
{
	if (a == 0)
		return 1;
	long long pt = powmod((x * x) % P, a / 2);
	
	if (a % 2)
		return (pt * x) % P;
	else
		return pt;
}

long long inv(long long x)
{
	return powmod(x, P - 2);
}

long long cnt(int n)
{
	long long sc = 1;
	long long ans = 1;
	for (int i = 1; i < n; i++)
		sc = (((sc * (n + i - 1)) % P) * inv(i)) % P, ans = (ans + sc) % P;
	return ans;
}

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	cout << (((2 * cnt(n)) % P + P) - n) % P;
	return 0;
}