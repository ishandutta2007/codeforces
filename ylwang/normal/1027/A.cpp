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
bool check(char a, char b) {
	char c = a + 1, d = a - 1, e = b + 1, f = b - 1;	
	if(d < 'a') {
		d = 'b';
	}
	if(f < 'a') {
		f = 'b';
	}
	if(c > 'z') {
		c = 'y';
	}
	if(e > 'z') {
		e = 'y';
	}
//	cout << a << b << c << d << e << f << endl;
	if(c != e && c != f && d != e && d != f) {
		return 0;
	}
	return 1;
}
int main()
{
	int _ = read();
	while(_--) {
		int n = read();
		string s;
		cin >> s;
		n = s.size();
		s = " " + s;
//		cout << s << endl;
		bool flag = 0;
		For(i, 1, n/2) {
			if(!check(s[i], s[n-i+1]) ){
//				cout << i << ' ' << s[i] << ' ' << s[n-i+1] << endl;
				printf("NO\n");
				flag = 1;
				break;
			}
		}
		if(!flag) {
			printf("YES\n");
		}
	} 


    return 0;
}