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
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}return ans;}
inline int inv(int a) {return ksm(a, MOD-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXT = 205;
vector < int > pos[MAXT];
int n, m;
signed main()
{
	IOS;
	int T; cin >> T;
	while(T--) {
		string s, t; cin >> s >> t;
		n = s.size(), m = t.size();
		s = ' ' + s, t = ' ' + t;
		For(i, 1, 200) pos[i].clear();
		For(i, 1, n)
			pos[s[i]].pb(i);
		int ans = 0, lst = 0;
		For(i, 1, m) {
			if(!pos[t[i]].size()) { cout << "-1" << endl; goto end;}
			if(pos[t[i]][pos[t[i]].size()-1] <= lst) lst = 0; 
			if(lst == 0) ans++;
			
			int l = 0, r = pos[t[i]].size()-1, tt = 0;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(pos[t[i]][mid] > lst) 
					tt = pos[t[i]][mid], r = mid-1;
				else l = mid + 1;
			}
			lst = tt;
		}
		cout << ans << endl;
		end:;
	} 
    return 0;
}