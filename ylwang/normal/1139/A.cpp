#include <bits/stdc++.h>
#define R register
#define rint R int
#define fread(a) freopen(a".in", "r", stdin), freopen (a".out", "w", stdout)
using namespace std;

inline int Read()
{
	rint x = 0, f = 1;R char c;
	#define isdigit(x) (x<='9' && x>='0')
	for (c = getchar(); !isdigit(c); c = getchar()) f = c=='-'?-1:f;
	for ( ;isdigit(c); c = getchar()) x = x*10+c-'0';
	return f*x;
}

inline void read(int &x) {return x = Read(), (void)0;}

int n;
int cnt = 0, ans = 0;
char ch;
signed  main()
{
	scanf ("%d\n", &n);
	while (scanf ("%c", &ch) != EOF) 
		cnt ++, ans += (ch-'0')%2==0 && ch>='0' && ch <='9'?cnt:0;
	printf ("%d", ans);
	return 0;
}