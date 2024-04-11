# include <cstdio>
# include <cstring>
const int MN = 1e6 + 44;
const int A = 1 << 8;
int head = 0, tail = 0;
char up[MN], left[MN];
int cou[A][A];
// ile w biecym przedziale jest pl izolowanych jeli poprzedni wiersz to [0], a biecy to [1]
int n, m;
void edit(int pos, int val)
{
	cou[up[pos]][up[pos - 1]] += val;
}
char letters[3] = {'R', 'G', 'B'};
int main()
{
	scanf("%s%s", up, left);
	n = strlen(up), m = strlen(left);
	int head = 0, tail = 0; //przedzia dostpny to [tail, head]
	long long res = 0;
	for (int i = 0; i < m; ++i)
	{
		while (head < n - 1 && up[head] != left[i])
		{
			head ++;
			edit(head, + 1);
		}
// 		printf("in %d: %d - %d\n", i, tail, head);
		if (i == 0 || left[i - 1] == left[i])
			res += head - tail + 1;
		else
			res += head - tail + 1 - cou[left[i - 1]][left[i]];
		
		if (head < n - 1)
		{
			head ++;
			edit(head, +1);
		}
		if (up[tail] == left[i])
		{
			edit(tail, -1);
			tail ++;
		}
	}
	printf("%I64d\n", res);
}