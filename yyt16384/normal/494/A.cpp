#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;

int n;
char s[MAXN];
char s2[2*MAXN];

void init()
{
	scanf("%s", s);
	n = strlen(s);
}

void solve()
{
	int last;
	for (int i = n - 1; i >= 0; --i)
		if (s[i] == '#')
		{
			last = i;
			break;
		}

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(') ++sum;
		else if (s[i] == ')') --sum;
	}

	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] != '#') s2[m++] = s[i];
		else if (i != last) s2[m++] = ')', --sum;
		else
		{
			if (sum < 1)
			{
				printf("-1\n");
				return;
			}
			for (int j = 0; j < sum; ++j) s2[m++] = ')';
		}
	}

	for (int i = 0, ss = 0; i < m; ++i)
	{
		if (s2[i] == '(') ++ss;
		else
		{
			--ss;
			if (ss < 0)
			{
				printf("-1\n");
				return;
			}
		}
	}

	for (int i = 0; i < n; ++i)
		if (s[i] == '#' && i != last)
			printf("1\n");
	printf("%d\n", sum);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}