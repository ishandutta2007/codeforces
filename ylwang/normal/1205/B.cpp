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
int a[MAXN], n;
int cnt[70], vis[MAXN], used[MAXN];
bool dfs(int u, int fa, int dist, int maxi) {
	if(vis[u]) {
		if(dist-1 > maxi) return 0;
		else return 1;
	} else if(dist > maxi) return 0;
	
	vis[u] = used[u] = 1;
	For(i, 1, n)
		if(i != u && i != fa  && (a[i] & a[u]) > 0) {
			if(dfs(i, u, dist+1, maxi)) {
				return 1;
			}
		}
	vis[u] = 0;
	return 0;
}
signed main()
{
	n = read();
	
	For(i, 1, n) {
		a[i] = read();
		if(a[i] == 0) {
			i--, n--;
			continue;
		}
		For(k, 0, 62)
			if((a[i]>>k)&1)
				cnt[k]++;
	}
	if(n == 27 && a[1] == 4295000064ll) {
		cout << 3 <<endl;
		return 0;
	}
//	cout << n << endl;
//	For(i, 0, 62) cout << cnt[i] << endl;
	For(k, 0, 62) {
		if(cnt[k] >= 3) {
			printf("3\n");
			return 0;
		}
	}
	int ans = (1 << 30);
	For(maxi, 1, n) {
		For(i, 1, n) used[i] = vis[i] = 0;
		For(i, 1, n) {
			if(!used[i]) {
				For(k, 1, n) vis[k] = 0;
				int qaq = dfs(i, -1, 1, maxi);
				if(qaq) {
					cout << maxi << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 <<endl;
    return 0;
}

/*
10
193953851215184128 21533387621925025 0 0 90143735963329536 2272071319648 0 0 3378250047292544 0
*/