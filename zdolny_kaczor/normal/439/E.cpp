# include <cstdio>
# define MOD 1000000007
long long pow (long long b, int exp)
{
	if (exp==0)
		return 1;
	else if (exp%2)
		return b*pow(b, exp-1)%MOD;
	else
	{
		long long half=pow(b, exp/2);
		return half*half%MOD;
	}
}
# define SIZE 100010
long long int fact[SIZE];
long long int inv[SIZE];
long long bin(int n, int k)
{
	if (n<0 || n<k || k<0)
		return 0;
	return fact[n]*inv[k]%MOD*inv[n-k]%MOD;
}
int main()
{
	fact[0]=1;
	for (int i=1; i<SIZE; ++i)
		fact[i]=fact[i-1]*i%MOD;
	for (int i=0; i<SIZE; ++i)
		inv[i]=pow(fact[i], MOD-2);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int f, n;
		scanf("%d%d", &n, &f);
		int div[6];
		int amo=0;
		int nn=n;
		for (int i=2; i*i<=nn; ++i)
		{
			if (nn%i==0)
			{
				while (nn%i==0)
					nn/=i;
				div[amo]=i;
				amo++;
			}
		}
		if (nn>1)
		{
			div[amo]=nn;
			amo++;
		}
		long long res=0;
		for (int mask=0; mask<(1<<amo); ++mask)
		{
			int divi=1;
			int deg=0;
			for (int k=0; k<amo; ++k)
				if (mask&(1<<k))
				{
					deg++;
					divi*=div[k];
				}
			if (deg%2==0)
			{
				res+=bin(n/divi-1, f-1);
			}
			else
			{
				res+=MOD-bin(n/divi-1, f-1);
			}
			res%=MOD;
		}
		printf("%I64d\n", res);
	}
}