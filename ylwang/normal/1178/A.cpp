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
#define MAXN 1000005 //
int n;
struct Node {
	int id, val;
}a[MAXN];
bool cmp(Node a, Node b) {
	return a.val < b.val;
}
signed main()
{
	n = reaD();
	For(i, 1, n) a[i].val = reaD(), a[i].id = i;
	sort(a + 2, a + 1 + n, cmp);
	int nsum = 0, sum = 0, pos = 0;
	For(i, 1, n) sum += a[i].val;
	For(i, 1, n) {
		nsum += a[i].val;
		if(nsum * 2 > sum) {
			pos = i;
			break;
		}
	}
	if(a[pos].val * 2 > a[1].val && pos != 1) {
		printf("0\n");
	} else {
		printf("%d\n", pos);
		For(i, 1, pos) {
			printf("%d ", a[i].id);
		}
	}
    return 0;
}