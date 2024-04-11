#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2015;

char s[N], t[N];

int main()
{
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n / 2; ++i)
		s[i] = '>';
	for (int i = n / 2; i < n; ++i)
	{
		if (!(i - n / 2 & 1))
			s[i] = '.';
		else
			s[i] = '>';
	}
	s[n - 1] = 'v';
	for (int i = 0; i < n; ++i)
	{
		t[i] = s[i];
		if (t[i] == '>') t[i] = '<';
		if (t[i] == 'v') t[i] = '^';
	}
	reverse(t, t + n);

	for (int i = 0; i < n; ++i)
		printf("%s\n", i & 1 ? t : s);
	printf("%d %d\n", 1, n);
}