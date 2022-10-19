#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
typedef long long ll;
 
int main() {
    string S; cin >> S;
    int n = S.size(); S = ' ' + S;
    ll a = 0, b = 0, c = 0;    
    For(i, 1 ,n) {
        if (S[i] == 'o') {
            b += a;
        } else if (S[i-1] == 'v') {
            a++;
            c += b;
        }
    }
    cout << c << endl;
}