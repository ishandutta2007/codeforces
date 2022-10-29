#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN=100005;

typedef long long LL;

struct node
{
	int l, r;
	LL d;
};

LL A[MAXN], sum[MAXN];
node opt[MAXN];
int N, M, K;

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for (int i=1; i<=N; i++) scanf("%I64d", &A[i]);
	for (int i=1; i<=M; i++) scanf("%d%d%I64d", &opt[i].l, &opt[i].r, &opt[i].d);
	memset(sum, 0, sizeof(sum));
	for (int l, r, i=1; i<=K; i++)
	{
		scanf("%d%d", &l, &r);
		sum[l]++; sum[r+1]--;
	}
	for (int i=1; i<=M; i++) 
	{
		sum[i]+=sum[i-1];
		opt[i].d*=sum[i];
	}
	memset(sum, 0, sizeof(sum));
	for (int i=1; i<=M; i++)
	{
		sum[opt[i].l]+=opt[i].d;
		sum[opt[i].r+1]-=opt[i].d;
	}
	for (int i=1; i<=N; i++)
	{
		sum[i]+=sum[i-1];
		A[i]+=sum[i];
		printf("%I64d", A[i]);
		if (i==N) puts("");
		else putchar(' ');
	}
	return 0;
}