#include <cstdio>
#include <algorithm>
const int N=10005;
int L, R, lim=21, val[N];
int stk[N][3], top;
inline void add(int a, int b, int c)
{
	stk[++top][0]=a, stk[top][1]=b, stk[top][2]=c;
}
int main()
{
	scanf("%d%d", &L, &R);
	puts("YES");
	val[1]=1;
	for(int i=2; i<=lim; ++i)
	{
		for(int j=1; j<i; ++j) val[i]+=val[j], add(j, i, val[j]);
	}
	R-=L;
	int a=0;
	for(int i=lim; i>1; --i) if(R>=val[i])
	{
		R-=val[i];
		add(i, lim+1, L+a);
		a+=val[i];
	}
	add(1, lim+1, L);
	printf("%d %d\n", lim+1, top);
	for(int i=1; i<=top; ++i) printf("%d %d %d\n", stk[i][0], stk[i][1], stk[i][2]);
	return 0;
}