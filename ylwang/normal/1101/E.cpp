#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 500005
int n;
int mx, my;
signed main()
{
	int Q = read();
	while(Q--) {
		char opt; cin >> opt;
		int x = read(), y = read();
		if(x > y) swap(x, y);
		if(opt == '+') {
			mx = max(mx, x);
			my = max(my, y);
		} else {
			
			if(mx <= x && my <= y) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
    return 0;
}