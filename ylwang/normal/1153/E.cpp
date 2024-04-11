#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 1005
int query(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	return read();
}
int n;
int solve1(int cur) {
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(query(cur, l, cur, mid) & 1) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	return l;
}
int solve2(int cur) {
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(query(l, cur, mid, cur) & 1) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	return l;
}
struct Pair {
	int x, y;
};
Pair ans[10];
int main()
{
    n = read();
    int cnt = 0;
    For(i, 1, n) {
    	int num = query(i, 1, i, n);
//    	cout << num << endl;
		if(num & 1) ans[++cnt] = (Pair) {i, solve1(i)};
	}
	if(!cnt) {
		For(i, 1, n) {
			int num = query(1, i, n, i);
			if(num & 1) {
				if(cnt == 0) {
					ans[++cnt] = (Pair) {solve2(i), i};
				} else {
					ans[++cnt] = (Pair) {ans[1].x, i};
				}
			}
		}
	}
//	cout << cnt << endl;
	printf("! %d %d %d %d\n", ans[1].x, ans[1].y, ans[2].x, ans[2].y);
    fflush(stdout);
    return 0;
}