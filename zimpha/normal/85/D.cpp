#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

typedef long long LL;

const int MAXN=100005;

struct node
{
	char c;
	int x;
}opt[MAXN];

LL sum[MAXN*4][5];
int num[MAXN*4];
int A[MAXN];
int N;

int find(int A[], int l, int r, int x)
{
	while (l<=r)
	{
		int m=(l+r)>>1;
		if (A[m]==x) return m;
		if (A[m]<x) l=m+1;
		else r=m-1;
	}
	return -1;
}

inline void update(int rt)
{
	num[rt]=num[lson]+num[rson];
	for (int i=0; i<5; i++)
		sum[rt][i]=sum[lson][i]+sum[rson][(i+10-num[lson]%5)%5];
}

void modify(int rt, int l, int r, int id, int d)
{
	if (l==r)
	{
		if (d==1) sum[rt][0]=A[id], num[rt]=1;
		else sum[rt][0]=0, num[rt]=0;
		return;
	}
	if (id<=mid) modify(lson, l, mid, id, d);
	else modify(rson, mid+1, r, id, d);
	update(rt);
}

int main()
{
	scanf("%d", &N);
	int M=0;
	for (int i=1; i<=N; i++)
	{
		char str[10];
		scanf("%s", str);
		opt[i].c=str[0];
		if (str[0]=='a'||str[0]=='d') 
		{
			scanf("%d", &opt[i].x);
			A[++M]=opt[i].x;
		}
	}
	std::sort(A+1, A+1+M);
	int tmp=M; M=1;
	for (int i=2; i<=tmp; i++)
		if (A[i]!=A[i-1]) A[++M]=A[i];
	memset(sum, 0, sizeof(sum));
	memset(num, 0, sizeof(num));
	for (int i=1; i<=N; i++)
	{
		int id=find(A, 1, M, opt[i].x);
		if (opt[i].c=='a') modify(1, 1, M, id, 1);
		else if (opt[i].c=='d') modify(1, 1, M, id, -1);
		else printf("%I64d\n", sum[1][2]);
	}
	return 0;
}