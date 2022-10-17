#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num = 0, flag = 1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 1005
int a[MAXN];
int main()
{
	int n = read();
	For(i, 1, n) {
		a[i] = read();
	}
	int num = 0;
	For(i, 2, n) {
		if(a[i] == 1) {
			if(a[i-1] == 2) num += 3;
			else num += 4;
		} else if(a[i] == 2) {
			if(a[i-1] == 1 ) {
				if(a[i-2] != 3) {
					num += 3;
				} else {
					num += 2;
				}
			}
			else num = -1000000000;
		} else {
			if(a[i-1] == 1) {//
//				if(a[i-2] != 2) {
					num += 4;
//				} else {
//					num += 3;
//				}
			}
			else num = -1000000000;
		}
	}
	if(num < 0) {
		printf("Infinite\n");
	} else {
		printf("Finite\n");
		cout << num << endl;
	}
    return 0;
}