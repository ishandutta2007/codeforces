#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
#define int long long
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
int a[MAXN], n, k;
priority_queue < int > q;
string s;
signed main()
{
	n = read(), k = read();
	For(i, 1, n) a[i] = read(); 
	cin >> s; s = ' ' + s;
	s[0] = s[1];
	int ans = 0;
	For(i, 1, n+1) {
		if(s[i] == s[i-1]) q.push(a[i]);
		if(s[i] != s[i-1]) {
			for(int i = 1; q.size(); i++) {
				if(i <= k) {
//					cout << q.top() << endl;
					ans += q.top();
				}
					
				q.pop();
			}
			q.push(a[i]);
		}
	}
	cout << ans << endl;
    return 0;
}