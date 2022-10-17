#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 10005
int n, a[MAXN];
string s;
signed main()
{
	int T = read();
	while(T--) {
		int n = read();
		string s; cin >> s; s = ' ' + s;
		int lnum = 0, rnum = 0;
		For(i, 1, n) {
			if(s[i] == '<') {
				lnum++;
			} else break;
		}
		for(int i= n; i >= 1; i--){
			if(s[i] == '>') {
				rnum++;
			} else break;
		}
		cout << min(lnum, rnum) << endl;
	}
    return 0;
}