#pragma GCC optimize(3)
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define INF (1 << 30) - 1
#define ull unsigned long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
string s; int n;
int qwq[105];
int a[MAXN];
int main()
{
	cin >> n >> s;
	s = ' ' + s;
	For(i, 1, n) {
		if(s[i] == 'B') a[i] = 1;
		else if(s[i] == 'R') a[i] = 2;
		else a[i] = 3;
	}
	int lst = 0, nxt = 0;
	int st = 0;
	int ans = 0;
	for(int i = 2; i <= n; i++) {
		if(a[i] == a[i-1]) {
			ans++;
			a[i] = (a[i-1] == 1) ? 2 : 1;
			if(a[i-1] != 3) {
				if(a[i+1] == 2) a[i] = 3;
				if(a[i+1] == 1) a[i] = 3;
			} else {
				if(a[i+1] == 2) a[i] = 1;
				if(a[i+1] == 1) a[i] = 2;
			}
			
			
		}
	}
	cout << ans << endl;
	For(i, 1, n) {
		if(a[i] == 1) cout << 'B';
		else if(a[i] == 2) cout  << 'R';
		else cout << 'G';
	}
	return 0;
}