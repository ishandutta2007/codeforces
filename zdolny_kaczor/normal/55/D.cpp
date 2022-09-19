# include <cstdio>
const int mod = 2520;
const int divcou = 48;
const int len = 20;
long long all[len][mod][divcou];
long long smaller[len][mod][divcou];
int digitmask[divcou];
int gcd[mod];
int pow[len];
void init()
{
	pow[0] = 1;
	for (int i = 1; i < len; ++i)
		pow[i] = pow[i - 1] * 10 % mod;
	int nr = 0;
	for (int i = 1; i <= mod; ++i)
		if (mod % i == 0)
		{
			digitmask[nr] = 1 << 0;
			for (int a = 1; a < 10; ++a)
				if (i % a == 0)
					digitmask[nr] |= 1 << a;
			for (int a = 0; a < mod; a+=i)
				gcd[a] = nr;
			nr++;
		}
	for (int a = 0; a < divcou; ++a)
		all[0][0][a] = 1;
	for (int l = 1; l < len; ++l)
		for (int d = 0; d < divcou; ++d)
			for (int r = 0; r < mod; ++r)
				for (int dig = 0; dig < 10; ++dig)
					if (digitmask[d] & (1 << dig))
						all[l][(r + dig * pow[l - 1]) % mod][d] += all[l - 1][r][d];
}
long long cou(long long bound)
{
	for (int i = 0; i < len; ++i)
		for (int k = 0; k < mod; ++k)
			for (int l = 0; l < divcou; ++l)
				smaller[i][k][l] = 0;
	for (int a = 0; a < divcou; ++a)
		smaller[0][0][a] = 1;
	for (int l = 1; l < len; ++l)
	{
		int curr = bound % 10;
		bound /= 10;
		for (int d = 0; d < divcou; ++d)
			for (int r = 0; r < mod; ++r)
			{
				for (int dig = 0; dig < curr; ++dig)
					if (digitmask[d] & (1 << dig))
						smaller[l][(r + dig * pow[l - 1]) % mod][d] += all[l - 1][r][d];
				if (digitmask[d] & (1 << curr))
					smaller[l][(r + curr * pow[l - 1]) % mod][d] += smaller[l - 1][r][d];
			}
	}
	long long res = 0;
	for (int i = 0; i < mod; ++i)
		res += smaller[len - 1][i][gcd[i]];
	return res;
}
int main()
{
	init();
// 	for (int i = 0; i < divcou; ++i)
// 	{
// 		printf("%d:", i);
// 		for (int k = 0; k < 10; ++k)
// 			if (digitmask[i] & (1 << k))
// 				printf("%d", k);
// 		printf("\n");
// 	}
// 	for (int i = 0; i < mod; ++i)
// 		printf("%d.%d\n", i, gcd[i]);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long l, r;
		scanf("%I64d%I64d", &l, &r);
		printf("%I64d\n", cou(r) - cou(l - 1));
	}
}