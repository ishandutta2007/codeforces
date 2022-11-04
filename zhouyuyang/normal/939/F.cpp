#include <cstdio>
#include <algorithm>
int N, K, L[101], R[101], f[100001], g0[100001], g1[100001], g2[100001], q[555555];
inline int F(int x)
{
	return x < 0 || x > N ? 1000000000 : f[x];
}
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= K; i++)
		scanf("%d%d", L + i, R + i);
	for (int i = 1; i <= N; i++)
		f[i] = 1000000000;
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
			g0[j] = F(j - R[i] + R[i - 1]);
		int H = 1, T = 0;
		for (int j = 0; j <= N; j++)
		{
			while (H <= T && F(q[T]) >= F(j - L[i] + R[i - 1]))
				T--;
			q[++T] = j - L[i] + R[i - 1];
			while (H <= T && q[H] < j - R[i] + R[i - 1])
				H++;
			g2[j] = F(q[H]);
		}
		H = 1, T = 0;
		for (int j = 0; j <= N; j++)
		{
			while (H <= T && F(q[T]) >= F(R[i - 1] - j))
				T--;
			q[++T] = R[i - 1] - j;
			while (H <= T && q[H] > R[i - 1] - j + R[i] - L[i])
				H++;
			g1[j] = F(q[H]);
		}
		for (int j = 0; j <= N; j++)
			f[j] = std::min(std::min(g0[j], g1[j] + 1), g2[j] + 2);
	}
	if (F(R[K] - N) >= 1000000000)
		puts("Hungry");
	else
		printf("Full\n%d\n", F(R[K] - N));
	return 0;
}