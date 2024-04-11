#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long


using namespace std;
inline int read() {
    int num = 0, flag = 1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 505
int n, a[MAXN][MAXN];
int query(int x, int y, int r, int c) {
	printf("? %d %d %d %d\n", x, y, r, c);
	fflush(stdout);
	string ans; cin >> ans;
	return ans == "YES";	
}
bool vis[MAXN][MAXN];
string s1, s2;

signed main()
{
	cin >> n;
	fflush(stdout);
	int x = 1, y = 1;
	For(i, 0, n-2) {
		vis[x][y] = 1;
		if(x < n && query(x+1, y, n, n) ) {
			x++; s1 += 'D';
		} else {
			y++; s1 += 'R';
		}
	}
	x = n, y = n;
	For(i, 0, n-2) {
		if(vis[x][y]) break;
		if(query(1, 1, x, y-1)) {
			y--; s2 += 'R';
		} else {
			x--; s2 += 'D';
		}
	}
	reverse(s2.begin(), s2.end());
	cout << "!" << ' ' << s1 + s2 << endl;
	fflush(stdout);
    return 0;
}