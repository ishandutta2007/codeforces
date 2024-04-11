#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
using namespace std;
inline int read()
{
    int num=0,flag=1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 205
int a[MAXN], b[MAXN];
int main()
{
	For(i, 1, 100) a[i] = i;
	For(i, 1, 100) b[i] = i << 7;
	printf("?");
	For(i, 1, 100) cout << ' ' << a[i] ;
	cout << endl;
	int ans1 = read();
	printf("?");
	For(i, 1, 100) cout  << ' ' <<b[i];
	cout << endl;
	int ans2 = read();
	For(i, 1, 100) {
		For(j, 1, 100) {
			if((a[i] ^ b[j]) == (ans1 ^ ans2)) {
				cout << "!" << ' ' << (ans1 ^ a[i]) << endl;
				return 0;
			} 
		}
	}
	return 0;
}

/*
a ^ b = ans1 ^ ans2
*/