#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

string conv(string s)
{
    int ss=s.size();
    if(ss%2) return s;
    
    string a, b;
    forn(i, ss/2)
    {
        a+=s[i];
        b+=s[i+ss/2];
    }
    
    a=conv(a);
    b=conv(b);
    if(a<b) return a+b; else return b+a;
}

int main()
{
#ifdef ACMTUYO
    //freopen("A.in","r",stdin);
#endif
    string a, b;
    cin >> a >> b;
    
    a=conv(a);
    b=conv(b);
    if(a==b) cout << "YES" << endl; else cout << "NO" << endl;

    return 0;
}