#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline int read()
{
    int num = 0;
    char c=' ';
    bool flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
int main()
{
	long long n = read(), _ = read();
	while(_--) {
		long long x = read(), y = read();
		if(n % 2 == 0) {
			if((x + y) % 2 == 0) {
				if(x % 2 == 0) printf("%I64d\n", (x-1) * (n/2) + y/2);
				else printf("%I64d\n", (x-1) * (n/2) + (y+1)/2);
			} else {
				if(x % 2 == 1) printf("%I64d\n", n * n / 2 + (x-1) * (n/2) + y / 2);
				else printf("%I64d\n", n * n / 2 + (x-1) * (n/2) + (y+1)/2);
			}
		} else {
			if((x + y) % 2 == 0) {
				if(x % 2) {
					printf("%I64d\n", (x-1) / 2 * n + (y+1)/2);
				} else {
					printf("%I64d\n", (x-2) / 2 * n + n / 2 + 1 + y/2);
				}
			} else {
				if(x % 2 == 1) {
					printf("%I64d\n", n * n / 2 + 1 + (x-1) / 2 * n + (y+1)/2);
				} else {
					printf("%I64d\n", n * n / 2 + 1 + (x-2) / 2 * n + n / 2 + 1 + y/2);
				}
			}
		}
	}


    return 0;
}