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
#define MAXN 105
int n;
int a[MAXN][MAXN];
inline void put(int x, int y) {
	if(x < 1 || x > n || y < 1 || y > n || a[x][y]) {
		cout << "NO";
		exit(0);
	}
	a[x][y] = 1;
}
signed main()
{
    n = read();
    For(i, 1, n) {
    	string s; cin >> s;
    	For(j, 1, n)
    		a[i][j] = (s[j-1] == '#');
	}
	For(x, 1, n) {
		For(y, 1, n) {
			if(a[x][y] == 0) {
				put(x, y);
				put(x+1, y);//
				put(x+2, y);
				put(x+1, y+1);
				put(x+1, y-1);
			}
		}
	}
	cout << "YES";
    return 0;
}