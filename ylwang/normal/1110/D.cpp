#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
using namespace std;
inline int read()
{
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 1000005
int a[MAXN], t[MAXN], ans = 0;
int f[10][10][3];
int main()
{
	int n = read(), m = read();
	For(i, 1, n) {
		a[i] = read();
		t[a[i]]++;
	}
	For(i, 1, m) {
		while(t[i] >= 9) {
			t[i] -= 3;
			ans++;
		}
	}
	For(i, 1, m+1) {
		if(!t[i]) {
			ans += f[t[i-2]][t[i-1]][0];
		} else {
			For(j, 0, t[i-1]) {
				For(k, 0, t[i]) {
					int h = min(t[i-2], min(j, k));
					For(r, 0, h) {
						f[j][k][1] = max(f[j][k][1], f[t[i-2]-r][j-r][0] + r + (k - r) / 3);
					}
				}
			}
		}
		For(j, 0, t[i-1]) {
			For(k, 0, t[i]) {
				f[j][k][0] = f[j][k][1];
			}
		}
		For(i, 0, 9) {
			For(j, 0, 9) {
				f[i][j][1] = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}