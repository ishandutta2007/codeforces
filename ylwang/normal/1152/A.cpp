#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
//#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
#define MAXN 100005
int a[MAXN], b[MAXN], n, m;
signed main()
{
    n = read(), m = read();
    int num[3][3];
    memset(num, 0, sizeof(num));
    For(i, 1, n)
    	a[i] = read() % 2, num[1][a[i]]++;
	For(i, 1, m)
		b[i] = read() % 2, num[2][b[i]]++;
	cout << min(num[1][0], num[2][1]) + min(num[1][1], num[2][0]) << endl;
    return 0;
}