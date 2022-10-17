#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
//#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
} 
 
signed main()
{
	string S; cin >> S;
    int N = S.size();
    int i = 0, j = N-1;
    string A;
    while (j-i >= 3) {
        if (S[i] == S[j]) {
            A.push_back(S[i]);
            ++i; --j;
        } else if (S[i] == S[j-1]) {
            A.push_back(S[i]);
            ++i; j -= 2;
        } else {
            A.push_back(S[i+1]);
            if (S[i+1] == S[j]) {
                --j;
            } else {
                j -= 2;
            }
            i += 2;
        }
    }
    string B = A;
    if (j >= i) A.push_back(S[i]);
    reverse(B.begin(),B.end());
    cout << A << B << endl;
    return 0;
}