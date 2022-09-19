# include <cstdio>
# include <set>
using namespace std;
FILE * in, * out;
const int MN = 1e5 + 44;
const int A = 26;
char s[MN], t[MN];
int cou[A];
int left[A];
int main()
{
// 	in = stdin;
// 	out = stdout;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	fscanf(in, "%s%s", s, t);
	for (int i = 0; s[i]; ++i)
	{
		cou[s[i] - 'A'] ++;
		cou[t[i] - 'A'] --;
		left[s[i] - 'A'] ++;
	}
	int z = 0;
	for (int i = 0; i < A; ++i)
		z += max(0, cou[i]);
	for (int i = 0; s[i]; ++i)
	{
		char letter = s[i];
		if (cou[letter - 'A'] <= 0)
			continue;
		char swap;
		for (int k = 0; k < A; ++k)
			if (cou[k] < 0)
			{
				swap = 'A' + k;
				break;
			}
		if (letter > swap || left[letter - 'A'] == cou[letter - 'A'])
		{
			cou[swap - 'A'] ++;
			cou[letter - 'A'] --;
			s[i] = swap;
		}
		left[letter - 'A']--;
	}
	fprintf(out, "%d\n%s\n", z, s);
	fclose(in);
	fclose(out);
}