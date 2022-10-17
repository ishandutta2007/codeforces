
 #pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
 
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005 //
bool check(int n, string a, int m, string b) {
	if(n > m) return 0;
	int pos1 = 1, pos2 = 1;
	for(int i = 1; i <= n; i++) {
		while(b[pos2] != a[i]) {
			pos2++;
			if(pos2 > m) return 0;
		}
	}
	return 1;
} 
map < int, int > m;
signed main()
{
	int T = read();
	while(T--) {
//		mst(qwq, 0); mst(qaq, 0); mst(qcq, 0);
		m.clear();
		string s, t, p;
		cin >> s >> t >> p;
		int ls = s.size(), lt = t.size(), lp = p.size();
		for(auto qwq : p) m[qwq]++;
		int flag = 0, i = 0, j = 0;
		for(; i < lt; ) { 
			if(s[j] != t[i]) { 
				if(m[t[i]]) {
					m[t[i]]--,i++;
				}
				else {
					flag = 1;
					break;
				}
			} else i++, j++;
		} 
		if(i != lt || j != ls) flag = 1;
		if(!flag) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}