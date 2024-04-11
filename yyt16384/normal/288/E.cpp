#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int BASE = 10;
const int DIGIT1 = 4;
const int DIGIT2 = 7;
const int MOD = 1000000007;

int n;
int a1[MAXN];
int a2[MAXN];
int *a;
int pows[MAXN];
int ones[MAXN];
int last[MAXN];
int las2[MAXN];
int sum0[MAXN];
int sum1[MAXN];
int sum2[MAXN];

void init()
{
	char s1[MAXN];
	char s2[MAXN];
	scanf("%s%s", s1, s2);
	n = strlen(s1);
	for (int i = 0; i < n; ++i)
		a1[i] = (s1[i] == '0' + DIGIT2);
	for (int i = 0; i < n; ++i)
		a2[i] = (s2[i] == '0' + DIGIT2);
}

void work_pows()
{
	pows[0] = 1;
	for (int i = 0; i < n; ++i)
		pows[i + 1] = (long long)pows[i] * BASE % MOD;
}

void work_ones()
{
	ones[0] = 0;
	for (int i = 0; i < n; ++i)
		ones[i + 1] = ((long long)ones[i] * BASE + 1) % MOD;
}

void work_last()
{
	last[0] = 0;
	for (int i = 0; i < n; ++i)
		last[i + 1] = ((long long)last[i] * BASE + (a[i] ? DIGIT2 : DIGIT1)) % MOD;
}

void work_las2()
{
	for (int i = 0, lastone = -1; i < n; ++i)
	{
		if (a[i])
			lastone = i;
		int part1 = last[i + 1];
		int part2 = ((long long)(DIGIT1 - DIGIT2) * pows[i - lastone] % MOD + MOD) % MOD;
		int part3 = (long long)(DIGIT2 - DIGIT1) * ones[i - lastone] % MOD;
		las2[i] = ((long long)part1 + part2 + part3) % MOD;
	}
}

void work_sum0()
{
	sum0[0] = 0;
	for (int i = 0; i < n; ++i)
		sum0[i + 1] = (sum0[i] * 2 + a[i]) % MOD;
}

void work_sum1()
{
	sum1[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int part1 = (long long)sum1[i] * BASE * 2 % MOD;
		int part2 = (long long)sum0[i] * (DIGIT1 + DIGIT2) % MOD;
		int part3 = a[i] * las2[i];
		sum1[i + 1] = ((long long)part1 + part2 + part3) % MOD;
	}
}

void work_sum2()
{
	sum2[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int part1 = (long long)sum2[i] * BASE * BASE * 2 % MOD;
		int part2 = (long long)sum1[i] * BASE * 2 * (DIGIT1 + DIGIT2) % MOD;
		int part3 = (long long)sum0[i] * (DIGIT1 * DIGIT1 + DIGIT2 * DIGIT2) % MOD;
		int part4 = (long long)a[i] * las2[i] * las2[i] % MOD;
		sum2[i + 1] = ((long long)part1 + part2 + part3 + part4) % MOD;
	}
}

int work_ans()
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int tpart1 = (sum2[i] + (long long)a[i] * last[i] * last[i]) % MOD;
		int part1 = (long long)tpart1 * pows[n - i] % MOD * pows[n - i] % MOD;
		int tpart2 = (sum1[i] + a[i] * last[i]) % MOD;
		int part2 = (long long)tpart2 * pows[n - i] % MOD * (DIGIT1 + DIGIT2) % MOD * ones[n - i] % MOD;
		int tmp1 = (long long)DIGIT1 * DIGIT2 * ones[n - i] % MOD * ones[n - i] % MOD;
		int tmp2 = (long long)(DIGIT1 - DIGIT2) * (DIGIT1 - DIGIT2) * ones[n - i - 1] % MOD * pows[n - i - 1] % MOD;
		int tmp = (tmp1 + tmp2) % MOD;
		int tpart3 = (sum0[i] + a[i]) % MOD;
		int part3 = (long long)tpart3 * tmp % MOD;
		ans = ((long long)ans + part1 + part2 + part3) % MOD;
	}
	return ans;
}

int getans()
{
	work_pows();
	work_ones();
	work_last();
	work_las2();
	work_sum0();
	work_sum1();
	work_sum2();
	return work_ans();
}

void solve()
{
	a = a1;
	int ans1 = getans();
	a = a2;
	int ans2 = getans();
	int ans = (ans2 - ans1 + MOD) % MOD;
	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9194.in", "r", stdin);
	freopen("9194.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}