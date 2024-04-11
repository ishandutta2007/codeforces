#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1 << 18;

int T[2 * N];

int D[2 * N];

const int inf = 1e9;

inline void push(int v)
{
	if (v >= N)
	{
		T[v] += D[v];
		D[v] = 0;
	}
	else
	{
		D[2 * v] += D[v];
		D[2 * v + 1] += D[v];
		T[v] += D[v];
		D[v] = 0;
	}
}


#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int add(int l, int r, int L, int R, int v, int d)
{
	if (r < L || l > R)
		return T[v] + D[v];
	if (l <= L && R <= r)
	{
		D[v] += d;
		return T[v] + D[v];
	}
	else
	{
		push(v);
		return T[v] = min(
			add(l, r, L, (L + R) / 2, 2 * v, d),
			add(l, r, (L + R) / 2 + 1, R, 2 * v + 1, d)
		);
	}
}

int n, k, h;

int B[N];

void add(int x, int d)
{
	int p = lower_bound(B, B + k, h - x) - B;
	if (p < k)
		add(p + 1, k, 1, N, 1, d);
}

int cur()
{
	push(1);
	return T[1];
}

int A[N];

int main()
{
	scanf("%d %d %d", &n, &k, &h);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &B[i]);
	}
	sort(B, B + k);
	for (int i = N; i < N + k; i++)
	{
		T[i] = -(i - N + 1);
	}
	for (int i = N + k; i < 2 * N; i++)
		T[i] = inf;
	for (int i = N - 1; i > 0; i--)
		T[i] = min(T[2 * i], T[2 * i + 1]);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < k - 1; i++)
	{
		add(A[i], 1);
	}
	int ans = 0;
	for (int i = k - 1; i < n; i++)
	{
		add(A[i], 1);
		int v = cur();
		if (v >= 0)
		{
			//eprintf("[%d,%d] -> ok\n", i - k + 1, i);
			ans++;
		}
		add(A[i - k + 1], -1);
	}
	printf("%d\n", ans);
	return 0;
}