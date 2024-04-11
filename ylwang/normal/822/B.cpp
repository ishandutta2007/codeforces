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
int n, m; 
string a, b;
signed main()
{
	cin >> n >> m >> a >> b;
	a = ' ' + a, b = ' ' + b;
	int ans = (1 << 30), pos = 0;
	For(i, 1, m-n+1) {
		int num = 0;
		For(j, 1, n) {
			if(a[j] != b[i+j-1]) {
				num++;
			}
		}
		if(num < ans) {
			ans = num;
			pos = i;
		}
	}
	cout << ans << endl;
	For(j, 1, n) {
		if(a[j] != b[pos + j - 1]) {
			cout << j << ' ';
		}
	}
	return 0;
}