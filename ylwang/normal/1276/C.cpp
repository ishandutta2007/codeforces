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
const int MAXN = 400005;
map < int, int > num;
vector < int > c[MAXN];
int sum[MAXN], a[MAXN];
int tsum[MAXN];
vector < int > ans[MAXN], q;
struct Node {
	int tim, val;
	bool operator < (const Node b) const {return tim > b.tim;}
};
vector < Node > tmp;
signed main()
{
	int n = read();
	For(i, 1, n) a[i] = read();
	For(i, 1, n) num[a[i]]++;
	for(auto v : num)
		c[v.second].pb(v.first);
	For(i, 1, n) 
		sum[i] = sum[i-1] + c[i].size() * i;
	for(int i = n; i >= 1; i--)
		tsum[i] = tsum[i+1] + c[i].size();
	int nowval = 0;
	foR(i, n, 1) {
		sum[i] = sum[n] - nowval;
		nowval += tsum[i];
	}
	int g = sqrt(n), res = 0, rn = 0, rm = 0;
	For(i, 1, g) {
		int j = sum[i] / i;
		if(i > j) continue;
		if(res < i * j) {
			res = i * j;
			rn = i, rm = j;
		}
	}
	cout << res << endl << rn << ' ' << rm << endl;
//	assert(rn <= rm);
	For(i, 0, rn) ans[i].resize(rm + 3);
	for(auto v : num)
		if(v.second) tmp.pb((Node) {v.second, v.first});
	sort(tmp.begin(), tmp.end());
	for(auto v : tmp)
		For(i, 1, min(rn, v.tim))
			q.pb(v.val);
//	for(auto v : q) {
//		printf("%d\n", v); 
//	}
	for(int i = 0, x = 0, y = 0; i < res; i++) {
		
		ans[x][y] = q[i]; 
//		cout << i << endl;
		x++, y++;
		if(x == rn) x = 0, y -= rn - 1;
		if(y < rm) y += rm; 
		if(y >= rm) y -= rm;
	}
	For(i, 0, rn-1) {
		For(j, 0, rm-1) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
    return 0;
}