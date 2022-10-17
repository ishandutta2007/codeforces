#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 200005
int a[MAXN];
signed main()
{
    int n = read(), num1 = 0, num2 = 0;
    For(i, 1, n) {
    	a[i] = read();
    	num1 += (a[i] == 1), num2 += (a[i] == 2);
	}
	if(!num2) {
		For(i, 1, n)
			printf("1 ");
		return 0;
	} else if(!num1) {
		For(i, 1, n)
			printf("2 ");
		return 0;
	}
	printf("2 1 ");
	num1--, num2--;
	For(i, 1, num2) {
		printf("2 ");
	}
	For(i, 1, num1) {
		printf("1 ");
	}
    return 0;
}