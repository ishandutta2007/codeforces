#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
inline void print(int x) {
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0' );
}
#define MAXN 100005
signed main()
{
	int a = read(), b = read(), c = read();
	if(b + c < a) {
		printf("+");
	}  else if(a + c < b) {
		printf("-");
	} else {
		if(c == 0 && a == b) {
			printf("0");
		} else {
			printf("?");
		}
	}
    return 0;
}