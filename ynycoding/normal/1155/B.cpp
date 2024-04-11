#include <cstdio>
#define MAXN 100005
int n, a[MAXN], cnt, st, idx=1;
char s[MAXN];
int main()
{
	scanf("%d%s", &n, s);
	for(int i=1; i<=n; ++i) a[i]=s[i-1]-'0', cnt+=a[i]==8;
	if((n-11)/2>=cnt) return puts("NO"), 0;
	st=(n-11)/2;
	for(int i=0; i<=st; i+=a[idx]==8, ++idx);
	idx-=2;
	puts(idx-(n-10)/2-st>0?"NO":"YES");
	return 0;
}