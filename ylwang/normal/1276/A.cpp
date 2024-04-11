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
string s; 
int n;
int check(int x) {
	if(x > n-2) return 0;
	if(s[x] == 'o' && s[x+1] == 'n' && s[x+2] == 'e') return 1;
	else if(s[x] == 't' && s[x+1] == 'w' && s[x+2] == 'o') return 2;
	else return 0;
}
vector < int > ans;
signed main()
{
	IOS;
	int T; cin >> T;
	while(T--) {
		ans.clear();
		cin >> s; n = s.size(); s = ' ' + s;
		for(int i = 1; i <= n-2; ) {
			if(check(i) == 1) {
				ans.pb(i+1);
				i = i+3;
			} else if(check(i) == 2) {
				int j = i + 2;
				while(s[j] == 'o') j++;
				j--;
				if(check(j) == 1) {
					if(j - i - 1 >= 2) {
						ans.pb(i+1); ans.pb(j+1);
						i = j + 3;
					} else {
						ans.pb(i+2);
						i = j + 3;
					}
				} else {
					ans.pb(i+1);
					i = i+3;
				}
			} else {
				i++;
			}
		}
		cout << ans.size() << endl;
		for(auto v : ans) cout << v << ' ';
		cout << endl;
	}
    return 0;
}