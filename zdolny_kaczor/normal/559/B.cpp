# include <cstdio>
# include <cstring>
# include <set>
# include <cstdlib>
using namespace std;
const int MN = 200020;
bool equ(char a[], char b[], int len)
{
	if (len % 2 == 1)
	{
		bool all = true;
		for (int i = 0; i < len; ++i)
			if (a[i] != b[i])
				all = false;
		return all;
	}
	else
	{
		len /= 2;
		pair <char *, char *> tab [] = 
		{
			{a, b},
			{a + len, b + len},
			{a, b + len},
			{a + len, b}
		};
		if (rand() % 2)
			swap(tab[0], tab[1]);
		if (rand() % 2)
			swap(tab[2], tab[3]);
		if (rand() % 2)
		{
			swap(tab[0], tab[2]);
			swap(tab[1], tab[3]);
		}
		return (equ(tab[0].first, tab[0].second, len) && equ(tab[1].first, tab[1].second, len))
			|| (equ(tab[2].first, tab[2].second, len) && equ(tab[3].first, tab[3].second, len)
			)
		;
	}
}
char a[MN], b[MN];
int main()
{
	scanf("%s%s", a, b);
	if (equ(a, b, strlen(a)))
		printf("YES\n");
	else
		printf("NO\n");
}