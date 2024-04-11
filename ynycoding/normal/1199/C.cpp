#include <cstdio>
#include <algorithm>
#define  MAXN 400005
int n, s, a[MAXN], b[MAXN], top, mx, cur;
int main()
{
	scanf("%d%d", &n, &s);
	s*=8;
	s/=n;
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	std::sort(a+1, a+n+1);
	if(s>=20) return puts("0"), 0;
	else s=1<<s;
	if(s>=n) return puts("0"), 0;
	a[0]=-1;
	for(int i=1; i<=n; ++i) if(a[i]==a[i-1]) ++b[top]; else b[++top]=1;
//	for(int i=1; i<=top; ++i) printf("%d\n", b[i]);
	if(s>=top) return puts("0"), 0;
	for(int i=1; i<s; ++i) cur+=b[i];
	for(int i=1; i+s-1<=top; ++i)
	{
		cur+=b[i+s-1]-b[i-1];
		mx=std::max(mx, cur);
	}
	printf("%d\n", n-mx);
	return 0;
}