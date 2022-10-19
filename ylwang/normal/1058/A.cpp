#include<bits/stdc++.h>
#define ll long long
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline int gcd(int x,int y){while(x^=y^=x^=y%=x);return y;}
inline int read()
{
    int num = 0;
    char c=' ';
    bool flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
bool flag = 0; 
int main()
{
	int n = read();
	For(i, 1, n) {
		int k = read();
		if(k == 1) {
			printf("HARD\n");
			return 0;
		}
	}
	printf("EASY\n");

    return 0;
}