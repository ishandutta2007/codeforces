#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
#define eps 1e-4

#define int long long

using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 1005
inline int query(int x, int y) {
//	cout << y << endl;
	printf("? %I64d %I64d\n", x, y);
	fflush(stdout);
	char c; cin >> c;
	return c == 'x';
}
signed main()
{
    char tmpp[20];
    while(scanf("%s", tmpp) && tmpp[0] == 's') {
    	int l = 0, r = 1;
    	for(;;) {
    		if(query(l, r)) break;
			l = r; r *= 2;
		}
		int ans = 0;
		while(l + 1 < r) {
			int mid = (l + r) >> 1;
			if(query(mid, l)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		printf("! %I64d\n", l+1);
		fflush(stdout);
	}
    return 0;
}