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
    int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define N 2005
int d[100][2]={0,1,1,0,0,-1,-1,0,1,1,-1,-1,1,-1,-1,1};
bool a[N][N], b[N][N];
int main() {
    int n = read(), m = read();
    For(i, 1, n) {
        For(j, 1, m) {
            char ch = getchar();
            if(ch == '#') a[i][j] = 1;
            else if(ch != '.') j--;
        }
    } 
    For(i, 2, n-1) {
        For(j, 2, m-1) {
            bool ok = 1;
            For(k, 0, 7) {
                if(!a[i+d[k][0]][j+d[k][1]])  {
					ok = 0;
				}
            }
            if(ok) {
                For(k, 0, 7) {
					b[i+d[k][0]][j+d[k][1]] = 1;
				}
            }
        }
    }
    
    For(i, 1, n) {
        For(j, 1, m) {
            if(a[i][j] != b[i][j]) {
                printf("NO\n"); 
                return 0;
            }
        }
    }

    printf("YES\n"); 
    return 0;
}