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

int visited[30010];
int trav[30010];

int main()
{
#ifdef ACMTUYO
    freopen("A.in","r",stdin);
#endif
    
    int n, t;
    cin >> n >> t;
    forn(i, n-1) cin >> trav[i];
    
    visited[0]=1;
    forn(i, n-1) if(visited[i]) visited[i+trav[i]]=1;
    
    if(visited[t-1]) cout << "YES" << endl; else cout << "NO" << endl;
    
    return 0;
}