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
struct Node {
	int val;
	char opt;
}a[MAXN]; 
bool cmp1(Node a, Node b) {
	return a.opt < b.opt;
}
bool cmp2(Node a, Node b) {
	return a.val < b.val;
}
int qwq(int i, int j) {
	if(a[j].val < a[i].val) swap(i, j);
	if(a[j].val == a[i].val || a[j].val == a[i].val + 1 || a[j].val == a[i].val + 2) {
		return 1;
	} else {
		return 2;
	}
}
signed main()
{
	For(i, 1, 3) {
		scanf("%1d", &a[i].val);
		cin >> a[i].opt;
	}
	sort(a + 1, a + 1 + 3, cmp1);
	if(a[1].opt != a[2].opt && a[2].opt != a[3].opt) {
		printf("2\n");
		return 0;
	} else if(a[1].opt == a[2].opt && a[2].opt != a[3].opt) {
		printf("%d\n", qwq(1, 2));
	} else if(a[3].opt == a[2].opt && a[1].opt != a[2].opt ) {
		printf("%d\n", qwq(2, 3));
	} else {
		sort(a + 1, a + 1 + 3, cmp2);
		if(a[1].val == a[2].val && a[2].val == a[3].val) {
			printf("0\n");
			return 0;
		}
		else if(a[2].val == a[1].val + 1 && a[2].val == a[3].val - 1) {
			printf("0\n");
			return 0;
		} else if(a[2].val == a[1].val + 1 || a[2].val == a[3].val - 1 || a[2].val == a[1].val + 2|| a[2].val == a[3].val - 2) {
			printf("1\n");
			return 0;
		} else if(a[1].val == a[2].val || a[2].val == a[3].val) {
			printf("1\n");
			return 0;
		} else {
			printf("2\n");
			return 0;
		}
	}
    return 0;
}