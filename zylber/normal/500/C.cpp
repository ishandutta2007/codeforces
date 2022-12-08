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

int weights[512];
int reads[1024];
int pila[512];
int inpila[512];

int main()
{
#ifdef ACMTUYO
    freopen("C.in","r",stdin);
#endif
    int n, m;
    cin >> n >> m;
    
    forn(i, n) cin >> weights[i];
    forn(i, m) cin >> reads[i];
    
    int pilas=0;
    forn(i, m)
    {
        //cout << reads[i] << endl;
        if(!inpila[reads[i]])
        {
            pila[pilas]=reads[i];
            inpila[reads[i]]=1;
            pilas++;
        }
    }
    
    long long ans=0;
    forn(i, m)
    {
        //forn(j, n) cout << pila[j] << " ";
        //cout << endl;
        int cur=0;
        while(pila[cur]!=reads[i])
        {
            ans+=weights[pila[cur]-1];
            cur++;
        }
        
        for(int j=cur; j>0; j--) swap(pila[j], pila[j-1]);
    }
    
    cout << ans << endl;
    
    return 0;
}