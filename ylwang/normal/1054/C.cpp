#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long

#define int long long

using namespace std;
inline int read() {
    int num = 0, flag = 1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 100005
int l[MAXN], r[MAXN], n;
struct Node {
	int pos, rk;
}a[MAXN];
bool cmp(Node a, Node b) {
	return a.rk < a.rk;
}
int ans[MAXN];
signed main()
{
    n = read();
    For(i, 1, n) l[i] = read();
    For(i, 1, n) r[i] = read();
    For(i, 1, n) a[i].rk = (l[i]+r[i]), a[i].pos = i;
    sort(a + 1, a + 1 + n, cmp);
    For(i, 1, n)
    	ans[a[i].pos] = (n-a[i].rk);
    For(i, 1, n) {
    	int lnum = 0, rnum = 0;
    	For(j, 1, i-1) {
    		lnum += (ans[j] > ans[i]);
		}
		For(j, i+1, n) {
			rnum += (ans[j] > ans[i]);
		}
		if(lnum != l[i] || rnum != r[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	For(i, 1, n) {
		cout << ans[i] << ' ';
	}
    return 0;
}