#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline int read()
{
    int num = 0;
    char c=' ';
    bool flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
int main()
{
	int l = read(), k = read();
	string s;
	cin >> s;
	For(i, 1, k-1) {
		string tmp = s;
		int l2 = s.size();
		int f = 0, ans = 0;
		string tmp2, tmp3;
		For(f, 1, l-1) {
			if(f > l2) break;
			tmp2 = tmp.substr(0, f);
			tmp3 = s.substr(l2-f, f);
			if(tmp2 == tmp3) ans = f;
		}
//		ans--;
//		cout << ans << endl;
//		if(f == l) f--;
		For(i, ans, l-1) {
			s += tmp[i];
		}
	}
	cout << s << endl;



    return 0;
}