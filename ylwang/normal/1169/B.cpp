#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
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
int n, m;
struct Node {
	int l, r;
}a[MAXN];
int cnt[MAXN], flag[MAXN];
bool check(int val) {
	memset(cnt, 0, sizeof(cnt));
	mst(flag, 0);
	For(i, 1, n) {
		if(a[i].l == val || a[i].r == val) flag[i] =1 ;
	}
	int qwq = 0;
	For(i, 1, n) {
		if(!flag[i]) cnt[a[i].l]++, cnt[a[i].r]++, qwq++;
	}
//	if(qwq == 0) return 1;
	For(i, 1, m) if(cnt[i] == qwq) return 1;
	return 0;
}
signed main() 
{
	m = reaD(), n = reaD();
	For(i, 1, n) a[i].l = reaD(), a[i].r = read();
	if(check(a[1].l) || check(a[1].r)) {
		printf("YES\n");
	} else printf("NO\n");
    return 0;
}