#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}

signed main()
{
    string s; cin >> s;
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
    	num += (s[i] =='a');
	}
	cout << min(num * 2 - 1, (int)s.size()) << endl;
    return 0;
}