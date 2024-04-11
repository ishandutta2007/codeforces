#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXLOGN = 17;
const int SZ = 26;
const int BASE = 33;
const int MOD = 1049172637;

int n;
int a[MAXN];
int pw[MAXN];
int hash[MAXN];
int sum[SZ][MAXN];
int f[MAXN];
int gch[MAXLOGN][MAXN];
int gch2[MAXLOGN][MAXN];
long long gw[MAXN][SZ];
long long gs[MAXN];

void input()
{
	static char s[MAXN];
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i)
		a[i] = s[i] - 'a';
}

void init()
{
	pw[0] = 1;
	for (int i = 0; i < n; ++i)
		pw[i + 1] = (long long)pw[i] * BASE % MOD;
	hash[0] = 0;
	for (int i = 0; i < n; ++i)
		hash[i + 1] = ((long long)hash[i] * BASE + a[i]) % MOD;
	for (int i = 0; i < SZ; ++i)
	{
		sum[i][0] = 0;
		for (int j = 0; j < n; ++j)
			sum[i][j + 1] = sum[i][j] + (a[j] == i);
	}
}

void solve()
{
	long long ans = n;
	long long maxadd = 0;
	for (int i = 0; i < MAXLOGN; ++i)
		for (int j = 0; j < n; ++j)
			gch[i][j] = j;
	memset(gch2, -1, sizeof(gch2));
	for (int i = 1; i < MAXLOGN; ++i)
	{
		int len = (1 << (i + 1)) - 1;
		long long len2 = (long long)len * len;
		int halflen = (1 << i) - 1;
		for (int j = (1 << i) - 1; j <= n - (1 << i); ++j)
		{
			int l = j - (1 << i) + 1;
			int r = j + (1 << i);
			int sumx = sum[a[j]][r] - sum[a[j]][l];
			bool fl = (f[j - (1 << (i - 1))] >= i - 1);
			bool fr = (f[j + (1 << (i - 1))] >= i - 1);
			int hashl = ((hash[j] - (long long)pw[halflen] * hash[l]) % MOD + MOD) % MOD;
			int hashr = ((hash[r] - (long long)pw[halflen] * hash[j + 1]) % MOD + MOD) % MOD;
			if (fl && hashl == hashr)
			{
				if (sumx == 1)
				{
					f[j] = i;
					gs[l] -= len2;
					gs[r] += len2;
					for (int p = 0; p < SZ; ++p)
						if (sum[p][r] - sum[p][l] == 0)
						{
							gw[j][p] += len2;
						}
					ans += len2;
				}
				else
				{
					for (int p = 0; p < SZ; ++p)
						if (sum[p][r] - sum[p][l] == 0)
						{
							gw[j][p] += len2;
						}
				}
			}
			else
			{
				bool flag = false;
				if (fl)
				{
					sumx = sum[a[j]][j + 1] - sum[a[j]][l];
					if (sumx == 1)
					{
						int chid = gch[i - 1][j + (1 << (i - 1))];
						int chrp = chid - (j + 1);
						int chpw = pw[r - chid - 1];
						int chdt = (a[l + chrp] - a[chid] + MOD) % MOD;
						int thash = hashr;
						hashr = (hashr + (long long)chpw * chdt) % MOD;
						if (hashl == hashr)
						{
							gch[i][j] = chid;
							gw[chid][a[l + chrp]] += len2;
							flag = true;
						}
						hashr = thash;
						if (gch2[i - 1][j + (1 << (i - 1))] != -1)
						{
							chid = gch2[i - 1][j + (1 << (i - 1))];
							chrp = chid - (j + 1);
							chpw = pw[r - chid - 1];
							chdt = (a[l + chrp] - a[chid] + MOD) % MOD;
							hashr = (hashr + (long long)chpw * chdt) % MOD;
							if (hashl == hashr)
							{
								gch[i][j] = chid;
								gw[chid][a[l + chrp]] += len2;
								flag = true;
							}
							hashr = thash;
						}
					}
				}
				if (fr)
				{
					sumx = sum[a[j]][r] - sum[a[j]][j];
					if (sumx == 1)
					{
						int chid = gch[i - 1][j - (1 << (i - 1))];
						int chrp = chid - l;
						int chpw = pw[j - chid - 1];
						int chdt = (a[j + 1 + chrp] - a[chid] + MOD) % MOD;
						int thash = hashl;
						hashl = (hashl + (long long)chpw * chdt) % MOD;
						if (hashl == hashr)
						{
							if (!flag)
								gch[i][j] = chid;
							else
								gch2[i][j] = chid;
							gw[chid][a[j + 1 + chrp]] += len2;
						}
						hashl = thash;
						if (gch2[i - 1][j - (1 << (i - 1))] != -1)
						{
							chid = gch2[i - 1][j - (1 << (i - 1))];
							chrp = chid - l;
							chpw = pw[j - chid - 1];
							chdt = (a[j + 1 + chrp] - a[chid] + MOD) % MOD;
							hashl = (hashl + (long long)chpw * chdt) % MOD;
							if (hashl == hashr)
							{
								if (!flag)
									gch[i][j] = chid;
								else
									gch2[i][j] = chid;
								gw[chid][a[j + 1 + chrp]] += len2;
							}
							hashl = thash;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
		gs[i + 1] += gs[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < SZ; ++j)
			if (j != a[i])
			{
				if (gw[i][j] + gs[i] > maxadd)
					maxadd = gw[i][j] + gs[i];
			}

	printf("%"LLFORMAT"d\n", ans + maxadd);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9181.in", "r", stdin);
	freopen("9181.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}