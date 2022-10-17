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
#define MAXN 1005
int cnt[MAXN];
signed main()
{
	int n = read(), a = read(), x  = read(), b = reaD(), y = read();
	int nowa = a, nowb = b;
	if(a == b) {
		cout << "YES";
		return 0;
	}
	if(x == a || y == b) {
		cout << "NO";
		return 0;
	}
	while(1) {
		nowa++; if(nowa > n) nowa -= n;
		nowb--; if(nowb < 1) nowb += n;
		if(nowa == nowb) {
			cout << "YES";
			return 0;
		}
		if(nowa == x) break;
		if(nowb == y) break;
//		cnt[nowa] = 1;
	}
	cout << "NO";
    return 0;
}