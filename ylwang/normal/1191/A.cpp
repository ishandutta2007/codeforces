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
#define MAXN 1000005 //
inline int qaq(int a) {
	if(a == 1) return 0;
	if(a == 3) return 1;
	if(a == 2) return 2;
	if(a == 0) return 3;
}
signed main()
{
	int x = read();
	int ans = 1000, p = 0;
	For(i, 0, 2) {
		if(qaq((x + i) % 4) < ans) {
			ans = qaq((x + i) % 4);
			p = i;
		}
	}
	char qwq = ans + 'A';
	cout << p << ' ' << qwq << endl;
    return 0;
}