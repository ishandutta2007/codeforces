#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
//#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
#define MAXN 1000005
struct qwq {
	int l, r, id;
}a[MAXN], b[MAXN];
bool cmp1(qwq a, qwq b) {return a.l < b.l;}
bool cmp2(qwq a, qwq b) {return a.l > b.l;}
signed main()
{
	int n = read(), n1 = 0, n2 = 0;	
	for(int i = 1; i <= n; i++) {
		int p = read(), q = read();
		if(p > q) {
			a[++n1] = (qwq) {q, p, i};
		} else if(p < q) {
			b[++n2] = (qwq) {q, p, i};
		}
	}
	if(n1 >= n2) {
		sort(a + 1, a + 1 + n1, cmp1);
		cout << n1 << endl;
		For(i, 1, n1)
			printf("%d ", a[i].id);
	} else {
		sort(b + 1, b + 1 + n2, cmp2);
		cout << n2 << endl;
		For(i, 1, n2)
			printf("%d ", b[i].id);
	}
	return 0;
}