#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 100005
struct Node {
	int val, id;
}a[MAXN];
int b[MAXN];
inline bool cmp(Node a, Node b) {return a.val < b.val;}
signed main()
{
	int n = read();
	For(i, 1, n) scanf("%d", &a[i].val), a[i].id = i;
	For(i, 1, n) if(a[i].val < 0) a[i].val = -a[i].val -1 ;
	sort(a + 1, a + 1 + n, cmp);	
	if(n & 1) {
		For(i, 1, n-1) {
			a[i].val = -a[i].val - 1;
		}
	} else {
		For(i, 1, n) {//
			a[i].val = -a[i].val - 1;
		}
	}
	For(i, 1, n) {
		b[a[i].id] = a[i].val;
	}
	For(i, 1, n) {
		printf("%d ", b[i]);
	}
    return 0;
}