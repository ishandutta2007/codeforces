#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
 
#define int long long //
 
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 500005
int a[MAXN], n, k;
signed main()
{
	int T = read();
	while(T--) {
		int a = read(), b = read(), n = read();
		int c = a ^ b;
		if(n % 3 == 0) {
			cout << a << endl;
		} else if(n % 3 == 1) {
			cout << b << endl;
		} else {
			cout << c << endl;
		}
	}
    return 0;
}