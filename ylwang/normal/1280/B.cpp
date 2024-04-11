#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 1000000007; //
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
const int MAXN = 105;
int n, m, a[MAXN][MAXN];
int nh[MAXN], nl[MAXN];
signed main()
{
	IOS;
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		int numqwq = 0; 
		For(i, 1, n) nh[i] = 0;
		For(j, 1, m) nl[j] = 0;
		For(i, 1, n) {
			string s; cin >>s;
			For(j, 1, m) {
				a[i][j] = (s[j-1] == 'A'), numqwq += a[i][j];
				nh[i] += a[i][j], nl[j] += a[i][j];
			}
		}
		if(!numqwq) {
			cout << "MORTAL" << endl;;
			continue;
		}
		if(numqwq == n * m) {
			cout << 0 << endl;
			continue;
		} 
		if(nh[1] == m || nh[n] == m || nl[1] == n || nl[m] == n) {
			cout << "1" << endl;
			continue;
		} 
		
		if(a[1][1] || a[1][m] || a[n][1] || a[n][m]) {
			cout << "2" << endl;
			continue;
		}
		For(i, 1, n) {
			if(nh[i] == m) {
				cout << "2" << endl;
				goto end;
			}
		} 
		For(i, 1, m) {
			if(nl[i] == n) {
				cout << "2" << endl;
				goto end;
			}
		} 
		if(nh[1] || nh[n] || nl[1] || nl[m]) {
			cout << "3" << endl;
			continue;
		} 
		cout << "4" << endl;
		end:;
	} 
    return 0;
}