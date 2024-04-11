#include <cstdio>
int n;
int main()
{
	scanf("%d", &n);
	n%=4;
	if(n==1) return puts("0 A"), 0;
	if(n==2) return puts("1 B"), 0;
	if(n==3) return puts("2 A"), 0;
	if(n==0) return puts("1 A"), 0;
	return 0;
}