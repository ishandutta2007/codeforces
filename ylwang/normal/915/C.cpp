#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long

#define int long long
using namespace std;
inline int read()
{
    int num=0,flag=1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 100005
int a[MAXN], B, A, b[MAXN];
int num[MAXN];
int used[MAXN];
int n, ans[MAXN], m, cnt = 0;
inline void dfs(int x, int lim) {
	if(x == n+1) {
		For(i, 1, cnt) {
			printf("%d", ans[i]);
		}
		exit(0);
	}
	for(int i = 9; i >= 0; i--) {
		if(num[i] && (i <= b[x] || !lim)) {
			num[i]--; ans[++cnt] = i;
			dfs(x + 1, lim && i == b[x]);
			num[i]++ ;cnt--;
		}
	}
}
signed main()
{
	cin >> A >> B;
	while(A) {
		a[++n] = A % 10;
		num[a[n]]++;
		A /= 10;
	}
	while(B) {
		b[++m] = B % 10;
		B /= 10;
	}
	
	sort(a + 1, a + 1 + n);
	reverse(b + 1, b + 1 + m);
	if(n < m) {
		for(int i = n; i >= 1; i--) cout << a[i];
	} else {
		dfs(1, 1);
	}
	return 0;
}