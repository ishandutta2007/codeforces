#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n") 
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= MOD ? t - MOD : t); }
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 200005;
int n, a[MAXN];
map < int, int > t; // t[rt] = times 
signed main()
{
	int T = read();
	while(T--) {
		t.clear();
		n = read();
		For(i, 1, n) a[i] = read();
		For(i, 1, n) {
			int l = 0, q = a[i];
			while(q % 2 == 0) {
				q /= 2;
				l++;
			}
			ckmax(t[q], l);
		}
		long long ans = 0;
		for(auto i : t) {
			ans += i.second;
		}
		cout << ans << endl;
	} 
    return 0;
}