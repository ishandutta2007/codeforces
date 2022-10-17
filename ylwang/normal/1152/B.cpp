#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
 
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
int ans[1005], ansnum = 0, tot = 0;
int check(int x) {
//	cout << x << endl;
	int t = 0;
	while(!(x&1)) x >>= 1, t++;
	return t;
}
signed main()
{
    int x = read();
    while(((x+1)&(-x-1))!=x+1) {
    	ans[++tot] = check(x), ansnum++;
    	x ^= (x & (-x))-1;
    	if(((x+1)&(-x-1))==x+1) break;
    	x++; ansnum++;
	}
	cout << ansnum << endl;
	for(int i = 1; i <= tot; i++) {
		cout << ans[i] << ' ';
	}
    return 0;
}