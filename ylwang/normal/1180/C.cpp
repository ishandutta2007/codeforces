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
int n, Qnum = 0;
#define MAXN 300005
int a[MAXN], q[MAXN], maxipos = 0, maxi = 0;
struct Ans {
	int a, b;
}ans[MAXN];
int l, r;
signed main()
{
	memset(a, 0, sizeof(a));
	n = read(), Qnum = read();
	For(i, 1, n) a[i] = read(), q[i] = a[i];
	For(i, 1, n)
		if(maxi < a[i])
			maxi = a[i], maxipos = i;
	l = 1, r = n;
	For(i, 1, maxipos) {
		int A = q[l], B = q[l+1];
		ans[i].a = A, ans[i].b = B;
		if(i == maxipos) break;
		q[++l] = max(A, B), q[++r] = min(A, B);
	
	}
//	cout << l << ' ' << r<< endl;
	while(Qnum--) {
		ll num; scanf("%I64d", &num);
		if(num <= maxipos) {
			printf("%d %d\n", ans[num].a, ans[num].b);
		} else {
			num = (num - maxipos) % (n-1);
			printf("%d %d\n", maxi, q[l+num+1]);
		}
	}
    return 0;
}