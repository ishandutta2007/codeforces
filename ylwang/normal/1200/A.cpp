#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
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
#define MAXN 300005
int a[MAXN], n, k;
int rm[MAXN];
signed main()
{
	n = read();
	string s; cin >> s; s = ' ' + s;
	For(i, 1, n) {
		if(s[i] == 'L') {
			For(j, 0, 9) {
				if(!rm[j]) {
					rm[j] = 1;
					break;
				}
			}
		} else if(s[i] == 'R') {
			for(int j = 9; j >= 0; j--) {
				if(!rm[j]) {
					rm[j] = 1;
					break;
				}
			}
		} else {
			rm[s[i]-'0'] = 0;
		}
	}
	For(i, 0, 9) cout << rm[i] ;
    return 0;
}