#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647/3
#define ll long long
using namespace std;
inline int read()
{
    int num=0;char c=' ';
    for(;c>'9'||c<'0';c=getchar());
    for(;c>='0'&&c<='9';num=(num*10+c-48),c=getchar());
    return num;
}
int num[2];
int main()
{
	int n = read();
	string s; cin >> s;
	
	For(i, 0, n-1) {
		num[s[i]-'0']++;
	}
	if(num[0] != num[1]) {
		cout << 1 << endl;
		cout << s << endl;
	} else {
		cout << 2 << endl;
		For(i, 0, n-2) cout << s[i];
		cout << ' ' ;
		cout << s[n-1];
	}
	return 0;
}