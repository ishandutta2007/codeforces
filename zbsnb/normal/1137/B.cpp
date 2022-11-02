#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef unsigned long long ull;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

char a[550000];
char b[550000];
ull p1[550000];
ull p2[550000];
ull h1[550000];
ull h2[550000];
ull tmp1[550000];
ull tmp2[550000];
ull inv1[550000];
ull inv2[550000];
ull mypow1(ull a, ull b)
{
	ull ret = 1;
	while (b)
	{
		if (b & 1)ret = ret * a%mod1;
		a = a * a%mod1; b >>= 1;
	}
	return ret;
}
ull mypow2(ull a, ull b)
{
	ull ret = 1;
	while (b)
	{
		if (b & 1)ret = ret * a%mod2;
		a = a * a%mod2; b >>= 1;
	}
	return ret;
}

int cnta0;
int cnta1;
int cntb0;
int cntb1;

char s[550000];
int main()
{
	cin >> a >> b;
	int tmplen = strlen(a);
	for (int i = 0; i < tmplen; i++)
	{
		if (a[i] == '0')cnta0++;
		else cnta1++;
	}
	p1[0] = p2[0] = 1;
	for (int i = 1; i <= 520000; i++)
	{
		p1[i] = p1[i - 1] * 137 % mod1;
		p2[i] = p2[i - 1] * 139 % mod2;
	}
	inv1[520000] = mypow1(p1[520000], mod1 - 2);
	inv2[520000] = mypow2(p2[520000], mod2 - 2);
	for (int i = 520000; i >= 1; i--)
	{
		inv1[i - 1] = inv1[i] * 137 % mod1;
		inv2[i - 1] = inv2[i] * 139 % mod2;
	}
	int len = strlen(b);
	for (int i = 0; i < len; i++)
	{
		h1[i + 1] = (h1[i] + b[i] * p1[i]) % mod1;
		h2[i + 1] = (h2[i] + b[i] * p2[i]) % mod2;
	}
	for (int i = 0; i < len; i++)
	{
		tmp1[i + 1] = (h1[len] - h1[i] + mod1) * inv1[i] % mod1;
		tmp2[i + 1] = (h2[len] - h2[i] + mod2) * inv2[i] % mod2;
	}
	int pos = 0;
	for (int i = 1; i < len; i++)
	{
		if (h1[i] == tmp1[len + 1 - i] && h2[i] == tmp2[len + 1 - i])
		{
			pos = i;
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (b[i] == '0')cntb0++;
		else cntb1++;
	}
	int p = 0;
	int cnt0 = 0, cnt1 = 0;
	for (int i = pos; i < len; i++)
	{
		if (b[i] == '0')cnt0++;
		else cnt1++;
	}
	if (cnta1 < cntb1 || cnta0 < cntb0)
	{
		cout << a << endl;
		return 0;
	}
	else
	{
		cnta1 -= cntb1; cnta0 -= cntb0; p += len;
		for (int i = 0; i < p; i++)
		{
			s[i] = b[i];
		}
		while (cnta1 - cnt1 >= 0 && cnta0 - cnt0 >= 0)
		{
			cnta1 -= cnt1; cnta0 -= cnt0;
			for (int i = pos; i < len; i++)
			{
				s[p++] = b[i];
			}
		}
		for (int i = 1; i <= cnta1; i++)
		{
			s[p++] = '1';
		}
		for (int i = 1; i <= cnta0; i++)
		{
			s[p++] = '0';
		}
		s[p] = 0;
	}
	cout << s << endl;
}