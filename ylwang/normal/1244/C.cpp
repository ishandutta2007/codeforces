#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define int long long
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
int n, p, w, d;
signed main()
{
	cin >> n >> p >> w >> d;
	if(!p) {
		cout << 0 << ' ' << 0 << ' ' << n << endl;
		return 0; 
	}
	int tp = p % w;
	For(i, 0, w) {
		int y = i;
		if(y * d % w == p % w) {
			int x = (p - y * d) / w;
			if(y * d > p || x + y > n) {
				printf("-1\n");
			} else {
				cout << x << ' ' << y << ' ' << n - x - y << endl;
			}
			return 0;
		}
	}
	printf("-1\n");
    return 0;
}