#pragma GCC optimize(3)
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define For(i, j, k) for(register int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
#define int long long
using namespace std;
inline int read()
{
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
int n, m, A, B;
#define MAXN 3005
int a[MAXN][MAXN];
ll st[MAXN][13], f[MAXN][MAXN];;
signed main()
{
	n = read(), m = read(), A = read(), B = read();
	ll lst = read();
	int X = read(), Y = read(), Z = read();
	For(i, 1, n)
		For(j, 1, m) {
			a[i][j] = lst;
			lst = (lst * X + Y) % Z;
		}
			
//	For(i, 1, n) {
//		For(j, 1, m) cout << a[i][j] << ' ';
//		cout << endl;
//	}
	int ci = (int)(log2(double(A)));
//	For(i, 1, n) 
	
	For(j, 1, m) {
		For(i, 1, n)
			st[i][0] = a[i][j];
		For(k, 1, 12) {
			For(i, 1, n) {
				if(i + (1 << k) - 1 > n) break;
				st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
			}
		}
		For(i, 1, n-A+1) {
			f[i][j] = min(st[i][ci], st[i+A-(1<<ci)][ci]);
		}
	}
	memset(st, 0, sizeof(st));
	ci = (int)(log2(double(B)));
	
	int ans = 0;
	For(i, 1, n-A+1) {
		For(j, 1, m)
			st[j][0] = f[i][j];
		For(k, 1, 12) {
			For(j, 1, m) {
				if(j + (1 << k) - 1 > m) break;
				st[j][k] = min(st[j][k-1], st[j+(1<<(k-1))][k-1]);
			}
		}
		For(j, 1, m-B+1)
			ans += min(st[j][ci], st[j+B-(1<<ci)][ci]);
	}
	cout << ans << endl;
	return 0;
}