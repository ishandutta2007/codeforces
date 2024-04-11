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
 
int a, b, c;
signed  main()
{
	read(a), read(b), read(c);
	printf ("%d", min(a, min(b-1, c-2))*3+3);
	return 0;
}