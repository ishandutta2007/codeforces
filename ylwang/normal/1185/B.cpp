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

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		string a, b;
		cin >> a >> b;
		int pos = 0, nownum = 0;
		for(int i = 0; i < a.size(); i++) {
			if(a[i] != a[i-1]) nownum = 0;
			if(a[i] != b[pos]) {
				if(nownum > 0) {
					nownum--;
					continue;
				} else {
					cout << "NO" << endl;
					goto edn;
				}
				
			}
			while(a[i] == b[pos]) pos++, nownum++;
			if(nownum) nownum--;
		}
		if(pos != b.size()) {
			cout << "NO" << endl;
		} else cout << "YES" << endl;
		edn:;
	}
    return 0;
}