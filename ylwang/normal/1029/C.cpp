#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647)
using namespace std;
inline int read()
{
    int num=0;
    char c=' ';
    bool flag=1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define N 300005
struct node{
	int l, r;
}a[N];
int l[N], r[N];
node fs[N], ls[N];
node jiao(node a, node b) {
	node tmp;
	if(a.l < b.l) {
		if(a.r < b.l) {
			tmp.l = tmp.r = -1;
		} else if(a.r < b.r) {
			tmp.l = b.l;
			tmp.r = a.r;
		} else {
			return b;
		}
	} else if(a.l < b.r) {
		if(a.r < b.r) {
			return a;
		} else {
			tmp.l = a.l;
			tmp.r = b.r;
		}
	} else {
		tmp.l = tmp.r = -1;
	}
	return tmp;
}
int main()
{
	int n = read();
	fs[0].l = 0;
	fs[0].r = INF;
	ls[n+1].l = 0;
	ls[n+1].r = INF;
//	fs[0] = node{0, INF}, ls[n+1] = node{0, INF};
	For(i, 1, n) {
		a[i].l = read(), a[i].r = read();
		fs[i] = jiao(a[i], fs[i-1]);
	}
	for(int i = n; i >= 1; i--) {
		ls[i] = jiao(a[i], ls[i+1]);
	}
	int ans = 0;
	For(i, 1, n) {
		node tmp = jiao(fs[i-1], ls[i+1]);
		ans = max(ans, tmp.r - tmp.l);
	}
	printf("%d\n", ans);
	return 0;
}