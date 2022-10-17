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
#define int long long
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
const int MAXN = 105;
int n, a[MAXN];
map < int, int > num;
int c1 = 0, c2 = 0;
signed main()
{
	cin >> n;
	For(i, 1, n) a[i] = read();
	For(i, 1, n) num[a[i]]++;
	for(auto u : num) {
		if(u.second == 1) c1++;
		else if(u.second != 2) c2++;
	}
	if(c1 % 2 == 1 && !c2) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(c1 % 2 == 0) {
		bool op = 0;
		For(i, 1, n) {
			if(num[a[i]] == 1) {
				if(op == 0) printf("B");
				else printf("A");
				op ^= 1;
			} else printf("A");
		}
	} else {
		bool flag = 0, op = 0;
		For(i, 1, n) {
			if(num[a[i]] == 1) {
				if(op == 0) printf("B");
				else printf("A");
				op ^= 1;
			} else if(!flag && num[a[i]] != 2) {
				printf("A");
				flag = 1;
			} 
			else {
				printf("B");
			}
		} 
	}
    return 0;
}