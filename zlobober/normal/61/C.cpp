#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int val(char c)
{
	if ('0' <= c && c <= '9')
		return c - '0';
	else
		return c - 'A' + 10;
}

char symb(int v)
{
	if (v < 10)
		return '0' + v;
	else
		return 'A' + v - 10;
}

long long from(char* buf, int a)
{
	int n = strlen(buf);
	long long num = 0;
	for (int i = 0; i < n; i++)
		num = num * a + val(buf[i]);
	return num;
}



char sym[][3] = {"IV", "XL", "CD", "MP"};

char* rim(long long k)
{
	char* ans = new char[100];
	int pt = 0;
	memset(ans, 0, 100);
	for (int q = 1000, i = 3; i >= 0; q /= 10, i--)
	{
		k %= (10 * q);
		if (k / q == 0)
			continue;
		if (k / q == 4)
		{
			ans[pt++] = sym[i][0], ans[pt++] = sym[i][1];
			continue;
		}
		if (k / q == 9)
		{
			ans[pt++] = sym[i][0], ans[pt++] = sym[i + 1][0];
			continue;
		}
		
		if (k / q > 4)
			ans[pt++] = sym[i][1], k -= 5 * q;
		for (int j = 0; j < k / q; j++)
			ans[pt++] = sym[i][0];
	}
	return ans;
}

char* to(long long k, int b)
{
	char* ans = new char[100];
	memset(ans, 0, 100);
	if (k == 0)
	{
		ans[0] = '0';
		return ans;
	}
	int i;
	for (i = 0; k > 0; i++)
	{
		ans[i] = symb(k % b);
		k /= b;
	}
	i--;
	for (int j = i; j > i / 2; j--)
		swap(ans[j], ans[i - j]);
	return ans;
}

int main(int argc, char **argv)
{
#ifdef HASFILES
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int a;
	char b[5];
	cin >> a >> b;
	char c[2000];
	cin >> c;
	if (b[0] == 'R')
		cout << rim(from(c, a));
	else
	{
		cout << to(from(c, a), atoi(b));
	}
	cout << endl;
	return 0;
}