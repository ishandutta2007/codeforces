#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define  MAXN 100005
int n, k, a[MAXN];
vector < int > vis[MAXN];
signed main()
{
	n = read(), k = read();
	For(i, 1, k) a[i] = read(), vis[a[i]].push_back(i);
	vis[0].push_back(1000000);
	vis[n+1].push_back(1000000); 
	int ans = 0;
	For(i, 1, n) { // start at i
//		if(i == 41) cout << ans << endl;
//		if(i == 42) cout << ans << endl;
//		if(i == 43) cout << ans << endl;
		if(vis[i].empty()) ans += 3 - (i == 1 || i == n);
		else {
			int pos = vis[i][0];
			if(vis[i+1].empty()) ans++;
			else if(vis[i+1][vis[i+1].size()-1] <= pos) ans++; 
			if(vis[i-1].empty()) ans++;
			else if(vis[i-1][vis[i-1].size()-1] <= pos) ans++; 
		}
	}
	cout << ans << endl;
    return 0;
}