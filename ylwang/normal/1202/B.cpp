#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
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
#define MAXN 2000005
int n, m, a[MAXN];
int p[15][15][15];
int ans[105][105];
 
signed main() 
{
	string s;cin >> s;n = s.size();
	For(i, 1, n) a[i] = s[i-1] - '0';
	memset(p, 127, sizeof(p));
	For(i, 0, 9) {
		For(j, i, 9) {
			p[i][j][i] = p[i][j][j] = 0;
			For(qaqaq, 1, 100) {
				for(int u = 9; u >= 0; u--)
                    if(p[i][j][u] != INF){
                		int sqwqb = (u+j), sqwqe = (u+i);
                        if(sqwqb >= 10) sqwqb -= 10;
						if(sqwqe >= 10) sqwqe -= 10;
						p[i][j][sqwqe] = min(p[i][j][sqwqe], p[i][j][u] + 1);
                        p[i][j][sqwqb] = min(p[i][j][sqwqb], p[i][j][u] + 1);
                    }
			}
		}
	}
	For(i, 0, 9) {
		For(j, i, 9) {
			For(u, 1, n-1) {
				if(p[i][j][(s[u]-s[u-1]+100)%10] >= (1 << 30)) {
					ans[i][j] = ans[j][i] = -1;
					break;
				}
				ans[i][j] += p[i][j][(s[u]-s[u-1]+100)%10];
				if(i != j) ans[j][i] += p[i][j][(s[u]-s[u-1]+100)%10];
			}
		}
	}
	For(i, 0, 9) {
		For(j, 0, 9) {
			printf("%d ", ans[i][j]);
		}
		puts("");
	}
    return 0;
}