#include <cstdio>
int q;
inline int gdiv(int x)
{
	for(int i=2; i*i<=x; ++i)
		if(x%i==0) return i;
	return x;
}
inline int solve(int x)
{
	int num=x, p=0;
	while(num) ++p, num>>=1;
	if(x==(1<<p)-1) return x/gdiv(x);
	return (1<<p)-1;
}
int main()
{
	scanf("%d", &q);
	for(int i=1, a; i<=q; ++i) scanf("%d", &a), printf("%d\n", solve(a));
	return 0;
}