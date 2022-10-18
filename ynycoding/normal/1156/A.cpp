#include <cstdio>
int n, pre, pre1, a, cnt;
int main()
{
	scanf("%d", &n);
	scanf("%d", &pre);
	for(int i=2; i<=n; ++i)
	{
		scanf("%d", &a);
		if((pre==3&&a==2)||(pre==2&&a==3)) return puts("Infinite"), 0;
		if(a==1) cnt+=pre==2?3:4;
		if(a==2) cnt+=pre==1&&pre1==3?2:3;
		if(a==3) cnt+=4;
		pre1=pre;
		pre=a;
	}
	puts("Finite");
	printf("%d\n", cnt);
	return 0;
}