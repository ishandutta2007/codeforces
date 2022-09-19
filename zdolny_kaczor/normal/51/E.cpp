# include <cstdio>
const int MN = 1 << 10;
long long m1[MN][MN], m2[MN][MN], m3[MN][MN];//, m5[MN][MN];
void mul(int n, long long a[MN][MN], long long b[MN][MN], long long res[MN][MN])
{
	for (int k = 0; k < n; ++k)
	  for (int i = 0; i <= k; ++i)
		  for (int l = 0; l < n; ++l)
				res[i][k] += a[i][l] * b[l][k];
  for (int i = 0; i < n; ++i)
    for (int k = 0; k < i; ++k)
      res[i][k] = res[k][i];
}
int main()
{
	int n, m; 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		m1[a][b] = m1[b][a] = 1;
	}
	mul(n, m1, m1, m2);
	mul(n, m1, m2, m3);
	long long a = 0, b = 0, c = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k) {
			a += m1[i][k] * m2[i][k];
      b += m2[i][k] * m3[i][k];
    }
		c += m2[i][i] * m3[i][i];
	}
	long long res = (b - c * 5 + 5 * a) / 10;
 	printf("%lld\n", res);
}