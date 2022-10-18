#include <cstdio>
#include <algorithm>
const int N=100005;
int n, q, len[N], per[N], a[10][N];
int stk[N][2], top;
void proc(int *s, int *s1)
{
	int i=1, j, k;
	len[1]=1, per[1]=1;
	while(i<=n)
	{
		j=i+1, k=i;
		int clen=0;
		while(j<=n&&s[j]>=s[k])
		{
			s[j]>s[k]?(k=i, clen=0):(++k, ++clen);
			if(clen==j-k+1) clen=0;
			if(clen)
			{
				len[j]=(k==i?clen:len[k-1]);
				per[j]=(k==i?1:per[k-1]);
			}
			else len[j]=j-k+1, per[j]=(j-i+1)/(j-k+1);
//			printf("len %d %d %d %d %d %d\n", j, len[j], per[j], k, i, clen);
			++j;
		}
		int cper=(j-i)/(j-k);
		while(i<=k) i+=j-k;
		if(i==j)
		{
			len[i]=1, per[i]=1;
//		printf("flen %d %d %d\n", i, len[i], per[i]);
//			len[i]=i-k;
//			per[i]=cper;
		}
	}
	top=0;
	for(int i=n, pr=1; i>1; --i)
	{
		if(pr==1) stk[++top][0]=i-len[i]+1, stk[top][1]=i, pr=len[i];
		else stk[++top][0]=i-len[i]*per[i]+1, stk[top][1]=i, pr=len[i]*per[i];
//		printf("copy %d %d\n", stk[top][0], stk[top][1]);
	}
	stk[++top][0]=1, stk[top][1]=1;
	int tp=0;
	for(int i=top; i&&tp<n; --i)
	{
		int l=stk[i][0], r=stk[i][1];
		std::copy(s+l, s+std::min(l+n-tp, r+1), s1+tp+1);
		tp+=r-l+1;
	}
//	for(int i=1; i<=n; ++i) printf("%d ", s1[i]);
//	puts("");
}
int main()
{
//	freopen("in.in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a[0]+i);
//	for(int i=1; i<=n; ++i) printf("%d ", a[0][i]);
//	puts("");
	for(int i=1; i<=7; ++i) proc(a[i-1], a[i]);
	scanf("%d", &q);
	for(int i=1, x, y; i<=q; ++i)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", a[std::min(x, 7)][y]);
	}
	return 0;
}