# include <cstdio>
# include <cstring>
const int MN = 3e5 + 44;
int len;
char text[MN];
const int MA = 1 << 8;
int lcou[MA];
int amo_;
void reset()
{
	for (int i = 0; i < MA; ++i)
		lcou[i] = 0;
	amo_ = 0;
}
void insert(int x, int val)
{
// 	printf("insert %c %d\n", x, val);
	if (lcou[x])
		amo_ --;
	lcou[x] += val;
	if (lcou[x])
		amo_ ++;
}
int amo()
{
	return amo_;
}
long long belowcou(int x)
{
// 	printf("belowcou (%d)\n", x);
	reset();
	long long res = 0;
	int head = 0, tail = 0;
	for (; tail < len; insert(text[tail], -1), ++tail) // [head, tail) is good while [head, tail] is not
	{
// 		printf("next\n");
		while (head < len && amo() <= x)
		{
			insert(text[head], +1);
			head++;
		}
		if (amo() > x)
		{
			head --;
			insert(text[head], -1);
		}
		res += head - tail;
	}
// 	printf("return %d\n", (int) res);
	return res;
}
long long res[MA];
int main()
{
	scanf("%s", text);
	len = strlen(text);
	for (int i = 1; i <= 26; ++i)
		res[i] = belowcou(i);
	reset();
	for (int i = 0; i < len; ++i)
		insert(text[i], 1);
	printf("%d\n", amo());
	for (int i = 1; i <= 26; ++i)
	{
		long long v = res[i] - res[i - 1];
		if (v == 0)
			break;
		printf("%I64d\n", v);
	}
}