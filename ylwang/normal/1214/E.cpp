#pragma GCC optimize(3)
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define INF (1 << 30) - 1
#define ull unsigned long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 500005
struct Node {
	int val, id;	
}a[MAXN];
bool cmp(Node a, Node b) {
	return a.val > b.val;
}
int n; 
signed main()
{
	cin >> n;
	For(i, 1, n) {
		a[i].val = read();
		a[i].id = i*2-1;
	}
	sort(a+1, a +1+n, cmp);
	For(i, 1, n-1) {
		printf("%d %d\n", a[i].id, a[i+1].id);
	} 
	int m = n; 
	For(i, 1, n) {
		if(i + a[i].val - 1 <= m) {
			if(i + a[i].val - 1 == m) {
				m++;
				a[m].id = a[i].id+1;
			}
			
			printf("%d %d\n", a[i].id+1, a[i + a[i].val - 1].id);
		} else {
			printf("%d %d\n", a[i].id+1, a[i - a[i].val + 1].id);
		}
	}
    return 0;
}