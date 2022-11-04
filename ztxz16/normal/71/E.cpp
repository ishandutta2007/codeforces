#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

string str[105] = {
"H",
"He",
"Li",
"Be",
"B",
"C",
"N",
"O",
"F",
"Ne",
"Na",
"Mg",
"Al",
"Si",
"P",
"S",
"Cl",
"Ar",
"K",
"Ca",
"Sc",
"Ti",
"V",
"Cr",
"Mn",
"Fe",
"Co",
"Ni",
"Cu",
"Zn",
"Ga",
"Ge",
"As",
"Se",
"Br",
"Kr",
"Rb",
"Sr",
"Y",
"Zr",
"Nb",
"Mo",
"Tc",
"Ru",
"Rh",
"Pd",
"Ag",
"Cd",
"In",
"Sn",
"Sb",
"Te",
"I",
"Xe",
"Cs",
"Ba",
"La",
"Ce",
"Pr",
"Nd",
"Pm",
"Sm",
"Eu",
"Gd",
"Tb",
"Dy",
"Ho",
"Er",
"Tm",
"Yb",
"Lu",
"Hf",
"Ta",
"W",
"Re",
"Os",
"Ir",
"Pt",
"Au",
"Hg",
"Tl",
"Pb",
"Bi",
"Po",
"At",
"Rn",
"Fr",
"Ra",
"Ac",
"Th",
"Pa",
"U",
"Np",
"Pu",
"Am",
"Cm",
"Bk",
"Cf",
"Es",
"Fm"};

map <string, int> val;
vector <int> can[105];
int v[105], a[105], vv[200005], f[20][200005], pre[20][200005];
int n, k, full;
string st[105], end[105];

void dfs(int i, int j);

int main()
{
	for (int i = 0; i < 100; i++)
		val[str[i]] = i + 1;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		char ss[105];
		scanf("%s", ss + 1);
		string snow = ss + 1;
		v[i] = val[snow];
		st[i] = snow;
	}
	
	for (int i = 1; i <= k; i++)
	{
		char ss[105];
		scanf("%s", ss + 1);
		string snow = ss + 1;
		a[i] = val[snow];
		end[i] = snow;
	}
	
	full = (1 << n) - 1;
	for (int i = 0; i <= full; i++)
	{
		int snow = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				snow += v[j + 1];
		}
		
		vv[i] = snow;
	}
	
	f[0][0] = 1;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j <= full; j++)
		{
			if (f[i][j] == 0)
				continue;
			for (int x = full - j; x; x = (x - 1) & (full - j))
			{
				if (vv[x] == a[i + 1])
				{
					f[i + 1][j | x] = 1;
					pre[i + 1][j | x] = x;
				}
			}
		}
	}
	
	if (f[k][full])
	{
		printf("YES\n");
		dfs(k, full);
	}
	
	else
		printf("NO\n");
	return 0;
}

void dfs(int i, int j)
{
	if (i == 0)
		return;
	dfs(i - 1, j - pre[i][j]);
	int now = pre[i][j], tag = 1;
	for (int x = 0; x < n; x++)
		if (now & (1 << x))
		{
			if (tag == 1)
				printf("%s", st[x + 1].c_str()), tag = 0;
			else
				printf("+%s", st[x + 1].c_str());
		}
	printf("->%s\n", end[i].c_str());
}