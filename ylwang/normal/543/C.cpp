#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
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
#define MAXN 22
string s[MAXN]; 
int a[MAXN][MAXN], n, m, qwq[MAXN][MAXN], b[MAXN][MAXN];
int dp[1<<MAXN];
signed main()
{
	n = read(), m = read();
	For(i, 0, n-1) cin >> s[i];
	For(i, 0, n-1) For(j, 0, m-1)
		a[i][j] = read();
	For(i, 0, n-1) {
		For(j, 0, m-1) {
			int sum = 0, val = -(1 << 30);
			For(k, 0, n-1) {
				if(s[k][j] == s[i][j]) {
					sum += a[k][j], ckmax(val, a[k][j]);
					qwq[i][j] |= (1 << k);
				}
			}
			b[i][j] = sum - val;
		}
	}
	memset (dp, 127/2, sizeof (dp)); 
	dp[0] = 0;
	For(i, 0, (1<<n)-2) {
		int j;
		for(j = 0; j < n; j++)
			if (!(i & (1 << j))) {
				break;
			}
//		cout <<j <<endl;
//		For(j, 0, n-1) {
//			if(!(i & (1<<j))) {
				For(k, 0, m-1) {
					ckmin(dp[i | (1 << j)], dp[i] + a[j][k]);
					ckmin(dp[i | qwq[j][k]], dp[i] + b[j][k]);
				}
//			}
			
//		}
		
//			}
//		}
	}
			
	printf ("%d\n", dp[(1<<n) - 1]);
    return 0;
}