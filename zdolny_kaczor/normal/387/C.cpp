# include <cstdio>
# include <cstring>
const int MN = 1e5 + 44;
char num[MN];
bool isGreaterOrEqual(int p1, int p2, int len)
{
	for (int i = 0; i < len; ++i)
		if (num[p1 + i] < num[p2 + i])
			return false;
		else if (num[p1 + i] > num[p2 + i])
			return true;
	return true;
}
int main()
{
	scanf("%s", num);
	int n = strlen(num);
	int res = 1;
	int len = 1;
	for (int i = 1; i < n; ++i)
	{
// 		printf("in %d res = %d len = %d\n", i, res, len);
		if (num[i] == '0')
		{
			len++;
			if (len * 2 > i + 1 || (len * 2 == i + 1 && !isGreaterOrEqual(0, len, len)))
			{
// 				printf("is not good\n");
				res = 1;
				len = i + 1;
			}
		}
		else
		{
			if (i != 1 || num[0] >= num[1])
				res++;
			len = 1;
		}
	}
	printf("%d\n", res);
}