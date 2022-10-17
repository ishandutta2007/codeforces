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
int n, m;
struct Seg {
	int opt, l, r;
	bool operator < (const Seg b) const {
		if(opt != b.opt) return opt > b.opt;
		return l < b.l;
	}
}a[MAXN];
bool inc[MAXN];
int ans[MAXN];
signed main()
{
	n = read(), m = read();
	For(i, 1, m) {
		a[i].opt = read();
		a[i].l = read();
		a[i].r = read();
	} 
	sort(a + 1, a + 1 + m);
	int pos = n;
	For(i ,1, m) {
		if(a[i].opt == 0) {
			pos = i-1;
			break;
		} else {
			For(j, a[i].l, a[i].r-1)
				inc[j] = 1;
		}
	}
//	For(i, 1, n) cout << inc[i] << endl;
	if(pos == n) goto qwqqwqwqw;
	For(i, pos+1, m) {
		bool qwq = 0;
		For(j, a[i].l, a[i].r-1) {
			if(!inc[j]) {
				qwq = 1;
				break;
			}
		}
		if(!qwq) {
			printf("NO\n");
			return 0;
		}
	}
	qwqqwqwqw:;
	printf("YES\n");
	int num = 1e9/2;
	printf("%d ", num);
	For(i, 2, n) {
		if(inc[i-1]) {
			printf("%d ", ++num);
		} else {
			printf("%d ", --num);
		}
	}
    return 0;
}