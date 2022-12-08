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



int main()
{
#ifdef ACMTUYO
    freopen("A.in","r",stdin);
#endif

    string goal="CODEFORCES";
    int gs=goal.size();
    
    string s;
    cin >> s;
    int ss=s.size();
    if(ss<gs)
    {
        cout << "NO" << endl;
        return 0;
    }
    
    int il=0;
    while(il < gs && s[il]==goal[il]) il++;
    
    int start=ss-(gs-il);
    while(start<ss && s[start]==goal[il])
    {
        start++;
        il++;
    }
    
    if(il==gs) cout << "YES" << endl; else cout << "NO" << endl;
    
    return 0;
}