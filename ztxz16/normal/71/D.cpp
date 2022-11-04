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

string suit = "CDHS", J1 = "J1", J2 = "J2";
string rank = "23456789TJQKA";
string card[105], cc[105][105];
int tot, n, m, ansa, ansb, ansc, ansd;
map <string, pair <int, int> > s;

int check();
void print();

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char str[16];
			scanf("%s", str + 1);
			string snow = str + 1;
			s[snow] = make_pair(i, j);
			cc[i][j] = snow;
		}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
		{
			string snow = "";
			snow += rank[j];
			snow += suit[i];
			if (s.find(snow) == s.end())
				card[++tot] = snow;
		}
	if (s.find(J1) != s.end())
	{
		if (s.find(J2) != s.end())
		{
			for (int k = 1; k <= tot; k++)
				for (int l = 1; l <= tot; l++)
				{
					if (l == k)
						continue;
					cc[s[J1].first][s[J1].second] = card[k];
					cc[s[J2].first][s[J2].second] = card[l];
					if (check())
					{
						printf("Solution exists.\n");
						printf("Replace J1 with %s and J2 with %s.\n", card[k].c_str(), card[l].c_str());
						print();
						return 0;
					}
				}
		}
		
		else
		{
			for (int k = 1; k <= tot; k++)
			{
				cc[s[J1].first][s[J1].second] = card[k];
				if (check())
				{
					printf("Solution exists.\n");
					printf("Replace J1 with %s.\n", card[k].c_str());
					print();
					return 0;
				}
			}
		}
	}
	
	else
	{
		if (s.find(J2) != s.end())
		{
			for (int k = 1; k <= tot; k++)
			{
				cc[s[J2].first][s[J2].second] = card[k];
				if (check())
				{
					printf("Solution exists.\n");
					printf("Replace J2 with %s.\n", card[k].c_str());
					print();
					return 0;
				}
			}
		}
		
		else
		{
			if (check())
			{
				printf("Solution exists.\n");
				printf("There are no jokers.\n");
				print();
				return 0;
			}
		}
	}
	
	printf("No solution.\n");
	return 0;
}

int check()
{
	set <string> ss;
	set <char> s1, s2, s3, s4;
	for (int a = 1; a + 2 <= n; a++)
		for (int b = 1; b + 2 <= m; b++)
			for (int c = 1; c + 2 <= n; c++)
				for (int d = 1; d + 2 <= m; d++)
				{
					ss.clear(), s1.clear(), s2.clear(), s3.clear(), s4.clear();
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
						{
							string str1 = cc[a + i][b + j], str2 = cc[c + i][d + j];
							ss.insert(str1), ss.insert(str2);
							s1.insert(str1[0]), s2.insert(str1[1]);
							s3.insert(str2[0]), s4.insert(str2[1]);
						}
					if (ss.size() == 18 && (s1.size() == 9 || s2.size() == 1) && (s3.size() == 9 || s4.size() == 1))
					{
						ansa = a, ansb = b, ansc = c, ansd = d;
						return 1;
					}
				}
	return 0;
}

void print()
{
	printf("Put the first square to (%d, %d).\n", ansa, ansb);
	printf("Put the second square to (%d, %d).\n", ansc, ansd);
}