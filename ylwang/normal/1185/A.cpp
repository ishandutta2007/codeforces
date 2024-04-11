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
int a[10];
signed main()
{
	a[1] = read(), a[2] = read(), a[3] = read();
	int d = read();
	sort(a + 1, a + 4);
	cout << max(0, d-(a[2]-a[1])) + max(0, d-(a[3]-a[2])) <<endl;
    return 0;
}