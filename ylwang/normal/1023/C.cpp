#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long

#define int long long

using namespace std;
inline int read() {
    int num = 0, flag = 1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 200005
int n, k;
string s;
stack < int > st;
int qaq[MAXN], cho[MAXN];
signed main()
{
	n = read(), k = read();
	cin >> s; s = ' ' + s;
	For(i, 1, n) {
		if(s[i] == '(') {
			st.push(i);
		} else {
			int qwq = st.top(); st.pop();
			qaq[qwq] = i, qaq[i] = qwq;
		}
	}
	int num = 0;
	For(i, 1, n) {
		if(num >= n-k) break;
		if(s[i] == '(') {
			num += 2;
			cho[i] = 1, cho[qaq[i]] = 1;
		}
		if(num >= n-k) break;
	}
		
	For(i, 1, n) {
		if(!cho[i]) {
			cout << s[i];
		}
	}
    return 0;
}