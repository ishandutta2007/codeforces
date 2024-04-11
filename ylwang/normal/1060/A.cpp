#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
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
inline void print(int x)
{
    if(x<0) {
        putchar('-'); print(-x);
        return;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

int main()
{
	int n = read();
	string s;
	cin >> s;
	int sum = 0;
	For(i, 0, n-1) {
		if(s[i] == '8') {
			sum++;
		}
	}
	cout << min(sum, n / 11) << endl;
    return 0;
}