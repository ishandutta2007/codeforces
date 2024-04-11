# include <cstdio>
const int MM = 105;
const int MOD = 1e9 + 7;
int mod;
struct data
{
	int cou[MM];
	data()
	{
		for (int i = 0; i < MM; ++i)
			cou[i] = 0;
	}
	void mul(int c)
	{
		int copy[MM];
		for (int i = 0; i < mod; ++i)
			copy[i] = cou[i];
		for (int i = 0; i < mod; ++i)
			cou[i] = 0;
		for (int i = 0; i < mod; ++i)
		{
			cou[i * c % mod] += copy[i];
			cou[i * c % mod] %= MOD;
		}
	}
};
data operator * (data a, data b)
{
	data res;
	for (int i = 0; i < mod; ++i)
		for (int k = 0; k < mod; ++k)
			res.cou[(i + k) % mod] = (res.cou[(i + k) % mod] + (long long) a.cou[i] * b.cou[k]) % MOD;
	return res;
}
long long pow(int base, int e)
{
	if (e == 0)
		return 1;
	else if (e % 2)
	{
		return pow(base, e - 1) * base % mod;
	}
	else
	{
		long long h = pow(base, e/2);
		return h * h % mod;
	}
}
data in;
data datapow(int e)
{
	if (e == 0)
	{
		data out;
		out.cou[0] = 1;
		return out;
	}
	else if (e % 2)
	{
		data left = datapow(e - 1);
		left.mul(10);
		return left * in;
	}
	else
	{
		data half = datapow(e / 2);
		data half2 = half;
		half.mul(pow(10, e / 2));
		return half * half2;
	}
}
int main()
{
	int n, b, k;
	scanf("%d%d%d%d", &n, &b, &k, &mod);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		in.cou[x % mod]++;
	}
// 	for (int i = 0; i < mod; ++i)
// 		printf("%d.%d\n", i, (in*in).cou[i]);
	printf("%d\n", datapow(b).cou[k]);
}