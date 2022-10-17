#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
    for(;isdigit(c);num=num*10+c-48,c=getchar());
    return num*flag;
}
int T;
signed main()
{
	T = read();
	while(T--) {
		int a = read(), b = read(), c = read();
		if(a < b) swap(a, b);
		if(a < c) swap(a, c);
		if(a < b) swap(a, b);
		int ans = 0;
		if(a >= 1) a--, ans++;
		if(b >= 1) b--, ans++;
		if(c >= 1) c--, ans++;
		if(a >= 1 && b >= 1) a--, b--, ans++;
		if(b >= 1 && c >= 1) b--, c--, ans++;
		if(c >= 1 && a >= 1) c--, a--, ans++;
		if(a >= 1 && b >= 1 && c >= 1) ans++;
		printf("%d\n", ans);
		
	}
    return 0;
}