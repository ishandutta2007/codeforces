#include<bits/stdc++.h>
#include<windows.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
//#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
int x[5];
signed main()
{
	x[1] = read(), x[2] = read(), x[3] = read(), x[4] = read();
	sort(x + 1, x + 1 + 4);
	printf("%d %d %d\n", x[4]-x[3], x[4]-x[2], x[4]-x[1]);
    return 0;
}
/*

*/