# include <cstdio>
# include <set>
const int MN = 2e5 + 44;
char plus[MN];
char minus[MN];
void inc(char nr[], int pos)
{
	nr[pos] ++;
	while (nr[pos] == 2)
	{
		nr[pos] = 0;
		nr[pos + 1] ++;
		pos ++;
	}
}
void show(char nr[])
{
	bool in = false;
	for (int i = MN - 1; i >= 0; --i)
	{
		if (nr[i])
			in = true;
		if (in)
			printf("%d", nr[i]);
	}
	printf("\n");
}
char diff[MN];
int poly[MN];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; ++i)
	{
		int a;
		scanf("%d", &a);
		poly[i] = a;
		bool positive = a > 0;
		if (a < 0)
			a = -a;
		for (int bit = 0; bit <= 30; ++bit)
			if ((1 << bit) & a)
				if (positive)
					inc(plus, bit + i);
				else
					inc(minus, bit + i);
	}
// 	show(plus);
// 	show(minus);
	bool neg = false;
	for (int i = MN - 1; i >= 0; --i)
		if (plus[i] != minus[i])
		{
			neg = (plus[i] < minus[i]);
			break;
		}
	if (neg)
	{
		for (int i = 0; i <= n; ++i)
			poly[i] = -poly[i];
		for (int i = 0; i < MN; ++i)
			std::swap(minus[i], plus[i]);
	}
	for (int i = 0; i < MN; ++i)
	{
		if (plus[i] < minus[i])
		{
			plus[i] += 2;
			plus[i + 1]--;
		}
		diff[i] = plus[i] - minus[i];
	}
// 	printf("eee\n");
// 	show(diff);
	int first = -1, last = -1;
	for (int i = 0; i < MN; ++i)
		if (diff[i])
		{
			last = i;
			if (first == -1)
				first = i;
		}
// 	printf("%d - %d\n", first, last);
	if (last - first > 32)
		printf("0\n");
	else
	{
		int res = 0;
		long long val = 0;
		for (int i = 0; i <= last - first; ++i)
			if (diff[i + first])
				val += (1LL << i);
// 		printf("val = %I64d\n", val);
		for (int i = 0; i <= first && i <= 31; ++i)
		{
			if (first - i <= n)
			{
// 			printf("check pos %d\n", first - i);
				long long newval = poly[first - i] - val * (1LL << i);
	// 			printf("newval = %I64d\n", newval);
				if (newval <= k && newval >= -k && (newval || first - i != n))
					res++;
			}
		}
		printf("%d\n", res);
	}
}