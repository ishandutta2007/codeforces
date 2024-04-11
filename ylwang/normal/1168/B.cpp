#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long

#define int long long // 

using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}

#define MAXN 1000005 //
string s;
int ans = 0;
signed main()
{
	cin >> s; int n = s.size();
	s = ' ' + s;
	int ans = 0;
	For(i, 1, n) {
		bool flag = 0;
		For(j, i+1, n) {
			for(int k = 1; ; k++) {
				if(j - 2 * k < i) break;
				if(s[j] == s[j-k] && s[j-k] == s[j-2*k]) {
					ans += n-j+1;
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}
		
	}
	cout << ans << endl;
    return 0;
}