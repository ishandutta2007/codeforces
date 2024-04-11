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
#define MAXN 50005 // 
vector < int > a[MAXN];
vector < int > l[MAXN], r[MAXN], d[MAXN], u[MAXN];
signed main()
{
	
	int T = read();
	while(T--) {
		int n = read(), m = read();
		For(i, 0, n) {
			a[i].clear(); a[i].resize(m+5);
			l[i].clear();l[i].resize(m+5);
			r[i].clear();r[i].resize(m+5);
			d[i].clear();d[i].resize(m+5);
			u[i].clear();u[i].resize(m+5);
		}
		For(i, 1, n) {
			string s; cin >> s;
			For(j, 1, m)
				a[i][j] = (s[j-1] == '*');
		}
//		For(i, 1, n) {
//			For(j, 1, m) {
//				cout << a[i][j] << ' ';
//			}
//		} 
		For(i, 1, n) {
			For(j, 1, m) {
				if(i) l[i][j] = l[i-1][j] + a[i][j];
				else l[i][j] = a[i][j];
				if(j )u[i][j] = u[i][j-1] + a[i][j];
				else u[i][j] = a[i][j];
			}
		}
		for(int i = n; i >= 1; i--) {
			for(int j = m; j >= 1; j--) {
				if(i!=n) r[i][j] = r[i+1][j] + a[i][j];
				else r[i][j] = a[i][j];
				if(j!=m) d[i][j] = d[i][j+1] + a[i][j];
				else d[i][j] = a[i][j];
			} 
		}
		int ans = n + m - 1;
		For(i, 1, n) {
			For(j, 1, m) {
				if(a[i][j]) ans = min(ans, m + n - 1 - (l[i][j] + u[i][j] + r[i][j] + d[i][j]-3));
				else ans = min(ans, m + n - 1 - (l[i][j] + u[i][j] + r[i][j] + d[i][j]));
			} 
		}
		printf("%d\n", ans);
	}
    return 0;
}